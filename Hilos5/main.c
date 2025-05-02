//ARQ - TP HILOS ADICIONAL - PRACTICA - EJERCICIO 1

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

int x = 3; //variable global

void thread_code1();
void thread_code2();
void thread_code3();

int main()
{
    pthread_t hilo1, hilo2, hilo3;

    printf("Hilo Main: %d \n", pthread_self());

    pthread_create(&hilo1, NULL, thread_code3, NULL);
    pthread_create(&hilo2, NULL, thread_code2, NULL);
    pthread_create(&hilo3, NULL, thread_code1, NULL);

    //pthread_join(hilo1, NULL);
    //pthread_join(hilo2, NULL);
    pthread_join(hilo3, NULL);

    return 0;
}

void thread_code1(){
    pthread_exit(0);
    x = x * 3;
    printf("La variable x vale %d \n", x);
}

void thread_code2(){
    x++;
    printf("La variable x vale %d \n", x);
    pthread_exit(0);
}

void thread_code3(){
    x = 5;
    pthread_exit(0);
    printf("La variable x vale %d \n", x);
}
