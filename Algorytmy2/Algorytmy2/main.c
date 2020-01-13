#include <stdio.h>
#include <stdlib.h>
#include "drzewo_binarne/zadanie.h"
#include "sortowanie/sortowanie.h"

void test(int *t)
{
	(*t)++;
}

int main()
{
	int wybor;
	int value = 4;
	do
	{
		system("CLS");
		printf("Ktore zadanie?\n");
		printf("14 - Drzewo binarne\n");
		printf("21 - Sortowanie\n");
		printf("22 - \n");
		printf("25 - \n");
		printf("0 - Wyjscie\n");
		printf("\nPodaj liczbe:  ");
		scanf("%d", &wybor);
		
		switch (wybor)
		{
		case 14:
			menu_14();
			break;
		case 21:
			menu_21();
			break;
		case 22:
			break;
		case 25:
			break;
		default:
			break;
		}

	} while (wybor != 0);



	return 0;
}