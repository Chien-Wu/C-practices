#include <stdio.h>

int main(){
    int num, hundreds, tens, units;
    printf("enter a 3 digit number: ");
    scanf("%d", &num);
    hundreds = num / 100;
    tens = (num / 10) % 10;
    units = num % 10;
    printf("%d%d%d\n", units, tens, hundreds);
    return 0;
}