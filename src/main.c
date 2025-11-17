#include <stdio.h>
#include "stack.h"
#include "../include/doubly_linked_list.h"

DoublyList myList;

int main_doublylist(){
	printf("testing doubly_linked_list.h\n");
	printf("\ninsert head 5 (empty list)\n");
	doublyInsertHead(&myList, 5);
    doublyPrint(&myList); // expected: 5
    
	printf("\ninsert head 10 15\n");
    doublyInsertHead(&myList, 10);
    doublyInsertHead(&myList, 15);
    doublyPrint(&myList); // 
    
	printf("\ninsert tail 20 1\n");
    doublyInsertTail(&myList, 20);
    doublyInsertTail(&myList, 1); 
	doublyPrint(&myList); // 15 10 5 20 1
    
	printf("\ninsert at index 2, 99\n");
    doublyInsert(&myList, 99, 2);
	printf("\nprinted forward:\n");
	doublyPrint(&myList); // 15 10 99 5 20 1
	printf("\nprinted backwards:\n");
	doublyPrintBack(&myList); 
	
	
	printf("\nsearch...\n");
	DoublyNode *found_node = doublySearch(&myList, 99);
    if (found_node != NULL) {
        printf("99: FOUND. Data: %d\n", found_node->data);
    } else {
        printf("99: NOT FOUND.\n");
    }

    found_node = doublySearch(&myList, 500);
    if (found_node == NULL) {
        printf("500: NOT FOUND.\n");
    }
	
	printf("\ndelete... (99)\n");
	doublyDelete(&myList, 99);
    doublyPrint(&myList); // 15 10 5 20 1
	
	
	printf("\ndeleting unexistant\n");
	doublyDelete(&myList, 1000);
    doublyPrint(&myList); // 15 10 5 20 1
    
    printf("\ncurrent list size check: %d\n", myList.size);
    
    
	printf("\nemptying...(cleanup)\n");
    doublyDestroy(&myList); //cleanup	 
	printf("\nemptied\n");
    
    printf("list size now: %d\n", myList.size);
	
	return 0;
}

int main_stack(){
    struct Stack s;
    initStack(&s); //incia el stack

    //aquí va a ir el push de elementos:
    push(&s, 10);
    printf("Push: 10 \n");
    push(&s, 20);
    printf("Push: 20 \n");
    push(&s, 30);
    printf("Push: 30 \n");
    int val;

    //pop
    pop(&s, &val);
    printf("Pop: %d\n", val);
	//top
    top(&s, &val);
    printf("Top: %d\n", val);

    //Verificar si está vacío
    if (isEmpty(&s)) {
        printf("El stack está vacío\n");
    }
    else {
        printf("El stack no está vacío\n");
    }

    printf("A continuación, se va a vaciar el stack... \n");
    //Pop hasta vaciar stack para que esté vacío
    pop(&s, &val);
    pop(&s, &val);
    if (isEmpty(&s)) {
        printf("El stack está vacío\n");
    }
    else {
        printf("El stack no está vacío\n"); //debe imprimir que está vacío
    } 
}
int main(){
    main_doublylist();
    main_stack();
    return 0;
}
