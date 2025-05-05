#include <stdio.h>

int main (void){
    printf("Enter tree rows: ");
    int n;
    if (scanf("%d", &n)!=1 || n%2 != 0 || n <= 0){
        printf("Input Invalid");
        return 0;
    }

    for (int i=1; i<=n; i++){
        if(i%2 == 1)
        {
            for (int j=0; j<i; j++) printf("*");
            printf("\n");
            continue;
        }

        if (i == 2){
            printf("I\n"); 
            continue;
        }

        printf("I");
        for (int j = 0; j < i-3; j++) printf(" ");
        printf("+\n");

    }

}