#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cadena[50];
    int longitud;

    printf("Ingrese una cadena: ");
    fflush(stdin);
    gets(cadena);

    longitud = strlen(cadena);

    printf("La longitud de la cadena ingresada (%s) es: %i\n", cadena, longitud);

    return 0;
}
