#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int split(int arr[], int low, int high){
    int i, j, k, baseIndex = low, pivot = arr[low];

    for (i=low+1 ; i<=high ; i++){
        if (arr[i] <pivot){
            baseIndex ++;
            swap(&arr[baseIndex], &arr[i]);
        }
        for (j=low; j<=high; j++){
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
    
    swap(&arr[low], &arr[baseIndex]);

    for (k=low; k<=high; k++){
            printf("%d ", arr[k]);
        }
    printf("\n");
    printf("baseIndex_value:%d\n\n", arr[baseIndex]);

    return baseIndex;
}


void quickSort(int arr[], int low, int high){
    if (low < high){
        int baseIndex = split(arr, low , high);

        if(low < baseIndex-1){
            printf("spliting %d ~ %d\n", low, baseIndex-1);
            quickSort(arr, low, baseIndex-1);
        }

        if(baseIndex+1 < high){
            printf("spliting %d ~ %d\n", baseIndex+1, high);
            quickSort(arr, baseIndex+1, high);
        }
    }
}

int main(void){
    int k;
    int arr[] = {5, 8, 3, 1, 2, 0, 10, 12, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);

    printf("final sorted array: ");
    for (k=0; k<n; k++){
            printf("%d ", arr[k]);
        }
    printf("\n");
}