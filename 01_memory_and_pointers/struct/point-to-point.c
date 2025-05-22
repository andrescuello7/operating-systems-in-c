#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};


//  [STACK]
// +-------+
// |  head | ────────┐
// +-------+         │
//                   ↓
//    [HEAP] Nodo 1
// +--------+----------+
// |  1     |  *next   | ──→ Nodo 2
// +--------+----------+

//    [HEAP] Nodo 2
// +--------+----------+
// |  2     |  NULL    |
// +--------+----------+

int main()
{
    struct Node *head = malloc(sizeof(struct Node));
    head->value = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->value = 2;

    printf("Value of nodo 1: %i\n", head->value);
    printf("Direction of nodo 1: %p\n\n", head); // 0x12df04120...

    printf("Value of nodo 2: %i\n", head->next->value);
    printf("Direction of nodo 2: %p\n", head->next); // 0x12df042e0...
}
