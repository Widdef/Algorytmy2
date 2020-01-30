#include "listaC.h"


void list_add_end_C(listC** p, char value)
{
	listC** marker = p;
	listC* new_el = (listC*)malloc(sizeof(listC));
	new_el->data = value;
	new_el->next = NULL;
	if (p == NULL)
	{
		*p = new_el;
	}
	else
	{
		while (*marker)
		{
			marker = &(*marker)->next;
		}
		*marker = new_el;
	}
}

void list_add_start_C(listC **p, char value)
{
	if (*p == NULL)
	{
		listC *new_el = (listC*)malloc(sizeof(listC));
		new_el->data = value;
		new_el->next = NULL;
		*p = new_el;
	}
	else
	{
		listC *new_el = (listC*)malloc(sizeof(listC));
		new_el->data = value;
		new_el->next = *p;
		*p = new_el;
	}
}

void list_delete_first_C(listC **p)
{
	if (*p != NULL)
	{
		listC *tmp = *p;
		*p = (*p)->next;
		free(tmp);
	}
}
