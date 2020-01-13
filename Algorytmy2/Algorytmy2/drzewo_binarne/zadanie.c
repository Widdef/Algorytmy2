#include "zadanie.h"
#define COUNT 5

void menu_14() {
	int drzewo = 1;
	node* pierwsze = NULL;
	node* drugie = NULL;
	node* head = pierwsze;
	node* znalezione;
	int value;
	int wybor;
	do
	{
		system("CLS");
		wyswietl(head, 0);
		printf("\n--------------------------------------------------------------\n\n");
		printf("Co chcesz wykonac\n");
		printf("1 - Dodaj\n");
		printf("2 - Usun\n");
		printf("3 - Wyszukaj\n");
		printf("4 - Minimum\n");
		printf("5 - Maksimum\n");
		printf("6 - Wyznaczanie poprzednika\n");
		printf("7 - Wyznaczanie nastêpnika\n");
		printf("8 - Porownanie drzew - zadanie 16\n");
		printf("9 - Zmien drzewa");
		printf("0 - Cofnij\n");
		printf("\nPodaj liczbe:  ");
		scanf("%d", &wybor);

		switch (wybor)
		{
		case 1:
			wartosc(&value);
			dodaj(&head, value);
			break;
		case 2:
			wartosc(&value);
			usun(&head, value);
			break;
		case 3:
			wartosc(&value);
			znalezione = szukaj(&head, value);
			if (znalezione == 0)
				printf("\nNie znaleziono wartosci lub drzewo jest puste\n");
			else
				printf("Wyszukana wartosc:  %d, adres: %d\n", znalezione->wartosc, &znalezione);
			system("PAUSE");
			break;
		case 4:
			znalezione = minimum(&head);
			if(znalezione == 0)
				printf("\nDrzewo jest puste.\n");
			else
				printf("Wartosc minimalna:  %d", znalezione->wartosc);
			system("PAUSE");
			break;
		case 5:
			znalezione = maksimum(&head);
			if (znalezione == 0)
				printf("\nDrzewo jest puste.\n");
			else
				printf("Wartosc maksymalna:  %d", znalezione->wartosc);
			system("PAUSE");
			break;
		case 6:
			wartosc(&value);
			znalezione = poprzednik(&head, value);
			if(znalezione == 0)
				printf("\nNie posiada poprzednika lub drzewo jest puste\n");
			else
				printf("Wyszukana wartosc:  %d, adres: %d\n", znalezione->wartosc, &znalezione);
			system("PAUSE");
		case 7:
			wartosc(&value);
			znalezione = nastepnik(&head, value);
			if (znalezione == 0)
				printf("\nNie posiada poprzednika lub drzewo jest puste\n");
			else
				printf("Wyszukana wartosc:  %d, adres: %d\n", znalezione->wartosc, &znalezione);
		case 8:
			if (porownanie(&pierwsze, &drugie))
				printf("Drzewa sa identyczne");
			else
				printf("Drzewa sa rozne");
			system("PAUSE");
		case 9:
			if (drzewo == 1)
			{
				head = drugie;
				drzewo = 2;
			}
			if (drzewo == 2)
			{
				head = pierwsze;
				drzewo = 1;
			}
		default:
			break;
		}

	} while (wybor != 0);
	free(head);
}

void wartosc(int *value)
{
	system("CLS");
	printf("Podaj wartosc:  ");
	scanf("%d", value);
}

void wyswietl(node *root, int space) //rekurencyjna funkcja 
{
	if (root == NULL)
		return;
	space += COUNT;
	wyswietl(root->prawy, space); //najpier wywo³uje dla wiêkszych
	printf("\n\n");
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%d\n", root->wartosc); //wypisanie
	wyswietl(root->lewy, space); //na koniec mniejsze
}

void dodaj(node** p, int value) {
	node **marker = p;
	node* prev = NULL;
	node *new_el = (node*)malloc(sizeof(node));
	new_el->lewy = NULL;
	new_el->prawy = NULL;
	new_el->wartosc = value;
	while (*marker != NULL)
	{
		prev = *marker;
		if (value < (*marker)->wartosc)
			marker = &(*marker)->lewy;
		else
			marker = &(*marker)->prawy;
	}
	new_el->rodzic = prev;
	*marker = new_el;
}

void usun(node** p, int value)
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

node* szukaj(node** p, int value)
{
	node** marker = p;
	if (marker == NULL)
	{
		return 0;
	}
	while ((*marker)->wartosc != value)
	{
		if ((*marker)->wartosc > value)
			marker = &(*marker)->lewy;
		if ((*marker)->wartosc < value)
			marker = &(*marker)->prawy;
		if (marker == NULL)
			return 0;
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

node* poprzednik(node** p, int value)
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

node* nastepnik(node** p, int value)
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

int porownanie(node** p, node** l)
{
	list** pLista = treeToList(p);
	list** lLista = treeToList(l);
	if ((pLista == NULL && lLista != NULL) || (pLista != NULL && lLista == NULL))
		return 0;
	if ((pLista == NULL && lLista == NULL) || (pLista != NULL && lLista != NULL))
		return 1;
	while ((*pLista) != NULL && (*lLista) != NULL)
	{
		if (((*pLista)->data != (*lLista)->data) && (pLista == NULL || lLista == NULL))
			return 0;
		pLista = &(*pLista)->next;
		lLista = &(*lLista)->next;
	}
	if (pLista != lLista)
		return 0;
	return 1;
}

list** treeToList(node** p)
{
	if (p == NULL)
		return 0;
	list** lista = NULL;
	node* pom = minimum(p);
	list_add_end(lista, pom->wartosc);
	while (pom != 0)
	{
		pom = nastepnik(p, pom->wartosc);
		list_add_end(lista, pom->wartosc);
	}
	return lista;
}