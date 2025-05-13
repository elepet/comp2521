// Lev K. 2025

// Time complexity (tc) is the amount of time taken to run an algo as a function of the input size n.
// Tc can be found empirically by measuring the time taken over multiple runs of an algo and averaging them, or it can be found theoretically by counting the number of operations the algo does. Consider both at different input sizes.
// Empirical approach is limited by the fact that it requires an implementation and is affected by the runtime enviroment (machine, language, compiler, etc.).
// Theoretical approach is done by considering the primitive operations in the pseudocode for the algorithm. These primitive operations are the actual tasks done by the processor. Assume that they take the same amount of time.
// Primitive operations: assignment, indexing into array, calling/returning a function, evaluating an expression, increment/decrement.
// Only consider the most dominant term (e.g. tc of 2n^2 + n becomes O(n^2)). This indicates the asymptotic behaviour and is denoted with big-O notation.
// Since asymptotic tc is not affected by constant factors, instead of counting primitive ops, can just count line executions.
// Tc from fastest to slowest:
// - Constant: 1.
// - Logarithmic: log(n).
// - Linear: n.
// - N-Log-N: n * log(n).
// - Quadratic: n^2.
// - Cubic: n^3.
// - Exponential: 2^n.
// - Factorial: n!.
// There can also be multiple inputs and corresponding time complexities.
// In general, each basic nested loop adds a power to n.

// Helpers.
void plotTimeComplexity(int (*f)(int a[], int n, int value, int whoAmI));
void demonstrateSearch(int (*f)(int a[], int n, int value, int whoAmI), int n, int value);

// Searches.
int linearSearch(int a[], int n, int value, int whoAmI);
int binarySearch(int a[], int n, int value, int whoAmI);

