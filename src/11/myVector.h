#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <vector>

using namespace std;

class myVec:public vector<float>{

public:
    myVec();
    myVec(int, float);
    myVec operator+(myVec&);

    friend myVec operator*(float, const myVec&); 
    friend ostream& operator<<(ostream&, const myVec&);
};


#endif
