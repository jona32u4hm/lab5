#include "../include/doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>


   //    head -nxt-> node -> ... <-prv- tail 





void doublyInsertHead(DoublyList *doublyList, int data){
	DoublyNode *newNode = malloc(sizeof(DoublyNode));
	if (newNode == NULL) return;
	//hay que hacer: *newNode = {.data = data, .next = *doublyList->head, .prev = NULL};
	
	newNode->data = data;
	newNode->prev = NULL;
	if (doublyList->head == NULL) {
        // Si está vacía el nuevo nodo es la cabeza y la cola a la vez.
        newNode->next = NULL;
        doublyList->head = newNode;
        doublyList->tail = newNode;
    } else {
		newNode->next = doublyList->head;
		doublyList->head->prev = newNode;
		doublyList->head = newNode;
	}
	doublyList->size++;
}

void doublyInsertTail(DoublyList *doublyList, int data){
	DoublyNode *newNode = malloc(sizeof(DoublyNode));
	if (newNode == NULL) return;
	//hay que hacer: *newNode = {.data = data, .prev = *doublyList->tail, .next = NULL};
	
	newNode->data = data;
	newNode->next = NULL;
	if (doublyList->head == NULL) {
        // Si está vacía el nuevo nodo es la cabeza y la cola a la vez.
        newNode->prev = NULL;
        doublyList->head = newNode;
        doublyList->tail = newNode;
    } else {
		newNode->prev = doublyList->tail;
		doublyList->tail->next = newNode;
		doublyList->tail = newNode;
	}
	doublyList->size++;
}

void doublyInsert(DoublyList *doublyList, int data, int index){
	if (index > doublyList->size) return; // index must be in list range
	DoublyNode *newNode = malloc(sizeof(DoublyNode));
	newNode->data = data;
	DoublyNode *indexNode = doublyList->head;
	if (doublyList->head == NULL) {
        // Si está vacía el nuevo nodo es la cabeza y la cola a la vez.
        newNode->prev = NULL;
        newNode->next = NULL;
        doublyList->head = newNode;
        doublyList->tail = newNode;
    }else{
		for (;index > 0; index--){//recorrer la lista
			indexNode = indexNode->next;
		}
		
		if (newNode == NULL) return;
		
		newNode->prev = indexNode->prev;
		newNode->next = indexNode;
		indexNode->prev->next = newNode;
		indexNode->prev = newNode;
	
	}
	doublyList->size++;
}

void doublyDelete(DoublyList *doublyList, int data){
	DoublyNode *indexNode = doublyList->head;
	while (1){
		if (indexNode == NULL) return; //already at end of list
		if (indexNode->data == data) {
			// close the gap
			if(indexNode->prev == NULL) doublyList->head = indexNode->next;
			else{
				indexNode->prev->next = indexNode->next;
			}
			if(indexNode->next == NULL) doublyList->tail = indexNode->prev;
			else{
				indexNode->next->prev = indexNode->prev;
			}
			
			// delete *indexNode
			free(indexNode);
			indexNode = NULL; 
			doublyList->size--;
		}
		indexNode = indexNode->next;
	}
}

DoublyNode *doublySearch(DoublyList *doublyList, int data){
	DoublyNode *indexNode = doublyList->head;
	for (int index = doublyList->size; index > 0; index--){
		if (indexNode->data == data) return indexNode;
	}
	return NULL;
}

void doublyPrint(DoublyList *doublyList){
	DoublyNode *indexNode = doublyList->head;
	while (1){
		if (indexNode == NULL) return; //already at end of list
		printf(" %d ", indexNode->data);
		indexNode = indexNode->next;
	}
}

void doublyPrintBack(DoublyList *doublyList){
	DoublyNode *indexNode = doublyList->tail;
	while (1){
		if (indexNode == NULL) return; //already at front of list
		printf(" %d ", indexNode->data);
		indexNode = indexNode->prev;
	}
}

void doublyDestroy(DoublyList *doublyList){
	DoublyNode *indexNode = doublyList->head;
	DoublyNode *nextNode = doublyList->head;
	
	while (1){
		if (indexNode == NULL) return; //already at end of list
		nextNode = indexNode->next;
		free(indexNode);
		indexNode = nextNode;
	}
}




