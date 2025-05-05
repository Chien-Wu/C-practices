#include <stdio.h>
#include <ctype.h>
#include <string.h>


void swap(char *s1, char *s2){
    char temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int count_char_in_str(char *s, char n){
    int count = 0;
    for (int i=1; s[i] != ' '; i++){
        if(s[i] == n)count ++;
    }
    return count;
}

void str_tolower(char *s){
    for (int i = 0; s[i] != '\0'; i++){
        s[i] = tolower(s[i]);
    }
}


int is_anagram(char *s1, char *s2){
    str_tolower(s1);
    str_tolower(s2);
    for (int i=0; s1[i])
}


int main(void){
    //printf("%d", is_anagram("Algorithms", "Glamor Hits"))
    int count = count_char_in_str("hellpo", 'l');
    printf("%d", count);
}