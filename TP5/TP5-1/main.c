#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palabra1[50];
    char palabra2[50];
    int comparacion;

    printf("Ingrese una palabra: ");
    //fflush??
    scanf("%s", palabra1);
    printf("\nIngrese otra palabra: ");
    scanf("%s", palabra2);

    comparacion = strcmp(palabra1, palabra2);

    if(comparacion == 0){
        printf("\nLas cadenas son iguales");
    }else{
        printf("\nLas cadenas son diferentes");
    }

    return 0;
}
