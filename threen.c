#include <stdio.h>
#include <stdlib.h>

#define PERLINE 8

void find_sequence(int n, int *cycles, int *peak) {
    int count = 0;
    int max = n;

    while (n != 1) {
        // calculate and print the next value
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }

        // is this the new maximum value?
        if (n > max) {
            max = n;
        }
        count += 1;
    }
    *cycles = count;
    *peak = max;
}

int main(void){
    int nmax;
    printf("Enter value for nmax: ");
    scanf("%d", &nmax);

    int cycles, peak;
    int longest_start=0, longest_cycles=0, longest_cycles_peak=0;
    
    for(int seed=1; seed <= nmax; seed++){
        find_sequence(seed, &cycles, &peak);

        if (cycles >= longest_cycles){
            longest_start = seed;
            longest_cycles = cycles;
            longest_cycles_peak = peak;
        }
    }

    printf("start =%8d, cycles =%6d, max =%11d\n", longest_start, longest_cycles, longest_cycles_peak);
}

