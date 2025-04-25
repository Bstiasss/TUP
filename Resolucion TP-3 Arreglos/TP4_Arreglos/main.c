#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/* Práctico 3 - Arreglos
Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos).
Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.
Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos.
Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.
Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)
Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.
Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.
Realizar una función que obtenga el máximo carácter de un arreglo dado.
Realizar una función que determine si un arreglo es capicúa.
Realizar una función que invierta los elementos de un arreglo.  (sin utilizar un arreglo auxiliar)
Ordenar un arreglo según los siguientes métodos:
Selección
Inserción
Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de los dos primeros intercalados, de manera que quede un arreglo también ordenado alfabéticamente.
Dado el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del contenido de todo los elementos anteriores al índice actual: {1,6,12,19,27}.
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PROTOTIPOS:
int cargararreglo (int A [], int cantidad); // prototipos
int cargararreglochar (char B [], int cantidad);
int cargaArregloReales (float D [], int cantidad);
void mostrararreglo (int A[], int validos);
int sumar (int A[], int validos);
float sumareal (float D[], int validosR);
char buscarMayor (char B [], int validos2);
void invertirArreglo (int A [], int C [], int validos);
void invertirArreglo2 (char A [], int validos);
void copiarapila (int A[], Pila *P, int validos);
int buscarChar (char B [], int validos2, char dato);
int insertarChar (char B [], int validos, char elemento);
void mostrarArregloChar (char B[], int validos2);
int capicua (int A[], int validos);
int posicionMenor (int A[], int pos, int validos);
void ordenacionSeleccion (int A[], int validos);
void insertar(int A[], int u, int dato);
void ordenacionInsercion (int A[], int validos);
int CharIntercalado (char F[], int validosF, char G [], int validosG, char H[], int cantidadH);

//////////////////////////////////////////////////////////////////////////////////////////////
// MAIN:
int main()
{
    int A [5]={0};
    char B [10]={0};
    int C [5]={0};
    float D [100]={0};
    int E [5]={0};
    char F [4]={0};
    char G [5]={0};
    char H [20]={0};

/// EJER 1. Hacer una función que reciba como parámetro un arreglo de números enteros
/// y permita que el usuario ingrese valores al mismo teclado.
/// La función debe retornar la cantidad de elementos cargados en el arreglo.

    int validos=cargararreglo (A, 5);
    printf("Cantidad de elementos cargados en el arreglo: %d", validos);

/// EJERC 2. Hacer una función que reciba como parámetro un arreglo y la cantidad de
/// elementos (válidos) cargados en él y los muestre por pantalla.
    //si no estaba de antes, poner:  int validos=cargararreglo (A, 5);
    mostrararreglo (A, validos);

/// EJER 3. Hacer una función que reciba como parámetro un arreglo y la cantidad de
/// elementos (válidos) cargados en él y calcule la suma de sus elementos.

    int res=sumar (A, validos);
    printf("\n La suma de todos los elementos de la lista A es: %d\n", res);

/// EJERC 4. Hacer una función que reciba como parámetro 1 arreglo, la cantidad de elementos
/// cargados en él y 1 Pila. La fn debe copiar los elementos del arreglo en la pila.

    Pila Mipila;
    inicpila(&Mipila);
    copiarapila (A, &Mipila, validos);
    mostrararreglo(A, validos);
    printf("\nPila 'Mipila':   \n");
    mostrar (&Mipila);

/// EJER 5. Realizar 1 función que sume los elementos reales de un arreglo de dimensión 100.

    int validosR=cargaArregloReales (D, 100);
    float resR=sumareal (D, validosR);
    printf("\nLa suma de todos los elementos de la lista D es: %f\n", resR);

/// EJERC 6 Realizar una función que indique si un elemento dado se encuentra
/// en un arreglo de caracteres.

    int validos2=cargararreglochar (B, 5);
    char dato3=0;
    printf("\nIngrese la letra a buscar en el arreglo: ");
    fflush(stdin);
    scanf("%c",&dato3);
    int flag = buscarChar (B, validos2, dato3);
    if (flag==1) {
        printf("\nLa letra %c si se encuentra en el arreglo\n", dato3);
    }
    else {
        printf("\nLa letra %c no se encuentra en el arreglo\n", dato3);
    }

/// EJERC 7. Realizar una función que inserte 1 carácter en un arreglo ordenado
/// alfabéticamente, conservando el orden.

   // si no estaba de antes, poner: int validos2=cargararreglochar (B, 5);
   char dato=0;
   printf("\n\nIngrese el caracter a insertar en el arreglo ordenado alfabeticamente: ");
   fflush(stdin);
   scanf("%c",&dato); // el dato a insertar es una letra
   validos2=insertarChar (B, validos2, dato); //lo llamo con la variable validos2 porq al insertar un nuevo elem, validos ya aumenta
   printf("\nArreglo luego de la insercion:  ");
   mostrarArregloChar (B, validos2);

/// EJER 8. Realizar una función que obtenga el máximo carácter de un arreglo dado.

    //si no estaba de antes, poner:  int validos2=cargararreglochar (B, 5);
    char mayor=buscarMayor (B, validos2);
    printf("\nEl mayor de los elementos de la lista B es:  %c\n", mayor); //pongo %c en vez de %d para ver la letra y no su codigo

/// EJERC 9. Realizar una función que determine si un arreglo es capicúa.

    int validosC=cargararreglo (E, 5);
    int flag2 = capicua (E, validosC);
    if (flag2==0)
        printf("\nEl arreglo es capicua");
    else
        printf("\nEl arreglo no es capicua");

/// EJERC 10. Realizar una función que invierta los elementos de un arreglo.
    invertirArreglo2 (A, validos);
    printf("\nLos elementos de la lista A luego de la inversion son:   \n");
    mostrararreglo (A, validos);

/// EJERC 11. Ordenar un arreglo según los siguientes métodos: 1. Selección. 2. Inserción.
    printf("\n Ordenar por seleccion el arreglo...");
    int arregloOrdenSeleccion[]= {4,1,2,45,2,1,22,9};
    mostrararreglo(arregloOrdenSeleccion,8);
    ordenacionSeleccion(arregloOrdenSeleccion, 8);
    mostrararreglo(arregloOrdenSeleccion,8);

    printf("\n Ordenar por insercion el arreglo...");
    int arregloOrdenInsercion[]= {4,1,2,45,2,1,22,9};
    mostrararreglo(arregloOrdenInsercion,8);
    ordenacionInsercion(arregloOrdenInsercion, 8);
    mostrararreglo(arregloOrdenInsercion, 8);

/// EJERC 12. Dados dos arreglos ordenados alfabéticamente, crear un 3er arreglo con los
/// elementos de los 2 1ros intercalados, de manera q quede 1 arreglo también ordenado alfabéticamente.

    int validosF= cargararreglochar (F, 4);
    printf("Arreglo F");
    mostrarArregloChar(F, validosF);

    int validosG= cargararreglochar (G, 5);
    printf("Arreglo G");
    mostrarArregloChar(G, validosG);

    int validosH=CharIntercalado (F, validosF, G, validosG, H, 20);

    printf("\nArreglo H\n");
    mostrarArregloChar (H, validosH);
    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNCIONES:

/// EJER 1. CARGAR ARREGLO
/// Hacer una función que reciba como parámetro un arreglo de números enteros
/// y permita que el usuario ingrese valores al mismo teclado.
/// La función debe retornar la cantidad de elementos cargados en el arreglo.

/// SI LE PERMITO AL USUARIO ELEGIR CUANTOS CARGAR:

int cargararreglo (int A [], int dimension)
{
    char letra='s';
    int validos=0;
    while ((letra=='s') && (validos<dimension)) //entra x ultima vez al while cuando validos (los ya cargados)es 1 menos que cantidad, y
    {                                         // ahi cargará 1 mas (y ya quedará validos = a cantidad, y al llegar al proximo while ya no
        printf("\nIngrese un Nro entero  ");   // entra porque dejó de ser menor (y y la ultima posicion validas será cantidad menos 1, porque las posiciones arrancan en 0)
        fflush(stdin);
        scanf("%d", &A[validos]); //va con & xq NO ES EL ARREGLO, ES UNA POSICION DENTRO DEL ARREGLO
                            //lee el Nº ingresado y lo guarda en la direccion de memoria de la posicion q en ese momento asuma la variable
                            // "validos" dentro del array (arranca en 0) la variable validos es un contador y va avanzando recorriendo las posi
                            // ciones del arreglo desde la 0 hasta 1 menos que la variable "cantidad"
        validos++;
        printf("\ndesea ingresar mas elementos a la lista? (s/n) \n");
        fflush(stdin);
        scanf("%c", &letra);
    }
    return validos;
}

/// O PARA QUE EL USUARIO TENGA QUE CARGAR EL ARREGLO COMPLETO:

int cargararreglochar (char B [], int dimension) //es int y no char porq el return devuelve validos, q es un entero
{
    int validos2=0;
    while (validos2 < dimension)
    {
        printf("\nIngrese una letra  ");
        fflush(stdin);
        scanf("%c", &B[validos2]);
        validos2++;
    }
    return validos2;
}

/// PARA CARGAR FLOTANTES

int cargaArregloReales(float D [], int dimension)
{
    char letra='s';
    int validosR=0;
    while ((letra=='s') && (validosR<dimension)) //validos es < que dimension porque las posiciones validas son cantidad menos 1
    {
        printf("\nIngrese un Nro real  ");
        fflush(stdin);
        scanf("%f", &D[validosR]);
        validosR++;
        printf("\ndesea ingresar mas Nros reales a la lista? (s/n) ");
        fflush(stdin);
        scanf("%c", &letra);
    }
    return validosR;
}

/// EJERC 2. MOSTRAR
/// Hacer una función que reciba como parámetro un arreglo y la cantidad de
/// elementos (válidos) cargados en él y los muestre por pantalla.

/// PARA ENTEROS:

void mostrararreglo (int A[], int validos)
{
    int i=0;
    printf("\nContenido del arreglo:  ");
    for (i=0; i<validos; i++)
    {
        printf(" | %d | ", A[i]); //va a ir imprimiendo cada una de las posiciones desde que i sea 0 hasta que i sea <validos
    }
}

/// o PARA CHAR:

void mostrarArregloChar (char B[], int validos2)
{
    int i=0;
    printf("\nContenido del arreglo:  ");
    for (i=0; i<validos2; i++)
    {
        printf("%c  ", B[i]); //va a ir imprimiendo cada una de las posiciones desde que i sea 0 hasta que i sea <validos
    }
}

/// EJER 3. SUMAR ENTEROS
/// Hacer una función que reciba como parámetro un arreglo y la cantidad de
/// elementos (válidos) cargados en él y calcule la suma de sus elementos.

int sumar (int A[], int validos)
{
    int rta=0;
    int i=0;
    for (i=0; i<validos; i++)
    {
        rta= rta + A[i];
    }
    return rta;
}

/// EJ 5. SUMAR REALES
///Realizar 1 función que sume los elementos reales de un arreglo de dimensión 100.

float sumareal (float D[], int validosR)
{
    float rta=0;
    int i=0;
    for (i=0; i<validosR; i++)
    {
        rta= rta+D[i];
    }
    return rta;
}

/// EJERC 4. PASAR PILA
/// Hacer una función que reciba como parámetro 1 arreglo, la cantidad de elementos
/// cargados en él y 1 Pila. La fn debe copiar los elementos del arreglo en la pila.

void copiarapila (int A[], Pila* PDestino, int validos)
{
    int i=0;
    while (i<validos && i<50) // porque la pila tiene dim maxima de 50
    {
        apilar(PDestino, A[i]); //sin & la pila porque hay un puntero
        i++;
    }
}

/// EJERC 6: BUSCAR -
/// Realizar 1 función que indique si 1 elemento dado se encuentra en 1 arreglo de caracteres.

int buscarChar (char B[], int validos, char dato)
{
    int i = 0;
    int flag = 0;

    while ((i < validos) && (flag == 0))
    {
        if (dato == B[i]) {
            flag =1;
        }
        else {
            i++;
        }
    }
  return flag; // el flag se evalua en el main!!
}

/// EJERC 7. INSERTAR EN ORDEN
/// Realizar una función que inserte 1 carácter en un arreglo ordenado
/// alfabéticamente, conservando el orden.

int insertarChar (char B [], int validos, char dato)
{
    int ult = validos-1; //esta es la ultima posicion, y el arreglo se va a recorrer desde el ultimo hacia el 1ro
    while (ult>=0 && dato<B[ult])
    {
        B[ult+1]=B[ult]; //lo que está en A[i] (el mayor), se corre 1 lugar hacia la dcha del arreglo para hacer un espacio
        ult--; //(el indice decrece, para ir recorriendo desde el ultimo hacia el 1ro, y se va comparando el elemnto con cada posicion hacia la pos 0
                // hasta que encuentre el hueco donde ubicarse, que va a ser cuando se corte el while porque el elemento ya no es menor que A[i]
    }
    B[ult+1]=dato; //el elemento a insertar se inserta en una posicion a la dcha, 1 posicion mas, de donde se cortó el while porque encontró un elem menor
return validos+1;  //importante porq al insertar n dato mas, el arreglo ahora tiene un elemento mas
}


/// EJER 8. BUSCAR EL MAYOR
/// Realizar una función que obtenga el máximo carácter de un arreglo dado.
// uso la misma funcion que para buscar un entero mayor, porque las letras por codigo
// ascii tienen  un nro asignado que tbien puede ordenarse de mayor a menor
//(si quiero ver el codigo ascii de cada letra: (char letra= 'n';
// (o la letra que quiero ver), y luego printf ("%d", letra);
// pongo %d en vez de %c porque no quiero ver la letra sino su codigo, que es un entero



char buscarMayor (char B [], int validos2)
{
    char miMayor= B[0];
    int i=1;
    for (i=1; i<validos2; i++)
    {
        if (miMayor < B[i])
        {
            miMayor= B[i];
        }
    }
return miMayor;
}

int buscarMenor (int B[], int validos)
{
    int miMenor= B[0];
    int i=1;

    for (i=1; i<validos; i++)
    {
        if (miMenor > B[i])
        {
            miMenor= B[i];
        }
    }
return miMenor;
}

/// EJERC 9. Realizar una función que determine si un arreglo es capicúa.

int capicua (int A[], int validos)
{
    int flag = 0;
    int i=0;
    int ult = validos-1;

    while(i<ult && flag ==0)
    {
        if (A[i]==A[ult])
        {
            i++;
            ult--;
        }
        else
            flag =1; //es al reves, pongo flag 1 cuando ya no es capicua porq hay q cortar el while, si no es flag 0 porq tiene q seguir analizando
        }            // todos, no puedo cortar el while
    return flag;
}


/// EJERC 10. Realizar una función que invierta los elementos de un arreglo.

/*
/// creando un 2do arreglo:

void invertirArreglo (int A [], int C [], int validos) //esta lo invierte pasándolo a otro arreglo
{
    int iA=0;           //i es el indice de A y arranca en la 1er posicion valida, que es 0
    int iC=validos-1;  //para la pila C pongo un indice inverso al indice i, que es de la pila A. arranca en la ultima posicon de C (q es validos-1)
    for (iA=0; iA<validos; iA++)
        {
        C[iC]=A [iA];
        iC --;         //el indice de C decrece de a 1 al = tiempo que el de A aumenta de a 1
        }
}                    //no retorna nada porq trabaja con los arrays como pilas

*/

/// SOBRE EL MISMO ARREGLO USANDO UN PIVOT:

void invertirArreglo2 (char A [], int validos)
{
    int i = 0; //es la posicion 0 del arreglo, que luego se va incrementando, es un contador
    int u = validos-1; //es la ultima psicion del arreglo, que luego va decreciendo, contador
    char aux; //UNA VARIABLE AUXILIAR PARA PIVOTEAR
    int tope = validos/2;

    while (i<tope) /// O while (i<=u)
    {
        aux = A[u]; //lo que está en la ult posicion  pasa a la variable auxiliar
        A[u]= A[i]; //lo que está en la 1ra posicion pasa a la ultima pos
        A[i]= aux;  //lo que esta en aux (que era lo de la ult posicion) pasa a la 1ra posicion
        i++; //aumenta el contador avanzando una posicion mas desde la 1ra
        u--;  //decrece el contador retrocediendo una posicion mas desde la ultima
    }
}


/// EJER 11: ORDENAMIENTOS (SELECCION E INSERCION)

/// 11.A. oRDENAMIENTO POR Selección.

int posicionMenor (int A[], int pos, int validos)
{
    char menor = A[pos];//arranca en 0 y va creciendo
    int posmenor = pos;
    int i = pos +1;
    while (i<validos) {
        if (menor < A[i]) {
            menor = A[i];
            posmenor = i;
        }
        i++;
    }
    return posmenor;
}

void ordenacionSeleccion (int A[], int validos)
{
    int posmenor;
    int aux;
    int i = 0;
    while (i<validos-1) {
        posmenor = posicionMenor(A,i,validos);//busca
        aux = A[posmenor]; // "pivotea"
        A[posmenor]=A[i];
        A[i]= aux;
        i++; // avanza
    }
}




/// EJERC 11. B. ORDENAMIENTO POR Inserción.

void insertar(int A[], int u, int dato)
{   //si sólo inserto=> u=val-1 (acá no)
    //acá u arranca en 0 y equivale a los vál de la zona ordenada
    while(u>=0 && dato<A[u])
    {
        A[u+1]=A[u];
        u--;
    }
    A[u+1]=dato;
}


void ordenacionInsercion (int A[], int validos)
{
    int i = 0;
    while (i<validos-1)
    {
        insertar(A,i,A[i+1]);
        i++;
    }
}






/// EJER 12 INTERCALAR ARREGLOS CHAR

int CharIntercalado (char F[], int validosF, char G[], int valG, char H[], int dimH)
{
     int iF=0;  //indices para recorrer cada una de las 3 listas
     int iG=0;
     int iH=0;

     while((iF<validosF) && (iG<valG) && (iH<dimH))
     {
        if (F[iF]<G[iG])
        {
            H[iH]=F[iF];
            iH++;
            iF++;
        }
        else
        {
            H[iH]=G[iG];
            iH++;
            iG++;
        }
    }
    while(iF<validosF) //a partir de aca recorro los arrays F o G por si quedaron elementos en alguna de ellas
    {
        H[iH]=F[iF];
        iH++;
        iF++;
    }
    while(iG<valG)
    {
        H[iH]=G[iG];
        iH++;
        iG++;
    }
return iH;  //porque va a ser la ultima posicion valida de ls lista H, la posicion < de iH
}
