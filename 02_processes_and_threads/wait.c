#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int result = fork();

    if (result < 0)
    {
        printf("Llamada a Fork fallo");
        exit(-1);
    }
    if (result != 0)
    {
        wait(NULL);
        execlp("ls", "ls");
    }
    else
    {
        execlp("ps", "ps");
    }
    
}