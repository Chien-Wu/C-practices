#include <stdio.h>

int main(void){
    int n = 1;
    float x = 123.45;
    char m[16] = "          hello";
    printf("n = %3d, x = %8.4f, m = \"%-15s\"\n", n, x, m);
}