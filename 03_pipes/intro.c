#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// +-------------+
// |   stdin     |
// +-------------+
// |   stdout    |
// +-------------+
// |   stderr    |
// +-------------+
// | pipe1[0]-> r|
// +-------------+
// | pipe1[1]-> w|
// +-------------+

int main(int argc, char **argv){
    int pipe1[2];
    pipe(pipe1);
    char s[64];

    if (fork())
    {
        // Padre -> Leer
        close(pipe1[1]);
        // read(pipe1[0], s, 64);
        // close(pipe1[0]);
        close(0); // Cierra stdin
        dup(pipe1[0]); // Redirige stdin al pipe
        close(pipe1[0]); // Cierra el descriptor original del pipe
        
        // Ahora stdin está redirigido al pipe
        read(0, s, 64); // Lee del pipe
        printf("Soy el Padre he leido desde stdin la cadena: %s\n", s);
    }
    else
    {
        // Hijo -> Escribir
        strcpy(s, "Hola Mundo - Curso Sistemas Operativos");
        printf("%s", s);
        close(pipe1[0]);

        // write(pipe1[1], s, strlen(s));
        // close(pipe1[1]);
        
        close(1); // Cierra stdout
        dup(pipe1[1]); // Redirige stdout al pipe
        close(pipe1[1]); // Cierra el descriptor original del pipe

        // Ahora stdout está redirigido al pipe
        printf("%s", s);
    }
}
