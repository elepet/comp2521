#include "recursion.h"
#include "complexity.h"
#include "sorting.h"
#include "adt.h"
#include "tree.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));

//	// ============================================ RECURSION + LINKED LIST.
//	Node list = newNode(atoi(argv[1]));
//
//	for (int i = 2; i < argc; i++) {
//		appendNode(list, atoi(argv[i]));
//	}	
//
//	printList(list);
//
//	freeList(list);
//
//	// ============================================ TIME COMPLEXITY.
//
//	demonstrateSearch(linearSearch, 5, 420);
//	demonstrateSearch(binarySearch, 5, 420);
//	plotTimeComplexity(linearSearch);	
//
//	// ============================================ SORTING. 
//	demonstrateSort(selectionSort, 5);
//	demonstrateSort(bubbleSort, 5);
//	demonstrateSort(insertionSort, 5);
//	demonstrateSort(mergeSort, 5);
//	demonstrateSort(naiveQuickSort, 5);
//	demonstrateSort(medianOfThreeQuickSort, 5);
//	demonstrateSort(randomisedQuickSort, 5);
//
//	// ============================================ ADT.
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

	// ============================================ TREE.
	Tode root = bstInsert(bstNewTode(10), 10);
	bstInsert(root, 5);
	bstInsert(root, 14);
	bstInsert(root, 30);
	bstInsert(root, 29);
	bstInsert(root, 32);

	printf("Tree:\n");
	bstPrint(root);

	printf("Size of the tree: %d\n", bstSize(root));

	printf("Is 4 in the tree? %d\n", bstSearch(root, 4));
	printf("Is 5 in the tree? %d\n", bstSearch(root, 5));

	root = bstRotate(root, 'l');

	printf("Tree rotated left:\n");
	bstPrint(root);

	root = bstPartition(root, 3);
	printf("Tree partitioned around index 3:\n");
	bstPrint(root);

	root = bstRebalance(root);
	printf("Globally size-rebalanced tree:\n");
	bstPrint(root);

	bstFree(root);

	return 0;
}
