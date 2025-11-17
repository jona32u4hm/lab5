#include "stack.h"

void initStack(struct Stack* s) {
    s->top=-1; //Says stack empty
}

int isEmpty(struct Stack* s) {
    return (s->top==-1); // Verifies if the stack is empty
}

int push(struct Stack*s, int value) { // Adds an elemnt at the begining of the stack
    if (s->top >=MAX_STACK -1) {
        return 1; // Stack full
    }
    s-> top++;
    s->data[s->top]=value;
    return 0; // Succes

}

int pop(struct Stack* s, int* value) { // Eliminates and returns top element
    if (isEmpty(s)) { 
        return 1; 
    }
    *value=s->data[s->top];
    s->top--;
    return 0; 
}

int top(struct Stack* s, int* value) {
    if (isEmpty(s)) {
        return 1; 
    }
    *value= s->data[s->top];
    return 0; 
}
