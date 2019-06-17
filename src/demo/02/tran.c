#include <stdio.h>

int main(){
    int   i = 10;
    float f = 10.0;

    printf("%d\t%f\n", i, i);
    printf("%d\t%f\n", i, (float)i);
    printf("%f\t%d\n", f, f);
    printf("%f\t%d\n", f, (int)f);
}
