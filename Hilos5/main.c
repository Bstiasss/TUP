//ARQ - TP HILOS ADICIONAL - PRACTICA - EJERCICIO 1

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>
#include <semaphore.h>

void thread_code1();
void thread_code2();
void thread_code3();

int x = 3; //variables globales
sem_t semaforoA;
sem_t semaforoB;
sem_t semaforoC;

int main()
{
    pthread_t hilo1, hilo2, hilo3;

    sem_init(&semaforoA, 0, 0);
    sem_init(&semaforoB, 0, 1);
    sem_init(&semaforoC, 0, 0);

    printf("Hilo Main: %d \n", pthread_self());

    pthread_create(&hilo1, NULL, thread_code3, NULL);
    pthread_create(&hilo2, NULL, thread_code2, NULL);
    pthread_create(&hilo3, NULL, thread_code1, NULL);

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    pthread_join(hilo3, NULL);

    sem_destroy(&semaforoA);
    sem_destroy(&semaforoB);
    sem_destroy(&semaforoC);

    return 0;
}

void thread_code1(){
    sem_wait(&semaforoA);
    x = x * 3;
    printf("La variable x vale %d \n", x);
    sem_post(&semaforoC);

    pthread_exit(0);
}

void thread_code2(){
    sem_wait(&semaforoB);
    x++;
    printf("La variable x vale %d \n", x);
    sem_post(&semaforoA);

    pthread_exit(0);
}

void thread_code3(){
    sem_wait(&semaforoC);
    x = 5;
    printf("La variable x vale %d \n", x);
    sem_post(&semaforoB);

    pthread_exit(0);
}
