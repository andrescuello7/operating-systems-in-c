#include <stdio.h>

// +--------------------+       +-----------------------+
// |    Variable "a"    |       |   Variable "puntero"  |
// +--------------------+       +-----------------------+
// | Valor:      5      |       | Valor: dirección de a |
// | Dirección:  0x100  |       | Dirección:   0x200    |
// +--------------------+       +-----------------------+

// Representación:
// ┌────────────┐             ┌──────────────────────┐
// │     a      │             │      puntero         │
// └────────────┘             └──────────────────────┘
// │ Valor: 5   │             │ Valor: 0x100         │
// │ Dir: 0x100 │◄────────────┘ Dir:  0x200          │
// └────────────┘             └──────────────────────┘

// Explicación:
// - `a` es una variable de tipo `int` que almacena el valor `5`. Su dirección de memoria (ficticia) es `0x100`.
// - `puntero` es una variable de tipo `int*` (puntero a int), y guarda la dirección de memoria de `a`, o sea `0x100`.
// - `*puntero` accede al valor almacenado en la dirección a la que apunta (`a`), o sea `5`.


int main(){
    int a = 5;
    int *puntero = &a;

    printf("El valor de a es: %d\n", a);
    printf("El puntero de a es: %p\n", &a);
    printf("El puntero guarda la direccion de: %p\n", &puntero);
    printf("El valor donde la direccion que apunta el puntero es: %i\n", *puntero);
}