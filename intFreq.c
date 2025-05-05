#include <stdio.h>

void swap(int *n1, int *n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int* partition(int *lo, int *hi){
    int *i = lo + 1;
    int pivot = *lo;
    for (int *j = lo+1; j <= hi; j++){
        if(*j < pivot){
            swap(i, j);
            i ++;
        }
    }
    swap(lo, i-1);
    return i-1;
}

void quicksort(int *lo, int *hi){
    if (lo < hi){
        int *i = partition(lo, hi);
        quicksort(lo, i-1);
        quicksort(i+1, hi);
    }
}

void sort_arr(int *p, int count){
    quicksort(p, p + count-1);
}

int count_freq(int *arr1, int *arr2, int *freq, int max){
    int i;
    int j=0;

    arr2[0] = arr1[0];
    freq[0] = 0;

    for(i=0; i<=max; i++){

        if(arr1[i] != arr2[j])
        {
            j++;
            arr2[j] = arr1[i];
            freq[j] = 1;
        }

        else{
            freq[j]++;
        }
    }
    return j;
}

int main(void){
    printf("Enter as many as 1000 values, ^D to end\n");
    int n, i = 0;
    int arr[1000];
    while(scanf("%d",&n) == 1 && i < 1000){
        arr[i] = n;
        i ++;
    }

    sort_arr(arr, i);

    int arr2[i];
    int freq[i];

    for (int k = 0; k<i; k++){
        freq[k] = 1;
    }
    printf("%d values read into array\n", i);

    int count = count_freq(arr, arr2, freq, i);

    printf("Value   Freq\n");
    for (int i = 0; i < count; i++){
        printf("%4d   ", arr2[i]);
        printf("%4d\n", freq[i]);
    }
}