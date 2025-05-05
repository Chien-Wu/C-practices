#include <stdio.h>

int is_in_uset(int uset[], int count, int n){
    for(int i=0; i<count; i++){
        if (uset[i] == n) return 1;
    }
    return 0;
}

int set_union(int set1[], int n, int set2[], int m, int uset[]){
    int count = 0;
    for(int i=0; i<n; i++){
        if (is_in_uset(uset, count, set1[i]) == 0){
            uset[count] = set1[i];
            count ++;
        }
    }
    for(int i=0; i<m; i++){
        if (is_in_uset(uset, count, set2[i]) == 0){
            uset[count] = set2[i];
            count ++;
        }
    }
    return count;
}

int main(void){
    int set1[] = {1, 3, 4, 2}, set2[] = {2, 1, 7, 8, 4}, n = 4, m = 5;
    int uset[1000];
    int count = set_union(set1, n, set2, m, uset);
    printf("%d\n", count);
}