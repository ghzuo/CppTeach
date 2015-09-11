#include <stdio.h>

int main(){
    int x = 2147483647;
    int y = 1;
    int z = x+y;
    
    printf("%d %u\n", z, z);
    printf("%d %u\n", -1, -1);
}
