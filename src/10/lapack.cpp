#include <iostream>
using namespace std;
extern "C" void dsyev_(const char *JOBZ, const char *UPLO,
                       const int *N, double *A, const int *LDA,
                       double *W, double *WORK, const int *LWORK,
                       int *info);
int main(){

    char jobz = 'V';
    char uplo = 'L';
    int  N = 2;
    double A[4] = {1.0, 2.0, 2.0, 3.0};
    int  lda = N;
    double W[2];
    int lwork = 10;
    double work[10];
    int info;
    
    dsyev_(&jobz, &uplo, &N, A, &lda, W, work, &lwork, &info);
        
    if(info == 0) /* succeed */{
        cout << "The eigenvalues of A are:\n"
             << W[0] << '\n' << W[1] << endl;
        cout << "Here's a matrix whose columns are eigenvectors of A \n"
             << "corresponding to these eigenvalues:\n"
             << A[0] << "  " << A[1] << "\n"
             << A[2] << "  " << A[3] << endl;
    }else{
        cerr << "dgesv fails %d\n" <<  info << endl;
    }
}

