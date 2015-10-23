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
    printf("Case strcp: %s %s\n", pstr, astr);

    nstrcp(pstr);
    printf("Case nstrcp: %s %s\n", pstr, astr);
    
    lstrcp(pstr);
    printf("Case lstrcp: %s %s\n", pstr, astr);

    strcp(astr);
    printf("Case strcp astr %s %s\n", pstr, astr);
}

