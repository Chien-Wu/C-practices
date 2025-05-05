#include <stdlib.h>
#include <stdio.h>

int main(void) {
    while(1){
        int *p = malloc(1000);
        if (p == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            return 1;
        }
    }
    //void pointer (address)
}