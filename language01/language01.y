%{
    #include <stdio.h>
    #include <stdlib.h>
    #define YYSTYPE double /* tipo double para pilha Yacc */

    /*Compatibilidade com FLEX*/
    int yylex(void);
    void yyerror(const char *s){
    };
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
declaracaoLista : declaracao declaracaoM
            ;

declaracaoM : declaracaoM declaracao
            | 
            ;

//3
declaracao  : varDeclaracao
            | funDeclaracao
            ;

//4
varDeclaracao : tipoEspc ID ';'
            | tipoEspc ID ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha ';'
            ;

abreNumFecha : abreNumFecha ABRECOLCHETE NUMINT FECHACOLCHETE
            |
            ; 
//5 
tipoEspc  : types
            ;

types   : INT
            | FLOAT
            | CHAR
            | VOID
            | STRUCT ID ABRECHAVE atriDeclara FECHACHAVE
            ;

// 6
atriDeclara : varDeclaracao varDeclaracaoM
            ;

varDeclaracaoM  : varDeclaracaoM varDeclaracao
            | 
            ;


//7
funDeclaracao : tipoEspc ID ABREPARENTESES params FECHAPARENTESES compostDecl
            ;

//8
params  : paramLista
            |"void"
            ;

//9
paramLista  : param virgulaParam
            ;
          
virgulaParam  : virgulaParam ',' param
            |
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
exprDecl  : expr ';'
            | ';'
            ;

//16
selecDecl : IF ABREPARENTESES expr FECHAPARENTESES comand
            | IF ABREPARENTESES expr FECHAPARENTESES comand ELSE comand
            ;

//18
iterDecl  : WHILE ABREPARENTESES expr FECHAPARENTESES comand
            ;

//19
returnDecl  : RETURN ";"      {$$ = 0 ;}
            | RETURN expr ";" {$$ = $2;}
            ;


//20
expr   : var ATRIBUICAO expr {$$ = $3;}
            | exprSimples    {$$ = $1;}
            ;
            
//22
exprSimples : exprSoma RELOP exprSoma   //{$$ = $1 $2 $3;}
            | exprSoma                
            ;
//23
exprSoma  :  termo somaTermo {$$ = $1 + $2;}
            ;

somaTermo : somaTermo "+" termo  {$$ = $1 + $3 ;} 
            |somaTermo "-" termo {$$ = $1 - $3 ;}
            |                     
            ;
//27
termo : fator multFator {$$ = $1 + $2;}
            ;
multFator : multFator "*" fator {$$ = $1 * $3;}
            |multFator "/" fator {$$ = $1 / $3;}
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
argLista  :  expr virgulaExpr
            ;
virgulaExpr : virgulaExpr ',' expr
            |
            ;
//21
var    : ID
            | ID ABRECOLCHETE expr FECHACOLCHETE abreExpFecha  {$$ = $1;}
            ;
abreExpFecha : abreExpFecha ABRECOLCHETE expr FECHACOLCHETE
            | 
            ;
%%

int main(){
    yyparse();
    return 0;
}