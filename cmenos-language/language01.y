%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbol_table.h"
    #include "label_stack.h"

    extern FILE *yyin;

    extern int yylex();
    extern int yyparse(void);
    void yyerror(const char *s);

    extern int line_number;
    extern int column_number;
    extern char *yytext;

    int temp_count = 0;
    int label_count = 0;    

    LabelStack label_stack;
    
    // Arquivo para código de 3 endereços
    FILE *codigo_3_enderecos;

    char* new_temp() {
        char* temp = (char*)malloc(10);
        sprintf(temp, "t%d", temp_count++);
        return temp;
    }

    char* new_label() {
        char* temp = (char*)malloc(10);
        sprintf(temp, "l%d", label_count++);
        return temp;
    }
%}

%code requires {
    #include "symbol_table.h"
    #define MAX_STACK_SIZE 100
    typedef struct {
        char* nome;
        SymbolType tipo;  // Adiciona informação de tipo semântico
    } Atributo;
    typedef struct {
        Atributo rot_inicio;
        Atributo rot_fim;
    } Rots;
}

%union {
    char *string;
    int integer;
    float real;
    Atributo attr;
    Rots rotulos;
    int param_counter;
}


%token <string> ID
%token <integer> NUMINT
%token <real> NUMFLOAT
%token STRING
%token ABRECOLCHETE
%token FECHACOLCHETE
%token ATRIBUICAO
%token <string> RELOP
%token <string> MAIS
%token <string> MENOS
%token <string> MULT
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

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%type <attr> expr exprSimples exprSoma termo fator var
%type <attr> ativacao abreExpFecha
%type <param_counter> args argLista  

%type <string> tipoEspc   

%left MAIS MENOS
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
                if (!inserirSimbolo(current_table, $2, $1)) {
                }
                free($2);
                free($1);
            }
            | tipoEspc ID ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha PONTO_VIRGULA
            {
                char array_type[50];
                snprintf(array_type, sizeof(array_type), "%s_array[%d]", $1, $4);
                if (!inserirSimbolo(current_table, $2, array_type)) {
                    yyerror("Erro na declaração de array");
                }
                free($2);
                free($1);
            }
            | STRUCT ID ABRECHAVE atriDeclara FECHACHAVE
            {
                if (!inserirSimbolo(current_table, $2, "struct")) {
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
                if (!inserirSimbolo(current_table, $2, func_type)) {
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
                if (!inserirSimbolo(current_table, $2, $1)) {
                    yyerror("Erro na declaração de parâmetro");
                }
                free($2);
                free($1);
            }
            | tipoEspc ID ABRECOLCHETE FECHACOLCHETE
            {
                char param_type[50];
                snprintf(param_type, sizeof(param_type), "%s_array", $1);
                if (!inserirSimbolo(current_table, $2, param_type)) {
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
selecDecl : IF ABREPARENTESES expr FECHAPARENTESES{
                char* label_init = new_label();
                char* label_end = new_label();

                LabelPair pair;
                pair.label1 = strdup(label_init);
                pair.label2 = strdup(label_end);
                push_label(&label_stack, pair);
                
                fprintf(codigo_3_enderecos, "ifFalse %s goto %s\n", $3.nome, label_init);
            }
            comand else_opt
            | IF ABREPARENTESES error FECHAPARENTESES comand
            { printf("ERRO: Condição inválida no comando IF na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            ;
else_opt: %prec LOWER_THAN_ELSE{
            LabelPair pair = pop_label(&label_stack);
            fprintf(codigo_3_enderecos, "%s:\n", pair.label1);
            free(pair.label1);
            free(pair.label2);
        }
        | ELSE {
                LabelPair pair = pop_label(&label_stack);
                fprintf(codigo_3_enderecos, "goto %s\n", pair.label2);
                fprintf(codigo_3_enderecos, "%s:\n", pair.label1);
                $<string>$ = pair.label2;
                free(pair.label1);
            } comand {
                char* label_end = $<string>2;
                fprintf(codigo_3_enderecos, "%s:\n", label_end);
                free(label_end);
            }
            ;

//18
iterDecl  : WHILE ABREPARENTESES expr FECHAPARENTESES{
                Rots rotas;

                rotas.rot_inicio.nome = new_label();
                rotas.rot_fim.nome    = new_label();

                $<rotulos>$ = rotas; // passar início pro lado direito

                fprintf(codigo_3_enderecos, "%s:\n", rotas.rot_inicio.nome);
                fprintf(codigo_3_enderecos, "ifFalse %s goto %s\n", $3.nome, rotas.rot_fim.nome);
            } comand {
                fprintf(codigo_3_enderecos, "goto %s\n", $<rotulos>5.rot_inicio.nome); // volta pro início
                fprintf(codigo_3_enderecos, "%s:\n", $<rotulos>5.rot_fim.nome);     // fim do while
            }

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
expr   : var ATRIBUICAO expr { 
                // Verifica compatibilidade de tipos na atribuição
                if (!types_compatible($1.tipo, $3.tipo)) {
                    printf("ERRO SEMÂNTICO: Incompatibilidade de tipos na atribuição. ");
                    printf("Tentativa de atribuir %s a %s na linha %d\n", 
                           symbol_type_to_string($3.tipo), 
                           symbol_type_to_string($1.tipo), 
                           line_number);
                }
                
                // Para arrays, o nome já vem no formato "array[endereco]"
                if (strstr($1.nome, "[") != NULL) {
                    // É uma atribuição a array
                    fprintf(codigo_3_enderecos, "%s = %s\n", $1.nome, $3.nome);
                } else {
                    // Atribuição normal a variável
                    fprintf(codigo_3_enderecos, "%s = %s\n", $1.nome, $3.nome);
                }
                $$ = $1;
            }
            | exprSimples {$$ = $1;}
            ;
            
//22
exprSimples : exprSoma RELOP exprSoma {
                // Verifica se os operandos são compatíveis para comparação
                if (!is_numeric_type($1.tipo) || !is_numeric_type($3.tipo)) {
                    printf("ERRO SEMÂNTICO: Operação relacional '%s' requer operandos numéricos na linha %d\n", 
                           $2, line_number);
                }
                
                Atributo resultado;
                resultado.nome = new_temp();
                resultado.tipo = TYPE_INT; // Resultado de comparação é sempre int
                fprintf(codigo_3_enderecos, "%s = %s %s %s\n", resultado.nome, $1.nome, $2,  $3.nome);
                $$ = resultado;
            } 
            | exprSoma {$$ = $1;}      
            ;
//23
exprSoma  :  exprSoma MAIS termo {
                // Verifica se os operandos são numéricos
                SymbolType result_type = get_operation_result_type($1.tipo, $3.tipo, $2);
                if (result_type == TYPE_ERROR) {
                    printf("ERRO SEMÂNTICO: Operação '%s' entre tipos incompatíveis (%s e %s) na linha %d\n", 
                           $2, symbol_type_to_string($1.tipo), symbol_type_to_string($3.tipo), line_number);
                    result_type = TYPE_INT; // Fallback
                }
                
                Atributo resultado;
                resultado.nome = new_temp();
                resultado.tipo = result_type;
                fprintf(codigo_3_enderecos, "%s = %s %s %s\n", resultado.nome, $1.nome, $2,  $3.nome);
                $$ = resultado;
            }
            | exprSoma MENOS termo {
                // Verifica se os operandos são numéricos
                SymbolType result_type = get_operation_result_type($1.tipo, $3.tipo, $2);
                if (result_type == TYPE_ERROR) {
                    printf("ERRO SEMÂNTICO: Operação '%s' entre tipos incompatíveis (%s e %s) na linha %d\n", 
                           $2, symbol_type_to_string($1.tipo), symbol_type_to_string($3.tipo), line_number);
                    result_type = TYPE_INT; // Fallback
                }
                
                Atributo resultado;
                resultado.nome = new_temp();
                resultado.tipo = result_type;
                fprintf(codigo_3_enderecos, "%s = %s %s %s\n", resultado.nome, $1.nome, $2,  $3.nome);
                $$ = resultado;
            }
            | termo {
                $$ = $1;
            }
            ;
//27
termo : termo MULT fator {
                // Verifica se os operandos são numéricos
                SymbolType result_type = get_operation_result_type($1.tipo, $3.tipo, $2);
                if (result_type == TYPE_ERROR) {
                    printf("ERRO SEMÂNTICO: Operação '%s' entre tipos incompatíveis (%s e %s) na linha %d\n", 
                           $2, symbol_type_to_string($1.tipo), symbol_type_to_string($3.tipo), line_number);
                    result_type = TYPE_INT; // Fallback
                }
                
                Atributo resultado;
                resultado.nome = new_temp();
                resultado.tipo = result_type;
                fprintf(codigo_3_enderecos, "%s = %s %s %s\n", resultado.nome, $1.nome, $2, $3.nome);
                $$ = resultado;
            }
            | fator {
                $$ = $1;
            }

            ;

//29
fator   : ABREPARENTESES expr FECHAPARENTESES   {
                $$ = $2;
            }

            | var {
                Atributo resultado;
                
                // Se é um array, precisamos gerar código para acessar o valor
                if (strstr($1.nome, "[") != NULL) {
                    resultado.nome = new_temp();
                    fprintf(codigo_3_enderecos, "%s = %s\n", resultado.nome, $1.nome);
                } else {
                    // Variável normal
                    resultado = $1;
                }
                resultado.tipo = $1.tipo;
                $$ = resultado;
            }
            | ativacao {
                $$ = $1;
            }
            | NUMFLOAT  {
                Atributo resultado;
                char* temp = (char*)malloc(20);
                sprintf(temp, "%f", $1);
                resultado.nome = temp;
                resultado.tipo = TYPE_FLOAT;
                $$ = resultado;
            }
            | NUMINT  {
                Atributo resultado;
                char* temp = (char*)malloc(20);
                sprintf(temp, "%d", $1);
                resultado.nome = temp;
                resultado.tipo = TYPE_INT;
                $$ = resultado;
            }
            | MENOS fator %prec UMINUS {
                // Verifica se o operando é numérico
                if (!is_numeric_type($2.tipo)) {
                    printf("ERRO SEMÂNTICO: Operador unário '-' requer operando numérico na linha %d\n", line_number);
                }
                
                Atributo resultado;
                resultado.nome = new_temp();
                resultado.tipo = $2.tipo; // Mantém o tipo do operando
                fprintf(codigo_3_enderecos, "%s = -%s\n", resultado.nome, $2.nome);
                $$ = resultado;
            }
            ;
//30
ativacao  : ID ABREPARENTESES args FECHAPARENTESES
            {
                Symbol *sym = procurarSimbolo(current_table, $1);
                if (sym == NULL) {
                    yyerror("Função não declarada"); yyerrok;
                } else if (sym->type != TYPE_FUNCTION) {
                    printf("ERRO SEMÂNTICO: '%s' não é uma função na linha %d\n", $1, line_number);
                }
                
                Atributo resultado;
                resultado.nome = new_temp();
                // O tipo do resultado é o tipo de retorno da função
                $$ = resultado;
                fprintf(codigo_3_enderecos, "%s = call %s %d\n", resultado.nome, strdup($1), $3);
                free($1);
            }
            ;
//31
args : argLista { $$ = $1; }  
     | { $$ = 0; }           
     ;
//32
argLista  :  expr {
                fprintf(codigo_3_enderecos, "param %s\n", $1.nome);
                $$ = 1;
            }
            | argLista VIRGULA expr {
                fprintf(codigo_3_enderecos, "param %s\n", $3.nome);
                $$ = $1 + 1;
            }
            ;

//21
var    : ID
            {
                Symbol *sym = procurarSimbolo(current_table, $1);
                if (sym == NULL) {
                    printf("ERRO: Identificador '%s' não foi declarado ou está fora de escopo\n", $1);
                }
                Atributo resultado;
                resultado.nome = strdup($1);
                resultado.tipo = sym ? sym->type : TYPE_ERROR;
                $$ = resultado;
                free($1);
            }
            | ID ABRECOLCHETE expr FECHACOLCHETE abreExpFecha
            {
                Symbol *sym = procurarSimbolo(current_table, $1);
                if (sym == NULL) {
                    printf("ERRO: Identificador '%s' não foi declarado ou está fora de escopo\n", $1);
                } else if (!is_array_type(sym->type)) {
                    printf("ERRO: '%s' não é um array\n", $1);
                } else {
                    // Verifica se o índice é inteiro
                    if ($3.tipo != TYPE_INT && $3.tipo != TYPE_CHAR) {
                        printf("ERRO SEMÂNTICO: Índice de array deve ser inteiro, encontrado %s na linha %d\n", 
                               symbol_type_to_string($3.tipo), line_number);
                    }
                }
                
                Atributo resultado;
                
                if ($5.nome != NULL && strlen($5.nome) > 0) {
                    // Array multidimensional
                    
                    char* endereco_final = new_temp();
                    char* indices_extras = strdup($5.nome);
                    char* primeiro_extra = strtok(indices_extras, ",");
                    
                    if (primeiro_extra) {
                        // arr[i][j] - caso bidimensional
                        char* mult_temp = new_temp();
                        fprintf(codigo_3_enderecos, "%s = %s * 10\n", mult_temp, $3.nome); // Assume tamanho 10 por padrão
                        fprintf(codigo_3_enderecos, "%s = %s + %s\n", endereco_final, mult_temp, primeiro_extra);
                        
                        // Se há mais dimensões
                        char* proximo_indice;
                        while ((proximo_indice = strtok(NULL, ",")) != NULL) {
                            char* mult_temp2 = new_temp();
                            char* soma_temp = new_temp();
                            fprintf(codigo_3_enderecos, "%s = %s * 10\n", mult_temp2, endereco_final);
                            fprintf(codigo_3_enderecos, "%s = %s + %s\n", soma_temp, mult_temp2, proximo_indice);
                            endereco_final = soma_temp;
                        }
                    }
                    
                    // Para retornar, criamos um nome que indica array com endereço calculado
                    resultado.nome = (char*)malloc(strlen($1) + strlen(endereco_final) + 10);
                    sprintf(resultado.nome, "%s[%s]", $1, endereco_final);
                    free(indices_extras);
                } else {
                    // Array unidimensional: arr[i]
                    resultado.nome = (char*)malloc(strlen($1) + strlen($3.nome) + 10);
                    sprintf(resultado.nome, "%s[%s]", $1, $3.nome);
                }
                
                // Para acesso a array, o tipo é o tipo base do array
                resultado.tipo = sym ? get_base_type(sym->type) : TYPE_ERROR;
                $$ = resultado;
                free($1);
            }
            ;
abreExpFecha : ABRECOLCHETE expr FECHACOLCHETE abreExpFecha
            {
                // Concatena os índices para arrays multidimensionais
                if ($4.nome != NULL && strlen($4.nome) > 0) {
                    // Há mais índices após este
                    char* temp = (char*)malloc(strlen($2.nome) + strlen($4.nome) + 2);
                    sprintf(temp, "%s,%s", $2.nome, $4.nome);
                    $$.nome = temp;
                } else {
                    // Este é o último índice
                    $$.nome = strdup($2.nome);
                }
            }
            | 
            {
                $$.nome = strdup(""); // String vazia para indicar fim
            }
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

    // Abre o arquivo para código de 3 endereços
    codigo_3_enderecos = fopen("codigo_3_enderecos.txt", "w");
    if (!codigo_3_enderecos) {
        printf("Erro ao criar arquivo de código de 3 endereços.\n");
        fclose(arq_compilado);
        return -3;
    }

    // Inicializa a tabela de símbolos
    iniciarTabelaDeSimbolos();

    yyin = arq_compilado;
    if (yyparse() == 0) {
        printf("\n==========================================\n");
        printf("Análise sintática concluída com sucesso!\n");
        printf("==========================================\n");
        printf("Código de 3 endereços gerado em: codigo_3_enderecos.txt\n");
        
        // Imprime a tabela de símbolos final
        imprimirTodasTabela(current_table);
    }

    // Libera memória da tabela de símbolos
    limparTabela();
    
    // Fecha os arquivos
    fclose(arq_compilado);
    fclose(codigo_3_enderecos);
    
    return 0;
}