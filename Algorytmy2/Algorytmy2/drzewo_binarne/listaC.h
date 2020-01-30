#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ellc
{
	char data;
	struct ellc *next;
}listC;

void list_add_end_C(listC**, char);
void list_add_start_C(listC**, char);
void list_show_C(listC*);
void list_delete_first_C(listC**);
