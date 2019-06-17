#include <stdio.h>
#define n 1000000

int main(){
    
    double x[n];

    int i;
    for(i=0;i<n;++i)
	x[i] = 1;
    printf("%f\n", x[n-1]);

    return 0;
}
