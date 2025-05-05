#include <stdio.h>

int main (){
    int num, i=1;
    printf("enter width of the triangle: ");
    scanf("%d", &num);
    while (i <= num)
    {
        int j=1;
        while (j <= i)
        {
            printf("%d", j);
            j ++ ;
        }
        printf("\n");
        i ++ ;
    }
    return 0;
}