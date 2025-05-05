/* Exercise 7.12: Determine if a string is a palindrome
 * Scaffold by Alistair Moffat, October 2013.
 * (c) University of Melbourne */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 100

/* function prototypes */

int is_palindrome(char s[]);
int read_line(char str[], int max);

/* scaffolding to test the required function */
int
main(int argc, char *argv[]) {
    char str[MAXSTR];
    printf("Enter strings, one per line:\n");
    while (read_line(str, MAXSTR) == 1) {
        printf("The string \"%s\" is ", str);
        if (!is_palindrome(str)) {
            printf("**not** ");
        }
        printf("a palindrome\n");
    }
    return 0;
}

// TODO: implement is_palindrome
int is_palindrome(char s[]){
    int l = strlen(s);
    for (int i = 0; i < l/2; i++){
        if (s[i] != s[l-i-1]){
            return 0;
        }
    }
    return 1;
}



/* *** Helper functions *** */

/* read one line of input into a string of maximum length.
 * returns 1 if there still is text to be read (no EOF sent), 0 otherwise */
int
read_line(char str[], int max) {
    int n = 0, c;
    while ((c = getchar()) != EOF && c != '\n') {
        str[n++] = c;
        if (n == max - 1) {
            str[n++] = '\0';
            return 1;
        }
    }
    if (c == EOF && n == 0) {
        return 0;
    }
    str[n++] = '\0';
    return 1;
}