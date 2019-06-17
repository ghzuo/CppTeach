#include <stdio.h>
#include <stdlib.h>
typedef long Integer;

int main(int argc, char* argv[]){
    Integer n = atoi(argv[1]);
    Integer m = atoi(argv[2]);
    Integer s = atoi(argv[3]);

    printf("%d %d\n", n*m/s, m/s*n);
}
