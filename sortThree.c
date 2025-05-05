#include <stdio.h>

void swap(int *x1, int *x2){
    if (*x1 > *x2){
        int temp;
        temp = *x1;
        *x1 = *x2;
        *x2 = temp;
    }
}

void int_sort3(int *n1, int *n2, int *n3){
    swap(&*n1, &*n3);
    swap(&*n1, &*n2);
    swap(&*n2, &*n3);
}

int main(void){
    int n1, n2, n3;
    printf("Enter three integers: ");
    scanf("%d%d%d", &n1, &n2, &n3);
    printf("Before: v1 = %d, v2 = %d, v3 = %d\n", n1, n2, n3);
    int_sort3(&n1, &n2, &n3);
    printf("After: v1 = %d, v2 = %d, v3 = %d\n", n1, n2, n3);
}