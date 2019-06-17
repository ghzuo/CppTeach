#include <stdio.h>

void foo(int n, int (*x)[n]){
    printf("%d\n", x[1][1]);
}

int main(){
    int x[2][3]={{1,2,3},{4,5,6}};
    printf("%d\n", x[1][1]);
    printf("%p %p %p\n", &x, &(x[0]), &(x[0][0]));
    //printf("%d %d %d\n", x, x[0], x[0][0]);
    printf("%p %p %d\n", x, x[0], x[0][0]);
    foo(2, x);
}
