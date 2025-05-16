#include "tree.h"

struct tode {
	Tode left;
	Tode right;
	Tode next; // For queue.
	int depth; // For queue.
	int value;
};

struct tree {
	Tode root;
	int n;
	int h;
};

// Helper queue for todes.
// Used for print.
struct tueue {
	Tode front;
	Tode back;
	int size;
};

Tueue TueueNew(void) {
	Tueue q = (Tueue)malloc(sizeof(struct tueue));
	q->size = 0;
	return q;
}

void TueueEntueue(Tueue q, Tode n) {
	if (q->back == NULL) {
		q->front = n;
		q->back = n;
		q->size++;
		return;
	}
	Tode holder = q->back;
	q->back = n;
	q->back->next = holder;
	q->size++;
}

Tode get2ndLastTode(Tode n) {
	if (n->next->next == NULL) return n;
	return get2ndLastTode(n->next);
}

void TueueDetueue(Tueue q) {
	if (q->size == 1) {
		q->front = NULL;
		q->back = NULL;
	} else if (q->size == 2) {
		q->front = q->back;
	} else {
		Tode holder = get2ndLastTode(q->back);
		holder->next = NULL;
		q->front = holder;
	}
	q->size--;
}

Tode newTode(int value) {
	Tode tode = (Tode)malloc(sizeof(struct tode));
	tode->left = NULL;
	tode->right = NULL;
	tode->next = NULL;
	tode->depth = 0;
	tode->value = value;
	return tode;
}

Tree newTree() {
	Tree t = (Tree)malloc(sizeof(struct tree));
	t->root = NULL;
	t->n = 0;
	t->h = 0;
	return t;
}

void freeTreeFromRoot(Tode tode) {
	// Post-order traversal.
	if (tode->left != NULL) freeTreeFromRoot(tode->left);
	if (tode->right != NULL) freeTreeFromRoot(tode->right);
	free(tode);
}

void freeTree(Tree t) {
	freeTreeFromRoot(t->root);
}

void printTreeFromRoot(Tode tode) {
	Tueue q = TueueNew();
	TueueEntueue(q, tode);
	
	while (q->size > 0) {
		for (int i = 0; i < q->front->depth; i++) {
			printf(" ");
		}
		printf("%d\n", q->front->value);

		if (q->front->right != NULL) TueueEntueue(q, q->front->right);
		if (q->front->left != NULL) TueueEntueue(q, q->front->left);

		TueueDetueue(q);
	}
	
	free(q);
}

void printTree(Tree t) {
	printTreeFromRoot(t->root);
}

void insertFromRoot(Tode tode, int value) {
	if (tode->value > value) {
		if (tode->left == NULL) {
			Tode insertedTode = newTode(value);
			insertedTode->depth = tode->depth + 1;
			tode->left = insertedTode;
			return;
		}
		insertFromRoot(tode->left, value);
	}
	if (tode->value < value) {
		if (tode->right == NULL) {
			Tode insertedTode = newTode(value);
			insertedTode->depth = tode->depth + 1;
			tode->right = insertedTode;
			return;
		}
		insertFromRoot(tode->right, value);
	}
}

Tode bstInsert(Tree t, int value) {
	if (t->root == NULL) {
		Tode tode = newTode(value);
		t->root = tode;
		t->n = 1;
		t->h = 0;
		return t->root;
	}
	insertFromRoot(t->root, value);
	return t->root;
}

bool searchFromRoot(Tode tode, int value) {
	if (tode->value > value) {
		if (tode->left == NULL) {
			return false;
		}
		return searchFromRoot(tode->left, value);
	}
	if (tode->value < value) {
		if (tode->right == NULL) {
			return false;
		}
		return searchFromRoot(tode->right, value);
	}
	return true;
}

bool bstSearch(Tree t, int value) {
	if (t->root == NULL) return false;
	return searchFromRoot(t->root, value);
}

//Tode getMinFromRoot(Tode tode) {
//	if (tode->left == NULL) return tode;
//	getMinFromRoot(tode->left);
//}
//
//Tode bstJoin(Tree t1, Tree t2) {
//	Tode min2 = getMinFromRoot(t2->root);
//	Tode min22 = get2ndMinFromRoot(t2->root);
//	min22->left = NULL;
//	min2->left = t1->root;
//	min2->right = t2->root;
//	t2->root = min2;
//}

