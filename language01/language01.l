%{
/*-------------------------- Definitions --------------------------*/
#include<stdio.h>
int line_number = 1;
int column_number = 1;
%}

delim                   [ \t]
ws                      {delim}+

ponto_virgula           \;
virgula                 \,

letter 			        [a-zA-Z]
digit					[0-9]

relop                   <=|<|>|>=|==|!=

abrechave               \{
fechachave              \}
abreparenteses          \(    
fechaparenteses         \)
abrecolchete            \[
fechacolchete           \]


atribuicao              =

datatype                "int"|"float"|"char"|"struct"|"string"
reservedword			{datatype}|"return"|"void"

boolean                 "true"|"false"
not                     \!

if                      "if"
else                    "else"
while                   "while"
for                     "for"


id			            {letter}({letter}|{digit}|_({letter}|{digit}))*
int                     {digit}{digit}*
num                     {digit}+(\.{digit}+)?(e(\+|\-)?{digit}+)?
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
{soma}              { fprintf(yyout, "%-5d | %-6d | %-20s | (SOMA)\n", line_number, column_number, yytext); column_number+=yyleng;}
{mult}              { fprintf(yyout, "%-5d | %-6d | %-20s | (MULT)\n", line_number, column_number, yytext); column_number+=yyleng;}    
{comment}           { column_number = 1;}


{int}               { fprintf(yyout, "%-5d | %-6d | %-20s | (INT)\n", line_number, column_number, yytext); column_number+=yyleng;}
{num}               { fprintf(yyout, "%-5d | %-6d | %-20s | (NUM)\n", line_number, column_number, yytext); column_number+=yyleng;}
{reservedword}      { fprintf(yyout, "%-5d | %-6d | %-20s | (RESERVEDWORD)\n", line_number, column_number, yytext); column_number+=yyleng;}
{ponto_virgula}     { fprintf(yyout, "%-5d | %-6d | %-20s | (PONTO_VIRGULA)\n", line_number, column_number, yytext); column_number+=yyleng;}
{virgula}           { fprintf(yyout, "%-5d | %-6d | %-20s | (VIRGULA)\n", line_number, column_number, yytext); column_number+=yyleng;}
{relop}             { fprintf(yyout, "%-5d | %-6d | %-20s | (RELOP)\n", line_number, column_number, yytext); column_number+=yyleng;}
{if}                { fprintf(yyout, "%-5d | %-6d | %-20s | (IF)\n", line_number, column_number, yytext); column_number+=yyleng;}
{else}              { fprintf(yyout, "%-5d | %-6d | %-20s | (ELSE)\n", line_number, column_number, yytext); column_number+=yyleng;}
{for}               { fprintf(yyout, "%-5d | %-6d | %-20s | (FOR)\n", line_number, column_number, yytext); column_number+=yyleng;}
{while}             { fprintf(yyout, "%-5d | %-6d | %-20s | (WHILE)\n", line_number, column_number, yytext); column_number+=yyleng;}

{string}            { fprintf(yyout, "%-5d | %-6d | %-20s | (STRING)\n", line_number, column_number, yytext); column_number+=yyleng;}
{id}                { fprintf(yyout, "%-5d | %-6d | %-20s | (ID)\n", line_number, column_number, yytext); column_number+=yyleng;}

{abrechave}         { fprintf(yyout, "%-5d | %-6d | %-20s | (ABRECHAVE)\n", line_number, column_number, yytext); column_number+=yyleng;}
{fechachave}        { fprintf(yyout, "%-5d | %-6d | %-20s | (FECHACHAVE)\n", line_number, column_number, yytext); column_number+=yyleng;}
{atribuicao}        { fprintf(yyout, "%-5d | %-6d | %-20s | (ATRIBUICAO)\n", line_number, column_number, yytext); column_number+=yyleng;}
{boolean}           { fprintf(yyout, "%-5d | %-6d | %-20s | (BOOLEAN)\n", line_number, column_number, yytext); column_number+=yyleng;}
{abreparenteses}    { fprintf(yyout, "%-5d | %-6d | %-20s | (ABREPARENTESES)\n", line_number, column_number, yytext); column_number+=yyleng;}
{fechaparenteses}   { fprintf(yyout, "%-5d | %-6d | %-20s | (FECHAPARENTESES)\n", line_number, column_number, yytext); column_number+=yyleng;}
{abrecolchete}      { fprintf(yyout, "%-5d | %-6d | %-20s | (ABRECOLCHETE)\n", line_number, column_number, yytext); column_number+=yyleng;}
{fechacolchete}     { fprintf(yyout, "%-5d | %-6d | %-20s | (FECHACOLCHETE)\n", line_number, column_number, yytext); column_number+=yyleng;}
{not}               { fprintf(yyout, "%-5d | %-6d | %-20s | (NOT)\n", line_number, column_number, yytext); column_number+=yyleng;}

{digit}+\.{digit}+(\.|{digit})*                          { fprintf(yyout, "%-5d | %-6d | %-20s Lexical Error: Números escritos com mais que um ponto não são aceitos\n", line_number, column_number,yytext);}
{digit}+{letter}({letter}|{digit})+                      { fprintf(yyout, "%-5d | %-6d | %-20s Lexical Error: Identificadores iniciados com números não são aceitos\n", line_number, column_number,yytext);}
\"[^\n"]*                                                { fprintf(yyout, "%-5d | %-6d | %-20s Lexical Error: String devem começar e terminar com aspas duplas\n", line_number, column_number,yytext);}
{digit}+(\,{digit}+)?(e(\+|\-)?{digit}+)?                { fprintf(yyout, "%-5d | %-6d | %-20s Lexical Error: Números do tipo ponto flutuante devem ser escritos com \".\"\n", line_number, column_number,yytext);}  
{letter}({letter}|{digit}|(_{letter}|_{digit})|[@$&^~])* { fprintf(yyout, "%-5d | %-6d | %-20s ID com simbolo inválido\n", line_number, column_number,yytext);}
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
