#include "lista.h"


void list_add_end(list **p, int value)
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

void list_add_start(list **p, int value)
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

void list_delete_first(list **p)
{
	if (*p != NULL)
	{
		list *tmp = *p;
		*p = (*p)->next;
		free(tmp);
	}
}
