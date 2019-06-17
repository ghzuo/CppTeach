#include <stdio.h>
#include "fftw3.h"
#define N 8

int main(){

    int i;
    fftw_complex *din,*out;
    fftw_plan p;
    din  = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    if((din==NULL)||(out==NULL)){
        printf("Error:insufficient available memory\n");
    } else {
        for(i=0; i<N; i++){/*Testing Data*/
            din[i][0] = i+1;
            din[i][1] = 0;
        }
    }
    
    p = fftw_plan_dft_1d(N, din, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p); /* repeat as needed */
    fftw_destroy_plan(p);
    fftw_cleanup();
    
    for(i=0;i<N;i++) { /*OUTPUT*/
        printf("%f,%fi\n",din[i][0],din[i][1]);
    }
    printf("\n");
    
    for(i=0;i<N;i++){ /*OUTPUT*/
        printf("%f,%fi\n",out[i][0], out[i][1]);
    }

    if(din!=NULL) fftw_free(din);
    if(out!=NULL) fftw_free(out);
}

