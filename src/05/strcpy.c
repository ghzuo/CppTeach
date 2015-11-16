#include <string.h>
#include <stdio.h>

void cp(char** d){
	char* str = "XXXXX";
	*d = str;
	printf("%s\n", *d);
	str = "YYYY";
}

int main(){
	char* dest;
	cp(&dest);
	printf("%s\n", dest);
}
