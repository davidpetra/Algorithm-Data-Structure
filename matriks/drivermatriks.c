#include "matriks.h"

#include <stdio.h>



int main (){

// kamus

MATRIKS M1,M2;
int NB, NK;

indeks i, j;

//algoritma

printf("Masukan nilai-nilai efektif matriks : (format \"NB NK\")");

scanf("%d %d", &NB, &NK);

BacaMATRIKS(&M1,NB,NK);

BacaMATRIKS(&M2,NB,NK);
//cek eqivalen
if (EQM(M1,M2)){
    printf("Kedua matriks itu sama\n");
}
else if (EQM(M1,M2)){
    printf("Kedua matriks itu  berbeda\n");
}
//cek nb element matriks
printf("Jumlah elemen kedua matriks masing-masing adalah %d\n", NBElmt(M1));
//cek tulis matriks dan copy matriks
printf("Berikut Matriks kedua: \n");
TulisMATRIKS(M2);
printf("\n");
CopyMATRIKS(M2, &M1);
TulisMATRIKS(M1);

//cel Get first idxbars dan last idx baris sama first idx kol dan last idxkolom
printf("%d adalah contoh dari indeks baris pertama dan %d terakhir", GetFirstIdxBrs(M1), GetLastIdxBrs(M1));
printf("%d adalah contoh dari indeks kolom pertama dan %d terakhir", GetFirstIdxKol(M1), GetLastIdxKol(M1));

printf("Ayo masukin input indeks :");
scanf("%d %d", &i, &j);

//mencek i atau j itu valid
if (!IsIdxValid(i,j)){
    printf("Maaf Indeks tersebut tidak valid\n");
}

if(!IsIdxEff(M1,i,j))
{
    printf("Maaf Indeks tersebut tidak efektif\n");

}

return 0;

}
