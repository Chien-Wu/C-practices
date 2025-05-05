#include <stdio.h>

int main() {
    int a = 3;
    int *p = &a;
    printf("a: %d\n", a);
    printf("*p: %d\n", *p);
    printf("p: %p\n", (void *)p);
    printf("&a: %p\n", (void *)&a);
    return 0;
}