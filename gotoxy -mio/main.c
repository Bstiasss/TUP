#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "gotoxy.h"

void imprimirUno();


int main()
{
    char c=0;
    int x=10;
    int y=10;

    hidecursor(0);
    color(9);
    gotoxy(x,y);
    printf("%c",219);

    do{
        Sleep(1000);
        x++;
        y++;
        imprimirUno();
        gotoxy(x,y);
        //system("cls");
        printf("%c",219);
        Beep(100,150);
        c=getch();
        switch(c){
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
            case 72:
                if(y>0){
                    y--;
                    gotoxy(x,y);
                    printf("%c",219);
                }
                break;
            case 75:
                if(x>0){
                    x--;
                    gotoxy(x,y);
                    printf("%c",219);
                }
                else{
                     Beep(100,150);
                }
                break;
            case 77:
                if(x<79){
                    x++;
                    gotoxy(x,y);
                    printf("%c",219);
                }
                break;
            case 80:
                if(y<23){
                    y++;
                    gotoxy(x,y);
                    printf("%c",219);
                }
                break;
        }
    }
    while(c!=27);

    return 0;
}

void imprimirUno(){

    int x=15;
    int y=10;
    for(int i = 0; i < 10; i++){
        y++;
        //int y=10;
        gotoxy(x,y);
        printf("%c",219);

    }

//gotoxy(x,y);
//printf("%c",219);
}
