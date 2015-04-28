#include <stdio.h>
#include "omp.h"

void suma_par(int i, double A[20]){
	int j, size;
	double sum =0.0;

	size = omp_get_num_threads();
	for(j=i; j<20 ; j+=size)
		sum+=A[j];
	printf("En hebra %d la suma es %f\n",i,sum);
}

main(){
	double A[20];
	int i, id;
 	for(i=0;i<20;i++)
		A[i]=i;
	omp_set_num_threads(4);
	
	#pragma omp parallel private(id)
	{
		id= omp_get_thread_num();
		suma_par(id,A);
	}
}
