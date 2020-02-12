
#include <stdio.h>
#include <stdlib.h>
#include "array.h"


int main () {
	/* KAMUS */
	TabOrder T;
	int i;
	int lastidx;
	Order X;
	

	/* ALGORITMA */
	printf("Masukkan N = ");
	scanf("%d", &T.Neff);

	for (i = 1; i <= T.Neff; i++) {
		T.TI[i].noMeja = 2*i;
		printf("Isi tabel T.TI[%d].noMeja : %d\n", i, T.TI[i].noMeja);
	}
	
	for (i = 1; i <= T.Neff; i++) {
		T.TI[i].noMenu = 3*i;
		printf("Isi tabel T.TI[%d].noMenu : %d\n", i, T.TI[i].noMenu);
	}	

	lastidx = GetLastIdxOrder(T);
	printf("Indeks elemen terakhir : %d\n\n", lastidx);


	printf("\nReset tabel kuy\n");
	MakeEmptyTabOrder(&T);

	for (i = 1; i <= T.Neff; i++) {
		printf("Isi tabel T.TI[%d].noMeja : %d\n", i, T.TI[i].noMeja);
	}
	
	for (i = 1; i <= T.Neff; i++) {
		printf("Isi tabel T.TI[%d].noMenu : %d\n", i, T.TI[i].noMenu);
	}
	printf("Tabel sudah direset\n");

	printf("Masukkan N baru = ");
	scanf("%d", &T.Neff);
	
	for (i = 1; i <= T.Neff; i++) {
		T.TI[i].noMeja = 1*i;
		printf("Isi tabel baru T.TI[%d].noMeja : %d\n", i, T.TI[i].noMeja);
	}
	
	X.noMeja = 3;
	X.noMenu = 3;
	AddAsLastElTabOrder(&T,X);
	
	for (i = 1; i <= T.Neff; i++) {
		printf("Isi tabel T.TI[%d].noMeja : %d\n", i, T.TI[i].noMeja);
	}
	
	for (i = 1; i <= T.Neff; i++) {
		printf("Isi tabel T.TI[%d].noMenu : %d\n", i, T.TI[i].noMenu);
	}
	
	DelEliTabOrder(&T,1,&X);
	
	for (i = 1; i <= T.Neff; i++) {
		printf("Isi tabel T.TI[%d].noMeja : %d\n", i, T.TI[i].noMeja);
	}
	
	for (i = 1; i <= T.Neff; i++) {
		printf("Isi tabel T.TI[%d].noMenu : %d\n", i, T.TI[i].noMenu);
	}

	return 0;
}
