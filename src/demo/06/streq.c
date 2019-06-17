#include <stdio.h>

void streq1(char* s){
    char* ptr = "changed";
    s = ptr;
}

void streq2(char** s){
    char ptr[] = "changed";
    *s = ptr;
}

void streq3(char** s){
    char* ptr = "changed";
    *s = ptr;
}

void streq4(char** s, char* str){
    *s = str;
}

int main(){
    char* str = "initial";

    streq1(str);
    printf("case 1: %s\n", str);

    streq2(&str);
    printf("case 2: %s\n", str);

    streq3(&str);
    printf("case 3: %s\n", str);

    char pstr[] = "changed";
    streq4(&str, pstr);
    printf("case 4: %s\n", str);
}
