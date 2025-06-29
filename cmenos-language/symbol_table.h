#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enumeração para tipos de símbolos
typedef enum {
    SYMBOL_VAR,
    SYMBOL_FUNC,
    SYMBOL_STRUCT,
    SYMBOL_PARAM
} SymbolType;

// Enumeração para tipos de dados
typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_VOID,
    TYPE_STRUCT,
    TYPE_ARRAY
} DataType;

// Estrutura para armazenar informações de um símbolo
typedef struct Symbol {
    char name[100];           // Nome do símbolo
    SymbolType type;          // Tipo do símbolo (variável, função, etc.)
    DataType dataType;        // Tipo de dados
    char structName[100];     // Nome da estrutura (se aplicável)
    int arrayDimensions;      // Número de dimensões do array
    int arraySizes[10];       // Tamanhos das dimensões
    int line;                 // Linha onde foi declarado
    int column;               // Coluna onde foi declarado
    int scope;                // Escopo do símbolo
    struct Symbol* next;      // Próximo símbolo na lista
} Symbol;

// Estrutura da tabela de símbolos
typedef struct {
    Symbol* head;             // Primeiro símbolo na tabela
    int currentScope;         // Escopo atual
    int symbolCount;          // Contador de símbolos
} SymbolTable;

// Funções da tabela de símbolos
SymbolTable* createSymbolTable();
void destroySymbolTable(SymbolTable* table);
Symbol* insertSymbol(SymbolTable* table, const char* name, SymbolType type, DataType dataType, int line, int column);
Symbol* lookupSymbol(SymbolTable* table, const char* name, int scope);
Symbol* lookupSymbolGlobal(SymbolTable* table, const char* name);
void enterScope(SymbolTable* table);
void exitScope(SymbolTable* table);
void printSymbolTable(SymbolTable* table);
void removeSymbolsInScope(SymbolTable* table, int scope);

// Funções auxiliares
const char* getSymbolTypeName(SymbolType type);
const char* getDataTypeName(DataType type);
DataType getDataTypeFromToken(int token);

#endif 