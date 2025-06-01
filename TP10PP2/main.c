#include <stdio.h>
#include <stdlib.h>

int traspasarArregloPares(int arregloOrigen[], int validosOrigen, int arregloDestino[]);
int contarPares(int arreglo[], int validos);
void mostrarArreglo(int arreglo[], int validos);
void cargarArreglo(int arreglo[], int dim);

int main()
{
    //int arreglo[10] = {1,2,3,4,5,6};
    int *arreglo = malloc(10 * sizeof(int));
    int *arregloNuevo = malloc(5 * sizeof(int));

    cargarArreglo(arreglo, 10);
    mostrarArreglo(arreglo, 10);
    int validosArregloNuevo = traspasarArregloPares(arreglo, 10, arregloNuevo);

    mostrarArreglo(arregloNuevo, validosArregloNuevo);



    return 0;
}

int traspasarArregloPares(int arregloOrigen[], int validosOrigen, int arregloDestino[]){
    int validosDestino = 0;
    arregloDestino = realloc(arregloOrigen, sizeof(int) * contarPares(arregloOrigen, validosOrigen) );
    for(int i = 0; i < validosOrigen; i++){
        if(arregloOrigen[i] % 2 == 0){
            arregloDestino[validosDestino] = arregloOrigen[i];
           // printf("a ver %i", arregloDestino[validosDestino]);
            validosDestino++;
        }

    }
    mostrarArreglo(arregloDestino, validosDestino);
    return validosDestino;
}


int contarPares(int arreglo[], int validos){
    int cantidad = 0;
    for(int i=0; i < validos; i++){
        if(arreglo[i] % 2 == 0){
            printf("Par %i", arreglo[i]);
            cantidad++;
        }
    }
    return cantidad;
}

void mostrarArreglo(int arreglo[], int validos){
    for(int i=0; i < validos; i++){
        printf("|%i|", arreglo[i]);
    }

}

void cargarArreglo(int arreglo[], int dim){

    for(int i=0; i < dim; i++){
        arreglo[i] = i;
    }


}
