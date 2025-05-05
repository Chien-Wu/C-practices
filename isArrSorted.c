#define IS_SORTED 1
#define NOT_SORTED 0

int is_sorted(int A[], int n);

// TODO: Implement is_sorted
int is_sorted(int A[], int n) {
    // 如果元素數量少於 2，視為已排序
    if (n < 2) return IS_SORTED;
    
    // 找到第一個不相等的相鄰對，確定排序方向
    int i = 0;
    while (i < n - 1 && A[i] == A[i+1])
        i++;
    
    // 如果整個序列都相等，也算排序
    if (i == n - 1)
        return IS_SORTED;
    
    int diff = A[i+1] - A[i];  // 決定排序方向
    // 根據 diff > 0 (升序) 或 diff < 0 (降序) 來檢查剩餘的相鄰對
    for (; i < n - 1; i++) {
        if (diff > 0 && A[i] > A[i+1])
            return NOT_SORTED;
        if (diff < 0 && A[i] < A[i+1])
            return NOT_SORTED;
    }
    
    return IS_SORTED;
}

/* Scaffold below, do not modify. */
#include <stdio.h>
#include "arrayops.h"

#define MAXVALS 1000

int
main(int argc, char *argv[]) {
    /* get the input */
    int numbers[MAXVALS], nnumbs;
    nnumbs = read_int_array(numbers, MAXVALS);
    
    print_int_array(numbers, nnumbs);
    if (is_sorted(numbers, nnumbs)) {
        printf("Array is sorted.\n");
    } else {
        printf("Array is not sorted.\n");
    }
    
    return 0;
}