#include <stdio.h>
#include <stdlib.h>

// Stack | is allocated in the stack
// ┌────────────── STACK ──────────────┐
// │                                  │
// │ stackArray[0] = 1  (dir: 0x100)  │
// │ stackArray[1] = 2  (dir: 0x104)  │
// │ stackArray[2] = 3  (dir: 0x108)  │
// │ stackArray[3] = 4  (dir: 0x10C)  │
// │ stackArray[4] = 5  (dir: 0x110)  │
// │                                  │
// └──────────────────────────────────┘
int main()
{
    int stackArray[] = {1, 2, 3, 4, 5};
    printf("El valor de array es: %p\n", stackArray);

    // Heap | is allocated in the heap
    // ┌────────────── HEAP ──────────────┐
    // │                                  │
    // │ heapArray[0] = 1  (dir: 0x200)   │
    // │ heapArray[1] = 2  (dir: 0x204)   │
    // │ heapArray[2] = 3  (dir: 0x208)   │
    // │ heapArray[3] = 4  (dir: 0x20C)   │
    // │ heapArray[4] = 5  (dir: 0x210)   │
    // │                                  │
    // └──────────────────────────────────┘
    // ┌────────────── HEAP ──────────────┐
    // │                                  │
    // │ heapArray[5] = 6  (dir: 0x214)   │
    // │ heapArray[6] = 7  (dir: 0x218)   │
    // │ heapArray[7] = 8  (dir: 0x21C)   │
    // │ heapArray[8] = 9  (dir: 0x220)   │
    // │ heapArray[9] = 10 (dir: 0x224)   │
    // │                                  │
    // └──────────────────────────────────┘
    int *heapArray = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        heapArray[i] = i + 1;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Valor de array[%i] = %i\n", i, heapArray[i]);
    }

    free(heapArray);
}
