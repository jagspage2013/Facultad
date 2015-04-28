#include <stdio.h>


int n = 1000;
float x0 = 0.0;
float xf= 10.0;


float f(float x){
	return x;
}

int main(){
	float xi = x0;
	float dx = (xf - x0)/n;
	int i;
	float areat=0.0;
	for(i =0 ; i<n ; i++){
		areat += (f(xi+dx/2));
		xi +=dx;
	}
	areat*=dx;
	printf("EL resultado es : %f\n",areat);
	return 0;
}
