%{
/*-------------------------- Definitions --------------------------*/
#include<stdio.h>
%}

ws                      {delim}+
delim                   [ \t\n]
letter 			        [a-zA-z]
digit					[0-9]
datatype                "int"|"float"|"char"|"struct"|"string"
reservedword			{datatype}|"return"|"void"
if                      "if"
else                    "else"
while                   "while"
num                     {digit}+(\.{digit}+)?(e(\+|\-)?{digit}+)?
string                  \"[^\n"]*\"
mult                    \*|\/
soma 			        \+|-
id			            {letter}({letter}|{digit})*
comment 		        "#".*|"/*"(.*|{ws})*"*/"
relop                   <=|<|>|>=|==|!=
other                   .



%%
%{
/*----------------------------- Rules -----------------------------*/
%}
	
{ws}			    {}
{soma}			    { fprintf(yyout, "%s (SOMA) \n", yytext);}
{mult}			    { fprintf(yyout, "%s (MULT) \n", yytext);}	
{comment}		    {}
{num}		        { fprintf(yyout,"%s (NUM)\n",yytext);}
{reservedword}		{ fprintf(yyout, "%s (RESERVEDWORD)\n", yytext);}
{relop}		        { fprintf(yyout, "%s (RELOP))\n", yytext);}
{if}		        { fprintf(yyout, "%s (IF)\n", yytext);}
{else}		        { fprintf(yyout, "%s (ELSE)\n", yytext);}
{while}		        { fprintf(yyout, "%s (WHILE)\n", yytext);}
{string}            { fprintf(yyout, "%s (string) \n", yytext);}
{id}			    { fprintf(yyout, "%s (ID) \n", yytext);}
{other}             { fprintf(yyout, "Lexical error. Input -> \"%s\"\n", yytext); }


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
