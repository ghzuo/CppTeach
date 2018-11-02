#include "vec.h"

Vec Vec::operator+(const Vec& v) const{
    int idim = ndim();
    if(ndim() != v.ndim){
	cerr << "the numbers of the two vectors are not equal!" <<endl;
	exit(1);
    }

    vector<float> newdata(idim, 0.0);
    for(int i=0; i<idim; ++i)
	newdata[i] = getdim(i) + v.getdim[i];
    Vec newvec(idim);
    newvec.init(newdata);
    return newvec;
};


