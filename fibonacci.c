#include <stdio.h>
#define MAX 10000000

int main(void){
    int n1=1, n2=1, n3=2;
    while(n3 <= MAX){
        n3 = n1+n2;
        printf("%d,%d,%d\n", n1,n2,n3);
        n1=n2;
        n2=n3;
    }
}