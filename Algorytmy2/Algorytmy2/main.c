#include <stdio.h>
#include <stdlib.h>
#include "drzewo_binarne/zadanie.h"
#include "sortowanie/sortowanie.h"
#include "kopce/kopce.h"
#include "droga/droga.h"
#include "porownanie/porownanie.h"

int main()
{
	int wybor;
	do
	{
		system("CLS");
		printf("Ktore zadanie?\n");
		printf("14 - Drzewo binarne\n");
		printf("16 - Porownanie\n");
		printf("21 - Sortowanie\n");
		printf("22 - Kopce\n");
		printf("25 - Droga\n");
		printf("0 - Wyjscie\n");
		printf("\nPodaj liczbe:  ");
		scanf("%d", &wybor);
		
		switch (wybor)
		{
		case 14:
			menu_14();
			break;
		case 16:
			menu_16();
			break;
		case 21:
			menu_21();
			break;
		case 22:
			menu_22();
			break;
		case 25:
			menu_25();
			break;
		default:
			break;
		}

	} while (wybor != 0);



	return 0;
}