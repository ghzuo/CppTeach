#include <stdio.h>

main(){
    char *cp = "BAA";
    unsigned  *dp = (unsigned*)cp;
    printf("%u\n", *dp);
    //printf("%s\n", *cp);
}
