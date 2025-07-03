#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 100
#define MAX_SCOPE_LEVEL 50

// Tipos de dados suportados
typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_VOID,
    TYPE_STRUCT,
    TYPE_ARRAY
} tipoDado;

// Estrutura para um símbolo na tabela
typedef struct Symbol {
    char *name;                 // Nome do identificador
    tipoDado type;              // Tipo de dado
    tipoDado array_base_type;   // Tipo base do array (se for array)
    int address;                // Endereço relativo
    int scope_level;            // Nível de escopo
    int array_size;             // Tamanho do array (se for array)
    struct Symbol *next;        // Próximo símbolo na lista (para colisões)
} Symbol;

// Estrutura da tabela de símbolos
typedef struct SymbolTable {
    Symbol *table[HASH_TABLE_SIZE];
    int current_scope;
    int next_address;
} SymbolTable;

// Variável global da tabela de símbolos
extern SymbolTable symbol_table;

// Protótipos das funções
void init_symbol_table();
unsigned int hash_function(const char *name);
int insert_symbol(const char *name, tipoDado type, int array_size);
int insert_array_symbol(const char *name, tipoDado base_type, int array_size);
Symbol* lookup_symbol(const char *name);
void enter_scope();
void exit_scope();
void print_symbol_table();
const char* type_to_string(tipoDado type);
void free_symbol_table();

#endif 