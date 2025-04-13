%{
/*-------------------------- Definitions --------------------------*/
#include<stdio.h>
%}

delim                   [ \t\n]
ws                      {delim}+
ifelse			"if"|"else"
digit					[0-9]
int			    {digit}+
float			{digit}+(\.{digit}+)?
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
{comment}		{}		
{int}			{ fprintf(yyout,"%d (INT)\n",atoi(yytext));}
{float}                 { fprintf(yyout,"%.2f (FLOAT)\n",atof(yytext)); }
{ifelse}		{ fprintf(yyout, "%s (IF ELSE)\n", yytext);}
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
