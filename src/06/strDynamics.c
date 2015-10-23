#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Defination of the string
typedef struct string{
    char* pstr;
} String;

// delete string
void strDelete(String* str){
    free((*str).pstr);
    (*str).pstr = NULL;
}

// Intial string
void strInitial(String* str){
    (*str).pstr = NULL;
}

// assign by c type string
void strByCstr(String* str, char* v){
    if((*str).pstr != NULL)
        strDelete(str);
    
    (*str).pstr = (char*) malloc(strlen(v)+1);
    strcpy((*str).pstr, v);
}

// assign by char
void strByChar(String* str, char v){
    if((*str).pstr != NULL)
        strDelete(str);
    
    (*str).pstr = (char*) malloc(2);
    (*str).pstr[0] = v;
    (*str).pstr[1] = '\0';
}

// assign by string
void strByStr(String* str, String v){
    if((*str).pstr != NULL)
        strDelete(str);

    (*str).pstr = (char*) malloc(strlen(v.pstr)+1);
    strcpy((*str).pstr, v.pstr);
}

void streq(String* s){
    char v[] = "Very Very Very Loooooooooooooooooooooooog";
    strByCstr(s, v);
}

int main(){
    String str;
    strInitial(&str);
    
    streq(&str);
    printf("%s\n", str.pstr);
}

// = between String will be very dangerous;
// Cann't free memory when delete string ...
