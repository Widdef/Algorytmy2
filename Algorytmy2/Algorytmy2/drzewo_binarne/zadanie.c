#include "zadanie.h"
#define COUNT 5

void menu_14() {
	node* pierwsze = NULL;
	node* znalezione;
	char* value = malloc(sizeof(char)*100);
	int wybor;
	do
	{
		system("CLS");
		wyswietl(pierwsze, 0);
		printf("\n--------------------------------------------------------------\n\n");
		printf("Co chcesz wykonac\n");
		printf("1 - Dodaj\n");
		printf("2 - Usun\n");
		printf("3 - Wyszukaj\n");
		printf("4 - Minimum\n");
		printf("5 - Maksimum\n");
		printf("6 - Wyznaczanie poprzednika\n");
		printf("7 - Wyznaczanie nastepnika\n");
		printf("8 - Zapis do pliku\n");
		printf("0 - Cofnij\n");
		printf("\nPodaj liczbe:  ");
		scanf("%d", &wybor);

		switch (wybor)
		{
		case 1:
			wartosc(&value);
			dodaj(&pierwsze, value);
			break;
		case 2:
			wartosc(&value);
			usun(&pierwsze, value);
			break;
		case 3:
			wartosc(&value);
			znalezione = szukaj(&pierwsze, value);
			if (znalezione == 0)
				printf("\nNie znaleziono wartosci lub drzewo jest puste\n");
			else
				printf("Wyszukana wartosc:  %d, adres: %p\n", znalezione->wartosc, &znalezione);
			system("PAUSE");
			break;
		case 4:
			znalezione = minimum(&pierwsze);
			if(znalezione == 0)
				printf("\nDrzewo jest puste.\n");
			else
				printf("Wartosc minimalna:  %s\n", znalezione->wartosc);
			system("PAUSE");
			break;
		case 5:
			znalezione = maksimum(&pierwsze);
			if (znalezione == 0)
				printf("\nDrzewo jest puste.\n");
			else
				printf("Wartosc maksymalna:  %s\n", znalezione->wartosc);
			system("PAUSE");
			break;
		case 6:
			wartosc(&value);
			znalezione = poprzednik(&pierwsze, value);
			if(znalezione == 0)
				printf("\nNie posiada poprzednika lub drzewo jest puste\n");
			else
				printf("Wyszukana wartosc:  %s, adres: %p\n", znalezione->wartosc, &znalezione);
			system("PAUSE");
			break;
		case 7:
			wartosc(&value);
			znalezione = nastepnik(&pierwsze, value);
			if (znalezione == 0)
				printf("\nNie posiada poprzednika lub drzewo jest puste\n");
			else
				printf("Wyszukana wartosc:  %s, adres: %p\n", znalezione->wartosc, &znalezione);
			system("PAUSE");
			break;
		case 8:
			zapis_15(&pierwsze);
			break;
		default:
			break;
		}

	} while (wybor != 0);
	free(pierwsze);
}

void wartosc(char **value)
{
	system("CLS");
	for (int i = 0; i < 100; i++)
		(*value)[i]=' ';
	printf("Podaj wartosc:  ");
	scanf_s("%s", (*value), 100);
}

void wyswietl(node *root, char* space) //rekurencyjna funkcja 
{
	if (root == NULL)
		return;
	space += COUNT;
	wyswietl(root->prawy, space); //najpier wywo³uje dla wiêkszych
	printf("\n\n");
	for (int i = COUNT; i < space; i++)
		printf(" ");
	int i = 0;
	int j = strlen(root->wartosc);
	while (i != j)
	{
		printf("%c", root->wartosc[i]); //wypisanie
		i++;
	}
	printf("\n");
	wyswietl(root->lewy, space); //na koniec mniejsze
}

void dodaj(node** p, char* value) {
	node **marker = p;
	node* prev = NULL;
	node *new_el = (node*)malloc(sizeof(node));
	new_el->lewy = NULL;
	new_el->prawy = NULL;
	new_el->wartosc = malloc(sizeof(char)*100);
	memcpy(new_el->wartosc, value, 100);
	while (*marker != NULL)
	{
		prev = *marker;
		if (memcmp((*marker)->wartosc, value, strlen((*marker)->wartosc))>0)
			marker = &(*marker)->lewy;
		else
			marker = &(*marker)->prawy;
	}
	new_el->rodzic = prev;
	*marker = new_el;
}

void usun(node** p, char* value)
{
	node* marker  = szukaj(p, value);
	node* pom = marker;
	if (marker->lewy != NULL)
	{
		pom = poprzednik(&marker, value);
		marker->wartosc = pom->wartosc;
		if (pom->rodzic != NULL)
			if (pom->rodzic->lewy == pom)
				if (pom->lewy == NULL)
					pom->rodzic->lewy = NULL;
				else
					pom->rodzic->lewy = pom->lewy;
			else
				if (pom->lewy == NULL)
					pom->rodzic->prawy = NULL;
				else
					pom->rodzic->prawy = pom->lewy;
	}
	else if (marker->prawy != NULL)
	{
		pom = nastepnik(&marker, value);
		marker->wartosc = pom->wartosc;
		if (pom->rodzic != NULL)
			if (pom->rodzic->lewy == pom)
				if (pom->prawy == NULL)
					pom->rodzic->lewy = NULL;
				else
					pom->rodzic->lewy = pom->prawy;
			else
				if (pom->prawy == NULL)
					pom->rodzic->prawy = NULL;
				else
					pom->rodzic->prawy = pom->prawy;
	}
	else if (marker == *p)
		*p = NULL;
	
	free(pom);
}

node* szukaj(node** p, char* value)
{
	node** marker = p;
	if (marker == NULL)
	{
		return 0;
	}
	int i = memcmp((*p)->wartosc, value, 100);
	while (i)
	{
		if (i>0)
			marker = &(*marker)->lewy;
		if (i<0)
			marker = &(*marker)->prawy;
		if (*marker == NULL)
			return 0;
		i = memcmp((*marker)->wartosc, value, 100);
		
	}
	return (*marker);
}

node* minimum(node** p)
{
	if (p == NULL)
	{
		return 0;
	}
	node** marker = p;
	while ((*marker)->lewy != NULL)
	{
		marker = &(*marker)->lewy;
	}
	return (*marker);
}

node* maksimum(node** p)
{
	if (p == NULL)
	{
		return 0;
	}
	node** marker = p;
	while ((*marker)->prawy != NULL)
	{
		marker = &(*marker)->prawy;
	}
	return (*marker);
}

node* poprzednik(node** p, char* value)
{
	if (p == NULL)
		return 0;
	node* marker = szukaj(p, value);
	if (marker->lewy != NULL)
		return maksimum(&marker->lewy);
	else
	{
		if (marker == *p)
		{
			return 0;
		}
		while ((marker->rodzic->prawy != marker) && (marker->rodzic != *p))
			marker = marker->rodzic;
		if (marker->rodzic->prawy == marker)
			return marker->rodzic;
		return 0;
	}
}

node* nastepnik(node** p, char* value)
{
	if (p == NULL)
		return 0;
	node* marker = szukaj(p, value);
	if (marker->prawy != NULL)
		return minimum(&marker->prawy);
	else
	{
		if (marker == *p)
		{
			return 0;
		}
		while ((marker->rodzic->lewy != marker) && (marker->rodzic != *p))
			marker = marker->rodzic;
		if (marker->rodzic->lewy == marker)
			return marker->rodzic;
		return 0;
	}
}

void zapis_15(node** p)
{
	char file[256];
	FILE *fptr;
	printf_s("Podaj nazwe pliku: ");
	scanf_s("%s", &file, 256);
	fptr = fopen(file, "w");
	if (fptr == NULL)
	{
		printf("Blad otwarcia pliku.\n");
		system("PAUSE");
		fclose(fptr);
		return;
	}
	listC* list = NULL;
	treeToList_15(p, &list);
	while (list != NULL)
	{
		fprintf(fptr, "%d ", list->data);
		list = list->next;
	}
	printf("Udalo sie zapisac dane do pliku.\n");
	fclose(fptr);
	system("PAUSE");
}

void treeToList_15(node** p, listC** list)
{
	if (p == NULL)
		return;
	listC* lista = NULL;
	list_add_end(&lista, (*p)->wartosc);
	treeToList_15((*p)->lewy, &lista);
	treeToList_15((*p)->prawy, &lista);
}