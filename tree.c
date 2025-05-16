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

void printTreeFromRoot(Tode tode, char* prefix, int isLeft, int isRoot) {
	printf("%s", prefix);
	if (isRoot) {
		printf("%d\n", tode->value);
	} else if (isLeft) {
		printf("├── l: %d\n", tode->value);
	} else {
		printf("└── r: %d\n", tode->value);
	}

	char newPrefix[1000];
	strcpy(newPrefix, prefix);
	if (isRoot) {
		strcat(newPrefix, "");
	} else if (isLeft) {
		strcat(newPrefix, "│   ");
	} else {
		strcat(newPrefix, "    ");
	}

	if (tode->left != NULL) printTreeFromRoot(tode->left, newPrefix, 1, 0);
	if (tode->right != NULL) printTreeFromRoot(tode->right, newPrefix, 0, 0);
}

void printTree(Tree t) {
	printTreeFromRoot(t->root, "", 0, 1);
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

Tode rotate(Tree t, char leftOrRight) {
	if (leftOrRight == 'l') {
		if (t->root->right == NULL) return t->root;
		Tode holder = t->root->right;
		t->root->right = holder->left;
		holder->left = t->root;
		t->root = holder;
	} else if (leftOrRight == 'r') {
		if (t->root->left == NULL) return t->root;
		Tode holder = t->root->left;
		t->root->left = holder->right;
		holder->right = t->root;
		t->root = holder;
	}
	return t->root;
}
