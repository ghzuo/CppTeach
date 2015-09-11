#include "randomWalk.h"
#define PI 3.1415926

/* Initial the status by (0.0, 0.0, 0) */
void init(Status* st){
    (*st).x = 0.0;  		/* x-axis of the point */
    (*st).y = 0.0;		/* y-axis of the point */
    (*st).n = 0;		/* steps of the point */
};

/* one step */
void step(Status* st){
    float deg = rand()*2*PI/(float)RAND_MAX; /* get the degree */
    ++(*st).n;
    (*st).x += cos(deg);
    (*st).y += sin(deg);
};

/* Output the present status */
void output(Status* st, FILE* fp){
    fprintf(fp, "%10d %13.2f %13.2f %13.2f\n", (*st).n, (*st).x, (*st).y, distance(st));
};

/* Get the distance for the start point */
float distance(Status* st){
    return sqrt((*st).x*(*st).x + (*st).y*(*st).y);
};
