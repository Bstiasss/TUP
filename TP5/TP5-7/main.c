#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insercionSort(char cadena[], int validos);
void insertar(char cadena[], int indice, char dato);

// 7. Escribe una función llamada insercionSort que ordene un array de caracteres
// que contiene las letras del abecedario desordenadas utilizando el algoritmo de
// ordenamiento por inserción.

int main()
{
    char cadena[] = "islaoepb";

    printf("\nCadena sin ordenar: %s", cadena);

    int validos = strlen(cadena);
    insercionSort(cadena, validos);

    printf("\nCadena ordenada por insercion: %s", cadena);



    return 0;
}


void insercionSort(char cadena[], int validos){

//recorrer todo el array una vez y en cada paso ordenar
    int i = 0;

    while(i < validos - 1){
        insertar(cadena, i, cadena[i+1] );
        i++;
    }
}

void insertar(char cadena[], int indice, char dato){

    int i = indice;
    while(i>=0 && dato < cadena[i]){

        cadena[i+1] = cadena[i];
        i--;
    }
    cadena[i+1] = dato;
}
