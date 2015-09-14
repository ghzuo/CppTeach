#include <stdio.h>

int main(){
    printf("Size of _Bool: %lu\n", sizeof(_Bool));
    printf("Size of char: %lu\n", sizeof(char));
    printf("Size of int: %lu\n", sizeof(int));
    printf("Size of long: %lu\n", sizeof(long));
    printf("Size of long long: %lu\n", sizeof(long long));
    printf("Size of __int128: %lu\n", sizeof(__int128));
    printf("Size of unsigned: %lu\n", sizeof(unsigned));
    printf("Size of unsigned long: %lu\n", sizeof(unsigned long));
    printf("Size of float: %lu\n", sizeof(float));
    printf("Size of double: %lu\n", sizeof(double));
    printf("Size of long double: %lu\n", sizeof(long double));

    int *pInt;
    long *pLong;
    enum string{x1, x2, x3, x4} eStr; 
    printf("Size of point to int: %lu\n", sizeof(pInt));
    printf("Size of point to long: %lu\n", sizeof(pLong));
    printf("Size of enum: %lu\n", sizeof(eStr));

    int aInt[10] = {1,2,3,4,5,6,7,8,9,10};
    int *pAInt = aInt;
    printf("Size of array: %lu\n", sizeof(aInt));
    printf("The number of 2nd is: %d\n", aInt[1]);
    printf("Size of point to array: %lu\n", sizeof(pAInt));
    printf("The number of 2nd is: %d\n", pAInt[1]);
}
