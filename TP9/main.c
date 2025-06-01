#include <stdio.h>
#include <stdlib.h>

int factorial(int x);
int calcularPotencia(int base, int exponente);
void mostrarArregloRecursivo(int arreglo[], int validos, int posicion);
void mostrarArregloInvertido(int arreglo[], int validos, int posicion);
int esCapicua(int arreglo[], int posicion, int validos);
int sumarArreglo(int arreglo[], int validos);
int buscarMenor(int arreglo[], int validos);
void guardarDatosArchivo(char nombreArchivo[], int arreglo[], int validos);
void mostrarDatosArchivo(char nombreArchivo[]);


int main()
{
    //  printf("\nEl factorial de 3 es %i", factorial(3));
    //  printf("\nLa potencia 4 de base 2 es %i", calcularPotencia(2, 4));

    int arregloEnteros[10] = {1,3,5,7,9,11};

    printf("\nMostrando arreglo recursivo");
    mostrarArregloRecursivo(arregloEnteros, 6, 0);

    printf("\nMostrando arreglo recursivo invertido");
    mostrarArregloInvertido(arregloEnteros, 6, 0);

    int arregloEnteros2[10] = {14,4,5,2,3,12};
   // printf("salida %i", esCapicua(arregloEnteros2, 0, 6));

    if(esCapicua(arregloEnteros2, 0, 6))
    {
        printf("\nEs capicua");
    }
    else
    {
        printf("\nNo es capicua");
    }

    printf("\nLa suma del arreglo es %i ", sumarArreglo(arregloEnteros2, 6));

    printf("\nEl menor elemento del arreglo es %i", buscarMenor(arregloEnteros2, 6));


    int arregloEnteros3[10] = {1,3,5,7,9,11,4,17};
    char nombreArchivo[30] = "datosInt.bin";

    guardarDatosArchivo(nombreArchivo,arregloEnteros3, 8);
    printf("\n");
    mostrarDatosArchivo(nombreArchivo);


    return 0;
}


//Ejercicio 1
int factorial(int x)
{
    int rta;
    if( x == 0)
    {
        rta = 1;
    }
    else
    {
        rta = x * factorial(x-1);
    }
    return rta;
}

//Ejercicio 2

int calcularPotencia(int base, int exponente)
{
    int resultado;
    if(exponente == 0)  //condicion de corte
    {
        resultado = 1;
    }
    else
    {
        resultado = base * calcularPotencia(base, exponente -1);
    }
    return resultado;
}

//Ejercicio 3

void mostrarArregloRecursivo(int arreglo[], int validos, int posicion)
{
    if( posicion == validos - 1)
    {
        printf("|%i|", arreglo[posicion]);
    }
    else
    {
        printf("|%i|", arreglo[posicion]);
        mostrarArregloRecursivo(arreglo, validos, posicion +1);
    }
}

//Ejercicio 4

void mostrarArregloInvertido(int arreglo[], int validos, int posicion)
{
    if( posicion == validos - 1)
    {

        printf("|%i|", arreglo[posicion]);

    }
    else
    {
        mostrarArregloInvertido(arreglo, validos, posicion +1);
        printf("|%i|", arreglo[posicion]);

    }
}

//Ejercicio 5

int esCapicua(int arreglo[], int posicion, int validos)
{
    int capicua = 1;
    if(posicion < validos)
    {
        if(arreglo[posicion] == arreglo[validos-1])
        {
           capicua = esCapicua(arreglo, posicion + 1, validos -1);
        }
        else
        {
           capicua = 0;
        }
    }
    else
    {
        capicua = 1;
    }

    return capicua;
}

//Ejercicio 6

int sumarArreglo(int arreglo[], int validos){
    int suma = 0;

    if(validos == 1){
          suma = arreglo[validos-1];

    }else{
          suma += arreglo[validos -1] + sumarArreglo(arreglo, validos-1);
    }

    return suma;
}


//Ejercicio 7

int buscarMenor(int arreglo[], int validos){
    int menor;
    if(validos -1 == 0){
        menor = arreglo[validos-1];
    }else{
        if(arreglo[validos-1] < buscarMenor(arreglo, validos-1)){
            menor = arreglo[validos-1];
        }else{
            menor = buscarMenor(arreglo, validos-1);
        }

    }
    return menor;
}

//Ejercicio 8

void guardarDatosArchivo(char nombreArchivo[], int arreglo[], int validos){

    FILE *archivo = fopen(nombreArchivo, "wb");
    if(archivo == NULL){
        printf("Error abriendo archivo");

    }else{
        fwrite(&arreglo[0],sizeof(int),validos, archivo);
        fclose(archivo);
    }
}

void mostrarDatosArchivo(char nombreArchivo[]){
    int dato;
    FILE *archivo = fopen(nombreArchivo, "rb");
    if(archivo == NULL){
         printf("Error abriendo archivo");
    }else{
  //      while(!feof(archivo)){
            while(fread(&dato, sizeof(int), 1, archivo) > 0){
           // fread(&dato, sizeof(int), 1, archivo);
            printf("|%i|", dato);
        }
        fclose(archivo);
    }
}

int buscarMenorEnArchivo(char nombreArchivo[]){
    int menor;
    FILE *archivo = fopen(nombreArchivo, "rb");
    if(archivo == NULL){
        printf("Error abriendo archivo");
    }else{
        fseek(archivo, 0, SEEK_END);
        int cantidadBytes = ftell(archivo);
        int cantidadRegistros = cantidadBytes / sizeof(int);
        rewind(archivo);


        fclose(archivo);

    }




}

int buscarMenorFile(FILE *archivo, int numeroRegistro, int cantidadRegistros){
    int menor;
    if(numeroRegistro == cantidadRegistros){
        fread(&menor,sizeof(int), 1, archivo);
    }else{


    }

    return menor;

}


