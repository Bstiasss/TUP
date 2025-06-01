#include <stdio.h>
#include <stdlib.h>

void mostrarElemento(int **punteroAlPuntero[]);
int * CyRetornar();
int * CyRetornar2(int *a);
int * CyRetornar3(int **a, int dim);
void memoriaEstatica();
void memoriaEstaticaCalloc();
int* memoriaEstatica3();
void memoriaEstatica4(int *p);
void redimensionarArray(int *arregloNvo, int dim);

int main()
{
    int *arreglo;
    int cantidad = 3;
    arreglo = (int*) malloc(cantidad * sizeof(int));
    arreglo[0] = 5;
    arreglo[1] = 6;
    arreglo[2] = 7;
    arreglo[3] = 8;
    arreglo[4] = 9;

    printf("\nValor en arreglo[0] %i", arreglo[0]);
    printf("\nValor en arreglo[1] %i", arreglo[1]);
    printf("\nValor en arreglo[2] %i", arreglo[2]);
    printf("\nValor en arreglo[3] %i", arreglo[3]);
    printf("\nValor en arreglo[4] %i", arreglo[4]);

    int a = 5;
    int b = 6;
    int *p = &a;
    int **pp = &p;

    printf("\n direccion de a: %p , contenido de a %i ", &a, a);
    printf("\n direccion de p: %p , contenido de p %p ", &p, p);
    printf("\n direccion de pp: %p , contenido de p %p ", &pp, pp);
    printf("\n a donde apunta *p %i", *p);
    printf("\n a donde apunta *pp %p", *pp);
    printf("\n a donde apunta **pp %i", **pp);
    *pp =&b;
    printf("\n a donde apunta *pp %p", *pp);
    printf("\n a donde apunta **pp %i", **pp);

    int arregloEstatico[15] = {1,2,3,4,5};
    int arregloEstatico2[15] = {0,9,8,7,6};
    int *puntero = &arregloEstatico;
    int **punteroAlPuntero;
    punteroAlPuntero = &puntero;

    mostrarElemento(&punteroAlPuntero);

    printf("\nProbando punteros dobles");
    int *baro = CyRetornar();
    printf(" %i", baro[2]);
    printf(" %i", (CyRetornar())[2] );

    int *arregloNuevo = malloc(10*sizeof(int));
    CyRetornar2(arregloNuevo);

    int *arregloMuyNuevo;
    CyRetornar3(&arregloMuyNuevo, 10);

    memoriaEstatica();
    memoriaEstaticaCalloc();

    int *punteroNuevo = memoriaEstatica3();
    printf("\nDesde funcion3 %i", *punteroNuevo);

    int *puntAInt = (int) malloc(sizeof(int));
    memoriaEstatica4(puntAInt);
    printf("\nDesde funcion4 %i", *puntAInt);

   // int *arrayDinamico = (int) calloc(sizeof(int), 10);
    int *arrayDinamico = (int) malloc(15 * sizeof(int));
    arregloCallocYMalloc(arrayDinamico, 15);
    mostrarArreglo(arrayDinamico,15);

    int tamano;
    printf("Ingrese el tamano del array\n");
    scanf("%d", &tamano);

    int *arrayDinamico2 = (int) malloc(tamano * sizeof(int));
    arregloCallocYMalloc(arrayDinamico2, tamano);
    mostrarArreglo(arrayDinamico2, tamano);
    printf("\n");
    redimensionarArray(arrayDinamico2, 10);
    mostrarArreglo(arrayDinamico2, 10);

    return 0;
}

void mostrarElemento(int **punteroAlPuntero[])
{

    printf("\nResultado %i", (**punteroAlPuntero)[2]);
}

int * CyRetornar()
{
    int *a = malloc(10*sizeof(int));
    for(int i=0; i < 10; i++)
    {
        a[i]=i+1;
    }
    return a;
}

int * CyRetornar2(int *a)
{
    //int *a = malloc(10*sizeof(int));
    for(int i=0; i < 10; i++)
    {
        a[i]=i+1;
    }
    //return a;
}

int * CyRetornar3(int **a, int dim)
{
    *a = malloc(dim*sizeof(int));
    for(int i=0; i < dim; i++)
    {
        (*a)[i]=i+1;
    }
    //return a;
}

void memoriaEstatica()
{
    int *puntAInt = (int) malloc(sizeof(int));
    *(puntAInt+1) = 10;
    printf("\nUsando malloc Num: %d", *(puntAInt+1));

}

int* memoriaEstatica3()
{
    int *puntAInt = (int) malloc(sizeof(int));
    *(puntAInt) = 21;
    return puntAInt;

}

//muy parecida a malloc, pero diferencias en sintaxis y la variable la inicializa en 0
void memoriaEstaticaCalloc()
{
    int *puntAInt = (int) calloc(sizeof(int), 1);
    //*(puntAInt+1) = 10;
    printf("\nUsando calloc Num: %d", *(puntAInt));

}

void memoriaEstatica4(int *p)
{
    *(p) = 25;
}

void arregloCallocYMalloc(int puntAInt[], int dim)
{
    //int *puntAInt = (int) calloc(sizeof(int), 10);

    int i;
    for(i=0; i<dim; i++)
    {

        puntAInt[i] = i;
    }

}

void mostrarArreglo(int arreglo[], int val)
{
    int i;
    for(i=0; i<val; i++)
    {
        printf("| % d |", arreglo[i]);
    }

}

void redimensionarArray(int *arregloNvo, int dim){

    arregloNvo = realloc(arregloNvo, dim);

      for(int i=0; i<dim; i++)
    {

        arregloNvo[i] = i;
    }

}
