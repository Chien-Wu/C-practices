#include <stdio.h>

int main() {
    int num1, num2, num3, max, min;
    printf("enter num1: ");
    scanf("%d", &num1);

    printf("enter num2: ");
    scanf("%d", &num2);

    printf("enter num3: ");
    scanf("%d", &num3);

    max = num1;
    min = num1;

    if (num2 > num1)
        {
            max = num2;
            min = num1;
        }
    else
        {
            max = num1;
            min = num2;
        }

    if (num3> max)
        {max = num3;}

    if (num3<min)
        {min = num3;}

    printf("mina is %d, max is %d\n", min, max);
    return 0;

}