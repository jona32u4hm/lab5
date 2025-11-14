#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>


   //    head -nxt-> node -> ... <-prv- tail 

typedef struct {
	void *data;
	struct node *prev;
	struct node *next;
} DoublyNode;
typedef struct {
	DoublyNode *head;
	DoublyNode *tail;
	int size;
	char type_indicator; //data type must be defined when creating the list and this must be repected afterwards
} DoublyList



void doublyInsertHead(DoublyList *doublyList, void *data){
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
		doublyList->head->prev = &newNode;
		doublyList->head = newNode;
	}
	doublyList->size++;
}

void doublyInsertTail(DoublyList *doublyList, void *data){
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
		doublyList->tail->next = &newNode;
		doublyList->tail = newNode;
	}
	doublyList->size++;
}

void doublyInsert(DoublyList *doublyList, void *data, int index){
	DoublyNode *indexNode = doublyList->head;
	if (index > doublyList->size) return; // el index debe estar dentro de la lista
	
	if (doublyList->head == NULL) {
        // Si está vacía el nuevo nodo es la cabeza y la cola a la vez.
        newNode->prev = NULL;
        newNode->next = NULL;
        doublyList->head = newNode;
        doublyList->tail = newNode;
    }else{
		for (index > 0, index--){//recorrer la lista
			indexNode = indexNode->next;
		}
		
		DoublyNode *newNode = malloc(sizeof(DoublyNode));
		if (newNode == NULL) return;
		
		newNode->prev = indexNode->prev;
		newNode->next = indexNode;
	
	}
	doublyList->size++;
}



