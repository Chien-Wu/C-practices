#include <stdio.h>
#include <ctype.h>

int main(void){
    printf("Enter text:\n");
    char c;
    int lines=0, words=0, chars=0;
    int inaword=0;
    while((c = getchar()) != EOF){

        if (c == '\n'){
            lines ++;
        }

        if (isalpha(c)){
            inaword = 1;
        } else if(inaword==1){
            words ++;
            inaword=0;
        }
        chars++;
    }
    printf("Lines:%8d\nWords:%8d\nChars:%8d\n", lines, words, chars);
}