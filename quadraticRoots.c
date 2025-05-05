#include <stdio.h>
#include <math.h>

int main(void){
    double a, b, c, d, sol1, sol2;
    int count;

    printf("Enter a b c: ");
    count = scanf("%lf %lf %lf", &a, &b, &c);
    if (count != 3) {
        printf("Error in input\n");
        return 1;
    }
    printf("Equation %.1lfx^2 + %.1lfx + %.1lf = 0 has\n    ", a, b, c);

    d = b*b -4*a*c;
    if (a==0 && b==0 && c==0){
        printf("an infinite number of roots\n");
    } else if (a==0 && b==0){
        printf("no real roots\n");
    } else if (a==0){
        sol1 = -c / b;
        printf("one real root: x = %.1lf\n", sol1);
    } else if (d > 0){
        sol1 = (-b + sqrt(d))/ (2 * a);
        sol2 = (-b - sqrt(d))/ (2 * a);
        printf("two real roots: x1 = %.1lf, x2 = %.1lf\n", sol1, sol2);
    } else if (d == 0){
        sol1 = -b / (2 * a);
        printf("one real root: x = %.1lf\n", sol1);
    } else if (d < 0){
        printf("no real roots\n");
    }  
}