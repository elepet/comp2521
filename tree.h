// TODO: local rebalancing, delete, join, avl.

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

// Dynamically allocate a new tode. Integer implementation.
Tode bstNewTode(int value);

// Free dynamically allocated memory in tree from tode t.
void bstFree(Tode t);

// Recursively print tree from tode t. Helper for bstPrint. Assume not empty.
//void bstPrintRecurse(Tode t, char* prefix, int isLeft, int isRoot, int hasRightPeer);
void bstPrintRecurse(Tode t, char* prefix, int isRight, int isRoot, int hasLeftPeer);

// Print tree from tode t.
void bstPrint(Tode t);

// Insert value into tree from tode t and return root of updated tree.
// At most one node is visited per level and the no of ops per node is constant, so O(h).
Tode bstInsert(Tode t, int value);

// Search for value in tree from tode t.
// At most one node is visited per level and the no of ops per node is constant, so O(h).
bool bstSearch(Tode t, int value);

// Rotate tree and return root of updated tree. Assume not empty.
// Left -> bigger becomes root, right -> smaller becomes root.
// Tc is O(1).
Tode bstRotate(Tode t, char leftOrRight);

// Return size of subtree from tode t. Assume not empty.
int bstSize(Tode t);

// Given root tode t, find element with index i, rotate to lift it to root, return root of updated tree.
Tode bstPartition(Tode t, int i);

// Globally size-rebalance tree, return root. Assume not empty.
// O(n * log(n)).
Tode bstRebalance(Tode t);

#endif
