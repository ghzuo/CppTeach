#include "myVector.h"

myVec::myVec(){};
myVec::myVec(int n, float v){
    for(int i=0; i<n; ++i)
	(*this).push_back(v);
};


myVec myVec::operator+(myVec& v){
    if(size() != v.size()){
	    cerr << "the numbers of the two vectors are not equal!" <<endl;
	    exit(1);
    }

    myVec newvec;
    for(int i=0; i<size(); ++i)
	newvec.push_back((*this)[i]+v[i]);
    return newvec;
};

myVec operator*(float f, const myVec& v){
    myVec v2;
    for(int i=0; i<v.size(); ++i)
        v2.push_back(f * v[i]);
    return v2;
}

ostream& operator<<(ostream& os, const myVec& v){
    for(myVec::const_iterator iter=v.begin(); iter!=v.end(); ++iter)
	os << *iter << "   ";
    return os;
};
