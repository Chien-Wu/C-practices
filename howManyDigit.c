#include <stdio.h>

int main(){
    int num;
    printf("enter num: ");
    scanf("%d", &num);
    if(num>9 && num<100)
    printf("2 digit\n");
    else if (num>99 && num < 1000)
    printf("3 digit\n");
    else
    printf("neither double/triple\n");
    return 0;
}