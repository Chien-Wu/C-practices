#include<stdio.h>

int factorial(int a){
    int sol = 1;
    for(int i=1; i <= a; i++){
        sol *= i;
    }
    return sol;
}


int n_choose_k(int n, int k){
    return (factorial(n)/(factorial(n-k)*factorial(k)));
}


int main(void){
    int n, k, sol;
    printf("Enter n and k: ");
    scanf("%d%d", &n, &k);
    sol = n_choose_k(n, k);
    printf("%d choose %d = %d\n", n, k, sol);
}