#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

void runMagicBox();
void gotoxy(int x, int y);
void delay(int number_of_seconds);
void printArray(int arr[],int arrSize);

int main()
{
    runArrayTest();

    runMagicBox();
}

void runArrayTest() {
    int arrSize;
    printf("Enter the array's size\n");
    scanf("%d", &arrSize);
    if (arrSize <= 0) {
        printf("Array size must be positive");
        return 0;
    }
    int arr[arrSize];
    printf("Enter the elements\n");
    for (int i=0;i<arrSize;i++) {
        int k;
        scanf("%d", &k);
        arr[i] = k;
    }
    printArray(arr, arrSize);
    printMinMax(arr, arrSize);
}
void runMagicBox(){
    printf("===================\n");
    int inpSize;
    printf("Enter Magic Box Size: ");
    scanf("%d", &inpSize);
    if (inpSize <= 0) {
        printf("Please Enter a positive number.");
        return;
    }
    if (inpSize%2 == 0) {
        printf("%d is an even number, please enter an odd number (example: 3, 5, 7).", inpSize);
        return;
    }
    system("cls");
    int posX = 0, posY = 0;
    for (int i=1;i<=inpSize*inpSize;i++) {
        if (i == 1) {
            posX=0;
            posY=inpSize/2;
        }
        else if ((i-1)%inpSize == 0) {
            posX++;
            if (posX == inpSize) {
                posX = 0;
            }
        }
        else {
            posX--;
            posY--;
            if (posX == -1) {
                posX = inpSize-1;
            }
            if (posY == -1) {
                posY = inpSize-1;
            }
        }
        gotoxy((5*posY), (5*posX));
        printf("%d", i);
        delay(1);
    }
}

void printArray(int arr[], int arrSize) {
    for (int i=0;i<arrSize;i++) {
        printf("Element %d = %d \n", i, arr[i]);
    }
}
void printMinMax(int arr[], int arrSize) {
    int min = arr[0], max = arr[0];
    for (int i=0;i<arrSize;i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
}



void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}
