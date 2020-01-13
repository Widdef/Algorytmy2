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

void menu_14();
void wartosc(int*);
void wyswietl(node*, int);
void dodaj(node**, int);
void usun(node**, int);
node* szukaj(node**, int);
node* minimum(node**);
node* maksimum(node**);
node* poprzednik(node**, int);
node* nastepnik(node**, int);
int porownanie(node**, node**);
list** treeToList(node**);