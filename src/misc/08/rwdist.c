#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include "randomWalk.h"

/* Usage ... */
void usage(char* program){
    fprintf(stderr, "\nProgram Usage:\n%s\n", program);
    fprintf(stderr, "     [ -t  100  ]       times to be run, default 1000\n");
    fprintf(stderr, "     [ -d  100  ]       target distance per run, default 100\n");
    fprintf(stderr, "     [ -n  10000000 ]   max steps per run, default 10000000\n");
    fprintf(stderr, "     [ -o output.txt ]  the output file, default: output.txt\n");
    fprintf(stderr, "     [ -h ]             display this information\n");
    fprintf(stderr, "\n");
    exit(1);
}


/* Main program */
int main(int argc, char *argv[]){

    int ntime  = 100;
    int nstep  = 1000000;
    float dist = 100.0;
    char* filename = "output.txt";

    /* Get the Argments */
    char ch;
    while (( ch = getopt(argc, argv, "t:d:n:o:h")) != -1){ 
	switch (ch){ 
	case 't': 
	    ntime = atoi(optarg); break; 
	case 'd': 
	    dist = atof(optarg); break;
	case 'n': 
	    nstep = atoi(optarg); break; 
	case 'o': 
	    filename = optarg; break; 
	case 'h':
	    usage(argv[0]);
	case '?': 
	    usage(argv[0]); 
	} 
    }
    
    /* run random wolk */
    int i;
    FILE* fp = fopen(filename, "w");
    for(i=0; i<ntime; ++i){
	Status st;
	init(&st);
	while(st.n < nstep && distance(&st)<dist)
	    step(&st);
	fprintf(fp, "%10d %10d\n", i, st.n);
	
    }
    fclose(fp);
}
