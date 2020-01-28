#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

typedef struct tree
{
	struct tree* lewy;
	struct tree* prawy;
	struct tree* rodzic;
	int wartosc;
} node;

void menu_16();
void wartosc_16(int*);
void wyswietl_16(node*, int);
void dodaj_16(node**, int);
void usun_16(node**, int);
node* szukaj_16(node**, int);
node* minimum_16(node**);
node* maksimum_16(node**);
node* poprzednik_16(node**, int);
node* nastepnik_16(node**, int);
int porownanie_16(node**, node**);
list* treeToList_16(node**);