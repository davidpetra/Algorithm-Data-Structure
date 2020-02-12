#ifndef AREA_H
#define AREA_H

#include <stdio.h>
#include "matriks.h"
#include "queue.h"


/* INTERFACE MAP DALAM GAME */



void GameMaps(MATRIKS M);
char *LifePrint(int life);
char *MoneyPrint(int money);
char *TimePrint(int watku);
void NamePrint(char name[100]);
void LoadMap1();
void LoadMap2();
void waitinglist (Queue *Q);

#endif
