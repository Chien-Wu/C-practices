#include <stdio.h>

#define MAXVALS 1000

int read_int_array(int A[]);
int kth_smallest(int A[], int n, int k);

int main(void){
    int numbers[MAXVALS];
    printf("enter as many as %d value: ", MAXVALS);
    int valid = read_int_array(numbers);

    for (int k = 0; k < valid; k++) {
        printf("The %d'th smallest is %d\n", k,
               kth_smallest(numbers, valid, k));
    }
}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int split(int arr[], int lo, int hi){
    int base = arr[lo];
    int split_index = lo;

    for (int i = lo+1; i <= hi; i++){
        if (arr[i] < base){
            split_index ++;
            swap(&arr[i], &arr[split_index]);
        }
    }

    swap(&arr[lo], &arr[split_index]);
    return split_index;
}


int kth_smallest(int A[], int n, int k){

    //copy the array so old one is not modified
    int copy[n];
    for (int i = 0; i < n; i++){
        copy[i] = A[i];
    }


    int lo = 0, hi = n-1;
    while(hi >= lo){
        int p = split(copy, lo, hi);
        if (p > k){
            hi = p - 1;
        } else if (p < k){
            lo = p + 1;
        }

        printf("p=%d, lo=%d, hi=%d\n", p, lo, hi);
        if(p == k){
            return copy[k];
        }
    }
    return -1;
}


int read_int_array(int A[]){
    int n = 0, next;
    while (scanf("%d", &next) == 1)
    {
        if (n == MAXVALS){
            break;
        }
        A[n] = next;
        n += 1;
    }
    return n;
}