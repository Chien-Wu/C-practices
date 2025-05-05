#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_dupe(char *s);
char **string_set_dupe(char **S);

int main(void){

    char s[] = "abc";
    char *copy = string_dupe(s);
    printf("%s\n", copy);
    free(copy);

    char *original[] = {"apple", "banana", "cherry", NULL};
    char **copy2 = string_set_dupe(original);

    for(int i = 0; copy2[i] != NULL; i++){
        printf("%s\n", copy2[i]);
        free(copy2[i]);
    }
    free(copy2);
    return 0;
}

char *string_dupe(char *s){
    size_t len = strlen(s) + 1;
    char *copy = malloc(len);
    strcpy(copy, s);
    return copy;
}

char **string_set_dupe(char **S){
    int count;
    while (S[count] != NULL){
        count++;
    }

    char **dup = malloc((count+1) * sizeof(char *));

    for (int j = 0; j < count; j++){
        dup[j] = string_dupe(S[j]);
    }

    dup[count] = NULL;
    return dup;
}