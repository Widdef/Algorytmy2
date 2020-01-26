#include "listaC.h"


void list_add_end_C(list **p, char value)
{
	list ** marker = p;
	list *new_el = (list*)malloc(sizeof(list));

	while (*marker)
	{
		marker = &(*marker)->next;
	}
	new_el->data = value;
	new_el->next = NULL;
	*marker = new_el;
}

void list_add_start_C(list **p, char value)
{
	if (*p == NULL)
	{
		list *new_el = (list*)malloc(sizeof(list));
		new_el->data = value;
		new_el->next = NULL;
		*p = new_el;
	}
	else
	{
		list *new_el = (list*)malloc(sizeof(list));
		new_el->data = value;
		new_el->next = *p;
		*p = new_el;
	}
}

void list_delete_first_C(list **p)
{
	if (*p != NULL)
	{
		list *tmp = *p;
		*p = (*p)->next;
		free(tmp);
	}
}
