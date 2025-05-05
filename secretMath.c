#include <stdio.h>


int is_n_s_n_of_k(int n, int k){
    if(n<=k) return 1;
    for (int i = 2;  ; i++){
        while(n%i == 0)n = n/i;
        if(n==1) return 1;
    }
    return 0;
}

int nth_s_n_of_k(int n, int k){
    int count = 0, try_num = 0;
    while(count < n){
        try_num++;
        count += is_n_s_n_of_k(try_num, k);
    }
    return try_num;
}


int main(void){
    int i = 5, j = 2, k1 = 3, k2 = 7;
    printf("%d\n", nth_s_n_of_k(i, k1));
    printf("%d\n", nth_s_n_of_k(j, k2));
}