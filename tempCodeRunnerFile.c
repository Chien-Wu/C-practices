long long findMaximumScore(int* nums, int numsSize) {
    int curr = 0;
    int tot = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] > nums[curr]){
            tot += (i-curr)*nums[curr];
            curr = i;
            continue;
        }
        if (i = numsSize-1){
            tot += (i-curr)*nums[curr];
        }
    }
    
    return tot;
}