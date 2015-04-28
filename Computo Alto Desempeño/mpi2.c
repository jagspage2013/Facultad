#include <stdio.h>
#include "mpi.h"

int main(int argc, char ** argv){

	int size,rank,error;
	error = MPI_Init(&argc,&argv);

	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	printf("Hola mundo soy %i de %i \n",rank,size);
	error = MPI_Finalize();

	
	return 0;
}
