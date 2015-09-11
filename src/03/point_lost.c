#include <stdio.h>
#include <stdlib.h>

void foo(void **pX){
    int x=1;
    *pX = &x;
    printf("In foo function: %d\n", *(int*)pX);
}

void fooMolloc(int **pX){
    int *pInt; 
    pInt = malloc(sizeof(int));
    *pInt = 1;
    *pX = pInt;
    printf("In foo function: %d\n", *(int*)pX);
}

int main(){

    int *px;

    fooMolloc(&px);
    printf("In main function: %d\n", *px);

    foo(&px);
    printf("In main function: %d\n", *px);
}
