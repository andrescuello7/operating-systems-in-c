#include <stdio.h>
#include <stdlib.h>

int main() {
    // HEAP (después de malloc + inicialización)
    // 🧩 Reserva: 5 enteros (20 bytes) en el HEAP.
    // 🧪 Estado inicial: puede contener basura (valores aleatorios) si no se inicializa.
    
    // ┌────────────── HEAP ──────────────┐
    // │ numeros[0] = 1   (dir: 0x500)    │
    // │ numeros[1] = 2   (dir: 0x504)    │
    // │ numeros[2] = 3   (dir: 0x508)    │
    // │ numeros[3] = 4   (dir: 0x50C)    │
    // │ numeros[4] = 5   (dir: 0x510)    │
    // └──────────────────────────────────┘
    
    // 1. malloc: asignar memoria para 5 enteros (sin inicializar)
    int* numeros = (int*) malloc(5 * sizeof(int));
    if (numeros == NULL) {
        printf("No se pudo asignar memoria con malloc.\n");
        return 1;
    }
    // Inicializar con valores
    for (int i = 0; i < 5; i++) {
        numeros[i] = i + 1;
    }

    printf("Valores con malloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");


    // HEAP (después de calloc)
    // 🧩 Reserva: 5 enteros (20 bytes) en el HEAP.
    // 🌱 Estado inicial: todos los valores están en 0.
    
    // ┌────────────── HEAP ──────────────┐
    // │ ceros[0] = 0   (dir: 0x600)      │
    // │ ceros[1] = 0   (dir: 0x604)      │
    // │ ceros[2] = 0   (dir: 0x608)      │
    // │ ceros[3] = 0   (dir: 0x60C)      │
    // │ ceros[4] = 0   (dir: 0x610)      │
    // └──────────────────────────────────┘
    
    // 2. calloc: asignar memoria para 5 enteros (inicializados en 0)
    int* ceros = (int*) calloc(5, sizeof(int));
    if (ceros == NULL) {
        printf("No se pudo asignar memoria con calloc.\n");
        free(numeros);
        return 1;
    }

    printf("Valores con calloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ceros[i]);  // Todos deben ser 0
    }
    printf("\n");

    
    // HEAP (después de realloc y agregar nuevos valores)
    // 🔄 Expansión: se agranda el bloque a 10 enteros (40 bytes).
    // ⚠️ Si no hay espacio contiguo, el sistema:
    
    // Reserva un nuevo bloque
    // Copia los datos anteriores
    // Libera el bloque viejo
    
    // ┌────────────── HEAP ──────────────┐
    // │ numeros[0] = 1   (dir: 0x700)    │
    // │ numeros[1] = 2   (dir: 0x704)    │
    // │ numeros[2] = 3   (dir: 0x708)    │
    // │ numeros[3] = 4   (dir: 0x70C)    │
    // │ numeros[4] = 5   (dir: 0x710)    │
    // │ numeros[5] = 60  (dir: 0x714)    │
    // │ numeros[6] = 70  (dir: 0x718)    │
    // │ numeros[7] = 80  (dir: 0x71C)    │
    // │ numeros[8] = 90  (dir: 0x720)    │
    // │ numeros[9] = 100 (dir: 0x724)    │
    // └──────────────────────────────────┘
    
    // 3. realloc: agrandar el arreglo de 'numeros' a 10 enteros
    int* nuevos_numeros = (int*) realloc(numeros, 10 * sizeof(int));
    if (nuevos_numeros == NULL) {
        printf("No se pudo reasignar memoria con realloc.\n");
        free(numeros);
        free(ceros);
        return 1;
    }
    numeros = nuevos_numeros;

    // Agregar nuevos valores
    for (int i = 5; i < 10; i++) {
        numeros[i] = (i + 1) * 10;
    }

    printf("Valores después de realloc:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    // 4. Liberar la memoria
    free(numeros);
    free(ceros);

    return 0;
}
