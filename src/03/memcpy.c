#include <stdio.h>
#include <string.h>

int main(){
    int x[] = {5,6,7,8};
    int i, y[]={0,1,2,3,4};

    memcpy(y,x,sizeof(y));
    for(i=0;i<5;++i)
	printf("%d\n", y[i]);
    
}
