/* Exercise 7.s4: Lexicographically Next Permutation
 * Scaffold by Alistair Moffat, October 2013.
 * (c) University of Melbourne */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 100

/* function prototypes */
void swap(char *s1, char *s2);
void next_perm(char *s);
int read_line(char str[], int max);

/* scaffolding to test the required function */
int
main(int argc, char *argv[]) {
    char s[MAXSTR];
    printf("Enter strings, one string per line:\n");
    while ((read_line(s, MAXSTR) == 1)) {
        printf("next_perm(\"%s\") = ", s);
        next_perm(s);
        printf("\"%s\"\n", s);
    }
    return 0;
}

/* generates the lexicographically next permutation of the 
   input string s, storing it in s */
void 
next_perm(char *s) {
    int max = strlen(s);
    int lo, hi;
    int have_next = 0;

    for(lo = max - 2; lo >= 0; lo--){
        if (s[lo] < s[lo+1]){
            have_next = 1;
            break;
        }
    }

    if (have_next == 0){
        return;
    }


    for(hi = max-1; hi > lo; hi--){
        if (s[hi] > s[lo]){
            break;
        }
    }

    swap(&s[lo], &s[hi]);

    for(int i = 1; i <= (max-lo)/2; i++){
        swap(&s[lo+i], &s[max-i]);
    }
}


void
swap(char *s1, char *s2){
    char temp = *s1;
    *s1 = *s2;
    *s2 = temp;
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