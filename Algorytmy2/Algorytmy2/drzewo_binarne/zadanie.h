#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tree
{
	struct tree* lewy;
	struct tree* prawy;
	struct tree* rodzic;
	char wartosc;
} node;

void menu_14();
void wartosc(char*);
void wyswietl(node*, char);
void dodaj(node**, char);
void usun(node**, char);
node* szukaj(node**, char);
node* minimum(node**);
node* maksimum(node**);
node* poprzednik(node**, char);
node* nastepnik(node**, char);
//void zapis_15(node**);