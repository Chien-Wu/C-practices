#include <stdio.h>

#define PI 3.14159

int main() {
	double radius, volume;
	printf("Enter sphere radius: ");
	scanf("%lf", &radius);
	volume = (4.0*PI*radius*radius*radius)/3.0;
	printf("When radius is %.2f meters, ", radius);
	printf("volume is %.2f cubic meters\n", volume);
	return 0;
}