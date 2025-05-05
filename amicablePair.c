#include <stdio.h>


int amicable_pair(int n1, int n2);

int main(void){
    printf("Enter two integers: ");

    int n1, n2;
    scanf("%d%d", &n1, &n2);

    printf("%d and %d are ", n1, n2);

    if (amicable_pair(n1, n2) == 0){
        printf("not ");
    }
    
    printf("an amicable pair\n");
}

int amicable_pair(int n1, int n2){

    if (n1 == n2){
        return 0;
    }
    
    int sum1 = 1, sum2 = 1;

    for (int i = 2; i*i <= n1; i ++){
        if (i*i == n1){
            sum1 += i;
        }
        else if (n1%i == 0){
            sum1 += i;
            sum1 += n1/i;
        }
    }
    for (int i = 2; i*i < n2; i ++){
        if (i*i == n2){
            sum2 += i;
        }
        else if (n2%i == 0){
            sum2 += i;
            sum2 += n2/i;
        }
    }

    if(sum1==n2 && sum2==n1){
        return 1;
    }
    return 0;
}
