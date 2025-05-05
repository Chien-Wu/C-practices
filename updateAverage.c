#include <stdio.h>

void updateAverage(int a, int b, double * avg){
    * avg = (a+b) / 2.0;
}

int main(void){
    int a, b;
    double avg;
    printf("enter two numbers: ");
    scanf("%d %d", &a, &b);
    updateAverage(a, b, &avg);
    printf("%lf\n", avg);
}