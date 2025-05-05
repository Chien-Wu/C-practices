#include <stdio.h>

int main(void){
    printf("Enter text:\n");
    int c;
    int chars=0, lines=0;
    while((c = getchar()) != EOF){
        if (c=='\n'){
            lines ++;
        }
        chars++;
    }
    printf("Lines:%7d\n", lines);
    printf("Chars:%7d\n", chars);
}