#include <stdio.h>

int median_3_ints(int n1, int n2, int n3){
    int max = n1, min = n1;

    if (n2>max){
        max = n2;
    } else if (n2<min){
        min = n2;
    }

    if (n3>max){
        max = n3;
    } else if (n3<min){
        min = n3;
    }

    return (n1+n2+n3-min-max);
}


int main(void){
    int n1,n2,n3,median;
    printf("Enter three integers: ");
    scanf("%d%d%d", &n1, &n2, &n3);
    median = median_3_ints(n1, n2, n3);
    printf("median_3_ints(%d, %d, %d) = %d\n", n1, n2, n3, median);
}