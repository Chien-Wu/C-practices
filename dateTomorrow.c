#include <stdio.h>

int main (void){
    int d, m, y;
    int daysInMonth;
    printf("Enter a date in dd/mm/yyyy format: ");
    scanf("%d/%d/%d", &d, &m, &y);
    printf("The date today is: %02d/%02d/%02d\n", d, m, y);

    switch (m)
    {
    case 2:
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)){
            daysInMonth = 29;
        }else{
            daysInMonth = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        daysInMonth = 30;
        break;
    default:
        daysInMonth = 31;
        break;
    }

    d++;
    if(d > daysInMonth){
        d = 1;
        m++;
        if (m > 12){
            m = 1;
            y ++;
        }
    }

    printf("The date tomorrow is: %02d/%02d/%02d\n", d, m, y);
    return 0;
}