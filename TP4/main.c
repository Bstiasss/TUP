#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int cargarArray(int arreglo[], int dim);
void mostrarArray(int arreglo[], int validos);
int sumarElementos(int arreglo[], int validos);
void copiarArregloPila(int arreglo[], int validos, Pila *pila);
int cargarArrayFloat(float arreglo[], int dim); //5
void mostrarArrayFloat(float arreglo[], int validos); //5
float sumarElementosFloat(float arreglo[], int validos); //5

int main()
{
    int ejercicioNumero;
    int validos;
    int suma;
    float sumaFloat;
    int arrayE1[20];
    int arrayE2[20];
    int arrayE3[20];
    int arrayE4[20];
    float arrayE5[100];
    Pila pila4;
    inicpila(&pila4);

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
            //Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario
            // ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados
            //en el arreglo (o pueden utilizar como puntero válidos).

            printf("1. Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario");
            printf("ngrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados");
            printf("en el arreglo (o pueden utilizar como puntero válidos). \n\n");

            validos = cargarArray(arrayE1, 20);

            printf("El vector tiene %d elementos validos.\n\n", validos);

            system("pause");
            system("cls");
            break;

        case 2:

            printf("2. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos");
            printf("(válidos) cargados en él y los muestre por pantalla.  \n\n");

            validos = cargarArray(arrayE2, 20); //cargamos el array

            mostrarArray(arrayE2, validos);  //muestro el array

            system("pause");
            system("cls");
            break;

        case 3:
            //Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos.

            printf("3. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él ");
            printf("y calcule la suma de sus elementos. \n\n");

            validos = cargarArray(arrayE3, 20); // cargamos el arreglo

            suma = sumarElementos(arrayE3, validos);

            printf("\nLa suma de los elementos es: %i \n\n", suma);


            system("pause");
            system("cls");
            break;

        case 4: // Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él
            // y una Pila. La función debe copiar los elementos del arreglo en la pila.

            printf("4. Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados ");
            printf(" en él y una Pila. La función debe copiar los elementos del arreglo en la pila. ");

            validos = cargarArray(arrayE4, 20); //cargamso datos al arreglo
            copiarArregloPila(arrayE4, validos, &pila4); //funcion que copia de arreglo

            mostrar(&pila4);



            system("pause");
            system("cls");
            break;

        case 5:
            //Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100.
            // (se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)


            printf("5. Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100. ");
            printf("(se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo) \n\n");

            //cargar datos
            validos = cargarArrayFloat(arrayE5,100);

            //sumar elementos float
            sumaFloat = sumarElementosFloat(arrayE5, validos);

            printf("\nLa suma de los elementos es %.2f \n", sumaFloat);

            //mostrar
            mostrarArrayFloat(arrayE5, validos);

            system("pause");
            system("cls");
            break;

        case 6:
            //Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.

            printf("6. Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.");


            system("pause");
            system("cls");
            break;

        case 7:

            printf("7. ");


            system("pause");
            system("cls");
            break;

         case 8:

            printf("8. ");


            system("pause");
            system("cls");
            break;

         case 9:

            printf("9. ");


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

//1 -Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario
// ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados
//en el arreglo (o pueden utilizar como puntero válidos).

int cargarArray(int arreglo[], int dim){
    char control = 's';
    int i = 0;

    while(control == 's' && i<dim){
        printf("\nIngrese un valor a su array: ");
        scanf("%i", &arreglo[i]);

        i++;

        printf("\nPara agregar otro elemento elemento presione 's': ");
        fflush(stdin);
        scanf("%c", &control);

    }
    return i;
}

//2 Hacer una función que reciba como parámetro un arreglo
//y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.

void mostrarArray(int arreglo[], int validos){

    printf("\nElementos del array: \n");

    for(int i=0; i<validos; i++){

        printf("\narray[%i] es %i", i, arreglo[i]);

    }

    printf("\n\n");

}

//3 Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
// cargados en él y calcule la suma de sus elementos.

int sumarElementos(int arreglo[], int validos){

    int suma = 0;
    int vueltas = 0;

    while(vueltas < validos){

        suma += arreglo[vueltas];
        vueltas++;

    }

    return suma;
}

//Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos)
// cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.

void copiarArregloPila(int arreglo[], int validos, Pila *pila){

    for(int i=0; i < validos; i++){

       apilar(pila, arreglo[i]);
    }
}

//5
int cargarArrayFloat(float arreglo[], int dim){
    char control = 's';
    int i = 0;

    while(control == 's' && i<dim){
        printf("\nIngrese un valor a su array: ");
        scanf("%f", &arreglo[i]);

        i++;

        printf("\nPara agregar otro elemento elemento presione 's': ");
        fflush(stdin);
        scanf("%c", &control);

    }
    return i;
}

void mostrarArrayFloat(float arreglo[], int validos){

    printf("\nElementos del array: \n");

    for(int i=0; i<validos; i++){

        printf("\narray[%i] es %.2f", i, arreglo[i]);

    }

    printf("\n\n");

}

float sumarElementosFloat(float arreglo[], int validos){

    float suma = 0;
    int vueltas = 0;

    while(vueltas < validos){

        suma += arreglo[vueltas];
        vueltas++;

    }

    return suma;
}




