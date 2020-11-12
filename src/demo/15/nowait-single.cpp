/*
 * Copyright (c) 2020  T-Life Research Center, Fudan University, Shanghai, China.
 * See the accompanying Manual for the contributors and the way to cite this work.
 * Comments and suggestions welcome. Please contact
 * Dr. Guanghong Zuo <ghzuo@fudan.edu.cn>
 * 
 * @Author: Dr. Guanghong Zuo
 * @Date: 2020-11-10 18:06:48
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2020-11-10 18:06:48
 */

#include <iostream>
using namespace std;

int main(){
#pragma omp parallel
{
  #pragma omp single nowait
  double a = alice();
   #pragma omp single nowait
  double b = bob();
    #pragma omp single nowait
  double c = cy(); 
}
double s = boss(a,b);
cout << bigboss(s,c) << endl;

}