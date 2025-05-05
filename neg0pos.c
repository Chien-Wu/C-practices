# include <stdio.h>

int main (){
    int num;
    printf("enter an integer: ");
    scanf("%d", &num);
    if (num == 0)
        printf("0\n");
    else if (num < 0)
        printf("-1\n");
    else if (num > 0)
        printf("1\n");
    else
        printf("please enter an interger!!\n");

    return 0;
}