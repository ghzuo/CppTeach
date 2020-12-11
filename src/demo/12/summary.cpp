/*
 * Copyright (c) 2020  T-Life Research Center, Fudan University, Shanghai,
 * China. See the accompanying Manual for the contributors and the way to cite
 * this work. Comments and suggestions welcome. Please contact Dr. Guanghong Zuo
 * <ghzuo@fudan.edu.cn>
 *
 * @Author: Dr. Guanghong Zuo
 * @Date: 2020-11-10 16:01:32
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2020-11-10 16:01:32
 */

#include <iostream>
using namespace std;

int main() {
  int x = 0;
    
#pragma omp parallel
  {
    int xn = 0;
#pragma omp for
    for (int i = 100; i < 600; i++)
      xn += i;
#pragma omp atomic
    x += xn;
  }

  cout << x << endl;
}
