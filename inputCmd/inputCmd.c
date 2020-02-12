#include "inputCmd.h"
#include "interface.h"
#include "boolean.h"
#include "exit.h"
#include "credit.h"
#include "variable.h"
#include "controller.h"
#include "ranOrder.h"
#include "array.h"
#include "queue.h"

boolean EndKata;
Kata CKata;



void COMMAND(){
    /* KAMUS LOKAL */
    char input[5];
    boolean keluar;
    int i;
    int carix, cariy;
    int c = 0;

    /* ALGORTIMA */
    keluar = false;
    printf(" Command : ");
    scanf("%s", input);
    
    while (input[c] != '\0') {
		c++;
	}
	CKata.Length = c;
    

    //x = strlen(input);

    for (i = 0; i <= CKata.Length; i++) {
        CKata.TabKata[i] = input[i];
    }
    
    while (!keluar) {
        if (CKata.Length == 4 && CKata.TabKata[0] == 'E' && CKata.TabKata[1] == 'X' && CKata.TabKata[2] == 'I' && CKata.TabKata[3] == 'T') {
            keluar = true;
        }
        else {
					
            if (CKata.Length == 2 && CKata.TabKata[0] == 'G' && CKata.TabKata[1] == 'U') {
                if (!pindah) {
                    GU(&M1);
                    buatqueuewaiting(&Cust);
                }
                else {
                    carix = SearchI(M2);
                    cariy = SearchJ(M2);

                    if (carix == 1 && cariy == 5) {
                        pindah = false;
                        waktu++;
                        DeleteQC(&Cust,&dc);
                        buatqueuewaiting(&Cust);
                       
					}
                    else 
                    {
                        GU(&M2);
                        buatqueuewaiting(&Cust);
                    }
                }
            }
            else if (CKata.Length == 2 && CKata.TabKata[0] == 'G' && CKata.TabKata[1] == 'D') {
				if (!pindah) {
                    carix = SearchI(M1);
                    cariy = SearchJ(M1);
					
						
                    if (carix == 8 && cariy == 5) {
                        pindah = true;
                        waktu++;
                        DeleteQC(&Cust,&dc);
                        buatqueuewaiting(&Cust);
                    }
                    else {
                        GD(&M1);
                        buatqueuewaiting(&Cust);
                    }
                }
                else {
                    GD(&M2);
                    buatqueuewaiting(&Cust);
                }
            }
            else if (CKata.Length == 2 && CKata.TabKata[0] == 'G' && CKata.TabKata[1] == 'L') {

                if (!pindah) {    
                    GL(&M1);
                    buatqueuewaiting(&Cust);
                }
                else {
                    GL(&M2);
                    buatqueuewaiting(&Cust);
                }
            }
            else if (CKata.Length == 2 && CKata.TabKata[0] == 'G' && CKata.TabKata[1] == 'R') {
                 
                if (!pindah) {
                    GR(&M1);
                    buatqueuewaiting(&Cust);
                }
                else {
                    GR(&M2);
                    buatqueuewaiting(&Cust);
                }
            }
            else if (CKata.Length == 2 && CKata.TabKata[0] == 'C' && CKata.TabKata[1] == 'T') {
                CT();
                //printf("ct\n");
                buatqueuewaiting(&Cust);
            }
            else if (CKata.Length == 4 && CKata.TabKata[0] == 'T' && CKata.TabKata[1] == 'A' && CKata.TabKata[2] == 'K' && CKata.TabKata[3] == 'E') {
                Take(M2);
                buatqueuewaiting(&Cust);
                //printf("take\n");
                
            }
            else if (CKata.Length == 4 && CKata.TabKata[0] == 'G' && CKata.TabKata[1] == 'I' && CKata.TabKata[2] == 'V' && CKata.TabKata[3] == 'E') {
                
                GIVE(&M1);
                buatqueuewaiting(&Cust);
                //printf("give\n");
                
            }
            else if (CKata.Length == 5 && CKata.TabKata[0] == 'P' && CKata.TabKata[1] == 'L' && CKata.TabKata[2] == 'A' && CKata.TabKata[3] == 'C' && CKata.TabKata[4] == 'E') {
                placeCustomer(&M1,&Cust2);
                buatqueuewaiting(&Cust);
                
            }
            else if (CKata.Length == 5 && CKata.TabKata[0] == 'O' && CKata.TabKata[1] == 'R' && CKata.TabKata[2] == 'D' && CKata.TabKata[3] == 'E' && CKata.TabKata[4] == 'R') {
                Ordermakanan(&M1);
                tulisorder(&TabOrders);
                buatqueuewaiting(&Cust);
            }
            else {
                printf(" > Pilihan yang anda masukan salah! Silakan masukan command kembali!\n");
            }
            if (life == 0) 
            {
				keluar = true;
			}
            
            if (!pindah) {
                GameMaps(M1);
            }
            else {
                GameMaps(M2);
            } 
            
            printf(" Command : ");
            scanf("%s", input);
            
            c = 0;
            
            while (input[c] != '\0') {
				c++;
			}
			CKata.Length = c;

            //x = strlen(input);

            for (i = 0; i <= CKata.Length; i++) {
                CKata.TabKata[i] = input[i];
            }
            
            /*IdxWL=1;
            IdxWLC=1;
			pwaktu5=5;
			pwaktu20=30;
			waitinglist(&Q);*/
			//buatqueuewaiting(&Cust);
			
        }
    }

    if (keluar) {
        EXIT();
    }
}
