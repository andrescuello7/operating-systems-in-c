#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// +-------------+
// |    stdin    |
// +-------------+
// |   stdout    |
// +-------------+
// |   stderr    |
// +-------------+
// |   pipe1[0]  |
// +-------------+
// |   pipe1[1]  |
// +-------------+

int main(int argc, char **argv){
    int pipe1[2];
    pipe(pipe1);
    char s[64];

    if (fork())
    {
        // Padre
        close(pipe1[1]);
        read(pipe1[0], s, 64);
        close(pipe1[0]);
        printf("Soy el Padre he leido en el descriptor %i la cadena: %s\n", pipe1[0], s);
    }
    else
    {
        // Hijo
        strcpy(s, "Hola mundo curso sistemas operativos");
        close(pipe1[0]);
        write(pipe1[1], s, strlen(s));
        close(pipe1[1]);
        printf("Soy el hijo es escrito en el descriptor %i la cadena: %s\n", pipe1[1], s);
    }
}