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
	if (index > doublyList->size) return; // index must be in list range
	
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

void doublyDelete(DoublyList *doublyList, int data){
	DoublyNode *indexNode = doublyList->head;
	while (1){
	if (indexNode == NULL) return; //already at end of list
	if (*indexNode->data != data) continue;
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
}

DoublyNode doublySearch(DoublyList *doublyList, void data){
	DoublyNode *indexNode = doublyList->head;
	for (index = doublyList->size, index > 0, index--){
		if (*indexNode->data == data) return indexNode;
	}
	return NULL;
}

void doublyPrint(DoublyList *doublyList){
	DoublyNode *indexNode = doublyList->head;
	while (1){
		if (indexNode == NULL) return; //already at end of list
		//print Node 
		indexNode = indexNode->next;
	}
}

void doublyPrintBack(DoublyList *doublyList){
	if(doublyList->type_indicator == NULL) {
		printf("unspecified data type");
		return;
	}
	DoublyNode *indexNode = doublyList->tail;
	while (1){
		if (indexNode == NULL) return; //already at end of list
		doublyPrintNode(indexNode, doublyList->type_indicator); 
		indexNode = indexNode->prev;
	}
}

void doublyPrintNode(DoublyNode *node, char type_indicator){
    switch (type_indicator) {
        case 'c': // char
            printf("%c", *(char*)node->data);
            break;
        case 's': // short
            printf("%hd", *(short*)node->data);
            break;
        case 'i': // int
            printf("%d", *(int*)node->data);
            break;
        case 'l': // long
            printf("%ld", *(long*)node->data);
            break;
        case 'f': // float
            printf("%f", *(float*)node->data);
            break;
        case 'd': // double
            printf("%lf", *(double*)node->data);
            break;
        case 'L': // long double
            printf("%Lf", *(long double*)node->data);
            break;
        case 'p': // pointer (address)
            printf("%p", *(void*)node->data); 
            break;
        case 'S': // string (char array)
            // For strings, the void* is a char* to the start of string
            printf("%s", (char*)node->data);
            break;
        default:
            printf("Unknown or unsupported type indicator: %c", type_indicator);
            break;
    }
}


