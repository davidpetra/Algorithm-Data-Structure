
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void CopyStack (Stack Sin, Stack *Sout);
void InverseStack (Stack *S);
Stack MergeStack(Stack S1, Stack S2);
void FilterStack(Stack *S);


int main() {
	int isiStack;
	Stack S1, S2, Shasil;
	address i;
	infotype x;

	CreateEmptyStack(&S1);
	CreateEmptyStack(&S2);
	CreateEmptyStack(&Shasil);
	printf("Masukkan elemen : \n");
	while (!IsFullStack(S1)) {	
		scanf("%d", &isiStack);
		if (isiStack == 999) {
			break;
		}
		Push(&S1,isiStack);
	}

	printf("\n");
	TulisStack(S1);

	printf("\n");
	printf("\n");
	CopyStack(S1,&S2);
	InverseStack(&S2);
	TulisStack(S2);

	printf("\n");
	printf("\n");

	Shasil = MergeStack(S1,S2);
	TulisStack(Shasil);

	printf("\n");
	printf("\n");

	FilterStack(&Shasil);
	TulisStack(Shasil);

	return 0;
}



void CopyStack (Stack Sin, Stack *Sout)
{
	Stack Stemp;
	infotype x;

	CreateEmptyStack(&Stemp);
	CreateEmptyStack(Sout);
	
	while (!IsEmptyStack(Sin)) {
		Pop(&Sin,&x);
		Push(&Stemp,x);
	}

	while (!IsEmptyStack(Stemp)) {
		Pop(&Stemp,&x);
		Push(Sout,x);
	}
}

void InverseStack (Stack *S)
{
	Stack Stemp;
	infotype x;

	CreateEmptyStack(&Stemp);

	while (!IsEmptyStack(*S)) {
		Pop(S,&x);
		Push(&Stemp,x);
	}
	CopyStack(Stemp,S);

}

Stack MergeStack(Stack S1, Stack S2)
{
	Stack Stemp, Shasil;
	infotype x;

	CreateEmptyStack(&Stemp);
	CreateEmptyStack(&Shasil);

	CopyStack(S1,&Shasil);
	CopyStack(S2,&Stemp);

	InverseStack(&Stemp);

	while (!IsEmptyStack(Stemp) && (!IsFullStack(Shasil))) {
		Pop(&Stemp,&x);
		Push(&Shasil,x);
	}

	return Shasil;
}


void FilterStack(Stack *S)
{
	Stack Stemp;
	infotype x;

	CreateEmptyStack(&Stemp);

	while (!IsEmptyStack(*S)) {
		Pop(S,&x);
		if (x % 2 == 0) {
			Push(&Stemp,x);
		}
	}

	while (!IsEmptyStack(Stemp)) {
		Pop(&Stemp,&x);
		Push(S,x);
	}

}
