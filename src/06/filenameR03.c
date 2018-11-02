#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
    char file[100];
    strcpy(file, *filename);
    while (( ch = getopt(argc, argv, "n:o:h")) != -1){
        switch (ch){
        case 'n':
            *nstep = atoi(optarg); break;
        case 'o':
            strcpy(file, optarg); break;
        case 'h':
            usage(argv[0]);
        case '?':
            usage(argv[0]);
        }
    }

    char buff[20];
    sprintf(buff, "%d", *nstep);
    strcat(file, buff);
    printf("In sub function: %s\n", file);
    strcpy(*filename, file);
}

// the main program
int main(int argc, char* argv[]){
    
        //for parameters
        int nstep  = 1000;
        char* filename = "output.dat";
        getMyArgs(argc, argv, &nstep, &filename);

        printf("Output Name: %s\n", filename);
}