#include <stdio.h>
#include "mesin_kar.h"

int main() {
	printf("Awal pita : \n");
	START("load_map1.txt");

	while (!EOP) {
		printf("%c", CC);
		ADV();
	}

	printf("\nakhir, Bye!\n");

	return 0;
}
