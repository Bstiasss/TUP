#include <stdio.h>
#include <stdlib.h>

int main()
{

// Ejercicio 1: Punteros �Qu� imprime?.
/*    int *punt;
    int x=7;
    int y=5;
    punt=&x;
    *punt=4;
    printf("%d, %d",x,y); // �qu� imprime este printf?  4, 5

// Ejercicio 2: Punteros �Qu� imprime?.
    int *punt;
    int x=7;
    int y=5;
    punt=&x;
    x=4;
    printf("%d, %d",*punt,y); // �qu� imprime este printf?  4, 5


// Ejercicio 3: Punteros �Qu� imprime?.
    int *punt;
    int x=7;
    int y=5;
    punt=&x;
    x=4;
    punt=&y;
    printf("%d, %d",*punt,x); // �qu� imprime este printf?  5, 4

// Ejercicio 4: Punteros �Qu� imprime?.
   int *punt;
    int x=7;
    int y=5;
    punt=&x;
    *punt=3;
    punt=&y;
    *punt=x;
    x=9;
    printf("%d, %d",*punt,x); // �qu� imprime este printf?  3, 9



// Ejercicio 5: Punteros �Qu� imprime?.
    int *punta, *puntb;
    int x=7;
    int y=5;
    punta=&x;
    *punta=3;
    puntb=&y;
    *puntb=x;
    x=9;
    printf("%d, %d",*puntb,x); // �qu� imprime este printf?  3, 9


// Ejercicio 6: Punteros �Qu� imprime?.

    int *punta, *puntb;
    int x=7;
    int y=5;
    punta=&x;
    *punta=3;
    puntb=&y;
    *puntb=x;
    x=9;
    printf("%d, %d",*puntb, *punta); // �qu� imprime?  3, 9

*/
// Ejercicio 7: Punteros �Qu� imprime?.
    int *punta, *puntb;
    int x=7;
    int y=5;
    punta=&x;
    *punta=3;
    puntb=&y;
    *puntb=x;
    x=9;
    puntb=punta;
    printf("%d, %d",*puntb, y); // �qu� imprime?  9,  3

/*
*/
}
