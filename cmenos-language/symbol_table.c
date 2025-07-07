#include "symbol_table.h"

// Variável global da tabela de símbolos
SymbolTable symbol_table;

// Inicializa a tabela de símbolos
void init_symbol_table() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        symbol_table.table[i] = NULL;
    }
    symbol_table.current_scope = 0;
    symbol_table.next_address = 0;
}

// Função hash simples
unsigned int hash_function(const char *name) {
    unsigned int hash = 0;
    while (*name) {
        hash = (hash * 31 + *name) % HASH_TABLE_SIZE;
        name++;
    }
    return hash;
}

// Função auxiliar para calcular o tamanho em bytes de um tipo
int get_type_size(tipoDado type) {
    switch (type) {
        case TYPE_INT:
        case TYPE_FLOAT:
            return 4;
        case TYPE_CHAR:
            return 1;
        default:
            return 4;
    }
}

// Insere um símbolo de array na tabela
int insert_array_symbol(const char *name, tipoDado base_type, int array_size) {
    // Verifica se já existe no escopo atual
    Symbol *existing = lookup_symbol(name);
    if (existing != NULL && existing->scope_level == symbol_table.current_scope) {
        printf("ERRO: Identificador '%s' já declarado no escopo atual\n", name);
        return 0;
    }
    
    unsigned int index = hash_function(name);
    Symbol *new_symbol = (Symbol*)malloc(sizeof(Symbol));
    if (new_symbol == NULL) {
        printf("ERRO: Falha na alocação de memória para símbolo\n");
        return 0;
    }
    
    new_symbol->name = strdup(name);
    new_symbol->type = TYPE_ARRAY;
    new_symbol->array_base_type = base_type;
    new_symbol->scope_level = symbol_table.current_scope;
    new_symbol->array_size = array_size;
    new_symbol->address = symbol_table.next_address;
    
    // Calcula o tamanho total do array
    int element_size = get_type_size(base_type);
    symbol_table.next_address += array_size * element_size;
    
    new_symbol->next = symbol_table.table[index];
    symbol_table.table[index] = new_symbol;
    
    printf("Array '%s' inserido no escopo %d, endereço %d, tamanho total %d bytes\n", 
           name, symbol_table.current_scope, new_symbol->address, array_size * element_size);
    
    return 1;
}

// Insere um símbolo na tabela
int insert_symbol(const char *name, tipoDado type, int array_size) {
    if (type == TYPE_ARRAY) {
        return insert_array_symbol(name, TYPE_INT, array_size); // Assume int como tipo base padrão
    }
    
    // Verifica se já existe no escopo atual
    Symbol *existing = lookup_symbol(name);
    if (existing != NULL && existing->scope_level == symbol_table.current_scope) {
        printf("ERRO: Identificador '%s' já declarado no escopo atual\n", name);
        return 0;
    }
    
    unsigned int index = hash_function(name);
    Symbol *new_symbol = (Symbol*)malloc(sizeof(Symbol));
    if (new_symbol == NULL) {
        printf("ERRO: Falha na alocação de memória para símbolo\n");
        return 0;
    }
    
    new_symbol->name = strdup(name);
    new_symbol->type = type;
    new_symbol->array_base_type = type;
    new_symbol->scope_level = symbol_table.current_scope;
    new_symbol->array_size = 0;
    new_symbol->address = symbol_table.next_address;
    
    symbol_table.next_address += get_type_size(type);
    
    new_symbol->next = symbol_table.table[index];
    symbol_table.table[index] = new_symbol;
    
    printf("Símbolo '%s' inserido no escopo %d, endereço %d\n", 
           name, symbol_table.current_scope, new_symbol->address);
    
    return 1;
}

// Busca um símbolo na tabela
Symbol* lookup_symbol(const char *name) {
    unsigned int index = hash_function(name);
    Symbol *current = symbol_table.table[index];
    
    Symbol *best_match = NULL;
    int best_scope = -1;
    
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current->scope_level <= symbol_table.current_scope &&
                current->scope_level > best_scope) {
                best_match = current;
                best_scope = current->scope_level;
            }
        }
        current = current->next;
    }
    
    if (best_match == NULL) {
        printf("ERRO: Identificador '%s' não foi declarado ou está fora de escopo\n", name);
    }
    
    return best_match;
}

// Entra em um novo escopo
void enter_scope() {
    symbol_table.current_scope++;
    printf("Entrando no escopo %d\n", symbol_table.current_scope);
}

// Sai do escopo atual
void exit_scope() {
    printf("Saindo do escopo %d\n", symbol_table.current_scope);
    
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Symbol **current = &symbol_table.table[i];
        while (*current != NULL) {
            if ((*current)->scope_level == symbol_table.current_scope) {
                Symbol *to_remove = *current;
                *current = (*current)->next;
                printf("Removendo símbolo '%s' do escopo %d\n", 
                       to_remove->name, to_remove->scope_level);
                free(to_remove->name);
                free(to_remove);
            } else {
                current = &((*current)->next);
            }
        }
    }
    
    symbol_table.current_scope--;
}

// Converte tipo para string
const char* type_to_string(tipoDado type) {
    switch (type) {
        case TYPE_INT: return "int";
        case TYPE_FLOAT: return "float";
        case TYPE_CHAR: return "char";
        case TYPE_VOID: return "void";
        case TYPE_STRUCT: return "struct";
        case TYPE_ARRAY: return "array";
        default: return "unknown";
    }
}

// Imprime a tabela de símbolos
void print_symbol_table() {
    printf("\n========== TABELA DE SÍMBOLOS ==========\n");
    printf("%-15s %-10s %-10s %-8s %-10s %-8s\n", 
           "Nome", "Tipo", "TipoBase", "Escopo", "Endereço", "Tamanho");
    printf("--------------------------------------------\n");
    
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Symbol *current = symbol_table.table[i];
        while (current != NULL) {
            printf("%-15s %-10s ", 
                   current->name, 
                   type_to_string(current->type));
            
            if (current->type == TYPE_ARRAY) {
                printf("%-10s ", type_to_string(current->array_base_type));
            } else {
                printf("%-10s ", "-");
            }
            
            printf("%-8d %-10d ", 
                   current->scope_level,
                   current->address);
            
            if (current->type == TYPE_ARRAY) {
                printf("%-8d\n", current->array_size);
            } else {
                printf("%-8s\n", "-");
            }
            
            current = current->next;
        }
    }
    printf("==========================================\n\n");
}

// Libera memória da tabela de símbolos
void free_symbol_table() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Symbol *current = symbol_table.table[i];
        while (current != NULL) {
            Symbol *next = current->next;
            free(current->name);
            free(current);
            current = next;
        }
        symbol_table.table[i] = NULL;
    }
} 