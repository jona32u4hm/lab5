#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

   // doubly_linked_list.h 
   // doubly linked list structure:
   //    head -nxt-> node -> ... <-prv- tail 
   //

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

void doublyInsertHead(DoublyList *doublyList, void *data);
void doublyInsertTail(DoublyList *doublyList, void *data);
void doublyInsert(DoublyList *doublyList, void *data, int index);
void doublyDelete(DoublyList *doublyList, int data);
DoublyNode doublySearch(DoublyList *doublyList, void data);
void doublyPrint(DoublyList *doublyList);
void doublyPrintBack(DoublyList *doublyList);






#endif
