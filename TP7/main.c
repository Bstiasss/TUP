#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char nombre[30];
    char genero; //m, f, o

} Alumno;

Alumno cargarAlumno();
int cargarArregloAlumnos(Alumno arregloAlumnos[], int dim);
void mostrarAlumno(Alumno alumno);
void mostrarArregloAlumnos(Alumno arrelgoAlumnos[], int validos);
int ingresarMatriculaAlumno();
void encontrarAlumno(Alumno arregloAlumnos[], int validos);


int main()
{
    Alumno arregloAlumno[3];
    int validos = cargarArregloAlumnos(arregloAlumno, 3);

    mostrarArregloAlumnos(arregloAlumno, validos);

    encontrarAlumno(arregloAlumno, validos);


    return 0;
}

//1 - Hacer una función que  cargue un arreglo de alumnos, hasta que el usuario lo decida.

Alumno cargarAlumno(){

    Alumno alumno;
    printf("Ingrese la matricula del alumno: ");
    scanf("%i", &alumno.matricula);
    printf("Ingrese el nombre del alumno: ");
    fflush(stdin);
    scanf("%s", &alumno.nombre);
    printf("Ingrese el genero del alumno (m, f, o):");
    fflush(stdin);
    scanf("%c", &alumno.genero);

    return alumno;
}

int cargarArregloAlumnos(Alumno arregloAlumnos[], int dim){

    int i = 0;
    char control = 's';

    do{
        arregloAlumnos[i] = cargarAlumno();
        i++;
        printf("\nIngrese 's' para cargar otro alumno:");
        fflush(stdin);
        scanf("%c", &control);

    }while(control == 's' && i < dim);

    return i;

}


//2 - Hacer una función que muestre un arreglo de alumnos por pantalla. Modularizar.

void mostrarAlumno(Alumno alumno){

    printf("Matricula: %i \n", alumno.matricula);
    printf("Nombre: %s \n", alumno.nombre);
    printf("Genero: %c \n", alumno.genero);

}

void mostrarArregloAlumnos(Alumno arregloAlumnos[], int validos){

    for(int i = 0; i < validos; i++){
        mostrarAlumno(arregloAlumnos[i]);
        printf("\n");
    }
}

//3 -  Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.

int ingresarMatriculaAlumno(){
    int matricula;
    printf("\nIngrese la matricula del alumno:");
    scanf("%i", &matricula);

    return matricula;
}



void encontrarAlumno(Alumno arregloAlumnos[], int validos){

    int matricula = ingresarMatriculaAlumno();
    int alumnoEncontrado = 0;
    int i = 0;
    while(i < validos && alumnoEncontrado == 0){

        if(matricula == arregloAlumnos[i].matricula){
            alumnoEncontrado = 1;
        }

        i++;
    }

    if(alumnoEncontrado){
        mostrarAlumno(arregloAlumnos[i-1]);
    }else{
        printf("\nNo se encontro el alumno con matricula %i", matricula);
    }
}
