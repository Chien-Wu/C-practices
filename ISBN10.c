#include <stdio.h>

int main(void) {
    printf("Enter ISBN: ");
    char ch; 
    int rest = 0, weight = 10;
    int validDigits = 0;

    while (weight >= 1 && scanf("%c", &ch) != EOF) {
        if (ch == '-' || ch == ' ' || ch == '\n')
            continue;
        
        int value;
        if (ch >= '0' && ch <= '9') {
            value = ch - '0';
        } else if (ch == 'X') {
            value = 10;
        } else {
            printf("INVALID :(\n");
            return 0;
        }
        rest += weight * value;
        weight--;
        validDigits++;
    }
    
    if (validDigits != 10 || weight != 0) {
        printf("INVALID :(\n");
    } else if (rest % 11 == 0) {
        printf("VALID :)\n");
    } else {
        printf("INVALID :(\n");
    }
    
    return 0;
}