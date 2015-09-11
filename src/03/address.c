#include <stdio.h>

void foo(int* x){
    printf("\nIn the foo function:\n");
    printf("address of x: %p\n", &x);
    printf("address of x[0]: %p\n", &(x[0]));
}

int main(){
    int x[10];
    printf("\nIn the main function:\n");
    printf("address of x: %p\n", &x);
    printf("address of x[0]: %p\n", &(x[0]));
    foo(x);
}
