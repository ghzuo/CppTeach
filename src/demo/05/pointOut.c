#include <stdio.h>
#include <stdlib.h> 
#define MAX_SIZE 10

int main(int argc, char* argv[]){
    int array[MAX_SIZE];
    int index;
    int limit = atoi(argv[1]);

    printf("Enter limit (integer: ) ");
    scanf("%d", &limit);

    for(index=0; index < limit; index++){
        array[index] = 0;
        printf("array[%d] is set to 0\n", index);
    }
}

