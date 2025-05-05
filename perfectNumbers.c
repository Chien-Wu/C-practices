#include <stdio.h>

int isperfect(int n){
    int sum = 1;

    if (n==1){
        return 0;
    }
    
    for (int i=2; i*i<n; i++){
        if (n%i ==0){
            sum += i;
            sum += n/i;
        }
    }

    if (sum == n){
        return 1;
    }
    return 0;
}

int nextperfect(int n){
    while(1){
        if (isperfect(n)){
            return n;
        }
        n++;
    }
}

int main(void){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isperfect(n)){
        printf("%d is a perfect number\n", n);
    }else {
        printf("%d is not a perfect number\n", n);
    }

    int next_perfect = nextperfect(n+1);
    printf("The next perfect is %d\n", next_perfect);
}