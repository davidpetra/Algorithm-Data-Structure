#include "ranOrder.h"
#include "variable.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void randomOrder() {
    /* KAMUS LOKAL */
    
    const char *makanan[] = {"Burger Monas","Kentang Parut","Nugget Penyet","Engi's Krim","Nasi Goreng Ngiss","Seblak Ceker","Bitterballen","Fried Unagi","Lasagna","Tahu Bulat","Cilok","Go Milk","Green Macchiato","Dumpling Hakao","Surabinasution"};

    /* ALGORITMA */
    const size_t makanan_count = sizeof(makanan) / sizeof(makanan[0]);
    srand(time(NULL));
    printf("Random text: %s\n", makanan[rand() % makanan_count]);
}
