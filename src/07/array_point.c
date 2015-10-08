#include <stdio.h>

int main(){
    
    int x[]={1,2,3,4,5};
    int *p;
    int y[3]={1,2,3};
    
    p = x;
    int i;
    for(i=0;i<5;++i){
	printf("%d %d %d %d %d\n", i, y[i], p[i], i[p], *(p+i));
    }
}
