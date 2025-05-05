#include <stdio.h>

int main (){
    int a, b;
    printf("enter num1: ");
    scanf("%d", &a);
    printf("enter num2: ");
    scanf("%d", &b);

    if (a == b)
        printf("EQUAL\n");
    else
        printf("NOT EQUAL\n");
    return 0;
}