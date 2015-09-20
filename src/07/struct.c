#include <stdio.h>
#include <string.h>

struct Pad {
    long l;
    double d;
    char c[8];
};
        
int main(){
    struct Pad p;
    strcpy(p.c, "ddddddd");
    p.l = 10;
    p.d = 1000.0;
    printf("Double: %g\n", p.d);
    printf("Long Integer: %ld\n", p.l);
    printf("String: %s\n", p.c);
    printf("Hex Integer: %lx\n", p.l);
    
}
