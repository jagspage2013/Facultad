#include <stdio.h>
#include "omp.h"
#define ITER 10

int main(){
	float a;
	int id=-1,i;
	printf("hola mundo serial \n");
	#pragma omp parallel private(i,id)
	{
		id = omp_get_thread_num();
		for(i=0;i<ITER; i++)
			printf("Hola Mundo paralelo %d PID=> %d\n",i,id);
	}
	printf("hola mundo serial %d \n",id);
	
	return 0;
}
