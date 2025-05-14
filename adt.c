#include "recursion.h"
#include "adt.h"

// Linked list implementation of stack for integers.
struct node {
	int value;
	struct node* next;
};

struct stack {
	Node head;
	int size;
};

Stack StackNew(void) {
	Stack s = (Stack)malloc(sizeof(struct stack));
	s->size = 0;
	return s;
}

void StackFree(Stack s) {
	freeList(s->head);
	free(s);
}

void StackPush(Stack s, Node n) {
	if (s->head == NULL) {
		s->head = n;
		s->size++;
		return;
	}
	Node holder = s->head;
	s->head = n;
	s->head->next = holder;
	s->size++;
}

void StackPop(Stack s) {
	Node holder = s->head->next;
	free(s->head);
	s->head = holder;
	s->size--;
}

int StackSize(Stack s) {
	return s->size;
}

Node StackPeek(Stack s) {
	return s->head;
}

// Linked list implementation of queue for integers.
struct queue {
	Node front;
	Node back;
	int size;
};

Queue QueueNew(void) {
	Queue q = (Queue)malloc(sizeof(struct queue));
	q->size = 0;
	return q;
}

void QueueFree(Queue q) {
	freeList(q->back);
	free(q);
}

void QueueEnqueue(Queue q, Node n) {
	if (q->back == NULL) {
		q->front = n;
		q->back = n;
		q->size++;
		return;
	}
	Node holder = q->back;
	q->back = n;
	q->back->next = holder;
	q->size++;
}

void QueueDequeue(Queue q) {
	if (q->size == 1) {
		free(q->front);
		q->front = NULL;
		q->back = NULL;
	} else if (q->size == 2) {
		free(q->front);
		q->front = q->back;
	} else {
		Node holder = get2ndLastNode(q->back);
		holder->next = NULL;
		free(q->front);
		q->front = holder;
	}
	q->size--;
}

int QueueSize(Queue q) {
	return q->size;
}

Node QueuePeek(Queue q) {
	return q->back;
}
