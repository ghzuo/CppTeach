#include <stdio.h>

void foo(double x){
    printf("This is a double number: %lf\n", x);
}

void foo(float x){
    printf("This is a float number: %f\n", x);
}

void foo(int x){
    printf("This is an int number: %d\n", x);
}

void foo(unsigned x){
    printf("This is an unsigned number: %d\n", x);
}


int main(){
    double   x=1.0;
    float    y=1.0;
    int      z=1;
    unsigned a=1;
    long     b=2;
    
    foo(x);
    foo(y);
    foo(z);
    foo(a);
    foo(b);
}
