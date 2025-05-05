#include <stdio.h>

int main(){
    char op;
    int a, b;

    printf("enter math operator: ");
    scanf("%c", &op);

    printf("enter num1: ");
    scanf("%d", &a);

    printf("enter num2: ");
    scanf("%d", &b);

    switch (op)
    {
    case '+':
        printf("%d\n", a + b);
        break;
    
    case '-':
        printf("%d\n", a - b);
        break;

    case '*':
        printf("%d\n", a*b);
        break;
    
    case '/':
        printf("%lf\n", a/(double)b);
        break;

    default:
        printf("wrong mathematical opertor\n");
        break;
    }
    return 0;

}