#include <stdio.h>
#include <string.h>

#define MAXLEN 100
#define TOTAL_MAX 10000

int main(int argc, char * argv[]){
    char line[MAXLEN];
    char allInput[TOTAL_MAX];
    allInput[0] = '\0';

    while(fgets(line, MAXLEN, stdin) != NULL){
        printf("%s", line);
        strcat(allInput, line);
    }

    for (int i = 1; i < argc; i++){
        FILE *f = fopen(argv[i], "w");
        if (f == NULL) {
            fprintf(stderr, "Error: CANNOT OPEN %s\n", argv[i]);
            continue;
        }
        fputs(allInput, f);
        fclose(f);
    }
}