#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>
#include "gotoxy.h"

#define LEFT 1
#define RIGHT 79
#define TOP 1
#define BOTTOM 16

void *moverBola();
void dibujarTabla(int x, int y, int colorNumero);
void *verificarBolaTabla();
void dibujarMarco();

int xBola=30;
int yBola=2;
int xTabla = RIGHT / 2 ;
int yTabla = BOTTOM+1;
int colorTabla = 5;
int level = 100;
int puntos = 0;
int exitGame = 0;


int main()
{
    pthread_t hiloMoverBola, hiloControlBolaTabla;
    int x = 0;
    int y = 0;

    hidecursor(0);
    // Sleep(5000);
    dibujarMarco();

    char c=0;

    dibujarTabla(xTabla,yTabla,colorTabla);

    pthread_create(&hiloMoverBola, NULL, moverBola, NULL);
    pthread_create(&hiloControlBolaTabla, NULL, verificarBolaTabla, NULL);

    do
    {
        c=getch();
        switch(c)
        {
        case 45: //subir level
            if(level < 500){
            level += 10;
            }
            break;

        case 43: //subir level
            if(level > 20){
            level -= 10;
            }
            break;
        case 59:
            color(9);
            break;
        case 60:
            color(10);
            break;
        case 61:
            color(11);
            break;
        case 62:
            color(12);
            break;
        case 63:
            color(13);
            break;
        case 64:
            color(14);
            break;
        case 27:
            x=10;
            y=10;
            gotoxy(x,y);
            printf("Bye Bye.....");
            getch();
            break;
        /*       case 72:
                   if(y>0)
                   {
                       y--;
                       gotoxy(x,y);
                       printf("%c",219);
                   }
                   break;
    */       case 75:
            if(xTabla > LEFT)
            {
                xTabla--;
                dibujarTabla(xTabla,yTabla,colorTabla);
                /*                gotoxy(xTabla-6,yTabla);
                                color(0);
                                for(int i=0; i< 12; i++ ){
                                    printf("%c",219);
                                }

                                gotoxy(xTabla-5,yTabla);
                                color(14);
                                for(int i=0; i< 10; i++ ){
                                    printf("%c",219);
                                }
                */
            }
            else
            {
                Beep(100,150);
            }
            break;
        case 77:
            if(xTabla < RIGHT)
            {
                xTabla++;

                dibujarTabla(xTabla,yTabla,colorTabla);
                /*               gotoxy(xTabla-6,yTabla);
                               color(0);
                               for(int i=0; i< 12; i++ ){
                                   printf("%c",219);
                               }

                               gotoxy(xTabla-5,yTabla);
                               color(14);
                               for(int i=0; i< 10; i++ ){
                                   printf("%c",219);
                               }
                */
            }
            break;
            /*        case 80:
                        if(y<23)
                        {
                            y++;
                            gotoxy(x,y);
                            printf("%c",219);
                        }
             */           break;
        }
    }
    while(c!=27);

    return 0;
}

void *moverBola()
{
    int direccionX = 1; //hacia derecha
    int direccionY = 1; //hacia abajo

    while(exitGame == 0)
    {
        if(xBola == RIGHT)
        {
            direccionX = direccionX *(-1);
        }
        if(xBola == LEFT)
        {
            direccionX = direccionX *(-1);
        }
        if(yBola == BOTTOM)
        {
            direccionY = direccionY *(-1);
        }
        if(yBola == TOP)
        {
            direccionY = direccionY *(-1);
        }

        if(direccionX == -1)
        {
            xBola--;
        }
        else
        {
            xBola++;
        }
        if(direccionY == -1)
        {
            yBola--;
        }
        else
        {
            yBola++;
        }

        gotoxy(xBola,yBola);

        color(9);
        printf("%c",254);
        //      Beep(100,150);

        Sleep(level);
        gotoxy(xBola,yBola);
        color(0);
        printf("%c",219);


    }

    pthread_exit(0);
}


void dibujarTabla(int x, int y, int colorNumero)
{
    gotoxy(x-6,y);
    color(0);
    for(int i=0; i< 12; i++ )
    {
        printf("%c",219);
    }

    gotoxy(x-5,y);
    color(colorNumero);
    for(int i=0; i< 10; i++ )
    {
        printf("%c",219);
    }
}

void *verificarBolaTabla(){

    while(exitGame == 0){
        if(yBola == BOTTOM){
            if(xBola >= xTabla - 5 && xBola <= xTabla + 5){
                puntos++;
            }else{
            exitGame = 1;
            }


        }



    }

}

void dibujarMarco(){

    //lados horizontales
    int i = LEFT - 1;
    color(14);

    while(i <= RIGHT +1){
        gotoxy(i,TOP -1 );
        printf("%c",223);

        gotoxy(i,BOTTOM + 3 );
        printf("%c",223);
        i++;
    }

    //lados verticales
    i = TOP - 1;
    color(14);

    while(i < BOTTOM + 3){
        gotoxy(LEFT-1, i);
        printf("%c",219);

        gotoxy(RIGHT+1,i );
        printf("%c",219);
        i++;
    }


}

