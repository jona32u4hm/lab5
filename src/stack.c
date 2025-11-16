#include "stack.h"

void initStack(struct Stack* s) {
    s->top=-1; //indica stack vacío
}

int isEmpty(struct Stack* s) {
    return (s->top==-1); //verifica si el stack está vacío
}

int push(struct Stack*s, int value) { //agrega un elemento al inicio del stack
    if (s->top >== MAX_STACK -1) {
        return 0; //verifica si el stack está lleno
    }
    s-> top++;
    s->data[s->top]=value;
    return 1; //si no está lleno, devuelve 1
}

int pop(struct Stack* s, int* value) { //elimina y delvuelve el elemento superior
    if (isEmpty(s)) { 
        return 0; //falla si el stack está vacío
    }
    *value=s->data[s->top];
    s->top--;
    return 1; //funciona si el stack no está vacío
}

int top(struct Stack* s, int* value) {
    if (isEmpty(s)) {
        return 0 //falla si el stack está vacío
    }
    *value= s->data[s->top];
    return 1; 
}