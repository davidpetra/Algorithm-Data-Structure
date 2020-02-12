/* Body prototype queue */
#include <stdio.h>
#include "queue.h"
#include "variable.h"


/* *** Predikat Pemeriksaan Kondisi Queue *** */
boolean IsEmptyQ(Queue Q)
/* Mengirim true jika Q kosong */
{
	/* KAMUS LOKAL */

	/* ALGORITMA */
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));

}


boolean IsFullQ(Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung
MaxEl elemen */
{  int jumlah;
	jumlah = (Tail(Q))-(Head(Q))+1;
	return (jumlah == MaxElQC);

}


int NBElmtQ(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	/* KAMUS LOKAL */

	/* ALGORITMA */
	if (IsEmptyQ(Q)) {
		return 0;
	}
	else {
		return (Tail(Q) - Head(Q) + 1);
	}

}


/* *** Konstruktor *** */
void CreateEmptyQ(Queue *Q)
{
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
}




/* *** Operator-Operator Dasar Queue *** */
void AddQ (Queue *Q,infotype X)
{/* KAMUS LOKAL */
int idx;
	/* ALGORITMA */
	if (IsEmptyQ(*Q)) {
		Head(*Q) = 1;
		Tail(*Q) = 1;
		idx = Tail(*Q);
		(*Q).Customer[idx].Jumlahorang = X;
		(*Q).Customer[idx].Kesabaran = 30;
	}
	else {
		Head(*Q) = 1;
		Tail(*Q) = NBElmtQ(*Q);
		
		Tail(*Q)++;
		idx = Tail(*Q);
		(*Q).Customer[idx].Jumlahorang = X;
		(*Q).Customer[idx].Kesabaran = 30;
	}
}

void DeleteQC (Queue *Q, infotype *X)
{//mendelete costumer di waiting list yang kesabarannya sudah mencapai nilai 0
 //dan mengurangi kesabaran customer di antrian
	int i;
	
	if ((InfoHeadK(*Q)==0)&&(!IsEmptyQ(*Q))) {
		DelQ(Q,X);
		life--;
		if (Head(*Q) != Tail(*Q)){
			for (i=Head(*Q);i<=Tail(*Q);i++)
			{
				KOrang((*Q),i)--;
			}
		}
		
		if (NMOrang(*Q,1)==1){
			Elmt(M1,1,2) = 'X';
			Elmt(M1,2,1) = 'X';
			Elmt(M1,2,3) = 'X';
			Elmt(M1,3,2) = 'X';
		}
		else if (NMOrang(*Q,1) == 2) {
			Elmt(M1,2,6) = 'X';
			Elmt(M1,2,8) = 'X';
		}
		else if (NMOrang(*Q,1) == 3) {
			Elmt(M1,6,2) = 'X';
			Elmt(M1,7,1) = 'X';
			Elmt(M1,7,3) = 'X';
			Elmt(M1,8,2) = 'X';
		}
		else if (NMOrang(*Q,1) == 4) {
			Elmt(M1,7,6) = 'X';
			Elmt(M1,7,8) = 'X';
		}
	}
	else {
		for (i=Head(*Q);i<=Tail(*Q);i++)
		{
			KOrang((*Q),i)--;
		}
	}
	
	/*if ( Head(*Q) == Tail (*Q))
	{
		if (InfoHeadK(*Q)==0)
		DelQ(Q,X);
	}
	else // lebih dari 1 elemen isi dari si queue waitingnya
	{
		for (i=Head(*Q);i<=Tail(*Q);i++)
		{
			if (InfoHeadK(*Q)==0){
				DelQ(Q,X);
				Head(*Q)++;
			}
		}
	}*/
}

void DelQ(Queue *Q,infotype *X)
/* Proses: Menghapus elemen pertama pada Q dengan aturan FIFO
   I.S. Q tidak kosong
   F.S. X = nilai elemen HEAD pada I.S.,
        Jika Queue masih isi : HEAD diset tetap = 1, elemen-elemen setelah
        HEAD yang lama digeser ke "kiri", TAIL = TAIL � 1;
        Jika Queue menjadi kosong, HEAD = TAIL = Nil. */
{
	/* ALGORITMA */
	int idx;
	*X = Head(*Q);
	
	if (NBElmtQ(*Q) == 1) {
		InfoHead(*Q) = Nil;
		InfoHeadK(*Q) = Nil;
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}
	else {
		Tail(*Q) = NBElmtQ(*Q);
		for (idx = 1; idx <= (Tail(*Q) - Head(*Q)); idx++) {
			(*Q).Customer[idx] = (*Q).Customer[idx+1];
		}
		InfoTail(*Q) = Nil;
		InfoTailK(*Q) = Nil;
		Tail(*Q)--;
		Head(*Q) = 1;
	}

}



