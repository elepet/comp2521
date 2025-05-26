#include "../include/tree.h"

struct tode {
	Tode left;
	Tode right;
	int value;
};

Tode bstNewTode(int value) {
	Tode tode = (Tode)malloc(sizeof(struct tode));
	tode->left = NULL;
	tode->right = NULL;
	tode->value = value;
	return tode;
}

void bstFree(Tode t) {
	// Post-order traversal.
	if (t->left != NULL) bstFree(t->left);
	if (t->right != NULL) bstFree(t->right);
	free(t);
}

void bstPrintRecurse(Tode t, char* prefix, int isRight, int isRoot, int hasLeftPeer) {
	printf("%s", prefix);
	if (isRoot) {
		printf("%d\n", t->value);
	} else if (isRight) {
		if (hasLeftPeer) printf("├── r: %d\n", t->value);
		else printf("└── r: %d\n", t->value);
	} else {
		printf("└── l: %d\n", t->value);
	}	

	char newPrefix[1000];
	strcpy(newPrefix, prefix);
	if (isRoot) {
		strcat(newPrefix, "");
	} else if (isRight) {
		if (hasLeftPeer) strcat(newPrefix, "│   ");
		else strcat(newPrefix, "    ");
	} else {
		strcat(newPrefix, "    ");
	}

	if (t->right != NULL && t->left != NULL) bstPrintRecurse(t->right, newPrefix, 1, 0, 1);
	if (t->right != NULL && t->left == NULL) bstPrintRecurse(t->right, newPrefix, 1, 0, 0);
	if (t->left != NULL) bstPrintRecurse(t->left, newPrefix, 0, 0, 0);
}

void bstPrint(Tode t) {
	if (t == NULL) return;
	bstPrintRecurse(t, "", 0, 1, 0);
}

Tode bstInsert(Tode t, int value) {
	if (t == NULL) {
		Tode inserted = bstNewTode(value);
		t = inserted;
	}
	if (t->value > value) {
		if (t->left == NULL) {
			Tode inserted = bstNewTode(value);
			t->left = inserted;
			return t;
		}
		bstInsert(t->left, value);
	}
	if (t->value < value) {
		if (t->right == NULL) {
			Tode inserted = bstNewTode(value);
			t->right = inserted;
			return t;
		}
		bstInsert(t->right, value);
	}
	return t;
}

bool bstSearch(Tode t, int value) {
	if (t == NULL) return false;
	if (t->value > value) {
		if (t->left == NULL) {
			return false;
		}
		return bstSearch(t->left, value);
	}
	if (t->value < value) {
		if (t->right == NULL) {
			return false;
		}
		return bstSearch(t->right, value);
	}
	return true;
}

Tode bstRotate(Tode t, char leftOrRight) {
	if (leftOrRight == 'l') {
		if (t->right == NULL) return t;
		Tode holder = t->right;
		t->right = holder->left;
		holder->left = t;
		t = holder;
	} else if (leftOrRight == 'r') {
		if (t->left == NULL) return t;
		Tode holder = t->left;
		t->left = holder->right;
		holder->right = t;
		t = holder;
	}
	return t;
}

int bstSize(Tode t) {
	int n = 1;
	if (t->left != NULL) n += bstSize(t->left);
	if (t->right != NULL) n += bstSize(t->right);
	return n;
}

Tode bstPartition(Tode t, int i) {
	int leftSize = 0;
	if (t->left != NULL) leftSize = bstSize(t->left);
	if (i < leftSize) {
		t->left = bstPartition(t->left, i);
		t = bstRotate(t, 'r');
	} else if (i > leftSize) {
		t->right = bstPartition(t->right, i - leftSize - 1);
		t = bstRotate(t, 'l');
	}
	return t;
}

Tode bstRebalance(Tode t) {
	int n = bstSize(t);
	if (n < 3) return t;
	
	t = bstPartition(t, n / 2);
	t->left = bstRebalance(t->left);
	t->right = bstRebalance(t->right);
	return t;
}

//Tode bstDelete(Tode t, int value) {
//	if (t == NULL) return NULL;
//	if (t->value < value) bstDelete(t->left, value);
//	if (t->value > value) bstDelete(t->right, value);
//	if (t->value == value) {
//		if (t->left == NULL && t->right == NULL) {
//			
//		}
//	}
//	return t;
//}
