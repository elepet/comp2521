// Recursion is used to solve problems by breaking them down into simpler, smaller versions of the same problem.
// In code, this means calling a function within itself.
// Each function call creates a stack frame that holds local variables used in that call.
// Which is why too much recursion can cause stack overflow (exceeding available call stack memory).
// The calling code waits until the called function excecutes. So first iteration of is finished last. 
// The 'base case' is the stopping condition. Check this before calling the next iteration.
// Stack behaviour before reaching base case is 'winding' and after is 'unwinding'.
// Operations before call to next iteration are called 'pre-order ops' and occur during winding. Vice versa for 'post-ops'.
// All recursive functions can be rewritten iteratively and vice versa.
// Some applications are easier / more intuitive to implement with one method. Generally iterative methods are more space / time efficient but less succinct.
// If the recursive call is what is returned (very last thing the function does), this is called 'tail call optimization' and it allows for recursion to be implemented without making a new stack frame every call, as the old local variables are not needed. Space complexity goes from O(n) to O(1). This is not standard but supported by GCC, Clang, and other compilers.

#include "standard.h"

#ifndef RECURSION_H
#define RECURSION_H

// Singly linked list with recursive operations. In header guards so it can be reused elsewhere.
// Node. Like the functions, the struct implementation is in the .c file.
struct node;
typedef struct node* Node;

// Dynamically allocate a new node.
Node newNode(int value);

// Free dynamically allocated memory in list starting from node n.
void freeList(Node n);

// Add node to end of list.
void appendNode(Node n, int value);

// Print list from starting from node n. If param newline set to true add newlines between nodes.
void printList(Node n, bool newline);

// Return 2nd last node in list.
Node get2ndLastNode(Node n);

// Delete and free 1st instance of  node with given value starting from node n. Return success.
bool delete1stInstanceOf(Node n, int value);

#endif

