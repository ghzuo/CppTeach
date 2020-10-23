#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define PI 3.1415926

// the usage
void usage(char *program) {
  fprintf(stderr, "\nProgram Usage:\n%s\n", program);
  fprintf(stderr,
          "     [ -n  1000000 ]    number of steps per run, default 10000\n");
  fprintf(stderr,
          "     [ -o output.dat ]  the output file, default: output.dat\n");
  fprintf(stderr, "     [ -h ]             display this information\n");
  fprintf(stderr, "\n");
  exit(1);
}

// function to get system arguments from command line
void getMyArgs(int argc, char **argv, int *nstep, char *filename) {
  char ch;
  while ((ch = getopt(argc, argv, "n:o:h")) != -1) {
    switch (ch) {
    case 'n':
      *nstep = atoi(optarg);
      break;
    case 'o':
      filename = optarg;
      break;
    case 'h':
      usage(argv[0]);
    case '?':
      usage(argv[0]);
    }
  }
}

// function to get the distance from the start point
float dist(float *site) { return sqrt(site[0] * site[0] + site[1] * site[1]); }

// function to output the data
void output(FILE *fp, int istep, float *site) {
  fprintf(fp, "%10d %10.2f %10.2f %10.2f\n", istep, site[0], site[1],
          dist(site));
}

// function to get the step
void getStep(float *step) {
  /* get the degree */
  float deg = rand() * 2 * PI / (float)RAND_MAX;
  step[0] = sin(deg);
  step[1] = cos(deg);
}

// function run the step
void runStep(float *site, float *step) {
  site[0] += step[0];
  site[1] += step[1];
}

// the main program
int main(int argc, char *argv[]) {

  // for parameters
  int nstep = 1000;
  char *filename = "output.dat";
  getMyArgs(argc, argv, &nstep, filename);

  // the initial state
  float site[] = {0.0, 0.0};
  FILE *fp = fopen(filename, "w");
  output(fp, 0, site);

  // walking ....
  int i;
  for (i = 1; i < nstep; ++i) {
    float step[2];
    getStep(step);
    runStep(site, step);
    output(fp, i, site);
  }
  fclose(fp);
}
