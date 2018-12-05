#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

// Node holds a pointer to data and pointer to next Node
typedef struct node{
	void* data;
	struct node* next;
}Node;

// LinkedList holds the first Node and a size
typedef struct{
	Node* head;
	int size;
	void (*freeFunc)(void*);
} LinkedList;


LinkedList* createList(void (*freeFunc)(void*));

// Adds to a linked list at position n starting at 0
// Returns 1 if successful or 0 if unsuccessful
// Assumes data is malloc'd
int addToList(LinkedList* list, void* data, int n);

// Adds to the front of a linked list
// Calls add with n = 0
// Returns 1 if successful and 0 if unsuccessful
int addToFront(LinkedList* list, void* data);

// returns pointer to data at index n
// returns Null pointer if out of range or unsuccessful
void* get(LinkedList* list, int n);

// returns a 1 if successful or 0 if unsuccessful
int delete(LinkedList* list, int n);

#endif
