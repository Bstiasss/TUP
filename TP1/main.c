#include <stdio.h>
#include <stdlib.h>

int randomizar();
void mayorMenor(int num1, int num2, int num3);
int sumatoria(int num);
void mostrarTabla(int num);
void calcular(int num1, int num2, char operacion);
int sumar(int num1, int num2);
int restar(int num1, int num2);
int multiplicar(int num1, int num2);
float dividir(int num1, int num2);


int main()
{
    //1
    int numRandom = randomizar();
    printf("El numero random es: %i \n", numRandom);

    //2
    int num1, num2, num3;
    printf("Ingrese el primer numero: ");
    scanf("%i", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%i", &num2);
    printf("Ingrese el tercer numero: ");
    scanf("%i", &num3);
    mayorMenor(num1, num2, num3);

    //3
    int numN, suma;
    printf("\nIngrese el numero N: ");
    scanf("%i", &numN);
    suma = sumatoria(numN);
    printf("La sumatoria es: %i", suma);

    //4
    int numMultiplicar;
    printf("\nIngrese el numero para mostrar su tabla: ");
    scanf("%i", &numMultiplicar);
    mostrarTabla(numMultiplicar);

    //5
    int num1Calc, num2Calc;
    char operCalc;

    printf("\nCalculadora----");
    printf("\nIngrese el primer numero: ");
    scanf("%i", &num1Calc);
    printf("\nIngrese el segundo numero: ");
    scanf("%i", &num2Calc);
    printf("\nIngrese el operador (s: sumar, m: multiplicar, r: restar, d: dividir ");
    fflush(stdin);
    scanf("%c", &operCalc);

    calcular(num1Calc, num2Calc, operCalc);


    return 0;
}

/** 1. Desarrollar una función que devuelva un valor RANDOM en el rango de 0 a 100.
*/

int randomizar(){
    int num;
    srand(time(NULL));
    num = rand() % 100 + 1;

    return num;
}

/** 2. Diseñe una función que reciba 3 números enteros y muestre el mayor y el menor
*/

void mayorMenor(int num1, int num2, int num3){

    int mayor, menor;

    if(num1 >= num2 && num1 >= num3){
        mayor = num1;
    }else if(num2 >= num1 && num2 >= num3){
        mayor = num2;
    }else{
        mayor = num3;
    }

    if(num1 <= num2 && num1 <= num3){
        menor = num1;
    }else if(num2 <= num1 && num2 <= num3){
        menor = num2;
    }else{
        menor = num3;
    }

    printf("El numero mayor es: %i y el numero menor es: %i", mayor, menor);


}

/** 3. Diseñe una función que reciba un número entero N y realice la suma de los números
enteros positivos menores que N y lo retorne. N es un dato ingresado por el usuario en
el main.
*/

int sumatoria(int num){

    int sumatoria = 0;

    for(int i=0; i < num; i++){
        sumatoria += i;
    }

    return sumatoria;
}

/** 4. Desarrollar una función que muestre la tabla de multiplicar de un número entero recibido por
parámetro.

*/

void mostrarTabla(int num){

    int resultado;
    for(int i=1; i <= 10; i++){
        resultado = i * num;
        printf("\n%i x %i = %i", num, i, resultado);
    }

}


/**5. Realice una pequeña calculadora, utilizando funciones (una función de suma, una de
multiplicación, una de resta, una de división…)
*/


void calcular(int num1, int num2, char operacion){

    int suma, resta, multiplicacion;
    float division;

    switch (operacion){

    case 's':
        suma = sumar(num1, num2);
        printf("\nEl resultado de la suma es: %i", suma);
        break;
    case 'r':
        resta = restar(num1, num2);
        printf("\nEl resultado de la resta es: %i", resta);
        break;
    case 'm':
        multiplicacion = multiplicar(num1, num2);
        printf("\nEl resultado de la multiplicacion es: %i", multiplicacion);
        break;
    case 'd':
        division = dividir(num1, num2);
        printf("\nEl resultado de la division es: %f", division);
        break;

    }

}

int sumar(int num1, int num2){

    int suma;
    suma = num1 + num2;

    return suma;
}

int restar(int num1, int num2){
    int resta;
    resta = num1 - num2;

    return resta;
}

int multiplicar(int num1, int num2){
    int multiplicacion;
    multiplicacion = num1 * num2;

    return multiplicacion;
}


float dividir(int num1, int num2){
    float division;
    division = (float) num1 / num2;

    return division;
}
