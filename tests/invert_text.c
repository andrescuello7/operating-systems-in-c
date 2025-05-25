#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Patente {
    char *value;
};

int main(int argc, char **argv)
{
    struct Patente p = { .value = argv[1] };

    size_t length = strlen(p.value);
    char *inverted = malloc(length + 1);

    for (size_t i = 0; i <= length; i++)
    {
        inverted[i] = p.value[length - 1 - i];
    }

    printf("\n");
    printf("- Puntero %p\n", (void*)&p.value);
    printf("- Primer Parametro %c\n", *p.value);
    printf("- Original %s\n", p.value);
    printf("- Invertido %s\n", inverted);

    free(inverted);
    return 0;
}