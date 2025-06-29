%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "symbol_table.h"
    extern FILE *yyin;

    extern int yylex();
    extern int yyparse(void);
    void yyerror(const char *s);

    extern int line_number;
    extern int column_number;
    
    // Variável global para a tabela de símbolos
    SymbolTable* symbolTable;
    
    // Variáveis para armazenar informações temporárias
    char currentFunctionName[100];
    DataType currentFunctionType;
    char currentStructName[100];
%}

%union {
    double num;
    char* str;
    DataType type;
}

%token ID
%token STRING
%token ABRECOLCHETE
%token FECHACOLCHETE
%token ATRIBUICAO
%token RELOP
%token SOMA
%token MULT
%token ABREPARENTESES
%token FECHAPARENTESES
%token NUMFLOAT
%token NUMINT
%token ABRECHAVE
%token FECHACHAVE
%token IF
%token ELSE
%token WHILE
%token INT
%token FLOAT
%token CHAR
%token VOID
%token STRUCT
%token RETURN 
%token PONTO_VIRGULA
%token NOT
%token VIRGULA
%token FOR
%token BOOLEAN   

%type <str> ID
%type <type> tipoEspc

%left SOMA
%left MULT
%right UMINUS


%%
//1
programa : declaracaoLista
            { 
                printf("\n=== ANÁLISE SINTÁTICA E SEMÂNTICA CONCLUÍDA ===\n");
                printSymbolTable(symbolTable);
            }
            ;

//2
declaracaoLista : declaracao
            | declaracaoLista declaracao
            ;

//3
declaracao  : funDeclaracao
            | varDeclaracao
            ;

//4
varDeclaracao : tipoEspc ID PONTO_VIRGULA
            { 
                insertSymbol(symbolTable, $2, SYMBOL_VAR, $1, line_number, column_number);
            }
            | tipoEspc ID ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha PONTO_VIRGULA
            { 
                Symbol* symbol = insertSymbol(symbolTable, $2, SYMBOL_VAR, TYPE_ARRAY, line_number, column_number);
                if (symbol) {
                    symbol->arrayDimensions = 1;
                    symbol->arraySizes[0] = $4;
                }
            }
            | STRUCT ID ABRECHAVE atriDeclara FECHACHAVE
            { 
                strcpy(currentStructName, $2);
                insertSymbol(symbolTable, $2, SYMBOL_STRUCT, TYPE_STRUCT, line_number, column_number);
            }
            | tipoEspc error PONTO_VIRGULA
            { printf("ERRO: Declaração de variável inválida na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            | tipoEspc ID ABRECOLCHETE error FECHACOLCHETE PONTO_VIRGULA
            { printf("ERRO: Valor inválido ou ausente para o tamanho do arrayna linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            ;

abreNumFecha : ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha
            |
            ;
//5 
tipoEspc  : INT
            { $$ = TYPE_INT; }
            | FLOAT
            { $$ = TYPE_FLOAT; }
            | CHAR
            { $$ = TYPE_CHAR; }
            | VOID
            { $$ = TYPE_VOID; }
            ;

// 6
atriDeclara : varDeclaracao 
            | varDeclaracao atriDeclara
            ;


//7
funDeclaracao : tipoEspc ID ABREPARENTESES params FECHAPARENTESES compostDecl
            { 
                strcpy(currentFunctionName, $2);
                currentFunctionType = $1;
                insertSymbol(symbolTable, $2, SYMBOL_FUNC, $1, line_number, column_number);
            }
            | tipoEspc error ABREPARENTESES params FECHAPARENTESES compostDecl
            { printf("ERRO: Nome de função ausente ou inválido após o tipo de retorno na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            | tipoEspc ID ABREPARENTESES error FECHAPARENTESES compostDecl
            { printf("ERRO: Lista de parâmetros malformada na declaração de função na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            | error '\n' { printf("Redução: ERRO NA REDUCAO PARA FUNDECLARACAO\n"); yyerrok;}
            ;

//8
params  : paramLista
            | VOID
            ;

//9
paramLista  : param 
            | paramLista VIRGULA param 
            ;
          
//10
param : tipoEspc ID
            { 
                insertSymbol(symbolTable, $2, SYMBOL_PARAM, $1, line_number, column_number);
            }
            | tipoEspc ID ABRECOLCHETE FECHACOLCHETE
            { 
                Symbol* symbol = insertSymbol(symbolTable, $2, SYMBOL_PARAM, TYPE_ARRAY, line_number, column_number);
                if (symbol) {
                    symbol->arrayDimensions = 1;
                    symbol->arraySizes[0] = 0; // Array sem tamanho especificado
                }
            }
            ;

//11
compostDecl : ABRECHAVE localDecla comandLista FECHACHAVE
            { 
                exitScope(symbolTable);
            }
            ;

//12
localDecla  : localDecla varDeclaracao
            |
            ;

//13
comandLista : comandLista comand
            | 
            ;

//14
comand  : exprDecl
            | compostDecl
            | selecDecl
            | iterDecl
            | returnDecl
            | error PONTO_VIRGULA
            { printf("ERRO: Comando sintaticamente inválido ou incompleto na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            ;

//15
exprDecl  : expr PONTO_VIRGULA
            | PONTO_VIRGULA
            ;

//16
selecDecl : IF ABREPARENTESES expr FECHAPARENTESES comand
            | IF ABREPARENTESES expr FECHAPARENTESES comand ELSE comand
            | IF ABREPARENTESES error FECHAPARENTESES comand
            { printf("ERRO: Condição inválida no comando IF na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            ;

//18
iterDecl  : WHILE ABREPARENTESES expr FECHAPARENTESES comand
            | WHILE ABREPARENTESES error FECHAPARENTESES comand
            { printf("ERRO: Condição inválida no comando WHILE na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            ;

//19
returnDecl  : RETURN PONTO_VIRGULA      
            | RETURN expr PONTO_VIRGULA 
            | RETURN error PONTO_VIRGULA
            { printf("ERRO: Valor de retorno inválido na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            ;


//20
expr   : var ATRIBUICAO expr 
            | exprSimples    
            ;
            
//22
exprSimples : exprSoma RELOP exprSoma   
            | exprSoma                
            ;
//23
exprSoma  :  exprSoma SOMA termo 
            { $$ = $1 + $3;}
            | termo
            ;
//27
termo : termo MULT fator
            | fator
            ;

//29
fator   : ABREPARENTESES expr FECHAPARENTESES  
            { $$ = $2;}
            | var
            | ativacao
            | NUMFLOAT
            | NUMINT
            | '-' fator %prec UMINUS
            ;
//30
ativacao  : ID ABREPARENTESES args FECHAPARENTESES
            { 
                Symbol* func = lookupSymbolGlobal(symbolTable, $1);
                if (!func || func->type != SYMBOL_FUNC) {
                    printf("ERRO: Função '%s' não declarada na linha %d, coluna %d\n", 
                           $1, line_number, column_number);
                }
            }
            ;
//31
args : argLista
            |
            ;
//32
argLista  :  expr 
            | argLista VIRGULA expr
            ;

//21
var    : ID
            { 
                Symbol* symbol = lookupSymbolGlobal(symbolTable, $1);
                if (!symbol) {
                    printf("ERRO: Variável '%s' não declarada na linha %d, coluna %d\n", 
                           $1, line_number, column_number);
                }
            }
            | ID ABRECOLCHETE expr FECHACOLCHETE abreExpFecha  
            { 
                Symbol* symbol = lookupSymbolGlobal(symbolTable, $1);
                if (!symbol) {
                    printf("ERRO: Variável '%s' não declarada na linha %d, coluna %d\n", 
                           $1, line_number, column_number);
                } else if (symbol->type != SYMBOL_VAR || symbol->dataType != TYPE_ARRAY) {
                    printf("ERRO: '%s' não é um array na linha %d, coluna %d\n", 
                           $1, line_number, column_number);
                }
                $$ = $1;
            }
            ;
abreExpFecha : abreExpFecha ABRECOLCHETE expr FECHACOLCHETE
            | 
            ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s na linha %d, coluna %d\n", s, line_number, column_number);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Você deve prover um arquivo de entrada para o compilador.\n");
        return -1;
    }
    FILE *arq_compilado = fopen(argv[1], "r");
    if (!arq_compilado) {
        printf("O arquivo fornecido para compilação não é válido.\n");
        return -2;
    }

    // Inicializa a tabela de símbolos
    symbolTable = createSymbolTable();
    if (!symbolTable) {
        printf("Erro ao criar tabela de símbolos.\n");
        fclose(arq_compilado);
        return -3;
    }

    yyin = arq_compilado;
    if (yyparse() == 0) {
        printf("\n==========================================\n");
        printf("Análise sintática concluída com sucesso!\n");
        printf("==========================================\n");
    }

    // Limpa a tabela de símbolos
    destroySymbolTable(symbolTable);
    fclose(arq_compilado);
    return 0;
}
