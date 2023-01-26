#define _GNU_SOURCE
#include "xfunctions.h"
#include <assert.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <unistd.h>

// gcc ... -ldl


static bool induce_failure = false;

void * malloc(size_t nbytes)
{
    void * (*original_malloc)(size_t nbytes) = dlsym(RTLD_NEXT, "malloc");

    if (induce_failure) {
        return NULL;
    }
    else {
        return original_malloc(nbytes);
    }
}

void * calloc(size_t nitems, size_t size)
{
    void * (*original_calloc)(size_t nitems, size_t size) = dlsym(RTLD_NEXT, "calloc");

    if (induce_failure) {
        return NULL;
    }
    else {
        return original_calloc(nitems, size);
    }
}

void * realloc(void * prev, size_t nbytes)
{
    void * (*original_realloc)(void * prev, size_t nbytes) = dlsym(RTLD_NEXT, "realloc");

    if (induce_failure) {
        return NULL;
    }
    else {
        return original_realloc(prev, nbytes);
    }
}

void failure(const char * test)
{
    fprintf(stderr, "Not the expected condition on: %s\n", test);
}

void die(const char * msg)
{
    fprintf(stderr, "Error (not in the tested file, but in the test): %s\n", msg);
    exit(EXIT_FAILURE);
}

int main(void)
{
    // Doesn't have to execute commands of the second argument
    XNOTNULL_OR_ELSE((void *)1, failure("Test XNULL_OR_ELSE with NON NULL value"));
    // Actually has to execute commands of the second argument
    bool flag = false;
    XNOTNULL_OR_ELSE((void *)0, flag = true);
    if (flag != true) {
        failure("XNULL_OR_ELSE with NULL value");
    }

    int pid1 = fork();

    if (pid1 < 0) {
        die("Forking process");
    }

    // First process
    if (pid1 > 0) {
        // without shim
        void * ptr = xmalloc(10);
        ptr = xrealloc(ptr, 20);

        free(ptr);

        // With shim
        induce_failure = true;
        ptr = xmalloc(10);
        failure("XMALLOC should not return in failure");
        return 1;
    }


    // Second process
    int pid2 = fork();
    if (pid2 > 0) {
        // without shim
        void * ptr = xcalloc(10, 1);
        free(ptr);

        // With shim
        induce_failure = true;
        ptr = xcalloc(10, 1);
        failure("XCALLOC should not return in failure");
        return 1;
    }

    // Third process
    {
        // Without shim
        FILE * f = xfopen("file.txt", "w");
        fclose(f);

        // With shim
        induce_failure = true;
        f = xfopen("file.txt", "w");
        failure("XFOPEN should not return in failure");
    }
}
