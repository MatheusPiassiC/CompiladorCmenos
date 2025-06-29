%{
    #include <stdio.h>
    #include <stdlib.h>
    extern FILE *yyin;

    extern int yylex();
    extern int yyparse(void);
    void yyerror(const char *s);

    extern int line_number;
    extern int column_number;
%}

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

%left SOMA
%left MULT
%right UMINUS


%%
//1
programa : declaracaoLista
            { printf("Redução: programa -> declaracaoLista\n"); }
            ;

//2
declaracaoLista : declaracao
            { printf("Redução: declaracaoLista -> declaracao\n"); }
            | declaracaoLista declaracao
            { printf("Redução: declaracaoLista -> declaracaoLista declaracao\n"); }
            ;

//3
declaracao  : funDeclaracao
            { printf("Redução: declaracao -> funDeclaracao\n"); }
            | varDeclaracao
            { printf("Redução: declaracao -> varDeclaracao\n"); }
            ;

//4
varDeclaracao : tipoEspc ID PONTO_VIRGULA
            { printf("Redução: varDeclaracao -> tipoEspc ID PONTO_VIRGULA\n"); }
            | tipoEspc ID ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha PONTO_VIRGULA
            | STRUCT ID ABRECHAVE atriDeclara FECHACHAVE
            { printf("Redução: varDeclaracao -> tipoEspc ID ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha PONTO_VIRGULA\n"); }
            | tipoEspc error PONTO_VIRGULA
            { printf("ERRO: Declaração de variável inválida na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            | tipoEspc ID ABRECOLCHETE error FECHACOLCHETE PONTO_VIRGULA
            { printf("ERRO: Valor inválido ou ausente para o tamanho do arrayna linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            ;

abreNumFecha : ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha
            { printf("Redução: abreNumFecha -> ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha\n"); }
            |
            { printf("Redução: abreNumFecha -> ε\n"); }
            ; 
//5 
tipoEspc  : INT
            { printf("Redução: tipoEspc -> INT\n"); }
            | FLOAT
            { printf("Redução: tipoEspc -> FLOAT\n"); }
            | CHAR
            { printf("Redução: tipoEspc -> CHAR\n"); }
            | VOID
            { printf("Redução: tipoEspc -> VOID\n"); }
            ;

// 6
atriDeclara : varDeclaracao 
            { printf("Redução: atriDeclara -> varDeclaracao\n"); }
            | varDeclaracao atriDeclara
            { printf("Redução: atriDeclara -> varDeclaracao atriDeclara\n"); }
            ;


//7
funDeclaracao : tipoEspc ID ABREPARENTESES params FECHAPARENTESES compostDecl
            { printf("Redução: funDeclaracao -> tipoEspc ID ABREPARENTESES params FECHAPARENTESES compostDecl\n"); }
            | tipoEspc error ABREPARENTESES params FECHAPARENTESES compostDecl
            { printf("ERRO: Nome de função ausente ou inválido após o tipo de retorno na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            | tipoEspc ID ABREPARENTESES error FECHAPARENTESES compostDecl
            { printf("ERRO: Lista de parâmetros malformada na declaração de função na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            | error '\n' { printf("Redução: ERRO NA REDUCAO PARA FUNDECLARACAO\n"); yyerrok;}
            ;

//8
params  : paramLista
            { printf("Redução: params -> paramLista\n"); }
            | VOID
            { printf("Redução: params -> VOID\n"); }
            ;

//9
paramLista  : param 
            { printf("Redução: paramLista -> param\n"); }
            | paramLista VIRGULA param 
            { printf("Redução: paramLista -> paramLista VIRGULA param\n"); }
            ;
          
//10
param : tipoEspc ID
            { printf("Redução: param -> tipoEspc ID\n"); }
            | tipoEspc ID ABRECOLCHETE FECHACOLCHETE
            { printf("Redução: param -> tipoEspc ID ABRECOLCHETE FECHACOLCHETE\n"); }
            ;

//11
compostDecl : ABRECHAVE localDecla comandLista FECHACHAVE
            { printf("Redução: compostDecl -> ABRECHAVE localDecla comandLista FECHACHAVE\n"); }
            ;

//12
localDecla  : localDecla varDeclaracao
            { printf("Redução: localDecla -> localDecla varDeclaracao\n"); }
            |
            { printf("Redução: localDecla -> ε\n"); }
            ;

//13
comandLista : comandLista comand
            { printf("Redução: comandLista -> comandLista comand\n"); }
            | 
            { printf("Redução: comandLista -> ε\n"); }
            ;

//14
comand  : exprDecl
            { printf("Redução: comand -> exprDecl\n"); }
            | compostDecl
            { printf("Redução: comand -> compostDecl\n"); }
            | selecDecl
            { printf("Redução: comand -> selecDecl\n"); }
            | iterDecl
            { printf("Redução: comand -> iterDecl\n"); }
            | returnDecl
            { printf("Redução: comand -> returnDecl\n"); }
            | error PONTO_VIRGULA
            { printf("ERRO: Comando sintaticamente inválido ou incompleto na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            ;

//15
exprDecl  : expr PONTO_VIRGULA
            { printf("Redução: exprDecl -> expr PONTO_VIRGULA\n"); }
            | PONTO_VIRGULA
            { printf("Redução: exprDecl -> PONTO_VIRGULA\n"); }
            ;

//16
selecDecl : IF ABREPARENTESES expr FECHAPARENTESES comand
            { printf("Redução: selecDecl -> IF ABREPARENTESES expr FECHAPARENTESES comand\n"); }
            | IF ABREPARENTESES expr FECHAPARENTESES comand ELSE comand
            { printf("Redução: selecDecl -> IF ABREPARENTESES expr FECHAPARENTESES comand ELSE comand\n"); }
            | IF ABREPARENTESES error FECHAPARENTESES comand
            { printf("ERRO: Condição inválida no comando IF na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            ;

//18
iterDecl  : WHILE ABREPARENTESES expr FECHAPARENTESES comand
            { printf("Redução: iterDecl -> WHILE ABREPARENTESES expr FECHAPARENTESES comand\n"); }
            | WHILE ABREPARENTESES error FECHAPARENTESES comand
            { printf("ERRO: Condição inválida no comando WHILE na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            ;

//19
returnDecl  : RETURN PONTO_VIRGULA      
            { printf("Redução: returnDecl -> RETURN PONTO_VIRGULA\n"); }
            | RETURN expr PONTO_VIRGULA 
            { printf("Redução: returnDecl -> RETURN expr PONTO_VIRGULA\n"); }
            | RETURN error PONTO_VIRGULA
            { printf("ERRO: Valor de retorno inválido na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
            ;


//20
expr   : var ATRIBUICAO expr 
            { printf("Redução: expr -> var ATRIBUICAO expr\n"); }
            | exprSimples    
            { printf("Redução: expr -> exprSimples\n"); }
            ;
            
//22
exprSimples : exprSoma RELOP exprSoma   
            { printf("Redução: exprSimples -> exprSoma RELOP exprSoma\n"); }
            | exprSoma                
            { printf("Redução: exprSimples -> exprSoma\n"); }
            ;
//23
exprSoma  :  exprSoma SOMA termo 
            { printf("Redução: exprSoma -> exprSoma SOMA termo\n"); $$ = $1 + $3;}
            | termo
            { printf("Redução: exprSoma -> termo\n"); }
            ;
//27
termo : termo MULT fator
            { printf("Redução: termo -> termo MULT fator\n"); }
            | fator
            { printf("Redução: termo -> fator\n"); }
            ;

//29
fator   : ABREPARENTESES expr FECHAPARENTESES  
            { printf("Redução: fator -> ABREPARENTESES expr FECHAPARENTESES\n"); $$ = $2;}
            | var
            { printf("Redução: fator -> var\n"); }
            | ativacao
            { printf("Redução: fator -> ativacao\n"); }
            | NUMFLOAT
            { printf("Redução: fator -> NUMFLOAT\n"); }
            | NUMINT
            { printf("Redução: fator -> NUMINT\n"); }
            | '-' fator %prec UMINUS
            { printf("Redução: fator -> - fator\n"); }
            ;
//30
ativacao  : ID ABREPARENTESES args FECHAPARENTESES
            { printf("Redução: ativacao -> ID ABREPARENTESES args FECHAPARENTESES\n"); }
            ;
//31
args : argLista
            { printf("Redução: args -> argLista\n"); }
            |
            { printf("Redução: args -> ε\n"); }
            ;
//32
argLista  :  expr 
            { printf("Redução: argLista -> expr\n"); }
            | argLista VIRGULA expr
            { printf("Redução: argLista -> argLista VIRGULA expr\n"); }
            ;

//21
var    : ID
            { printf("Redução: var -> ID\n"); }
            | ID ABRECOLCHETE expr FECHACOLCHETE abreExpFecha  
            { printf("Redução: var -> ID ABRECOLCHETE expr FECHACOLCHETE abreExpFecha\n"); $$ = $1;}
            ;
abreExpFecha : abreExpFecha ABRECOLCHETE expr FECHACOLCHETE
            { printf("Redução: abreExpFecha -> abreExpFecha ABRECOLCHETE expr FECHACOLCHETE\n"); }
            | 
            { printf("Redução: abreExpFecha -> ε\n"); }
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

    yyin = arq_compilado;
    if (yyparse() == 0) {
        printf("\n==========================================\n");
        printf("Análise sintática concluída com sucesso!\n");
        printf("==========================================\n");
    }

    fclose(arq_compilado);
    return 0;
}
