/*
 * Copyright (c) 2020  T-Life Research Center, Fudan University, Shanghai,
 * China. See the accompanying Manual for the contributors and the way to cite
 * this work. Comments and suggestions welcome. Please contact Dr. Guanghong Zuo
 * <ghzuo@fudan.edu.cn>
 *
 * @Author: Dr. Guanghong Zuo
 * @Date: 2020-11-08 20:19:59
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2020-11-08 20:19:59
 */

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int n = 6;
  if(argc > 1){
    n = atoi(argv[1]);
  }
  int half = n / 2;

  for (int i = 1; i <= half; ++i) {
    for (int j = 0; j < i; ++j) {
      cout << i << " " << j << endl;
    }

    int ni = n - i;
    if (ni != i) {
      for (int j = 0; j < ni; ++j) {
        cout << ni << " " << j << endl;
      }
    }
  }
}