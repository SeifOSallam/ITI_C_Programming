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

void gotoxy(int x,int y)
{
    COORD coord={0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void runEditor() {
    int posX = 1, posY = 1;
    int boxLimitX = 20, boxLimitY = 50;
    char lines[boxLimitX-1][boxLimitY-1];
    for (int i=0;i<boxLimitX-1;i++) {
        for (int j=0;j<boxLimitY-1;j++) {
            lines[i][j] = 0;
        }
    }

    int positionFixerFlag=0;

    while(1) {

        system("cls");
        printStatus(posX, posY);
        printOuterBox(boxLimitX,boxLimitY);
        printText(boxLimitX, boxLimitY, lines);
        char c = getch();
        if (c != -32 && c != BACKSPACE) {
            pushText(boxLimitX-1, boxLimitY-1,lines,posX,posY);
            lines[posX-1][posY-1] = c;
            if (posY == boxLimitY-2) {
                posY = 1;
                posX++;
            }
            else posY++;
            positionFixerFlag=1;
        }
        else if (c == BACKSPACE) {
            if (posY != 1) {
                posY--;
            }
            pullbackText(boxLimitX-1, boxLimitY-1,lines,posX,posY);


            //lines[posX-1][posY-1] = '\0';

        }
        else {
            c = getch();
            switch(c) {
                case UP_KEY: {
                    if (posX == 1) {
                        posX = boxLimitX - 2;
                    }
                    else {
                        posX--;
                    }
                    if (positionFixerFlag) {
                        posY--;
                        positionFixerFlag=0;
                    }

                    break;
                }
                case DOWN_KEY: {
                    if (posX == boxLimitX - 2) {
                        posX = 1;
                    }
                    else {
                        posX++;
                    }
                    if (positionFixerFlag) {
                        posY--;
                        positionFixerFlag=0;
                    }
                    break;
                }
                case LEFT_KEY: {
                    if (posY == 1) {
                        posY = boxLimitY - 2;
                    }
                    else {
                        posY--;
                    }
                    break;
                }
                case RIGHT_KEY: {
                    if (posY == boxLimitY - 2) {
                        posY = 1;
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

void printText(int LimitX,int LimitY, char lines[LimitX-1][LimitY-1]) {
    for (int i=0;i < LimitX-1;i++) {
        for (int j=0;j < LimitY-1;j++) {
            gotoxy(j+1,i+1);
            printf("%c", lines[i][j]);
        }
    }
}

void printStatus(int posX, int posY) {
    gotoxy(0,20);
    printf("PosX = %d, PosY = %d", posX-1, posY-1);
    gotoxy(0,0);
}

void pullbackText(int LimitX,int LimitY, char lines[LimitX-1][LimitY-1], int posX, int posY) {
    for (int j=posY;j < LimitY-1;j++) {
        lines[0][j-1] = lines[0][j];
    }
}


void pushText(int LimitX,int LimitY, char lines[LimitX-1][LimitY-1], int posX, int posY) {
    for (int j=posY+1;j < LimitY-2;j++) {
        lines[0][j] = lines[0][j+1];
    }
}

