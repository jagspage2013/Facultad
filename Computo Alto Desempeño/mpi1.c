#include <stdio.h>
#include "mpi.h"

int main(int argc, char ** argv){

	int size,rank,error;
	error = MPI_Init(&argc,&argv);
	printf("Hola mundo\nError %d",error);
	error = MPI_Finalize();
	printf("Se acaba Hola mundo\nError %d",error);
	
	return 0;
}
