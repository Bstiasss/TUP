#include <stdio.h>
#include <stdlib.h>

void insertar(int arreglo[],int i,int dato);
void ordenarPorInsercion(int arreglo[], int validos);

int posicionMenor(int arreglo[],int i, int validos);
void ordenarPorSeleccion(int arreglo[], int validos);


int main()
{
    int array[]={6,8,4,10,6};

   // ordenarPorInsercion(array, 5);

    ordenarPorSeleccion(array, 5);
    for(int i=0; i< 5; i++){
        printf("|%i|", array[i]);
    }


    return 0;
}


void ordenarPorInsercion(int arreglo[], int validos){

    int i = 0;
    while(i < validos -1){
        insertar(arreglo,i,arreglo[i+1]);
    i++;
    }

}

//funcion para insertar datos, le paso el arreglo, la posicion para que empiece y el dato

void insertar(int arreglo[],int i,int dato){
    while(i >= 0 && dato < arreglo[i]){
        arreglo[i+1] = arreglo[i];
        i--;
    }
    arreglo[i+1]= dato;
}



void ordenarPorSeleccion(int arreglo[], int validos){

    int posMenor;
    int aux;
    int i = 0;

    while(i < validos -1){

       posMenor = posicionMenor(arreglo, i, validos);
       aux = arreglo[i];
       arreglo[i] = arreglo[posMenor];
       arreglo[posMenor]= aux;

       i++;
    }



}

int posicionMenor(int arreglo[],int i, int validos){

    int posMenor = i; //asumo que estoy en la menor

    while(i < validos){
        if(arreglo[posMenor] > arreglo[i]){

            posMenor = i;
        }
        i++;
    }

    return posMenor;
}














