#include "hash.h"

// These must be relative primes such that k % REL_PRIME gives 1 ~ (TABLE_SIZE - 1).
#define TABLE_SIZE 11
#define REL_PRIME 5

struct set {
	int N;
	int M;
	int* valueArr;
};

int hash(int key) {return key % TABLE_SIZE;}

int hash2(int key) {return (key % REL_PRIME) + 1;}

Set SetNew(void) {
	Set s = (Set)malloc(sizeof(struct set));
	s->N = TABLE_SIZE;
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
	int index = hash(i);
	int increment = hash2(i);
	if ((float)(s->M + 1) / (float)s->N >= 1.f) {
		s->N += TABLE_SIZE;	
		s->valueArr = realloc(s->valueArr, (s->N) * sizeof(int));
	}
	while (s->valueArr[index] != 0) {
		index += increment;
		if (index > s->N) index %= s->N; 
		if (s->valueArr[index] == -1) continue;
		if (s->valueArr[index] == i) return;
	}
	s->M++;
	s->valueArr[index] = i;
}

bool SetContains(Set s, int i) {
	int index = hash(i);
	while (s->valueArr[index] != 0) {
		if (s->valueArr[index] == i) return true;
		index++;
	}
	return false;
}

// Tombstone.
void SetDelete(Set s, int i) {
	int index = hash(i);
	while (s->valueArr[index] != i) {
		index++;
	}
	s->valueArr[index] = -1;
	s->M--;
}

int SetNumItems(Set s) {return s->M;}
int SetNumSlots(Set s) {return s->N;}
