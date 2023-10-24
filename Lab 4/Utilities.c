#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include "Utilities.h"
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






void program_1() {
    int rows = 3, columns = 3;
    int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    for (int i=0;i<columns;i++) {
        int avg=0;
        for (int j=0;j<rows;j++) {
            avg+= matrix[i][j];
        }
        avg/=3;
        printf("Average of row %d = %d\n", i+1, avg);
    }
}

void program_2() {
    int matrix1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int matrix2[3][3] = {{7,8,9}, {6,5,4}, {2,1,3}};
    int resMatrix[3][3];
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            resMatrix[i][j] = matrix1[i][j]+matrix2[i][j];
        }
    }
    printf("Result Matrix: \n");
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            printf("%d \t", resMatrix[i][j]);
        }
        printf("\n");
    }
}

void program_3() {
    char str[100];
    char c;
    int ctr=0;
    do {
        printf("Enter char:");
        c = getch();
        if (c != 13 && c != -32) {
            printf("%c\n", c);
            str[ctr] = c;
            ctr++;
        }
        else if (c == -32) {
            printf("Enter a proper input. \n");
            getch();
        }
        else {
            str[ctr] = '\0';
            printf("%c\n", c);
        }

    }while(c != 13);

    printf("%s", str);
}

void program_4() {
    char c;
    c = getch();
    if (c == -32) {
        c = getch();
        printf("Extended key with value = %d", c);
    }
    else {
        printf("Normal key with value = %d", c);
    }
}

void program_5() {
    char firstName[100];
    printf("Enter first name: ");
    fgets(firstName, 100, stdin);
    char lastName[100];
    printf("Enter last name: ");
    fgets(lastName, 100, stdin);
    char fullName[200];
    int ctr=0;
    for (int i=0;firstName[i] != '\0';i++,ctr++) {
        fullName[ctr] = firstName[i];
    }

    for (int i=0;lastName[i] != '\0';i++,ctr++) {
        fullName[ctr] = lastName[i];
    }
    printf("Full name : %s", fullName);
}


void program_6() {
    int position = 0;

    do {
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
        char c;
        c = getch();
        if (c == -32) {
            c = getch();
            if (c == UP_KEY) {
                if (position == 0) {
                    position = 2;
                }
                else position--;
            }
            else if (c == DOWN_KEY) {
                if (position == 2) {
                    position = 0;
                }
                else position++;
            }

        }
        else if (c == 13) {
            SetColor(15);
            if (position == 0) {
                system("cls");
                gotoxy(10,7);
                printf("New");
                while (1) {
                    char inp;
                    inp = getch();
                    if (inp != '\0') break;
                }

            }
            else if (position == 1) {
                system("cls");
                gotoxy(10,7);
                printf("Display");
                while (1) {
                    char inp = getch();
                    if (inp != '\0') break;
                }
            }
            else {
                system("cls");
                gotoxy(10,7);
                printf("You sure? Y/N");
                char p = getch();
                if (p == 'y' || p == 'Y') {
                    break;
                }
                else {
                    printf("%c", p);
                }
            }
        }

    }while(1);

}


void program_7() {
    char str[100];
    printf("Enter String: ");
    fgets(str, 100, stdin);
    int alpha[26] = {0};
    for (int i=0;str[i] != '\0';i++) {
        if (str[i] >= 'a' && str[i] <='z') {
            alpha[str[i]-'a']++;
        }
        else if (str[i] >= 'A' && str[i] <='Z') {
            alpha[str[i]-'A']++;
        }
    }
    for (int i=0;i<26;i++) {
        if (alpha[i] != 0) {
            printf("%c : %d\n", i+'A', alpha[i]);
        }

    }
}
void program_8() {
    char str1[100];
    printf("Enter String: ");
    fgets(str1, 100, stdin);
    char str2[100];
    for (int i=0;str1[i] != '\0';i++) {
        str2[i] = str1[i];
    }
    printf("String 2 = %s", str2);
}

void program_9() {
    char str[100];
    printf("Enter String: ");
    fgets(str, 100, stdin);
    int len = 0;
    for (int i=0;str[i] != '\0';i++) {
        len++;
    }
    printf("String Length = %d", --len);
}

void program_10() {
    char str[100];
    printf("Enter String: ");
    fgets(str, 100, stdin);
    char resStr[100];
    int ctr=0;
    for (int i=0;str[i] != '\0';i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            resStr[ctr] = str[i];
            ctr++;
        }
    }
    resStr[ctr] = '\0';
    printf("Result = %s", resStr);
}

void program_11() {
    char str[100];
    printf("Enter String: ");
    fgets(str, 100, stdin);
    for (int i=0;str[i] != '\0';i++) {
        if ((str[i] >= 'a' && str[i] <= 'z')) {
            str[i]-=32;
        }
    }
    printf("Result = %s", str);
}
