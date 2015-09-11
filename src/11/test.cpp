#include <istream>
#include "myVector.h"
using namespace std;

int main(){
    myVec v1(3, 1);
    myVec v2(3, 2);
    myVec v3 = v1 + v2;
    myVec v4 = 3.0*v3;

    cout << v3  << endl;
    cout << v4  << endl;

    return 0;
}
