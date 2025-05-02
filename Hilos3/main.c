#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *funcion1();
void *funcion2();

int a =10;



int main()
{
    pthread_t th1, th2;
    pthread_create(&th1, NULL, funcion1, NULL);
    pthread_create(&th2, NULL, funcion2, NULL);
    printf("El thread principal continua ejecutando: %d\n", pthread_self());
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    return 0;
}

void *funcion1(){

    sleep(30);
    a = a * 2;
    printf("\nThread: %d - valor de a: %d", pthread_self(), a);
    pthread_exit(0);
}

void *funcion2(){
    sleep(5);
    a = a + 5;
    printf("\nThread: %d - valor de a: %d", pthread_self(), a);
    pthread_exit(0);
}
