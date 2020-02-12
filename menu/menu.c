#include "start.h"
#include "newgame.h"
#include "menu.h"
#include "interface.h"
#include "matriks.h"
#include "startgame.h"
#include "credit.h"

/* PROGRAM UNTUK MEMILIH PILIHAN MENU */

void pilihMenu()
/* Prosedur user menginput pilihan main menu */
{
    /* KAMUS LOKAL */
    char pilihan;
    boolean cek,ceknama, ceklagi;

    /* ALGORITMA */
    STARTMENU();
    cek = false;
    printf("> Silakan pilih salah satu menu diatas!\n");
    printf("> Ketik angka untuk memilih : \n");
    printf("> -- 1 : NEWGAME / 2 : STARTGAME / 3 : EXITGAME --\n");
    printf(">> ");
    scanf("%c", &pilihan);

   while (!cek) {
       if (pilihan == '1' || pilihan == '2' || pilihan == '3') {
           cek = true;
        }
       else {
           printf("> Input yang anda masukan salah! Silakan masukan input kembali!\n");
           printf(">> ");
           scanf(" %c", &pilihan);
       }
    }
    ceknama = false;//inisialisasi apa program udah input nama
    if (cek) {
        if (pilihan == '1') {
            NEWGAME();
            ceknama = true;//user sudah input nama
            printf ("\n> PILIHAN 2: STARTGAME atau PILIHAN 3 : CREDIT\n");
            printf(">> ");
            scanf(" %c", &pilihan);

            ceklagi = false;
            while (!ceklagi) {
                if (pilihan == '2' || pilihan == '3') {
                    ceklagi = true;
                }
                else {
                    printf("> Input yang anda masukan salah! Silakan masukan input kembali!\n");
                    printf(">> ");
                    scanf(" %c", &pilihan);
                }
            }
        }    

        if (pilihan == '2') {
            while (!ceknama) {
			   printf("> Silahkan masukkan nama terlebih dahulu!\n");
               NEWGAME();
               ceknama = true;
            }
            if (ceknama)
            {
                STARTGAME();
            }
        }
        else if (pilihan == '3') {
            CREDIT();
        }
    }
}
