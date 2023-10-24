#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Double: %lf \t Float: %f \t Char: %c\n==============\n", 3.14159265, 5.3, 'k');
    char c = 'a';
    printf("Char = %d\n==============\n",c);
    int x = 1 + 2;
    printf("Sum = %d\n==============\n", x);
    printf("Hexa of 63 is %x\n==============\n", 63);
    int y = 10, z = 5;
    printf("Sub of 10,5 :%d\n==============\n", y-z);
    printf("Mult of 10,5 :%d\n==============\n", y*z);
    printf("Div of 10,5 :%d\n==============\n", y/z);
    printf("Remainder of 10,5 :%d\n==============\n", y%z);
    if (x > y && x > z) {
        printf("X is the greatest integer with value of %d", x);
    }
    else if (y > x && y > z) {
        printf("Y is the greatest integer with value of %d", y);
    }
    else {
        printf("Z is the greatest integer with value of %d", z);
    }
}
