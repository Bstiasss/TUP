#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cadena[50];
    char copia[50];
    char segundaCadena[50];

    printf("Ingrese una cadena de texto: ");
    fflush(stdin);
    gets(cadena);

    strcpy(copia, cadena);

    printf("Las cadenas son: \nOriginal: %s \nCopia: %s", cadena, copia);

    printf("\nIngrese una segunda cadena: ");
    fflush(stdin);
    gets(segundaCadena);

    strcat(copia, segundaCadena);

    printf("La cadena resultante es: %s", copia);

    return 0;
}
