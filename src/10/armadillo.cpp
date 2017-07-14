#define  ARMA_DONT_USE_WRAPPER
#define  ARMA_USE_LAPACK
#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;

int main(){

    mat A("0.6606, 0.1751, 0.058,  0.0314, 0.0459, 0.029; 0.1826, 0.7138, 0.02,   0.0506, 0.0271, 0.0059; 0.0747, 0.0317, 0.7783, 0.0045, 0.0339, 0.0769; 0.0394, 0.0627, 0.0072, 0.6989, 0.0269, 0.1649; 0.2412, 0.1294, 0.0471, 0.0941, 0.4412, 0.0471; 0.0109, 0.0019, 0.0114, 0.0395, 0.0019, 0.9344;");

    A = A.t();
    cout << "Here is the matrix A:\n" << A << endl;

    // get the Eigen
    cx_vec eigval;
    cx_mat eigvec;
    eig_gen(eigval, eigvec, A);

    cout << "The eigenvalues of A are:\n"
         << eigval << endl;
    cout << "Here's a matrix whose columns are eigenvectors of A \n"
         << "corresponding to these eigenvalues:\n"
         << eigvec << endl;
}

