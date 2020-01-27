#include "kopce.h"

void menu_22()
{
	system("CLS");
	char* napis = (char*)malloc(100 * sizeof(char));
	for (int i = 0; i < 100; i++)
		napis[i] = ' ';
	printf("Sortowanie ciagu znakow kopcowe.");
	printf("\nPodaj ciag znakow (max 100 znakow)\n");
	scanf_s(" %s", napis, 100);
	int ilosc = strlen(napis);
	printf("\n%d\n", ilosc);
	heapSort(napis, ilosc);

	printf("Po sortowaniu: ");
	for (int i = 0; i < ilosc; i++)
		printf("%c", napis[i]);
	printf("\n");
	system("PAUSE");
}

void swapkop(char* a, char* b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

void heapify(char *arr, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2; 

	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r; 
	if (largest != i)
	{
		swapkop(&arr[i], &arr[largest]);
 
		heapify(arr, n, largest);
	}
}
 
void heapSort(char* arr, int n)
{ 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
 
	for (int i = n - 1; i >= 0; i--)
	{ 
		swapkop(&arr[0], &arr[i]); 
		heapify(arr, i, 0);
	}
}