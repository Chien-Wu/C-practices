#include <stdio.h>

int main(){
    double data, demi;
    printf("enter floating point number: ");
    scanf("%lf", &data);
    demi = data - (int)data;
    printf("%lf become %.2lf after removing denicals part", data, demi);
    return 0;
}