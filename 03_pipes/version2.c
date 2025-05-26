#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    if (argc != 2) // Replace with actual condition to check if argv[1] is provided
    {
        printf("Dame un fichero");
        exit(1);
    }
    {
        /* code */
    }
    
    int pipe1[2], pipe2[2];
    pipe(pipe2);

    if (fork())
    {
        // # Abuelo Sort
        close(pipe2[1]);
        close(0);
        dup(pipe2[0]);
        close(pipe2[0]);

        close(1);
        open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0755);

        execlp("sort", "sort", "-u", NULL);
        printf("Error executing sort\n");
        exit(1);
    }
    else
    {
        pipe(pipe1);

        if (fork())
        {
            // # Padre CUT

            // stdin
            close(pipe1[1]);
            close(0);
            dup(pipe1[0]);
            close(pipe1[0]);

            // stdout
            close(pipe2[0]);
            close(1);
            dup(pipe2[1]);
            close(pipe2[1]);

            execlp("cut", "cut", "-c5-12", NULL);
            printf("Error executing cut\n");
        }
        else
        {
            // # Hijo PS
            close(pipe2[0]);
            close(pipe2[1]);

            close(pipe1[0]);
            close(1);
            dup(pipe1[1]);
            close(pipe1[1]);

            execlp("ps", "ps", "-efl", NULL);
            printf("Error executing ps\n");
        }
    }
}
