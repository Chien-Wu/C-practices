#include <stdio.h>

int int_pow(int a, int b){
    int sol = 1;
    for(int i=0; i < b; i++){
        sol *= a;
    }
    return sol;
}

int main(){
    int a, b;
    printf("Enter the base and the exponent: ");
    scanf("%d%d", &a, &b);
    int sol = int_pow(a, b);
    printf("%d^%d = %d\n", a, b, sol);
}