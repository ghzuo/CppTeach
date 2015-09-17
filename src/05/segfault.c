#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* foo1(){
    int *x = NULL;
    printf("%i\n", *x);
    return x;
}

void foo2(){
    char *ptr = "test";
    strcpy(ptr, "TEST");
}

void foo3(){ 
    int *ptr = (int *)0; 
    *ptr = 100; 
}

void foo(){
    int *pB = foo1();
}

int main(){
    foo2();
}
