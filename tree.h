// TODO: rotations, balancing, delete, join, avl.

// Lev K. 2025

// A tree is a hierarchical data structure consisting of connected nodes. Each node has one parent node (except root node, which has none) and may have multiple child nodes. 
// A classic example is a file system.
// A binary tree is where each node can have up to two child nodes, called the left and right child nodes.// A binary search tree (BST) is an ordered binary tree where all values in the left subtree are less than the value in the node and vice versa for right.
// BSTs are efficient to search and insert/delete.
// A leaf node is one that has no child nodes. An internal node is one that has at least one child node.
// The height (h) of a tree is the maximum path length from root to leaf (counting intervals, not nodes).
// The height of a tree determines efficiency of many operations.
// For a tree with n nodes, the maximum possible height is n - 1 and the minimum possible height is log2(n).
// A tree is said to be balanced if its height is close to minimum and degenerate if its height is close ot maximum.
// The structure, height, and hence performance depends on insertion order.
// A size-balanced tree is one that for every node |size(l) - size(r)| <= 1. A height-balanced tree is one that for every node |height(l) - height(r)| <= 1. 
// Can rotate left / right (change root left / right) to balance. Partitioning is doing this multiple times to get a specific node to be the root, usually to balance the tree.

#include "standard.h"

#ifndef TREE_H
#define TREE_H

// These tree nodes are different to the linked list nodes in recursion.h, so have to declare them separately.
struct tode;
typedef struct tode* Tode;

// Tracker.
struct tree;
typedef struct tree* Tree;

// Dynamically allocate a new tode. Integer implementation.
Tode newTode(int value);

// Dynamically allocate tree tracker.
Tree newTree(void);

// Free dynamically allocated memory in tree from root. Do not use outside of freeTree.
void freeTreeFromRoot(Tode tode);

// Free all dynamically allocated memory in tree. Assume not empty.
void freeTree(Tree t);

//// Print tree from root. Do not use outside of printTree.
void printTreeFromRoot(Tode tode, char* prefix, int isLeft, int isRoot);

// Print tree. Assume not empty.
void printTree(Tree t);

// Below are BST operations.

// Insert value into tree from root. Do not use outside of bstInsert.
void insertFromRoot(Tode tode, int value);

// Insert value into tree and return root of updated tree.
// At most one node is visited per level and the no of ops per node is constant, so O(h).
Tode bstInsert(Tree t, int value);

// Search for value in tree from root. Do not use outside of bstSearch.
bool searchFromRoot(Tode tode, int value);

// Return true if value is in tree and false otherwise.
// At most one node is visited per level and the no of ops per node is constant, so O(h).
bool bstSearch(Tree t, int value);

//// Return node with min value. Do not use outside of bstJoin.
//Tode getMinFromRoot(Tode tode);
//
//// Join two trees where max(t1) < min(t2) and return root of updated t2. Assume not empty.
//Tode bstJoin(Tree t1, Tree t2);

// Rotate tree and return root of updated tree. Assume not empty.
// Left -> bigger becomes root, right -> smaller becomes root.
Tode rotate(Tree t, char leftOrRight);

#endif
