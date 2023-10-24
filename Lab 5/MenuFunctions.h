#ifndef MENUFUNCTIONS_H_INCLUDED
#define MENUFUNCTIONS_H_INCLUDED

struct student {
    char name[100];
    int ID;
};


void SetColor(int ForgC);
void gotoxy(int x,int y);
void runMenu();
void displayMainMenu();
int checkInput(char c, int* position, struct student studentsList[], int* actualSize);
void handleNewSubMenu(struct student studentsList[], int* actualSize);
void handleDisplaySubMenu(struct student studentsList[], int* actualSize);
int handleExitSubMenu();

#endif // MENUFUNCTIONS_H_INCLUDED
