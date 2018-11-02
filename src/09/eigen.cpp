#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

typedef Matrix<float,6,6> Matrix6f;

int main(){

    Matrix6f A;
    A <<0.6606, 0.1751, 0.0580, 0.0314, 0.0459, 0.0290,
        0.1826, 0.7138, 0.0200, 0.0506, 0.0271, 0.0059,
        0.0747, 0.0317, 0.7783, 0.0045, 0.0339, 0.0769,
        0.0394, 0.0627, 0.0072, 0.6989, 0.0269, 0.1649,
        0.2412, 0.1294, 0.0471, 0.0941, 0.4412, 0.0470,
        0.0109, 0.0019, 0.0114, 0.0395, 0.0019, 0.9344;
    A.transposeInPlace();
   
    cout << "Here is the matrix A:\n" << A << endl;

    // get the eigen
    EigenSolver<Matrix6f> eigensolver(A);
    // EigenSolver<Matrix2f> eigensolver(A);

    if (eigensolver.info() != Success) abort();

    cout << "The eigenvalues of A are:\n"
         << eigensolver.eigenvalues() << endl;
    cout << "Here's a matrix whose columns are eigenvectors of A \n"
         << "corresponding to these eigenvalues:\n"
         << eigensolver.eigenvectors() << endl;
}

