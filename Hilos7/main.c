//ARQ - TP HILOS ADICIONAL - PRACTICA - EJERCICIO 3

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int saldo = 1000;  //variable global

void *sacar_plata(void *arg);

int main()
{
    pthread_t cliente1, cliente2;
    int monto1 = 700, monto2 = 500;

    pthread_create(&cliente1, NULL, sacar_plata, &monto1);
    pthread_create(&cliente2, NULL, sacar_plata, &monto2);

    pthread_join(cliente1, NULL);
    pthread_join(cliente2, NULL);

    printf("Saldo final: %d\n", saldo);



    return 0;
}


void *sacar_plata(void *arg){
    int monto = *(int*)arg;

    if(saldo >= monto){
        printf("Extrayendo %d pesos...\n", monto);
        saldo -= monto;
        printf("Saldo restante: %d\n", saldo);
    }else{
        printf("No hay suficiente saldo para entraer %d pesos\n", monto);
    }
    pthread_exit(0);
}
