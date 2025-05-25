#include "recursion.h"
#include "complexity.h"
#include "sorting.h"
#include "adt.h"
#include "tree.h"
#include "graph.h"
#include "hash.h"
#include "pq.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));

	// ============================================ RECURSION + LINKED LIST.
//	Node list = newNode(atoi(argv[1]));
//
//	for (int i = 2; i < argc; i++) {
//		appendNode(list, atoi(argv[i]));
//	}	
//
//	printList(list, true);
//	
//	printf("Size: %i\n", countList(list));
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
//	printList(StackPeek(s), true);
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
//	QueueDequeue(q, true);
//
//	printList(QueuePeek(q), true);
//
//	printf("Size: %i\n", QueueSize(q));
//
//	QueueFree(q);
//
//      // ============================================ TREE.
//	Tode root = bstInsert(bstNewTode(10), 10);
//	bstInsert(root, 5);
//	bstInsert(root, 14);
//	bstInsert(root, 30);
//	bstInsert(root, 29);
//	bstInsert(root, 32);
//
//	printf("Tree:\n");
//	bstPrint(root);
//
//	printf("Size of the tree: %d\n", bstSize(root));
//
//	printf("Is 4 in the tree? %d\n", bstSearch(root, 4));
//	printf("Is 5 in the tree? %d\n", bstSearch(root, 5));
//
//	root = bstRotate(root, 'l');
//
//	printf("Tree rotated left:\n");
//	bstPrint(root);
//
//	root = bstPartition(root, 3);
//	printf("Tree partitioned around index 3:\n");
//	bstPrint(root);
//
//	root = bstRebalance(root);
//	printf("Globally size-rebalanced tree:\n");
//	bstPrint(root);
//
//	bstFree(root);
//
//	// ============================================ GRAPH.
//
//	Graph g = GraphNew(5);
//
//	GraphInsertEdge(g, 0, 1);
//	GraphInsertEdge(g, 1, 2);
//	GraphInsertEdge(g, 2, 3);
//	GraphInsertEdge(g, 3, 4);
//	GraphInsertEdge(g, 4, 0);
//
//	printf("Graph with %i vertices and %i edges:\n", GraphNumVertices(g), GraphNumEdges(g));
//	GraphPrint(g);
//
//	printf("Is 2 adjacent to 3? %i\n", GraphIsAdjacent(g, 2, 3));
//	printf("Is 2 adjacent to 4? %i\n", GraphIsAdjacent(g, 2, 4));
//	printf("Is there a cycle? %i\n", GraphDFSHasCycle(g, 0));
//
//	//GraphBFS(g, 0);
//
//	GraphRemoveEdge(g, 0, 1);
//	GraphRemoveEdge(g, 1, 2);
//	GraphRemoveEdge(g, 2, 3);
//
//	printf("Graph with %i vertices and %i edges:\n", GraphNumVertices(g), GraphNumEdges(g));
//	GraphPrint(g);
//
//	printf("Is there a path between 0 and 1 (using DFS)? %i\n", GraphDFS(g, 0, 1));
//	printf("Is there a path between 4 and 0 (using DFS)? %i\n", GraphDFS(g, 4, 0));
//	printf("Is there a cycle? %i\n", GraphDFSHasCycle(g, 0));
//
//	GraphFree(g);
//
//	Graph g1 = GraphNew(5);
//
//	GraphInsertEdge(g1, 0, 1);
//	GraphInsertEdge(g1, 2, 3);
//	GraphInsertEdge(g1, 3, 4);
//	GraphInsertEdge(g1, 2, 4);
//
//	printf("Graph with 2 connected components:\n");
//	GraphPrint(g1);
//
//	printf("Is there a cycle? %i\n", GraphDFSHasCycle(g1, 0));
//
//	GraphFree(g1);
//
//	Graph g2 = WDGraphNew();
//
//	WDGraphInsertEdge(g2, 0, 22, 1, 22);
//	WDGraphInsertEdge(g2, 0, 81, 5, -1);
//	WDGraphInsertEdge(g2, 5, 116, 6, -1);
//	WDGraphInsertEdge(g2, 6, 79, 1, -1);
//	WDGraphInsertEdge(g2, 0, 666, 6, -1);
//	
//	printf("Directed weighted graph with %i vertices and %i edges:\n", GraphNumVertices(g2), GraphNumEdges(g2));
//	GraphPrint(g2);
//	printf("Is there a path between 0 and 1 (using DFS)? %i\n", WDGraphDFS(g, 0, 1));
//	printf("Is there a path between 4 and 0 (using DFS)? %i\n", WDGraphDFS(g, 4, 0));
//	printf("Is there a cycle? %i\n", WDGraphDFSHasCycle(g, 0));
//
//	WDGraphDijkstra(g2, 0, false, 0);
//	WDGraphDijkstra(g2, 0, true, 6);
//
//	WDGraphRemoveEdge(g2, 1, 0);
//	WDGraphRemoveEdge(g2, 5, 6);
//	WDGraphRemoveEdge(g2, 6, 1);
//
//	printf("Same DW graph but with some edges removed:\n");
//	GraphPrint(g2);
//	printf("Is there a cycle? %i\n", WDGraphDFSHasCycle(g, 0));
//
//	GraphFree(g2);
//
//
//	// ============================================ HASH TABLE.
//	Set s = SetNew();
//
//	SetInsert(s, 52);
//	SetInsert(s, 61);
//	SetInsert(s, 32);
//	SetInsert(s, 44);
//	SetInsert(s, 11);
//	SetInsert(s, 11);
//	SetInsert(s, 99);
//	SetInsert(s, 65);
//	SetInsert(s, 75);
//	SetInsert(s, 112);
//	SetInsert(s, 4442);
//	SetInsert(s, 632);
//	SetInsert(s, 6);
//
//	printf("Set:\n");
//	SetPrint(s);
//	
//	printf("Number of items (M): %i\n", SetNumItems(s));
//	printf("Number of slots (N): %i\n", SetNumSlots(s));
//	printf("Load factor (α = M / N): %.2f\n", (float)SetNumItems(s) / (float)SetNumSlots(s));
//	printf("Contains 32? %i\n", SetContains(s, 32));
//
//	SetDelete(s, 32);
//	printf("Set with 32 deleted:\n");
//	SetPrint(s);
//	printf("Contains 32? %i\n", SetContains(s, 32));
//
//
//	SetFree(s);

	// ============================================ PQ + HEAP.
	
	Pq pq = PqNew();
	PqInsert(pq, 1, 69);
	PqInsert(pq, 2, 112);
	PqInsert(pq, 3, 323);
	PqInsert(pq, 4, 12);
	PqInsert(pq, 5, 1001);

	printf("Priority queue (binary heap implementation):\n");
	PqPrint(pq);
	
	free(PqDelete(pq));
	free(PqDelete(pq));

	printf("Same PQ with some items deleted:\n");
	PqPrint(pq);

	printf("Highest priority value? %i\n", PqPeek(pq));
	printf("Is empty? %i\n", PqIsEmpty(pq));

	PqFree(pq);
	return 0;

}
