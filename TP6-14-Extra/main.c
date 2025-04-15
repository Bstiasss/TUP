#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int filaVotos = 5;
const int colVotos = 4;
const int cantidadCabeceras = 5;

void imprimirTabla(int matrizVotos[5][4], char matrizCabecera[cantidadCabeceras][20]);
int calcularTotalVotos(int matrizVotos[filaVotos][colVotos], int arregloTotalVotos[4]);


int main()
{
    //  int matrizVotos[filaVotos][colVotos]
    int matrizVotos[5][4] = {{194,48,206,45}, {180,20,320,16}, {221,90,140,20}, {432,51,821,14}, {820,61,946,18}};
    char matrizCabecera[5][20] = {{"Distrito  "},{"Candidato A"}, {"Candidato B"}, {"Candidato C"}, {"Candidato D"}};
    int arregloTotalVotos[4];

    imprimirTabla(matrizVotos, matrizCabecera);

    int indiceMasVotado = calcularTotalVotos(matrizVotos,arregloTotalVotos);

    //Imprimo totales y remarco el mas votado
    printf("|   TOTAL   |");
    for(int i = 0; i < 4; i++)
    {
        if(i == indiceMasVotado){

            printf("|**  %i  **|", arregloTotalVotos[i]);
        }else{
        printf("|    %i    |", arregloTotalVotos[i]);
        }
    }

    //espacio al final para que quede bien
    printf("\n\n");

    system("pause");

    return 0;
}


void imprimirTabla(int matrizVotos[5][4], char matrizCabecera[cantidadCabeceras][20])
{
    for(int i = 0; i < cantidadCabeceras; i++)
    {
        printf("|%s |", matrizCabecera[i]);
    }
    printf("\n");

    for(int i=0; i < filaVotos; i++)
    {
        printf("|    %i      |", i+1);
        for(int j=0; j < colVotos; j++)
        {
            printf("|    %i     |", matrizVotos[i][j]);
        }
        printf("\n");
    }
}

//calcula el total de votos , lo guarda en el arreglo y devuelve el indice del candidato mas votado
int calcularTotalVotos(int matrizVotos[filaVotos][colVotos], int arregloTotalVotos[4])
{
    int indiceMasVotado = 0; //asumo que el primer candidato es el mas votado
    int totalVotos;

    for(int i = 0; i < colVotos; i++)
    {
        totalVotos = 0;
        for(int j = 0; j < filaVotos; j++)
        {
            totalVotos += matrizVotos[j][i];
        }

        arregloTotalVotos[i] = totalVotos;

        if(arregloTotalVotos[indiceMasVotado] < arregloTotalVotos[i])
        {
            indiceMasVotado = i;
        }
    }
    return indiceMasVotado;
}
