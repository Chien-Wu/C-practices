#include <stdio.h>

int main() {
    int distance, speed, hours, mins;

    printf("enter the distance (km): ");
    scanf("%d", &distance);

    printf("enter the speed (km/h): ");
    scanf("%d", &speed);

    hours = distance / speed;
    mins = (distance % speed) * 60 / (double)speed;

    printf("it takes %d hours and %d minutes to drive", hours, mins);
    return 0;

}