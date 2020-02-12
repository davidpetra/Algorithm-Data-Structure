/* Modul ADT Queue � Alternatif I */
/* *** Deklarasi Queue yang diimplementasi dengan tabel kontigu *** */
/* *** HEAD dan TAIL adalah alamat elemen pertama dan terakhir *** */
/* *** Queue mampu menampung MaxEl buah elemen *** */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "boolean.h"
#include <stdlib.h>

/* *** konstanta *** */
#define Nil 0
/* Definisi elemen dan address */
#define MaxElQC 4  /* Max Pelanggan di waiting customer */


/* *** Definisi elemen dan address *** */
typedef int infotype;
typedef int address; /* indeks tabel */

/* *** Definisi Type Queue *** */
/* Deklarasi variabel bertype Queue : */


/* *** Definisi Type Queue *** */
/* Deklarasi variabel bertype Queue : */

typedef struct {
	int Kesabaran;
	int Jumlahorang;
	int NoMeja;
} TypeCustomer;

typedef struct
{   
    TypeCustomer Customer[MaxElQC+1];   /* tabel penyimpan elemen */
    address HEAD;
    address TAIL;
}   Queue;

/* Definisi Queue kosong: Head = Nil; TAIL = Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* Definisi akses dengan Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).Customer[(Q).HEAD].Jumlahorang
#define InfoTail(Q) (Q).Customer[(Q).TAIL].Jumlahorang
#define InfoHeadK(Q) (Q).Customer[(Q).HEAD].Kesabaran
#define InfoTailK(Q) (Q).Customer[(Q).TAIL].Kesabaran
#define InfoTailNM(Q) (Q).Customer[(Q).TAIL].NoMeja
#define MaxElQ(Q) (Q).MaxElQC
#define NOrang(Q,i) (Q).Customer[(i)].Jumlahorang
#define KOrang(Q,i) (Q).Customer[(i)].Kesabaran
#define NMOrang(Q,i) (Q).Customer[(i)].NoMeja

/* *** Predikat Pemeriksaan Kondisi Queue *** */
boolean IsEmptyQ(Queue Q);
/* Mengirim true jika Q kosong */
boolean IsFullQ(Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung
MaxEl elemen */
int NBElmtQ(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Konstruktor *** */
void CreateEmptyQ(Queue *Q);
/* I.S. Max terdefinisi }
   F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb :
   Jika alokasi berhasil, tabel memori dialokasi berukuran Max
   atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0
   Proses : Melakukan alokasi memori dan membuat sebuah Q kosong */

/* *** Destruktor *** */
/* *** Operator-Operator Dasar Queue *** */
void AddQ(Queue *Q,infotype X);
/* Proses : Menambahkan X pada Q dengan aturan FIFO
   I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh
   F.S. X menjadi TAIL yang baru, TAIL "maju" */
void DelQ(Queue *Q,infotype *X);
/* Proses: Menghapus elemen pertama pada Q dengan aturan FIFO
   I.S. Q tidak kosong
   F.S. X = nilai elemen HEAD pada I.S.,
        Jika Queue masih isi : HEAD diset tetap = 1, elemen-elemen setelah
        HEAD yang lama digeser ke "kiri", TAIL = TAIL � 1;
        Jika Queue menjadi kosong, HEAD = TAIL = Nil. */
        
void DeleteQC (Queue *Q, infotype *X);        

#endif // __QUEUE_H__
