/* Deskripsi     Realisasi/ kode program dari semua prototype yg didefinisikan pada matriks.h */

#include <stdio.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	/* ALGORITMA */
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	/* ALGORITMA */
	return (((BrsMin <= i) && (i <= BrsMax)) && ((KolMin <= j) && (j <= KolMax)));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	/* ALGORITMA */
	return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	/* ALGORITMA */
	return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	/* ALGORITMA */
	return NBrsEff(M);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	/* ALGORITMA */
	return NKolEff(M);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	/* ALGORITMA */
	return (((GetFirstIdxBrs(M) <= i) && (i <= GetLastIdxBrs(M))) && ((GetFirstIdxKol(M) <= j) && (j <= GetLastIdxKol(M))));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	/* ALGORITMA */
	return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
	/* ALGORITMA */
	*MHsl = MIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
	/* KAMUS */
	indeks i, j;

	/* ALGORITMA */
	MakeMATRIKS(NB, NK, M);
	for(i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
	{
		for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
		{
			scanf("%d", &Elmt(*M,i,j));
		}
	}
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	/* KAMUS */
	indeks i, j;

	/* ALGORITMA */
	for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
		{
			printf("%d", Elmt(M,i,j));
			if(j != GetLastIdxKol(M))
			{
				printf(" ");
			}
		}
		if(i != GetLastIdxBrs(M))
		{
			printf("\n");
		}
	}
}



/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetLastIdxBrs(M1) = GetLastIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
	/* KAMUS */
	indeks i, j;
	boolean eq;

	/* ALGORITMA */
	if((GetLastIdxBrs(M1) == GetLastIdxBrs(M2)) && (GetLastIdxKol(M1) == GetLastIdxKol(M2)))
	{
		eq = true;
		i = GetFirstIdxBrs(M1);
		while((i <= GetLastIdxBrs(M1)) && eq)
		{

			j = GetFirstIdxKol(M1);
			while((j <= GetLastIdxKol(M1)) && eq)
			{
				if(Elmt(M1,i,j) != Elmt(M2,i,j))
				{
					eq = false;
				}
				else
				{
					j++;
				}
			}
			if(eq)
			{
				i++;
			}
		}
		return eq;
	}
	else
	{
		return false;
	}
}




/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
	/* ALGORITMA */
	return (NBrsEff(M) * NKolEff(M));
}

