#ifndef HEADERS_SEEN

#include <stdio.h>
#include <stdlib.h>

#include "recursion.h"

#endif

struct node {
	int value;
	struct node* next;
};

Node newNode(int value) {
	Node n = (Node)malloc(sizeof(struct node));
	n->value = value;
	n->next = NULL;
	return n;
}

void freeList(Node n) {
	if (n->next == NULL) {
		return;
	}
	freeList(n->next);
	free(n);
}

void appendNode(Node n, int value) {
	if (n->next == NULL) {
		n->next = newNode(value);
	} else {
		appendNode(n->next, value);
	}
}

void printList(Node n) {
	printf("%i\n", n->value);
	if (n->next == NULL) {
		return;
	}
	printList(n->next);
}

Node get2ndLastNode(Node n) {
	if (n->next->next == NULL) return n;
	return get2ndLastNode(n->next);
}
