#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

#define MAX 10

void *funcion1(int *i);

int main()
{
    pthread_t thid[10];

    for(int i = 0; i < MAX; i++){
        pthread_create(&thid[i], NULL, funcion1, i);

    }

    printf("Start sleep\n");
    Sleep(10000);
    printf("End sleep\n");


    return 0;
}

void *funcion1(int *i){
    printf("Thread: %d, el valor de i: %d\n", pthread_self(),i);
    pthread_exit(0);
}
