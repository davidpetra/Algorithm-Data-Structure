#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "variable.h"

int main(){
	/* Kamus Lokal */
	int c, n;
	int i;
	Queue RandomCust;
	
	/* Algoritma */
	
	CreateEmptyQ(&RandomCust);
	printf("Ten random numbers in Queue\n");
	
	for (c = 1; c <= 10; c++) {
		n = rand() % 2 + 1;
		printf("%d\n", n);
		if(n == 2){
			AddQ(&RandomCust,4);
		}else if(n == 1){
			AddQ(&RandomCust,2);
		}
	}
	
	printf("isi queue \n");
	i = Head(RandomCust);
	while(i<=Tail(RandomCust)){
		printf("%d\n",RandomCust.Customer[i].Jumlahorang);
		i++;
	}
	//INI UNTUK CEK ADDD
	printf("\n");
	Add(&RandomCust, 2121);
	printf("Coba deh nambah isi bos \n");
	i = Head(RandomCust);
	while(i<=Tail(RandomCust)){
		printf("%d\n",RandomCust.Customer[i].Jumlahorang);
		i++;
	}
// Ini cek delete queue	
	printf("Coba deh kuhapus top nya\n");
	DelQ(&RandomCust,&Head(RandomCust));
	while(i<=Tail(RandomCust)){
		printf("%d\n",RandomCust.Customer[i].Jumlahorang);
		i++;
	}
	printf("\n");
	return 0;
}
