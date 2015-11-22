#define  ARMA_DONT_USE_WRAPPER
#define  ARMA_USE_LAPACK
#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;

int main(){
    vec X{1,2,3,4,5,6,7,8};
    cx_vec Y = fft(X);
    cout << Y << endl;
}

