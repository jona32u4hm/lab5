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
} DoublyList






#endif
