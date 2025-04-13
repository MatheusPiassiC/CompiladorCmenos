%{
/*-------------------------- Definitions --------------------------*/
#include<stdio.h>
%}

delim                   [ \t\n]
ws                      {delim}+
datatype                "int"|"float"|"struct"
reservedword			"if"|"else"|{datatype}|"return"|"void"
digit					[0-9]
num                     {digit}+(\.{digit}+)?(e(\+|\-)?{digit}+)?
string                  \"[^\n"]*\"
int			    {digit}+
float			{digit}+(\.{digit}+)?
mult            \*|\/
soma 			\+|-
letter 			[a-zA-z]
id			    {letter}({letter}|{digit})*
comment 		"#".*|"/*"(.*|{ws})*"*/"
other                   .


%%
%{
/*----------------------------- Rules -----------------------------*/
%}
	
{ws}			{}
{soma}			{fprintf(yyout, "%s (SOMA) \n", yytext);}
{mult}			{fprintf(yyout, "%s (MULT) \n", yytext);}	
{comment}		{}
{num}		        { fprintf(yyout,"%s (NUM)\n",yytext);}
{int}			{ fprintf(yyout,"%d (INT)\n",atoi(yytext));}
{float}                 { fprintf(yyout,"%.2f (FLOAT)\n",atof(yytext)); }
{reservedword}		{ fprintf(yyout, "%s (RESERVEDWORD)\n", yytext);}
{string}                { fprintf(yyout, "%s (string) \n", yytext);}
{id}			{ fprintf(yyout, "%s (ID) \n", yytext);}
{other}                 { fprintf(yyout, "Lexical error. Input -> \"%s\"\n", yytext); }


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
