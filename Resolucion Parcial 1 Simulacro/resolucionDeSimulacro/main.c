#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>


void cargarPila(Pila *dada);
int pasarDePilaAArreglo(Pila dada, int arr[], int dim);
int encontrarPosDeMenor(int arr[], int validos);

// Lucrecia Bazan
int main()
{
    // Ejercicio 1
    Pila pilita;
    inicpila(&pilita);

    cargarPila(&pilita);
    mostrar(&pilita);



// Ejercicio 2
int arreglo[20];
int validos = pasarDePilaAArreglo(pilita, arreglo, 20);


// Ejercicio 3
int posMenor = encontrarPosDeMenor(arreglo, validos);

printf(" El numero %i se encuentra en la posicion %i", arreglo[posMenor], posMenor);


// Ejercicio 4





    return 0;
}

// Ejercicio 1
void cargarPila(Pila *dada){

    char opcion = 's';
    int cant = 0;

    while(opcion == 's'){
        leer(dada);

        cant++;

        printf("Desea cargar otro dato a la pila? 's' o 'n' ");
        fflush(stdin);
        scanf("%c", &opcion);
    }

    if( (cant % 2)!=0 ){
        printf("Ingrese un ultimo valor: ");
        leer(dada);
    }
}


// Ejercicio 2
int pasarDePilaAArreglo(Pila dada, int arr[], int dim){

    int i = 0;

    while(!pilavacia(&dada) && i < dim){

            if( ((tope(&dada) % 5 ) == 0) && tope(&dada) != 0){
                arr[i] = tope(&dada);
                i++;
            }
            desapilar(&dada);
    }
    return i;
}


// Ejercicio 3
int encontrarPosDeMenor(int arr[], int validos){

int menor = arr[0];
int pos = 0;

    for(int i = 0 ; i < validos ; i++){

        if(arr[i] < menor){
            menor = arr[i];
            pos = i;
        }
    }

    return pos;

}


// Ejercicio 4

int pedirPos(int validos){

    int pos;

    do {
        printf("Ingrese una posicion del array: ");
        scanf("%i", &pos);
    }while(pos < 0 || pos > validos);

    return pos;
}


void mostrarElemento(int arr[], int validos){

    int pos = pedirPos(validos);
    printf(" |%i| ", arr[pos]);
}


// Ejercicio 6
void ordenarPila(Pila dada, Pila *ordenada){

    Pila aux;
    Pila menor;
    inicpila(&aux);
    inicpila(&menor);

    while(!pilavacia(&dada)){
      apilar(&menor, desapilar(&dada));

        while(!pilavacia(&dada)){

            if(tope(&dada) < tope(&menor)){
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&dada));
            }else{
                 apilar(&aux, desapilar(&dada));
            }


        }

        apilar(ordenada, desapilar(&menor));

        while(!pilavacia(&aux)){
            apilar(&dada, desapilar(&aux));
        }
    }

}





