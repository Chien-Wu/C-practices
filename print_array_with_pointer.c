#include <stdio.h>
void print_from_start(int arr[], int n);
void print_from_end(int arr[], int n);

int main(void){
    int arr[] = {1,2,3,4,5,6,7,9,11,13,15};
    int n = sizeof(arr) / sizeof(int);
    print_from_start(arr, n);
    print_from_end(arr, n);
}

void print_from_start(int *arr, int n){
    if (n <= 0) {
        printf("\n");
        return;
    }
    printf("%d ", arr[0]);
    print_from_start(arr + 1, n - 1);
}

void print_from_end(int *arr, int n){
    if (n <= 0){
        printf("\n");
        return;
    }

    printf("%d ", arr[n-1]);
    print_from_end(arr, n-1);
}