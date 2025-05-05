#include <stdio.h>

int main() {
    float s, h;
    printf("enter salary per hour: ");
    scanf("%f", &s);
    printf("enter how many hours you work in a month: ");
    scanf("%f", &h);

    printf("your monthly salary is: %f\n", s*h);
    return 0;
}