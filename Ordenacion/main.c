#include <stdio.h>
#include <stdlib.h>

void ordenacionSeleccion(int a[], int cantVal);
int posicionMenor(int a[], int cantVal, int pos);
void mostrarArray(int array[], int validos);
int posicionMenor(int a[], int cantVal, int pos);
void insertar(int a[], int u, int dato);

int main()
{
    int array[] = {5,6,9,4,1,3};

    mostrarArray(array, 6);

    //ordenacionSeleccion(array, 6);
    ordenacionInsercion(array, 6);
    mostrarArray(array, 6);

    return 0;
}

//selecciono el menor de todos los valores a la derecha de la posicion actual
//y lo voy trayendo a la posicion actual
//en cada vuelta

void ordenacionSeleccion(int a[], int cantVal){

    int posMenor;
    int i = 0;
    int aux;
    while(i < cantVal - 1) {  //llego hasta la ultima posicion
        posMenor = posicionMenor(a, cantVal, i);
        aux = a[posMenor];
        a[posMenor] = a[i];
        a[i] = aux;
        i++;
    }
}


int posicionMenor(int a[], int cantVal, int pos){

    int menor = a[pos];
    int posMenor = pos;
    int index = pos + 1;
    while(index < cantVal){
        if(menor > a[index]){
            menor = a[index];
            posMenor = index;
        }
        index++;
    }

    return posMenor;
}

void ordenacionInsercion(int a[], int cantVal){
    int u=0;
    while(u < cantVal - 1){
        //llega hasta la posicion del anteultimo elemento del arreglo
        insertar(a, u, a[u+1]);
        u++;
    }
}




void insertar(int a[], int u, int dato){
    int i = u; //ultima pos valida izq
    while(i >=0 && dato < a[i]){
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = dato;
}




void mostrarArray(int array[], int validos){
    int i = 0;
    printf("\n\n");
    while(i < validos){

        printf("|%i|",array[i]);
        i++;
    }
}
