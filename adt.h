// Lev K. 2025

// An Abstract Data Type (ADT) is a data structure with defined operations but without a defined implementation.
// The set of operations provided by an ADT is called the interface, which is what the user interacts with. The user should not have access to the implementation.
// Generally PascalCase is used for ADTs.
// Examples:
// - Stack.
// - Queue.
// - Set.
// - Multiset.
// - Map.
// - Graph.
// - Priority Queue.

// ============================================ STACK.
// Last In First Out (LIFO).
struct stack; 
typedef struct stack* Stack;

// Dynamically allocate stack tracker.
Stack StackNew(void);

// Free all dynamically allocated memory in stack.
void StackFree(Stack s);

// Add node to top of stack.
void StackPush(Stack s, Node n);

// Remove node from top of stack. Assume not empty.
void StackPop(Stack s);

// Get stack size.
int StackSize(Stack s);

// Get node at top of stack. Assume not empty.
Node StackPeek(Stack s);

// ============================================ QUEUE.
// First In First Out (FIFO).
struct queue;
typedef struct queue* Queue;

// Dynamically allocate queue tracker.
Queue QueueNew(void);

// Free all dynamically allocated memory in queue.
void QueueFree(Queue q);

// Add node to end of queue.
void QueueEnqueue(Queue q, Node n);

// Remove node from front of queue.
void QueueDequeue(Queue q);

// Get queue size.
int QueueSize(Queue q);

// Get node at front of queue. Assume not empty.
Node QueuePeek(Queue q);

