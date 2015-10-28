#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char* pStr = (char*) malloc(10);
    strcpy(pStr, "ABCDEFG");

    char* pStr2 = pStr;

    printf("%s %s\n", pStr, pStr2);

    //Note: The free object will not be deleted immadiately
    free(pStr);
    printf("%s %s\n", pStr, pStr2);
    
}
