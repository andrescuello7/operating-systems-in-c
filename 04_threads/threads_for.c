#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 100

int num_threads;
int *array;
int *thread_result;

void *sum(void *arg) {
    int id = *(int*)arg;
    int nums_to_sum = SIZE / num_threads;
    int start = id * nums_to_sum;
    int end = nums_to_sum + start;

    int sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += array[i];
    }
    thread_result[id] = sum;
    printf("Hilo %i ha terminado con resultado %i\n", id, sum);

    pthread_exit(0);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Dame el numero de hilos\n");
        exit(-1);
    }

    num_threads = atoi(argv[1]);
    array = malloc(SIZE * sizeof(int));
    thread_result = malloc(num_threads * sizeof(int));

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = i + 1;
    }

    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    int total = 0;

    for (int i = 0; i < num_threads; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, sum, (void*)&thread_ids[i]);
    }
    
    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
        total += thread_result[i];
    }
    
    printf("Total: %d\n", total);
    
    free(array);
    free(thread_result);
}
