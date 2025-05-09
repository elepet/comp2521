#ifndef HEADERS_SEEN

#include <stdio.h>
#include <stdlib.h>

#include "recursion.h"

#endif

Node* newNode(int value) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (!node) {
		printf("Error: malloc failed\n");
		return NULL;
	}
	node->value = value;
	node->next = NULL;
	return node;
}

void freeList(Node* node) {
	if (node == NULL) {
		
	}
	if (node->next == NULL) {
		return;
	}
	freeList(node->next);
	free(node);
}

void appendNode(Node* node, int value) {
	if (node->next == NULL) {
		node->next = newNode(value);
	} else {
		appendNode(node->next, value);
	}
}

void printList(Node* node) {
	printf("%i\n", node->value);
	if (node->next == NULL) {
		return;
	}
	printList(node->next);
}

