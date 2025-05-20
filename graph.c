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

// This requires a different node type for the queue, since used adjacency list for graph.

//void GraphBFS(Graph g, int v) {
//	int predecessor[10];
//	for (int i = 0; i < 10; i++) predecessor[i] = -1;
//	Queue q = QueueNew();
//
//	predecessor[v] = v;
//	QueueEnqueue(q, g->vertArr[v]); 
//
//	Node movingHolder;
//	Node vertHolder;
//	while (QueueSize(q) != 0) {
//		movingHolder = QueuePeek(q);
//		vertHolder = movingHolder;
//		QueueDequeue(q, false);
//		while (movingHolder->next != NULL) {
//			if (predecessor[movingHolder->next->value] == -1) {
//				predecessor[movingHolder->next->value] = vertHolder->value;
//				QueueEnqueue(q, g->vertArr[movingHolder->next->value]);
//			}
//			movingHolder = movingHolder->next;
//		}
//	}
//
//	printf("Predecessor array:\n");
//	for (int i = 0; i < 10; i++) printf("%i: %i\n", i, predecessor[i]);	
//	
//	printList(QueuePeek(q), true);
//
//	QueueFree(q);
//}

bool GraphDFSRecurse(Graph g, int v, int w, bool visited[10]) {
	visited[v] = true;
	if (v == w) return true;
	Node holder = g->vertArr[v];
	while (holder->next != NULL) {
		if (!visited[holder->next->value]) {
			if (GraphDFSRecurse(g, holder->next->value, w,  visited)) return true;
		}
		holder = holder->next;
	}
	return false;
}

bool GraphDFS(Graph g, int v, int w) {
	bool visited[10];
	for (int i = 0; i < 10; i++) visited[i] = false;
	return GraphDFSRecurse(g, v, w, visited);
}

bool GraphDFSHasCycleRecurse(Graph g, int v, int w, bool visited[10]) {
	visited[v] = true;
	Node holder = g->vertArr[v];
	while (holder->next != NULL) {
		if (holder->next->value != w) {
			if (visited[holder->next->value]) return true;
			else if (GraphDFSHasCycleRecurse(g, holder->next->value, v, visited)) return true;
		}
		holder = holder->next;
	}
	return false;
}

bool GraphDFSHasCycle(Graph g, int v) {
	bool visited[10];
	for (int i = 0; i < 10; i++) visited[i] = false;
	for (int i = 0; i < g->nV; i++)
		if (visited[i] == false)
			 if (GraphDFSHasCycleRecurse(g, v, v, visited)) return true;
	return false;
}

