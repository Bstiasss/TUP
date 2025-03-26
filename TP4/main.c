#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int cargarArray (int arreglo[], int dim);//ej1
void mostrarArray (int arreglo[], int validos);//ej2
int sumarElementos(int arreglo[], int validos);//ej 3
void copiarArregloPila (int arreglo[], int validos, Pila *pila);//ej4
int cargarArrayFloat (float arreglo[], int dim);//ej5 1
float sumarElementosFloat (float arreglo[], int validos);//ej5 2
void mostrarArrayFloat (float arreglo[], int validos);//ej5 3
int cargarArrayChar (char arreglo[], int dim);//ej6 1
void mostrarArrayChar (char arreglo[], int validos);//ej6 1
int encontrarElemento (char arreglo[], int validos, char caracterUsuario);//ej6 2
void ordenarArray(char arrayDado[], int validos);
char obtenerMaximoChar(char arreglo[], int validos);
int determinarSiEsCapicua(int arreglo[],int validos);


int main()
{
    int ejercicioNumero;
    int validos;
    int suma;
    int arrayE1[20];
    int arrayE2[20];
    int arrayE3 [20];
    int arrayE4 [20];
    Pila pila4;
    inicpila(&pila4);
    float arrayE5 [100];
    float sumaFloat;
    char arrayE6[20];
    char arrayE7[20];
    char arrayE8[20];
    int arrayE9[20];

    do
    {
        printf("TP 4 - Arreglos\n\n");
        printf("1  -  Ejercicio 1\n");
        printf("2  -  Ejercicio 2\n");
        printf("3  -  Ejercicio 3\n");
        printf("4  -  Ejercicio 4\n");
        printf("5  -  Ejercicio 5\n");
        printf("6  -  Ejercicio 6\n");
        printf("7  -  Ejercicio 7\n");
        printf("8  -  Ejercicio 8\n");
        printf("9  -  Ejercicio 9\n");
        printf("10 -  Ejercicio 10\n");
        printf("11 -  Ejercicio 11\n");
        printf("12 -  Ejercicio 12\n");
        printf("13 -  Ejercicio 13\n");


        printf("Ingrese opcion numerica (o 0 para terminar): ");
        fflush(stdin);  //uso fflush en caso de que el usuario ingrese un char en lugar de un numero entero
        scanf("%i", &ejercicioNumero);

        system("cls");

        switch (ejercicioNumero)
        {

        case 0:
            printf("\nPrograma Terminado.\n\n");
            break;

        case 1:
            printf ("1 - Hacer una funcion que reciba como parametro un arreglo de numeros enteros");
            printf (" y permita que el usuario ingrese valores al mismo por teclado.La funcion debe retornar la cantidad de elementos cargados en el arreglo");
            printf (" o pueden utilizar como puntero validos, \n\n");

            validos = cargarArray (arrayE1, 20);

            printf ("\nLos elementos validos dentro del arreglo son; %d\n\n", validos);

            system("pause");
            system("cls");
            break;

        case 2:
            printf ("2 - Hacer una funcion que reciba como parametro un arreglo y la cantidad de elementos (validos)");
            printf (" cargados en el y los muestre por pantalla.\n\n");

            validos = cargarArray (arrayE2, 20);// usando la funcion del ej1 cargamos el arreglo
            mostrarArray (arrayE2, validos); // muestra el array

            system("pause");
            system("cls");
            break;

        case 3:
            printf ("Hacer una funcion que reciba como parametro un arreglo y la cantidad");
            printf (" de elementos (validos) cargados en el y calcule la suma de sus elementos.");

            validos = cargarArray (arrayE3, 20);// usando la funcion del ej1 cargamos el arreglo
            suma = sumarElementos (arrayE3, validos); //calculamos la suma de los elementos y guardamos en la variable suma

            printf ("La suma de los elementos es: %i\n\n", suma);

            system("pause");
            system("cls");
            break;

        case 4:
            printf ("Hacer una funcion que reciba como parametro un arreglo, la cantidad de elementos (validos)");
            printf (" cargados en el y una Pila. La funcion debe copiar los elementos del arreglo en la pila.\n\n");

            validos = cargarArray (arrayE4, 20);// usando la funcion del ej1 cargamos el arreglo
            copiarArregloPila (arrayE4, validos, &pila4); //funcion que copie los elementos del arreglo a la pila

            mostrar(&pila4);

            system("pause");
            system("cls");
            break;

        case 5:
            printf ("Realizar una funcion que sume los elementos de un arreglo de numeros reales (float) de dimensión 100.");
            printf ("(se recomienda hacer una funcion para cargar y otra para mostrar para este tipo de dato asociado al arreglo)");

            validos = cargarArrayFloat (arrayE5, 100); //cargar datos
            sumaFloat = sumarElementosFloat (arrayE5, validos); // suma elementos float

            printf ("\nLa suma de los elementos es: %.2f\n", sumaFloat);

            mostrarArrayFloat (arrayE5, validos); //mostrar

            system("pause");
            system("cls");
            break;

        case 6:
            printf ("Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres");

            //pedirle al usuario la carga de un arreglo char
            validos = cargarArrayChar (arrayE6, 20);
            mostrarArrayChar (arrayE6, validos);
            // pedirle al usuario el elemento a buscar
            char caracterAbuscar;

            printf ("\nIngrese el caracter que desea buscar: ");
            fflush (stdin);
            scanf ("%c", &caracterAbuscar);
            // invocar una funcion que me diga si el elemento se encuentra en el arreglo (si o no)
            encontrarElemento (arrayE6, validos, caracterAbuscar);
            int estaOno = encontrarElemento (arrayE6, validos, caracterAbuscar);
            if(estaOno == 1)
            {
                printf ("El elemento SE encuentra dentro del arreglo\n");
            }
            else
            {
                printf ("El elemento NO se encuentra dentro del arreglo\n");
            }

            system("pause");
            system("cls");
            break;

        case 7: //Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.

            printf ("Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.");

            //pedirle al usuario la carga de un arreglo char
            validos = cargarArrayChar (arrayE7, 20);
          //  printf("validos = %d", validos);
            mostrarArrayChar(arrayE7, validos);

            ordenarArray(arrayE7, validos);
            mostrarArrayChar(arrayE7, validos);

            system("pause");
            system("cls");
            break;

        case 8: //Realizar una función que obtenga el máximo carácter de un arreglo dado.
            printf ("Realizar una función que obtenga el máximo carácter de un arreglo dado.\n\n");

            validos = cargarArrayChar (arrayE8, 20);
            mostrarArrayChar(arrayE8, validos);

            int maxChar = obtenerMaximoChar(arrayE8, validos);

            printf("El maximo char es %c", maxChar);

            system("pause");
            system("cls");
            break;

        case 9: //9. Realizar una función que determine si un arreglo es capicúa.

            printf("9. Realizar una función que determine si un arreglo es capicúa.\n\n");

            validos = cargarArray(arrayE9, 20);

            int esCapicua = determinarSiEsCapicua(arrayE9, validos);

            if (esCapicua == 1){

                printf("\033[0;32m");
                printf("\nEl arreglo es capicua.\n\n");
                printf("\033[0m");

            }else{
                printf("\033[0;31m");
                printf("\nEl arreglo NO es capicua.\n\n");
                printf("\033[0m");
            }

            mostrarArray(arrayE9, validos);

            system("pause");
            system("cls");
            break;


        default:
            printf("Opcion incorrecta.\n");
            system("pause");
            system("cls");
        }
    }

    while (ejercicioNumero != 0);

    return 0;
}

//1 - Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores
//al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos).


int cargarArray (int arreglo[], int dim)
{
    char control = 's';
    int i = 0;

    while (control == 's' && i<dim)
    {
        printf ("\nIngrese un valor a su Arreglo: ");
        scanf ("%i", &arreglo[i]);

        i++;

        printf ("\nPara agregar otro elemento presione 's': ");
        fflush (stdin);
        scanf ("%c", &control);
    }

    return i;
}

//2 - Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él
// y los muestre por pantalla.

void mostrarArray (int arreglo[], int validos)
{
    printf ("\nElementos del array: ");

    for (int i=0; i<validos; i++)
    {
        printf ("\narray [%i] es %i", i,  arreglo[i]);
    }
    printf ("\n\n");
}

//3 - Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él
//y calcule la suma de sus elementos.

int sumarElementos(int arreglo[], int validos)
{

    int suma = 0;
    int vueltas  = 0;

    while (vueltas < validos)
    {
        suma += arreglo[vueltas];
        vueltas ++;
    }
    return suma;
}

//4 - Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él
// y una Pila. La función debe copiar los elementos del arreglo en la pila.

void copiarArregloPila (int arreglo[], int validos, Pila *pila)
{
    for (int i=0; i < validos; i++)
    {
        apilar (pila, arreglo[i]);
    }
}

//5 - Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100.
//(se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)

int cargarArrayFloat (float arreglo[], int dim)
{
    char control = 's';
    int i = 0;

    while (control == 's' && i<dim)
    {
        printf ("\n Ingrese un valor a su Arreglo: ");
        scanf ("%f", &arreglo[i]);

        i++;

        printf ("\nPara agregar otro elemento presione 's': ");
        fflush (stdin);
        scanf ("%c", &control);
    }

    return i;
}

float sumarElementosFloat (float arreglo[], int validos)
{

    float suma = 0;
    int vueltas  = 0;

    while (vueltas < validos)
    {
        suma += arreglo[vueltas];
        vueltas ++;
    }
    return suma;
}


void mostrarArrayFloat (float arreglo[], int validos)
{
    printf ("\nElementos del array: ");

    for (int i=0; i<validos; i++)
    {
        printf ("\narray [%i] es %2.f", i,  arreglo[i]);
    }
    printf ("\n\n");
}

//6 - Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.

int cargarArrayChar (char arreglo[], int dim)
{
    char control = 's';
    int i = 0;

    while (control == 's' && i<dim)
    {
        printf ("\n Ingrese un valor a su Arreglo: ");
        fflush (stdin);
        scanf ("%c", &arreglo[i]);

        i++;

        printf ("\nPara agregar otro elemento presione 's': ");
        fflush (stdin);
        scanf ("%c", &control);
    }

    return i;
}

void mostrarArrayChar (char arreglo[], int validos)
{
    printf ("\nElementos del array: ");

    for (int i=0; i<validos; i++)
    {
        printf ("\narray [%i] es %c", i,  arreglo[i]);
    }
    printf ("\n\n");
}

// invocar una funcion que me diga si el elemento se encuentra en el arreglo (si o no)
int encontrarElemento (char arreglo[], int validos, char caracterUsuario)
{
    int estaOno = 0;
    for (int i=0; i<validos; i++)
    {
        if ( arreglo[i] == caracterUsuario)
        {
            estaOno = 1;
        }
    }
    return estaOno;
}


void ordenarArray(char arrayDado[], int validos)
{
    char arrayAux[20];
    char arrayOrdenado[20];
    int cantidadOrdenado = 0;
    int cantidadAux = 0;


    printf("indice dados en funcionn %i", validos);

    while(validos > 0)
    {

        while(validos > 0 && arrayOrdenado[cantidadOrdenado - 1] > arrayDado[validos - 1])
        {
            cantidadAux++;
            arrayAux[cantidadAux - 1] = arrayOrdenado[cantidadOrdenado - 1];

            cantidadOrdenado--;

        }
        cantidadOrdenado++;
        arrayOrdenado[cantidadOrdenado - 1] = arrayDado[validos - 1];
        printf("Muestro ordenados");
        mostrarArrayChar(arrayOrdenado,cantidadOrdenado);

        validos--;

        while(cantidadAux > 0)
        {
            cantidadOrdenado++;
            arrayOrdenado[cantidadOrdenado] = arrayAux[cantidadAux];

            cantidadAux--;

        }
    }
    for(int i = 0; i < validos; i++){

        arrayDado[i] = arrayOrdenado[i];

    }


}

//8 Realizar una función que obtenga el máximo carácter de un arreglo dado.

char obtenerMaximoChar(char arreglo[], int validos){

    char maximoChar = arreglo[0];  // caso de que tenga 1 solo elemento

    for(int i=0; i < validos; i++){

        if(arreglo[i] > maximoChar){

            maximoChar = arreglo[i];
        }
    }
    return maximoChar;
}


//9 Realizar una función que determine si un arreglo es capicúa. (devuelve 1 si es y 0 si no es)

int determinarSiEsCapicua(int arreglo[],int validos){

    int arregloAux[20];
    int esCapicua = 1;  //asumo que los numeros son capicuas
    int contador = 0;
    int indice = validos - 1;

    //recorro el arreglo y creo una copia en aux pero en orden inverso

    for(int i = 0; i < validos; i++){

        arregloAux[i] = arreglo[indice];
        indice--;
    }

    //comparo ambos arreglos, si son iguales es capicua

    while(contador < validos){

        if(arreglo[contador] != arregloAux[contador]){
            esCapicua = 0;
        }
        contador++;
    }

    return esCapicua;
}
