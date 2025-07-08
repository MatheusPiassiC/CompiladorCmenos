#include "symbol_table.h"

// Variável global da tabela de símbolos atual
SymbolTable *current_table = NULL;

// Cria uma nova tabela de símbolos
SymbolTable* criarTabelaSimbolos(SymbolTable *parent) {
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
void destruirTabela(SymbolTable *table) {
    if (table == NULL) return;
    
    // Libera todos os símbolos
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Symbol *current = table->table[i];
        while (current != NULL) {
            Symbol *next = current->next;
            free(current->name);
            free(current->type_string);
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

// Converte string de tipo para SymbolType
SymbolType stringParaTipo(const char *type_str) {
    if (strcmp(type_str, "int") == 0) return TYPE_INT;
    if (strcmp(type_str, "float") == 0) return TYPE_FLOAT;
    if (strcmp(type_str, "char") == 0) return TYPE_CHAR;
    if (strcmp(type_str, "void") == 0) return TYPE_VOID;
    if (strstr(type_str, "int_array") != NULL) return TYPE_INT_ARRAY;
    if (strstr(type_str, "float_array") != NULL) return TYPE_FLOAT_ARRAY;
    if (strstr(type_str, "char_array") != NULL) return TYPE_CHAR_ARRAY;
    if (strstr(type_str, "function_") != NULL) return TYPE_FUNCTION;
    if (strcmp(type_str, "struct") == 0) return TYPE_STRUCT;
    return TYPE_ERROR;
}

// Converte SymbolType para string
const char* symbol_type_to_string(SymbolType type) {
    switch (type) {
        case TYPE_INT: return "int";
        case TYPE_FLOAT: return "float";
        case TYPE_CHAR: return "char";
        case TYPE_VOID: return "void";
        case TYPE_INT_ARRAY: return "int_array";
        case TYPE_FLOAT_ARRAY: return "float_array";
        case TYPE_CHAR_ARRAY: return "char_array";
        case TYPE_FUNCTION: return "function";
        case TYPE_STRUCT: return "struct";
        default: return "error";
    }
}

// Obtém o tipo base de um array
SymbolType get_base_type(SymbolType type) {
    switch (type) {
        case TYPE_INT_ARRAY: return TYPE_INT;
        case TYPE_FLOAT_ARRAY: return TYPE_FLOAT;
        case TYPE_CHAR_ARRAY: return TYPE_CHAR;
        default: return type;
    }
}

// Verifica se é tipo numérico
int is_numeric_type(SymbolType type) {
    return (type == TYPE_INT || type == TYPE_FLOAT || type == TYPE_CHAR);
}

// Verifica se é tipo array
int is_array_type(SymbolType type) {
    return (type == TYPE_INT_ARRAY || type == TYPE_FLOAT_ARRAY || type == TYPE_CHAR_ARRAY);
}

// Verifica compatibilidade entre tipos
int types_compatible(SymbolType type1, SymbolType type2) {
    if (type1 == type2) return 1;
    
    // Conversões implícitas permitidas
    if (is_numeric_type(type1) && is_numeric_type(type2)) {
        // char pode ser convertido para int ou float
        if (type1 == TYPE_CHAR && (type2 == TYPE_INT || type2 == TYPE_FLOAT)) return 1;
        if (type2 == TYPE_CHAR && (type1 == TYPE_INT || type1 == TYPE_FLOAT)) return 1;
        // int pode ser convertido para float
        if ((type1 == TYPE_INT && type2 == TYPE_FLOAT) || 
            (type1 == TYPE_FLOAT && type2 == TYPE_INT)) return 1;
    }
    
    return 0;
}

// Determina o tipo resultado de uma operação
SymbolType get_operation_result_type(SymbolType type1, SymbolType type2, const char *op) {
    // Verifica se ambos são tipos numéricos
    if (!is_numeric_type(type1) || !is_numeric_type(type2)) {
        return TYPE_ERROR;
    }
    
    // Para operações relacionais, resultado é sempre int (0 ou 1)
    if (strcmp(op, "<") == 0 || strcmp(op, ">") == 0 || 
        strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0 ||
        strcmp(op, "==") == 0 || strcmp(op, "!=") == 0) {
        return TYPE_INT;
    }
    
    // Para operações aritméticas, segue hierarquia: float > int > char
    if (type1 == TYPE_FLOAT || type2 == TYPE_FLOAT) return TYPE_FLOAT;
    if (type1 == TYPE_INT || type2 == TYPE_INT) return TYPE_INT;
    return TYPE_CHAR;
}

// Insere um símbolo na tabela
int inserirSimbolo(SymbolTable *table, const char *name, const char *type) {
    if (table == NULL || name == NULL || type == NULL) {
        printf("ERRO: Parâmetros inválidos para inserção de símbolo\n");
        return 0;
    }
    
    // Verifica se já existe no escopo atual
    Symbol *existe = procuraEscopoAtual(table, name);
    if (existe != NULL) {
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
    
    new_symbol->type_string = (char*)malloc(strlen(type) + 1);
    strcpy(new_symbol->type_string, type);
    
    // Analisa o tipo semântico
    new_symbol->type = stringParaTipo(type);
    
    // Para arrays, extrai o tamanho
    if (is_array_type(new_symbol->type)) {
        char *bracket = strchr(type, '[');
        if (bracket) {
            new_symbol->array_size = atoi(bracket + 1);
        } else {
            new_symbol->array_size = -1; // Array sem tamanho especificado
        }
    } else {
        new_symbol->array_size = 0;
    }

    
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
    
//    printf("Símbolo '%s' (tipo: %s) inserido, offset: %d\n", 
//           name, type, new_symbol->offset);
    
    return 1; // Sucesso
}

// Busca um símbolo na tabela (inclui escopos pais)
Symbol* procurarSimbolo(SymbolTable *table, const char *name) {
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
        return procurarSimbolo(table->parent, name);
    }
    
    return NULL; // Não encontrado
}

// Busca um símbolo apenas no escopo atual (sem verificar pais)
Symbol* procuraEscopoAtual(SymbolTable *table, const char *name) {
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
    SymbolTable *new_table = criarTabelaSimbolos(current_table);
    if (new_table != NULL) {
        current_table = new_table;
//        printf("Entrando em novo escopo\n");
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
    
    SymbolTable *pai = current_table->parent;
    
    if (pai != NULL) {
        // Atualiza o offset da tabela pai
        pai->next_offset = current_table->next_offset; }
        
    //     // Remove esta tabela da sequência de next_scope
    //     SymbolTable *prev = pai;
    //     while (prev != NULL && prev->next_scope != current_table) {
    //         prev = prev->next_scope;
    //     }
    //     if (prev != NULL) {
    //         prev->next_scope = current_table->next_scope;
    //     }
    // }
    
//    printf("Saindo do escopo atual\n");
    //destruirTabela(current_table);
    current_table = pai;
}

// Imprime a tabela de símbolos
void imprimirTabela(SymbolTable *table) {
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
                   current->type_string,
                   current->offset);
            current = current->next;
        }
    }
    
    // Imprime tabela pai se existir
    if (table->parent != NULL) {
        printf("\n--- ESCOPO PAI ---\n");
        imprimirTabela(table->parent);
    }
    
    printf("==========================================\n\n");
}

// Inicializa a tabela de símbolos global
void iniciarTabelaDeSimbolos() {
    current_table = criarTabelaSimbolos(NULL);
    if (current_table == NULL) {
        printf("ERRO: Não foi possível inicializar a tabela de símbolos\n");
    } else {
        printf("Tabela de símbolos inicializada\n");
    }
}

// Limpa toda a estrutura de tabelas de símbolos
void limparTabela() {
    while (current_table != NULL) {
        SymbolTable *parent = current_table->parent;
        destruirTabela(current_table);
        current_table = parent;
    }
    printf("Tabela de símbolos limpa\n");
}

// Imprime todas as tabelas de símbolos da raiz até a atual
void imprimirTodasTabela(SymbolTable *table) {
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
                       sym->type_string,
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