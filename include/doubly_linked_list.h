#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

   // doubly_linked_list.h 
   // doubly linked list structure:
   //    head -nxt-> node -> ... <-prv- tail 
   //

struct DoublyNode{
	int data;
	struct DoublyNode *prev;
	struct DoublyNode *next;
};
typedef struct DoublyNode DoublyNode;
typedef struct {
	DoublyNode *head;
	DoublyNode *tail;
	int size;
} DoublyList;

void doublyInsertHead(DoublyList *doublyList, int data);
void doublyInsertTail(DoublyList *doublyList, int data);
void doublyInsert(DoublyList *doublyList, int data, int index);
void doublyDelete(DoublyList *doublyList, int data);
DoublyNode *doublySearch(DoublyList *doublyList, int data);
void doublyPrint(DoublyList *doublyList);
void doublyPrintBack(DoublyList *doublyList);






#endif
