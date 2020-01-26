#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ell
{
	char data;
	struct ell *next;
}list;

void list_add_end_C(list**, char);
void list_add_start_C(list**, char);
void list_show_C(list*);
void list_delete_first_C(list**);

