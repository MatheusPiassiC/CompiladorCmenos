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

%left '+' '-'
%left '*' '/'
%right UMINUS


%%
//1
programa : declaracaoLista
            ;

//2
declaracaoLista : declaracao declaracaoLista
            | declaracao
            ;

//3
declaracao  : varDeclaracao
            | funDeclaracao
            ;

//4
varDeclaracao : tipoEspc ID PONTO_VIRGULA
            | tipoEspc ID ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha PONTO_VIRGULA
            ;

abreNumFecha : ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha
            |
            ; 
//5 
tipoEspc  : INT
            | FLOAT
            | CHAR
            | VOID
            | STRUCT ID ABRECHAVE atriDeclara FECHACHAVE
            ;

// 6
atriDeclara : varDeclaracao 
            | varDeclaracao atriDeclara
            ;


//7
funDeclaracao : tipoEspc ID ABREPARENTESES params FECHAPARENTESES compostDecl
            ;

//8
params  : paramLista
            | VOID
            ;

//9
paramLista  : param 
            | param VIRGULA paramLista
            ;
          
//10
param : tipoEspc ID
            | tipoEspc ID ABRECOLCHETE FECHACOLCHETE
            ;

//11
compostDecl : ABRECHAVE localDecla comandLista FECHACHAVE
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
            ;

//15
exprDecl  : expr PONTO_VIRGULA
            | PONTO_VIRGULA
            ;

//16
selecDecl : IF ABREPARENTESES expr FECHAPARENTESES comand
            | IF ABREPARENTESES expr FECHAPARENTESES comand ELSE comand
            ;

//18
iterDecl  : WHILE ABREPARENTESES expr FECHAPARENTESES comand
            ;

//19
returnDecl  : RETURN PONTO_VIRGULA      
            | RETURN expr PONTO_VIRGULA 
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
exprSoma  :  termo somaTermo 
            ;

somaTermo : somaTermo "+" somaTermo  
            |somaTermo "-" somaTermo
            |termo                     
            ;
//27
termo : fator multFator 
            ;
multFator : multFator "*" fator 
            |multFator "/" fator 
            |
            ;

//29
fator   : ABREPARENTESES expr FECHAPARENTESES  {$$ = $2;}
            | var
            | ativacao
            | NUMFLOAT
            | NUMINT
            ;
//30
ativacao  : ID ABREPARENTESES args FECHAPARENTESES
            ;
//31
args : argLista
            |
            ;
//32
argLista  :  expr 
            | expr VIRGULA argLista
            ;

//21
var    : ID
            | ID ABRECOLCHETE expr FECHACOLCHETE abreExpFecha  {$$ = $1;}
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

    yyin = arq_compilado;
    if (yyparse() == 0) {
        printf("!!! Análise sintática bem sucedida !!!\n");
    }

    fclose(arq_compilado);
    return 0;
}