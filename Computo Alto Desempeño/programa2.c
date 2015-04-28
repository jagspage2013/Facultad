#include <stdio.h>

int main(){
	float a;
	int id;
	printf("hola mundo serial \n");
	#pragma omp parallel
	{
		id = omp_get_thread_num();
		printf("Hola Mundo paralelo %d \n",id);
	}

	printf("Hola Mundo serial 2\n");
	#pragma omp parallel
	{
		id = omp_get_thread_num();
		printf("Hola Mundo paralelo %d \n",id);
	}

	#pragma omp parallel
	{
		id = omp_get_thread_num();
		printf("Hola Mundo paralelo %d \n",id);
	}
	return 0;
}
