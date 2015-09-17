#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char x = '0';
    int  y1 = x;
    int  y2 = atoi(&x);

    printf("===Transition from char to int===\n");
    printf("Transition directly: %d\n", y1);
    printf("Transition by atoi:  %d\n", y2);

    printf("\n===Transition from char array to int===\n");
    int i;
    char xx[10];
    for(int i=0; i<8; ++i){
        strcat(xx,"d");
        int  yy = *(int*)xx;
        printf("Transition: %8s %10d\n", xx, yy);
    }
    
}
