#include <stdio.h>
#include <stdlib.h>

#include "recursion.h"

int main(int argc, char *argv[]) {

	// RECURSION + LINKED LIST
	Node* list = newNode(atoi(argv[1]));

	for (int i = 2; i < argc; i++) {
		appendNode(list, atoi(argv[i]));
	}	

	printList(list);

	freeList(list);

	return 0;
}
