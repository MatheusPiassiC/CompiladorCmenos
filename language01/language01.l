%{
/*-------------------------- Definitions --------------------------*/
#include<stdio.h>
#include "parser.tab.h"

int line_number = 1;
int column_number = 1;
%}

delim                   [ \t]
ws                      {delim}+

ponto_virgula           \;
virgula                 \,


letter 			        [a-z]
digit					[0-9]

relop                   <=|<|>|>=|==|!=

abrechave               \{
fechachave              \}
abreparenteses          \(    
fechaparenteses         \)
abrecolchete            \[
fechacolchete           \]


atribuicao              =

struct                  "struct"
void                    "void"
return                  "return"

boolean                 "true"|"false"
not                     \!

if                      "if"
else                    "else"
while                   "while"
for                     "for"


id			            {letter}({letter}|{digit}|_({letter}|{digit}))*
numint                  {digit}{digit}*
numfloat                {digit}+(\.{digit}+)(E(\+|\-)?{digit}+)?
string                  \"[^\n"]*\"
mult                    \*|\/
soma 			        \+|\-
comment 		        "#".*|"/*"(.*|\n)*"*/"


other                   .



%%
%{
/*----------------------------- Rules -----------------------------*/
%}

\n                  { line_number++; column_number = 1;}  
{ws}			    { column_number += yyleng; }
{soma}              { fprintf(yyout, "%-5d | %-6d | %-20s | (SOMA)\n", line_number, column_number, yytext); column_number+=yyleng; return SOMA;}
{mult}              { fprintf(yyout, "%-5d | %-6d | %-20s | (MULT)\n", line_number, column_number, yytext); column_number+=yyleng; return MULT;}    
{comment}       {
                        for (int i = 0; i < yyleng; i++) {
                            if (yytext[i] == '\n') {
                                line_number++;
                                column_number = 1;
                            } else {
                                column_number++;
                            }
                        }
                    }

{struct}            { fprintf(yyout, "%-5d | %-6d | %-20s | (STRUCT)\n", line_number, column_number, yytext); column_number+=yyleng; STRUCT }
{numint}               { fprintf(yyout, "%-5d | %-6d | %-20s | (NUMINT)\n", line_number, column_number, yytext); column_number+=yyleng; return NUMINT;}
{numfloat}               { fprintf(yyout, "%-5d | %-6d | %-20s | (NUMFLOAT)\n", line_number, column_number, yytext); column_number+=yyleng; return NUMFLOAT;}
{reservedword}      { fprintf(yyout, "%-5d | %-6d | %-20s | (RESERVEDWORD)\n", line_number, column_number, yytext); column_number+=yyleng; return RESERVEDWORD;}
"int"              { fprintf(yyout, "%-5d | %-6d | %-20s | (INT)\n", line_number, column_number, yytext); column_number+=yyleng; return INT;}
"float"            { fprintf(yyout, "%-5d | %-6d | %-20s | (FLOAT)\n", line_number, column_number, yytext); column_number+=yyleng; return FLOAT;}
"char"             { fprintf(yyout, "%-5d | %-6d | %-20s | (CHAR)\n", line_number, column_number, yytext); column_number+=yyleng; return CHAR;}
"string"           { fprintf(yyout, "%-5d | %-6d | %-20s | (STRING)\n", line_number, column_number, yytext); column_number+=yyleng; return STRING;}
{ponto_virgula}     { fprintf(yyout, "%-5d | %-6d | %-20s | (PONTO_VIRGULA)\n", line_number, column_number, yytext); column_number+=yyleng;return PONTO_VIRGULA;}
{virgula}           { fprintf(yyout, "%-5d | %-6d | %-20s | (VIRGULA)\n", line_number, column_number, yytext); column_number+=yyleng;return VIRGULA;}
{relop}             { fprintf(yyout, "%-5d | %-6d | %-20s | (RELOP)\n", line_number, column_number, yytext); column_number+=yyleng;return  RELOP;}
{if}                { fprintf(yyout, "%-5d | %-6d | %-20s | (IF)\n", line_number, column_number, yytext); column_number+=yyleng;return IF;}
{else}              { fprintf(yyout, "%-5d | %-6d | %-20s | (ELSE)\n", line_number, column_number, yytext); column_number+=yyleng;return ELSE;}
{for}               { fprintf(yyout, "%-5d | %-6d | %-20s | (FOR)\n", line_number, column_number, yytext); column_number+=yyleng;return FOR;}
{while}             { fprintf(yyout, "%-5d | %-6d | %-20s | (WHILE)\n", line_number, column_number, yytext); column_number+=yyleng; return WHILE;}

{string}            { fprintf(yyout, "%-5d | %-6d | %-20s | (STRING)\n", line_number, column_number, yytext); column_number+=yyleng; return STRING;}
{id}                { fprintf(yyout, "%-5d | %-6d | %-20s | (ID)\n", line_number, column_number, yytext); column_number+=yyleng; return ID;}

{abrechave}         { fprintf(yyout, "%-5d | %-6d | %-20s | (ABRECHAVE)\n", line_number, column_number, yytext); column_number+=yyleng; return ABRECHAVE;}
{fechachave}        { fprintf(yyout, "%-5d | %-6d | %-20s | (FECHACHAVE)\n", line_number, column_number, yytext); column_number+=yyleng; return FECHACHAVE;}
{atribuicao}        { fprintf(yyout, "%-5d | %-6d | %-20s | (ATRIBUICAO)\n", line_number, column_number, yytext); column_number+=yyleng; return ATRIBUICAO;}
{boolean}           { fprintf(yyout, "%-5d | %-6d | %-20s | (BOOLEAN)\n", line_number, column_number, yytext); column_number+=yyleng; return BOOLEAN;}
{abreparenteses}    { fprintf(yyout, "%-5d | %-6d | %-20s | (ABREPARENTESES)\n", line_number, column_number, yytext); column_number+=yyleng; return ABREPARENTESES;}
{fechaparenteses}   { fprintf(yyout, "%-5d | %-6d | %-20s | (FECHAPARENTESES)\n", line_number, column_number, yytext); column_number+=yyleng; return FECHAPARENTESES;}
{abrecolchete}      { fprintf(yyout, "%-5d | %-6d | %-20s | (ABRECOLCHETE)\n", line_number, column_number, yytext); column_number+=yyleng; return ABRECOLCHETE;}
{fechacolchete}     { fprintf(yyout, "%-5d | %-6d | %-20s | (FECHACOLCHETE)\n", line_number, column_number, yytext); column_number+=yyleng; return FECHACOLCHETE;}
{not}               { fprintf(yyout, "%-5d | %-6d | %-20s | (NOT)\n", line_number, column_number, yytext); column_number+=yyleng; return NOT;}

{digit}+\.{digit}+(\.|{digit})*                          { fprintf(yyout, "%-5d | %-6d | %-20s Lexical Error: Números escritos com mais que um ponto não são aceitos\n", line_number, column_number,yytext);}
{digit}+{letter}({letter}|{digit})+                      { fprintf(yyout, "%-5d | %-6d | %-20s Lexical Error: Identificadores iniciados com números não são aceitos\n", line_number, column_number,yytext);}
\"[^\n"]*                                                { fprintf(yyout, "%-5d | %-6d | %-20s Lexical Error: String devem começar e terminar com aspas duplas\n", line_number, column_number,yytext);} 
{letter}({letter}|{digit}|(_{letter}|_{digit})|[@$&^~])* { fprintf(yyout, "%-5d | %-6d | %-20s ID com simbolo inválido\n", line_number, column_number,yytext);}
[A-Z]([A-Z]|{digit}|_([A-Z]|{digit}))*                   { fprintf(yyout, "%-5d | %-6d | %-20s ID com letras maiúsculas não são aceitas\n", line_number, column_number,yytext);}
{other}                                                  { fprintf(yyout, "%-5d | %-6d | %-20s Lexical Error\n", line_number, column_number,yytext);}




%%
/*------------------------ User subrotines ------------------------*/
int main(int argc, char *argv[]){
    yyin = fopen(argv[1], "r");
    yyout=stdout;
    printf("Linha | Coluna | Lexema |               Token\n");
    yylex();
    fclose(yyin);
    return 0;
}

int yywrap(){
    return 0;
}
