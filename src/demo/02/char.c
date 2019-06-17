#include <stdio.h>

int main(){
    char x = 'A';
    int  y = 30;
    char z = x+y;

    int a = 127;
    
    printf("%c %d %x\n", z,z,z);
    printf("%c %d %x\n", a,a,a);
}
