//ARQ - TP - EJERCICIO 7

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *imprimirMensaje();

int main()
{
    pthread_t hiloArr[10];

    for(int i = 0; i < 10; i++){
        pthread_create(&hiloArr[i], NULL, imprimirMensaje, NULL);
    }

    for(int i = 0; i < 10; i++){
        pthread_join(hiloArr[i], NULL);
    }

    return 0;
}


void *imprimirMensaje()
{
    for(int i = 1; i <= 1000; i++)
    {
        printf("\nHola Threads!. Soy el thread %i ejecuntando por %i vez.", pthread_self(), i);

    }

    pthread_exit(0);

}

