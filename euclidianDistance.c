#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} vector_t;

double distance(vector_t p1, vector_t p2){
    double dx, dy;
    dx = p1.x - p2.x;
    dy = p1.y - p2.y;
    return(sqrt(dx*dx + dy*dy));
}

int main(void){
    printf("Enter two points: ");
    double x1, y1, x2, y2;
    scanf(" ( %lf , %lf ) ( %lf , %lf )", &x1, &y1, &x2, &y2);

    vector_t p1 = {x1, y1};
    vector_t p2 = {x2, y2};

    double dis = distance(p1, p2);
    printf("distance between (%.1f, %.1f) and (%.1f, %.1f) is %.1f\n", p1.x, p1.y, p2.x, p2.y, dis);
}