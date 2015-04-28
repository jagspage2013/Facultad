#include <stdio.h>
#include "mpi.h"

MPI_Status status;
int rank,size,error,i,j;
int datos[8],datoss[8];
int main(int argc, char ** argv){
	
	error = MPI_Init(&argc,&argv);

	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	
	for(i=0;i<=8;i++)
		datos[i] =rank;
	
	
	return ;
}
