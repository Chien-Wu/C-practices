# include <stdio.h>

int main (){
    int max;
    printf("how many stars you want? ");
    scanf("%d", &max);
    while (max > 0)
    {
        printf("*\n");
        max --;
    }
    return 0;
}