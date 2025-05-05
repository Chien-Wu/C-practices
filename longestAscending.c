#include <stdio.h>

#define MAXVALS 1000

int longest_ascending_run(int A[], int n);


int
read_int_array(int A[], int maxvals) {
    int n = 0, excess = 0, next;

    printf("Enter as many as %d values, ^D to end\n", maxvals);
    while (scanf("%d", &next) == 1) {
        if (n == maxvals) {
            excess += 1;
        } else {
            A[n] = next;
            n += 1;
        }
    }

    printf("%d values read into array", n);
    if (excess) {
        printf(", %d excess values discarded", excess);
    }
    printf("\n");
    return n;
}


int main(int argc, char *argv[]){
    int numbers[MAXVALS], nnumbs;
    nnumbs = read_int_array(numbers, MAXVALS);
    int longest_run = longest_ascending_run(numbers, nnumbs);
    printf("Longest ascending run starts at index %d.\n", longest_run);

    return 0;
}

int longest_ascending_run(int A[], int n){
    int longest = 0, longest_index = 0, start = 0, end = 0;;
    for(int i=0; i<n-1; i++){

        if (A[i+1] >= A[i]){
            end = i+1;
        } else {
            start = i+1;
        }

        if(end-start > longest){
            longest = end-start;
            longest_index = start;
        }
    }
    return longest_index;
}