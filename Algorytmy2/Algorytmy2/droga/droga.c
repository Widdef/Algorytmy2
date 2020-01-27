#include "droga.h"

void menu_25()
{
	int value = 0;
	int **matrix = NULL;
	int wybor;
	int start = 0;
	int meta = 0;
	do
	{
		system("CLS");
		printf("\n--------------------------------------------------------------\n\n");
		printf("Co chcesz wykonac\n");
		printf("1 - Wygeneruj macierz grafu\n");
		printf("2 - Znajdz droge\n");
		printf("3 - Wyswietl\n");
		printf("0 - Cofnij\n");
		printf("\nPodaj liczbe:  ");
		scanf(" %d", &wybor);
		switch (wybor)
		{
		case 1:
			rozmiar(&value);
			generuj(matrix,value);
			break;
		case 2:
			printf("Wybierz start: ");
			scanf(" %d", &start);
			printf("Wybierz mete: ");
			scanf(" %d", &meta);
			dijkstry(matrix, start, meta);
			break;
		case 3:
			wyswietl_25(matrix, value);
			system("PAUSE");
			break;
		default:
			break;
		}

	} while (wybor != 0);
}

void rozmiar(int *value)
{
	printf("Podaj rozmiar macierzy do wygenerowania.");
	scanf(" %d", value);
}

void generuj(int **matrix, int value)
{
	time_t tt;
	srand((unsigned int)time(&tt));
	matrix = (int**)malloc(sizeof(int *) * value);
	for (int i = 0; i < value; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int) * value);
	}
	for (int i = 0; i < value; i++)
	{
		for (int j = 0; j < value; j++)
		{
			if (i == j)
				matrix[i][j] = 0;
			else
			{
				if (rand() % 100 < 40)
					matrix[i][j] = 0;
				else
					matrix[j][i] = matrix[i][j] = rand()%20;
			}
		}
	}
}

void wyswietl_25(int** p, int lenght)
{
	if (p == NULL)
		return;
	for (int i = 0; i < lenght; i++)
	{
		for (int j = 0; j < lenght; j++)
		{
			printf("  %d  ", p[i][j]);
		}
		printf("\n");
	}
}

void dijkstry(int **matrix, int start, int meta)
{

}