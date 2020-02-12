/* Body prototype type array */

#include <stdio.h>
#include <stdlib.h>

#include "array.h"

//KONSTRUKTOR  buat ORder

void MakeEmptyTabOrder (TabOrder * T)
{//membuat empty taborder
	Neff(*T)=0;
}

boolean IsFullTabOrder (TabOrder T)
{//memberikan true kalo Ordernya udah penuh
	return (Neff(T)==IdxMaxOrder);
}

boolean IsEmptyArrTabOrder (TabOrder T)
{// memberikan true kalo ordernya masih kosong

	return (Neff(T)==0);
}

void AddAsLastElTabOrder (TabOrder *T, Order X){
	Neff(*T)++;
	if (IsEmptyArrTabOrder(*T)) {
		ElmtArr(*T,1) = X;
	}
	else {
		ElmtArr(*T,Neff(*T)) = X;
	}
		
}


void tulisorder (TabOrder *T)
{
	IdxType i;
	
	printf("[");
	
	
	if (!(IsEmptyArrTabOrder(*T))) {
		
		for (i=IdxMin; i<=Neff(*T)-1; i++) {
			printf("%d,%d ; ",(*T).TI[i].noMeja,(*T).TI[i].noMenu);
		}
		printf("%d,%d",(*T).TI[i].noMeja,(*T).TI[i].noMenu);
    }
    else {
		for (i=IdxMin; i<=IdxMaxOrder; i++) {
			printf("%d,%d ; ",0,0);
		}
		nomejaorder(*T,1) = 0; 
		nomenu(*T,1) = 0;
	}
	
	printf("]\n");
}


void DelEliTabOrder (TabOrder *T, IdxType i, Order *X)
{//ngedelete element tab di order
  *X = ElmtArr(*T, i);
  IdxType j;
  for(j=i ; j<=Neff(*T)-1; j++){
    ElmtArr(*T,j) = ElmtArr(*T, j+1);
    nomejaorder(*T,j+1) = 0;
    nomenu(*T,j+1) = 0;
  }
  Neff(*T) -= 1;
}

int SearchOrder (TabOrder T, Order X){
//Mencari indeks i dari T yang memiliki elemen tuple X
	if (IsEmptyArrTabOrder(T))
	{
		//Do nothing
	}
	else
	{
		boolean found = false;
		IdxType i=1;
		while (!found && i<=9)
		{
			if ((nomejaorder(T,i) == X.noMeja) && (nomenu(T,i) == X.noMenu))
			{
				found = true;
			}
		    else
		    {
				i++;
		    }
		}
		if (found)
		{
		  return i;
		}
		else
		{
		  return IdxUndef;
		}
	}
}

/* BODY Prototype */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
  Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArr (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
  if (IsEmptyArr(T))
  {
    return 0;
  }
  else
  {
    return Neff(T);
  }
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return IdxMax-IdxMin+1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return IdxMin;
}
int GetLastIdxOrder (TabOrder T)
{
	return Neff(T);
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return GetFirstIdx(T)+Neff(T)-1;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArr (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
  return Neff(T)==0;
}

boolean IsFullArr (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return (GetFirstIdx(T)==IdxMin && GetLastIdx(T)==IdxMax);
}
