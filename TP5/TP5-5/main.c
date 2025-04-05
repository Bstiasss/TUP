#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarVocales(char cadena[], int validos);

//5. Crea un programa que solicite al usuario ingresar una cadena y luego utilice un
//bucle para recorrer la cadena y contar la cantidad de vocales que contiene.


int main()
{
    char cadena[50];
    int validos;
    int cantidadVocales;

    printf("Ingrese una cadena de texto: \n");
    fflush(stdin);
    gets(cadena);

    //obtengo la cantidad de elementos validos de la cadena

    validos = strlen(cadena);
    cantidadVocales = contarVocales(cadena, validos);

    printf("La cantidad de vocales en la cadena es: %i", cantidadVocales);

    return 0;
}

int contarVocales(char cadena[], int validos)
{

    int contadorVocales = 0;

    for(int i = 0; i < validos; i++)
    {
        if(cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u')
        {
            contadorVocales++;
        }
    }
    return contadorVocales;
}
