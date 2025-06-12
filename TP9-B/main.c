#include <stdio.h>
#include <stdlib.h>

void cargarArchivo(char nombreArchivo[]);
void mostrarArchivo(char nombreArchivo[]);
int buscarMenorElementoEnArchivo(char nombreArchivo[]);
int buscarMenorElemento(FILE *archivo);

int main()
{
    char nombreArchivo[30] = "datos.bin";
    printf("Cargarndo Archivo");
    cargarArchivo(nombreArchivo);
    printf("\nMostrar Archivo");
    mostrarArchivo(nombreArchivo);
    int menor = buscarMenorElementoEnArchivo(nombreArchivo);
    printf("\nEl menor es: %i", menor);

    return 0;
}


void cargarArchivo(char nombreArchivo[]){
    FILE *archivo = fopen(nombreArchivo, "wb");
    if(archivo == NULL){
        printf("Error abriendo el archivo");
    }else{
        int arreglo[20] = {50,9,62,10,24,9,18,7};  //validos 8
        fwrite(arreglo, sizeof(int), 8, archivo);
        fclose(archivo);
    }
}

void mostrarArchivo(char nombreArchivo[]){
    FILE *archivo = fopen(nombreArchivo, "rb");
    if(archivo ==  NULL){
        printf("Error abriendo el archivo");
    }else{
        int dato;
        while(fread(&dato, sizeof(int), 1, archivo) > 0){
            printf("| %i |", dato);
        }
        fclose(archivo);
    }

}

int buscarMenorElementoEnArchivo(char nombreArchivo[]){
    int menor;

    FILE *archivo = fopen(nombreArchivo, "rb");
    if(archivo == NULL){
        printf("El archivo no se puede abrir");
    }else{
        menor = buscarMenorElemento(archivo);
        fclose(archivo);
    }
    return menor;
}

int buscarMenorElemento(FILE *archivo){
/*    int menor;
    int dato;
    int aux;
    if(feof(archivo)){
        fseek(archivo, sizeof(int)*(-1), SEEK_END);
        fread(&menor, sizeof(int), 1, archivo);
    }else{
        fread(&dato, sizeof(int), 1, archivo);
        aux = buscarMenorElemento(archivo);
        if(dato < aux){
           menor = dato;
        }else{
           menor = aux;
        }
    }

*/
    int menor,num;
    fread(&num, sizeof(int), 1, archivo);

    if(feof(archivo)){
        fseek(archivo,-sizeof(int), SEEK_END);
        fread(&menor, sizeof(int), 1, archivo);
    }else{
        menor = buscarMenorElemento(archivo);
        if(menor > num){
            menor = num;
        }
    }




    return menor;
}



