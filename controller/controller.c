#include "controller.h"
#include "ranOrder.h"
#include "startgame.h"


int SearchI ( MATRIKS M){
	/* kamus lokal */
	int i, j;
	int out;
	/* algoritma */

	i = 1; j = 1;
	
		for (i=1; i<= 8; i++){
			for(j=1;j<=8;j++){
				if(Elmt(M,i,j) == 'P'){
					out = i;
					break;
				}
			}
		}
	return out;
}

int SearchJ ( MATRIKS M){
	/* kamus lokal */
	int i, j;
	int out;
	/* algoritma */

	i = 1; j = 1;
	
		for (i=1; i<= 8; i++){
			for(j=1;j<=8;j++){
				if(Elmt(M,i,j) == 'P'){
					out = j;
					break;
				}
			}
		}
	return out;
}

/* MENU INTERFACE START */
void GU (MATRIKS *M)
{//posisi pemain berpindah satu ke atas
	//kamus
	//POINT P;
	//Algoritma
	
	x = SearchI(*M);
	y = SearchJ(*M);
	
	if (cekU(*M)) {
		printf(" > Silakan coba arah lain, disini ada halangan!\n");	
	}
	else {
		if (x == 8 && y == 5) {
			Elmt(*M,x,y) = 'D';
			//P = NextYU(P);
			Elmt(*M,x-1,y) = 'P';
		}
		else {
			Elmt(*M,x,y) = ' ';
			//P = NextYU(P);
			Elmt(*M,x-1,y) = 'P';
		}
		waktu++;
		DeleteQC(&Cust,&dc);
		DeleteQC(&Cust2,&dd);
	}
	
}

void GD (MATRIKS *M)
{
	//posisi pemain berpindah satu ke bawah
	//kamus
	//POINT P;
	//Algoritma
	//P = SearchP(M);
	x = SearchI(*M);
	y = SearchJ(*M);


	if (cekD(*M)) {
		printf(" > Silakan coba arah lain, disini ada halangan!\n");
	}
	else {
		if (pindah && x == 1 && y == 5) {
			Elmt(*M,x,y) = 'D';
			//P = NextYU(P);
			Elmt(*M,x+1,y) = 'P';
		}
		else {
			Elmt(*M,x,y) = ' ';
			//P = NextYD(P);
			Elmt(*M,x+1,y) = 'P';
		}
		waktu++;
		DeleteQC(&Cust,&dc);
		DeleteQC(&Cust2,&dd);
	}
}


void GR (MATRIKS *M)
{//posisi pemain berpindah satu ke kanan
	
	//POINT P;
	
	//P = SearchP(M);
	x = SearchI(*M);
	y = SearchJ(*M);
	if (cekR(*M)) {
		printf(" > Silakan coba arah lain, disini ada halangan!\n");	
	}
	else {
		if (x == 8 && y == 5) {
				Elmt(*M,x,y) = 'D';
				//P = NextXR(P);
				Elmt(*M,x,y+1) = 'P';
		}
		else {
			if (pindah && x == 1 && y == 5) {
				Elmt(*M,x,y) = 'D';
				//P = NextYU(P);
				Elmt(*M,x,y+1) = 'P';
			}
			else {
				Elmt(*M,x,y) = ' ';
				//P = NextXR(P);
				Elmt(*M,x,y+1) = 'P';
			}
		}
		waktu++;
		DeleteQC(&Cust,&dc);
		DeleteQC(&Cust2,&dd);
	}
}

void GL (MATRIKS *M)
{//posisi pemain berpindah satu ke kiri
	//POINT P;
	x = SearchI(*M);
	y = SearchJ(*M);
	if (cekL(*M)) {
		printf(" > Silakan coba arah lain, disini ada halangan!\n");
	}
	else {
		if (x == 8 && y == 5) {
			Elmt(*M,x,y) = 'D';
			//P = NextXL(P);
			Elmt(*M,x,y-1) = 'P';
		}
		else {
			if (pindah && x == 1 && y == 5) {
				Elmt(*M,x,y) = 'D';
				//P = NextYU(P);
				Elmt(*M,x,y-1) = 'P';
			}
			else {
				//P = SearchP(M);
				Elmt(*M,x,y) = ' ';
				//P = NextXL(P);
				Elmt(*M,x,y-1) = 'P';
			}
		}
		
		waktu++;
		DeleteQC(&Cust,&dc);
		DeleteQC(&Cust2,&dd);
		}
	}


boolean cekU (MATRIKS M) {
	x = SearchI(M);
	y = SearchJ(M);
	
	return ((Elmt(M,x-1,y) == 'C' || Elmt(M,x-1,y) == 'X' || Elmt(M,x-1,y) == '2' || Elmt(M,x-1,y) == '4' || Elmt(M,x-1,y) == 'M') || x == 1);
	
}

boolean cekD (MATRIKS M) {
	x = SearchI(M);
	y = SearchJ(M);
	
	return ((Elmt(M,x+1,y) == 'C' || Elmt(M,x+1,y) == 'X' || Elmt(M,x+1,y) == '2' || Elmt(M,x+1,y) == '4' || Elmt(M,x+1,y) == 'M') || x == 8);
	
}

boolean cekL (MATRIKS M) {
	x = SearchI(M);
	y = SearchJ(M);
	
	return ((Elmt(M,x,y-1) == 'C' || Elmt(M,x,y-1) == 'X' || Elmt(M,x,y-1) == 'M') || y == 1);
	
}

boolean cekR (MATRIKS M) {
	x = SearchI(M);
	y = SearchJ(M);
	
	return ((Elmt(M,x,y+1) == 'C' || Elmt(M,x,y+1) == 'X' || Elmt(M,x,y+1) == 'M') || y == 8);
	
}

int SearchIC ( MATRIKS M){
	/* kamus lokal */
	int i, j;
	int out;
	/* algoritma */

	i = 1; j = 1;
	
		for (i=1; i<= 8; i++){
			for(j=1;j<=8;j++){
				if((Elmt(M,i,j) == 'P')&&((Elmt(M,i,j+1)=='C')||(Elmt(M,i,j-1)=='C')||(Elmt(M,i+1,j)=='C')||(Elmt(M,i-1,j)=='C')))
				{
					out = i;
					break;
				}
			}
		}
	return out;
}
int SearchJC ( MATRIKS M){
	/* kamus lokal */
	int i, j;
	int out;
	/* algoritma */

	i = 1; j = 1;
	
		for (i=1; i<= 8; i++){
			for(j=1;j<=8;j++){
				if((Elmt(M,i,j) == 'P')&&((Elmt(M,i,j+1)=='C')||(Elmt(M,i,j-1)=='C')||(Elmt(M,i+1,j)=='C')||(Elmt(M,i-1,j)=='C'))){
					out = j;
					break;
				}
			}
		}
	return out;
}

int searchnomeja (MATRIKS M)
{
	int out;
	x = SearchIC (M);//cari i dari posisi costumer yang akan di order
	y = SearchJC (M);
	if ((Elmt(M,x,y+2)=='1')||(Elmt(M,x,y-2)=='1')||(Elmt(M,x+2,y)=='1')||(Elmt(M,x-2,y)=='1')||(Elmt(M,x+1,y+1)=='1')|| (Elmt(M,x-1,y-1)=='1')||(Elmt(M,x-1,y+1)=='1')||(Elmt(M,x+1,y-1)=='1'))
   		out = 1;
	else if  ((Elmt(M,x,y+2)=='2')||(Elmt(M,x,y-2)=='2')||(Elmt(M,x+2,y)=='2')||(Elmt(M,x-2,y)=='2')||(Elmt(M,x+1,y+1)=='2')|| (Elmt(M,x-1,y-1)=='2')||(Elmt(M,x-1,y+1)=='2')||(Elmt(M,x+1,y-1)=='2'))
		out = 2;
	else if  ((Elmt(M,x,y+2)=='3')||(Elmt(M,x,y-2)=='3')||(Elmt(M,x+2,y)=='3')||(Elmt(M,x-2,y)=='3')||(Elmt(M,x+1,y+1)=='3')|| (Elmt(M,x-1,y-1)=='3')||(Elmt(M,x-1,y+1)=='3')||(Elmt(M,x+1,y-1)=='3'))
		out = 3;
	else if  ((Elmt(M,x,y+2)=='4')||(Elmt(M,x,y-2)=='4')||(Elmt(M,x+2,y)=='4')||(Elmt(M,x-2,y)=='4')||(Elmt(M,x+1,y+1)=='4')|| (Elmt(M,x-1,y-1)=='4')||(Elmt(M,x-1,y+1)=='4')||(Elmt(M,x+1,y-1)=='4'))
		out = 4;	
		
	return out;
}

void Ordermakanan (MATRIKS *M)
{	
	
    //int tableno=0;
    int i,j;
    boolean cek = false;
    //int menu;
    
    if (!IsFullTabOrder(TabOrders))
    {
        while (!cek)
        {
			i = SearchI(*M);
			j = SearchJ(*M);
			if ((Elmt(*M,i,j+1)== 'C')||(Elmt(*M,i,j-1)== 'C')||(Elmt(*M,i+1,j)== 'C')||(Elmt(*M,i-1,j)== 'C'))
			{ 
				tableno = searchnomeja(*M);
				cek = true;
			}
			else 
			{
				tableno = 0;
				break;
			}
        }
        
        if (!cek)
        {
            printf("Tidak ada customer disini!\n");
        }
        else
        {
            menu = (rand() % (15 + 1 - 1) + 1); //Jumlah makanan ada 1..15 --> rand() % (max_number + 1 - minimum_number) + minimum_number
			
			for(i=1;i<=Tail(Cust2);i++){
				if (NMOrang(Cust2,i)==tableno){
					KOrang(Cust2,i)=30;
				}
			}
			
            Temp.noMeja = tableno;
            Temp.noMenu = menu;
            
            AddAsLastElTabOrder(&TabOrders,Temp);
            
            printf("Order berhasil!\n");
            waktu++;
            InfoHeadK(Cust)=30;
            printf("Nomor meja customer : %d\n", Temp.noMeja); 
            printf("Customer memilih Menu : %d\n", Temp.noMenu);
            printf("Menu %d adalah : ", Temp.noMenu);
            
            if (Temp.noMenu == 1) {
				idxiM3 = 1;
				idxjM3 = 1;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma1);
			}
			else if (Temp.noMenu == 2) {
				idxiM3 = 2;
				idxjM3 = 1;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma2);
			}
			else if (Temp.noMenu == 3) {
				idxiM3 = 3;
				idxjM3 = 1;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma3);
			}
			else if (Temp.noMenu == 4) {
				idxiM3 = 4;
				idxjM3 = 1;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma4);
			}
			else if (Temp.noMenu == 5) {
				idxiM3 = 5;
				idxjM3 = 1;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma5);
			}
			else if (Temp.noMenu == 6) {
				idxiM3 = 6;
				idxjM3 = 1;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma6);
			}
			else if (Temp.noMenu == 7) {
				idxiM3 = 7;
				idxjM3 = 1;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma7);
			}
			else if (Temp.noMenu == 8) {
				idxiM3 = 8;
				idxjM3 = 1;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma8);
			}
			else if (Temp.noMenu == 9) {
				idxiM3 = 5;
				idxjM3 = 4;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma9);
			}
			else if (Temp.noMenu == 10) {
				idxiM3 = 5;
				idxjM3 = 5;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma9);
			}
			else if (Temp.noMenu == 11) {
				idxiM3 = 8;
				idxjM3 = 4;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma9);
			}
			else if (Temp.noMenu == 12) {
				idxiM3 = 8;
				idxjM3 = 5;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma9);
			}
			else if (Temp.noMenu == 13) {
				idxiM3 = 8;
				idxjM3 = 6;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma9);
			}
			else if (Temp.noMenu == 14) {
				idxiM3 = 8;
				idxjM3 = 7;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma9);
			}
			else if (Temp.noMenu == 15) {
				idxiM3 = 8;
				idxjM3 = 8;
				printf("%s\n", nama(M2,idxiM3,idxjM3));
				//printf("%s\n", Ma9);
			}
			DeleteQC(&Cust,&dc);
			
        } 
    }
    else
    {
        printf("Order sudah penuh, orderan tidak berhasil diambil!\n");
    }
}


void Take (MATRIKS M)
{	int i,j;
	MATRIKS Temp;
	
	i = SearchI(M);
	j = SearchJ(M);
    /*kondisi hand penuh*/
    if (IsFullStack(FS))
    {
        printf("Food Stack penuh!\n");
    }
    else
    {
        if(Elmt(M,i+1,j)=='M') //MEJA ADA DI KANAN PEMAIN
        {
            /*Memasukkan bahan ke Tray*/
            no(Temp,i,j) = no(M,i+1,j);
            Push(&FS,no(Temp,i,j));
            printf("Bahan berhasil ditambahkan ke hand.\n");
            TulisStack(FS);
            waktu++;
			DeleteQC(&Cust,&dc);
            
        }
        else if (Elmt(M,i-1,j) =='M') //MEJA ADA DI KIRI PEMAIN
        {
            /*Memasukkan bahan ke Tray*/
            no(Temp,i,j) = no(M,i-1,j);
            Push(&FS,no(Temp,i,j));
            printf("Bahan berhasil ditambahkan ke hand.\n");
            TulisStack(FS);
            waktu++;
            DeleteQC(&Cust,&dc);

        }
        else if (Elmt(M,i,j+1)=='M') //MEJA ADA DI ATAS PEMAIN
        {
            /*Memasukkan bahan ke Tray*/
            no(Temp,i,j) = no(M,i,j+1);
            Push(&FS,no(Temp,i,j));
            printf("Bahan berhasil ditambahkan ke hand.\n");
            TulisStack(FS);
            waktu++;
            DeleteQC(&Cust,&dc);

        }
        else if (Elmt(M,i,j-1)=='M')//MEJA ADA DI BAWAH PEMAIN
        {
            /*Memasukkan bahan ke Tray*/
            no(Temp,i,j) = no(M,i,j-1);
            Push(&FS,no(Temp,i,j));
            printf("Bahan berhasil ditambahkan ke hand.\n");
            TulisStack(FS);
            waktu++;
			DeleteQC(&Cust,&dc);
        }
        else
        {
            printf("Meja tidak ditemukan!\n");
            
        }
        
        
        
    }
}


void CT(){
/* Prosedur ketika pemain memilih CT */
/* Membuang seluruh makanan yang berada di dalam tray */
    //Kamus
	infotype X;

    //Algoritma
        
    if (IsEmptyStack(FS)) {
		printf("Food Stack kosong\n");
	}
	else {
		while (Top(FS) != Nil) {
			Pop(&FS, &X);
		}
		nama(M1,2,9) = "...";
		nama(M1,3,9) = "...";
		nama(M1,4,9) = "...";
		nama(M2,2,9) = "...";
		nama(M2,3,9) = "...";
		nama(M2,4,9) = "...";
		printf("Makanan pada tray berhasil dibuang!\n");
	}
	
	waktu++;
	DeleteQC(&Cust,&dc);
}


void GIVE(MATRIKS *M){
/* Prosedur ketika pemain memilih GIVE */
/* Memberikan makanan yang berada di paling atas tumpukan
ke pengunjung yang bertetanggaan */
    //Kamus
    infotype X;
    int i,j; //IdxO untuk index array TabOrders
    boolean cek = false;

    //Algoritma
    if (!IsEmptyStack(FS)) {
        while (!cek){
			i = SearchI(*M);
			j = SearchJ(*M);
			if ((Elmt(*M,i,j+1)== 'C')||(Elmt(*M,i,j-1)== 'C')||(Elmt(*M,i+1,j)== 'C')||(Elmt(*M,i-1,j)== 'C'))
			{ 
				tableno = searchnomeja(*M);
				cek = true;
			}
			else 
			{
				tableno = 0;
				break;
			}
        }
        
        if (!cek)
        {
            printf("Tidak ada customer disini!\n");
        }
        else
        {
			printf("%d\n", InfoTop(FS));
            
			if ((InfoTop(FS) == nomenu(TabOrders,1)) && tableno == nomejaorder(TabOrders,1)) {
				Pop(&FS, &X);
				DeleteQC(&Cust,&dc);
				TulisStack(FS);
				waktu++;
				tulisorder(&TabOrders);
				DelEliTabOrder(&TabOrders, 1, &Temp);
				tulisorder(&TabOrders);
				
				printf("Makanan berhasil diberikan kepada customer!\n");
				
				
				if (Temp.noMenu == 1) {
					idxiM3 = 1;
					idxjM3 = 1;
					money += harga(M2,idxiM3,idxjM3);
					
					//printf("%s\n", Ma1);
				}
				else if (Temp.noMenu == 2) {
					idxiM3 = 2;
					idxjM3 = 1;
					money += harga(M2,idxiM3,idxjM3);
					//printf("%s\n", Ma2);
				}
				else if (Temp.noMenu == 3) {
					idxiM3 = 3;
					idxjM3 = 1;
					money += harga(M2,idxiM3,idxjM3);
					//printf("%s\n", Ma3);
				}
				else if (Temp.noMenu == 4) {
					idxiM3 = 4;
					idxjM3 = 1;
					money += harga(M2,idxiM3,idxjM3);
					//printf("%s\n", Ma4);
				}
				else if (Temp.noMenu == 5) {
					idxiM3 = 5;
					idxjM3 = 1;
					money += harga(M2,idxiM3,idxjM3);
					//printf("%s\n", Ma5);
				}
				else if (Temp.noMenu == 6) {
					idxiM3 = 6;
					idxjM3 = 1;
					money += harga(M2,idxiM3,idxjM3);
					//printf("%s\n", Ma6);
				}
				else if (Temp.noMenu == 7) {
					idxiM3 = 7;
					idxjM3 = 1;
					money += harga(M2,idxiM3,idxjM3);
					//printf("%s\n", Ma7);
				}
				else if (Temp.noMenu == 8) {
					idxiM3 = 8;
					idxjM3 = 1;
					money += harga(M2,idxiM3,idxjM3);
					//printf("%s\n", Ma8);
				}
				else if (Temp.noMenu == 9) {
					idxiM3 = 5;
					idxjM3 = 4;
					money += harga(M2,idxiM3,idxjM3);
					//printf("%s\n", Ma9);
				}
				else if (Temp.noMenu == 10) {
					idxiM3 = 5;
					idxjM3 = 5;
					money += harga(M2,idxiM3,idxjM3);
					//printf("%s\n", Ma9);
				}
				else if (Temp.noMenu == 11) {
					idxiM3 = 8;
					idxjM3 = 4;
					money += harga(M2,idxiM3,idxjM3);
					//printf("%s\n", Ma9);
				}
				else if (Temp.noMenu == 12) {
					idxiM3 = 8;
					idxjM3 = 5;
					money += harga(M2,idxiM3,idxjM3);
					//printf("%s\n", Ma9);
				}
				else if (Temp.noMenu == 13) {
					idxiM3 = 8;
					idxjM3 = 6;
					money += harga(M2,idxiM3,idxjM3);
					//printf("%s\n", Ma9);
				}
				else if (Temp.noMenu == 14) {
					idxiM3 = 8;
					idxjM3 = 7;
					money += harga(M2,idxiM3,idxjM3);
					
					//printf("%s\n", Ma9);
				}
				else if (Temp.noMenu == 15) {
					idxiM3 = 8;
					idxjM3 = 8;
					money += harga(M2,idxiM3,idxjM3);
					//printf("%s\n", Ma9);
				}
				
				/* Meja 1(4):(1,2),(2,1)(2,3),(3,2)
				   Meja 2(2):(2,6),(2,8)
				   Meja 3(4):(6,2),(7,1)(7,3),(8,2)
				   Meja 4(2):(7,6),(7,8)
				*/
				if (tableno == 1) {
					Elmt(M1,1,2) = 'X';
					Elmt(M1,2,1) = 'X';
					Elmt(M1,2,3) = 'X';
					Elmt(M1,3,2) = 'X';
				}
				else if (tableno == 2) {
					Elmt(M1,2,6) = 'X';
					Elmt(M1,2,8) = 'X';
				}
				else if (tableno == 3) {
					Elmt(M1,6,2) = 'X';
					Elmt(M1,7,1) = 'X';
					Elmt(M1,7,3) = 'X';
					Elmt(M1,8,2) = 'X';
				}
				else if (tableno == 4) {
					Elmt(M1,7,6) = 'X';
					Elmt(M1,7,8) = 'X';
				}
			}
			else {
				printf("Customer tidak memesan menu ini!\n");
				TulisStack(FS);
			} 
		}
	}
    else {
		printf("Tidak ada makanan di dalam Food Stack!\n");
	}
    
    
}

  
int SearchIX( MATRIKS M){
	/* kamus lokal */
	int i, j;
	int out;
	/* algoritma */

	i = 1; j = 1;
	
		for (i=1; i<= 8; i++){
			for(j=1;j<=8;j++){
				if((Elmt(M,i,j) == 'P')&&((Elmt(M,i,j+1)=='X')||(Elmt(M,i,j-1)=='X')||(Elmt(M,i+1,j)=='X')||(Elmt(M,i-1,j)=='X')))
				{
					out = i;
					break;
				}
			}
		}
	return out;
}

int SearchJX ( MATRIKS M){
	/* kamus lokal */
	int i, j;
	int out;
	/* algoritma */

	i = 1; j = 1;
	
		for (i=1; i<= 8; i++){
			for(j=1;j<=8;j++){
				if((Elmt(M,i,j) == 'P')&&((Elmt(M,i,j+1)=='X')||(Elmt(M,i,j-1)=='X')||(Elmt(M,i+1,j)=='X')||(Elmt(M,i-1,j)=='X'))){
					out = j;
					break;
				}
			}
		}
	return out;
}

int searchnomejaX (MATRIKS M)
{
	int out;
	x = SearchI (M);//cari i dari posisi costumer yang akan di order
	y = SearchJ (M);
	if ((Elmt(M,x,y+2)=='1')||(Elmt(M,x,y-2)=='1')||(Elmt(M,x+2,y)=='1')||(Elmt(M,x-2,y)=='1')||(Elmt(M,x+1,y+1)=='1')|| (Elmt(M,x-1,y-1)=='1')||(Elmt(M,x-1,y+1)=='1')||(Elmt(M,x+1,y-1)=='1'))
   		out = 1;
	else if  ((Elmt(M,x,y+2)=='2')||(Elmt(M,x,y-2)=='2')||(Elmt(M,x+2,y)=='2')||(Elmt(M,x-2,y)=='2')||(Elmt(M,x+1,y+1)=='2')|| (Elmt(M,x-1,y-1)=='2')||(Elmt(M,x-1,y+1)=='2')||(Elmt(M,x+1,y-1)=='2'))
		out = 2;
	else if  ((Elmt(M,x,y+2)=='3')||(Elmt(M,x,y-2)=='3')||(Elmt(M,x+2,y)=='3')||(Elmt(M,x-2,y)=='3')||(Elmt(M,x+1,y+1)=='3')|| (Elmt(M,x-1,y-1)=='3')||(Elmt(M,x-1,y+1)=='3')||(Elmt(M,x+1,y-1)=='3'))
		out = 3;
	else if  ((Elmt(M,x,y+2)=='4')||(Elmt(M,x,y-2)=='4')||(Elmt(M,x+2,y)=='4')||(Elmt(M,x-2,y)=='4')||(Elmt(M,x+1,y+1)=='4')|| (Elmt(M,x-1,y-1)=='4')||(Elmt(M,x-1,y+1)=='4')||(Elmt(M,x+1,y-1)=='4'))
		out = 4;	
		
	return out;
}

void buatqueuewaiting (Queue *Cust)
{
	/* Kamus Lokal */
	int n;
	/* Algoritma */
		//CreateEmptyQ(Cust);
	//buat bentuk random nomor nanti isi dari random nomor ini adalah 2 dan 4 -> jumlah customer
	//c =1 ;
	
	if (waktu == 2) {
		n = rand() % 2 + 1;
		if(n == 2)
		{
			AddQ((Cust),4);
		}
		else if(n == 1)
		{
			AddQ((Cust),2);
		}
	}
	else {
		n = rand() % 2 + 1;
		if((n == 2)&&(waktu %10 == 0))
		{
			AddQ((Cust),4);
		}
		else if((n == 1)&& (waktu %10 == 0))
		{
			AddQ((Cust),2);
		}
	}
}

void placeCustomer(MATRIKS *M,Queue *Cust2)
/*I.S. Player berada di manapun. Tabel QWaitingC mungkin kosong
F.S. apabila memenuhi, Tabel QSeatedC bertambah satu elemennya dan QWaitingC berkurang satu elemennya. Kesabaran customer bertambah secara random. Failed jika player berada jauh. Customer di meja bersangkutan belum melakukan order*/
{
    int tableno=0;
    int i =1,j=1;
    boolean cek = false;
    if (!IsEmptyQ(Cust))
    {
        while (!cek)
        {
			i = SearchI(*M);
			j = SearchJ(*M);
			tableno = searchnomejaX(*M);
			if ((Elmt(*M,i,j+1)== 'X')||(Elmt(*M,i,j-1)== 'X')||(Elmt(*M,i+1,j)== 'X')||(Elmt(*M,i-1,j)== 'X'))
			{ 
				
				cek = true;
				if (tableno == 3)
				{
					if (Cust.Customer[Head(Cust)].Jumlahorang == 4)
					{printf ("CUKUP");
						Elmt(M1,7,1) = 'C';
						Elmt(M1,7,3) = 'C';
						Elmt(M1,6,2) = 'C';
						Elmt(M1,8,2) = 'C';
						waktu++;
						
						cek = true;
						AddQ((Cust2),4);
						InfoTailNM(*Cust2) = 3;
						DelQ(&Cust,&Head(Cust));
						DeleteQC(&Cust,&dc);
						}
					else if (Cust.Customer[Head(Cust)].Jumlahorang == 2)
					{printf ("CUKUP");
						Elmt(M1,7,1) = 'C';
						Elmt(M1,7,3) = 'C';
						AddQ((Cust2),2);
						InfoTailNM(*Cust2) = 3;
						DelQ(&Cust,&Head(Cust));
						DeleteQC(&Cust,&dc);
						waktu++;
						cek = true;
					}
				}
				else if (tableno == 1)
				{
					if (Cust.Customer[Head(Cust)].Jumlahorang == 4)
					{printf ("CUKUP");
						Elmt(M1,2,1) = 'C';
						Elmt(M1,2,3) = 'C';
						Elmt(M1,1,2) = 'C';
						Elmt(M1,3,2) = 'C';
						AddQ((Cust2),4);
						InfoTailNM(*Cust2) = 1;
						DelQ(&Cust,&Head(Cust));
						DeleteQC(&Cust,&dc);
						waktu++;
						cek = true;
						}
					else if (Cust.Customer[Head(Cust)].Jumlahorang == 2)
					{printf ("CUKUP");
						Elmt(M1,2,1) = 'C';
						Elmt(M1,2,3) = 'C';
						AddQ((Cust2),2);
						InfoTailNM(*Cust2) = 1;
						DelQ(&Cust,&Head(Cust));
						DeleteQC(&Cust,&dc);
						waktu++;
						
						cek = true;
					}
				}
				else if (tableno == 2)
				{
					if (Cust.Customer[Head(Cust)].Jumlahorang == 4)
						{
							printf ("kursi tidak cukup");
							cek = false;
							break;
						}
					if (Cust.Customer[Head(Cust)].Jumlahorang == 2)
						{printf ("CUKUP");
							Elmt(*M,2,6) = 'C';
							Elmt(*M,2,8) = 'C';
							cek = true;
							waktu++;
							
							AddQ((Cust2),2);
							InfoTailNM(*Cust2) = 2;
							DelQ(&Cust,&Head(Cust));
							DeleteQC(&Cust,&dc);
						}	
				}
				else if (tableno == 4)
				{
					if (Cust.Customer[Head(Cust)].Jumlahorang == 4)
						{
							printf ("kursi tidak cukup");
							cek = false;
							break;
						}
					if (Cust.Customer[Head(Cust)].Jumlahorang == 2)
						{printf ("CUKUP");
							Elmt(*M,7,6) = 'C';
							Elmt(*M,7,8) = 'C';
							AddQ((Cust2),2);
							InfoTailNM(*Cust2) = 4;
							DelQ(&Cust,&Head(Cust));
							DeleteQC(&Cust,&dc);
							
							waktu++;
							cek = true;
							
						}	
				}
				else
				{
					printf ("kursi tidak cukup");
					cek = false;
					
					break;
				}
			
			}
			else 
			{	printf ("Salah posisi tempat");
				cek =false;
				break;
			}
        }
    }
    else
    {
        printf("Tidak ada customer yang menunggu!\n");
    }
   
}


