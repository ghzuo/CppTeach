#include <stdio.h>

int main(){
    
    int x = 3;
    int y = 4;
    int *p = &x;
    
    int i;
    for(i=0;i<5;++i){
	printf("%d %d\n", i, *p);
	++p;
    }
}
