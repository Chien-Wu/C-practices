#include <stdio.h>

#define MASK_TARGET 100

int mask_pair(int data[], int n){
    int i = 0, count = 0;
    while (i < n-1){
        if (data[i] + data[i+1] == MASK_TARGET){
            data[i] += MASK_TARGET;
            data[i+1] += MASK_TARGET;
            i++;
            count++;
        }
        i++;
    }
    return count;
}

int main(void){
    int data[] = {76, 37, 63, 15, 50, 50, 50, 6, 94, 40};
    int n = 10;
    int count = mask_pair(data, n);
    printf("%d\n", count);
}