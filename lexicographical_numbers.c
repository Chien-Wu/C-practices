#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int(const void *a, const void *b){
    const int ia = *(const int *)a;
    const int ib = *(const int *)b;

    char sa[32], sb[32];
    sprintf(sa, "%d", ia);
    sprintf(sb, "%d", ib);
    return strcmp(sa, sb);
}

int* lexicalOrder(int n, int* returnSize) {
    int * arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        arr[i] = i+1;
    }
    qsort(arr, n, sizeof(int), cmp_int);
    return arr;
}


int main(void){
    int n = 13;
    int arr_size = n*sizeof(int);
    int *arr = lexicalOrder(n, &arr_size);
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
}