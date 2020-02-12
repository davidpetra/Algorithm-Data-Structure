#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "matriks.h"
#include "variable.h"



/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
/* I.S. Sembarang
   F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl
   jadi indeksnya antara 1..MaxEl
   Ciri stack kosong : TOP bernilai Nil */
{
	/* KAMUS LOKAL */

	/* ALGORITMA */
	Top(*S) = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
	/* KAMUS LOKAL */

	/* ALGORITMA */
	return (Top(S) == Nil);
}

boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
	/* KAMUS LOKAL */

	/* ALGORITMA */
	return (Top(S) == MaxEl);
}


/* ********** Operator Dasar Stack ********* */
void Push(Stack *S,infotype X)
/* Menambahkan X sebagai elemen Stack S.
   I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
   F.S. X menjadi TOP yang baru, TOP bertambah 1 */
{
	/* KAMUS LOKAL */

	/* ALGORITMA */
	Top(*S)++;
	InfoTop(*S) = X;
}

void Pop(Stack *S,infotype *X)
/* Menghapus X dari Stack S.
   I.S. S tidak kosong
   F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	/* KAMUS LOKAL */

	/* ALGORITMA */
	*X = InfoTop(*S);
	Top(*S)--;
}

void TulisStack(Stack S)
{
	Stack Stemp;
	infotype x;
	int i=2; 
	test tempnama;
	int count = 0;
	int j;

	CreateEmptyStack(&Stemp);

	if (IsEmptyStack(S)){
		nama(M1,2,9) = "...";
		nama(M1,3,9) = "...";
		nama(M1,4,9) = "...";
		nama(M2,2,9) = "...";
		nama(M2,3,9) = "...";
		nama(M2,4,9) = "...";
	}
	
	while(!IsEmptyStack(S)) {
		Pop(&S,&x);
		count++;
		printf("%d ", x);
		if (x == 1) {
			idxiM3 = 1;
			idxjM3 = 1;
			tempnama = nama(M2,idxiM3,idxjM3);
			//printf("%s\n", Ma1);
		}
		else if (x == 2) {
			idxiM3 = 2;
			idxjM3 = 1;
			tempnama = nama(M2,idxiM3,idxjM3);
			//printf("%s\n", Ma2);
		}
		else if (x == 3) {
			idxiM3 = 3;
			idxjM3 = 1;
			tempnama = nama(M2,idxiM3,idxjM3);
			//printf("%s\n", Ma3);
		}
		else if (x == 4) {
			idxiM3 = 4;
			idxjM3 = 1;
			tempnama = nama(M2,idxiM3,idxjM3);
			//printf("%s\n", Ma4);
		}
		else if (x == 5) {
			idxiM3 = 5;
			idxjM3 = 1;
			tempnama = nama(M2,idxiM3,idxjM3);
			//printf("%s\n", Ma5);
		}
		else if (x == 6) {
			idxiM3 = 6;
			idxjM3 = 1;
			tempnama = nama(M2,idxiM3,idxjM3);
			//printf("%s\n", Ma6);
		}
		else if (x == 7) {
			idxiM3 = 7;
			idxjM3 = 1;
			tempnama = nama(M2,idxiM3,idxjM3);
			//printf("%s\n", Ma7);
		}
		else if (x == 8) {
			idxiM3 = 8;
			idxjM3 = 1;
			tempnama = nama(M2,idxiM3,idxjM3);
			//printf("%s\n", Ma8);
		}
		else if (x == 9) {
			idxiM3 = 5;
			idxjM3 = 4;
			tempnama = nama(M2,idxiM3,idxjM3);
			//printf("%s\n", Ma9);
		}
		else if (x == 10) {
			idxiM3 = 5;
			idxjM3 = 5;
			tempnama = nama(M2,idxiM3,idxjM3);
			//printf("%s\n", Ma9);
		}
		else if (x == 11) {
			idxiM3 = 8;
			idxjM3 = 4;
			tempnama = nama(M2,idxiM3,idxjM3);
			//printf("%s\n", Ma9);
		}
		else if (x == 12) {
			idxiM3 = 8;
			idxjM3 = 5;
			tempnama = nama(M2,idxiM3,idxjM3);
			//printf("%s\n", Ma9);
		}
		else if (x == 13) {
			idxiM3 = 8;
			idxjM3 = 6;
			tempnama = nama(M2,idxiM3,idxjM3);
			//printf("%s\n", Ma9);
		}
		else if (x == 14) {
			idxiM3 = 8;
			idxjM3 = 7;
			tempnama = nama(M2,idxiM3,idxjM3);
			//printf("%s\n", Ma9);
		}
		else if (x == 15) {
			idxiM3 = 8;
			idxjM3 = 8;
			tempnama = nama(M2,idxiM3,idxjM3);
		}

		nama(M1,i,9) = tempnama;
		nama(M2,i,9) = tempnama;
		i++;
		
		Push(&Stemp,x);
	}
	
	if (count == 1) {
		j = 3;
		while (j<=4) {
			nama(M1,j,9) = "...";
			nama(M2,j,9) = "...";
			j++;
		}
	}
	else if (count == 2) {
		j = 4;
		while (j<=4) {
			nama(M1,j,9) = "...";
			nama(M2,j,9) = "...";
			j++;
		}
	}
		
	while (!IsEmptyStack(Stemp)) {
		Pop(&Stemp,&x);
		Push(&S,x);
	}
		
}
