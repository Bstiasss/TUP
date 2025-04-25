#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


int cargarPila(Pila *pila,int *total);
void ordenarPilaInsercion(Pila pilaCompras, Pila *pilaOrdenada);

int main()
{
    Pila pilaCompras;
    inicpila(&pilaCompras);
    int totalCompras = 0;

    int validos = cargarPila(&pilaCompras, &totalCompras);

    mostrar(&pilaCompras);
    printf("total %i ; cantidad %i", totalCompras, validos);

    Pila pilaOrdenada;
    inicpila(&pilaOrdenada);

    ordenarPilaInsercion(pilaCompras, &pilaOrdenada);

    mostrar(&pilaOrdenada);


    return 0;
}

int cargarPila(Pila *pila,int *total){

    char control = 's';
    int validos = 0;

    while(control == 's'){

        leer(pila);
        validos++;
        *total += tope(pila);

        printf("Para cargar otra compra presione 's' ");
        fflush(stdin);
        scanf("%c", &control);

    }
    return validos;
}

void ordenarPilaInsercion(Pila pilaCompras, Pila *pilaOrdenada){

    Pila pilaAux;
    inicpila(&pilaAux);

    while(!pilavacia(&pilaCompras)){

    while(!pilavacia(pilaOrdenada) && tope(&pilaCompras) < tope(pilaOrdenada)){

        apilar(&pilaAux, desapilar(pilaOrdenada));
    }

    apilar(pilaOrdenada, desapilar(&pilaCompras));

    while(!pilavacia(&pilaAux)){

        apilar(&pilaCompras, desapilar(&pilaAux));
    }

    }
}

