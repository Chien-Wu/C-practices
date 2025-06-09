#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool canConstruct(char* s, int k) {
    if (strlen(s) < k) return false;
    
    bool char_count_table[256] = {false};
    for (int i = 0; s[i] != '\0'; i++){
        char_count_table[(int)s[i]] = !char_count_table[(int)s[i]];
    }
    
    int odd_count = 0;
    for (int i = 0; i < 256; i++){
        odd_count += (int)char_count_table[i];
    }
    if (odd_count > k){ return false; }
}

int main(void){
    char * s = "leetcode";
    int k = 3;
    canConstruct(s, k);
}