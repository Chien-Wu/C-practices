# include <stdio.h>

int main (){
    long num, pow, result=1;
    printf("enter num: ");
    scanf("%ld", &num);
    printf("enter pow: ");
    scanf("%ld", &pow);

    while (pow > 0)
    {
        result = result * num;
        pow -- ;
    }

    printf("%ld\n", result);
    return 0;
}