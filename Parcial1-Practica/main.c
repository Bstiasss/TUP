#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>

#define FILACHAR 5
#define COLCHAR 10

//Lucas Lomuoio

const int DIMARREGLO = 20;
const int FILA = 3;
const int COL= 3;
//const int FILACHAR = 5;
//const int COLCHAR = 10;

void cargarPila(Pila *pila);
int copiarPilaArreglo(Pila *pila, int arreglo[DIMARREGLO]);
int encontrarPosicionMenor(int arreglo[DIMARREGLO], int validos);
void cargarMatriz(int matrix[FILA][COL]);
void mostrarMatriz(int matrix[FILA][COL]);
int pedirPosArreglo(int arreglo[DIMARREGLO], int validos);
int mostrarPosArreglo(int arreglo[DIMARREGLO], int validos);
int sumarMatriz(int matrix[FILA][COL]);
float promediarMatriz(int matrix[FILA][COL]);
void cargarMatrizChar(char matriz[FILACHAR][COLCHAR]);
void mostrarMatrizChar(char matriz[FILACHAR][COLCHAR]);
int encontrarCoincidencias(char matriz1[FILACHAR][COLCHAR], int validos1, char matriz2[FILACHAR][COLCHAR],int validos2);



int main()
{
    Pila pila;
    inicpila(&pila);
    int arreglo[DIMARREGLO];
    int matrix[FILA][COL];

    //ejercicio 1
    cargarPila(&pila);

    //ejercicio 2
    int validos = copiarPilaArreglo(&pila, arreglo);

    //ejercicio 3
    int posMenor = encontrarPosicionMenor(arreglo, validos);
    printf("\nEl numero %i, se encuentra en la posicion %i", arreglo[posMenor], posMenor);

    //ejercicio 4
    cargarMatriz(matrix);
    mostrarMatriz(matrix);

    //ejercicio 5
    int elementoArreglo = mostrarPosArreglo(arreglo, validos);
    printf("\nEl elemento buscado del arreglo es %i", elementoArreglo);



    //ejercicio 7
    float promedio = promediarMatriz(matrix);
    printf("\nEl promedio es %f", promedio);

    //ejercicio 8

    char matrizChar[FILACHAR][COLCHAR];
    cargarMatrizChar(matrizChar);
    mostrarMatrizChar(matrizChar);


    //ejercicio 9
    char matrizChar1[FILACHAR][COLCHAR] = {"perro", "gato", "conejo"};
    char matrizChar2[FILACHAR][COLCHAR] = {"gato", "loro", "perro", "gato"};

    int coincidencias = encontrarCoincidencias(matrizChar1, 3, matrizChar2, 4);
    printf("La cantidad de coinicidencias encontradas es %i ", coincidencias);


    return 0;
}

//ejercicio 1

void cargarPila(Pila *pila)
{

    char control;

    do
    {
        leer(pila);
        leer(pila);

        printf("Ingrese 's' para cargar mas datos.");
        fflush(stdin);
        scanf("%c", &control);

    }
    while(control == 's');
}

// ejercicio 2
int copiarPilaArreglo(Pila *pila, int arreglo[DIMARREGLO])
{

    int contador = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pila))
    {

        if(tope(pila) % 5 == 0 && tope(pila) != 0)
        {

            arreglo[contador] = tope(pila);
            contador++;
        }
        apilar(&aux, desapilar(pila));

    }
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));

    }

    return contador;
}

//ejercicio 3

int encontrarPosicionMenor(int arreglo[DIMARREGLO], int validos)
{

    int posicionMenor = 0;

    for(int i = 0; i < validos; i++)
    {

        if(arreglo[posicionMenor] > arreglo[i])
        {
            posicionMenor = i;
        }
    }

    return posicionMenor;
}

//ejercicio 4

void cargarMatriz(int matrix[FILA][COL])
{

    for(int i = 0; i < FILA; i++)
    {
        for(int j = 0; j < COL; j++)
        {

            printf("\nIngrese un numero:");
            fflush(stdin);
            scanf("%i", &matrix[i][j]);
        }
    }
}

void mostrarMatriz(int matrix[FILA][COL])
{

    for(int i = 0; i < FILA; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("|%i|", matrix[i][j]);
        }
        printf("\n");
    }
}


//ejercicio 5

int pedirPosArreglo(int arreglo[DIMARREGLO], int validos){

    int posicion = -1;
    while(posicion < 0){

        printf("\nIngrese la posicion a buscar (0 a %i)", validos);
        fflush(stdin);
        scanf("%i", &posicion);
        if(posicion > validos || posicion < 0){
            posicion = -1;
        }
    }
    return posicion;
}

int mostrarPosArreglo(int arreglo[DIMARREGLO], int validos){

    int posicion = pedirPosArreglo(arreglo, validos);
    printf("\n posicion %i", posicion);
    printf("\nelemento %i", arreglo[posicion]);
    return arreglo[posicion];
}

//ejercicio 6
/*
void ordenarSeleccion(Pila *pila){

    Pila aux, ordenada;
    inicpila(&aux);
    inicpila(&ordena);

    while(!pila)




}*/


//ejercicio 7

int sumarMatriz(int matrix[FILA][COL]){

    int suma = 0;
     for(int i = 0; i < FILA; i++)
    {
        for(int j = 0; j < COL; j++)
        {
        suma += matrix[i][j];
        }
    }
    return suma;
}

float promediarMatriz(int matrix[FILA][COL]){

    int suma = sumarMatriz(matrix);
    float promedio = (float) suma / (FILA * COL);

    return promedio;
}


//ejercicio 8

void cargarMatrizChar(char matriz[FILACHAR][COLCHAR]){

    for(int i = 0; i < FILACHAR; i++){

        printf("\nIngrese una candena de caracteres: ");
        fflush(stdin);
        gets(matriz[i]);
    }
}

void mostrarMatrizChar(char matriz[FILACHAR][COLCHAR]){

    for(int i = 0; i < FILACHAR; i++){

        printf("\n%s", matriz[i]);
    }

}

//ejercicio 9

int encontrarCoincidencias(char matriz1[FILACHAR][COLCHAR], int validos1, char matriz2[FILACHAR][COLCHAR],int validos2){

    int coincidencias = 0;

    for (int i = 0; i < validos1; i++){

        for (int j=0; j< validos2; j++){

            if(strcmp(matriz1[i], matriz2[j]) == 0){

                coincidencias++;
            }
        }
    }
    return coincidencias;
}
