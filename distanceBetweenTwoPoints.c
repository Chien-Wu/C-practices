#include <stdio.h>
#include <math.h>

int main() {
    double x1, x2, y1, y2;
    double distance;

    printf("enter x1: ");
    scanf("%lf", &x1);

    printf("enter x2: ");
    scanf("%lf", &x2);

    printf("enter y1: ");
    scanf("%lf", &y1);

    printf("enter y2: ");
    scanf("%lf", &y2);

    distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));

    printf("the distance is %lf", distance);
    return 0;
}