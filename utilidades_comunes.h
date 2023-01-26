#ifndef UTILIDADES_COMUNES_H
#define UTILIDADES_COMUNES_H
// *. ¿Qué es el preprocesador?
// *. ¿Qué es una guarda de inclusión?
// *. Mencione el nombre completo y característica de los tres estándares
//    mayores del lenguaje C (C90, C99 y C11) y las dos revisiones menores
//    (C95 y C17)

#if defined(_MSC_VER)
# error "El compilador de Visual Studio no puede comprender este código"
// *. Haga una lista de las directivas de preprocesador del lenguaje C
// *. ¿Qué tan bueno es el soporte del lenguaje C por parte del compilador
//    MSVC (Compilador de C/C++ de Microsoft)? ¿Por qué?. Instale gcc, clang y
//    musl-gcc
#endif

/*#pragma GCC system_header*/
// *. ¿Qué es un pragma?
// *. Liste los pragma's estándar de C11
// *. ¿Qué es el pragma "system_header" específico de GCC?

// ##### Utilidades generales #####
#include <stdio.h>

#define TEXTO_LITERAL_A_CADENA(arg) #arg
#define ARG_MACRO_A_CADENA(arg)     TEXTO_LITERAL_A_CADENA(arg)
#define IMPRIMIR(formato, ...)      printf(" " formato "\n", ## __VA_ARGS__)
#define IMPRIMIR_ERR(formato, ...)  fprintf(stderr, " " formato "\n", ## __VA_ARGS__)
#ifdef __GCC__
#define TAM_ARREGLO(array)                                                                                \
    ({                                                                                                   \
        _Static_assert                                                                                   \
        (                                                                                                \
            ! __builtin_types_compatible_p(typeof(array), typeof(& array[0])),                           \
            "ARRAY_SIZE: " TEXTO_LITERAL_A_CADENA(array) " [expanded from: " # array "] is not an array" \
        );                                                                                               \
        sizeof(array) / sizeof((array)[0]);                                                              \
    })
#else
#define TAM_ARREGLO(arr)            (sizeof(arr) / sizeof(*(arr)))
#endif // __GCC__
#define EXPANDIR_ARREGLO(arr)       TAM_ARREGLO(arr), (arr)
#define LEER_ARR_CHAR(arr)          leerCad(EXPANDIR_ARREGLO(arr))

//La versión con void * tope_aplicar = (int[]){ 0 } solo funciona en arr de ptr
// Se puede declarar (tipo * []) { NULL }
#define APLICAR_A_LISTA_ESTATICA(tipo, fun, ...)                             \
    do {                                                                     \
        tipo lista_para_aplicar[] = {__VA_ARGS__ };                          \
        size_t tamanio = sizeof(lista_para_aplicar) / sizeof(tipo);          \
        for (size_t i = 0; i < tamanio; ++i) {                               \
            fun(lista_para_aplicar[i]);                                      \
        }                                                                    \
    } while (0)
// *. ¿Qué es una macro?
// *. Tipos de macros.
// *. Ventajas y desventajas de utilizar una macro-función en lugar de una
// función.
// *. Operadores que se pueden usar con los argumentos de las macros.
// *. Diferencia entre una variable y una literal.
// *. Diferencia entre un lvalue y un rvalue.
// *. ¿Qué es la concatenación de cadenas en tiempo de compilación?
//     ¿Qué parte del compilador se encarga de ella?
// *. ¿Por qué no se puede obtener el tamaño de un arreglo recibido como
//     parámetro? Defina decaimiento a puntero.
// *. ¿Qué es una macro de argumentos variables y cómo se usa?
// *. ¿Que herramientas no estándar (extensiones) proporciona GCC al
//     manejar macros de argumentos variables?

static inline char * leerCad(int tam, char cad[tam])
{
    return fgets(cad, tam, stdin);
}
// *. ¿Por qué se declaró obsoleta la función gets() en C99 y se eliminó en C11?
// *. Liste las clases de almacenamiento en C y su utilidad (incluido static).
// *. Liste los atributos de tipo del lenguaje C y su utilidad.
// *. ¿Qué son los especificadores de función? (incluido inline)
// *. ¿Qué es un atributo imperativo y uno no imperativo?

static inline void limpiarBufferEntrada(void)
{
    int ch;
    do {
        ch = getchar();
    } while (ch != '\n' && ch != EOF);
}
// *. ¿Qué es la macro EOF?
// *. ¿Por qué al iterar hasta EOF se tiene que usar un entero?
// *. ¿Por qué no se debe usar fflush(stdin) para limpiar el buffer de entrada?

#include <inttypes.h>
#include <stdio.h>

#include "intercambiar.h"
// *. Explique el operador no estándar typeof() y sus posibles usos

#include "ciclos.h"

// *. ¿Qué es una característica opcional del lenguaje C y en qué se
//     diferencia con una características no estándar?
// *. Liste las características opcionales del lenguaje C.
// *. ¿Qué son los enteros de tamaño fijo? ¿Por qué son una característica
//     opcional del lenguaje C?
// *. Mencione los grupos de alias de enteros definidos en la
//     cabecera stdint.h
// *. ¿Cómo imprimo de forma portable un entero de los definidos en la
//     cabecera anterior?

// *. ¿Qué es el tipo de dato size_t y para qué sirve?
// *. ¿Qué funciones hacen uso de dicho tipo de dato?
// *. ¿Cómo imprimo dicho tipo de dato con printf()?

#define REPEAT(n) for (ssize_t _ = 0; _ < MAXIMO(0, (ssize_t)n); _++)

#include <stdarg.h>
// *. ¿Cómo puedo recibir argumentos variables en una función normal?
// *. Mencione los problemas de seguridad de las macros de argumentos
//     variables.

// ##### Tratamiento de errores #####
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
static_assert(__STDC_VERSION__ >= 199901L,
              "Use la bandera -std=gnu11 al llamar al compilador");
// *. ¿Qué es una aserción y para qué sirve?
// *. En el lenguaje C, ¿Cómo se hace una aserción en tiempo de ejecución y
//    como se hace una aserción en tiempo de compilación?
// *. ¿De qué sirve la macro NDEBUG en C?

#ifndef NDEBUG
# define COMPROBAR_CONDICION(condicion, accionesSiFalla)                     \
    do {                                                                     \
        if (!(condicion)) {                                                  \
            fprintf(stderr, __FILE__ ": " ARG_MACRO_A_CADENA(__LINE__) "."   \
                    " ¡La condición (" #condicion ") ha fallado!");          \
            { accionesSiFalla; }                                             \
            exit(EXIT_FAILURE);                                              \
        }                                                                    \
    } while (0)
#else
# define COMPROBAR_CONDICION(condicion, accionesSiFalla)
#endif
// *. ¿Qué función tiene la estructura FILE?
// *. ¿Qué es un flujo de datos (data stream)?
// *. ¿Cuales son los flujos abiertos por defecto en un programa en C?
//     ¿Qué nombre reciben?
// *. ¿Cómo redirigir flujos de datos con el sistema operativo y como
//     hacerlo directamente desde C?

#define SALIR_SI_HAY_ERROR()                                                 \
    do {                                                                     \
        if (errno) {                                                         \
            perror("Error");                                                 \
            exit(EXIT_FAILURE);                                              \
        }                                                                    \
    } while (0)
// *. ¿Para qué sirve la función perror()?
// *. ¿Cuál es la diferencia entre "return valor" y "exit(valor)"?
// *. ¿Qué son las macros EXIT_FAILURE y EXIT_SUCCESS y donde están definidas?

#include <setjmp.h>
#include <signal.h>
typedef void (* manejador_senial)(int);
// *. ¿Cómo se puede simular manejo de excepciones en lenguaje C?

// ##### Manejo de memoria #####
#include "xfunctions.h"
#include "memory_allocation.h"

#define LIBERAR_ARGS(...) APLICAR_A_LISTA_ESTATICA(void *, free, __VA_ARGS__)

// ##### Operaciones matemáticas #####

#include <tgmath.h>
#include <fenv.h>
// *. ¿Qué es una excepción de punto flotante y cuando se generar una?

#include <float.h>
#include <limits.h>
// *. ¿Por qué hay cabeceras que definen los límites y características de
//     los tipos de datos básicos? ¿Qué no siempre son iguales?

#include <stdbool.h>
// *. ¿Qué son las macros de tipo genérico?
// *. ¿Qué se define en la cabecera tgmath?
// *. ¿Cómo hago mis propias macros de tipo genérico?

#define MAXIMO(a, b)                                                         \
    ({                                                                       \
        typeof(a) _a = (a);                                                  \
        typeof(b) _b = (b);                                                  \
        _a > _b ? _a : _b;                                                   \
    })
#define MINIMO(a, b)                                                         \
    ({                                                                       \
        typeof(a) _a = (a);                                                  \
        typeof(b) _b = (b);                                                  \
        _a < _b ? _a : _b;                                                   \
    })
// *. ¿Cómo usar las expresiones de sentencia (extensión de GCC)?

#define _GENERAR_FUNCIONES_MAX_MIN(nombre, tipo)                             \
    static inline tipo maximo##nombre(size_t n, tipo vec[n])                 \
    {                                                                        \
        COMPROBAR_CONDICION(n != 0,                                          \
            IMPRIMIR_ERR("No se puede sacar el mayor de 0 elementos\n"));    \
        tipo mayor_actual = vec[0];                                          \
        FOR_RANGO(i, 1, n - 1, mayor_actual = MAXIMO(mayor_actual, vec[i])); \
        return mayor_actual;                                                 \
    }                                                                        \
    static inline tipo minimo##nombre(size_t n, tipo vec[n])                 \
    {                                                                        \
        COMPROBAR_CONDICION(n != 0,                                          \
            IMPRIMIR_ERR("No se puede sacar el menor de 0 elementos\n"));    \
        tipo menor_actual = vec[0];                                          \
        FOR_RANGO(i, 1, n - 1, menor_actual = MINIMO(menor_actual, vec[i])); \
        return menor_actual;                                                 \
    }                                                                        \

_GENERAR_FUNCIONES_MAX_MIN(Doble, double);
_GENERAR_FUNCIONES_MAX_MIN(LongDoble, long double);
_GENERAR_FUNCIONES_MAX_MIN(Entero, int);
_GENERAR_FUNCIONES_MAX_MIN(LongEntero, long);
_GENERAR_FUNCIONES_MAX_MIN(LongLongEntero, long long);

#define MAXIMO_VECTOR(primero, ...)                                          \
    (_Generic(primero,                                                       \
              float          : maximoDoble,                                  \
              double         : maximoDoble,                                  \
              long double    : maximoLongDoble,                              \
              long           : maximoLongEntero,                             \
              unsigned       : maximoLongLongEntero,                         \
              unsigned long  : maximoLongLongEntero,                         \
              long long      : maximoLongLongEntero,                         \
              unsigned long long: maximoLongLongEntero,                      \
              default        : maximoEntero))                                \
                    (sizeof((typeof(primero)[]){primero, __VA_ARGS__})       \
                     / sizeof(typeof(primero)),                              \
                     (typeof(primero)[]){primero, __VA_ARGS__})

#define MINIMO_VECTOR(primero, ...)                                          \
    (_Generic(primero,                                                       \
              float          : minimoDoble,                                  \
              double         : minimoDoble,                                  \
              long double    : minimoLongDoble,                              \
              long           : minimoLongEntero,                             \
              unsigned       : minimoLongLongEntero,                         \
              unsigned long  : minimoLongLongEntero,                         \
              long long      : minimoLongLongEntero,                         \
              unsigned long long: minimoLongLongEntero,                      \
              default        : minimoEntero))                                \
                    (sizeof((typeof(primero)[]){primero, __VA_ARGS__})       \
                     / sizeof(typeof(primero)),                              \
                     (typeof(primero)[]){primero, __VA_ARGS__})
// *. ¿Qué es una literal compuesta?
// *. ¿Cuándo se evalúa el argumento del operador sizeof()?
//     (Compilación o ejecución)

#define _GENERAR_FUNCION_PROMEDIO(nombre, tipo)                              \
    static inline tipo promedio##nombre(size_t n, tipo vec[n])               \
    {                                                                        \
        COMPROBAR_CONDICION(n != 0,                                          \
            IMPRIMIR_ERR("No se puede sacar promedio de 0 elementos\n"));    \
        tipo suma = 0;                                                       \
        FOR_RANGO(i, 0, n - 1, suma += vec[i]);                              \
        return suma / n;                                                     \
    }

_GENERAR_FUNCION_PROMEDIO(Doble, double);
_GENERAR_FUNCION_PROMEDIO(LongDoble, long double);
#if !defined(__STDC_NO_COMPLEX__)
_GENERAR_FUNCION_PROMEDIO(Complejo, complex double);
_GENERAR_FUNCION_PROMEDIO(ComplejoDoble, complex long double);
#endif
// *. ¿Cómo funcionan los números de punto flotante?
// *. ¿Cuantos tipos de dato de punto flotante existen en lenguaje C?
// *. ¿Cómo se usan correctamente los números complejos en el lenguaje C?

#if !defined(__STDC_NO_COMPLEX__)
# define PROMEDIO(primero, ...)                                              \
    (_Generic((primero) + 0.0,                                               \
              complex double      : promedioComplejo,                        \
              complex long double : promedioComplejoDoble,                   \
              long double         : promedioLongDoble,                       \
              default             : promedioDoble))                          \
                    (sizeof((typeof(primero)[]){primero, __VA_ARGS__})       \
                     / sizeof(typeof(primero)),                              \
                     (typeof((primero) + 0.0)[]){primero, __VA_ARGS__})
#else
# define PROMEDIO(primero, ...)                                              \
    (_Generic((primero) + 0.0,                                               \
              long double         : promedioLongDoble,                       \
              default             : promedioDoble))                          \
                    (sizeof((typeof(primero)[]){primero, __VA_ARGS__})       \
                     / sizeof(typeof(primero)),                              \
                     (typeof((primero) + 0.0)[]){primero, __VA_ARGS__})
#endif

// Se usa fabs de tgmath, que se expande a la función correspondiente
#define _GENERAR_FUNCION_COMPARAR_FLOTANTES(nombre, tipo)                    \
    static inline bool comparar##nombre(tipo val1, tipo val2,                \
                                        double epsilon)                      \
    {                                                                        \
        return (fabs(val1 - val2) <= epsilon * fabs(val1));                  \
    }
// *. ¿Por qué no es seguro comparar números de punto flotante?

_GENERAR_FUNCION_COMPARAR_FLOTANTES(Doble, double);
_GENERAR_FUNCION_COMPARAR_FLOTANTES(LongDoble, long double);
_GENERAR_FUNCION_COMPARAR_FLOTANTES(Complejo, complex double);
_GENERAR_FUNCION_COMPARAR_FLOTANTES(ComplejoDoble, complex long double);

#if !defined(__STDC_NO_COMPLEX__)
#define COMPARAR_CON_EPSILON(val1, val2, delta)                              \
    (_Generic((val1) + (val2) + 0.0,                                         \
              complex double      : compararComplejo,                        \
              complex long double : compararComplejoDoble,                   \
              long double         : compararLongDoble,                       \
              default             : compararDoble))                          \
                    (val1, val2, delta)
#else
#define COMPARAR_CON_EPSILON(val1, val2, delta)                              \
    (_Generic((val1) + (val2) + 0.0,                                         \
              long double         : compararLongDoble,                       \
              default             : compararDoble))                          \
                    (val1, val2, delta)
#endif

// ##### Números aleatorios #####
#include <stdlib.h>
#include <time.h>
static inline void plantarSemilla(void) { srand(time(NULL)); }
// *. ¿Qué es un generador de números pseudoaletorios?
// *. ¿Para qué sirve la semilla del generador pseudoaleatorio?
// *. ¿Es posible generar números verdaderamente aleatorios?

struct argumentoFuncionAleatorio { int a, b; };
static inline int aleatorioStruct(struct argumentoFuncionAleatorio rango)
{
    int mayor = MAXIMO(rango.a, rango.b);
    int menor = MINIMO(rango.a, rango.b);

    return rand() % (mayor - menor + 1) + menor;
}

#define ALEATORIO(...)                                                       \
    aleatorioStruct((struct argumentoFuncionAleatorio){__VA_ARGS__})

// ##### Manejo de cadenas #####

#include <ctype.h>
#include <string.h>
// *. Mencione los distintos tipos de cadenas en lenguaje c y sus prefijos.
// *. ¿Qué significa que las funciones de caracteres sean dependientes de la
//     plataforma?

#include <locale.h>
#include <uchar.h>
// *. ¿Cómo cambiar el tipo de flujo del programa de flujo de bytes a flujo
//     y para qué me sirve?

#include "cadenas.h"

// ##### Hilos y sincronización #####
// *. Dejando de lado las optimizaciones que pueda hacer el compilador. ¿Qué
//    utilidad tiene la palabra "restrict"?

#if !defined(__STDC_NO_ATOMICS__)
# include <stdatomic.h>
#endif
#if !defined(__STDC_NO_THREADS__)
# include <threads.h>
#endif
// *. ¿Qué es una operación atómica?
// *. ¿Qué es un tipo de dato atómico?
// *. ¿Cómo usar la API de manejo de hilos de C11?
// *. ¿Qué bibliotecas libres implementan la API antes mencionada? ¿Por qué
//    glib no la implementa (D:)?

// ##### Alias variados #####

#include <iso646.h>
#define eq ==
#define gt >
#define lt <
#define ge >=
#define le <=

#include <stdalign.h>
#include <stdbool.h>
#include <stdnoreturn.h>
// *. ¿Por qué existen cabeceras exclusivamente para crear alias?
// *. ¿Qué alias permiten usar las cabeceras anteriores?

#endif /* UTILIDADES_COMUNES_H */
