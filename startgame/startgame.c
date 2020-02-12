#include "startgame.h"
#include "interface.h"
#include "variable.h"
#include "inputCmd.h"
#include "matriks.h"
#include "array.h"
#include "queue.h"
#include "controller.h"
#include "interface.h" 

void STARTGAME()
{
    printf("                                  --------------------------------\n");
    printf("                                  |      GAME BARU DIMULAI!      |");
    printf("\n                                  --------------------------------");
    
    
    money = 500;
    life = 3;
    waktu = 0;
	MakeEmptyTabOrder(&TabOrders);
	CreateEmptyQ(&Cust);
	CreateEmptyQ(&Cust2);
	//buatqueuewaiting(&Cust);
	
	LoadMap1();
	LoadMap2();
    pindah = false;
    GameMaps(M1);
    COMMAND();
    
}
