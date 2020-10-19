/*
 * Copyright (c) 2020  T-Life Research Center, Fudan University, Shanghai,
 * China. See the accompanying Manual for the contributors and the way to cite
 * this work. Comments and suggestions welcome. Please contact Dr. Guanghong Zuo
 * <ghzuo@fudan.edu.cn>
 *
 * @Author: Dr. Guanghong Zuo
 * @Date: 2020-10-18 20:42:55
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2020-10-18 20:42:55
 */

#include <iostream>
#include <omp.h>

struct dbl_int {
  double val;
  int idx;
};

const dbl_int &max(const dbl_int &a, const dbl_int &b) {
  return a.val > b.val ? a : b;
}

#pragma omp declare reduction(maxVal: dbl_int : omp_out = max(omp_out, omp_in))

int main() {
  dbl_int di = {-100., -1};
#pragma omp parallel num_threads(10) reduction(maxVal : di)
  {
    di.val = omp_get_thread_num() % 7;
    di.idx = omp_get_thread_num();
  }
  std::cout << "Upon exit, value=" << di.val << " and index=" << di.idx
            << std::endl;
  return 0;
}