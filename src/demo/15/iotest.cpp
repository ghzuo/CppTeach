/*
 * Copyright (c) 2020  T-Life Research Center, Fudan University, Shanghai,
 * China. See the accompanying Manual for the contributors and the way to cite
 * this work. Comments and suggestions welcome. Please contact Dr. Guanghong Zuo
 * <ghzuo@fudan.edu.cn>
 *
 * @Author: Dr. Guanghong Zuo
 * @Date: 2020-10-20 13:26:45
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2020-10-20 13:26:46
 */

#include <chrono>
#include <iostream>
#include <vector>
const int N = 100000000;

using namespace std;

int main() {
  auto start(chrono::system_clock::now());

  vector<int> v(N);
  vector<int> vv(N, 3);
#pragma omp parallel for num_threads(4)
  for (int i = 1; i < N; ++i) {
    v[i] = i + vv[i];
  }

  double sum(0);
#pragma omp parallel for reduction(+ : sum) num_threads(4)
  for (int i = 1; i < N; ++i) {
    sum += (v[i] - vv[i]);
  }

  auto now(chrono::system_clock::now());

  cout << sum << "\t"
       << chrono::duration_cast<std::chrono::milliseconds>(now - start).count()
       << endl;
}