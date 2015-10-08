#include <stdio.h>

main(){
    int x = 66;
    int *xp = &x;
    
    void* vp;
    vp = xp;
    char *c = (char*)vp;
    int i = 0;
    for(;i<20;++i)
	printf("%c\n", *(c+i));
}
