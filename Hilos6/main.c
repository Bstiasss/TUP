//ARQ - TP HILOS ADICIONAL - PRACTICA - EJERCICIO 2

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *sumar(void *arg);

int contador = 0;

int main()
{
    pthread_t hilo1, hilo2;

    pthread_create(&hilo1, NULL, sumar, NULL);
    pthread_create(&hilo2, NULL, sumar, NULL);

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    printf("Valor final del contador: %d \n", contador);

    return 0;
}

void *sumar(void *arg){
    for(int i = 0; i < 100000; i++){
        contador++;
    }
    pthread_exit(NULL);
}
