%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbol_table.h"
    extern FILE *yyin;

    extern int yylex();
    extern int yyparse(void);
    void yyerror(const char *s);

    extern int line_number;
    extern int column_number;
    extern char *yytext;
%}

%code requires {
    #include "symbol_table.h"
}

%union {
    char *string;
    int integer;
    float real;
}

%token <string> ID
%token <integer> NUMINT
%token <real> NUMFLOAT
%token STRING
%token ABRECOLCHETE
%token FECHACOLCHETE
%token ATRIBUICAO
%token RELOP
%token SOMA
%token MULT
%token ABREPARENTESES
%token FECHAPARENTESES
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

%type <string> tipoEspc   

%left SOMA
%left MULT
%right UMINUS


%%
//1
programa : declaracaoLista
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
                if (!insert_symbol(current_table, $2, $1)) {
                    yyerror("Erro na declaração de variável");
                }
                free($2);
                free($1);
            }
            | tipoEspc ID ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha PONTO_VIRGULA
            {
                char array_type[50];
                snprintf(array_type, sizeof(array_type), "%s_array[%d]", $1, $4);
                if (!insert_symbol(current_table, $2, array_type)) {
                    yyerror("Erro na declaração de array");
                }
                free($2);
                free($1);
            }
            | STRUCT ID ABRECHAVE atriDeclara FECHACHAVE
            {
                if (!insert_symbol(current_table, $2, "struct")) {
                    yyerror("Erro na declaração de struct");
                }
                free($2);
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
            { $$ = strdup("int"); }
            | FLOAT
            { $$ = strdup("float"); }
            | CHAR
            { $$ = strdup("char"); }
            | VOID
            { $$ = strdup("void"); }
            ;

// 6
atriDeclara : varDeclaracao 
            | varDeclaracao atriDeclara
            ;


//7
funDeclaracao : tipoEspc ID ABREPARENTESES params FECHAPARENTESES compostDecl
            {
                char func_type[50];
                snprintf(func_type, sizeof(func_type), "function_%s", $1);
                if (!insert_symbol(current_table, $2, func_type)) {
                    yyerror("Erro na declaração de função");
                }
                free($2);
                free($1);
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
                if (!insert_symbol(current_table, $2, $1)) {
                    yyerror("Erro na declaração de parâmetro");
                }
                free($2);
                free($1);
            }
            | tipoEspc ID ABRECOLCHETE FECHACOLCHETE
            {
                char param_type[50];
                snprintf(param_type, sizeof(param_type), "%s_array", $1);
                if (!insert_symbol(current_table, $2, param_type)) {
                    yyerror("Erro na declaração de parâmetro array");
                }
                free($2);
                free($1);
            }
            ;

//11
compostDecl : ABRECHAVE { enter_scope(); } localDecla comandLista FECHACHAVE
            { exit_scope(); }
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
            | termo
            ;
//27
termo : termo MULT fator
            | fator
            ;

//29
fator   : ABREPARENTESES expr FECHAPARENTESES  

            | var
            | ativacao
            | NUMFLOAT
            | NUMINT
            | '-' fator %prec UMINUS
            ;
//30
ativacao  : ID ABREPARENTESES args FECHAPARENTESES
            {
                Symbol *sym = lookup_symbol(current_table, $1);
                if (sym == NULL) {
                    printf("ERRO: Função '%s' não foi declarada\n", $1);
                }
                free($1);
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
                Symbol *sym = lookup_symbol(current_table, $1);
                if (sym == NULL) {
                    printf("ERRO: Identificador '%s' não foi declarado ou está fora de escopo\n", $1);
                }
                free($1);
            }
            | ID ABRECOLCHETE expr FECHACOLCHETE abreExpFecha
            {
                Symbol *sym = lookup_symbol(current_table, $1);
                if (sym == NULL) {
                    printf("ERRO: Identificador '%s' não foi declarado ou está fora de escopo\n", $1);
                } else if (strstr(sym->type, "array") == NULL) {
                    printf("ERRO: '%s' não é um array\n", $1);
                }
                free($1);
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
    init_symbol_table();

    yyin = arq_compilado;
    if (yyparse() == 0) {
        printf("\n==========================================\n");
        printf("Análise sintática concluída com sucesso!\n");
        printf("==========================================\n");
        
        // Imprime a tabela de símbolos final
        print_symbol_table(current_table);
    }

    // Libera memória da tabela de símbolos
    cleanup_symbol_table();
    fclose(arq_compilado);
    return 0;
}
