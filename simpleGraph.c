#include <stdio.h>

int main() {
    int num;
    printf("Enter numbers: ");

    // 當 scanf 成功讀取到整數時回傳 1，遇到 EOF 則停止
    while (scanf("%d", &num) == 1) {
        int i;
        printf("%2d |", num);
        for(i=0; i<num; i++){
            printf("*");      
        }
        printf("\n"); 
    }
    
    return 0;
}