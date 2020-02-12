#include "controller.h"
#include <stdio.h>
#include "boolean.h"
#include "point.h"
void print_point(POINT P);
void print_point(POINT P){

	printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}
int main(){

	//Kamus
	POINT P, P1, P2;
	int kuadran;
	float f;

	//Algoritma
	printf("Msukan nilai abis dan ordinat");
	BacaPOINT(&P);

	
	printf("Test GeserSbXUp");
	GU(&P);
	print_point(P);
	
	printf("\n");

	return 0;
}



