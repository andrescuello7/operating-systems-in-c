#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int variable = 1;
    
    for (int i = 0; i < 4; i++)
    {
        // fork -> llamada para clonar el proceso
        int result = fork();
        if (result != 0)
        {
            variable++;
            break;
        }
        else
        {
            variable += 2;
        }
    }
    printf("Mi proceso es el %i, Mi padre es %i, resultado %i\n", getpid(), getppid(), variable);
}