/*
 * Copyright (c) 2018  T-Life Research Center, Fudan University, Shanghai, China.
 * See the accompanying Manual for the contributors and the way to cite this work.
 * Comments and suggestions welcome. Please contact
 * Dr. Guanghong Zuo <ghzuo@fudan.edu.cn>
 * 
 * @Author: Dr. Guanghong Zuo
 * @Date: 2018-08-02 11:55:09
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2018-08-02 11:55:09
 */

#include <iostream>
using namespace std;

int main(){
  #pragma omp parallel
  {
    #pragma omp critical
    cout << "Hello World!" << endl;
  }
}