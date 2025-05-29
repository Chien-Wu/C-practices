#include <stdio.h>
#include <math.h>

#define g 9.81
#define k 0.6
#define A 0.1
#define THRUST 500
#define DRY_MASS 10
#define INITIAL_FUEL 8
#define BURN_RATE 0.8

typedef struct{
    double t;
    double a;
    double v;
    double y;
} Record_t;

int main(void){

    double dt;
    printf("Enter deltat: ");
    scanf("%lf", &dt);

    double fuel = INITIAL_FUEL, mass, thrust;
    double t=0, v=0, a=0, y=0, y_max=0;
    Record_t record[40];

    int i =0;
    while(y > 0 || i==0){
        if (fuel > 0){
            mass = DRY_MASS + fuel;
            thrust = THRUST;

            fuel -= BURN_RATE * dt;
            if (fuel < 0) fuel = 0;

        } else {
            mass = DRY_MASS;
            thrust = 0;
        }

        double drag_mag = k * A * v * fabs(v);

        double F_d     = (v > 0 ?  -drag_mag : drag_mag);
        double F_g = - mass * g;
        double F_t = thrust;

        double F_net = F_t + F_g + F_d;

        a = F_net / mass;
        v += a * dt;
        y += v * dt;
        t += dt;

        if (y > y_max) y_max = y;
        if (y <= 0) break;

        record[i].a = a;
        record[i].t = t;
        record[i].v = v;
        record[i].y = y;

        printf("%.lf\n", record[i].y);
        i++;
    }
}