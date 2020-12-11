/*
 * Copyright (c) 2020  T-Life Research Center, Fudan University, Shanghai,
 * China. See the accompanying Manual for the contributors and the way to cite
 * this work. Comments and suggestions welcome. Please contact Dr. Guanghong Zuo
 * <ghzuo@fudan.edu.cn>
 *
 * @Author: Dr. Guanghong Zuo
 * @Date: 2020-10-20 12:02:08
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2020-10-20 12:02:08
 */

#include <iostream>
//#include <omp.h> 

int main() {
#pragma omp parallel
  {
#pragma omp for nowait  // comment/uncomment nowait for testing
    for (int i = 0; i < 1000; ++i) {
#pragma omp critical
      std::cout << i << "+" << std::endl;
    }

//#pragma omp barrier  // comment/uncomment line for testing

#pragma omp for
    for (int j = 0; j < 10; ++j) {
#pragma omp critical
      std::cout << j << "-" << std::endl;
    }
  }

  return 0;
}