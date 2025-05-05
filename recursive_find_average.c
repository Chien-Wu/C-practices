#include <stdio.h>

double recursive_find_average(double arr[], int n){
    if(n==1) return arr[0];
    double prev_avg = recursive_find_average(arr + 1, n - 1);
    double new_avg = (1/(double)n) * arr[0] + ((n-1)/(double)n) * prev_avg;
    return new_avg;
}

int main(void){
    double arr[] = {1,2,3,4,7};
    int n = sizeof(arr) / sizeof(double);
    printf("average = %lf\n", recursive_find_average(arr, n));
}