#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    double sum = 0;
    int i;
    for(i=1; i< argc; ++i){
	sum += atof(argv[i]);
    }

    printf("%f\n", sum);
}
