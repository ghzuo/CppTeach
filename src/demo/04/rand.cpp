#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    srand(time(0));
    cout << rand() << endl;
}
