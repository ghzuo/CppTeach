#include <stdio.h>

int main(){
    int x[4][5];
    int i,j;
    
    for(i=0;i<4;++i){
	for(j=0;j<5;++j){
	    x[i][j] = i*5+j;
	    printf("%3d", x[i][j]);
	}
    }
    printf("\n");

    int *p = x[0];
    for(i=0;i<20;++i){
	printf("%3d", p[i]);
    }
    printf("\n");

    printf("%d\n", *x[0,1]);
}
