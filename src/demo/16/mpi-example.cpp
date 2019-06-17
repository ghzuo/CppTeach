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

  // basic parameter, serial 
  int rank, size, tag, i;
  MPI_Status status;  // tag for status
  char message[20] = "Hello, Before!";

  // inital the parameters for parallel
  MPI_Init(&argc, &argv);  // initial by paramenters
  MPI_Comm_size(MPI_COMM_WORLD, &size); // MPI_COMM_WORLD: group for all processes
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  //output message in every processes
  std::cout << "node " << rank << ": " << message << std::endl;

  // communicate between processes ...
  tag = 7;  // tag for info
  if(rank == 0) {
    strcpy(message, "Hello, After!");
    for(int i=1; i<size; ++i){
      // send message from master to other processes
      MPI_Send(message, 13, MPI_CHAR, i, tag, MPI_COMM_WORLD);
    }
  } else {
    // receive message from master at other processes
    MPI_Recv(message, 13, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
  }

  //output message in every processes
  std::cout << "node " << rank << ": " << message << std::endl;

  // end of parallel
  MPI_Finalize();
}