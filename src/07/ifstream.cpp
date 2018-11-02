#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(){
    ifstream fp("test.txt");
    string str;
    while(fp >> str){
	cout << str << endl;
    }
}
