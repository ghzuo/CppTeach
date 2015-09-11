#include <iostream>
#include <bitset>
using namespace std;

int main(){
    int  x = 2147483647;
    int  y = 1;
    int  z = x+y;
    
    cout << z << endl;

    bitset<32> bx(x), by(y), bz(z);
    cout << bx << "\n"
         << by << "\n"
         << bz << endl; 
}
