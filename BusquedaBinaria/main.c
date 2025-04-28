#include <stdio.h>
#include <stdlib.h>

int busquedaBinaria(int arreglo[], int validos, int X);

int main()
{
    int validos = 50;
    int arreglo[validos];
    srand(time(NULL));
    for(int i=0; i<validos; i++){
        arreglo[i] = i;
    }
    int buscado = 23;
    int enc = busquedaBinaria(arreglo, validos, buscado);

    if(enc){
        printf("\n\t\tEl numero ha sido encontrado.");
    }else{
        printf("\nEl numero NO ha sido encontrado");
    }


    return 0;
}

int busquedaBinaria(int arreglo[], int validos, int X)
{
    int medio, pri, ult, enc;
    enc = 0;
    pri = 0;
    ult = validos-1;
    medio = (pri + ult)/2;

    while( (pri < ult) && (X != arreglo[medio]) ){
        printf("vuelta\n");
        if(X < arreglo[medio]){
            ult = medio - 1;
        }else
        {
            pri = medio + 1;
        }
        medio = (pri + ult) / 2;
    }
    if (X == arreglo[medio])
        enc = 1;

    return enc;
}
