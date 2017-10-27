#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// the usage 
void usage(char* program){
    fprintf(stderr, "\nProgram Usage:\n%s\n", program);
    fprintf(stderr, "     [ -n  1000000 ]    number of steps per run, default 10000\n");
    fprintf(stderr, "     [ -o output.dat ]  the output file, default: output.dat\n");
    fprintf(stderr, "     [ -h ]             display this information\n");
    fprintf(stderr, "\n");
    exit(1);
}

// function to get system arguments from command line
void getMyArgs(int argc, char** argv, int* nstep, char** filename){
    char ch;
    while (( ch = getopt(argc, argv, "n:o:h")) != -1){
        switch (ch){
        case 'n':
            *nstep = atoi(optarg); break;
        case 'o':
            *filename = optarg; break;
        case 'h':
            usage(argv[0]);
        case '?':
            usage(argv[0]);
        }
    }    
}

// the main program
int main(int argc, char* argv[]){
    
        //for parameters
        int nstep  = 1000;
        char* filename = "output.dat";
        getMyArgs(argc, argv, &nstep, &filename);

        printf("%s\n", filename);
}