// Lev K. 2025

// A map is an ADT that stores key-value pairs, where keys are unique. Also called dictionaries.
// Implementations:
// - Unordered array. 
// 	- Insert: O(n).
// 	- Lookup: O(n).
// 	- Delete: O(n).
// - Ordered array. 
// 	- Insert: O(n).
// 	- Lookup: O(log(n)).
// 	- Delete: O(n).
// - Balanced BST. 
// 	- Insert: O(log(n)).
// 	- Lookup: O(log(n)).
// 	- Delete: O(log(n)).
// Another implementation is the hash table. Average performance of O(1) for all ops.
// Uses array to store key-value pairs and a hash function that given a key computes an index into the array where the value is.
// Hashing is the process of mapping data of arbitrary size to fixed-sized values using a hash function.
// Hash functions must be cheap to compute, deterministic, and ideally map uniformly over the range of indices (0 ~ N - 1).
// Simple hash function for integers: int hash(int key, int N) {return key % N;}
// Often, the range of possible key values is much larger than the range of indices, which is why collisions occur. This is when two keys are hashed to the same value. A hash table must have a method for resolving collisions.
// Collision resolution methods:
// - Separate chaining. Each array entry contains a list of the items hashed to that index. Allows multiple entries in one slot.
// - Linear probing. Check rest of array slots consecutively until an empty slot is found.
// - Double hashing. Instead of checking consecutively, use an increment which is determined by secondary hash.
// Note: both the key and value are stored in the slot.
// Clustering is a problem with linear probing, where items tend to accumulate in long contiguous runs.
// An important statistic for analysing collision methods is the load faction α = M / N (items to slots).
// Double hashing uses relatively prime numbers to ensure that all slots are visited. Reduces clustering.
// Relatively prime numbers are those for which their greatest common divisor is 1, meaning they share no factors other than 1. Eg. 8 and 9.

#include "standard.h"

#ifndef HASH_H
#define HASH_H

// Hash table implementation of set.

struct set;
typedef struct set* Set;

// Helper hash functions.
int hash(int key);
int hash2(int key);

// Return new empty set.
Set SetNew(void);
// Free dynamically allocated memory in set.
void SetFree(Set s);
// Print set.
void SetPrint(Set s);
// Insert item into set.
void SetInsert(Set s, int i);
// Check if item is in set.
bool SetContains(Set s, int i);
// Delete item from set.
void SetDelete(Set s, int i);
// Return number of items in set.
int SetNumItems(Set s);
// Return number of slots in array.
int SetNumSlots(Set s);

#endif
