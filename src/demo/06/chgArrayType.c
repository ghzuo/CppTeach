/*
 * Copyright (c) 2020  T-Life Research Center, Fudan University, Shanghai,
 * China. See the accompanying Manual for the contributors and the way to cite
 * this work. Comments and suggestions welcome. Please contact Dr. Guanghong Zuo
 * <ghzuo@fudan.edu.cn>
 *
 * @Author: Dr. Guanghong Zuo
 * @Date: 2020-11-13 08:20:47
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2020-11-13 08:20:47
 */

#include <stdio.h>

int main() {
  int xi[] = {0, 1, 2, 4, 8, 16, 32};
  float *pf = (float *)xi;

  int i = 0;
  for (i = 0; i < sizeof(xi)/sizeof(int); ++i) {
    xi[i] *= (1024 * 1024* 256);
    printf("%d %d %f\n", i, xi[i], pf[i]);
  }
}