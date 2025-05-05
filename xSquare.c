#include <stdio.h>

int main() {
    double x, x2, x4, x6, x8;
    printf("enter x: ");
    scanf("%lf", &x);

    x2 = x * x;
    x4 = x2 * x2;
    x6 = x4 * x2;
    x8 = x6 * x2;

    printf("%lf, %lf, %lf, %lf, %lf\n", x, x2, x4, x6, x8);
    return 0;
}