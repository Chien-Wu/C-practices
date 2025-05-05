#include <stdio.h>

int main(){
    int num1, num2;
    int max, min;
    printf("enter num1: ");
    scanf("%d", &num1);
    printf("enter num2: ");
    scanf("%d", &num2);

    if (num1 > num2)
    {
        max = num1;
        min = num2;
    }
        
    else
    {
        max = num2;
        min = num1;
    }
        
    printf("max is %d\nmin is %d\n", max, min);

    return 0;
}
