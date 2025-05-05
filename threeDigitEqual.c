#include <stdio.h>

int main (){
    int num, hundreds, tens, units;
    printf("Enter a 3-digit number: ");
    scanf("%d", &num);

    hundreds = num / 100;
    tens = (num % 100) / 10;
    units = (num % 10);

    if (hundreds < tens && tens < units)
        printf("ASCENDING\n");
    else
        printf("NOT ASCENDING\n");
    
    return 0;
}