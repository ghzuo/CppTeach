#include <iostream>
using namespace std;

void fooRef(int& x){
    x += 1;
    cout << "In FooRef: " << x << endl;
}

void fooCopy(int x){
    x += 1;
    cout << "In FooCopy: " << x << endl;
}

void fooPoint(int* x){
    *x += 1;
    cout << "In FooPoint: " << *x << endl;    
}

int main(){
    int x = 10;

    fooCopy(x);
    cout << "In Main: "  << x << endl;
    fooPoint(&x);
    cout << "In Main: "  << x << endl;    
    fooRef(x);
    cout << "In Main: "  << x << endl;
}