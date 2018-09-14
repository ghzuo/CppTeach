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
#include <unistd.h>
using namespace std;

int main() {

  int sum(0);
#pragma omp parallel for reduction(+:sum)
  for (int i = 0; i < 100; ++i) {
    sum += i;
    usleep(10);
  }

  cout << sum << endl;
}