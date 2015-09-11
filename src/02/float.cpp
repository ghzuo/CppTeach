#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    int   m = atoi(argv[1]);
    int   n = 16777216;
    float f = 1.0/(float)n;

    float sum = 0.0;
    for(int i=0; i<n*m; ++i)
        sum += f;
    
    cout << sum << endl;

    bitset<32> bf(*((unsigned*)&f));
    bitset<32> bs(*((unsigned*)&sum)); 
    cout << bf << "\n"
         << bs << endl;
}
