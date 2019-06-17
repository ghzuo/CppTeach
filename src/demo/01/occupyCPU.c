#include <unistd.h>

int main(){
  for(;;){
    for(int i=0; i<60000; i++)
      ;
    usleep(100);
  }
}
