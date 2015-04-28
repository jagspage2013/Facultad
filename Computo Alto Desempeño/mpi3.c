#include <stdio.h>
#include "mpi.h"

int main(int argc, char ** argv){

	int size,rank,error;
	float a=3.14 ,b=0; // pasar a del proceso 0 a b del proceso 1
	MPI_Status status;
	
	error = MPI_Init(&argc,&argv);

	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	printf("Hola mundo soy %i de %i \n",rank,size);

	// haciendo el traspaso
	
	if(rank==0){
		MPI_Send(&a, 1,MPI_FLOAT, 1, 0,MPI_COMM_WORLD);
	
		printf("\nDato enviado en proceso %d :> %f",rank,a);
	}
	if(rank==1){
		MPI_Recv(&b,1,MPI_FLOAT,0,0,MPI_COMM_WORLD,&status);
		printf("\nDato recibido es :> %f ",b);

	}
	error = MPI_Finalize();

	
	return 0;
}
