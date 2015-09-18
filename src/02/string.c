#include <stdio.h>
// A string is an array end with 0

int main(){
    char str[] = "ABCDEFG";
    str[2] = 0;
    printf("%s\n", str);
    printf("%s\n", &str[3]);
}
