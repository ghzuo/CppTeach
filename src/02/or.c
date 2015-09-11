#include <stdio.h>

int main(){
    int google = 0;
    int baidu  = 0;

    if(google==1 || ++baidu==1)
	printf("%d %d \n", google, baidu);
    
    ++google;
    
    if(google==1 || ++baidu==1)
	printf("%d %d \n", google, baidu);    
}
