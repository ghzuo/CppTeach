#ifndef RANDOMWALK_H
#define RANDOMWALK_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

/* the data structure for the point */
struct Status{
    float x;
    float y;
    int n;
    
    Status(); // constructor
    void step(); //One step forward
    void output(FILE*); // Output the status to a file 
    float distance(); // output the distance from the zero point 
};

#endif
