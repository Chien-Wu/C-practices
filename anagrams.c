/* Exercise 7.15: Determine if two strings are anagrams
 * Scaffold by Alistair Moffat, October 2013.
 * (c) University of Melbourne */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 100

/* function prototypes */

int is_anagram(char s1[], char s2[]);
int read_line(char str[], int max);

/* scaffolding to test the required function */
int
main(int argc, char *argv[]) {
    char s1[MAXSTR], s2[MAXSTR];
    printf("Enter two strings, one string per line:\n");
    while ((read_line(s1, MAXSTR) == 1) && (read_line(s2, MAXSTR) == 1)) {
        printf("The strings \"%s\" and \"%s\" are ", s1, s2);
        if (!is_anagram(s1, s2)) {
            printf("**not** ");
        }
        printf("anagrams\n");
    }
    return 0;
}

/* returns 1 if s1 and s2 are anagrams: strings with the same character
 * frequencies, in linear time and constant space */
int
is_anagram(char s1[], char s2[]) {
    // TODO: Implement this function.
    if (strlen(s1) != strlen(s2))
        return 0;
    
    int freq[256] = {0};

    for (int i=0; s1[i]!= '\0'; i++){
        freq[(unsigned int)s1[i]] ++;
        freq[(unsigned int)s2[i]] --;
    }

    for (int i=0; i<256; i++){
        if (freq[i] != 0){
            return 0;
        }
    }
    return 1;
}


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