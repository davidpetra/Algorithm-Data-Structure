/* Nama			: David Petra Natanael */
/* NIM			: 18217011 */
/* Tanggal		: 20 September 2018 */
/* Deskripsi	: Implementasi mesin_kar.h */
/* Nama file	: mesin_kar.c */

#include <stdio.h>
#include "mesin_kar.h"

/* KAMUS */
char CC;
boolean EOP;
static FILE *pita;
static int retval;

/* ALGORITMA */

void START(char* filename)
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
filename merupakan nama file yang berisi pita karakter
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita

Jika CC != MARK maka EOP akan padam (false)
Jika CC = MARK maka EOP akan menyala (true) */
{
    pita = fopen(filename,"r");
    ADV();
}
void ADV()
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,

CC mungkin = MARK
Jika CC = MARK maka EOP akan menyala (true) */
{
    // TODO --> IMPLEMENTASI FUNGSI INI
    retval = fscanf(pita, "%c", &CC);
	EOP = IsEOP();
	if (EOP) { /* Karakter di jendela adalah "." */
		fclose(pita);
	}
}

char GetCC()
/* Mengembalikan karakter yang sedang terbaca di jendela.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : mengembalikan karakter yang sedang terbaca di jendela
*/
{
    // TODO --> IMPLEMENTASI FUNGSI INI
    return (CC);
}

boolean IsEOP()
/* Mengecek apakah pita telah selesai dibaca
I.S. : Pita telah terbaca
F.S. : Menegmbalikan true jika pita telah selesai terbaca, false jika sebaliknya
*/
{
    // TODO --> IMPLEMENTASI FUNGSI INI
    return (CC == MARK);
}
