#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){

    srand(time(NULL));
    int i;
    for(i=0; i<10; ++i){
        int r = rand();
        printf("%d\n", r);
    }
}
