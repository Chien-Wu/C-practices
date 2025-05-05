#include <stdio.h>


int count_distinct(int A[], int n){
    int count = 0;

    for (int i = 0; i < n; i ++){
        count ++;
        for (int j = 0; j < i;j++){
            if (A[i] == A[j]){
                count --;
                break;
            }
        }
    }

    return count;
}

int main(void){
    int n = 7;
    int A[] = {1, 3, 5, 7, 3, 5, 6};
    printf("%d\n",count_distinct(A, n));

}