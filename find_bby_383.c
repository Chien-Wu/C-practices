#include <stdio.h>

void swap (char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int find_bby(char rooms[], int n){
    int ind_bby = -1, ind_383 = -1;
    for (int i = 0; i < n-2; i++){
        if (rooms[i] == 'b' && rooms[i+1] == 'b' && rooms[i+2] == 'y'){
            ind_bby = i;
        }
        if ((int)rooms[i] == 3 && (int)rooms[i+1] == 8 && (int)rooms[i+2] == 3){
            ind_383 = i;
        }
    }
    if (ind_bby == -1 || ind_383 == -1)return -1;

    for (int i = 0; i < 3; i++){
        swap (&rooms[ind_bby+i], &rooms[ind_383+i]);
    }
    return 1;
}


int main(void){
    char rooms[] = {'b', 'c', 3, 8, 3, 'l', 'b', 'b', 'y'};
    int n = 9;

    for (int i = 0; i < n; i++){
        printf("%d ", (int)rooms[i]);
    }
    printf("\n");

    int k = find_bby(rooms, 9);
    for (int i = 0; i < n; i++){
        printf("%d ", (int)rooms[i]);
    }
    printf("\n");

    printf("%d\n", k);
}