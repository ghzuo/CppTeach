#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;

int main(){

    mat A("1 2; 2 3");
    cout << "Here is the matrix A:\n" << A << endl;

    // get the Eigen
    vec eigval;
    mat eigvec;
    eig_sym(eigval, eigvec, A);

    cout << "The eigenvalues of A are:\n"
        << eigval << endl;
    cout << "Here's a matrix whose columns are eigenvectors of A \n"
        << "corresponding to these eigenvalues:\n"
        << eigvec << endl;
}

