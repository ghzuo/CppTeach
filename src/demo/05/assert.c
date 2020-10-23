/*
 * Copyright (c) 2020  T-Life Research Center, Fudan University, Shanghai,
 * China. See the accompanying Manual for the contributors and the way to cite
 * this work. Comments and suggestions welcome. Please contact Dr. Guanghong Zuo
 * <ghzuo@fudan.edu.cn>
 *
 * @Author: Dr. Guanghong Zuo
 * @Date: 2020-06-07 12:13:01
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2020-06-07 12:13:01
 */

#include <stdio.h>
// uncomment to disable assert(), Can replace by -DNDEBUG
// #define NDEBUG
#include <assert.h>

int main() {
  assert(2 + 2 == 4);
  printf("Execution continues past the first assert\n");
  assert(2 + 2 == 5);
  printf("Execution continues past the second assert\n");
}
