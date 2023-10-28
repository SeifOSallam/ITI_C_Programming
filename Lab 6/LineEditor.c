#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include "LineEditor.h"
#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77
#define BACKSPACE 8
#define RED 4
#define WHITE 15
void SetColor(int ForgC){
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                 //Mask out all but the background attribute, and add in the forgournd     color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }

void gotoxy(int x,int y)
{
    COORD coord={0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void runEditor() {
    int posX = 0, posY = 0;
    int boxLimitX = 20, boxLimitY = 50;
    char lines[boxLimitX-1][boxLimitY-1];
    for (int i=0;i<boxLimitX-1;i++) {
        for (int j=0;j<boxLimitY-1;j++) {
            lines[i][j] = 0;
        }
    }


    while(1) {

        system("cls");
        printStatus(posX, posY);
        printOuterBox(boxLimitX,boxLimitY);
        printText(boxLimitX, boxLimitY, lines, posX, posY);
        char c = getch();
        if (c != -32 && c != BACKSPACE) {
            //pushText(boxLimitX-1, boxLimitY-1,lines,posX,posY);
            lines[posX][posY] = c;
            if (posY == boxLimitY-3) {
                posY = 0;
                posX++;
            }
            else posY++;
            if (posX == boxLimitX-3) {
                posX = 0;
            }
        }
        else if (c == BACKSPACE) {
            if (posY != 0) {
                pullbackText(boxLimitX-1, boxLimitY-1,lines,posX,posY);
                posY--;
            }
        }
        else {
            c = getch();
            switch(c) {
                case UP_KEY: {
                    if (posX == 0) {
                        posX = boxLimitX - 3;
                    }
                    else {
                        posX--;
                    }

                    break;
                }
                case DOWN_KEY: {
                    if (posX == boxLimitX - 3) {
                        posX = 0;
                    }
                    else {
                        posX++;
                    }

                    break;
                }
                case LEFT_KEY: {
                    if (posY == 0) {
                        posY = boxLimitY - 3;
                    }
                    else {
                        posY--;
                    }
                    break;
                }
                case RIGHT_KEY: {
                    if (posY == boxLimitY - 3) {
                        posY = 0;
                    }
                    else {
                        posY++;
                    }
                    break;
                }
                default: break;
            }
        }

    }
}

void printOuterBox(int LimitX, int LimitY) {
    for (int i=0;i<LimitX;i++) {
        for (int j=0;j<LimitY;j++) {
            if (i == 0 || i == LimitX-1) {
                printf("*");
            }
            else if (j == 0 || j == LimitY-1) {
                printf("*");
            }
            else printf(" ");
        }
        printf("\n");
    }
}

void printText(int LimitX,int LimitY, char lines[LimitX-1][LimitY-1],int posX, int posY) {
    for (int i=0;i < LimitX-1;i++) {
        for (int j=0;j < LimitY-1;j++) {
            gotoxy(j+1,i+1);
            if (i == posX && j == posY) {
                SetColor(RED);
            }
            else {
                SetColor(WHITE);
            }
            printf("%c", lines[i][j]);
        }
    }
}

void printStatus(int posX, int posY) {
    gotoxy(0,20);
    printf("PosX = %d, PosY = %d", posX, posY);
    gotoxy(0,0);
}

void pullbackText(int LimitX,int LimitY, char lines[LimitX-1][LimitY-1], int posX, int posY) {
    if (posX == 0) {
        for (int j=posY;j < LimitY-2;j++) {
            lines[posX][j-1] = lines[posX][j];
        }
    } else {
        for (int j=posY;j < LimitY-2;j++) {
            lines[posX][j] = lines[posX][j+1];
        }
    }

}



