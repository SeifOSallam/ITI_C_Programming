#ifndef LINEEDITOR_H_INCLUDED
#define LINEEDITOR_H_INCLUDED

void runEditor();
void printOuterBox(int LimitX,int LimitY);
void printText(int LimitX,int LimitY, char lines[LimitX-1][LimitY-1], int posX, int posY);
void printStatus(int posX, int posY);
#endif // LINEEDITOR_H_INCLUDED
