%{
/*-------------------------- Definitions --------------------------*/
#include<stdio.h>
#include<string.h>
#include "parser.tab.h"
#include "symbol_table.h"

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
{soma}              { column_number+=yyleng; return SOMA;}
{mult}              { column_number+=yyleng; return MULT;}    
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

{struct}            {  column_number+=yyleng; return STRUCT; }
{void}              {  column_number+=yyleng; return VOID; }
{return}            {  column_number+=yyleng; return RETURN; }
{numint}            {  column_number+=yyleng; return NUMINT;}
{numfloat}          {  column_number+=yyleng; return NUMFLOAT;}
"int"               {  column_number+=yyleng; return INT;}
"float"             {  column_number+=yyleng; return FLOAT;}
"char"              {  column_number+=yyleng; return CHAR;}
"string"            {  column_number+=yyleng; return STRING;}
{ponto_virgula}     {  column_number+=yyleng; return PONTO_VIRGULA;}
{virgula}           {  column_number+=yyleng; return VIRGULA;}
{relop}             {  column_number+=yyleng; return RELOP;}
{if}                {  column_number+=yyleng; return IF;}
{else}              {  column_number+=yyleng; return ELSE;}
{for}               {  column_number+=yyleng; return FOR;}
{while}             {  column_number+=yyleng; return WHILE;}
{boolean}           {  column_number+=yyleng; return BOOLEAN;}

{string}            { column_number+=yyleng; return STRING;}
{id}                { 
                        column_number+=yyleng; 
                        yylval.string = strdup(yytext); 
                        return ID;
                    }

{abrechave}         {  column_number+=yyleng; return ABRECHAVE;}
{fechachave}        {  column_number+=yyleng; return FECHACHAVE;}
{atribuicao}        {  column_number+=yyleng; return ATRIBUICAO;}
{abreparenteses}    { column_number+=yyleng; return ABREPARENTESES;}
{fechaparenteses}   {  column_number+=yyleng; return FECHAPARENTESES;}
{abrecolchete}      {   column_number+=yyleng; return ABRECOLCHETE;}
{fechacolchete}     {  column_number+=yyleng; return FECHACOLCHETE;}
{not}               {  column_number+=yyleng; return NOT;}

{digit}+\.{digit}+(\.|{digit})*                          { fprintf(yyout, "%-5d | %-6d | %-20s Lexical Error: Números escritos com mais que um ponto não são aceitos\n", line_number, column_number,yytext);}
{digit}+{letter}({letter}|{digit})+                      { fprintf(yyout, "%-5d | %-6d | %-20s Lexical Error: Identificadores iniciados com números não são aceitos\n", line_number, column_number,yytext);}
\"[^\n"]*                                                { fprintf(yyout, "%-5d | %-6d | %-20s Lexical Error: String devem começar e terminar com aspas duplas\n", line_number, column_number,yytext);} 
{letter}({letter}|{digit}|(_{letter}|_{digit})|[@$&^~])* { fprintf(yyout, "%-5d | %-6d | %-20s ID com simbolo inválido\n", line_number, column_number,yytext);}
[A-Z]([A-Z]|{digit}|_([A-Z]|{digit}))*                   { fprintf(yyout, "%-5d | %-6d | %-20s ID com letras maiúsculas não são aceitas\n", line_number, column_number,yytext);}




%%


int yywrap(){
    return 1;
}
