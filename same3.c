# include <stdio.h>

int main(){
    int a, b, c;
    printf("enter num1: ");
    scanf("%d", &a);
    printf("enter num2: ");
    scanf("%d", &b);
    printf("enter num3: ");
    scanf("%d", &c);

    if (a== b && b == c)
        printf("EQUAL\n");
    else
        printf("NOT EQUAL\n");

    return 0;
}