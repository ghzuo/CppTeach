#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

int main(){
    srand(time(0));
    for(int i=0; i<1000000; ++i){
	string str;
	for(int j=0; j<5; ++j){
	    int n=rand()%10;
	    char ch = (char) (n+65);
	    if(str.find(ch) == string::npos)
		str.push_back(ch);
	}
	cout << str << endl;
    }
}
