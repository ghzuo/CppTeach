#include <iostream>
#include <iomanip>
#include <complex>
#include <unsupported/Eigen/FFT>
using namespace std;

int main(){

    Eigen::FFT<float> fft;
    vector<float> timevec{1,2,3,4,5,6,7,8};
    vector<complex<float>> freqvec;
    fft.fwd(freqvec,timevec);
    // fft.inv(timevec,freqvec);

    cout << fixed << setprecision(5);
    for(const auto &x : freqvec)
        cout << x.real() << "+" << x.imag() << "i\n";
    cout << endl;
}

