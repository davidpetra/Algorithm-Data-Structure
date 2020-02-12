#include "exit.h"
#include "menu.h"
#include "mesin_kar.h"
#include "mesin_kata.h"
#include "credit.h"

void EXIT() {
/* Prosedur ketika pemain memilih Exit */
/* Menampilkan credit dan kembali ke main menu game */
	/* KAMUS LOKAL */

    /* ALGORITMA */
	CREDIT();

	if (CKata.TabKata[0] == 'E' &&
		CKata.TabKata[1] == 'X' &&
		CKata.TabKata[2] == 'I' &&
		CKata.TabKata[3] == 'T' ) {
		pilihMenu();
	}
}
