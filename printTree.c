#include <stdio.h>
int
main(int argc, char *argv[]){
    int k;
    printf("How many layers tall will the Christmas tree be?\n");
    scanf("%d", &k);
    for(int i = 1; i < 2 * k; i++){
        for (int j = 0; j < i; j++){
            printf("**");
        }
        printf("\n");
    }
    printf("\n");
}