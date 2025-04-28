//Lomuoio Lucas - Comision 8
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>

#define FILA 3
#define COL 3
#define FILACHAR 5
#define COLCHAR 30

void cargarArreglo(int arreglo[], int dim, int *validos);
int copiarArregloPila(Pila *pila, int arreglo[],int validos);
int encontrarCoincidencias(int matriz[FILA][COL], Pila pila);
int cargarPalabraMatriz(char matrizChar[FILACHAR][COLCHAR], char palabra[]);
int pedirNumeroFila();
float retornarPorcentajeCoinidencias(Pila pila, int numBuscado);

int main()
{

    //EJERCICIO 1
    int arreglo1[20];
    int validos;

    cargarArreglo(arreglo1, 20, &validos);

    printf ("\n\nCantidad de numeros cargados: %i \n\n", validos);


    for(int i = 0; i<validos; i++){
        printf("|%i|", arreglo1[i]);
    }


    //EJERCICIO 2
    int arreglo2[20] = {3,99,123,102,4,98,97,126}; //8
    Pila pila2;
    inicpila(&pila2);

    int cantidadPar = copiarArregloPila(&pila2, arreglo2, 8);

    mostrar(&pila2);

    if(cantidadPar == 1){

        printf("\nLa cantidad de elementos cargados en la pila es par");
    }else{
        printf("\nLa cantidad de elementos cargados en la pila es impar");
    }

    //EJERCICIO 3

    int matriz3[FILA][COL] = {{1,2,3}, {5,6,3}, {3,9,5}};
    Pila pila3;
    inicpila(&pila3);
    apilar(&pila3, 5);
    apilar(&pila3, 8);
    apilar(&pila3, 1);
    apilar(&pila3, 7);
    apilar(&pila3, 2);

    int coincidencias = encontrarCoincidencias(matriz3, pila3);

    printf("\nLa cantidad de coincidencias es: %i", coincidencias);


    //EJERCICIO 4

    char matrizChar[FILACHAR][COLCHAR] = {"palabra 1","palabra 2", "palabra 3", "palabra 4", "palabra 5"};
    char palabra[20] = {"palabra nueva"};

    int cargaExitosa = cargarPalabraMatriz(matrizChar, palabra);

    if(cargaExitosa){

        printf("\nLa palabra %s ,ha sido cargada en la matriz ", palabra);

        for(int i = 0; i < FILACHAR; i++){

            printf("\n %s", matrizChar[i]);
        }

    }


    //EJERCICIO 5

    Pila pila5;
    inicpila(&pila5);
    apilar(&pila5, 5);
    apilar(&pila5, 8);
    apilar(&pila5, 1);
    apilar(&pila5, 8);
    apilar(&pila5, 2);

    int numeroBuscado = 8;

    float porcentaje = retornarPorcentajeCoinidencias(pila5, numeroBuscado);

    printf ("\nEl porcentaje de coincidencias es: %.2f ", porcentaje * 100);


    return 0;
}





//Ejercicio 1

void cargarArreglo(int arreglo[], int dim, int *validos){

    char control;
    *validos = 0;
    do{
       printf("\nIngrese el numero entero a cargar en el arreglo: ");
       scanf("%i", &arreglo[*validos]);
       (*validos)++;

       printf("\nIngrese 's' para cargar otro numero:");
       fflush(stdin);
       scanf("%c", &control);


    }while(control == 's' &&  *validos < dim);

}


//Ejercicio 2

int copiarArregloPila(Pila *pila, int arreglo[],int validos){

    int contador = 1;
    for(int i= 0; i < validos; i++){


        if(arreglo[i] > 96 && arreglo[i] < 123){

            apilar(pila, arreglo[i]);

            if(contador == 0){
                contador++;
            }else{
                contador--;
            }

        }

    }
    return contador;

}

//Ejercicio 3

int encontrarCoincidencias(int matriz[FILA][COL], Pila pila){

    Pila aux;
    inicpila(&aux);

    int coincidencias = 0;

    for(int i=0; i < FILA; i++){
        for(int j=0; j < COL; j++){

            while(!pilavacia(&pila)){

                if(tope(&pila) == matriz[i][j]){
                    coincidencias++;
                }
                apilar(&aux, desapilar(&pila));
            }

            while(!pilavacia(&aux)){

                apilar(&pila, desapilar(&aux));
            }
        }
    }
    return coincidencias;
}


//Ejercicio 4-B

int cargarPalabraMatriz(char matrizChar[FILACHAR][COLCHAR], char palabra[]){

   int numeroFila = pedirNumeroFila();
   int cargaExitosa = 0;

   if(strlen(palabra) < COLCHAR -1){
        strcpy(matrizChar[numeroFila], palabra);
        cargaExitosa = 1;
   }

    return cargaExitosa;
}

//Ejercicio 4-A

int pedirNumeroFila(){

    int filaPedida = -1;

    while(filaPedida < 0 || filaPedida >= FILACHAR){

        printf("\nIngrese el numero de fila (entre 0 y %i): ", FILACHAR-1);
        scanf("%i", &filaPedida);
    }

    return filaPedida;
}


//5. Hacer una función de tipo real que reciba como parámetros una pila (cargada con valores) y un número entero.
// La función debe retornar el porcentaje de coincidencias en que se encontró el número entero en la pila.
// Ejemplo: Dada una pila de 4 elementos en los cuales 2 son el número buscado, la función retornaría 50 %.

//Ejercicio 5

float retornarPorcentajeCoinidencias(Pila pila, int numBuscado){

    int encontrado = 0;
    int cantidadElementos = 0;

    while(!pilavacia(&pila)){

        if (tope(&pila) == numBuscado){
            encontrado++;
        }
        desapilar(&pila);
        cantidadElementos++;
    }

    float porcentaje = (float)encontrado / (float)cantidadElementos;

    return porcentaje;
}
