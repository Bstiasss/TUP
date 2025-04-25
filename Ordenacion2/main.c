#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


void insertar(int arreglo[],int i,int dato);
void ordenarArregloPorInsercion(int arreglo[], int validos);

int posicionMenor(int arreglo[],int i, int validos);
void ordenarArregloPorSeleccion(int arreglo[], int validos);

void ordenarPilaPorInsercion(Pila pilaDada, Pila *pilaOrdenada);
void ordenarPilaPorSeleccion(Pila pilaDada, Pila *pilaOrdenada);

void mostrarArreglo(int array[], int validos);


int main()
{
    Pila pilaDada;
    Pila pilaOrdenada;
    inicpila(&pilaDada);
    inicpila(&pilaOrdenada);
    apilar(&pilaDada, 7);
    apilar(&pilaDada, 8);
    apilar(&pilaDada, 2);
    apilar(&pilaDada, 6);
    apilar(&pilaDada, 4);
    apilar(&pilaDada, 1);
    apilar(&pilaDada, 9);
    apilar(&pilaDada, 3);

    mostrar(&pilaDada);
   // ordenarPilaPorInsercion(pilaDada,&pilaOrdenada);
    ordenarPilaPorSeleccion(pilaDada,&pilaOrdenada);
    mostrar(&pilaOrdenada);

    int array[]= {6,8,4,10,3};

    mostrarArreglo(array, 5);

    // ordenarArregloPorInsercion(array, 5);

    ordenarArregloPorSeleccion(array, 5);

    printf("\n");
    mostrarArreglo(array, 5);


    return 0;
}


void ordenarArregloPorInsercion(int arreglo[], int validos)
{

    int i = 0;
    while(i < validos -1)
    {
        insertar(arreglo,i,arreglo[i+1]);
        i++;
    }

}

//funcion para insertar datos, le paso el arreglo, la posicion para que empiece y el dato

void insertar(int arreglo[],int i,int dato)
{
    while(i >= 0 && dato < arreglo[i])
    {
        arreglo[i+1] = arreglo[i];
        i--;
    }
    arreglo[i+1]= dato;
}



void ordenarArregloPorSeleccion(int arreglo[], int validos)
{

    int posMenor;
    int aux;
    int i = 0;

    while(i < validos -1)
    {

        posMenor = posicionMenor(arreglo, i, validos);
        aux = arreglo[i];
        arreglo[i] = arreglo[posMenor];
        arreglo[posMenor]= aux;

        i++;
    }



}

int posicionMenor(int arreglo[],int i, int validos)
{

    int posMenor = i; //asumo que estoy en la menor

    while(i < validos)
    {
        if(arreglo[posMenor] > arreglo[i])
        {

            posMenor = i;
        }
        i++;
    }

    return posMenor;
}

void ordenarPilaPorInsercion(Pila pilaDada, Pila *pilaOrdenada)
{
    Pila pilaAux;
    inicpila(&pilaAux);

    while(!pilavacia(&pilaDada))
    {
        while(!pilavacia(pilaOrdenada) && tope(pilaOrdenada) > tope(&pilaDada))
        {
            apilar(&pilaAux, desapilar(pilaOrdenada));
        }

        apilar(pilaOrdenada, desapilar(&pilaDada));

        while(!pilavacia(&pilaAux))
        {
            apilar(pilaOrdenada, desapilar(&pilaAux));
        }
    }

}


void ordenarPilaPorSeleccion(Pila pilaDada, Pila *pilaOrdenada)
{
    Pila menor, aux;
    inicpila(&menor);
    inicpila(&aux);

    while(!pilavacia(&pilaDada))
    {
        // primero paso el tope de dada a la pila menor ya que lo considero el menor
        apilar(&menor, desapilar(&pilaDada));

        //recorro la pila DADA hasta que hasta que se vacia (entonces lo que esta en menor es menor) o hasta que encuentro un menor a lo que hay en pila menor
        while(!pilavacia(&pilaDada))
        {
            if(tope(&pilaDada) <= tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&pilaDada));
            }
            else
            {
                apilar(&aux, desapilar(&pilaDada));
            }
    }
        //ahora vuelvo a apilar lo que deje en pila Aux a la pila DADA
        while(!pilavacia(&aux))
        {
            apilar(&pilaDada, desapilar(&aux));
        }
        //finalmente apilo la pila ordenada con el valor que quedo en pila menor
        apilar(pilaOrdenada, desapilar(&menor));
    }
}

void mostrarArreglo(int array[], int validos){

    for(int i=0; i< validos; i++)
    {
        printf("|%i|", array[i]);
    }

}










