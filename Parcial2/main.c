//Lucas Lomuoio
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct
{
    int id;
    char nombre[30];
    char categoria[20];
    int edad;
    float tiempoCarrera; // en segundos
    int puntos;
} Atleta;

int cargarAtletasAArray(Atleta **ppAtletas, char nombreArchivo[]);
float promediarTiemposCarrera(Atleta arregloAtletas[], int validos);
int sumarTiemposCarrera(Atleta arregloAtletas[], int validos, int pos);
int cantidadArribaPromedio(Atleta arregloAtletas[], int validos, float promedio);
void pasarArchivoCategoria(char nombreArchivo[], Atleta arregloAtletas[], int validos, char categoriaElegida[]);
void encontrarAtletaMenorTiempoyDuplicar(char nombreArchivo[]);
void aumentarPuntos(char nombreArchivo[], float tCarrera);
int verificarAtleta(Atleta arregloAtleta[], int validos, int pos, char nombre[]);
void mostrarArregloAtletas(Atleta arregloAtletas[], int validos);
void mostrarAtleta(Atleta atleta);
void mostrarAtletasEnArchivo(char nombreArchivo[]);

int main()
{
    //Ejercicio 1
    Atleta *arregloAtleta;
    char nombreArchivo[30] = "archivoAtletas";
    int validosArregloAtleta = cargarAtletasAArray(&arregloAtleta, nombreArchivo);
    mostrarArregloAtletas(arregloAtleta, validosArregloAtleta);

    //Ejercicio 2
    float promedioTiempo = promediarTiemposCarrera(arregloAtleta, validosArregloAtleta);
    printf("\nEl tiempo promedio de carreras es %f: ", promedioTiempo);
    int cantAtletasArribaProm = cantidadArribaPromedio(arregloAtleta, validosArregloAtleta, promedioTiempo);
    printf("\nLa cantidad de atletas arriba del promedio es %i \n", cantAtletasArribaProm);

    //Ejercicio 3
    char nombreArcCategorias[30] = "categorias.bin";
    char categoriaElegida[20] = "Amateur";
    pasarArchivoCategoria(nombreArcCategorias, arregloAtleta, validosArregloAtleta, categoriaElegida);
    printf("\n\nMostrando contenido de archivo %s \n", nombreArcCategorias);
    mostrarAtletasEnArchivo(nombreArcCategorias);
/*
    //Ejercicio 4
    //duplicar en 2 archivos
    encontrarAtletaMenorTiempoyDuplicar(nombreArcCategorias);
    encontrarAtletaMenorTiempoyDuplicar(nombreArchivo);

    printf("\n\nMostrando contenido de archivo %s, luego de duplicar puntos:\n", nombreArchivo);
    mostrarAtletasEnArchivo(nombreArchivo);

    printf("\n\nMostrando contenido de archivo %s, luego de duplicar puntos:\n", nombreArcCategorias);
    mostrarAtletasEnArchivo(nombreArcCategorias);
*/
    //Ejercicio 5
    float tiempoCarreraA = 25;
    aumentarPuntos(nombreArchivo, tiempoCarreraA);
/*
    //Ejercicio 6

    char nombreAbuscar[] = "Jose";
    if(verificarAtleta(arregloAtleta, validosArregloAtleta, 0, nombreAbuscar)){
        printf("El atleta existe");
    }
*/
    return 0;
}



//Ejercicio 1
//Hacer una función que pase los Atletas desde el archivo a un arreglo dinámico de la cantidad justa.
//La función debe retornar la cantidad de elementos del arreglo.

int cargarAtletasAArray(Atleta **ppAtletas, char nombreArchivo[])
{
    FILE *archivo = fopen(nombreArchivo, "rb");
    int i = 0;
    Atleta atleta;
    if(archivo == NULL)
    {
        printf("Error abriendo archivo");
    }
    else
    {
        fseek(archivo,0,SEEK_END);
        int cantRegistros = ftell(archivo)/ sizeof(Atleta);
        *ppAtletas = malloc(cantRegistros * sizeof(Atleta));
        fseek(archivo,0,SEEK_SET);
        while(fread(&atleta, sizeof(Atleta), 1, archivo) > 0)
        {
            (*ppAtletas)[i] = atleta;
            i++;
        }
        fclose(archivo);
    }

    return i;
}

void mostrarArregloAtletas(Atleta arregloAtletas[], int validos){
    for(int i = 0; i < validos; i++){
        printf("Atleta %i\n", i+1);
        mostrarAtleta(arregloAtletas[i]);

    }
}

void mostrarAtleta(Atleta atleta){

        printf("\nId: %i", atleta.id);
        printf("\nNombre: %s", atleta.nombre);
        printf("\nCategoria: %s", atleta.categoria);
        printf("\nEdad: %i", atleta.edad);
        printf("\nTiempo Carrera: %f", atleta.tiempoCarrera);
        printf("\nPuntos: %i\n\n", atleta.puntos);


}

//Ejercicio 2
// Hacer la/las funciones necesarias para obtener el promedio de tiempos
// de carrera del arreglo cargado en el punto anterior de forma recursiva.
// Además, hacer otra función que retorne la cantidad de participantes que están por encima del promedio.

float promediarTiemposCarrera(Atleta arregloAtletas[], int validos)
{
    float promedio = (float) sumarTiemposCarrera(arregloAtletas, validos, 0) / (float) validos;
    return promedio;
}

int sumarTiemposCarrera(Atleta arregloAtletas[], int validos, int pos){

    int suma;

    if(pos == validos - 1){
        suma = arregloAtletas[pos].tiempoCarrera;
    }else{
        suma = arregloAtletas[pos].tiempoCarrera + sumarTiemposCarrera(arregloAtletas, validos, pos + 1);
    }

    return suma;
}


int cantidadArribaPromedio(Atleta arregloAtletas[], int validos, float promedio)
{
    int cant = 0;
    for(int i = 0; i < validos; i++)
    {
        if(arregloAtletas[i].tiempoCarrera > promedio)
        {
            cant++;
        }
    }
    return cant;
}

//Ejercicio 3
//Hacer una función que pase desde el arreglo a un archivo, todos los socios de una determinada categoría.
//La función recibe por parametro toda la información necesaria para trabajar.

void pasarArchivoCategoria(char nombreArchivo[], Atleta arregloAtletas[], int validos, char categoriaElegida[])
{
    FILE *archivo = fopen(nombreArchivo, "wb");
    if(archivo == NULL)
    {
        printf("Error abriendo el archivo");
    }
    else
    {
        for(int i = 0; i < validos; i++)
        {
            if(strcmp(arregloAtletas[i].categoria, categoriaElegida) == 0)
            {
                fwrite(&arregloAtletas[i], sizeof(Atleta), 1, archivo);
            }
        }
        fclose(archivo);
    }
}

void mostrarAtletasEnArchivo(char nombreArchivo[]){
    Atleta atleta;
    FILE* archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL){
        while(fread(&atleta, sizeof(Atleta), 1, archivo) > 0){
            mostrarAtleta(atleta);

        }
       fclose(archivo);
    }
}



//Ejercicio 4
//Hacer la/las funciones necesarias para encontrar el Atleta con menor tiempo de carrera
//del archivo creado en el punto anterior, y duplicar sus puntos.

void encontrarAtletaMenorTiempoyDuplicar(char nombreArchivo[])
{
    FILE *archivo = fopen(nombreArchivo, "r+b");
    if(archivo == NULL)
    {
        printf("Error abriendo el archivo");
    }
    else
    {
        Atleta atleta;
        fread(&atleta, sizeof(Atleta), 1, archivo);
        int posMenorTiempo = 0;
        int i = 0;
        float menorTiempo = atleta.tiempoCarrera;

        while(fread(&atleta, sizeof(Atleta), 1, archivo) > 0)
        {
            i++;
            if(atleta.tiempoCarrera < menorTiempo)
            {
                posMenorTiempo = i;
            }

        }
        fseek(archivo, sizeof(Atleta)*posMenorTiempo, SEEK_SET);
        fread(&atleta, sizeof(Atleta), 1, archivo);
        atleta.puntos = 2 * atleta.puntos;
        fseek(archivo, sizeof(Atleta)*posMenorTiempo, SEEK_SET);
        fwrite(&atleta, sizeof(Atleta), 1, archivo);

        fclose(archivo);
    }
}
// Ejercicio 5
// Hacer una función que aumente en 5 unidades todos los puntos de aquellos atletas del
// archivo cuyo tiempo de carrera sea superior a un valor recibido por parámetro.


void aumentarPuntos(char nombreArchivo[], float tCarrera)
{
    Atleta atleta;
    FILE * archivo = fopen(nombreArchivo, "r+b");
    if(archivo == NULL)
    {
        printf("Error abriendo el archivo");
    }
    else
    {
        //int posiBytes;
        while(fread(&atleta, sizeof(Atleta), 1, archivo) > 0)
        {
            if(atleta.tiempoCarrera > tCarrera)
            {
                printf("Despues de fread %i\n", ftell(archivo));
                atleta.puntos = atleta.puntos + 5;
                fseek(archivo, ftell(archivo) - 68 , SEEK_SET);
 //               fseek(archivo, sizeof(Atleta)*(-1), SEEK_CUR);
 //              fseek(archivo, -68 , SEEK_CUR);
                printf("Antes de fwrite %i \n", ftell(archivo));
             //   fseek(archivo, sizeof(Atleta), SEEK_CUR);
                fwrite(&atleta, sizeof(Atleta), 1, archivo);
                printf("Despues de fwrite %i \n", ftell(archivo));


            }
        }
        fclose(archivo);
    }
}

//Ejercicio 6
// Hacer una función que verifique si existe un atleta en el arreglo mediante su nombre, de forma recursiva.

int verificarAtleta(Atleta arregloAtleta[], int validos, int pos, char nombre[]){
    int existe = 0;
    if(pos == validos -1){
        if(strcmp(arregloAtleta[pos].nombre, nombre) == 0){
            existe = 1;
        }
    }else{
        if(strcmp(arregloAtleta[pos].nombre, nombre) == 0){
            existe = 1;
        }
        existe = verificarAtleta(arregloAtleta, validos, pos + 1, nombre);
    }


    return existe;
}



