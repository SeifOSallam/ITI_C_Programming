#include <stdio.h>
#include <stdlib.h>

void method1(int* x, int* y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void method2(int* x, int* y) {
    if (*x == 0) {
        *x = *y;
        *y = 0;
        return;
    }
    else if (*y == 0) {
        *y = *x;
        *x = 0;
        return;
    }
    *x = *x * (*y);
    *y = *x / *y;
    *x = *x / *y;
}

void method3(int *x, int* y) {
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}
int main()
{
    int x, y;
    printf("Enter X : ");
    scanf("%d", &x);
    printf("Enter Y : ");
    scanf("%d", &y);

    method1(&x,&y);
    printf("Method 1 : X = %d, Y = %d\n", x,y);

    method2(&x, &y);
    printf("Method 2 : X = %d, Y = %d\n", x,y);

    method3(&x, &y);
    printf("Method 3 : X = %d, Y = %d\n", x,y);
}
