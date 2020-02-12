#include "point.h"
#include <stdio.h>
#include "boolean.h"
#include <math.h>


//Make Point
POINT MakePOINT (float X, float Y)
{

	//Kamus
	POINT P;

	//Algoritma
	Absis(P) = X;
	Ordinat(P) = Y;

	return P;
}

//Baca Point
void BacaPOINT (POINT * P)
{

	//Kamus
	float x,y;

	//Algoritma
	scanf("%f %f",&x,&y); //menerima input dari dalam 1 baris dengan sebuah pemisah 1 spasi

	*P = MakePOINT(x,y); //P terdefinisi
}

//Tulis Point
void TulisPOINT (POINT P)
{

	//Kamus

	//Algoritma
	printf("(%.2f,%.2f)", Absis(P), Ordinat(P)); //menulis ke layar dengan format (X,Y) dengan 2 angka di belakang koma
}

//boolean EQ
boolean EQ (POINT P1, POINT P2)// mengeluarkan true apabila P1 dan P2 sama 
{
	
	//Kamus

	//Algoritma
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

//boolean NEQ
boolean NEQ (POINT P1, POINT P2)//mengeluarkan true apabila P1 tidak sama dengan P2
{
	
	//kamus

	//Algoritma
	return(!EQ(P1,P2));
}

//boolean IsOrigin
boolean IsOrigin(POINT P)//menampilkan true apabila P adalah titik origin
{
	
	//kamus

	//Algoritma
	return((Absis(P) == 0 && Ordinat(P) == 0));
}	

//boolean IsOnSbX
boolean IsOnSbX (POINT P)
{

	//kamus

	//Algoritma
	return(Ordinat(P) == 0);
}

//boolean IsOnSbY
boolean IsOnSbY (POINT P)
{

	//kamus

	//Algoritma
	return(Absis(P) == 0);
}

//Kuadran
int Kuadran (POINT P)
{

	//kamus

	//Algoritma
	
	if((!IsOrigin(P)) && (!(IsOnSbX(P) || IsOnSbY(P)))){

		if (Absis(P)>0){
			if (Ordinat(P)>0){
				return 1;
			}
			else{
				return 4;
			}	
		}
		else {
			if (Ordinat(P)>0){
				return 2;
			}
			else{
				return 3;
			}
		}
	}

	else 
		return 0;
}

//NextX
POINT NextXR (POINT P)
{//Point p pindah satu ke kanan

	//kamus

	//Algoritma
	Absis(P) += 1;
	return P;
}
POINT NextXL (POINT P)
{//Point p pindah satu ke kiri

	//kamus

	//Algoritma
	Absis(P) = Absis(P) - 1;
	return P;
}


//NextY
POINT NextYU (POINT P)
{//Point p pindah satu ke atas

	//kamus

	//Algoritma
	Ordinat(P) += 1;
	return P;
}
POINT NextYD (POINT P)
{//Point p pindah satu ke bawah

	//kamus

	//Algoritma
	Ordinat(P) = Ordinat(P)-1;
	return P;
}
//PlusDelta
POINT PlusDelta (POINT P, float deltaX, float deltaY)
{

	//kamus

	//Algoritma
	Absis(P) += deltaX;
	Ordinat(P) += deltaY;
	return P;
}	

//MirrorOf
POINT MirrorOf (POINT P, boolean SbX)
{

	//kamus

	//Algoritma
	if(SbX){
		Ordinat(P) = -(Ordinat(P));
	} 
	else {
		Absis(P) = -(Absis(P));
	}
	return P;
}

//Jarak0
float Jarak0 (POINT P)
{

	//kamus
	POINT origin;

	//Algoritma
	Absis(origin) = 0;
	Ordinat(origin) = 0;

	return Panjang(P, origin);
}

//Panjang
float Panjang (POINT P1, POINT P2)
{

	//kamus
	float x1,x2,y1,y2,jarak;

	//Algoritma
	x1 = Absis(P1);
	x2 = Absis(P2);
	y1 = Ordinat(P1);
	y2 = Ordinat(P2);

	jarak = sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));

	return jarak;
}

//Geser
void Geser (POINT *P, float deltaX, float deltaY)
{

	//kamus

	//Algoritma
	*P = PlusDelta(*P,deltaX,deltaY);
}

//GeserKeSbX
void GeserKeSbX (POINT *P)
{

	//kamus

	//Algoritma
	Ordinat(*P) = 0;
}

//GeserKeSbY
void GeserKeSbY (POINT *P)
{

	//kamus

	//Algoritma
	Absis(*P) = 0;
}

//Mirror
void Mirror (POINT *P, boolean SbX)
{

	//kamus

	//Algoritma
	*P = MirrorOf(*P, SbX);
}

//Putar
void Putar (POINT *P, float Sudut)
{

	//kamus
	float X1, X2, Y1, Y2;
	double rad;

	//Algoritma
	X1 = Absis(*P);
	Y1 = Ordinat(*P);
	rad = (Sudut * 3.14159265 / 180);

	X2 = X1*(cos(rad)) + Y1*(sin(rad));
	Y2 = Y1*(cos(rad)) + X1*(sin(rad));

	Absis(*P) = X2;
	Ordinat(*P) = Y2;
}