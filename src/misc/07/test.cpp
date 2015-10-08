#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include "randomWalk.h"

int main(){

    Status st;
    init(&st);
    srand(time(0));
    while(distance(&st) < 10){
	step(&st);
	output(&st, stdout);
    }
}
