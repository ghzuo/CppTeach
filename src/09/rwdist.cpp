#include "rwdist.h"

int main(int argc, char *argv[]){

    srand(time(0));         /* set the random seed by time*/
    int ntime  = 100;
    int nstep  = 1000000;
    float dist = 100.0;
    const char* filename = "output.txt";

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
    FILE* fp = fopen(filename, "w");
    for(int i=0; i<ntime; ++i){
        Status theOne;
        while(theOne.n < nstep && theOne.distance()<dist)
            theOne.step();
        fprintf(fp, "%10d %10d\n", i, theOne.n);
    }
    fclose(fp);
}

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




