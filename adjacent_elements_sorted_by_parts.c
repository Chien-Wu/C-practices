// Write a Recursive Function that:
//     - Recieve an Array and its Size
//     - Returns "1" if:
//          - for two Adjacent elements in the 
//            the "Interger part" is sorted in Ascending order,
//            and the "fractional part" is sorted in Descending order.
//     - Returns "0" otherwise.

#include <stdio.h>
#include <math.h>

int adjacent_part_sorted(double arr[], int n){
    if (n == 1) return 1;

    if (!adjacent_part_sorted(arr + 1, n - 1))
        return 0;
        
    int prev_sorted = adjacent_part_sorted(arr+1, n-1);

    int float_sorted = arr[0] - floor(arr[0]) > arr[1] - floor(arr[1]);
    int int_sorted = floor(arr[1]) > floor(arr[0]);

    int curr_sorted = int_sorted && float_sorted;

    return prev_sorted && curr_sorted;
}

int main(void){
    double arr[] = {1.8, 3.7, 5.6, 7.5};
    int n = sizeof(arr) / sizeof(double);
    printf("%d\n", adjacent_part_sorted(arr, n));
}

