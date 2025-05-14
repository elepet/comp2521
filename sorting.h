// Lev K. 2025

// Sorting involves arranging a collection of items in order based on some property (called 'key').
// May allow for faster searching (e.g. binary search).
// Provides useful intermediate for other algos (e.g. duplicate detection, merging).
// Examples:
// - Basic: selection, bubble, insertion, shell.
// - Divide-and-conquer: merge, quick.
// - Non-comparison: radix, key-indexed counting. 
// Parameters:
// - hi, index of highest item.
// - lo, index of lowest item.
// - n, number of items (hi - lo + 1).
// - c, number of comparisons.
// - s, number of swaps.
// Properties:
// - Stability: preserves relative order of items w/ equal keys.
// - Adaptability: takes advantage of existing order (sorted input much faster).
// - In-place: sorts data within original structure w/o temporary arrays.
// Cases to consider: sorted, random/average, reverse-sorted.
// Divide-and-conquer sorts split a problem into two or more subproblems, solve them recursively, then combine the results.
// It can be shown that the lower bound on worst-case tc for comparison-based sorts is O(n * log(n)). Non-comparison based sorts exploit properties of the key data to sort it and allow for better tc.

#include "standard.h"

#ifndef SORTING_H
#define SORTING_H

// Change datatype of item here and macros accordingly.
typedef int Item;
// Macro to access key in item.
#define key(A) (A)
// Macros for comparison operations.
#define lt(A, B) (key(A) <  key(B))
#define le(A, B) (key(A) <= key(B))
#define ge(A, B) (key(A) >= key(B))
#define gt(A, B) (key(A) >  key(B))

// Helpers.
void swap(Item a[], int i, int j);
void merge(Item a[], int lo, int mid, int hi);
int partition(Item a[], int lo, int hi);
void medianOfThree(Item a[], int lo, int hi);
int randInt(int lo, int hi);
void demonstrateSort(void (*f)(Item a[], int lo, int hi, int whoAmI), int n);

// ============================================ SELECTION SORT.
// Method: find smallest, swap w/ 1st element. Find 2nd smallest, swap w/ 2nd element. Etc.
// c = (n - 1) + (n - 2) + ... + 1 = 0.5 * n * (n - 1) => O(n^2).
// s = n - 1.
// Unstable, non-adaptive, in-place.
void selectionSort(Item a[], int lo, int hi, int whoAmI);

// ============================================ BUBBLE SORT.
// Method: make multiple passes from lo to hi. On each pass, swap out of order adjacent pairs. 
// Best case (sorted): c = n - 1, s = 0, tc is O(n).
// Worst case (reverse-sorted): c = (n - 1) + (n - 2) + ... + 1 = 0.5 * n * (n - 1), s = 0.5 * n * (n - 1), tc is O(n^2).
// Average case: tc is O(n^2). Can be proven.
// Stable, adaptive, in-place.
void bubbleSort(Item a[], int lo, int hi, int whoAmI);

// ============================================ INSERTION SORT.
// Method: take 1st item and treat as sorted array. Take next item and insert into sorted part, preserving order. Etc.
// Best case (sorted): c = n - 1, tc is O(n).
// Worst case (reverse-sorted): c = 1 + 2 + ... + (n - 1) = 0.5 * n * (n - 1), tc is O(n^2).
// Average case: tc is O(n^2). Can be proven.
// Stable, adaptive, in-place.
void insertionSort(Item a[], int lo, int hi, int whoAmI);

// ============================================ MERGE SORT.
// Method: split items into two roughly equal-sized parts, recursively solve partitions, merge together.
// Split into halves, so log2(n) levels. Same ops at every level. Each level requires <= n comparisons, so tc is O(n * log(n)).
// Stable, non-adaptive, not in-place.
// There is also a bottom-up approach that works iteratively.
void mergeSort(Item a[], int lo, int hi, int whoAmI);

// ============================================ QUICK SORT.
// Method: choose item to be pivot. Partition the array so that all items to left are <= pivot and all elements to right are >= pivot. Recursively sort each partiton.
void naiveQuickSort(Item a[], int lo, int hi, int whoAmI);
void medianOfThreeQuickSort(Item a[], int lo, int hi, int whoAmI);
void randomisedQuickSort(Item a[], int lo, int hi, int whoAmI);

// ============================================ RADIX SORT.
// Method: decompose each key into constituent symbols (e.g. chars for strings, digits for integers). This set of symbols is the 'radix', which is ideally small. Pad each key so thay they are the same length. Perform stable sort using rightmost symbol (e.g. g in dog, 5 in 365). Perform stable sort using next symbol. Etc.
// If radix is small, tc is O(mn), where n is no. of keys and m. is no. of symbols in each key. Radix sort outperforms comparson-based sorts when keys are short and arrays are large.
// There is Least Significant Digit (LSD) and Most Significant Digit (MSD) versions.
// Stable, non-adaptive, not in-place.

#endif
