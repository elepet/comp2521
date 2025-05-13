#ifndef HEADERS_SEEN

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "sorting.h"

#endif

void swap(Item a[], int i, int j) {
	Item tempI = a[i];
	Item tempJ = a[j];

	a[i] = tempJ;
	a[j] = tempI;
}

void merge(Item a[], int lo, int mid, int hi) {
	Item* temp = malloc((hi - lo + 1) * sizeof(Item));
	int i = lo, j = mid + 1, k = 0;

	while (i <= mid && j <= hi) {
		if (le(a[i], a[j])) {
			temp[k++] = a[i++];
		} else {
			temp[k++] = a[j++];
		}
	}
	
	while (i <= mid) temp[k++] = a[i++];
	while (j <= hi) temp[k++] = a[j++];
	
	for (i = lo, k = 0; i <= hi; i++, k++) {
		a[i] = temp[k];
	}
	
	free(temp);
}

int partition(Item a[], int lo, int hi) {
	Item pivot = a[lo];

	int l = lo + 1;
	int r = hi;
	while (l < r) {
		while (l < r && le(a[l], pivot)) l++;
		while (l < r && ge(a[r], pivot)) r--;
		if (l == r) break;
		swap(a, l, r);
	}
	
	if (lt(pivot, a[l])) l--;
	swap(a, lo, l);
	return l;
}

void medianOfThree(Item a[], int lo, int hi) {
	int mid = (lo + hi) / 2;
	if (gt(a[mid], a[lo])) swap(a, mid, lo);
	if (gt(a[lo],  a[hi])) swap(a, lo,  hi);
	if (gt(a[mid], a[lo])) swap(a, mid, lo);
}

int randInt(int lo, int hi) {
	int i = rand() % (hi - lo + 1);
	return lo + i;
}

void demonstrateSort(void (*f)(Item a[], int lo, int hi, int whoAmI), int n) {
	Item a[n];
	printf("Unsorted:\n");
	printf("{");
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 1000;
		if (i == n - 1) { printf("%i}\n", a[i]); break;}
		printf("%i, ", a[i]);
	}
	clock_t start = clock();
	(*f)(a, 0, n - 1, 1);
	clock_t end = clock();
	double duration = 1000000 * (double)(end - start) / CLOCKS_PER_SEC;
	printf("{");
	for (int i = 0; i < n; i++) {
		if (i == n - 1) { printf("%i}\n", a[i]); break;}
		printf("%i, ", a[i]);
	}
	// Not precise.
	printf("Time taken: %.2fμs.\n\n", duration);
} 

void selectionSort(Item a[], int lo, int hi, int whoAmI) {
	if (whoAmI) printf("Sorted by selectionSort:\n");
	for (int i = lo; i < hi; i++) {
		int min = i;
		for (int j = i + 1; j <= hi; j++) {
			if (lt(a[j], a[min])) {
				min = j;
			}
		}
		swap(a, i, min);
	}
}

void bubbleSort(Item a[], int lo, int hi, int whoAmI) {
	if (whoAmI) printf("Sorted by bubbleSort:\n");
	for (int i = hi; i > lo; i--) {
		bool swapped = false;
		for (int j = lo; j < i; j++) {
			if (gt(a[j], a[j + 1])) {
				swap(a, j, j + 1);
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}

void insertionSort(Item a[], int lo, int hi, int whoAmI) {
	if (whoAmI) printf("Sorted by insertionSort:\n");
	for (int i = lo + 1; i <= hi; i++) {
		Item item = a[i];
		int j = i;
		for (; j > lo && lt(item, a[j - 1]); j--) {
			a[j] = a[j - 1];
		}
		a[j] = item;
	}
}

void mergeSort(Item a[], int lo, int hi, int whoAmI) {
	if (whoAmI) printf("Sorted by mergeSort:\n");
	if (lo >= hi) return;
	int mid = (lo + hi) / 2;
	mergeSort(a, lo, mid, 0);
	mergeSort(a, mid + 1, hi, 0);
	merge(a, lo, mid, hi);
}

void naiveQuickSort(Item a[], int lo, int hi, int whoAmI) {
	if (whoAmI) printf("Sorted by naiveQuickSort:\n");
	if (lo >= hi) return;
	int pivotIndex = partition(a, lo, hi);
	naiveQuickSort(a, lo, pivotIndex - 1, 0);
	naiveQuickSort(a, pivotIndex + 1, hi, 0);
}

void medianOfThreeQuickSort(Item a[], int lo, int hi, int whoAmI) {
	if (whoAmI) printf("Sorted by medianOfThreeQuickSort:\n");
	if (lo >= hi) return;
	medianOfThree(a, lo, hi);
	int pivotIndex = partition(a, lo, hi);
	medianOfThreeQuickSort(a, lo, pivotIndex - 1, 0);
	medianOfThreeQuickSort(a, pivotIndex + 1, hi, 0);
}

void randomisedQuickSort(Item a[], int lo, int hi, int whoAmI) {
	if (whoAmI) printf("Sorted by randomisedQuickSort:\n");
	if (lo >= hi) return;
	swap(a, lo, randInt(lo, hi));
	int pivotIndex = partition(a, lo, hi);
	randomisedQuickSort(a, lo, pivotIndex - 1, 0);
	randomisedQuickSort(a, pivotIndex + 1, hi, 0);
}

