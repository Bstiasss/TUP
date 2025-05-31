#include <stdio.h>
#include <stdlib.h>

int main()
{

  /*  FILE *archi = fopen("prueba1.bin", "rb"); //se abre en modo lectura

    if(archi == NULL){ //si no pudo ser abierto
        archi = fopen("prueba1.bin", "wb");

        if(archi != NULL){ //se crea el archivo y puedo trabajar

            //trabajo en el archivo
            printf("Archivo creado");
            fclose(archi);

        }else{

            printf("ERROR de datos - El archivo no puede ser abierto");
        }


    }else{

        //trabajo con el archivo
        printf("archivo listo para trabajar");

        fclose(archi);
    }

    if(archi != NULL){

        printf("archivo creado");
        fclose(archi);
    }else{
        printf("Error");
    }
*/

    int dato = 4;
    FILE *archi = NULL;
    char nombre[20];
    printf("\n Ingrese el nombre y ruta del archivo que desea abrir: ");
    fflush(stdin);
    gets(nombre);
    archi = fopen(nombre, "rb");

    if(archi == NULL){
        archi = fopen(nombre, "wb");
        if(archi != NULL){ // se pudo crear el archivo

            fwrite(&dato, sizeof(int), 1, archi);
            //puedo trabajar
            system("pause");
            if(fclose(archi) == -1){
            printf("El archivo no se pudo cerrar");
       }else{
            printf("Archivo cerrado exitosamente");
       }

        }else{
            printf("error creado el archivo");
        }


    }else{
        int otro;

        fread(&otro, sizeof(int), 1, archi);
        printf("leido %i", otro);

        //aca puedo leer el archivo
       if(fclose(archi) == -1){
            printf("El archivo no se pudo cerrar");
       }else{
            printf("Archivo cerrado exitosamente");
       }
    }

    return 0;
}
