#include <stdio.h>

int main(){
    int x = 2147483647;
    int y = 1;
    int z = x+y;
    
    printf("%d\t%u\n", z, z);
    printf("%d\t%u\n", -1, -1);
}
