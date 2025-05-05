#include <stdio.h>

int main() {
    float a1, d, an, sn;
    int n;

    printf("enter a1: ");
    scanf("%f", &a1);

    printf("enter d: ");
    scanf("%f", &d);

    printf("enter n: ");
    scanf("%d", &n);

    an = a1 + (n-1)*d;

    sn = (a1 + an) * n /2;

    printf("sn = %f\n", sn);
    return 0;
}