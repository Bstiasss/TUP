#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <strings.h>

typedef struct {
    int legajo;
    char nombreYapellido[30];
    int edad;
    int anio;
} stAlumno;

void agregarElementoArchivo(char nombreArchivo[], int elemento);
void mostrarContenidoArchivo(char nombreArchivo[]);
int cantidadRegistros(char nombreArchivo[]);
stAlumno cargarAlumno();
void guardar5Alumnos(char nombreArchivo[]);
void mostrarAlumno(stAlumno alumno);
void mostrarAlumnosArchivo(char nombreArchivo[]);
void agregarAlumnoFinalArchivo(char nombreArchivo[]);
void pasarAPilaLegajos(char nombreArchivo[], Pila* pila);
int contarAlumnosMayores(char nombreArchivo[], int edad);
void mostrarAlumnosEnRango(char nombreArchivo[], int edadMenor, int edadMayor);
void mostrarDatosAlumnosMayorEdad(char nombreArchivo[]);
int contarAlumnosEnAnioEnArchivo(char nombreArchivo[], int anio);
void copiarArregloArchivoAlumnos(stAlumno arregloAlumnos[], int validosAlumnos,  char nombreArchivo[]);
int copiarArchivoArregloAlumnosPorAnio(stAlumno arregloAlumnos[], char nombreArchivo[], int anio);
int devolverCantidadRegistros(char nombreArchivo[], int tamanoTipo);
void mostrarRegistroArchivo(char nombreArchivo[], int numeroRegistro);
stAlumno modificarAlumno(stAlumno alumno);
void modificarRegistro(char nombreArchivo[], int numeroRegistro);
void invertirElementosArchivo(char nombreArchivo[]);

int main()
{
    char nombreArchivo[30] = "archivo.bin";
    int elemento = 943;
    Pila pilaAlumnos;
    inicpila(&pilaAlumnos);

   // agregarElementoArchivo(nombreArchivo, elemento);
    mostrarContenidoArchivo(nombreArchivo);
    int cantidad = cantidadRegistros(nombreArchivo);
    printf("\nLa cantidad de registros es: %i", cantidad);
    //guardar5Alumnos(nombreArchivo);
    mostrarAlumnosArchivo(nombreArchivo);
    //agregarAlumnoFinalArchivo(nombreArchivo);
    //mostrarAlumnosArchivo(nombreArchivo);
  /*  pasarAPilaLegajos(nombreArchivo, &pilaAlumnos);
    mostrar(&pilaAlumnos);
    int edad = 20;
    int cantidadAlumnosMayores = contarAlumnosMayores(nombreArchivo, edad);
    printf("La cantidad de alumnos mayores a %i es %i", edad, cantidadAlumnosMayores);
    mostrarAlumnosEnRango(nombreArchivo,17, 25);
    mostrarDatosAlumnosMayorEdad(nombreArchivo);

    int anio;
    printf("\nIngrese el año a buscar: ");
    scanf("%i", &anio);
    int cantidadAlumnosAnio = contarAlumnosEnAnioEnArchivo(nombreArchivo, anio);
    printf("La cantidad de alumnos en el año %i es: %i", anio, cantidadAlumnosAnio);

    char nombreArchivo2 [30] = "alumnos.bin";
    stAlumno arregloAlumnos[5];
    arregloAlumnos[0].legajo = 1;
    strcpy(arregloAlumnos[0].nombreYapellido, "Mario");
    arregloAlumnos[0].edad = 15;
    arregloAlumnos[0].anio = 1;

    arregloAlumnos[1].legajo = 2;
    strcpy(arregloAlumnos[1].nombreYapellido, "Yeny");
    arregloAlumnos[1].edad = 18;
    arregloAlumnos[1].anio = 1;

    arregloAlumnos[2].legajo = 3;
    strcpy(arregloAlumnos[2].nombreYapellido, "Jony");
    arregloAlumnos[2].edad = 26;
    arregloAlumnos[2].anio = 2;

    copiarArregloArchivoAlumnos(arregloAlumnos, 3, nombreArchivo2);
    mostrarAlumnosArchivo(nombreArchivo2);

    stAlumno arregloAlumnosNuevo[10];
    int anioArregloAlumnos;
    printf("\nIngrese el año de los alumnos a buscar para el arreglo: ");
    scanf("%i", &anioArregloAlumnos);
    int validosAlumnos = copiarArchivoArregloAlumnosPorAnio(arregloAlumnosNuevo, nombreArchivo2, anioArregloAlumnos);

    printf("\nRecorro el arreglo de alumnos nuevo");
    for(int i = 0; i < validosAlumnos; i++){
        mostrarAlumno(arregloAlumnosNuevo[i]);
    }

    int cantidadRegistosEnArchivo = devolverCantidadRegistros(nombreArchivo2, sizeof(stAlumno));
    printf("\nLa cantidad de registros de Alumno en el archivo %s es de %i", nombreArchivo2, cantidadRegistosEnArchivo);

    printf("\nIngrese el numero de registro del alumno a buscar:");
    int numeroRegistro;
    scanf("%i", &numeroRegistro);
    mostrarRegistroArchivo(nombreArchivo, numeroRegistro);

    int numeroRegistroABuscar = -1;
    while(numeroRegistroABuscar < 0 || numeroRegistroABuscar >= devolverCantidadRegistros(nombreArchivo, sizeof(stAlumno)) ){
        printf("Ingrese el numero de registro a buscar:");
        scanf("%i", &numeroRegistroABuscar);
    }

   // modificarRegistro(nombreArchivo, numeroRegistroABuscar);
    mostrarAlumnosArchivo(nombreArchivo);
*/
    invertirElementosArchivo(nombreArchivo);
    mostrarAlumnosArchivo(nombreArchivo);

    return 0;
}

//Ejercicio 1
void agregarElementoArchivo(char nombreArchivo[], int elemento){

    FILE *archivo = fopen(nombreArchivo, "ab");
    int status;

    if (archivo != NULL){

        status = fwrite(&elemento, sizeof(int), 1, archivo);

       // printf("%i", status);
        fclose(archivo);

    }
}

//Ejercicio 2
void mostrarContenidoArchivo(char nombreArchivo[]){

    FILE *archivo = fopen(nombreArchivo, "rb");
    int elemento;

    if(archivo == NULL){
        printf("Error leyendo archivo");

    }else{
        while(!feof(archivo)){
            fread(&elemento, sizeof(int), 1, archivo);
            printf("%i", elemento);
        }
        fclose(archivo);
    }

}

//Ejercicio 3
int cantidadRegistros(char nombreArchivo[]){
    int cant = 0;
    int elemento;
    FILE *archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL){
        while(fread(&elemento, sizeof(int), 1, archivo) > 0){
        cant++;
        }

    }else{
        printf("\nError leyendo archivo");
    }

    return cant;
}

// Ejercicio 4

stAlumno cargarAlumno(){
    stAlumno alumno;
    printf("\nNuevo alumno: ");
    printf("\nIngrese el numero de legajo:");
    scanf("%i", &alumno.legajo);
    printf("\nIngrese el nombre y apellido: ");
    fflush(stdin);
    gets(alumno.nombreYapellido);
    printf("\nIngrese la edad: ");
    scanf("%i", &alumno.edad);
    printf("\nIngrese el anio: ");
    scanf("%i", &alumno.anio);

    return alumno;
}

void guardar5Alumnos(char nombreArchivo[]){

    FILE *archivo = fopen(nombreArchivo, "rb");
    if(archivo == NULL){
        printf("Archivo no existe, se crea.");
        archivo = fopen(nombreArchivo, "wb");

    }else{
        printf("El archivo existe");
        fclose(archivo);
        archivo = fopen(nombreArchivo, "wb");
    }

    for(int i = 0; i < 5 ; i++){
        stAlumno alumno = cargarAlumno();
        fwrite(&alumno, sizeof(alumno), 1, archivo);

    }
    fclose(archivo);

}

//Ejercicio 5

void mostrarAlumno(stAlumno alumno){
    printf("\nDatos del alumno:");
    printf("\nLegajo: %i", alumno.legajo);
    printf("\nNombre y Apellido: %s", alumno.nombreYapellido);
    printf("\nEdad: %i", alumno.edad);
    printf("\nAño: %i", alumno.anio);
}

void mostrarAlumnosArchivo(char nombreArchivo[]){
    FILE *archivo = fopen(nombreArchivo, "rb");
    stAlumno alumno;

    if(archivo == NULL){
        printf("El archivo no existe.");

    }else{
        while(fread(&alumno, sizeof(stAlumno), 1, archivo)){
            mostrarAlumno(alumno);
        }

        fclose(archivo);
    }



}

//Ejercicio 6

void agregarAlumnoFinalArchivo(char nombreArchivo[]){
    FILE *archivo = fopen(nombreArchivo, "ab");
    if(archivo == NULL){
        printf("Error leyendo archivos");
    }else{
        stAlumno alumno = cargarAlumno();
        fwrite(&alumno, sizeof(stAlumno), 1, archivo);
        fclose(archivo);

    }

}

//Ejercicio 7

void pasarAPilaLegajos(char nombreArchivo[], Pila* pila){

    FILE *archivo = fopen(nombreArchivo, "rb");
    stAlumno alumno;
    if(archivo == NULL){
        printf("\nError leyendo el archivo");
    }else{
        while(!feof(archivo)){

            fread(&alumno, sizeof(stAlumno), 1, archivo);
            if(alumno.edad > 18){
                apilar(pila, alumno.legajo);
            }
        }
        fclose(archivo);
    }

}

//Ejercicio 8

int contarAlumnosMayores(char nombreArchivo[], int edad){

    FILE *archivo = fopen(nombreArchivo, "rb");
    stAlumno alumno;
    int contador = 0;

    if(archivo == NULL){
        printf("Error leyendo archivo");
    }else{
        while(fread(&alumno,sizeof(stAlumno), 1, archivo)){
            if(alumno.edad > edad){
                contador++;
            }
        }
        fclose(archivo);
    }
    return contador;
}


//Ejercicio 9

void mostrarAlumnosEnRango(char nombreArchivo[], int edadMenor, int edadMayor){

    FILE *archivo = fopen(nombreArchivo, "rb");
    stAlumno alumno;

    if(archivo == NULL){
        printf("Error leyendo archivo");
    }else{
        while(fread(&alumno,sizeof(stAlumno), 1, archivo)){
            if(alumno.edad > edadMenor && alumno.edad < edadMayor){
                printf("\nNombre: %s", alumno.nombreYapellido);
            }
        }
        fclose(archivo);
    }
}

//Ejercicio 10

void mostrarDatosAlumnosMayorEdad(char nombreArchivo[]){
    FILE *archivo = fopen(nombreArchivo, "rb");
    stAlumno alumno;

    if(archivo == NULL){
        printf("Error leyendo archivo");
    }else{
        while(fread(&alumno,sizeof(stAlumno), 1, archivo)){
            if(alumno.edad > 18){
                mostrarAlumno(alumno);
            }
        }
        fclose(archivo);
    }
}

//Ejercicio 11

int contarAlumnosEnAnioEnArchivo(char nombreArchivo[], int anio){

    int cantidadAlumnos = 0;
    stAlumno alumno;
    FILE *archivo = fopen(nombreArchivo, "rb");
    if(archivo == NULL){
        printf("No se puede abrir el archivo");
    }else{
        while(!feof(archivo)){
            fread(&alumno, sizeof(stAlumno), 1, archivo);
            if(alumno.anio == anio){
                cantidadAlumnos++;
            }
        }
        fclose(archivo);
    }
    return cantidadAlumnos;
}

//Ejercicio 12

void copiarArregloArchivoAlumnos(stAlumno arregloAlumnos[], int validosAlumnos,  char nombreArchivo[]){

    stAlumno alumno;
    FILE *archivo = fopen(nombreArchivo, "wb");
    if(archivo == NULL){
        printf("Error creando el archivo");
    }else{
        int i = 0;
 /*       while(i < validosAlumnos){
            alumno = arregloAlumnos[i];
            fwrite(&alumno, sizeof(stAlumno), 1, archivo);
            i++;
        }

        //probando copiar un array
 */     fwrite(arregloAlumnos, sizeof(stAlumno), validosAlumnos, archivo);

        fclose(archivo);
    }
}

int copiarArchivoArregloAlumnosPorAnio(stAlumno arregloAlumnos[], char nombreArchivo[], int anio){
    stAlumno alumno;
    int i = 0;
    FILE *archivo = fopen(nombreArchivo, "rb");
    if(archivo == NULL){
        printf("Error abriendo archivo");
    }else{
        while(fread(&alumno, sizeof(stAlumno), 1, archivo) > 0){
            if(alumno.anio == anio){
                arregloAlumnos[i] = alumno;
                i++;
            }
        }
        fclose(archivo);
    }
    return i;
}

//Ejercicio 13

int devolverCantidadRegistros(char nombreArchivo[], int tamanoTipo){
    FILE *archivo = fopen(nombreArchivo, "rb");
    int cantidadBytes;
    if(archivo == NULL){
        printf("Error abriendo archivo");
    }else{
        fseek(archivo, 0, SEEK_END);
        cantidadBytes = ftell(archivo);
        fclose(archivo);

    }
    return cantidadBytes / tamanoTipo;
}

//Ejercicio 14

void mostrarRegistroArchivo(char nombreArchivo[], int numeroRegistro){
    if(numeroRegistro > 9 || numeroRegistro < 0){
        printf("Numero de registro no valido");
        return;
    }
    stAlumno alumno;
    FILE *archivo = fopen(nombreArchivo, "rb");
    if(archivo == NULL){
        printf("Error abriendo archivo");
    }else{
        int posicionRegistro = numeroRegistro * sizeof(stAlumno);
        fseek(archivo, posicionRegistro , SEEK_SET);
        fread(&alumno, sizeof(stAlumno), 1, archivo);
        mostrarAlumno(alumno);
        fclose(archivo);
    }

}

//Ejercicio 15

stAlumno modificarAlumno(stAlumno alumno){
    stAlumno alumnoNuevo;
    printf("\nAlumno actual:");
    mostrarAlumno(alumno);
    printf("\nModificar: ");
    printf("\nIngrese el numero de legajo:");
    scanf("%i", &alumnoNuevo.legajo);
    printf("\nIngrese el nombre y apellido: ");
    fflush(stdin);
    gets(alumnoNuevo.nombreYapellido);
    printf("\nIngrese la edad: ");
    scanf("%i", &alumnoNuevo.edad);
    printf("\nIngrese el anio: ");
    scanf("%i", &alumnoNuevo.anio);

    return alumnoNuevo;
}



void modificarRegistro(char nombreArchivo[], int numeroRegistro){
    if(numeroRegistro  >= devolverCantidadRegistros(nombreArchivo, sizeof(stAlumno))){
        printf("ERROR - Numero de registro superior a cantidad de registros");
        return;
    }else{
        stAlumno alumno;
        FILE *archivo = fopen(nombreArchivo, "r+b");
        if(archivo == NULL){
            printf("Error abriendo archivo");
        }else{
            fseek(archivo, numeroRegistro * sizeof(stAlumno), SEEK_SET);
            fread(&alumno, sizeof(stAlumno), 1, archivo);
            alumno = modificarAlumno(alumno);
            fseek(archivo, sizeof(stAlumno)* (-1), SEEK_CUR);
            fwrite(&alumno, sizeof(stAlumno), 1, archivo);
            fclose(archivo);
        }
    }

}

//ejercicio 16
void invertirElementosArchivo(char nombreArchivo[]){
    stAlumno alumno1, alumno2;
    FILE *archivo = fopen(nombreArchivo, "r+b");
    if(archivo == NULL){
        printf("Error abriendo el archivo");
    }else{
        int cantidadTotalDeRegistros = devolverCantidadRegistros(nombreArchivo, sizeof(stAlumno));
        int cantidadRegistrosProcesados = 0;

        while(cantidadRegistrosProcesados <= cantidadTotalDeRegistros / 2){

            fseek(archivo, cantidadRegistrosProcesados * sizeof(stAlumno), SEEK_SET);
            fread(&alumno1, sizeof(stAlumno),1, archivo);
            fseek(archivo, (cantidadRegistrosProcesados + 1) * (-1) * sizeof(stAlumno), SEEK_END);
            fread(&alumno2, sizeof(stAlumno),1, archivo);

            fseek(archivo, cantidadRegistrosProcesados * sizeof(stAlumno), SEEK_SET);
            fwrite(&alumno2, sizeof(stAlumno),1, archivo);
            fseek(archivo, (cantidadRegistrosProcesados + 1) * (-1) * sizeof(stAlumno), SEEK_END);
            fwrite(&alumno1, sizeof(stAlumno),1, archivo);

            cantidadRegistrosProcesados++;
        }
        fclose(archivo);
    }
}
