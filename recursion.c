#include "recursion.h"

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
	if (n == NULL || n->next == NULL) return;
	freeList(n->next);
	free(n);
}

void appendNode(Node n, int value) {
	if (n == NULL) return;
	if (n->next == NULL) {
		n->next = newNode(value);
	} else {
		appendNode(n->next, value);
	}
}

void printList(Node n, bool newline) {
	if (n == NULL) return;
	if (newline) {
		if (n->value == -1) printf("-\n");	
		else printf("%i\n", n->value);
	} else {
		if (n->next == NULL) {
			if (n->value == -1) printf("-");
			else printf("%i", n->value);
		}
		else {
			if (n->value == -1) printf("-	");
			else printf("%i	", n->value);
		}
	}
	if (n->next == NULL) {
		return;
	}
	printList(n->next, newline);
}

Node get2ndLastNode(Node n) {
	if (n->next->next == NULL) return n;
	return get2ndLastNode(n->next);
}

bool delete1stInstanceOf(Node n, int value) {
	if (n->next == NULL) return false;
	if (n->next->next == NULL) {
		if (n->next->value == value) {
			free(n->next);
			n->next = NULL;
			return true;
		}
		return false;
	}
	if (n->next->next->next == NULL) {
		if (n->next->value == value) {
			Node holder = n->next->next;
			free(n->next);
			n->next = holder;
			return true;
		}
		if (n->next->next->value == value) {
			free(n->next->next);
			n->next->next = NULL;
			return true;
		}
		return false;
	}
	delete1stInstanceOf(n->next, value);
	return false; // Silence warning. Not logic.
}

int countListRecurse(Node n, int counter) {
	if (n->next != NULL) counter = countListRecurse(n->next, counter + 1);
	return counter;
}

int countList(Node n) {
	if (n == NULL) return 0;
	else return countListRecurse(n, 1);
}
