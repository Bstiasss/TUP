#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int posMenor(char arreglo[],int i, int validos);
void seleccionSort(char arreglo[], int validos);


int main()
{
    char arreglo[7] = {'j','f','z','x','b','l','g'};
    seleccionSort(arreglo, 7);

    for(int i=0; i < 7 ; i++){

        printf("|%c|", arreglo[i]);

    }


    return 0;
}


void seleccionSort(char arreglo[], int validos){

    int i = 0;
    int posiMenor;
    int aux;

    while(i < validos -1){

        //invoco funcion que me devuelve el la posicion del menor para intercambiar
        posiMenor = posMenor(arreglo, i, validos);
        aux = arreglo[i];
        arreglo[i] = arreglo[posiMenor];
        arreglo[posiMenor] = aux;

        i++;
    }

}


int posMenor(char arreglo[],int i, int validos){

    int posiMenor = i; //asumo que la posicion en la que estoy contiene el menor
    while(i < validos){

        if(arreglo[posiMenor] > arreglo[i]){
            posiMenor = i;
        }
        i++;
    }
    return posiMenor;
}
