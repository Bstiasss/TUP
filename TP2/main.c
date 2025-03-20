#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//prototipados - firma de la funcion
void ingresarElementos(Pila *pilita);
void pasarElementosPilaAB(Pila *pilaA, Pila *pilaB);
void traspasar (Pila *pila1, Pila *pila2);
int encontrarMenor(Pila *pilaA);
void ordenarPorSeleccion(Pila *pilaDada, Pila *pilaOrdenada);
void insertarElementoOrdenado(Pila *pilaA, int elementoNuevo);
int sumar2(Pila *pila);
float calcularPromedio9(Pila *pila);
int calcularSuma9(Pila pila);
int contarElementosDePila9(Pila pila);
float dividir9(int suma, int cantidad);
int transformarPilaEnNumero(Pila *pila);
void cargarElementoEnPila(Pila *pila);
void mostrarV2(Pila *pila);


int main()
{
    Pila pilita, pila2A, pila2B, pila3A, pila3B, pila3C, pila4A, pila6A, pila8A;
    Pila pila9A, pila10A, pila11A, pila12A, pila5Dada, pila5Ordenada, pila7Dada, pila7Ordenada;
    inicpila(&pilita);
    inicpila(&pila2A);
    inicpila(&pila2B);
    inicpila(&pila3A);
    inicpila(&pila3B);
    inicpila(&pila3C);
    inicpila(&pila4A);
    inicpila(&pila5Dada);
    inicpila(&pila5Ordenada);
    inicpila(&pila6A);
    inicpila(&pila7Dada);
    inicpila(&pila7Ordenada);
    inicpila(&pila8A);
    inicpila(&pila9A);
    inicpila(&pila10A);
    inicpila(&pila11A);
    inicpila(&pila12A);

    int ejercicioNumero;
    int elementoEj6;
    float promedioEj9;
    int numeroEj10;
    int elementoEj11;
    int cantidadElementosEj12;


    srand(time(NULL));
    char control;

    do
    {
        printf("TP 2 - FUNCIONES CON PILAS -------\n\n");
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
        printf("11 -  Ejercicio Extra 1\n");
        printf("12 -  Ejercicio Extra 2\n\n");

        printf("Ingrese opcion numerica (o 0 para terminar): ");
        fflush(stdin);  //uso fflush en caso de que el usuario ingrese un char en lugar de un numero entero
        scanf("%i", &ejercicioNumero);

        system("cls");

        switch (ejercicioNumero)
        {

        case 0:
            printf("\nPrograma Terminado.\n\n");
            break;

        case 1: //1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.
            printf("1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.\n\n");

            ingresarElementos(&pilita);

            system("pause");
            system("cls");
            break;

        case 2: //2. Hacer una función que pase todos los elementos de una pila a otra
            printf("2. Hacer una función que pase todos los elementos de una pila a otra.\n\n");

            //inicializo las pilas de vuelta en caso de que el usuario ejecute el ejercicio 2 y quiera volver a ejecutarlo sin reiniciar el programa
            inicpila(&pila2A);
            inicpila(&pila2B);

            do
            {
                leer(&pila2A);
                printf("\nPara agregar otro elemento presione s: ");
                fflush(stdin);
                scanf("%c", &control);

            }
            while(control == 's');

            printf("\nPila A\n");
            mostrar(&pila2A);

            pasarElementosPilaAB(&pila2A, &pila2B);

            printf("\nPila B\n");
            mostrar(&pila2B);

            system("pause");
            system("cls");
            break;

        case 3: //3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.

            printf("3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.\n\n");

            printf ("Ingrese un numero: \n");
            do
            {
                leer(&pila3A);
                printf("\nPara agregar otro elemento presione s: ");
                fflush(stdin);
                scanf("%c", &control);

            }
            while(control == 's');
            printf ("Pila cargada por el usuario: ");
            mostrar (&pila3A);
            traspasar(&pila3A, &pila3B);
            printf ("\nPila invertida: ");
            mostrar (&pila3B);

            traspasar(&pila3B, &pila3C);
            printf ("\nPila Final: ");
            mostrar (&pila3C);

            system("pause");
            system("cls");
            break;

        case 4: //4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La
            //misma debe eliminar ese dato de la pila.

            printf("4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.\n\n");

            do
            {
                leer(&pila4A);
                printf("\nPara agregar otro elemento presione s: ");
                fflush(stdin);
                scanf("%c", &control);

            }
            while(control == 's');

            mostrar(&pila4A);

            int menor = encontrarMenor(&pila4A);

            printf("\nel menor: %i", menor);

            mostrar(&pila4A);

            system("pause");
            system("cls");
            break;

        case 5: //5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
            //nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)

            printf("5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una ");
            printf("nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección).\n\n");

            //tengo que inicializar las pilas DADA y ORDENADA en caso de que corra el programa mas de 1 vez

            inicpila(&pila5Dada);
            inicpila(&pila5Ordenada);

            printf("Genero valores random para la pila DADA.");

            for(int i = 0; i < 10; i++)
            {
                apilar(&pila5Dada, rand() % 20);
            }
            mostrar(&pila5Dada);

            ordenarPorSeleccion(&pila5Dada, &pila5Ordenada);

            printf("Pila Ordenada.");
            mostrar(&pila5Ordenada);

            system("pause");
            system("cls");
            break;

        case 6:   //6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de esta.

            printf("6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de esta.\n\n");

            //ingreso de datos del usuario
            do
            {
                leer(&pila6A);
                printf("\nPara agregar otro elemento presione s: ");
                fflush(stdin);
                scanf("%c", &control);

            }
            while(control == 's');

            mostrar(&pila6A);

            printf("Ingrese un elemento a agregar:\n");
            scanf("%i", &elementoEj6);

            // llamar funcion de agregar elemento
            insertarElementoOrdenado(&pila6A, elementoEj6);

            mostrar(&pila6A);


            system("pause");
            system("cls");
            break;

        case 7: //7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
            //nueva pila ordenada. Usar la función del ejercicio 6. (Ordenamiento por inserción)

            printf("7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.");
            printf("nueva pila ordenada. Usar la función del ejercicio 6. (Ordenamiento por inserción).\n\n");

            //tengo que inicializar las pilas DADA y ORDENADA en caso de que corra el programa mas de 1 vez

            inicpila(&pila7Dada);
            inicpila(&pila7Ordenada);

            printf("Genero valores random para la pila DADA.");

            for(int i = 0; i < 10; i++)
            {
                apilar(&pila7Dada, rand() % 20);
            }
            mostrar(&pila7Dada);

            ordenarPorInsercion(&pila7Dada, &pila7Ordenada);

            printf("Pila Ordenada.");
            mostrar(&pila7Ordenada);



            system("pause");
            system("cls");
            break;

        case 8: //8. Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior),
            //sin alterar su contenido.

            printf("8. Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior) sin alterar su contenido.\n\n");

            //generamos datos
            for(int i = 0; i < 10; i++)
            {
                apilar(&pila8A, rand() % 51);
            }
            mostrar(&pila8A);
            int suma = sumar2(&pila8A);
            printf("\nLa suma es: %i", suma);
            mostrar(&pila8A);

            system("pause");
            system("cls");
            break;


        case 9:
            //9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también
            //una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro
            //funciones, y la función que calcula el promedio invoca a las otras 3.

            printf("9.  Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una función que calcule la suma,\n");
            printf("otra para la cuenta y otra que divida. En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3.\n\n");

            //cargar pila con elementos random y mostrarla
            for(int i = 0; i < 10; i++)
            {
                apilar(&pila9A, rand() % 100);
            }
            printf("Pila 9A:");
            mostrar(&pila9A);

            //invocar la funcion que calcula promedio, cargando el dato que devuelve en una variable
            promedioEj9 = calcularPromedio9(&pila9A);

            //imprimir el promedio alamacenado en la variable
            printf("\nEl promedio de los elementos de la pila es: %.2f .\n\n", promedioEj9);

            system("pause");
            system("cls");
            break;

        case 10: //10. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de
            // quien usa el programa) y que transforme esos dígitos en un número decimal. Por ejemplo, la pila:
            // Base 57641 Tope. Debe retornar el número: 14675


            printf("10. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de quien usa el programa) y que transforme esos dígitos en un número decimal.\n\n");

            //usuario ingresa numero de la pila

            do
            {
                printf("\nIngrese un numero del 0 al 9: \n");
                leer(&pila10A);

                printf("Ingrese 's' si desea agregar otro numero: ");
                fflush(stdin);
                scanf("%c", &control);

            }
            while(control == 's');

            mostrar(&pila10A);

            //invoco funcion que devuelva el numero decimal segun el enunciado.

            numeroEj10 = transformarPilaEnNumero(&pila10A);

            printf("\nEl numero es: %i \n\n", numeroEj10);


            system("pause");
            system("cls");
            break;

        case 11:

            printf("Extra 1. Realizar una función que cargue la pila sin utilizar la función leer.\n\n");

            do
            {
                cargarElementoEnPila(&pila11A);

                printf("Desear cargar otro elemenot a la pila? Presione s. ");
                fflush(stdin);
                scanf("%c", &control);


            }
            while(control == 's');

            printf("\nPila 11A: \n");
            mostrar(&pila11A);

            system("pause");
            system("cls");
            break;

        case 12:

            printf("Extra 2. Realizar una función que muestre la pila sin utilizar la función mostrar.\n\n");

            //genero los elementos de la pila de forma automatica
            inicpila(&pila12A);  //tengo que inicializar la pila cada vez que entre al case en caso de que quiera re ejecutar el caso 12

            cantidadElementosEj12 = rand() % 10 + 10;

            for(int i = 0; i < cantidadElementosEj12; i++)
            {
                apilar(&pila12A, rand() % 100);
            }

            printf("\nPila 12A con la funcion mostrarV2(): \n");

            mostrarV2(&pila12A);

            printf("\nPila 12A con la funcion mostrar(): \n");

            mostrar(&pila12A);

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

//1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.

void ingresarElementos(Pila *pilita)
{
    char control = 's';
    while (control == 's')
    {
        leer(pilita);

        printf("\nIngrese 's' para agregar otro elemento: ");
        fflush(stdin);
        scanf("%c", &control);

    }

    mostrar(pilita);

}

//2. Hacer una función que pase todos los elementos de una pila a otra

void pasarElementosPilaAB(Pila *pilaA, Pila *pilaB)
{

    while(!pilavacia(pilaA))
    {
        apilar(pilaB, desapilar(pilaA));
    }
}

//3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.

void traspasar (Pila *pila1, Pila *pila2)
{
    while (!pilavacia (pila1))
    {
        apilar (pila2, desapilar (pila1));
    }
}

//4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La
//misma debe eliminar ese dato de la pila.

int encontrarMenor(Pila *pilaA)
{
    Pila pila4Aux;
    inicpila(&pila4Aux);

    int menor;
    // considero que el tope de la pila es el menor.
    menor = tope(pilaA);

    while (!pilavacia(pilaA))
    {
        if(tope(pilaA) <= menor )
        {

            menor = tope(pilaA);
        }
        apilar(&pila4Aux, desapilar(pilaA));
    }

    while(!pilavacia(&pila4Aux))
    {
        if(menor != tope(&pila4Aux))
        {
            apilar(pilaA, desapilar(&pila4Aux));
        }
        else
        {
            int descarte = desapilar(&pila4Aux);
        }

    }
    return menor;
}

//5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
//nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)

void ordenarPorSeleccion(Pila *pilaDada, Pila *pilaOrdenada)
{

    Pila menor, aux;
    inicpila(&menor);
    inicpila(&aux);


    while(!pilavacia(pilaDada))
    {
        apilar(pilaOrdenada,encontrarMenor(pilaDada));


        /*

              // primero paso el tope de dada a la pila menor ya que lo considero el menor
                apilar(&menor, desapilar(pilaDada));

                //recorro la pila DADA hasta que hasta que se vacia (entonces lo que esta en menor es menor) o hasta que encuentro un menor a lo que hay en pila menor
                while(!pilavacia(pilaDada))
                {


                if(tope(pilaDada) <= tope(&menor))
                    {
                        apilar(&aux, desapilar(&menor));
                        apilar(&menor, desapilar(pilaDada));
                    }
                    else
                    {
                        apilar(&aux, desapilar(pilaDada));
                    }



                }
                //ahora vuelvo a apilar lo que deje en pila Aux a la pila DADA


               while(!pilavacia(&aux))
                {
                    apilar(pilaDada, desapilar(&aux));

                }
                //finalmente apilo la pila ordenada con el valor que quedo en pila menor
                apilar(pilaOrdenada, desapilar(&menor));

                */
    }



}



//6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden
// de ésta


void insertarElementoOrdenado(Pila *pilaA, int elementoNuevo)
{
    Pila pilaAux;
    inicpila(&pilaAux);

    // printf("entra a la funcion");
    while(!pilavacia(pilaA) && tope(pilaA) > elementoNuevo )
    {
        apilar(&pilaAux, desapilar(pilaA));
    }

    apilar(pilaA, elementoNuevo);

    while(!pilavacia(&pilaAux))
    {

        apilar(pilaA, desapilar(&pilaAux));
    }
}

//7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
//nueva pila ordenada. Usar la función del ejercicio 6. (Ordenamiento por inserción)

void ordenarPorInsercion(Pila *pilaDada, Pila *pilaOrdenada)
{

    while(!pilavacia(pilaDada)){

        insertarElementoOrdenado(pilaOrdenada,desapilar(pilaDada));
    }

    //codigo de abajo es ordenamiento por insercion, pero voy a usar la funcion del ej 6 arriba

 /*   Pila pilaAux;
    inicpila(&pilaAux);

    while(!pilavacia(pilaDada))
    {
        while(!pilavacia(pilaOrdenada) && tope(pilaOrdenada) > tope(pilaDada))
        {
            apilar(&pilaAux, desapilar(pilaOrdenada));
        }

        apilar(pilaOrdenada, desapilar(pilaDada));

        while(!pilavacia(&pilaAux))
        {
            apilar(pilaOrdenada, desapilar(&pilaAux));
        }
    }

    */

}


//8. Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior),
//sin alterar su contenido.

int sumar2(Pila *pila)
{

    int primerNum = tope(pila);
    int topeOriginal = desapilar(pila);

    int suma = primerNum + tope(pila);

    mostrar(pila);

    apilar(pila, topeOriginal);

    return suma;
}

//9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también
//una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro
//funciones, y la función que calcula el promedio invoca a las otras 3.

float calcularPromedio9(Pila *pila)
{

    Pila pilaAux = *pila;

    int suma = calcularSuma9(pilaAux);
    int cantidadElementos = contarElementosDePila9(pilaAux);

    float promedio = dividir9(suma, cantidadElementos);

    return promedio;
}

int calcularSuma9(Pila pila)   //utilizo variable por copia
{
    Pila pilaAux;
    inicpila(&pilaAux);
    int suma = 0;

    while(!pilavacia(&pila))
    {
        suma += tope(&pila);
        apilar(&pilaAux, desapilar(&pila));
    }

    printf("\nLa suma de todos los elementos es: %i", suma);

    return suma;
}

int contarElementosDePila9(Pila pila)
{
    Pila pilaAux;
    inicpila(&pilaAux);
    int contador = 0;

    while(!pilavacia(&pila))
    {
        contador++;
        apilar(&pilaAux, desapilar(&pila));
    }
    printf("\nLa cantidad de elementos es: %i", contador);

    return contador;
}

float dividir9(int suma, int cantidad)
{

    float promedio = (float) suma / cantidad;

    return promedio;
}

//10. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de
// quien usa el programa) y que transforme esos dígitos en un número decimal. Por ejemplo, la pila:
// Base 57641 Tope. Debe retornar el número: 14675


int transformarPilaEnNumero(Pila *pila)
{

    Pila pilaCopia = *pila;
    Pila pilaAux;
    inicpila(&pilaAux);
    int numeroDecimal = 0;
    int potencia;
    //reutilizo la funcion del ejercicio 9
    int cantElementos = contarElementosDePila9(pilaCopia);

    while(!pilavacia(pila))
    {
        potencia = 1;

        for(int i = 0; i < (cantElementos -1); i++)
        {
            potencia *= 10;
        }
        numeroDecimal += (tope(pila) * potencia);

        cantElementos--;

        apilar(&pilaAux, desapilar(pila));
    }


    return numeroDecimal;
}

//Extra 1. Realizar una función que cargue la pila sin utilizar la función leer.

void cargarElementoEnPila(Pila *pila)
{

    int elementoNuevo;
    printf("\nIngrese un numero a cargar en la pila: ");
    scanf("%i", &elementoNuevo);
    apilar(pila, elementoNuevo);

}


//Extra 2. Realizar una función que muestre la pila sin utilizar la función mostrar.

void mostrarV2(Pila *pila)
{

    Pila pilaAux;
    inicpila(&pilaAux);
    int elemento;

    printf("\n----------");
    printf("\n--|TOPE|--");
    printf("\n----------");

    while(!pilavacia(pila))
    {


        elemento = tope(pila);
        printf("\n  | %i |", elemento);
        printf("\n  ------  ");
        apilar(&pilaAux, desapilar(pila));

    }

    printf("\n----------");
    printf("\n--|BASE|--");
    printf("\n----------");

    //vuela la pila a su estado original

    while(!pilavacia(&pilaAux))
    {
        apilar(pila, desapilar(&pilaAux));
    }

}

