/*
 * Copyright (c) 2020  T-Life Research Center, Fudan University, Shanghai, China.
 * See the accompanying Manual for the contributors and the way to cite this work.
 * Comments and suggestions welcome. Please contact
 * Dr. Guanghong Zuo <ghzuo@fudan.edu.cn>
 * 
 * @Author: Dr. Guanghong Zuo
 * @Date: 2020-11-12 14:55:56
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2020-11-12 14:55:56
 */

#include <iostream>
#include <vector>
#define N 10000000
using namespace std;

int main(){

  vector<int> x(N,1);
  int sum;
#pragma omp parallel for simd reduction(+:sum)
  for(int i=0; i<N; ++i){
    sum += i*x[i]*10;
  }
  cout << sum <<endl;
}