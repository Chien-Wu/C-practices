#include <stdio.h>

int main() {
    int totalSec, hour, min, sec;
    printf("enter second: ");
    scanf("%d", &totalSec);
    
    hour = totalSec / 3600;
    min = (totalSec % 3600) / 60;
    sec = totalSec % 60;

    printf("%d : %d : %d\n", hour, min, sec);
    return 0;
}