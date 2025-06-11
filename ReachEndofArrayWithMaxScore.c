#include <stdio.h>

long long findMaximumScore(int* nums, int numsSize) {
    int curr = 0;
    long long tot = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] > nums[curr]){
            tot += (long long)(i-curr)*nums[curr];
            curr = i;
            continue;
        }
        if (i == numsSize-1){
            tot += (i-curr)*nums[curr];
        }
    }
    
    return tot;
}

int main(void){
    int nums[] = {1,3,1,5};
    int n = findMaximumScore(nums, sizeof(nums)/sizeof(int));
    printf("%d\n", n);
}