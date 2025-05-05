#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORDS 10000
#define MAX_LINE_COUNT 100
#define MAX_CHAR_IN_LINE 100


int main(int argc, char *argv[]) {

    char **L = malloc(MAX_LINE_COUNT * sizeof(char *));
    if (L == NULL) {
        fprintf(stderr, "Memory allocation failed for L.\n");
        exit(1);
    }

    printf("Enter a line of text:\n");

    char line[MAX_CHAR_IN_LINE];

    int line_count;

    for (line_count = 0; fgets(line, sizeof(line), stdin) != NULL; line_count++){
        line[strcspn(line, "\n")] = '\0';
    }

    return 0;
}