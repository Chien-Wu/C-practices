#include <stdio.h>
#include <stdlib.h>
#include "arrayops.h"  // includes read_int_array, print_int_array

/* maximum array size allowed */
#define MAXVALS 1000

/* function prototypes */
int most_frequent(int A[], int n);

int
main(int argc, char *argv[]) {
    /* get the input */
    int numbers[MAXVALS];
    int valid = read_int_array(numbers, MAXVALS);

    printf("Before: ");
    print_int_array(numbers, valid);

    /* call the function of interest */
    printf("The most frequent item is %d\n", most_frequent(numbers, valid));

    /* prove that we didn't modify numbers, as required */
    printf("After : ");
    print_int_array(numbers, valid);

    return 0;
}

int most_frequent(int A[], int n){
    return 0;
}