#include "tree.h"

struct tode {
	Tode left;
	Tode right;
	int value;
};

struct tree {
	Tode root;
	int n;
	int h;
};

Tode newTode(int value) {
	Tode tode = (Tode)malloc(sizeof(struct tode));
	tode->left = NULL;
	tode->right = NULL;
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
	// Post-order traversal.
	// TODO: Change to nicer format with level-order traversal. Will need queue.
	if (tode->left != NULL) printTreeFromRoot(tode->left);
	if (tode->right != NULL) printTreeFromRoot(tode->right);
	printf("%i\n", tode->value);
}

void printTree(Tree t) {
	printTreeFromRoot(t->root);
}

void insertFromRoot(Tode tode, int value) {
	if (tode->value > value) {
		if (tode->left == NULL) {
			Tode insertedTode = newTode(value);
			tode->left = insertedTode;
			return;
		}
		insertFromRoot(tode->left, value);
	}
	if (tode->value < value) {
		if (tode->right == NULL) {
			Tode insertedTode = newTode(value);
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

