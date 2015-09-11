#include <stdio.h>

size_t foo(int xf[]){
    return sizeof(xf);
}

int main(){
    int x[10];
    printf("%lu %lu\n", sizeof(x), foo(x));
}
