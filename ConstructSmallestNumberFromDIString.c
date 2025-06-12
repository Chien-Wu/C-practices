#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* smallestNumber(char* pattern) {
    size_t n = strlen(pattern);
    size_t len = (n + 1);
    
    int arr[n+1];
    int cul_D = 1;
    for (int i = 0; i < n+1; i++){
        if (pattern[i] == 'D'){
            cul_D ++;
        }
        else {
            for (int j = 0; j < cul_D; j++){
                arr[i-j] = i+j-cul_D+2;
            }
            cul_D = 1;
        }
    }

    char *result = malloc(len + 1);
    if (!result) return NULL;
    for (size_t i = 0; i < len; i++) {
        result[i] = '0' + arr[i];
    }
    result[len] = '\0';

    return result;
}

int main(void){
    char * pattern = "IIIDIDDD";
    char *ans = smallestNumber(pattern);
    printf("%s\n", ans);
    free(ans);
}