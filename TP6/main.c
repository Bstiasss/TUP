#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int fila = 2;
const int col = 3;
const int filaString = 3;
const int colString = 20;

void cargarMatrix(int matrix[fila][col]);
void mostrarMatrix(int matrix[fila][col]);
void cargarMatrixRand(int matrix[fila][col]);
int sumaMatrix(int matrix[fila][col]);
float promedioMatrix(int matrix[fila][col]);
int buscarEnMatrix(int matrix[fila][col], int elemento);
int cargarStringMatrix(char matrix[filaString][colString]);
void mostrarStringMatrix(char matrix[filaString][colString]);
int buscarStringEnMatrix(char matrix[filaString][colString], int cantidadPalabras, char palabra[colString]);

void ordenarPorInsercion(char matriz[filaString][colString]);
void insertar(char matriz[filaString][colString],int i, char dato[colString]);

int main()
{

    int matrix[fila][col];
    int elemento;
    char matrixStrings[filaString][colString];

//    cargarMatrix(matrix);
    cargarMatrixRand(matrix);
    printf("\n");
    mostrarMatrix(matrix);
    printf("\nLa suma de la matrix es: %i ", sumaMatrix(matrix));
    printf("\nEl promedio de los elementos de la matrix es: %.2f", promedioMatrix(matrix));

    printf("\nIngrese el elemento a buscar: ");
    fflush(stdin);
    scanf("%i", &elemento);
    int encontrado = buscarEnMatrix(matrix, elemento);

    if(encontrado == 1){
        printf("\nEl elemennto %i se encuentra en la matriz", elemento);
    }else{
        printf("\nEl elemennto %i NO se encuentra en la matriz", elemento);
    }

    int validos = cargarStringMatrix(matrixStrings);

    mostrarStringMatrix(matrixStrings);

    printf("La cantidad de string cargados es: %i", validos);

    printf("\n\nIngrese la palabra a buscar: ");
    fflush(stdin);
    char palabraABuscar[colString];
    gets(palabraABuscar);

    int filaPalabraEncontrada = buscarStringEnMatrix(matrixStrings,validos, palabraABuscar);

    if(filaPalabraEncontrada == -1){

        printf("\nNo se encuentra la palabra %s .", palabraABuscar);
    }else{
        printf("\nLa palabra %s se encuentra en la fila %i", palabraABuscar, filaPalabraEncontrada);

    }

    printf("\nOrdeno alfabeticamente la matriz\n");

    ordenarPorInsercion(matrixStrings);

    mostrarStringMatrix(matrixStrings);


    return 0;
}

//1. Hacer una función que reciba como parámetro una matriz de números enteros
//y permita que el usuario ingrese valores al mismo por teclado.
//La función debe cargar la matriz por completo.


void cargarMatrix(int matrix[fila][col])
{

    for(int f=0; f < fila; f++)
    {
        for(int c=0; c < col; c++)
        {
            printf("Ingrese un numero: ");
            fflush(stdin);
            scanf("%i", &matrix[f][c]);
        }
    }
}


//2. Hacer una función que reciba como parámetro una matriz de números enteros
//y la muestre por pantalla (en formato matricial).

void mostrarMatrix(int matrix[fila][col])
{

    for(int f=0; f < fila; f++)
    {
        for(int c=0; c < col; c++)
        {
            printf("|%i|", matrix[f][c]);
        }
        printf("\n");
    }


}

//3. Hacer una función que reciba como parámetro una matriz de números enteros
//y que cargue la misma con números aleatorios (sin intervención del usuario)
//. La función debe cargar la matriz por completo.

void cargarMatrixRand(int matrix[fila][col]){

    srand(time(NULL));

    for(int i=0; i < fila; i++){

        for(int j=0; j < col; j++){

            matrix[i][j] = rand() % 100;


        }

    }
}

// 4. Hacer una función tipo int que sume el contenido total de una matriz de números enteros

int sumaMatrix(int matrix[fila][col]){

    int acumulador = 0;

    for(int i=0; i < fila; i++){

        for(int j=0; j < col; j++){

            acumulador += matrix[i][j];
        }
    }
    return acumulador;
}


//5 Hacer una función tipo float que calcule el promedio de una matriz de números enteros.

float promedioMatrix(int matrix[fila][col]){

    int cantidadElementos = fila*col;
    int suma = sumaMatrix(matrix);

    float promedio = (float) suma / cantidadElementos;


    return promedio;
}

//Hacer una función que determine si un elemento se encuentra dentro de una matriz de números enteros.
//La función recibe la matriz y el dato a buscar.

int buscarEnMatrix(int matrix[fila][col], int elemento){

    int i = 0;
    int j = 0;
    int encontrado = 0;

    while(i < fila){

        while(j < col){

            if(matrix[i][j] == elemento){

                encontrado = 1;
            }

            j++;
        }
        j=0;
        i++;
    }

    return encontrado;
}


//Hacer una función que cargue un arreglo de palabras (strings).
//La función debe retornar cuantas palabras se cargaron.  (puede ser a través del parámetro como puntero).

int cargarStringMatrix(char matrix[filaString][colString]){

    int contador = 0;

    for(int i=0; i < filaString; i++){

        printf("\nIngrese un palabra: ");
        fflush(stdin);
   //   scanf("%s", matrix[i]);
        gets(matrix[i]);

        contador++;
    }

    return contador;
}
//8
void mostrarStringMatrix(char matrix[filaString][colString])
{
    for(int f=0; f < filaString; f++)
    {
        printf("|%s| \n", matrix[f]);
    }
}


// 9 - Hacer una función que determine si un string se encuentra dentro de un arreglo de strings.
// La función recibe el arreglo, la cantidad de palabras que contiene y la palabra a buscar.
// devuelve el índice de la fila en que se encuentra, de lo contrario retorna -1

int buscarStringEnMatrix(char matrix[filaString][colString], int cantidadPalabras, char palabra[colString]){

    int i = 0;
    int encontrada = -1;

    while(i < cantidadPalabras){

        if(strcmp(matrix[i], palabra) == 0){ //encontro la palabra

            encontrada = i;
        }


        i++;
    }

    return encontrada;
}

// 11 - Hacer una función (o varias) que ordene un arreglo de palabras por orden alfabético.
// (Por selección o inserción, el que más te guste).

void ordenarPorInsercion(char matriz[filaString][colString]){

    int i = 0;
    char dato[colString];

    while(i < filaString -1){

        strcpy(dato, matriz[i+1]);

        insertar(matriz,i ,dato);

        i++;
    }
}

void insertar(char matriz[filaString][colString],int i, char dato[colString]){

    while(i>=0 && (strcmp(dato, matriz[i]) == -1)){

        strcpy(matriz[i+1], matriz[i]);
        i--;
    }
    strcpy(matriz[i+1], dato);

}


