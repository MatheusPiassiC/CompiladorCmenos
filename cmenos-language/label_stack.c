#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "label_stack.h"

void init_label_stack(LabelStack *ls) {
    ls->top = -1;
}

void push_label(LabelStack *ls, LabelPair pair) {
    if (ls->top >= MAX_LABEL_STACK - 1) {
        fprintf(stderr, "Erro: Pilha de rótulos cheia\n");
        return;
    }
    ls->top++;
    ls->stack[ls->top].label1 = strdup(pair.label1);
    ls->stack[ls->top].label2 = strdup(pair.label2);
}

LabelPair pop_label(LabelStack *ls) {
    LabelPair empty = {NULL, NULL};

    if (ls->top < 0) {
        fprintf(stderr, "Erro: Pilha de rótulos vazia\n");
        return empty;
    }

    LabelPair pair = ls->stack[ls->top];
    ls->top--;
    return pair;
}

int is_label_stack_empty(LabelStack *ls) {
    return ls->top < 0;
}

void free_label_stack(LabelStack *ls) {
    while (!is_label_stack_empty(ls)) {
        LabelPair pair = pop_label(ls);
        if (pair.label1) free(pair.label1);
        if (pair.label2) free(pair.label2);
    }
}
