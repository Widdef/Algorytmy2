#include "droga.h"

void menu_25()
{
	int value = 0;
	int **matrix = NULL;
	int wybor;
	int start = 0;
	int meta = 0;
	int edges = 0;
	do
	{
		wyswietl_matrix(matrix, value);
		system("CLS");
		printf("\n--------------------------------------------------------------\n\n");
		printf("Co chcesz wykonac\n");
		printf("1 - Wygeneruj macierz grafu\n");
		printf("2 - Znajdz droge\n");
		printf("0 - Cofnij\n");
		printf("\nPodaj liczbe:  ");
		scanf(" %d", &wybor);
		switch (wybor)
		{
		case 1:
			rozmiar(&value);
			generuj(&matrix,&edges,value);
			break;
		case 2:
			solve(matrix, value, edges);
			break;
		default:
			break;
		}

	} while (wybor != 0);
}

void rozmiar(int *value)
{
	printf("Podaj rozmiar macierzy do wygenerowania.");
	scanf(" %d", value);
}

void generuj(int ***p, int* edges, int value)
{
	time_t tt;
	srand((unsigned int)time(&tt));
	int** matrix = NULL;
	matrix = (int**)malloc(sizeof(int *) * value);
	for (int i = 0; i < value; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int) * value);
	}
	for (int i = 0; i < value; i++)
	{
		for (int j = 0; j < value; j++)
		{
			if (i == j)
				matrix[i][j] = 0;
			else
			{
				if (rand() % 100 < 30)
					matrix[i][j] = 0;
				else
				{
					matrix[j][i] = matrix[i][j] = (rand() % 19) + 1;
					(*edges)++;
				}
			}
		}
	}
	*p = matrix;
}

void wyswietl_matrix(int** dist, int size) {
	if(dist != NULL)
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				printf("%d  ", dist[i][j]);
			}
			printf("\n");
		}
	system("PAUSE");
}
void wyswietl_25(int** dist, int** next, int size) 
{
	
	printf("(pair, dist, path)\n");
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if ((i != j) && dist[i][j]) {
				int u = i + 1;
				int v = j + 1;
				printf("( %d ->  %d , %d ,", u, v, dist[i][j]);
				printf("%d", u);
				do {
					u = next[u - 1][v - 1];
					printf(" -> %d", u);
				} while (u != v);
				printf(")\n");
			}
		}
	}
	system("PAUSE");
}

void solve(int** w_s, const int num_vertices, int edges) {
	int** dist = (int**)malloc(sizeof(int *) * num_vertices);
	int** dim = (int**)malloc(sizeof(int *) * num_vertices);
	int** next = (int**)malloc(sizeof(int *) * num_vertices);
	for (int i = 0; i < num_vertices; i++)
	{
		dist[i] = (int*)malloc(sizeof(int) * num_vertices);
		dim[i] = (int*)malloc(sizeof(int) * num_vertices);
		next[i] = (int*)malloc(sizeof(int) * num_vertices);
	}
	for (int i = 0; i < num_vertices; i++) 
	{
		for (int j = 0; j < num_vertices; ++j) 
		{
			dim[i][j] = INT_MAX;
			dist[i][j] = 0;
		}
	}
	for (int i = 0; i < num_vertices-1; i++)
	{
		for (int j = 0; j < num_vertices-1; j++)
		{
			//printf("%d%d\n\n", i, j);
			if (w_s[i][j] == 0)
				continue;
			dist[i][j] += w_s[i][j];
		}
	}
	for (int i = 0; i < num_vertices; ++i) {
		for (int j = 0; j < num_vertices; ++j) {
			next[i][j] = 0;
		}
		for (int j = 0; j < num_vertices; ++j) {
			if (i != j) {
				next[i][j] = j + 1;
			}
		}
	}
	for (int k = 0; k < num_vertices; ++k) {
		for (int i = 0; i < num_vertices; ++i) {
			for (int j = 0; j < num_vertices; ++j) {
				if(dist[i][j] && dist[i][k] && dist[k][j])
					if (dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
						next[i][j] = next[i][k];
					}
			}
		}
	}
	wyswietl_25(dist, next,num_vertices);
}