#ifndef STACK_H
#define STACK_H
#define MAX_STACK 100

struct Stack {
    int data[MAX_STACK];
    int top;
};
//estructura del stack

void initStack(struct Stack* stack); //crea stack vacío
int isEmpty(struct Stack* stack);
int push(struct Stack* stack, int value);
int pop(struct Stack* stack, int* value);
int top(struct Stack* stack, int* value);

#endif