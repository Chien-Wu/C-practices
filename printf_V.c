#include <stdio.h>

void print_space(int n){
    for (int i=0; i<n;i++){
        printf(" ");
    }
}

int main (void){
    printf("Enter a positive odd number: ");
    int n;
    if (scanf("%d", &n) != 1 || n <= 0 || n%2 == 0){
        printf("Invalid Input");
        return 1;
    }

    for (int i=0; i<n; i++){
        print_space(i);
        printf("v");
        if(i==n-1) {
            printf("\n");
            break;
        }
        print_space(11-2*i);
        printf("v\n");
    }
    return 0;
}