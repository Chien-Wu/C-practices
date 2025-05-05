#include <stdio.h>
#include <math.h>

#define MAX_VERTICES 100

typedef struct
{
    double x;
    double y;
} point_t;


typedef struct{
    point_t pts[MAX_VERTICES];
    int n;
} poly_t;


double perimeter(poly_t P){
    double tot_len = 0;
    for (int i = 0; i < P.n; i++){

        int j = i+1;
        if(j == P.n) j=0;

        double dx = P.pts[j].x - P.pts[i].x;
        double dy = P.pts[j].y - P.pts[i].y;
        
        tot_len += sqrt(dx * dx + dy * dy);
    }
    return tot_len;
}

int main(void){
    poly_t P;
    P.n = 0;

    printf("Enter (3-100) points counter-clockwise:\n");
    while (P.n < MAX_VERTICES && scanf(" %lf , %lf", &(P.pts[P.n].x), &(P.pts[P.n].y)) == 2){
        P.n ++;
    }

    double lenth = perimeter(P);
    printf("Perimeter is %.4f\n", lenth);
    return 0;
}