#ifndef LABEL_STACK_H
#define LABEL_STACK_H

#define MAX_LABEL_STACK 100

typedef struct {
    char* label1;
    char* label2;
} LabelPair;

typedef struct {
    LabelPair stack[MAX_LABEL_STACK];
    int top;
} LabelStack;

// Inicializa a pilha
void init_label_stack(LabelStack *ls);

// Empilha um par de rótulos
void push_label(LabelStack *ls, LabelPair pair);

// Desempilha um par de rótulos
LabelPair pop_label(LabelStack *ls);

// Verifica se a pilha está vazia
int is_label_stack_empty(LabelStack *ls);

// Libera memória de todos os elementos da pilha
void free_label_stack(LabelStack *ls);

#endif
