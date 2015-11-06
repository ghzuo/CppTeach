#include "randomWalk.h"
#define PI 3.1415926

Status::Status(){ // Initial the status by (0.0, 0.0, 0)
    x = 0.0; /* x-axis of the point */
    y = 0.0; /* y-axis of the point */
    n = 0; /* steps of the point */
};

/* one step */
void Status::step(){
    float deg = rand()*2*PI/(float)RAND_MAX; /* get the degree */
    ++n;
    x += cos(deg);
    y += sin(deg);
};

/* Output the present status */
void Status::output(FILE* fp){
    fprintf(fp, "%10d %13.2f %13.2f %13.2f\n", n, x, y, distance());
};

/* Get the distance for the start point */
float Status::distance(){
    return sqrt(x*x + y*y);
};

