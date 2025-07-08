#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 211

// Enumeração para tipos básicos
typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_VOID,
    TYPE_INT_ARRAY,
    TYPE_FLOAT_ARRAY,
    TYPE_CHAR_ARRAY,
    TYPE_FUNCTION,
    TYPE_STRUCT,
    TYPE_ERROR
} SymbolType;

// Estrutura para um símbolo na tabela
typedef struct Symbol {
    char *name;
    char *type_string;      // String original do tipo (para compatibilidade)
    SymbolType type;        // Tipo enumerado para análise semântica
    int offset;
    int array_size;         // Para arrays - tamanho
    struct Symbol *next;
} Symbol;

// Estrutura para a tabela de símbolos
typedef struct SymbolTable {
    Symbol *table[HASH_TABLE_SIZE];
    struct SymbolTable *parent;
    struct SymbolTable *next_scope;  // Ponteiro para próxima tabela na ordem de criação
    int next_offset;
} SymbolTable;

// Variável global da tabela de símbolos atual
extern SymbolTable *current_table;

// Protótipos das funções
SymbolTable* criarTabelaSimbolos(SymbolTable *parent);
void destruirTabela(SymbolTable *table);
unsigned int hash_function(const char *name);
int inserirSimbolo(SymbolTable *table, const char *name, const char *type);
Symbol* procurarSimbolo(SymbolTable *table, const char *name);
Symbol* procuraEscopoAtual(SymbolTable *table, const char *name);
void enter_scope(void);
void exit_scope(void);
void imprimirTabela(SymbolTable *table);
void imprimirTodasTabela(SymbolTable *table);
void iniciarTabelaDeSimbolos(void);
void limparTabela(void);

// Funções para análise semântica de tipos
SymbolType stringParaTipo(const char *type_str);
const char* symbol_type_to_string(SymbolType type);
SymbolType get_base_type(SymbolType type);
int is_numeric_type(SymbolType type);
int is_array_type(SymbolType type);
int types_compatible(SymbolType type1, SymbolType type2);
SymbolType get_operation_result_type(SymbolType type1, SymbolType type2, const char *op);

#endif 