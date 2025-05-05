#include <stdio.h>


int main(void){
    // char str[] = "hello";
    // printf("%c\n", *str);

    int * a = {1,2,3};
    int n = sizeof(a);
    printf("%d\n", n);

    int b = 8;
    printf("%lu\n", sizeof(b));
}