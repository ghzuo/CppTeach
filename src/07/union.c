#include <stdio.h>
#include <string.h>

union Pad {
    long l;
    double d;
    char c[8];
};
        
int main(){
    union Pad p;
    p.l = 10;
    p.d = 1000.0;
    strcpy(p.c, "ddddddd");
    printf("Double: %f\n", p.d);
    printf("Long Integer: %ld\n", p.l);
    printf("String: %s\n", p.c);
}
