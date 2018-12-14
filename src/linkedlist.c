#include<stdio.h>
#include<stdlib.h>

#include "linkedlist.h"

// Returns null if unsuccessful
// Returns the pointer to a newly created linked list
LinkedList* createList(void (*freeFunc)(void*)){

	// Invalid freeFunc input
	if(freeFunc == NULL){
		return NULL;
	}

	LinkedList* temp = malloc(sizeof(LinkedList));
	temp->size = 0;
	temp->freeFunc = freeFunc;

	return temp;
}

// Adds data to linked list at index n
// Returns 1 if successful, 0 if unsucessful
int addToList(LinkedList* list, void* data, int n){

	// if invalid input then return 0
	if(data == NULL || list == NULL || n > list->size || n < 0){
		return 0;
	}

	// Create new Node
	Node* tempNode = malloc(sizeof(Node));
	tempNode->data = data;

	// Adding to front cases
	if(n == 0){

		// First item case
		if(list->size == 0){
			list->head = tempNode;
			list->size++;
			return 1;
		} else {

		// adding to front if there is already items in list
			tempNode->next = list->head;
			list->head = tempNode;
			list->size++;
			return 1;
		}
	} else {
		// After loop curr will point to item before index n
		Node* curr = list->head;
		int i;
		for(i = 0; i < n-1; i++){
			curr = curr->next;
		}

		// Puts tempNode into place after curr at index n
		tempNode->next = curr->next;
		curr->next = tempNode;
		list->size++;
		return 1;
	}


}

// Adds to front of linked list
// Returns 1 if successful, 0 if unsuccessful
int addToFront(LinkedList* list, void* data){
	return addToList(list, data, 0);
}


// Returns pointer to value from linked list at index n
void* get(LinkedList* list, int n){

	// Unsuccessful
	if(list == NULL || n > list->size || n < 0){
		return NULL;
	} else {

		// Loops to find Node at index n
		Node * curr = list->head;
		int i;
		for(i = 0; i < n; i++){
			curr = curr->next;
		}

		// Returns the void* to data
		return curr->data;
	}
}


// Deletes value at index n of linked list. 
// returns 1 if successful, 0 if unsuccessful
int delete(LinkedList* list, int n){
	// Unsuccessful
	if(list == NULL || n >= list->size || n < 0){
		return 0;

	} else if(n == 0) {
		// Case for deleting the first item in list

		// Save deleted node so that it can be freed
		Node* deleted = list->head;

		// Remove it from list
		list->head = list->head->next;
		list->size--;

		// Frees the data
		list->freeFunc(deleted->data);

		// Free's the Node
		free(deleted);

		// successful delete
		return 1;

	} else {

		// Loops to find item before n
		Node* curr = list->head;
		int i;
		for(i = 0; i < n-1; i++){
			curr = curr->next;
		}
		// Create pointer to item to be deleted so that it can be freed later
		Node* deleted = curr->next;

		// Case for deleting the last item
		if(n == list->size){
			curr->next = NULL;
			list->size--;

			// Frees the data
			list->freeFunc(deleted->data);

			// Free's the Node
			free(deleted);

			// successful delete
			return 1;

		} else {
		// Normal case
			curr->next = curr->next->next;
			list->size--;

			// Frees the data
			list->freeFunc(deleted->data);

			// Free's the Node
			free(deleted);

			// successful delete
			return 1;
		} 
		
	}

} // end function


// Sorts a linked list using Merge Sort
// inputs; linked list to be sorted, compare function which is using in sorting
// Returns 1 if successful and 0 if unsuccessful 
int sortLinkedList(LinkedList* l, void (*compare)(void* data1, void* data2)){
	return 1;
}

// Linked List pointer should be set to NULL after using this function
// Deletes everything and frees data
void freeLinkedList(LinkedList* l){
	
	// First deletes all nodes
	while(l->size > 0){
		delete(l, 0);
	}
	
	free(l);
	l = NULL;
	
}







