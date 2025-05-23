#include "hash.h"

struct set {
	int N;
	int M;
	int* valueArr;
};

int hash(int key, int N) {return key % N;}

Set SetNew(void) {
	Set s = (Set)malloc(sizeof(struct set));
	s->N = 10;
	s->M = 0;
	s->valueArr = (int*)calloc(s->N, sizeof(int));
	return s;
}

void SetFree(Set s) {
	free(s->valueArr);
	free(s);
}

void SetPrint(Set s) {
	for (int i = 0; i < s->N; i++) {
		if (i == s->N - 1) printf("%i\n", s->valueArr[i]);
		else printf("%i, ", s->valueArr[i]); 
	}
}

void SetInsert(Set s, int i) {
	int index = hash(i, s->N);
	while (s->valueArr[index] != 0) {
		if (s->valueArr[index] == -1) continue;
		if (s->valueArr[index] == i) return;
		index++;
	}
	s->valueArr[index] = i;
	s->M++;
	if ((float)s->M / (float)s->N >= 1.f) {
		s->N += 10;	
		s->valueArr = realloc(s->valueArr, (s->N) * sizeof(int));
	}
}

bool SetContains(Set s, int i) {
	int index = hash(i, 10);
	while (s->valueArr[index] != 0) {
		if (s->valueArr[index] == i) return true;
		index++;
	}
	return false;
}

// Tombstone.
void SetDelete(Set s, int i) {
	int index = hash(i, 10);
	while (s->valueArr[index] != i) {
		index++;
	}
	s->valueArr[index] = -1;
	s->M--;
}

int SetNumItems(Set s) {return s->M;}
int SetNumSlots(Set s) {return s->N;}
