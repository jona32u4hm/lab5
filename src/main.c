#include <stdio.h>
#include "stack.h"
#include "doubly_linked_list.h"
#include "dynamic_arrays.h"

DoublyList myList;

int main_doublylist(){
    printf("Testing doubly_linked_list.h\n");
    printf("\nInsert as head 5 (empty list)\n");
    doublyInsertHead(&myList, 5);
    doublyPrint(&myList); // expected: 5
    
    printf("\nInsert as head 10 then 15\n");
    doublyInsertHead(&myList, 10);
    doublyInsertHead(&myList, 15);
    doublyPrint(&myList); // 15 10 5
    
    printf("\nInsert as tail 20 then 1\n");
    doublyInsertTail(&myList, 20);
    doublyInsertTail(&myList, 1); 
    doublyPrint(&myList); // 15 10 5 20 1
    
    printf("\nInsert at index 2, 99\n");
    doublyInsert(&myList, 99, 2);
    doublyPrint(&myList); // 15 10 99 5 20 1

    printf("\nPrinted backwards:\n");
    doublyPrintBack(&myList); 
	
	
    printf("\n\nSearch 99\n");
    DoublyNode *found_node = doublySearch(&myList, 99);
    if (found_node != NULL) {
        printf("99: FOUND. Data: %d\n", found_node->data);
    } else {
        printf("99: NOT FOUND.\n");
    }

    printf("Search 500\n");
    found_node = doublySearch(&myList, 500);
    if (found_node != NULL) {
        printf("500: FOUND. Data: %d\n", found_node->data);
    } else {
        printf("500: NOT FOUND.\n");
    }	

    printf("\nDelete (99)\n");
    doublyDelete(&myList, 99);
    doublyPrint(&myList); // 15 10 5 20 1
	
	
    printf("\nDeleting unexistant value 1000\n");
    doublyDelete(&myList, 1000);
    doublyPrint(&myList); // 15 10 5 20 1
    
    printf("\nCurrent list size check: %d\n", myList.size);
    
    
    printf("\nEmptying...(cleanup)\n");
    doublyDestroy(&myList); // Cleanup	 
    printf("\nEmptied\n");
    
    printf("List size now: %d\n", myList.size);
    printf("End of doublylist testing\n");
	
    return 0;
}

int main_stack(){
    printf("\nTesting stack.h\n");
    printf("\nCreating an empty stack and pushing elements\n");
    struct Stack s;
    initStack(&s); 

    // Pushing elements:
    push(&s, 10);
    printf("Push: 10 \n");
    push(&s, 20);
    printf("Push: 20 \n");
    push(&s, 30);
    printf("Push: 30 \n");
    int val;    //val will contain top value
    top(&s, &val);
    printf("Top: %d\n", val);
	
    
    // Using pop
    printf("\nTop value will be popped and the new top value will be printed");
    pop(&s, &val);
    printf("\nPop: %d\n", val);
    top(&s, &val);
    printf("Top: %d\n", val);

    // Check if is empty
    printf("\nChecking if the stack is empty...\n");
    if (isEmpty(&s)) {
        printf("Stack is empty\n");
    }
    else {
        printf("Stack is not empty\n");
    }

    printf("Emptying stack...\n");
    // Pop until there is nothing left
    pop(&s, &val);
    pop(&s, &val);
    if (isEmpty(&s)) {
        printf("Stack is empty\n");
    }
    else {
        printf("Stack is not empty\n"); // Expected to be empty
    }
    printf("End of stack testing\n");
    return 0; 
}

int main_dynamic_arrays() {
    printf("\nTesting stack.h\n");

    printf("\nCreating array...\n");
    int* array = create_array();
    print_array(array);
    
    printf("\n\nAdding elements to the array...\n");
    for (int i = 1; i <= 6; i++) {
	array = add_element(array, i);
    }
    print_array(array);

    printf("\n\nEliminating the element at index 4...\n");
    array = eliminate_element(array, 4);
    print_array(array);

    printf("\n\nGetting the value at index 4...");
    int val = get_element(array, 4);
    printf("\n%d\n", val);
    
    //Normalizing array
    printf("\nThe array will be printed manually\n");
    printf("[");
    for (int i = 0; i <= *array; i++) {
	if (i != *array) {
	    printf("%d,", *(array+i));
	} else {
	    printf("%d", *(array+i));
	}
    }
    printf("]");
    printf("\nFirst element contains the size of the array");
    printf("\nNormalizing array...");
    int size = get_element(array, -1);
    array = normalize_array(array);
    printf("\nThe array will be printed manually\n");
    printf("[");
    for (int i = 0; i <= size-1; i++) {
	if (i != size-1) {
	    printf("%d,", *(array+i));
	} else {
	    printf("%d", *(array+i));
	}
    }
    printf("]");
    free(array);
    array = NULL
    return 0;
}

int main(){
    main_doublylist();
    main_stack();
    main_dynamic_arrays();
    return 0;
}
