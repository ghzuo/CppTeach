#include <stdio.h>
#include <string.h>

void strcp(char* s){
    char* ptr = "changed";
    strcpy(s, ptr);
}

void nstrcp(char* s){
    char* ptr = "veryVeryLongStringHaHaHa....";
    strncpy(s, ptr, strlen(s));
}

void lstrcp(char* s){
    char* ptr = "veryVeryLongStringHaHaHa....";
    strcpy(s, ptr);
}

int main(){
    char pstr[] = "pstrInitial";
    char *astr  = "astrInitial";
    
    strcp(pstr);
    printf("%s %s\n", pstr, astr);

    nstrcp(pstr);
    printf("%s %s\n", pstr, astr);
    
    lstrcp(pstr);
    printf("%s %s\n", pstr, astr);

    strcp(astr);
    printf("%s %s\n", pstr, astr);
}

