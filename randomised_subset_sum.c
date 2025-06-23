#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_sum_random_subset(int items[], int n, int count){
    int temp[n];
    for (int i = 0; i < n; i++) temp[i] = items[i];

    for (int i = 0; i < n; i++){
        int j = i + rand() % (n - i);
        swap(&temp[i], &temp[j]);
    }
    int sum = 0;
    for (int i = 0; i < count; i++){
        sum += temp[i];
    }
    return sum;
}

int randomised_subset_sum(int items[], int n, int k){
    srand(time(NULL));

    for (int i = 0; i < 10000; i++){
        int count = rand() % n + 1;
        int sum = find_sum_random_subset(items, n, count);
        if (sum == k){
            return 1;
        }
    }
    return 0;
}
