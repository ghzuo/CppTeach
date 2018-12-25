/*
 * Copyright (c) 2018  T-Life Research Center, Fudan University, Shanghai, China.
 * See the accompanying Manual for the contributors and the way to cite this work.
 * Comments and suggestions welcome. Please contact
 * Dr. Guanghong Zuo <ghzuo@fudan.edu.cn>
 * 
 * @Author: Dr. Guanghong Zuo
 * @Date: 2018-12-25 10:53:08
 * @Last Modified By: Dr. Guanghong Zuo
 * @Last Modified Time: 2018-12-25 10:53:08
 */

#include <iostream>
#include <mpi.h>

int main(int argc, char **argv){
  int rank, size, tag, i;
  MPI_Status status;
  char message[20];

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  tag = 7;
  if(rank == 0) {
    strcpy(message, "Hello, world");
    for(int i=1; i<size; ++i){
      MPI_Send(message, 13, MPI_CHAR, i, tag, MPI_COMM_WORLD);
    }
  } else {
    MPI_Recv(message, 13, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
  }
  std::cout << "node " << rank << ": " << message << std::endl;
  MPI_Finalize();
}