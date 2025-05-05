#include <stdio.h>

int main(void){
    int i;
    printf("           +0  +1  +2  +3  +4  +5  +6  +7\n");
    printf("        +--------------------------------");
    for(i=32;i<=126;i++){
        if(i%8==0){
            printf("\n%7d |", i);
        }
        printf("   %c", (char)i);
    }
    printf("\n");
}