#include <stdio.h>
#include <stdlib.h>

int rot13(char n) {
    if (n >= 'A' && n <= 'Z')
        return 'A' + (n - 'A' + 13) % 26;
    if (n >= 'a' && n <= 'z')
        return 'a' + (n - 'a' + 13) % 26;
    return n;
}

/* Do not change this main function */
int main(void) {
    printf("Enter text to encrypt / decrypt (Ctrl-D to finish):\n");
    char n;
    while (scanf("%c", &n) != EOF) {
        char n2 = rot13(n);
        printf("%c", n2);
    }
    return 0;
}

