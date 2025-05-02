#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>
#include "gotoxy.h"

#define RIGHT 79
#define BOTTOM 16

void *moverBola();
void dibujarTabla(int x, int y, int colorNumero);

int xBola=1;
int yBola=1;
int xTabla = RIGHT / 2 ;
int yTabla = BOTTOM+1;
int colorTabla = 5;
int exitGame = 0;

int main()
{
    pthread_t hilo1;
    int x = 0;
    int y = 0;

    hidecursor(0);



   // Sleep(5000);



    char c=0;

    dibujarTabla(xTabla,yTabla,colorTabla);

    pthread_create(&hilo1, NULL, moverBola, NULL);

    do
    {

        c=getch();
        switch(c)
        {
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
            if(xTabla>0)
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
            if(xTabla<79)
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
 */           }
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
        if(xBola == 0)
        {
            direccionX = direccionX *(-1);
        }
        if(yBola == BOTTOM)
        {
            direccionY = direccionY *(-1);
        }
        if(yBola == 0)
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

        Sleep(100);
        gotoxy(xBola,yBola);
        color(0);
        printf("%c",219);


    }

    pthread_exit(0);
}


void dibujarTabla(int x, int y, int colorNumero){


                gotoxy(x-6,y);
                color(0);
                for(int i=0; i< 12; i++ ){
                    printf("%c",219);
                }

                gotoxy(x-5,y);
                color(colorNumero);
                for(int i=0; i< 10; i++ ){
                    printf("%c",219);
                }

}
