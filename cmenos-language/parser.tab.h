/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 36 "language01.y"

    #include "symbol_table.h"
    #define MAX_STACK_SIZE 100
    typedef struct {
        char* nome;   // nome da variável temporária
    } Atributo;
    typedef struct {
        Atributo rot_inicio;
        Atributo rot_fim;
    } Rots;

#line 61 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    NUMINT = 259,                  /* NUMINT  */
    NUMFLOAT = 260,                /* NUMFLOAT  */
    STRING = 261,                  /* STRING  */
    ABRECOLCHETE = 262,            /* ABRECOLCHETE  */
    FECHACOLCHETE = 263,           /* FECHACOLCHETE  */
    ATRIBUICAO = 264,              /* ATRIBUICAO  */
    RELOP = 265,                   /* RELOP  */
    MAIS = 266,                    /* MAIS  */
    MENOS = 267,                   /* MENOS  */
    MULT = 268,                    /* MULT  */
    ABREPARENTESES = 269,          /* ABREPARENTESES  */
    FECHAPARENTESES = 270,         /* FECHAPARENTESES  */
    ABRECHAVE = 271,               /* ABRECHAVE  */
    FECHACHAVE = 272,              /* FECHACHAVE  */
    IF = 273,                      /* IF  */
    ELSE = 274,                    /* ELSE  */
    WHILE = 275,                   /* WHILE  */
    INT = 276,                     /* INT  */
    FLOAT = 277,                   /* FLOAT  */
    CHAR = 278,                    /* CHAR  */
    VOID = 279,                    /* VOID  */
    STRUCT = 280,                  /* STRUCT  */
    RETURN = 281,                  /* RETURN  */
    PONTO_VIRGULA = 282,           /* PONTO_VIRGULA  */
    NOT = 283,                     /* NOT  */
    VIRGULA = 284,                 /* VIRGULA  */
    FOR = 285,                     /* FOR  */
    BOOLEAN = 286,                 /* BOOLEAN  */
    LOWER_THAN_ELSE = 287,         /* LOWER_THAN_ELSE  */
    UMINUS = 288                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "language01.y"

    tipoDado datatype;
    char *string;
    int integer;
    float real;
    Atributo attr;
    Rots rotulos;

#line 120 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
