#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

typedef struct tree2
{
	struct tree2* lewy;
	struct tree2* prawy;
	struct tree2* rodzic;
	int wartosc;
} node16;

void menu_16();
void wartosc_16(int*);
void wyswietl_16(node16*, int);
void dodaj_16(node16**, int);
void usun_16(node16**, int);
node16* szukaj_16(node16**, int);
node16* minimum_16(node16**);
node16* maksimum_16(node16**);
node16* poprzednik_16(node16**, int);
node16* nastepnik_16(node16**, int);
int porownanie_16(node16**, node16**);
list* treeToList_16(node16**);