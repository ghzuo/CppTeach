#include "rwtime.h"

int main(int argc, char *argv[]){
     
    srand(time(0));             /* set the random seed by time*/
    int ntime = 100;		/* default run times */
    int nstep = 1000000;	/* default step number per run  */
    const char* filename = "output.txt"; /* default output file */

    /* Get the Argments */
    char ch;
    while (( ch = getopt(argc, argv, "t:n:o:h")) != -1){ 
        switch (ch){
            case 't':
                ntime = atoi(optarg); break;
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
    /* Initial the total array */
    float dist[nstep];
    for(int i=0; i<nstep; ++i)
	dist[i] = 0;
	
    /* run the walking */
    for(int i=0; i<ntime; ++i){
        Status theOne;
        while(theOne.n < nstep){
            dist[theOne.n] += theOne.distance();
            theOne.step();
        }
    }

    /* output the result */
    FILE* fp = fopen(filename, "w");
    for(int i=0; i<nstep; ++i)
        fprintf(fp, "%10d %12.2f\n", i, dist[i]/(float)ntime);
    fclose(fp);
}

/* Usage ... */
void usage(char* program){
    fprintf(stderr, "\nProgram Usage:\n%s\n", program);
    fprintf(stderr, "     [ -t  100  ]       times to be run, default 1000\n");
    fprintf(stderr, "     [ -n  1000000 ]    number of steps per run, default 10000\n");
    fprintf(stderr, "     [ -o output.txt ]  the output file, default: output.txt\n");
    fprintf(stderr, "     [ -h ]             display this information\n");
    fprintf(stderr, "\n");
    exit(1);
}

