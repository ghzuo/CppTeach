#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    int n = 1024*1024*2;
    int m = atoi(argv[1])*n;
    float f  = 1.0/(float)n;

    int i;
    float sum = 0;
    for(i=0; i<m; ++i)
        sum += f;
    
    printf("The sum of %i %g is %g\n", m, f, sum);
}
