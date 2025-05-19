#include "recursion.h"
#include "graph.h"

// Integer, array of lists implementation.

struct node {
	int value;
	struct node* next;
};

struct graph {
	int nE;
	int nV;
	struct node** vertArr;
};

Graph GraphNew(int nV) {
	Graph g = (Graph)malloc(sizeof(struct graph));
	g->nE = 0;
	g->nV = nV;
	g->vertArr = malloc(nV * sizeof(Node));
	for (int i = 0; i < nV; i++) {
		g->vertArr[i] = newNode(i);
	}
	return g;
}

void GraphInsertEdge(Graph g, int v, int w) {
	appendNode(g->vertArr[v], w);
	appendNode(g->vertArr[w], v);
	g->nE++;
}

void GraphRemoveEdge(Graph g, int v, int w) {
	bool b1 = delete1stInstanceOf(g->vertArr[v], w);
	bool b2 = delete1stInstanceOf(g->vertArr[w], v);
	if (b1 && b2) g->nE--;
}

void GraphFree(Graph g) {
	for (int i = 0; i < g->nV; i++) {
		freeList(g->vertArr[i]);
	}
	free(g->vertArr);
	free(g);
}

void GraphPrint(Graph g) {
	for (int i = 0; i < g->nV; i++) {
		printf("%i: ", i);
		printList(g->vertArr[i]->next, 0);
		printf("\n");
	}
}

int GraphNumVertices(Graph g) {
	return g == NULL ? -1 : g->nV;
}

int GraphNumEdges(Graph g) {
	return g == NULL ? -1 : g->nE;
}

bool GraphIsAdjacent(Graph g, int v, int w) {
	bool b1 = false;
	bool b2 = false;
	Node holder = g->vertArr[v];
	while (holder != NULL) {
		if (holder->value == w) b1 = true;
		holder = holder->next;
	}
	holder = g->vertArr[w];
	while (holder != NULL) {
		if (holder->value == v) b2 = true;
		holder = holder->next;
	}
	if (b1 && b2) return true;
	else return false;
}
