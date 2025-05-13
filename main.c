#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "recursion.h"
#include "complexity.h"
#include "sorting.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));

//	// ============================================ RECURSION + LINKED LIST.
//	Node* list = newNode(atoi(argv[1]));
//
//	for (int i = 2; i < argc; i++) {
//		appendNode(list, atoi(argv[i]));
//	}	
//
//	printList(list);
//
//	freeList(list);


//	// ============================================ TIME COMPLEXITY.
	
//	demonstrateSearch(linearSearch, 5, 420);
//	demonstrateSearch(binarySearch, 5, 420);
	plotTimeComplexity(linearSearch);	

	// ============================================ SORTING. 
//	demonstrateSort(selectionSort, 5);
//	demonstrateSort(bubbleSort, 5);
//	demonstrateSort(insertionSort, 5);
//	demonstrateSort(mergeSort, 5);
//	demonstrateSort(naiveQuickSort, 5);
//	demonstrateSort(medianOfThreeQuickSort, 5);
//	demonstrateSort(randomisedQuickSort, 5);

	return 0;
}
