#include <stdio.h>
#include <stdlib.h>
/* function prototypes */

void int_sort2(int *x1, int *x2){
    if (*x1 > *x2){
        int temp;
        temp = *x1;
        *x1 = *x2;
        *x2 = temp;
    }
}

/* scaffolding to test that function */
int
main(int argc, char *argv[]) {

    /* get two numbers */
    printf("Enter two integers: ");
    int v1, v2;
    if (scanf("%d%d", &v1, &v2) != 2) {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }

    /* test the function with the input */
    printf("Before: v1 = %d, v2 = %d\n", v1, v2);
    int_sort2(&v1, &v2);
    printf("After:  v1 = %d, v2 = %d\n", v1, v2);

    return 0;
}