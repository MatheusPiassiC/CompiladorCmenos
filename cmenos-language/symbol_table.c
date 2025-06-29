#include "symbol_table.h"

// Cria uma nova tabela de símbolos
SymbolTable* createSymbolTable() {
    SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
    if (table) {
        table->head = NULL;
        table->currentScope = 0;
        table->symbolCount = 0;
    }
    return table;
}

// Destrói a tabela de símbolos e libera a memória
void destroySymbolTable(SymbolTable* table) {
    if (!table) return;
    
    Symbol* current = table->head;
    while (current) {
        Symbol* next = current->next;
        free(current);
        current = next;
    }
    free(table);
}

// Insere um símbolo na tabela
Symbol* insertSymbol(SymbolTable* table, const char* name, SymbolType type, DataType dataType, int line, int column) {
    if (!table || !name) return NULL;
    
    // Verifica se o símbolo já existe no escopo atual
    Symbol* existing = lookupSymbol(table, name, table->currentScope);
    if (existing) {
        printf("ERRO: Símbolo '%s' já declarado no escopo atual (linha %d, coluna %d)\n", 
               name, line, column);
        return NULL;
    }
    
    // Cria um novo símbolo
    Symbol* symbol = (Symbol*)malloc(sizeof(Symbol));
    if (!symbol) return NULL;
    
    strcpy(symbol->name, name);
    symbol->type = type;
    symbol->dataType = dataType;
    symbol->line = line;
    symbol->column = column;
    symbol->scope = table->currentScope;
    symbol->arrayDimensions = 0;
    symbol->structName[0] = '\0';
    
    // Insere no início da lista
    symbol->next = table->head;
    table->head = symbol;
    table->symbolCount++;
    
    return symbol;
}

// Busca um símbolo no escopo especificado
Symbol* lookupSymbol(SymbolTable* table, const char* name, int scope) {
    if (!table || !name) return NULL;
    
    Symbol* current = table->head;
    while (current) {
        if (strcmp(current->name, name) == 0 && current->scope == scope) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Busca um símbolo globalmente (em qualquer escopo)
Symbol* lookupSymbolGlobal(SymbolTable* table, const char* name) {
    if (!table || !name) return NULL;
    
    Symbol* current = table->head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Entra em um novo escopo
void enterScope(SymbolTable* table) {
    if (table) {
        table->currentScope++;
    }
}

// Sai do escopo atual
void exitScope(SymbolTable* table) {
    if (table && table->currentScope > 0) {
        removeSymbolsInScope(table, table->currentScope);
        table->currentScope--;
    }
}

// Remove todos os símbolos de um escopo específico
void removeSymbolsInScope(SymbolTable* table, int scope) {
    if (!table) return;
    
    Symbol* current = table->head;
    Symbol* prev = NULL;
    
    while (current) {
        if (current->scope == scope) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->head = current->next;
            }
            
            Symbol* toDelete = current;
            current = current->next;
            free(toDelete);
            table->symbolCount--;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// Imprime a tabela de símbolos
void printSymbolTable(SymbolTable* table) {
    if (!table) {
        printf("Tabela de símbolos não existe.\n");
        return;
    }
    
    printf("\n=== TABELA DE SÍMBOLOS ===\n");
    printf("Escopo atual: %d\n", table->currentScope);
    printf("Total de símbolos: %d\n\n", table->symbolCount);
    
    printf("%-15s %-10s %-10s %-15s %-8s %-8s %-8s\n", 
           "Nome", "Tipo", "Tipo Dados", "Estrutura", "Linha", "Coluna", "Escopo");
    printf("----------------------------------------------------------------\n");
    
    Symbol* current = table->head;
    while (current) {
        printf("%-15s %-10s %-10s %-15s %-8d %-8d %-8d\n",
               current->name,
               getSymbolTypeName(current->type),
               getDataTypeName(current->dataType),
               current->structName[0] ? current->structName : "-",
               current->line,
               current->column,
               current->scope);
        current = current->next;
    }
    printf("================================================================\n\n");
}

// Retorna o nome do tipo de símbolo
const char* getSymbolTypeName(SymbolType type) {
    switch (type) {
        case SYMBOL_VAR: return "Variavel";
        case SYMBOL_FUNC: return "Funcao";
        case SYMBOL_STRUCT: return "Estrutura";
        case SYMBOL_PARAM: return "Parametro";
        default: return "Desconhecido";
    }
}

// Retorna o nome do tipo de dados
const char* getDataTypeName(DataType type) {
    switch (type) {
        case TYPE_INT: return "int";
        case TYPE_FLOAT: return "float";
        case TYPE_CHAR: return "char";
        case TYPE_VOID: return "void";
        case TYPE_STRUCT: return "struct";
        case TYPE_ARRAY: return "array";
        default: return "desconhecido";
    }
}

// Converte um token para o tipo de dados correspondente
DataType getDataTypeFromToken(int token) {
    switch (token) {
        case 258: // INT
            return TYPE_INT;
        case 259: // FLOAT
            return TYPE_FLOAT;
        case 260: // CHAR
            return TYPE_CHAR;
        case 261: // VOID
            return TYPE_VOID;
        case 262: // STRUCT
            return TYPE_STRUCT;
        default:
            return TYPE_INT; // Padrão
    }
} 