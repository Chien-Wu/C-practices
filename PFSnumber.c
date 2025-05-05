#include <stdio.h>

int prime_factor_sum(int n){
    int sum = 0;
    for (int i = 2; i <= n; i++){
        if (n%i == 0)
        {
            sum += i;
            while (n%i == 0){
                n = n/i;
            }
        }
    }
    return sum;
}

int is_n_a_k_PFS (int n, int k){
    int p = prime_factor_sum(n);
    if (p < k) return 1;
    return 0;
}

int previous_k_PFS(int n, int k){
    for (int i = n-1; i>0; i--){
        if(is_n_a_k_PFS(i, k) == 1) return i;
    }
    return 1;
}

int main(void){
    int n = previous_k_PFS(18, 8);
    printf("%d\n", n);
}