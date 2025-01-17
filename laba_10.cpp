#include "StdAfx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "string.h"
#include <cmath>
#include <queue>
using namespace std;


int **createG(int size){
	int **G;
	G = (int**)malloc(size * sizeof(int*));
	for(int i=0; i < size; i++){
		G[i] = ((int*)malloc(size * sizeof(int)));
	}

	for (int i=0; i < size; i++){
		for(int j = i; j<size; j++){
			G[i][j] = rand()%6;
			if (i == j) G[i][j] = 0;
			G[j][i] = G[i][j];
		}
	}
	return G;
}

void **printG(int **G, int size){
	for (int i=0; i < size; i++){
		for(int j = 0; j<size; j++){
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void **BFS(int **G, int v, int size, int *dist)
{
	queue <int> q;
	q.push (v);
	dist[v]=0;

	while (!q.empty()){
		v=q.front();
		q.pop();
		for (int i=0; i<size; i++){
			if (G[v][i] > 0 && dist[i] > dist[v] + G[v][i]){
				q.push (i);
				dist[i]=dist[v]+G[v][i];
			}
		}
	}
	return 0;
}

int main(){
	int size = 0, s = 0, *vis;
    srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	printf("Введите размер графа: ");
	scanf("%d",&size);

	//queue <int> ex;

	vis = (int*)malloc(size * sizeof(int));
	//for(int i = 0; i < size; i++) vis[i] = 1000;
	int **G1 = createG(size);
	printG(G1, size);
	printf("\n");
	
	int maxic = -1;

	int *ex;
	for (int i =0; i <size;i++) ex = ((int*)malloc(size * sizeof(int)));

	for(int i =0; i < size; i++){
		maxic = -1;
		for(int k = 0; k < size; k++) vis[k] = 1000;
		BFS(G1, i, size, vis);
		for(int j = 0; j < size; j++) {
			printf("%d ", vis[j]);
			if(maxic < vis[j]) maxic = vis[j];
		}
		ex[i] = maxic;
		printf("    %d\n", maxic);
	}
	//for(int i = 0; i < size; i++) 
		//printf("%d ", ex[i]);


	/*for(int i=0; i<size; i++) printf("Ðàññòîÿíèå äî %d âåðøèíû = %d\n", i, vis[i]);;
	printf("\n");
	for(int i=0; i<size; i++){
		if (vis[i] == -1) printf("Âåðøèíà %d èçîëèðîâàííàÿ\n", i);
	}*/
}