#include "interface.h"
#include "variable.h"
#include "mesin_kar.h"
#include "matriks.h"
#include "startgame.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "inputCmd.h"
#include "stack.h"
#include "queue.h"

MATRIKS M;
MATRIKS M1;
MATRIKS M2;


void LoadMap1(){
	/* Kamus Lokal */
	int i, j;
	int NB = 9; int NK = 9;


	/* Algoritma */
	MakeMATRIKS(NB,NK,&M1);
	START("load_map1.txt");
	while(!EOP){
		for(i = 1 ; i <= 8 ; i++){
			for(j = 1 ; j <= 8 ; j++){
				Elmt(M1,i,j) = GetCC();
				ADV();
			}
		}
	}
	
	nama(M1,2,9) = "...";
	nama(M1,3,9) = "...";
	nama(M1,4,9) = "...";
	
	
}

void LoadMap2(){
	/* KAMUS LOKAL */
	int i, j;
	int NB = 9; 
	int NK = 9;

	/* ALGORITMA */
	MakeMATRIKS(NB, NK, &M2);

	START("load_map2.txt");
	while (!EOP) {
		for (i = 1; i <= 8; i++) {
			for (j = 1; j <= 8; j++) {
				Elmt(M2, i, j) = GetCC();
				ADV();
			}
		}
	}
	
	no(M2,1,1) = 1;
	nama(M2,1,1) = "Burger Monas";
    harga(M2,1,1)= 200;

	no(M2,2,1) = 2;
    nama(M2,2,1) = "Kentang Parut";
    harga(M2,2,1)= 20;

	no(M2,3,1) = 3;
    nama(M2,3,1) = "Nugget Penyet";
    harga(M2,3,1)= 35;

	no(M2,4,1) = 4;
    nama(M2,4,1) = "Engi's Krim";
    harga(M2,4,1)= 15;

	no(M2,5,1) = 5;
    nama(M2,5,1) = "Nasi Goreng Ngiss";
    harga(M2,5,1)= 100;

    no(M2,6,1) = 6;
    nama(M2,6,1) = "Seblak Ceker";
    harga(M2,6,1)= 15;

	no(M2,7,1) = 7;
    nama(M2,7,1) = "Bitterballen";
    harga(M2,7,1)= 50;

	no(M2,8,1) = 8;
    nama(M2,8,1) = "Fried Unagi";
    harga(M2,8,1)= 100;

	no(M2,5,4) = 9;
    nama(M2,5,4) = "Lasagna";
    harga(M2,5,4)= 100;
    
    no(M2,5,5) = 10;
    nama(M2,5,5) = "Tahu Bulat";
    harga(M2,5,5)= 25;

	no(M2,8,4) = 11;
    nama(M2,8,4) = "Cilok";
    harga(M2,8,4)= 20;

	no(M2,8,5) = 12;
    nama(M2,8,5) = "Go Milk";
    harga(M2,8,5)= 20;

	no(M2,8,6) = 13;
    nama(M2,8,6) = "Green Macchiato";
    harga(M2,8,6)= 50;

	no(M2,8,7) = 14;
    nama(M2,8,7) = "Dumpling Hakao";
    harga(M2,8,7)= 30;

	no(M2,8,8) = 15;
    nama(M2,8,8) = "Surabinasution";
    harga(M2,8,8)= 10;
    
    /*test = (char *) malloc (20 * sizeof(test));
    
    if (InfoTop(FS) == no(M2,8,7)) {
		test = nama(M2,8,7);
	}*/
	
	nama(M2,2,9) = "...";
	nama(M2,3,9) = "...";
	nama(M2,4,9) = "...";
	
	
}


void GameMaps(MATRIKS M){
	
    /* Kamus Lokal */
	
		
    /* Algoritma */
		
printf("\n");
printf("\n");
printf("====================================================================================================\n");
printf("-------------------------------------   Engi's Kitchen V 2.0   -------------------------------------\n");
printf("====================================================================================================\n");
printf(" _____________________ ___________________________ _____________ __________________________________\n");
printf("|");NamePrint(name);printf("     |Money:%s|Life:%s|Time:%s        |",MoneyPrint(money),LifePrint(life),TimePrint(waktu));printf("\n");
printf("|_____________________|___________________________|_____________|__________________________________|\n");
printf("|Waiting Cust         |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |Food Stack          \n",Elmt(M,1,1),Elmt(M,1,2),Elmt(M,1,3),Elmt(M,1,4),Elmt(M,1,5),Elmt(M,1,6),Elmt(M,1,7),Elmt(M,1,8));
//if (cektake && Temp.noMenu == 14) {nama(M,2,9) = "Dumpling Hakao";} else {nama(M,2,9) = "...";}
printf("|%d           	      |______|______|______|______|______|______|______|______|%s                    \n",NOrang(Cust,1), nama(M,2,9));
printf("|           	      |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |                    \n",Elmt(M,2,1),Elmt(M,2,2),Elmt(M,2,3),Elmt(M,2,4),Elmt(M,2,5),Elmt(M,2,6),Elmt(M,2,7),Elmt(M,2,8));
printf("|%d                    |______|______|______|______|______|______|______|______|%s                    \n",NOrang(Cust,2), nama(M,3,9));
printf("|           	      |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |                  \n",Elmt(M,3,1),Elmt(M,3,2),Elmt(M,3,3),Elmt(M,3,4),Elmt(M,3,5),Elmt(M,3,6),Elmt(M,3,7),Elmt(M,3,8));
printf("|%d           	      |______|______|______|______|______|______|______|______|%s                    \n",NOrang(Cust,3), nama(M,4,9));
printf("|           	      |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |                  \n",Elmt(M,4,1),Elmt(M,4,2),Elmt(M,4,3),Elmt(M,4,4),Elmt(M,4,5),Elmt(M,4,6),Elmt(M,4,7),Elmt(M,4,8));
printf("|%d                    |______|______|______|______|______|______|______|______|____________________\n",NOrang(Cust,4));
printf("|         	      |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |Order               \n",Elmt(M,5,1),Elmt(M,5,2),Elmt(M,5,3),Elmt(M,5,4),Elmt(M,5,5),Elmt(M,5,6),Elmt(M,5,7),Elmt(M,5,8));
printf("|                     |______|______|______|______|______|______|______|______|%d,%d                 \n", nomejaorder(TabOrders,1), nomenu(TabOrders,1));
printf("|           	      |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |%d,%d                 \n",Elmt(M,6,1),Elmt(M,6,2),Elmt(M,6,3),Elmt(M,6,4),Elmt(M,6,5),Elmt(M,6,6),Elmt(M,6,7),Elmt(M,6,8), nomejaorder(TabOrders,2), nomenu(TabOrders,2));
printf("|           	      |______|______|______|______|______|______|______|______|%d,%d                 \n", nomejaorder(TabOrders,3), nomenu(TabOrders,3));
printf("|           	      |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |%d,%d                 \n",Elmt(M,7,1),Elmt(M,7,2),Elmt(M,7,3),Elmt(M,7,4),Elmt(M,7,5),Elmt(M,7,6),Elmt(M,7,7),Elmt(M,7,8), nomejaorder(TabOrders,4), nomenu(TabOrders,4));
printf("|           	      |______|______|______|______|______|______|______|______|              \n");
printf("|           	      |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |               \n",Elmt(M,8,1),Elmt(M,8,2),Elmt(M,8,3),Elmt(M,8,4),Elmt(M,8,5),Elmt(M,8,6),Elmt(M,8,7),Elmt(M,8,8));
printf("|_____________________|______|______|______|______|______|______|______|______|____________________\n"); 

}

    
char *LifePrint(int life){
		/* kamus Lokal */
		
		/* Algoritma */
		char *str = malloc(sizeof(char));
	
	if (life<10) {
		sprintf(str, "%d       ",life);
	}
	if ((life>9)&&(life<100)) {
		sprintf(str, "%d      ",life);
	}
	if ((life>99)&&(life<1000)) {
		sprintf(str, "%d     ",life);
	}
	return str;
}  

void NamePrint(char name[100]){
		/* kamus Lokal */
		int x,i,y;
		/* maksimal nama berjumlah 16 karakter*/
		/* Algoritma */
	x = strlen(name);
	y = 16-x;
	printf("%s",name);
	for(i=1;i<=y;i++){
		printf(" ");
	}
} 
 
char *MoneyPrint(int money){
	
	char *str = malloc(sizeof(char));
	
	if (money<10) {
		sprintf(str, "%d                    ",money);
	}
	if ((money>9)&&(money<100)) {
		sprintf(str, "%d                   ",money);
	}
	if ((money>99)&&(money<1000)) {
		sprintf(str, "%d                  ",money);
	}
	if ((money>999)&&(money<10000)) {
		sprintf(str, "%d                 ",money);
	}
	if ((money>9999)&&(money<100000)) {
		sprintf(str, "%d                ",money);
	}
	return str;
}

char *TimePrint(int waktu){
	char *str = malloc(sizeof(char));
	
	if (waktu<10) {
		sprintf(str, "%d                    ",waktu);
	}
	if ((waktu>9)&&(waktu<100)) {
		sprintf(str, "%d                   ",waktu);
	}
	if ((waktu>99)&&(waktu<1000)) {
		sprintf(str, "%d                  ",waktu);
	}
	return str;

}

/*void waitinglist (Queue *Q)
{	
	if (waktu<=10)
	{	if (waktu == pwaktu5)
		{	
			
			NOrang(*Q,IdxWL) = NOrang(Cust,IdxWLC);
			KOrang(*Q,IdxWL) = KOrang(Cust,IdxWLC);
			pwaktu5 += 5;
			IdxWL++;
			IdxWLC++;
		}
	}
	
	if (waktu>10){
		IdxWL=NBElmtQ(*Q);
		
		if (IdxWL <= MaxElQC) {
			if (waktu == pwaktu20){
				NOrang(*Q,IdxWL) = NOrang(Cust,IdxWLC);
				KOrang(*Q,IdxWL) = KOrang(Cust,IdxWLC);
				IdxWL++;
				IdxWLC++;
			}
		}
		
		pwaktu20 += 20;
	}
}*/
