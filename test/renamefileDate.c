#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    int id;
} ThreadStruct;

#define SIZE 100
char *directoy_name;

void add_log(const char *directory_path, const char *mensaje) {
    char path[1024];
    snprintf(path, sizeof(path), "./log.txt");

    FILE *file = fopen(path, "a");
    if (file == NULL) {
        perror("No se pudo abrir el archivo");
        return;
    }

    fprintf(file, "%s\n", mensaje);
    fclose(file);
}

// This is the code to change name in the sub_directory
void change_name_sub_dir(char *sub_directoy, char *filename, char *new_name, int thread_id){
    char old_path[1024];
    snprintf(old_path, sizeof(old_path), "%s/%s", sub_directoy, filename);

    char new_filename[1024];
    snprintf(new_filename, sizeof(new_filename), "%s.txt", new_name);

    char new_path[1024];
    snprintf(new_path, sizeof(new_path), "%s/%s", sub_directoy, new_filename);
    
    if (rename(old_path, new_path) != 0) {
        perror("Error: renombrando directorio");
    } else {
        char log[1024];
        snprintf(log, sizeof(log), "- Se cambio el nombre del directorio [%s] por [%s]\n", filename, new_filename);
        add_log(sub_directoy, log);
        printf("Renombrar: %s -> %s | Hilo %i\n", old_path, new_path, thread_id);
    }
}

// Directories in this Directory?
void *find_directories(void *arg){
    ThreadStruct *thread_data = (ThreadStruct*)arg;

    char *sub_directoy_name;
    struct dirent *dp;
    DIR *open_directory;

    open_directory = opendir(directoy_name);
    while ((dp = readdir(open_directory)) != NULL){
        struct stat data;

        if (stat(directoy_name, &data) != 0)
        {
            printf("Ha fallado la llamada a stat\n");
            exit(-1);
        }

        if (strcmp(dp->d_name, ".") && strcmp(dp->d_name, ".."))
        {
            char *new_name = ctime(&data.st_mtime);
            change_name_sub_dir(directoy_name, dp->d_name, new_name, thread_data->id);
        }
    }
    closedir(open_directory);

    sleep(1);
    pthread_exit(0);
}

// Method for tasks to Number of Threads
void threads_find_directories(int num_threads){
    pthread_t threads[num_threads];
    ThreadStruct thread_data[num_threads];
    
    for (int i = 0; i < num_threads; i++)
    {
        thread_data[i].id = i;
        pthread_create(&threads[i], NULL, find_directories, (void*)&thread_data[i]);
    }
    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }
}

// Is Argv[1] a Directory?
void is_directory(char *directoy_name){
    if (errno == ENOENT)
    {
        printf("Error: Este directorio no existe\n");
        exit(-1);
    }
    
    struct stat data;
    if (stat(directoy_name, &data))
    {
        printf("Error: No se hizo en STAT\n");
        exit(-1);
    }

    if (!S_ISDIR(data.st_mode))
    {
        printf("Error: %s No es un directorio\n", directoy_name);
        exit(-1);
    }
}

int main(int argc, char **argv){
    if(argc != 5 || strcmp(argv[1], "-d") != 0 || strcmp(argv[3], "-h") != 0){
        printf("$ renamefileDate -d [directorio] -h [num hilos]!\n");
        exit(-1);
    }
    
    // Define File Path of Directories and Numbers of Threads
    directoy_name = argv[2];
    int num_threads = atoi(argv[4]);
    
    is_directory(directoy_name);
    threads_find_directories(num_threads);

    return 0;
}
