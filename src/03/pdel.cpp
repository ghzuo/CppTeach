#include <iostream>
using namespace std;

int main(){
    int* p = new int[10];
    int* p2 = p;
    for(int i=0; i<10; ++i)
	*p2++ = i;

    p2 = p+1;
    delete p2;

    cout <<"XXX" << endl;
    int* p3 = p;
    for(int i=1; i<10; ++i)
	cout << *p3++ <<endl;
    
}
