#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct string{
    char* pstr;
} String;

void strByCstr(String* str, char* v){
    if((*str).pstr != NULL)
        free((*str).pstr);
    (*str).pstr = malloc(strlen(v)+1);
    strcpy((*str).pstr, v);
}

void strByChar(String* str, char v){
    if((*str).pstr != NULL)
        free((*str).pstr);
    (*str).pstr = malloc(2);
    (*str).pstr[0] = v;
    (*str).pstr[1] = '\0';
}

void strByStr(String* str, String v){
    if((*str).pstr != NULL)
        free((*str).pstr);
    (*str).pstr = malloc(strlen(v.pstr)+1);
    strcpy((*str).pstr, v.pstr);
}

void streq(String* s){
    String ptr;
    strByCstr(&ptr, "XXXXX");
    strByStr(s, ptr);
}

int main(){
    String str;  // = between String will be very dangerous ...
    streq(&str);
    printf("%s\n", str.pstr);
}

