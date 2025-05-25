#include "pq.h"

#define CAPACITY 10

struct pqItem {
	int value;
	int priority;
};

struct pq {
	PqItem *items;
	int size;
	int capacity;
};

PqItem PqNewItem(int value, int priority) {
	PqItem n = (PqItem)malloc(sizeof(struct pqItem));
	n->value = value;
	n->priority = priority;
	return n;
}

Pq PqNew(void) {
	Pq pq = (Pq)malloc(sizeof(struct pq));
	pq->size = 0;
	pq->items = (PqItem*)malloc(pq->capacity * sizeof(struct pqItem));
	for (int i = 0; i < pq->size; i++) pq->items[i] = NULL;
	return pq;
}

void PqFree(Pq pq) {
	for (int i = 0; i < pq->size; i++) free(pq->items[i]);
	free(pq->items);
	free(pq);
}

void PqInsert(Pq pq, int value, int priority) {
	if (pq->size == pq->capacity) {
		pq->capacity += CAPACITY;
		pq->items = realloc(pq->items, pq->capacity * sizeof(struct pqItem));
	}
	pq->size++;	
	pq->items[pq->size] = PqNewItem(value, priority);

	int i = pq->size;
	PqItem holder;
	while (i > 1 && pq->items[i]->priority > pq->items[i / 2]->priority) {
		holder = pq->items[i];
		pq->items[i] = pq->items[i / 2];
		pq->items[i / 2] = holder;
		i = i / 2;
	}
}

void PqPrint(Pq pq) {
	printf("Index	Item v	Item p\n");
	for (int i = 0; i < pq->capacity; i++) {
		if (pq->items[i] == NULL) printf("%i	NULL	NULL\n", i);
		else printf("%i	%i	%i\n", i, pq->items[i]->value, pq->items[i]->priority);
	}
}

PqItem PqDelete(Pq pq) {
	PqItem item = pq->items[1];
	pq->items[1] = pq->items[pq->size];
	pq->size--;

	int i = 1;	
	PqItem holder;
	while (2 * i <= pq->size) {
		int j = 2 * i;
		if (j < pq->size && pq->items[pq->size] < pq->items[j + 1]) j++;
		if (pq->items[i] >= pq->items[j]) break;
		holder = pq->items[i];
		pq->items[i] = pq->items[j];
		pq->items[j] = holder;
		i = j;
	}
	pq->items[pq->size + 1] = NULL;
	
	return item;
}

int PqPeek(Pq pq) {return pq->items[1]->value;}

bool PqIsEmpty(Pq pq) {
	if (pq->size == 0) return true;
	else return false;
}
