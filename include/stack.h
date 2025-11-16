#ifndef STACK_H
#define STACK_H

struch StackNode {
    int data;
    struct StackNode* next;
}
//esta parte es la estructura de un nodo del stack

struct Stack {
    struct StackNode* top;
}
//estructura del stack

void initStack(struct Stack* stack); //crea stack vacío
void push(struct Stack* stack, init value); //elemento a parte superior
int pop(struct Stack* stack); //elimina y retorna elemento superior
int pek(struct Stack* stack); //devuelve elemento superior sin eliminarlo
int isEmpty(struct Stack stack);//verifica stack vacío
void freeStack(struct Stack* stack); //libera nodos

#endif