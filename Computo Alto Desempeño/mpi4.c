#include <stdio.h>
#include "mpi.h"


float x0=0.0, xf=1.0;
int i;
float n = 100000000.0
float dx, rango;
float xi;
float areas = 0.0, temp;
MPI:Status status;

int id, niter,rank,size,iter_ini,iter_fin;

int main(int argc, char ** argv){
	
	error = MPI_Init(&argc,&argv);

	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	rango= xf-x0;
	dx= rango / n;

	niter = n/size;	
	
	iter_ini = rank * niter;
	iter_fin = iter_ini +niter;

	if(rank==size-1) iter_fin=n;

	for(i=iter_ini; i<iter_fin; i++){
		xi = dx*i + dx/2;
		areas+= f(xi)*dx;
	}

	if(rank)
		MPI_Send(&areas,1,MPI_FLOAT,0,0,MPI_COMM_WORLD);
	else{
		for(i=1;i<size;i++){
			
			MPI_Recv();
		}

	}
	

	return 0;
}
