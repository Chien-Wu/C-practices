//https:// leetcode.com/problems/find-minimum-time-to-reach-last-room-ii

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minTimeToReach(int** moveTime, int rows, int* moveTimeColSize) {
    int cols = *moveTimeColSize;
    int **shortTime = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        shortTime[i] = malloc(cols * sizeof(int));
    }
    shortTime[0][0] = 0;

    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            if (r == 0 && c == 0){
                continue;
            }
            int timeCost = ((r + c) % 2 == 0) ? 1 : 2;

            int top_time = (r > 0) ? shortTime[r-1][c] : INT_MAX;
            int left_time = (c > 0) ? shortTime[r][c-1] : INT_MAX;

            int out_time = (top_time > left_time) ? left_time : top_time;
            int own_time = moveTime[r][c];

            shortTime[r][c] = (out_time > own_time) ? out_time + timeCost : own_time + timeCost;
        }
    }
    return shortTime[rows-1][cols-1];
}

int main(void){
    int n = 2, m = 2;
    int **moveTime = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        moveTime[i] = malloc(m * sizeof(int));
    }
    moveTime[0][0] = 0; moveTime[0][1] = 4;
    moveTime[1][0] = 4; moveTime[1][1] = 4;

    printf("%d\n", minTimeToReach(moveTime, n, &m));

    for (int i = 0; i < n; i++) free(moveTime[i]);
    free(moveTime);
}
