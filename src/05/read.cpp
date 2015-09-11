#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ifstream fp("list.txt");
    for(string line; getline(fp, line); ){
        line = line.substr(0,line.find_first_of("#"));
        if( !line.empty())
            cout << line << endl;
    }
    fp.close();
}
