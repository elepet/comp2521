#include "recursion.h"
#include "complexity.h"
#include "sorting.h"
#include "adt.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));

	// ============================================ RECURSION + LINKED LIST.
	Node list = newNode(atoi(argv[1]));

	for (int i = 2; i < argc; i++) {
		appendNode(list, atoi(argv[i]));
	}	

	printList(list);

	freeList(list);

	// ============================================ TIME COMPLEXITY.

	demonstrateSearch(linearSearch, 5, 420);
	demonstrateSearch(binarySearch, 5, 420);
	plotTimeComplexity(linearSearch);	

	// ============================================ SORTING. 
	demonstrateSort(selectionSort, 5);
	demonstrateSort(bubbleSort, 5);
	demonstrateSort(insertionSort, 5);
	demonstrateSort(mergeSort, 5);
	demonstrateSort(naiveQuickSort, 5);
	demonstrateSort(medianOfThreeQuickSort, 5);
	demonstrateSort(randomisedQuickSort, 5);

	// ============================================ ADT.
//	Stack s = StackNew();
//	StackPush(s, newNode(2));
//	StackPush(s, newNode(7));
//	StackPush(s, newNode(4));
//	StackPush(s, newNode(1));
//	StackPop(s);
//
//	printList(StackPeek(s));
//
//	printf("Size: %i\n", StackSize(s));
//
//	StackFree(s);
//
//	Queue q = QueueNew();
//	QueueEnqueue(q, newNode(2));
//	QueueEnqueue(q, newNode(7));
//	QueueEnqueue(q, newNode(4));
//	QueueEnqueue(q, newNode(1));
//	QueueDequeue(q);
//
//	printList(QueuePeek(q));
//
//	printf("Size: %i\n", QueueSize(q));
//
//	QueueFree(q);

	return 0;
}
