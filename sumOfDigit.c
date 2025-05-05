#include <stdio.h>

int main(){
    int num, hundreds, tens, units;
    printf("enter 3 digit number: ");
    scanf("%d", &num);
    hundreds = num / 100;
    tens = (num / 10) % 10;
    units = num % 10;
    printf("the sum is: %d\n", hundreds + tens + units);
    return 0;
}