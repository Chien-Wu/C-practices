#include <stdio.h>


int getDayInMonth(int m, int y){
    int dayInMonth;
    switch (m)
    {
    case 2:
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)){
            dayInMonth = 29;
        }else{
            dayInMonth = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        dayInMonth = 30;
        break;
    default:
        dayInMonth = 31;
        break;
    }
    return dayInMonth;
}


int main(void){
    int d, m, y, i, dayInMonth;
    int totalDay = 0;
    printf("Enter date in dd/mm/yyyy format: ");
    scanf("%d/%d/%d", &d, &m, &y);
    for(i = 1; i < m; i++){
        dayInMonth = getDayInMonth(i, y);
        totalDay += dayInMonth;
    }
    totalDay += d;
    printf("%02d/%02d/%02d is day number %d in the year\n", d,m,y,totalDay);
    return 0;
}

