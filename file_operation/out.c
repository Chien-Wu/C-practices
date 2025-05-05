#include <stdio.h>

int main(void) {
    // Print a message to standard output
    fprintf(stdout, "This is a standard output message.\n");
    
    // Print an error message to standard error
    fprintf(stderr, "This is an error message.\n");
    
    return 0;
}