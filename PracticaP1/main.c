// Lucas Lomuoio

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>

#define FILA 3
#define COL 3

void cargarPila(Pila *pila);
int copiarPilaArreglo(Pila pila, int arreglo[], int dim);
void mostrarArreglo(int arreglo[], int validos);
int encontarPosicionMenorArreglo(int arreglo[], int validos);
void cargarMatriz(int matriz[FILA][COL]);
void mostrarMatriz(int matriz[FILA][COL]);
void mostrarPosicionArreglo(int arreglo[], int validos);
int pedirPosicion(int validos);
void ordernarPilaSeleccion(Pila dada, Pila *ordenada);

int main()
{
/*    //Ejercicio 1
    Pila pila1A;
    inicpila(&pila1A);
    cargarPila(&pila1A);
    mostrar(&pila1A);

    //Ejercicio 2
    int arreglo2A[20];
    int validos2A = copiarPilaArreglo(pila1A, arreglo2A, 20);
    mostrarArreglo(arreglo2A, validos2A);

    //Ejercicio 3
    int posMenorArreglo = encontarPosicionMenorArreglo(arreglo2A, validos2A);
    printf("\nEl numero %i se encuentra en la posicion %i", arreglo2A[posMenorArreglo], posMenorArreglo);

    //Ejercicio 4
    printf("EJERCICIO 4");
    int matriz4A[FILA][COL];
    cargarMatriz(matriz4A);
    mostrarMatriz(matriz4A);

    //Ejercicio 5
    printf("EJERCICIO 5");
    int arreglo5A[10] = {5,6,7,9,2};
    int validos5A = 5;
    mostrarPosicionArreglo(arreglo5A, validos5A);
*/
    //Ejercicio 6
    printf("EJERCICIO 6");
    Pila dada, ordenada;
    inicpila(&dada);
    inicpila(&ordenada);

    apilar(&dada, 8);
    apilar(&dada, 5);
    apilar(&dada, 10);
    apilar(&dada, 1);
    apilar(&dada, 9);
    ordernarPilaSeleccion(dada, &ordenada);
    mostrar(&dada);
    mostrar(&ordenada);



    return 0;
}


//Ejercicio 1
void cargarPila(Pila *pila){

    char control = 's';

    do{
        leer(pila);
        leer(pila);

        printf("Ingrese 's' para cargar otro valor:");
        fflush(stdin);
        scanf("%c", &control);

    }while (control == 's' || control =='S');

}

//Ejercicio 2
int copiarPilaArreglo(Pila pila, int arreglo[], int dim){

    int validos = 0;

    while(!pilavacia(&pila)){

        if(tope(&pila)% 5 == 0 && tope(&pila) != 0 && validos < dim){

            arreglo[validos] = tope(&pila);
            validos++;
        }
        desapilar(&pila);
    }

    return validos;

}

void mostrarArreglo(int arreglo[], int validos){

    for(int i = 0; i < validos; i++){
        printf("|%i|", arreglo[i]);
    }


}


//Ejercicio 3
int encontarPosicionMenorArreglo(int arreglo[], int validos){

    int posMenor = 0;

    for(int i = 1; i < validos; i++){

        if(arreglo[i] < arreglo[posMenor]){

            posMenor = i;
        }
    }
    return posMenor;
}

//Ejercicio 4

void cargarMatriz(int matriz[FILA][COL]){

    for(int i = 0; i < FILA; i++){
      for(int j= 0; j < COL; j++){
            printf("\nIngrese un numero para la fila %i / columna %i:", i, j);
            fflush(stdin);
            scanf("%i", &matriz[i][j]);
      }
    }
}

void mostrarMatriz(int matriz[FILA][COL]){

  for(int i = 0; i < FILA; i++){
      for(int j=0; j < COL; j++){

            printf("|%i|", matriz[i][j]);
      }
      printf("\n");
    }
}

//Ejecicio 5

void mostrarPosicionArreglo(int arreglo[], int validos){

    int posicion = pedirPosicion(validos);

    printf("El elemento en la posicion %i es %i", posicion, arreglo[posicion]);

}

int pedirPosicion(int validos){

    int posicion = -1;
    while(posicion < 0 || posicion > validos-1){

        printf("\nIngrese la posicion del arreglo (entre 0 y %i)", validos-1);
        fflush(stdin);
        scanf("%i", &posicion);

    }
    return posicion;
}

//Ejercicio 6

void ordernarPilaSeleccion(Pila dada, Pila *ordenada){

    Pila aux, menor;
    inicpila(&aux);
    inicpila(&menor);

    apilar(&menor, desapilar(&dada));

    while (!pilavacia(&dada)){

        while(!pilavacia(&dada)){
            printf("entra al while");
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

