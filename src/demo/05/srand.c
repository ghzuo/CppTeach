/*
 * Copyright (c) 2020  T-Life Research Center, Fudan University, Shanghai,
 * China. See the accompanying Manual for the contributors and the way to cite
 * this work. Comments and suggestions welcome. Please contact Dr. Guanghong Zuo
 * <ghzuo@fudan.edu.cn>
 *
 * @Author: Dr. Guanghong Zuo
 * @Date: 2020-10-23 19:54:35
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2020-10-23 19:54:35
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int myRand() {
  // cannot run srand in sub-function, for testing
  // srand(time(0));
  return rand();
}

int main() {
  srand(time(0));

  int i;
  for (i = 0; i < 100; ++i) {
    printf("%d : %d \n", i, myRand());
  }
}