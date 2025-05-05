#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void str_tolower(char *s){
    for (int i = 0; s[i] != '\0'; i++){
        s[i] = tolower(s[i]);
    }
}

int is_anagram(char *s1, char *s2){
    str_tolower(s1);
    str_tolower(s2);

    int freq[256]={0};

    for (int i = 0; s1[i] != '\0'; i++){
        if(isspace(s1[i])) continue;
        freq[(unsigned int)s1[i]] ++;
    }

    for (int i = 0; s2[i] != '\0'; i++){
        if(isspace(s2[i])) continue;
        freq[(unsigned int)s2[i]] --;
    }

    for (int i = 0; i<256; i++){
        if(freq[i]!= 0) return 0; 
    }

    return 1;
    
}

int main(void){
    char s1[] = "Programming is fun!";
    char s2[] = "prof margin musing";
    printf("%d\n", is_anagram(s1, s2));
}