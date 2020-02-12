#include "boolean.h"
#include "jam.h"
#include <stdio.h>

void print_bool (boolean X){

	if(X){
		printf("true");
	}
	else {
		printf("false");
	}
}

void print_jam (JAM J){

	printf("%02d:%02d:%02d", Hour(J),Minute(J),Second(J));
}

void print_long (long L){

	printf("%ld",L);
}

int main(){
	//Kamus
	JAM j1,j2;
	long N;

	//Algoritma
	BacaJAM(&j1);
	BacaJAM(&j2);
	TulisJAM(j1);
	TulisJAM(j2);

	N = JAMToDetik(j1);
	printf("\n Test JAMToDetik ");
	print_long(N);

	j1 = DetikToJAM(186401);
	printf("\n Test DetikToJAM ");
	print_jam(j1);

	JEQ(j1,j2);
	printf("\n Test JEQ ");
	print_bool(JEQ(j1,j2));

	JNEQ(j1,j2);
	printf("\n Test JNEQ ");
	print_bool(JNEQ(j1,j2));

	JLT(j1,j2);
	printf("\n Test JLT ");
	print_bool(JLT(j1,j2));

	JGT(j1,j2);
	printf("\n Test JGT ");
	print_bool(JGT(j1,j2));

	j1 = NextDetik(j1);
	printf("\n Test NextDetik ");
	print_jam(j1);

	j1 = NextNDetik(j1,10);
	printf("\n Test NextNDetik ");
	print_jam(j1);

	j1 = PrevDetik(j1);
	printf("\n Test PrevDetik ");
	print_jam(j1);

	j1 = PrevNDetik(j1,10);
	printf("\n Test PrevNDetik ");
	print_jam(j1);

	printf("\n jam 1 : ");
	print_jam(j1);
	printf("\n jam 2 : ");
	print_jam(j2);

	long dt = Durasi(j1,j2);
	printf("\n Test Durasi ");
	print_long(dt);
	printf("\n");
	return 0;
}
