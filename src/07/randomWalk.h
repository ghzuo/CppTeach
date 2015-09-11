#ifndef RANDOMWALK_H
#define RANDOMWALK_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

/* the data structure for the point */
typedef struct _Status{
    float x;
    float y;
    int n;
} Status;

/* Initial... */
void init(Status*);

/* One step forward */
void step(Status*);

/* Output the status to a file */
void output(Status*, FILE*);

/* output the distance from the zero point */
float distance(Status*);

#endif
