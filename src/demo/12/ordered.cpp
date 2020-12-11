/*
 * Copyright (c) 2018  T-Life Research Center, Fudan University, Shanghai,
 * China. See the accompanying Manual for the contributors and the way to cite
 * this work. Comments and suggestions welcome. Please contact Dr. Guanghong Zuo
 * <ghzuo@fudan.edu.cn>
 *
 * @Author: Dr. Guanghong Zuo
 * @Date: 2018-08-02 11:55:09
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2018-08-02 11:55:09
 */

#include <iostream>
using namespace std;

int main() {
#pragma omp parallel for ordered
  for (int i = 0; i < 10; ++i) {
    #pragma omp ordered
    cout << "Hello World! " << i << endl;
  }
}