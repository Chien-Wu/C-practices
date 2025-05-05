#include <stdio.h>

#define MAXVALS 1000

int num_inversions(int[], int);

int main(void){
    int n;
    int nums[MAXVALS];
    int count;


    printf("Enter as many as 1000 values, ^D to end\n");
    for (count = 0; count < MAXVALS && scanf("%d", &n) != EOF; count++){
        nums[count] = n;
    }

    printf("%d values read into array\n", count);


    printf("Array: ");
    for (int i = 0; i < count; i++){
        printf("%4d", nums[i]);
    }
    printf("\n");


    int inversion_count = num_inversions(nums, count);
    printf("There are %d inversions\n", inversion_count);
}

int num_inversions(int nums[], int n){
    int inversion_count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if (nums[j] > nums[i]){
                inversion_count ++;
            }
        }
    }
    return inversion_count;
}