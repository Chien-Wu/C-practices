/* Exercise 8.05: Complex numbers
 * Scaffold: Quynh-Chi Nguyen, Alistair Moffat, May 2010
 * (c) University of Melbourne */

#include <stdio.h>

// TODO: Define complex_t type here.
typedef struct{
    double re;
    double im;
} complex_t;

complex_t complex_add(complex_t, complex_t);
complex_t complex_mpy(complex_t, complex_t);
complex_t read_complex();
void print_complex(complex_t);

/* simple scaffolding to test functions */
int
main (int argc, char *argv[]) {
	complex_t v1, v2;
    
    printf("Enter two complex numbers v1, v2: ");
    v1 = read_complex();
    v2 = read_complex();
    

    printf("v1 =                  ");
	print_complex(v1);
    printf("v2 =                  ");
	print_complex(v2);
    printf("complex_add(v1, v2) = ");
	print_complex(complex_add(v1, v2));
    printf("complex_mpy(v1, v2) = ");
	print_complex(complex_mpy(v1, v2));
	return 0;
}

complex_t
complex_add(complex_t v1, complex_t v2) {
    v1.re += v2.re;
    v1.im += v2.im;
    return v1;
}

complex_t
complex_mpy(complex_t v1, complex_t v2) {
    double a = v1.re;  // Save original real part of v1
    double b = v1.im;  // Save original imaginary part of v1

    complex_t result;
    result.re = a * v2.re - b * v2.im;  // (a+bi)*(c+di) -> real part: ac - bd
    result.im = a * v2.im + b * v2.re;  // imaginary part: ad + bc
    return result;
}

complex_t
read_complex() {
    double a, b;
    scanf("%lf+%lfi", &a, &b);
    complex_t apple = {a, b};
    return apple;
}

void
print_complex(complex_t v) {
    printf("%6.2lf + %6.2lfi\n", v.re, v.im);
}