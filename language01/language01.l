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
abreparente             \(    
fechaparente            \)
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


id			            {letter}({letter}|{digit}|(_{letter}|_{digit})?)*
int                     {digit}{digit}*
num                     ("+"|"-")?{digit}+(\.{digit}+)?(e(\+|\-)?{digit}+)?
string                  \"[^\n"]*\"
mult                    \*|\/
soma 			        \+|-
comment 		        "#".*|"/*"(.*|{ws})*"*/"


other                   .



%%
%{
/*----------------------------- Rules -----------------------------*/
%}

\n                  { line_number++; column_number = 1;}
[ \t]+              { column_number += yyleng; }  
{ws}			    {}
{soma}			    { fprintf(yyout,"%-20s (SOMA) \n", yytext); column_number+=yyleng;}
{mult}			    { fprintf(yyout, "%-20s (MULT) \n", yytext); column_number+=yyleng;}	
{comment}		    { column_number = 1;}
{int}		        { fprintf(yyout,"%-20s (INT)\n",yytext); column_number+=yyleng;}
{num}		        { fprintf(yyout,"%-20s (NUM)\n",yytext); column_number+=yyleng;}
{reservedword}		{ fprintf(yyout, "%-20s (RESERVEDWORD)\n", yytext); column_number+=yyleng;}
{ponto_virgula}		{ fprintf(yyout, "%-20s (PONTO VIRGULA)\n", yytext); column_number+=yyleng;}
{virgula}		    { fprintf(yyout, "%-20s (VIRGULA)\n", yytext); column_number+=yyleng;}
{relop}		        { fprintf(yyout, "%-20s (RELOP)\n", yytext); column_number+=yyleng;}
{if}		        { fprintf(yyout, "%-20s (IF)\n", yytext); column_number+=yyleng;}
{else}		        { fprintf(yyout, "%-20s (ELSE)\n", yytext); column_number+=yyleng;}
{while}		        { fprintf(yyout, "%-20s (WHILE)\n", yytext); column_number+=yyleng;}
{string}            { fprintf(yyout, "%-20s (STRING) \n", yytext); column_number+=yyleng;}
{id}			    { fprintf(yyout, "%-20s (ID) \n", yytext); column_number+=yyleng;}
{abrechave}         { fprintf(yyout, "%-20s (ABRECHAVE)\n", yytext); column_number+=yyleng;}
{fechachave}        { fprintf(yyout, "%-20s (FECHACHAVE)\n", yytext); column_number+=yyleng;}
{atribuicao}        { fprintf(yyout, "%-20s (ATRIBUICAO)\n", yytext); column_number+=yyleng;}
{boolean}			{ fprintf(yyout, "%-20s (BOOLEAN)\n", yytext); column_number+=yyleng;}
{abreparente}       { fprintf(yyout, "%-20s (ABREPARENTE)\n", yytext); column_number+=yyleng;}
{fechaparente}      { fprintf(yyout, "%-20s (FECHAPARENTE)\n", yytext); column_number+=yyleng;}
{abrecolchete}      { fprintf(yyout, "%-20s (ABRECOLCHETE)\n", yytext); column_number+=yyleng;}
{fechacolchete}     { fprintf(yyout, "%-20s (FECHACOLCHETE)\n", yytext); column_number+=yyleng;}
{not}               { fprintf(yyout, "%-20s (NOT)\n", yytext); column_number+=yyleng;}
{for}               { fprintf(yyout, "%-20s (FOR)\n", yytext); column_number+=yyleng;}

{other}             { fprintf(yyout, "Lexical error in line %d column %d. Input -> \"%s\"\n", line_number, column_number,yytext);}



%%
/*------------------------ User subrotines ------------------------*/
int main(int argc, char *argv[]){
    yyin = fopen(argv[1], "r");
    yyout=stdout;
    yylex();
    fclose(yyin);
    return 0;
}

int yywrap(){
    return 0;
}
