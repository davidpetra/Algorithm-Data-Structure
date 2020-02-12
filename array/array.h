
#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"

#define Nol 0
#define IdxMaxOrder 4
//indeks maksimum dari order
#define IdxMax 100
//indeks maksimum dari array
#define IdxMin 1
//indeks minimum dari array
#define IdxUndef -999
/* Indeks tak terdefinisi*/

//definisi type object
typedef int IdxType;  /* type indeks */
typedef int ElType;   /* type elemen tabel */
typedef struct
{
  int noMenu;
  int noMeja;
} Order;

typedef struct {
	ElType TI[IdxMax+1]; /* memori tempat untuk menyimpan elemen itu sendiri */
	int Neff; /* banyak elemen yang aktif */
} TabInt;

typedef struct {
  Order TI[IdxMax+1]; /* memori tempat untuk menyimpan elemen itu sendiri  */
  int Neff; /* banyak elemen yang aktif */
} TabOrder;

/* ********** SELEKTOR ********** */
#define Neff(T)   (T).Neff
#define TI(T)     (T).TI
#define ElmtArr(T,i) (T).TI[(i)]
#define nomejaorder(T,i) (T).TI[(i)].noMeja
#define nomenu(T,i) (T).TI[(i)].noMenu

//KONSTRUKTOR UNTUK ORDER
void MakeEmptyTabOrder (TabOrder * T);
// untuk membuat order menjadi kosong
boolean IsFullTabOrder (TabOrder T);
// mencek apakah order full jika full maka akan menghasilkan true
boolean IsEmptyTabOrder (TabOrder T);
// mencek apakah order kosong jika kosong maka akan dihasilkan true
void AddAsLastElTabOrder (TabOrder * T, Order X);
// untuk menambahkan elemen di order di posisi akhir
void DelEliTabOrder (TabOrder * T, IdxType i, Order * X);
// untuk mendelete elemen di order


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArr (TabInt T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdxOrder (TabOrder T);
IdxType GetLastIdx (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArr (TabInt T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullArr (TabInt T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */

void tulisorder (TabOrder *T);

int SearchOrder (TabOrder T, Order X);
//Mencari indeks i dari T yang memiliki elemen tuple X



#endif
