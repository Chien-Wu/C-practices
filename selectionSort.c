#include <stdio.h>
#include <limits.h>

void selectionSort(int arr[], int n){
    int i, j, k, minIndex, temp;
    for (i=0; i<n; i++){
        minIndex = i;
        for (j=i+1; j<n; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        for (k=0; k<n; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");

        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;  
    }
}
int main(void){
    int i;
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    printf("final: ");
    for (i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}