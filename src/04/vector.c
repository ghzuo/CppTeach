#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NDIM 3

struct vector{
    float r[NDIM];
};

char* outVector(struct vector* a){
    int i;
    static char str[11*NDIM+1];
    strcpy(str, "");
    for (i=0; i<NDIM; ++i){
        char buffer[12];
        sprintf(buffer, " %10.3f", a->r[i]);
        strcat(str, buffer);            
    }
    return str;
}

void initVector(struct vector* a){
    int i;
    for(i=0; i<NDIM; ++i)
        a->r[i] = 0;
}

float moduleVector(struct vector* a){
    int i;
    float mm = 0;
    for(i=0; i<NDIM; ++i)
        mm += (a->r[i]*a->r[i]);
    return sqrt(mm);
}

void normalVector(struct vector* a){
    float m = moduleVector(a);
    int i;
    for(i=0; i<NDIM; ++i)
        a->r[i] /= m;
}


void randVector(struct vector* a){
    int i;
    for(i=0; i<NDIM; ++i)
        a->r[i] = (float)(rand()%10000);
    normalVector(a);
}

struct vector addVector(struct vector* a,
                        struct vector* b){
    int i;
    struct vector sum;
    for(i=0; i<NDIM; ++i)
        sum.r[i] = a->r[i] + b->r[i];
    return sum;
}

int main(){
    srand(time(NULL));
    
    struct vector v1={{1}};
    initVector(&v1);
    printf("%s\n", outVector(&v1));
        
    randVector(&v1);
    printf("%s\n", outVector(&v1));
    
    printf(" %10.3f\n", moduleVector(&v1));
    
    struct vector v2;
    randVector(&v2);
    printf("%s\n", outVector(&v2));
    
    struct vector v3 = addVector(&v1, &v2);
    printf("%s\n", outVector(&v3));    
}
