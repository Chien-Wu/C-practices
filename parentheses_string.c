// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool canBeValid(char* s, char* locked) {
    int n = strlen(s);
    if (n % 2) return false;

    int minOpen = 0, maxOpen = 0;
    for (int i = 0; i < n; i++) {
        if (locked[i] == '1') {
            if (s[i] == '(') {
                minOpen++;
                maxOpen++;
            } else {
                minOpen--;
                maxOpen--;
            }
        } else {
            minOpen--;
            maxOpen++;
        }

        if (maxOpen < 0) return false;
        if (minOpen < 0) minOpen = 0;
    }

    return (minOpen == 0);
}

int main(void){
    char s[]     = "))()))";
    char locked[] = "010100";
    printf("%d\n", (int)canBeValid(s, locked));
}