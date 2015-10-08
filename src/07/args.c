#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

main(int argc, char *argv[]){
    int x;
    int y = 1;
    char *str="XXXX";

    char ch;
    while ((ch = getopt(argc, argv, "x:s:yh")) != -1){
      switch (ch){
      case 'x':
	  x = atoi(optarg); break;
      case 's': 
	  str = optarg; break;
      case 'y':
	  y = 3; break;
      case '?':
	  printf("Wrong input arguments!\n"); 
      }
    }

    printf("the x is: %d\n", x);
    printf("the y is: %d\n", y);
    printf("the str is: %s\n", str);
}
