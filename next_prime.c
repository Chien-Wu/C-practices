#include <stdio.h>

int is_prime(long n){

    if (n < 2){
        return 0;
    }

    for(int i=2; i*i <= n; i++){
        if(n%i==0){
            return 0;
        }
    }

    return 1;
}

int main(void){
    long n;
    printf("Enter an integer value: ");
    scanf("%ld", &n);

    n++;
    while(1){
        if(is_prime(n)){
            break;
        }
        n++;
    }
    printf("The next prime is     : %ld\n", n);
}