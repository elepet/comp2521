// Lev K. 2025

// A priority queue (PQ) is an ADT that is has items ordered by priority.
// Here, a large priority value will be considered high priority.
// Implementations:
// Data structure	|Insert	|Delete	|Peek	|Is Empty
// Unordered array	|O(1)	|O(n)	|O(n)	|O(1)
// Ordered array	|O(n)	|O(1)	|O(1)	|O(1)
// Unordered ll		|O(1)	|O(n)	|O(n)	|O(1)
// Ordered ll		|O(n)	|O(1)	|O(1)	|O(1)
// Binary heap		|O(lgn)	|O(lgn)	|O(1)	|O(1)

// A heap is a tree-based data structure which satisfies the heap property.
// The heap property specifies how values should be ordered (either max or min heap).
// In a max heap, the value in each node must be >= the values in its children.
// In a min heap, the value in each node must be <= the values in its children.
// A binary heap is one that is a binary tree and satisfies the heap property and the completeness property.
// The completeness property requires all levels of the tree (except possibly the last) to be filled fully and the last level must be filled from left to right.
// A result of the completeness property is that binary heaps always contain log2(n) + 1 levels.
// Heaps are usually implemented with an array. For a binary heap, index 1 contains the root, the next 2 contain the root's children, the next 4 contains their children, etc.
// This allows for a useful property, which makes traversal efficient.
// For an item at index i:
// - Its left child is located at index 2 * i.
// - Its right child is located at index 2 * i + 1.
// - Its parent is located at index i / 2.

#include "standard.h"

#ifndef PQ_HEAP_TRIE
#define PQ_HEAP_TRIE

// Binary heap implementation of PQ.

struct pqItem;
typedef struct pqItem *PqItem;
struct pq;
typedef struct pq *Pq;

// Return new pqItem.
PqItem PqNewItem(int value, int priority);

// Return new empty PQ.
Pq PqNew(void);

// Free dynamically allocated memory to PQ. 
void PqFree(Pq pq);

// Add item with priority to PQ.
void PqInsert(Pq pq, int value, int priority);

// Print PQ.
void PqPrint(Pq pq);

// Delete and return item with highest priority.
PqItem PqDelete(Pq pq);

// Return value with highest priority.
int PqPeek(Pq pq);

// Return true if pq is empty, false otherwise.
bool PqIsEmpty(Pq pq);

#endif
