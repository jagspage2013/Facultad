#include <stdio.h>
#include "omp.h"

float f(int x){
	return x;
}

int main(){
float x_ini=0.0, x_fin=10.0;
int i, id, size;

int n= 10;
int first, last;

float base, rango;
float x_i, suma=0;
float areas;

rango = x_fin-x_ini;
base = rango / (float)n;
int  lastarray[4]= {-10,-10,-12,-10};
first=last=10;

#pragma omp parallel for private(i,x_i) reduction(+:areas) schedule(static,4) firstprivate(first) lastprivate(last)
for(i=0; i<n; i++){
	id= omp_get_thread_num();
	//printf("Hebra %i hace iter %i \n",id,i);
	printf("First: %i \n",first);
	last = id;
	x_i = base*i + base/2;
	areas+= f(x_i)*base;
	lastarray[id] = i;
}

printf("First %i, Last: %i \n",first,last);
printf("%i %i %i %i ",lastarray[0],lastarray[1],lastarray[2],lastarray[3]);
}

