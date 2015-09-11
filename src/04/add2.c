#include <stdio.h>

int main(){

    double sum, data;
    while(scanf("%lf", &data)>0)
	sum += data;
    
    printf("%f\n", sum);
}
