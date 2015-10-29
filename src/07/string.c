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
    char* pStrTemp = (char*) malloc(1);
    if(pStrTemp == NULL){
        printf("Alloc memory failure");
        exit(1);
    }else{
        pStrTemp[0] = '\0';
        (*str).pstr = pStrTemp;
    }
}

// assign by c type string
void strByCstr(String* str, char* v){
    char* pStrTemp = (char*)realloc((*str).pstr, strlen(v) + 1);
    if(pStrTemp == NULL){
        printf("Alloc memory failure");
        exit(1);
    }else{
        strcpy(pStrTemp, v);
        (*str).pstr = pStrTemp;
    }
}

// assign by char
void strByChar(String* str, char v){
    char s[2] = {v,'\0'};
    strByCstr(str, s);
}

// assign by string
void strEqual(String* str, String v){
    strByCstr(str, v.pstr);
}

int main(){
    String str;
    strInitial(&str); // must initial after declaration

    strByChar(&str, 'X');
    printf("%s\n", str.pstr); // assign by char
    
    char cstr[] = "C style string 1";
    strByCstr(&str, cstr);  // assign by c style string

    String str2;
    str2 = str;  // only the address are assigned
    printf("%s, %s\n", str.pstr, str2.pstr);

    char longStr[] = "Very Very Very Loooooooooog";
    strByCstr(&str, longStr); 
    printf("%s, %s\n", str.pstr, str2.pstr);
}


// = between String will be very dangerous;
// Cann't free memory when delete string ...
