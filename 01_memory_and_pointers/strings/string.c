#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // [hello] --> | 'H' | 'o' | 'l' | 'a' | '\0' |
    // [chau]  --> | 'E' | 'x' | 'i' | 't' | '\0' |

    char hello[] = {'H', 'o', 'l', 'a', '\0'};
    char chau[] = "Exit";

    printf("- Saludo: %s\n", hello);
    printf("- Salida: %s\n", chau);

    char **saludo = malloc(2 * sizeof(char*));
    char *msg1 = malloc(8 * sizeof(char));
    char *msg2 = malloc(8 * sizeof(char));

    // saludo (char**) --> +--------+--------+
    //                     | msg1 * | msg2 * |
    //                     +--------+--------+
    //                          ↓         ↓
    //                        msg1      msg2
    //                     +--------+ +------------------+
    //                     | ? ? ? ?| | ? ? ? ? ? ? ? ?  |
    //                     +--------+ +------------------+


    strcpy(msg1, "Hola");
    strcpy(msg2, "Hasta luego");

    saludo[0] = msg1;
    saludo[1] = msg2;

    printf("- Saludo: %s\n", saludo[0]);
    printf("- Salida: %s\n", saludo[1]);

//     saludo --> +------------+---------------+
//                | saludo[0]  | saludo[1]     |
//                | → msg1     | → msg2        |
//                +------------+---------------+

//    msg1 →  | 'H' | 'o' | 'l' | 'a' | '\0' | ? | ? | ? |
//    msg2 →  | 'H' | 'a' | 's' | 't' | 'a' | ' ' | 'l' | ... |
//     ↑ texto copiado → "Hasta luego" (¡más largo que 8 bytes!)

}
