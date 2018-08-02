/*
 * Copyright (c) 2018  T-Life Research Center, Fudan University, Shanghai,
 * China. See the accompanying Manual for the contributors and the way to cite
 * this work. Comments and suggestions welcome. Please contact Dr. Guanghong Zuo
 * <ghzuo@fudan.edu.cn>
 *
 * @Author: Dr. Guanghong Zuo
 * @Date: 2018-08-02 14:20:13
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2018-08-02 14:20:13
 */

#include <iostream>
#include <omp.h>
using namespace std;

int counter;
#pragma omp threadprivate(counter)

int main() {

#pragma omp parallel
  {
    counter = omp_get_thread_num();
#pragma omp critical
    cout << omp_get_thread_num() << " " << counter << endl;
  }

  cout << endl;
  
#pragma omp parallel
  {
#pragma omp critical
    cout << omp_get_thread_num() << " " << counter << endl;
  }
}