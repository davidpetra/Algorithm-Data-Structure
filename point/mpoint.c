#include "point.h"
#include <stdio.h>
#include "boolean.h"

void print_point(POINT P){

	printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

void print_bool (boolean X){
	if (X) {
		printf("true");
	}
	else {
		printf("false");
	}
}

int main(){

	//Kamus
	POINT P, P1, P2;
	int kuadran;
	float f;

	//Algoritma
	printf("Masukkan nilai absis dan ordinat : ");
	BacaPOINT(&P);

	printf("Masukkan nilai absis dan ordinat : ");
	BacaPOINT(&P1);

	printf("Titik yang dibaca ");
	TulisPOINT(P);
	printf("\n");

	printf("Test EQ");
	print_bool(EQ(P,P1));
	printf("\n");

	printf("Test NEQ");
	print_bool(NEQ(P,P1));
	printf("\n");

	printf("Test IsOrigin");
	print_bool(IsOrigin(P));
	printf("\n");

	printf("Test IsOnSbX");
	print_bool(IsOnSbX(P));
	printf("\n");

	printf("Test IsOnSbY");
	print_bool(IsOnSbY(P));
	printf("\n");

	printf("Test Kuadran");
	kuadran = Kuadran(P);
	printf("%d\n",kuadran);

	printf("Test NextX");
	P2 = NextXL(P);
	print_point(P2);
	printf("\n");

	printf("Test NextY");
	P2 = NextYU(P);
	print_point(P2);
	printf("\n");

	printf("Test PlusDelta");
	P2 = PlusDelta(P,5,5);
	print_point(P2);
	printf("\n");

	printf("Test MirrorOf");
	P2 = MirrorOf(P,true);
	print_point(P2);
	printf("\n");

	printf("Test Jarak0");
	f = Jarak0(P);
	printf("%.2f\n",f);

	printf("Test Panjang");
	f = Panjang(P,P1);
	printf("%.2f\n",f);

	printf("Test Geser");
	Geser(&P,5,5);
	print_point(P);
	printf("\n");

	printf("TestMirror");
	Mirror(&P,true);
	print_point(P);
	printf("\n");

	printf("Test Putar");
	printf("\n Posisi Awal : ");
	print_point(P);
	Putar(&P, 90);
	printf("\n Posisi Akhir : ");
	print_point(P);
	printf("\n");

	printf("Test GeserSbX");
	GeserKeSbX(&P);
	print_point(P);
	printf("\n");

	printf("Test GeserSbY");
	GeserKeSbY(&P);
	print_point(P);
	printf("\n");

	return 0;
}



