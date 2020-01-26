#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ell
{
	int data;
	struct ell *next;
}list;

void list_add_end(list**, int);
void list_add_start(list**, int);
void list_show(list*);
void list_delete_first(list**);

