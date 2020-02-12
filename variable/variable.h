#ifndef VARIABLE_H
#define VARIABLE_H

#include <stdio.h>
#include "array.h"
#include "matriks.h"
#include "point.h"
#include "stack.h"
#include "queue.h"

char name[100];
int money;
int life;
int waktu;
POINT P;
int x,y;
boolean pindah;
int dc,dd;
/*int IdxWL;
int IdxWLC;
int pwaktu5;
int pwaktu20;*/

Order Temp;
TabOrder TabOrders;
int tableno;
int menu;
int idxiM3, idxjM3;
Stack FS;
typedef char *test;

Queue Cust;
Queue Cust2;
extern MATRIKS M;
extern MATRIKS M1;
extern MATRIKS M2;
extern MATRIKS M3;
#endif
