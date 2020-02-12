/* NIM/Nama  : 18217011/David Petra Natanael
   Nama file : mesin_kata.c
   Topik     : Tugas Pra Praktikum 03
   Tanggal   : 25 September 2018 
   Deskripsi : File Body ADT mesin_kata              */



/* Body prototype mesin_kata */

#include <stdio.h>
#include "mesin_kata.h"

/* KAMUS */
boolean EndKata;
Kata CKata;

/* ALGORTIMA */

//{ ***** Primitif-Primitif Mesin Kata ***** }
void Ignore_Blank()
/*{ Mengabaikan satu atau beberapa BLANK }
{ I.S. : CC sembarang }
{ F.S. : CC ? BLANK atau CC = MARK }*/
{
	/* KAMUS LOKAL */


	/* ALGORITMA */
	while ((CC == BLANK) && (CC != MARK)) {
		ADV();
	}
}


void STARTKATA(char* filename)
/*
{ I.S. : CC sembarang }
{ F.S. : EndKata = true, dan CC = Mark; }
{        atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
         CC karakter pertama sesudah karakter terakhir kata } */
{
	/* KAMUS LOKAL */


	/* ALGORITMA */
	START(filename);
	Ignore_Blank();
	if (CC == MARK) {
		EndKata = true;
	}
	else { /* CC != MARK */
		EndKata = false;
		SalinKata();
	}

}


void ADVKATA()
/*
{ I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir 
         dari kata yg sudah diakuisisi }
{ F.S. : Jika CC = MARK, maka EndKata = true
         atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
         CC karakter pertama sesudah karakter terakhir kata } */
{
	/* KAMUS LOKAL */


	/* ALGORITMA */
	Ignore_Blank();
	if (CC == MARK) {
		EndKata = true;
	}
	else { /* CC != MARK */
		SalinKata();
	}
}


void SalinKata()
/*
{ Mengakuisisi kata, menyimpan dalam CKata }
{ I.S. : CC adalah karakter pertama dari kata }
{ F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi 
         NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah 
         karakter sesudah karakter terakhir yang diakuisisi } */
{
	/* KAMUS LOKAL */
	int i = 1;

	/* ALGORITMA */
	for (;;) {
		CKata.TabKata[i] = CC;
		ADV();

		if ((CC == MARK) || (CC == BLANK)) {
			break;
		}
		else {
			i++;
		}
	}
	CKata.Length = i;
 }
