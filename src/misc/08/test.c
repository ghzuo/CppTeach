#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include "randomWalk.h"

int main(){

    Status st, pst, ppst;
    Status sc, psc, ppsc;
    init(&st); init(&pst); init(&ppst);
    init(&sc); init(&psc); init(&ppsc);
    int index = 0;
    while(distance(&st) < 270){
	step(&st);
	step(&sc);
	if(++index == 100){
	    printf("%d %d %.2f %.2f %.2f %.2f %.2f %.2f\n", 
		   st.n, 1, st.x, st.y, st.x-pst.x, st.y-pst.y,
		   st.x+ppst.x-2*pst.x,st.x+ppst.x-2*pst.x);
	    printf("%d %d %.2f %.2f %.2f %.2f %.2f %.2f\n", 
		   sc.n, 2, sc.x, sc.y, sc.x-psc.x, sc.y-psc.y,
		   sc.x+ppsc.x-2*psc.x,sc.x+ppsc.x-2*psc.x);
	    ppst=pst; pst=st; 
	    ppsc=psc; psc=sc; 
	    index = 0;
	}
    }
}
