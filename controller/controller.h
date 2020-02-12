#ifndef controller_H
#define controller_H

#include <stdio.h>
#include "boolean.h"
#include "point.h"
#include "matriks.h"
#include "variable.h"
#include "array.h"
#include "stack.h"
#include "queue.h"



//POINT SearchP (MATRIKS M);
//Mencari baris di matriks dan diubah ke Point
int SearchI (MATRIKS M);
int SearchJ (MATRIKS M);
void GU (MATRIKS *M);
//Posisi Pemain berpindah ke atas
void GD (MATRIKS *M);
//Posisi Pemain berpindah ke bawah
void GR (MATRIKS *M);
//Posisi Pemain berpindah ke kanan
void GL (MATRIKS *M);
//Posisi Pemain berpindah ke kiri
boolean cekU (MATRIKS M);
boolean cekD (MATRIKS M);
boolean cekL (MATRIKS M);
boolean cekR (MATRIKS M);


int SearchIC (MATRIKS M); 
int SearchIJ (MATRIKS M);
int searchnomeja (MATRIKS M);
void Ordermakanan (MATRIKS *M);

void CT();
/* Prosedur ketika pemain memilih CT */
/* Membuang seluruh makanan yang berada di dalam tray */

void PLACE();
/* Prosedur ketika pemain memilih PLACE */
/* menaruh pelanggan di meja dan kosong.
Pelanggan yang ditaruh adalah pelanggan pada top of queue */

void GIVE();
/* Prosedur ketika pemain memilih GIVE */
/* Memberikan makanan yang berada di paling atas tumpukan
ke pengunjung yang bertetanggaan */

void Take (MATRIKS M);


void buatqueuewaiting (Queue *Q);
int searchnomejaX (MATRIKS M);
int SearchJX ( MATRIKS M);
	
int SearchIX( MATRIKS M);
void placeCustomer(MATRIKS *M, Queue *Cust2);

#endif
