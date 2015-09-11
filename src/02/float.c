#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    int m = atoi(argv[1]);
    
    int n  = 16777215;
    float f  = 1.0/(float)n;

    int i;
    float sum = 0;
    for(i=0; i<m*n; ++i)
        sum += f;
    
    printf("%g\n", sum);
}
