#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 100

// Estrutura para um símbolo na tabela
typedef struct Symbol {
    char *name;                 // Nome do identificador
    char *type;                 // Tipo de dado (string)
    int offset;                 // Offset/endereço relativo
    struct Symbol *next;        // Próximo símbolo na lista (para colisões)
} Symbol;

// Estrutura da tabela de símbolos
typedef struct SymbolTable {
    Symbol *table[HASH_TABLE_SIZE];     // Array de ponteiros para símbolos
    struct SymbolTable *parent;         // Ponteiro para tabela pai (escopo externo)
    int next_offset;                    // Próximo offset disponível
} SymbolTable;

// Variável global da tabela de símbolos atual
extern SymbolTable *current_table;

// Protótipos das funções
SymbolTable* create_symbol_table(SymbolTable *parent);
void destroy_symbol_table(SymbolTable *table);
unsigned int hash_function(const char *name);
int insert_symbol(SymbolTable *table, const char *name, const char *type);
Symbol* lookup_symbol(SymbolTable *table, const char *name);
Symbol* lookup_symbol_current_scope(SymbolTable *table, const char *name);
void enter_scope();
void exit_scope();
void print_symbol_table(SymbolTable *table);
void init_symbol_table();
void cleanup_symbol_table();

#endif 