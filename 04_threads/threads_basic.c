#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_func(void *arg) {
    int valor_pasado = *(int*)arg;
    printf("El valor recibido es %i\n", valor_pasado);

    pthread_exit(0);
}

int main() {
    pthread_t thread1, thread2;
    int valor1 = 5, valor2 = 10;
    pthread_create(&thread1, NULL, thread_func, &valor1);
    pthread_create(&thread2, NULL, thread_func, &valor2);
    printf("Soy el hilo principal.\n");
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}
// gcc -o threads_basic threads_basic.c -lpthread