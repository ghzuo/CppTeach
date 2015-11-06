#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include "randomWalk.h"

int main(){

    srand(time(0));
    Status theOne;
    while(theOne.distance() < 10){
        theOne.step();
        theOne.output(stdout);
    }
}

