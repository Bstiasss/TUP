#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//6. Escribe un programa que defina dos cadenas de caracteres (strings) y
// luego utilice la función strcat() para concatenar la segunda cadena a la primera.
// Finalmente, imprime la cadena resultante.


int main()
{
    char cadena1[50] = {'l','a',' ','c', 'a', 's', 'a', '\0'};
    char cadena2[]= " de papel." ;

    printf("Cadena 1: %s  / Cadena 2: %s \n", cadena1, cadena2);

    strcat(cadena1, cadena2);

    printf("La cadena resultante es: %s", cadena1);

    return 0;
}
