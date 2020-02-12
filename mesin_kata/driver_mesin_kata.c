#include "mesin_kata.h"
#include <stdio.h>

boolean IsKataSama(Kata K1, Kata K2);

int main() {
	int i;
	int NbKata = 0;
	int LTotal = 0;

	Kata TempKata;
	int NWHILE;

	char filename[100];

	TempKata.TabKata[1] = 'w';
	TempKata.TabKata[2] = 'h';
	TempKata.TabKata[3] = 'i';
	TempKata.TabKata[4] = 'l';
	TempKata.TabKata[5] = 'e';
	TempKata.Length = 5;
	NWHILE = 0;

	printf("Masukan nama file :\n");
	scanf("%s", filename);


	STARTKATA(filename);
	while (!EndKata) {
		for (i = 1; i <= CKata.Length; i++) {
			printf("%c", CKata.TabKata[i]);
		}		
		printf("\n");
		ADVKATA();
	}

	printf("\n");

	STARTKATA(filename);
	while (!EndKata) {
		NbKata++;
		LTotal += CKata.Length;
		ADVKATA();
	}
	if (NbKata != 0) {
		printf("\nPanjang rata2 kata yaitu = %d\n", LTotal/NbKata);
	}
	else {
		printf("\nPita tidak mengandung kata!\n");
	}

	STARTKATA(filename);
	while (!EndKata) {
		if (IsKataSama(TempKata, CKata)) {
			NWHILE++;
		}
		ADVKATA();
	}

	printf("jml while = %d\n", NWHILE);

	return 0;
}

boolean IsKataSama(Kata K1, Kata K2) {
	int i;
	if (K1.Length != K2.Length) {
		return false;
	}
	else {
		i = 1;
		while ((i < K1.Length) && (K1.TabKata[i] = K2.TabKata[i])) {
			i++;
		}
		return (K1.TabKata[i] = K2.TabKata[i]);	
	}
}