#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct string{
    char* pstr;
} String;

void strByCstr(String* str, char* v){
    if((*str).pstr != NULL){
        free((*str).pstr);
        (*str).pstr = NULL;
    }
    
    (*str).pstr = (char*) malloc(strlen(v)+1);
    strcpy((*str).pstr, v);
}

void strByChar(String* str, char v){
    if((*str).pstr != NULL){
        free((*str).pstr);
        (*str).pstr = NULL;
    }
        
    (*str).pstr = (char*) malloc(2);
    (*str).pstr[0] = v;
    (*str).pstr[1] = '\0';
}

void strByStr(String* str, String v){
    if((*str).pstr != NULL){
        free((*str).pstr);
        (*str).pstr = NULL;
    }
    
    (*str).pstr = (char*) malloc(strlen(v.pstr)+1);
    strcpy((*str).pstr, v.pstr);
}

void streq(String* s){
    char v[] = "Very Very Very Loooooooooooooooooooooooog";
    String ptr = {NULL};
    strByCstr(s, v);
}

int main(){
    String str = {NULL};
    
    streq(&str);
    printf("%s\n", str.pstr);
}

// = between String will be very dangerous;
// Cann't free memory when delete string ...
