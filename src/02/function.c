#include <stdio.h>

void v(int x){
    x = x+10;
}

void p(int *x){
    *x = *x+10;
}

int main(){
    
    int a = 10;
    v(a);
    printf("by function v: %d\n", a);

    p(&a);
    printf("by function p: %d\n", a);
    
}
