#include <stdio.h>
#include <stdlib.h>

void checkSign(int x);
void isEven(int x);
void largestNumber(int x, int y, int z);
int checkGrade(int x);
void runCalculator();

int main()
{
    int x;
    printf("Enter number: ");
    scanf("%d", &x);
    checkSign(x);
    isEven(x);
    printf("Enter Three Numbers:\n");
    int a,b,c;

    printf("First: \n");
    scanf("%d", &a);
    printf("Second: \n");
    scanf("%d", &b);
    printf("Third: \n");
    scanf("%d", &c);
    largestNumber(a, b, c);
    int grad;
    printf("Enter your grade: ");
    scanf("%d", &grad);
    int ans = checkGrade(grad);
    while (!ans) {
        printf("Enter your grade: ");
        scanf("%d", &grad);
        ans = checkGrade(grad);
    }
    runCalculator();
}


void checkSign(int x) {
    if (x > 0) {
        printf("Positive!\n");
    }else if (x < 0) {
        printf("Negative!\n");
    }
    else {
        printf("Zero!\n");
    }
}
void isEven(int x) {
    if (x%2 == 0) {
        printf("Number is Even \n");
    }
    else {
        printf("Number is Odd \n");
    }
}

void largestNumber(int x, int y, int z) {
    if (x > y && x > z) {
        printf("%d is the greatest integer\n", x);
    }
    else if (y > x && y > z) {
        printf("%d is the greatest integer\n", y);
    }
    else {
        printf("%d is the greatest integer\n", z);
    }
}

int checkGrade(int grad) {
    if (grad < 50 && grad >= 0) {
        printf("Failed..\n");
    }
    else if (grad >= 50 && grad < 65) {
        printf("Passed!\n");
    }
    else if (grad >= 65 && grad < 75) {
        printf("Good!\n");
    }
    else if (grad >= 75 && grad < 85) {
        printf("Very good!\n");
    }
    else if (grad >= 85 && grad <= 100) {
        printf("Excellent!\n");
    }
    else {
        printf("Please Enter a valid number between 0 and 100\n");
        return 0;
    }
    return 1;
}

void runCalculator() {
    char op;
    int frst,scnd;
    printf("Enter the operator: ");
    scanf(" %c", &op);
    while(op != '+' && op != '-' && op != '*' && op != '/' ) {
        printf("Please Enter a valid operator\n");
        scanf(" %c", &op);
    }
    printf("Enter the first number: ");
    scanf("%d", &frst);
    printf("Enter the second number: ");
    scanf("%d", &scnd);
    while(scnd == 0 && op == '/') {
        printf("The second number cannot be 0 in case of division, please try again.\n");
        scanf("%d", &scnd);
    }
    switch(op) {
    case '+':
        printf("Sum = %d",frst+scnd);
        break;
    case '-':
        printf("Sub = %d",frst-scnd);
        break;
    case '*':
        printf("Multiplication = %d",frst*scnd);
        break;
    case '/':
        printf("Division = %d",frst/scnd);
        break;
    default: break;
    }
}
