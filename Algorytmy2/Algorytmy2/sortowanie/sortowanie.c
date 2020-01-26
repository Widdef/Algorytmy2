#include "sortowanie.h"
#define START 0
#define KONIEC 10000
#define COUNT 1000

void menu_21() {
	system("CLS");
	printf("Moze to chwile potrwac....\n");
	time_t tt;
	srand(time(&tt));
	unsigned int tab[4][KONIEC];
	unsigned int sortowania[4][2][COUNT]; // 1 cyfra to srotowanie 2 to przypisania/podstawienia 3 kolejne wyniki
	unsigned int max[4][2]; // w [][0] - podstawienia [][1] - porownania
	unsigned int min[4][2];
	unsigned int srednia[4][2];
	for (int i = 0; i < COUNT; i++)
	{
		for (int j = 0; j < KONIEC; j++)
			tab[0][j] = tab[1][j] = tab[2][j] = tab[3][j] = rand()%100000;
		for (int j = 0; j < 4; j++)
		{
			sortowania[j][0][i] = 0;
			sortowania[j][1][i] = 0;
		}
		babelkowe(tab[0], KONIEC, &sortowania[0][0][i], &sortowania[0][1][i]);
		wstawianie(tab[1], KONIEC, &sortowania[1][0][i], &sortowania[1][1][i]);
		shella(tab[2], KONIEC, &sortowania[2][0][i], &sortowania[2][1][i]);
		quicksort(tab[3], START, KONIEC-1, &sortowania[3][0][i], &sortowania[3][1][i]);
	}
	for (int i = 0; i < 4; i++)
	{
		min[i][0] = max[i][0] = sortowania[i][0][0];
		min[i][1] = max[i][1] = sortowania[i][1][0];
		srednia[i][0] = srednia[i][1] = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < COUNT; j++)
		{
			srednia[i][0] += sortowania[i][0][j];
			srednia[i][1] += sortowania[i][1][j];
			if (min[i][0] > sortowania[i][0][j])
				min[i][0] = sortowania[i][0][j];
			if (max[i][0] < sortowania[i][0][j])
				max[i][0] = sortowania[i][0][j];
			if (min[i][1] > sortowania[i][1][j])
				min[i][1] = sortowania[i][1][j];
			if (max[i][1] < sortowania[i][1][j])
				max[i][1] = sortowania[i][1][j];
		}
	}
	float srednie[4][2];
	for (int i = 0; i < 4; i++)
	{
		srednie[i][0] = (float)srednia[i][0] / (float)COUNT;
		srednie[i][1] = (float)srednia[i][1] / (float)COUNT;
	}
	printf("Rodzaj:                   MAX_PODST          MIN_PODST          SREDNIA_PODS          MAX_POR          MIN_POR          SREDNIA_POR\n");
	printf("Sortowanie babelkowe:     %d           %d          %f          %d          %d          %f\n", max[0][0], min[0][0], srednie[0][0], max[0][1], min[0][1], srednie[0][1]);
	printf("Sortowanie wstawianie:    %d           %d          %f          %d          %d          %f\n", max[1][0], min[1][0], srednie[1][0], max[1][1], min[1][1], srednie[1][1]);
	printf("Sortowanie Shella:        %d           %d          %f          %d          %d          %f\n", max[2][0], min[2][0], srednie[2][0], max[2][1], min[2][1], srednie[2][1]);
	printf("Sortowanie szybkie:       %d           %d          %f          %d          %d          %f\n", max[3][0], min[3][0], srednie[3][0], max[3][1], min[3][1], srednie[3][1]);


	system("PAUSE");
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void babelkowe(int arr[], int n, int* podstawienia, int* porownania)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				(*podstawienia) += 3;
				(*porownania) += 2;
			}
}

void wstawianie(int arr[], int n, int* podstawienia, int* porownania)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		(*podstawienia)++;
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			(*podstawienia)++;
			(*porownania)++;
			j--;
		}
		arr[j + 1] = key;
		(*podstawienia)++;
	}
}

void shella(int arr[], int n, int* podstawienia, int* porownania)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1, (*porownania)++)
		{
			int temp = arr[i];
			(*podstawienia)++;
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap, (*porownania)++)
			{
				arr[j] = arr[j - gap];
				(*podstawienia)++;
			}
			arr[j] = temp;
			(*podstawienia)++;
		}
	}
}

int partition(int arr[], int start, int end, int* podstawienia, int* porownania)
{
	int podzialka = arr[end]; 
	int i = (start - 1);

	for (int j = start; j <= end - 1; j++, (*porownania)++)
	{
		if (arr[j] < podzialka)
		{
			i++;
			(*porownania)++;
			swap(&arr[i], &arr[j]);
			(*podstawienia) += 3;
		}
	}
	swap(&arr[i + 1], &arr[end]);
	(*podstawienia) += 3;
	return (i + 1);
}

void quicksort(int arr[], int start, int end, int* podstawienia, int* porownania)
{
	if (start < end)
	{
		int pi = partition(arr, start, end, podstawienia, porownania);
		quicksort(arr, start, pi - 1, podstawienia, porownania);
		quicksort(arr, pi + 1, end, podstawienia, porownania);
	}
}
