# include <stdio.h>

int main(){
    int year, month, day;
    printf("enter year: ");
    scanf("%d", &year);
    printf("enter month: ");
    scanf("%d", &month);
    printf("enter day: ");
    scanf("%d", &day);

    printf("%X / %X / %X\n", day, month, year);
    return 0;
}