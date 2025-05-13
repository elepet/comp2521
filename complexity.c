#ifndef HEADERS_SEEN

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "complexity.h"

#define RED	"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define WHITE	"\033[37m"
#define RESET	"\033[0m"

#endif

void plotTimeComplexity(int (*f)(int a[], int n, int value, int whoAmI)) {
	// Running search on arrays of successive powers of 2, 100000 times each, and storing times.
	double times[10];
	for (int i = 0; i < 10; i++) {
		int n = (int)pow(2, i);
		int a[n];
		int hiddenIndex = rand() % n;
		for (int j = 0; j < n; j++) {
			a[j] = rand() % 100000;
			if (j == hiddenIndex) a[j] = 420;
		}
		clock_t start = clock();
		for (int j = 0; j < 1000; j++) {
			(*f)(a, n, 420, 0);
		}
		clock_t end = clock();
		times[i] = (double)(end - start) / CLOCKS_PER_SEC;
	}

	FILE *file;
	file = fopen("times.csv", "w");
	for (int i = 0; i < 10; i++) {
		fprintf(file, "%f", times[i]);
		if (i < 9) {
			fprintf(file, ",");
		}
	}
	fprintf(file, "\n");
	fclose(file);
}

int linearSearch(int a[], int n, int value, int whoAmI) {
	if (whoAmI) printf("Searched by linearSearch.\n");
	for (int i = 0; i < n; i++) {
		if (a[i] == value) return i;
	}
	return -1;
}

int binarySearch(int a[], int n, int value, int whoAmI) {
	if (whoAmI) printf("Searched by binarySearch.\n");
	int lo = 0;
	int hi = n - 1;
	
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		
		if (value < a[mid]) {
			hi = mid - 1;
		} else if (value > a[mid]) {
			lo = mid + 1;
		} else {
			return mid;
		}
	}
	
	return -1;
}

void demonstrateSearch(int (*f)(int a[], int n, int value, int whoAmI), int n, int value) {
	int a[n];
	int hiddenIndex = rand() % n;
	printf("At which index is %d in the below array?\n", value);
	printf("{");
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 1000;
		if (i == hiddenIndex) a[i] = value;
		if (i == n - 1) { printf("%i}\n", a[i]); break;}
		printf("%i, ", a[i]);
	}
	clock_t start = clock();
	int index = (*f)(a, n, value, 0);
	for (int i = 0; i < 1000000000; i++) {
		(*f)(a, n, value, 0);
	}
	clock_t end = clock();
	double duration = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Index: %i\n", index);
	(*f)(a, n, value, 1);
	// Not precise.
	printf("Average time taken: %.2fns.\n\n", duration);
}


