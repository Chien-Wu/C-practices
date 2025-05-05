#include <stdio.h>

int main(void){
    printf("Enter an integer greater than 3: ");
    int n = 0;
    if(scanf("%d", &n) != 1 || n < 3){
        printf("Invalid Input");
    }
    for (int i = 0; i < n; i++){
        printf("N");
        if (i==0 || i==n-1){
            for (int j=0; j < n-2; j++){
                printf(" ");
            }
        }
        else {
            for (int j = 0; j < i-1; j++){
                printf(" ");
            }
            printf("N");
            for (int j = 0; j < n-i-2; j++){
                printf(" ");
            }
        }
        printf("N\n");
    }
}