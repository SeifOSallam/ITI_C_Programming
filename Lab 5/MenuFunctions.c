#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include "MenuFunctions.h"
#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77



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

void runMenu() {
    int position = 0;
    char c;
    struct student studentsList[100];
    int actualSize=0;
    do {
        displayMainMenu(position);
        c = getch();

    }while(checkInput(c, &position, studentsList, &actualSize));

}


void displayMainMenu(int position) {
    system("cls");
    gotoxy(10,7);
    if (position == 0) {
        SetColor(4);
    }
    else {
        SetColor(15);
    }
    printf("New");

    gotoxy(10,14);
    if (position == 1) {
        SetColor(4);
    }
    else {
        SetColor(15);
    }
    printf("Display");

    gotoxy(10,21);
    if (position == 2) {
        SetColor(4);
    }
    else {
        SetColor(15);
    }
    printf("Exit");
}

int checkInput(char c, int* position, struct student studentsList[], int* actualSize) {
    if (c == -32) {
        c = getch();
        if (c == UP_KEY) {
            if (*position == 0) {
                *position = 2;
            }
            else (*position)--;
        }
        else if (c == DOWN_KEY) {
            if (*position == 2) {
                *position = 0;
            }
            else (*position)++;
        }
    }
    else if (c == 13) {
        SetColor(15);
        if (*position == 0) {
            handleNewSubMenu(studentsList, actualSize);
        }
        else if (*position == 1) {
            handleDisplaySubMenu(studentsList, actualSize);
        }
        else {
            return handleExitSubMenu();
        }
    }
    return 1;
}

void handleNewSubMenu(struct student studentsList[], int* actualSize) {
    system("cls");
    do {
        printf("Do you want to enter a student? (Y/N)\n");
        char c = getch();
        if (c == 'y' || c == 'Y') {
            //printf("Current Size = %d\n", *actualSize);
            fflush(stdin);
            printf("Student name: ");
            //scanf("%s", studentsList[(*actualSize)].name);
            fgets(studentsList[(*actualSize)].name, 100, stdin);
            //gets(studentsList[(*actualSize)].name);

            printf("Student ID: ");
            scanf("%d", &studentsList[(*actualSize)].ID);
            (*actualSize)++;
        }
        else {
            return;
        }
    }while(1);
}

void handleDisplaySubMenu(struct student studentsList[], int* actualSize) {
    system("cls");
    //gotoxy(10,7);
    for (int i=0;i<(*actualSize);i++) {
        printf("--------------Student %d--------------\n", i+1);
        printf("Name : %s\n", studentsList[i].name);
        printf("ID : %d\n\n", studentsList[i].ID);
        Sleep(500);
    }
    getch();
}

int handleExitSubMenu() {
    system("cls");
    gotoxy(10,7);
    printf("You sure? Y/N");
    char p = getch();
    if (p == 'y' || p == 'Y') {
        return 0;
    }
    else {
        return 1;
    }
}


