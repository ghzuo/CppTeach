#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strAssign(char** dest, char* src){
    *dest = malloc(strlen(src)+1);
    strcpy(*dest, src);
}

void streq(char** s){
    char ptr[] = "looooooooooooooooong";
    strAssign(s, ptr);
}

int main(){
    char* str;
    streq(&str);
    printf("%s\n", str);
}
