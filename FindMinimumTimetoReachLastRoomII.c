//https:// leetcode.com/problems/find-minimum-time-to-reach-last-room-ii

#include <stdio.h>
#include <stdlib.h>

int max_num(int a, int b, int c){
    if (a>b) {
        if (a>c) return a;
        else return c;
    }
    else {
        if (b>c) return b;
        else return c;
    }
}

int minTimeToReach(int** moveTime, int rows, int* moveTimeColSize) {
    int cols = *moveTimeColSize;
    int **shortTime = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        shortTime[i] = malloc(cols * sizeof(int));
    }
    shortTime[0][0] = moveTime[0][0];

    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            int timeCost = (r+c) % 2 + 1;
            //shortTime[r][c] = max_num(move);
            shortTime[r][c] = timeCost;
        }
    }

    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            printf("%d ", shortTime[r][c]);
        }
        printf("\n");
    }
    
    return 0;
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
