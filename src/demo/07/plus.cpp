/*
 * Copyright (c) 2019  T-Life Research Center, Fudan University, Shanghai, China.
 * See the accompanying Manual for the contributors and the way to cite this work.
 * Comments and suggestions welcome. Please contact
 * Dr. Guanghong Zuo <ghzuo@fudan.edu.cn>
 * 
 * @Author: Dr. Guanghong Zuo
 * @Date: 2019-11-02 10:31:57
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2019-11-02 10:31:57
 */

#include <iostream>
using namespace std;

int main(){
  int n = 1;

  // output 5 for clang, 6 for g++
  cout << (++n) + (++n) << endl;
}