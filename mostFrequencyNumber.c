#include <stdio.h>

int most_frequent(int A[], int n){
    int max_freq=0, max_freq_index;
    int curr_freq = 1;
    for (int i = 0; i < n-1; i++){

        if (A[i+1] == A[i]){
            curr_freq+=1;
        }
        else {
            if (max_freq < curr_freq){
                max_freq = curr_freq;
                max_freq_index = i;
                curr_freq = 1;
            }
        }
    }
    return A[max_freq_index];
}


int main(void){
    int A[] = {1,1,1,1,1,2,2,3,3,3,4,4,4};
    printf("%d\n", A[most_frequent(A, sizeof(A)/sizeof(int))]);
}