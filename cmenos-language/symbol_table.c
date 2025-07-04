#include "symbol_table.h"

// Variável global da tabela de símbolos atual
SymbolTable *current_table = NULL;

// Cria uma nova tabela de símbolos
SymbolTable* create_symbol_table(SymbolTable *parent) {
    SymbolTable *table = (SymbolTable*)malloc(sizeof(SymbolTable));
    if (table == NULL) {
        printf("ERRO: Falha na alocação de memória para tabela de símbolos\n");
        return NULL;
    }
    
    // Inicializa a tabela
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        table->table[i] = NULL;
    }
    
    table->parent = parent;
    table->next_scope = NULL;
    table->next_offset = (parent != NULL) ? parent->next_offset : 0;
    
    // Se tem pai, adiciona esta tabela como próxima na sequência
    if (parent != NULL) {
        // Encontra a última tabela na sequência
        SymbolTable *last = parent;
        while (last->next_scope != NULL) {
            last = last->next_scope;
        }
        last->next_scope = table;
    }
    
    return table;
}

// Destrói uma tabela de símbolos e libera memória
void destroy_symbol_table(SymbolTable *table) {
    if (table == NULL) return;
    
    // Libera todos os símbolos
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Symbol *current = table->table[i];
        while (current != NULL) {
            Symbol *next = current->next;
            free(current->name);
            free(current->type);
            free(current);
            current = next;
        }
    }
    
    free(table);
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

// Insere um símbolo na tabela
int insert_symbol(SymbolTable *table, const char *name, const char *type) {
    if (table == NULL || name == NULL || type == NULL) {
        printf("ERRO: Parâmetros inválidos para inserção de símbolo\n");
        return 0;
    }
    
    // Verifica se já existe no escopo atual
    Symbol *existing = lookup_symbol_current_scope(table, name);
    if (existing != NULL) {
        printf("ERRO: Identificador '%s' já declarado no escopo atual\n", name);
        return 0;
    }
    
    // Calcula o índice hash
    unsigned int index = hash_function(name);
    
    // Cria novo símbolo
    Symbol *new_symbol = (Symbol*)malloc(sizeof(Symbol));
    if (new_symbol == NULL) {
        printf("ERRO: Falha na alocação de memória para símbolo\n");
        return 0;
    }
    
    // Preenche os dados do símbolo
    new_symbol->name = (char*)malloc(strlen(name) + 1);
    strcpy(new_symbol->name, name);
    
    new_symbol->type = (char*)malloc(strlen(type) + 1);
    strcpy(new_symbol->type, type);
    
    new_symbol->offset = table->next_offset;
    
    // Calcula o próximo offset baseado no tipo
    if (strcmp(type, "int") == 0 || strcmp(type, "float") == 0) {
        table->next_offset += 4;
    } else if (strcmp(type, "char") == 0) {
        table->next_offset += 1;
    } else if (strstr(type, "array") != NULL) {
        // Para arrays, assume tamanho padrão de 40 bytes (10 elementos * 4 bytes)
        table->next_offset += 40;
    } else {
        table->next_offset += 4; // Tamanho padrão
    }
    
    // Insere no início da lista (chaining)
    new_symbol->next = table->table[index];
    table->table[index] = new_symbol;
    
    printf("Símbolo '%s' (tipo: %s) inserido, offset: %d\n", 
           name, type, new_symbol->offset);
    
    return 1; // Sucesso
}

// Busca um símbolo na tabela (inclui escopos pais)
Symbol* lookup_symbol(SymbolTable *table, const char *name) {
    if (table == NULL || name == NULL) {
        return NULL;
    }
    
    unsigned int index = hash_function(name);
    Symbol *current = table->table[index];
    
    // Procura no escopo atual
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    
    // Se não encontrou, procura no escopo pai
    if (table->parent != NULL) {
        return lookup_symbol(table->parent, name);
    }
    
    return NULL; // Não encontrado
}

// Busca um símbolo apenas no escopo atual (sem verificar pais)
Symbol* lookup_symbol_current_scope(SymbolTable *table, const char *name) {
    if (table == NULL || name == NULL) {
        return NULL;
    }
    
    unsigned int index = hash_function(name);
    Symbol *current = table->table[index];
    
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    
    return NULL; // Não encontrado no escopo atual
}

// Entra em um novo escopo
void enter_scope() {
    SymbolTable *new_table = create_symbol_table(current_table);
    if (new_table != NULL) {
        current_table = new_table;
        printf("Entrando em novo escopo\n");
    } else {
        printf("ERRO: Não foi possível criar novo escopo\n");
    }
}

// Sai do escopo atual
void exit_scope() {
    if (current_table == NULL) {
        printf("ERRO: Não há escopo para sair\n");
        return;
    }
    
    SymbolTable *parent = current_table->parent;
    
    if (parent != NULL) {
        // Atualiza o offset da tabela pai
        parent->next_offset = current_table->next_offset; }
        
    //     // Remove esta tabela da sequência de next_scope
    //     SymbolTable *prev = parent;
    //     while (prev != NULL && prev->next_scope != current_table) {
    //         prev = prev->next_scope;
    //     }
    //     if (prev != NULL) {
    //         prev->next_scope = current_table->next_scope;
    //     }
    // }
    
    printf("Saindo do escopo atual\n");
    //destroy_symbol_table(current_table);
    current_table = parent;
}

// Imprime a tabela de símbolos
void print_symbol_table(SymbolTable *table) {
    if (table == NULL) {
        printf("Tabela de símbolos vazia\n");
        return;
    }
    
    printf("\n========== TABELA DE SÍMBOLOS ==========\n");
    printf("%-15s %-10s %-8s\n", "Nome", "Tipo", "Offset");
    printf("------------------------------------\n");
    
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Symbol *current = table->table[i];
        while (current != NULL) {
            printf("%-15s %-10s %-8d\n", 
                   current->name, 
                   current->type,
                   current->offset);
            current = current->next;
        }
    }
    
    // Imprime tabela pai se existir
    if (table->parent != NULL) {
        printf("\n--- ESCOPO PAI ---\n");
        print_symbol_table(table->parent);
    }
    
    printf("==========================================\n\n");
}

// Inicializa a tabela de símbolos global
void init_symbol_table() {
    current_table = create_symbol_table(NULL);
    if (current_table == NULL) {
        printf("ERRO: Não foi possível inicializar a tabela de símbolos\n");
    } else {
        printf("Tabela de símbolos inicializada\n");
    }
}

// Limpa toda a estrutura de tabelas de símbolos
void cleanup_symbol_table() {
    while (current_table != NULL) {
        SymbolTable *parent = current_table->parent;
        destroy_symbol_table(current_table);
        current_table = parent;
    }
    printf("Tabela de símbolos limpa\n");
}

// Imprime todas as tabelas de símbolos da raiz até a atual
void print_all_symbol_tables(SymbolTable *table) {
    if (table == NULL) {
        printf("Tabela de símbolos vazia\n");
        return;
    }

    // Primeiro vai até a raiz (tabela mais antiga)
    SymbolTable *root = table;
    int nivel = 0;
    while (root->parent != NULL) {
        root = root->parent;
        nivel++;
    }

    // Agora imprime da raiz até a tabela atual
    SymbolTable *current = root;
    int escopo_atual = 0;
    while (current != NULL) {
        printf("\n========== TABELA DE SÍMBOLOS (Escopo %d) ==========\n", escopo_atual);
        printf("%-15s %-10s %-8s\n", "Nome", "Tipo", "Offset");
        printf("------------------------------------\n");

        for (int i = 0; i < HASH_TABLE_SIZE; i++) {
            Symbol *sym = current->table[i];
            while (sym != NULL) {
                printf("%-15s %-10s %-8d\n", 
                       sym->name, 
                       sym->type,
                       sym->offset);
                sym = sym->next;
            }
        }

        printf("==========================================\n");
        
        // Se este é o escopo atual, marca com um indicador
        if (current == table) {
            printf("^^^ ESCOPO ATUAL ^^^\n\n");
        } else {
            printf("\n");
        }

        if (current->next_scope != NULL) {
            current = current->next_scope;
            escopo_atual++;
        }
        else {
            current = NULL;
        }
    }
} 