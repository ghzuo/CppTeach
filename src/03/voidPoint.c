#include <stdio.h>

int main(){
    void *pVoid;
    int *pInt;
    *pInt = 10;
    
    pVoid = pInt;
    printf("%d\n", *pVoid);
}
