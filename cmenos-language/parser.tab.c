/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "language01.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbol_table.h"
    #include "label_stack.h"

    extern FILE *yyin;

    extern int yylex();
    extern int yyparse(void);
    void yyerror(const char *s);

    extern int line_number;
    extern int column_number;
    extern char *yytext;

    int temp_count = 0;
    int label_count = 0;    

    LabelStack label_stack;
    
    // Arquivo para código de 3 endereços
    FILE *codigo_3_enderecos;

    char* new_temp() {
        char* temp = (char*)malloc(10);
        sprintf(temp, "t%d", temp_count++);
        return temp;
    }

    char* new_label() {
        char* temp = (char*)malloc(10);
        sprintf(temp, "l%d", label_count++);
        return temp;
    }

#line 109 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUMINT = 4,                     /* NUMINT  */
  YYSYMBOL_NUMFLOAT = 5,                   /* NUMFLOAT  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_ABRECOLCHETE = 7,               /* ABRECOLCHETE  */
  YYSYMBOL_FECHACOLCHETE = 8,              /* FECHACOLCHETE  */
  YYSYMBOL_ATRIBUICAO = 9,                 /* ATRIBUICAO  */
  YYSYMBOL_RELOP = 10,                     /* RELOP  */
  YYSYMBOL_MAIS = 11,                      /* MAIS  */
  YYSYMBOL_MENOS = 12,                     /* MENOS  */
  YYSYMBOL_MULT = 13,                      /* MULT  */
  YYSYMBOL_ABREPARENTESES = 14,            /* ABREPARENTESES  */
  YYSYMBOL_FECHAPARENTESES = 15,           /* FECHAPARENTESES  */
  YYSYMBOL_ABRECHAVE = 16,                 /* ABRECHAVE  */
  YYSYMBOL_FECHACHAVE = 17,                /* FECHACHAVE  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_INT = 21,                       /* INT  */
  YYSYMBOL_FLOAT = 22,                     /* FLOAT  */
  YYSYMBOL_CHAR = 23,                      /* CHAR  */
  YYSYMBOL_VOID = 24,                      /* VOID  */
  YYSYMBOL_STRUCT = 25,                    /* STRUCT  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_PONTO_VIRGULA = 27,             /* PONTO_VIRGULA  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_VIRGULA = 29,                   /* VIRGULA  */
  YYSYMBOL_FOR = 30,                       /* FOR  */
  YYSYMBOL_BOOLEAN = 31,                   /* BOOLEAN  */
  YYSYMBOL_LOWER_THAN_ELSE = 32,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_UMINUS = 33,                    /* UMINUS  */
  YYSYMBOL_34_n_ = 34,                     /* '\n'  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_programa = 36,                  /* programa  */
  YYSYMBOL_declaracaoLista = 37,           /* declaracaoLista  */
  YYSYMBOL_declaracao = 38,                /* declaracao  */
  YYSYMBOL_varDeclaracao = 39,             /* varDeclaracao  */
  YYSYMBOL_abreNumFecha = 40,              /* abreNumFecha  */
  YYSYMBOL_tipoEspc = 41,                  /* tipoEspc  */
  YYSYMBOL_atriDeclara = 42,               /* atriDeclara  */
  YYSYMBOL_funDeclaracao = 43,             /* funDeclaracao  */
  YYSYMBOL_params = 44,                    /* params  */
  YYSYMBOL_paramLista = 45,                /* paramLista  */
  YYSYMBOL_param = 46,                     /* param  */
  YYSYMBOL_compostDecl = 47,               /* compostDecl  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_localDecla = 49,                /* localDecla  */
  YYSYMBOL_comandLista = 50,               /* comandLista  */
  YYSYMBOL_comand = 51,                    /* comand  */
  YYSYMBOL_exprDecl = 52,                  /* exprDecl  */
  YYSYMBOL_selecDecl = 53,                 /* selecDecl  */
  YYSYMBOL_54_2 = 54,                      /* $@2  */
  YYSYMBOL_else_opt = 55,                  /* else_opt  */
  YYSYMBOL_56_3 = 56,                      /* @3  */
  YYSYMBOL_iterDecl = 57,                  /* iterDecl  */
  YYSYMBOL_58_4 = 58,                      /* @4  */
  YYSYMBOL_returnDecl = 59,                /* returnDecl  */
  YYSYMBOL_expr = 60,                      /* expr  */
  YYSYMBOL_exprSimples = 61,               /* exprSimples  */
  YYSYMBOL_exprSoma = 62,                  /* exprSoma  */
  YYSYMBOL_termo = 63,                     /* termo  */
  YYSYMBOL_fator = 64,                     /* fator  */
  YYSYMBOL_ativacao = 65,                  /* ativacao  */
  YYSYMBOL_args = 66,                      /* args  */
  YYSYMBOL_argLista = 67,                  /* argLista  */
  YYSYMBOL_var = 68,                       /* var  */
  YYSYMBOL_abreExpFecha = 69               /* abreExpFecha  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   108,   108,   112,   113,   117,   118,   122,   129,   139,
     146,   148,   152,   153,   156,   158,   160,   162,   167,   168,
     173,   183,   185,   187,   191,   192,   196,   197,   201,   209,
     222,   222,   227,   228,   232,   233,   237,   238,   239,   240,
     241,   242,   247,   248,   252,   252,   264,   267,   273,   273,
     287,   287,   302,   307,   308,   309,   315,   335,   339,   352,
     355,   370,   385,   390,   405,   412,   416,   430,   433,   441,
     449,   463,   481,   482,   485,   489,   496,   508,   565,   579
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMINT",
  "NUMFLOAT", "STRING", "ABRECOLCHETE", "FECHACOLCHETE", "ATRIBUICAO",
  "RELOP", "MAIS", "MENOS", "MULT", "ABREPARENTESES", "FECHAPARENTESES",
  "ABRECHAVE", "FECHACHAVE", "IF", "ELSE", "WHILE", "INT", "FLOAT", "CHAR",
  "VOID", "STRUCT", "RETURN", "PONTO_VIRGULA", "NOT", "VIRGULA", "FOR",
  "BOOLEAN", "LOWER_THAN_ELSE", "UMINUS", "'\\n'", "$accept", "programa",
  "declaracaoLista", "declaracao", "varDeclaracao", "abreNumFecha",
  "tipoEspc", "atriDeclara", "funDeclaracao", "params", "paramLista",
  "param", "compostDecl", "$@1", "localDecla", "comandLista", "comand",
  "exprDecl", "selecDecl", "$@2", "else_opt", "@3", "iterDecl", "@4",
  "returnDecl", "expr", "exprSimples", "exprSoma", "termo", "fator",
  "ativacao", "args", "argLista", "var", "abreExpFecha", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-26)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      74,   -16,   -91,   -91,   -91,   -91,    25,    72,    90,   -91,
     -91,    21,   -91,   -91,    35,   -91,   -91,    -8,    -4,   118,
      82,   -91,    51,    10,   -91,   118,    76,    40,    58,    83,
      78,    87,   -91,    79,    93,    94,   108,   -91,   100,     2,
     -91,   122,   115,   127,   105,   137,   115,   115,   126,   -91,
     -91,   -91,   -91,   142,   125,   -91,   -91,   -91,   -91,   145,
     -91,   118,   137,   -91,    44,   -91,   128,    39,   -91,   -91,
     133,   133,   -91,   140,   143,    80,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   129,   -91,    31,   146,   -91,   -91,   149,
     -91,   133,   133,   -91,   -91,   147,   116,   121,   134,   -91,
     136,   -91,   133,   133,   133,   133,   133,   152,   -91,   150,
     135,   -91,   151,   153,   154,   155,   -91,   -91,    57,   146,
     146,   -91,   -91,   160,   -91,   133,    62,   -91,    62,   -91,
     133,   -91,   -91,   -91,    62,   -91,    62,   163,   156,   -91,
     160,   -91,   -91,   -91,    62,   -91
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    14,    15,    16,    17,     0,     0,     0,     3,
       6,     0,     5,    23,     0,     1,     4,     0,     0,     0,
       0,    10,     0,     0,     7,    18,     0,     0,    17,     0,
       0,    24,    26,     0,     0,     0,     0,    19,     0,     0,
       9,    28,     0,     0,     0,    13,     0,     0,     0,    30,
      21,    27,    11,     0,     0,    22,    20,    29,    33,     0,
       8,    35,    13,    32,     0,    12,     0,    76,    69,    68,
       0,     0,    31,     0,     0,     0,    43,    37,    34,    36,
      38,    39,    40,     0,    57,    59,    62,    64,    67,    66,
      41,     0,    73,    70,    66,     0,     0,     0,     0,    53,
       0,    42,     0,     0,     0,     0,     0,     0,    74,     0,
      72,    65,     0,     0,     0,     0,    55,    54,    58,    60,
      61,    63,    56,    79,    71,     0,     0,    44,     0,    50,
       0,    77,    75,    46,     0,    52,     0,     0,    47,    51,
      79,    48,    45,    78,     0,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   -91,   164,   -17,   111,     7,   157,   -91,   158,
     -91,   131,   -30,   -91,   -91,   -91,   -26,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -71,   -91,    75,   -90,   -69,
     -91,   -91,   -91,   -65,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    54,    26,    27,    12,    30,
      31,    32,    77,    58,    61,    64,    78,    79,    80,   134,
     142,   144,    81,   136,    82,    83,    84,    85,    86,    87,
      88,   109,   110,    89,   131
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,    93,    25,    22,   100,    94,    20,    11,    25,    22,
      23,    35,    50,   119,   120,    11,    55,    56,    13,    21,
     107,   108,    17,    24,    18,   113,   115,    29,    14,    24,
      29,     2,     3,     4,    28,   122,   121,    94,    94,    94,
      94,   102,   103,   104,    63,    66,    91,    67,    68,    69,
      29,    19,    33,    92,   132,    34,    70,    40,    71,   137,
      49,    72,    73,    66,    74,    67,    68,    69,   103,   104,
      75,    76,    15,   -25,    70,     1,    71,    38,    49,    39,
      73,    98,    74,    67,    68,    69,    41,    44,    75,    76,
      -2,     1,    70,    42,    71,     2,     3,     4,     5,     6,
     133,    45,   135,     2,     3,     4,    28,    99,   138,    46,
     139,     2,     3,     4,     5,     6,    43,   112,   145,    67,
      68,    69,   114,    47,    67,    68,    69,    21,    70,    48,
      71,    49,    52,    70,    57,    71,    67,    68,    69,     2,
       3,     4,     5,     6,    53,    70,    59,    71,     2,     3,
       4,     5,    60,    62,    96,    90,   101,    97,   106,   105,
     123,   116,   111,   117,   125,   124,   126,   130,   127,   128,
     129,   140,    16,    65,    51,   141,   143,   118,     0,     0,
       0,    36,    37
};

static const yytype_int16 yycheck[] =
{
      71,    70,    19,     7,    75,    70,    14,     0,    25,     7,
      14,     1,    42,   103,   104,     8,    46,    47,    34,    27,
      91,    92,     1,    27,     3,    96,    97,    20,     3,    27,
      23,    21,    22,    23,    24,   106,   105,   102,   103,   104,
     105,    10,    11,    12,    61,     1,     7,     3,     4,     5,
      43,    16,     1,    14,   125,     4,    12,    17,    14,   130,
      16,    17,    18,     1,    20,     3,     4,     5,    11,    12,
      26,    27,     0,    15,    12,     1,    14,     1,    16,     3,
      18,     1,    20,     3,     4,     5,     3,     8,    26,    27,
       0,     1,    12,    15,    14,    21,    22,    23,    24,    25,
     126,     8,   128,    21,    22,    23,    24,    27,   134,    15,
     136,    21,    22,    23,    24,    25,    29,     1,   144,     3,
       4,     5,     1,    15,     3,     4,     5,    27,    12,     7,
      14,    16,    27,    12,     8,    14,     3,     4,     5,    21,
      22,    23,    24,    25,     7,    12,     4,    14,    21,    22,
      23,    24,    27,     8,    14,    27,    27,    14,     9,    13,
       8,    27,    15,    27,    29,    15,    15,     7,    15,    15,
      15,     8,     8,    62,    43,    19,   140,   102,    -1,    -1,
      -1,    23,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    21,    22,    23,    24,    25,    36,    37,    38,
      39,    41,    43,    34,     3,     0,    38,     1,     3,    16,
      14,    27,     7,    14,    27,    39,    41,    42,    24,    41,
      44,    45,    46,     1,     4,     1,    44,    42,     1,     3,
      17,     3,    15,    29,     8,     8,    15,    15,     7,    16,
      47,    46,    27,     7,    40,    47,    47,     8,    48,     4,
      27,    49,     8,    39,    50,    40,     1,     3,     4,     5,
      12,    14,    17,    18,    20,    26,    27,    47,    51,    52,
      53,    57,    59,    60,    61,    62,    63,    64,    65,    68,
      27,     7,    14,    64,    68,    60,    14,    14,     1,    27,
      60,    27,    10,    11,    12,    13,     9,    60,    60,    66,
      67,    15,     1,    60,     1,    60,    27,    27,    62,    63,
      63,    64,    60,     8,    15,    29,    15,    15,    15,    15,
       7,    69,    60,    51,    54,    51,    58,    60,    51,    51,
       8,    19,    55,    69,    56,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    39,    39,    39,
      39,    39,    40,    40,    41,    41,    41,    41,    42,    42,
      43,    43,    43,    43,    44,    44,    45,    45,    46,    46,
      48,    47,    49,    49,    50,    50,    51,    51,    51,    51,
      51,    51,    52,    52,    54,    53,    53,    55,    56,    55,
      58,    57,    57,    59,    59,    59,    60,    60,    61,    61,
      62,    62,    62,    63,    63,    64,    64,    64,    64,    64,
      64,    65,    66,    66,    67,    67,    68,    68,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     7,     5,
       3,     6,     4,     0,     1,     1,     1,     1,     1,     2,
       6,     6,     6,     2,     1,     1,     1,     3,     2,     4,
       0,     5,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     2,     2,     1,     0,     7,     5,     0,     0,     3,
       0,     6,     5,     2,     3,     3,     3,     1,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       2,     4,     1,     0,     1,     3,     1,     5,     4,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 7: /* varDeclaracao: tipoEspc ID PONTO_VIRGULA  */
#line 123 "language01.y"
            { 
                if (!inserirSimbolo(current_table, (yyvsp[-1].string), (yyvsp[-2].string))) {
                }
                free((yyvsp[-1].string));
                free((yyvsp[-2].string));
            }
#line 1274 "parser.tab.c"
    break;

  case 8: /* varDeclaracao: tipoEspc ID ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha PONTO_VIRGULA  */
#line 130 "language01.y"
            {
                char array_type[50];
                snprintf(array_type, sizeof(array_type), "%s_array[%d]", (yyvsp[-6].string), (yyvsp[-3].integer));
                if (!inserirSimbolo(current_table, (yyvsp[-5].string), array_type)) {
                    yyerror("Erro na declaração de array");
                }
                free((yyvsp[-5].string));
                free((yyvsp[-6].string));
            }
#line 1288 "parser.tab.c"
    break;

  case 9: /* varDeclaracao: STRUCT ID ABRECHAVE atriDeclara FECHACHAVE  */
#line 140 "language01.y"
            {
                if (!inserirSimbolo(current_table, (yyvsp[-3].string), "struct")) {
                    yyerror("Erro na declaração de struct");
                }
                free((yyvsp[-3].string));
            }
#line 1299 "parser.tab.c"
    break;

  case 10: /* varDeclaracao: tipoEspc error PONTO_VIRGULA  */
#line 147 "language01.y"
            { printf("ERRO: Declaração de variável inválida na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
#line 1305 "parser.tab.c"
    break;

  case 11: /* varDeclaracao: tipoEspc ID ABRECOLCHETE error FECHACOLCHETE PONTO_VIRGULA  */
#line 149 "language01.y"
            { printf("ERRO: Valor inválido ou ausente para o tamanho do arrayna linha %d, coluna %d\n", line_number, column_number); yyerrok; }
#line 1311 "parser.tab.c"
    break;

  case 14: /* tipoEspc: INT  */
#line 157 "language01.y"
            { (yyval.string) = strdup("int"); }
#line 1317 "parser.tab.c"
    break;

  case 15: /* tipoEspc: FLOAT  */
#line 159 "language01.y"
            { (yyval.string) = strdup("float"); }
#line 1323 "parser.tab.c"
    break;

  case 16: /* tipoEspc: CHAR  */
#line 161 "language01.y"
            { (yyval.string) = strdup("char"); }
#line 1329 "parser.tab.c"
    break;

  case 17: /* tipoEspc: VOID  */
#line 163 "language01.y"
            { (yyval.string) = strdup("void"); }
#line 1335 "parser.tab.c"
    break;

  case 20: /* funDeclaracao: tipoEspc ID ABREPARENTESES params FECHAPARENTESES compostDecl  */
#line 174 "language01.y"
            {
                char func_type[50];
                snprintf(func_type, sizeof(func_type), "function_%s", (yyvsp[-5].string));
                if (!inserirSimbolo(current_table, (yyvsp[-4].string), func_type)) {
                    yyerror("Erro na declaração de função");
                }
                free((yyvsp[-4].string));
                free((yyvsp[-5].string));
            }
#line 1349 "parser.tab.c"
    break;

  case 21: /* funDeclaracao: tipoEspc error ABREPARENTESES params FECHAPARENTESES compostDecl  */
#line 184 "language01.y"
            { printf("ERRO: Nome de função ausente ou inválido após o tipo de retorno na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
#line 1355 "parser.tab.c"
    break;

  case 22: /* funDeclaracao: tipoEspc ID ABREPARENTESES error FECHAPARENTESES compostDecl  */
#line 186 "language01.y"
            { printf("ERRO: Lista de parâmetros malformada na declaração de função na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
#line 1361 "parser.tab.c"
    break;

  case 23: /* funDeclaracao: error '\n'  */
#line 187 "language01.y"
                         { printf("Redução: ERRO NA REDUCAO PARA FUNDECLARACAO\n"); yyerrok;}
#line 1367 "parser.tab.c"
    break;

  case 28: /* param: tipoEspc ID  */
#line 202 "language01.y"
            {
                if (!inserirSimbolo(current_table, (yyvsp[0].string), (yyvsp[-1].string))) {
                    yyerror("Erro na declaração de parâmetro");
                }
                free((yyvsp[0].string));
                free((yyvsp[-1].string));
            }
#line 1379 "parser.tab.c"
    break;

  case 29: /* param: tipoEspc ID ABRECOLCHETE FECHACOLCHETE  */
#line 210 "language01.y"
            {
                char param_type[50];
                snprintf(param_type, sizeof(param_type), "%s_array", (yyvsp[-3].string));
                if (!inserirSimbolo(current_table, (yyvsp[-2].string), param_type)) {
                    yyerror("Erro na declaração de parâmetro array");
                }
                free((yyvsp[-2].string));
                free((yyvsp[-3].string));
            }
#line 1393 "parser.tab.c"
    break;

  case 30: /* $@1: %empty  */
#line 222 "language01.y"
                        { enter_scope(); }
#line 1399 "parser.tab.c"
    break;

  case 31: /* compostDecl: ABRECHAVE $@1 localDecla comandLista FECHACHAVE  */
#line 223 "language01.y"
            { exit_scope(); }
#line 1405 "parser.tab.c"
    break;

  case 41: /* comand: error PONTO_VIRGULA  */
#line 243 "language01.y"
            { printf("ERRO: Comando sintaticamente inválido ou incompleto na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
#line 1411 "parser.tab.c"
    break;

  case 44: /* $@2: %empty  */
#line 252 "language01.y"
                                                  {
                char* label_init = new_label();
                char* label_end = new_label();

                LabelPair pair;
                pair.label1 = strdup(label_init);
                pair.label2 = strdup(label_end);
                push_label(&label_stack, pair);
                
                fprintf(codigo_3_enderecos, "ifFalse %s goto %s\n", (yyvsp[-1].attr).nome, label_init);
            }
#line 1427 "parser.tab.c"
    break;

  case 46: /* selecDecl: IF ABREPARENTESES error FECHAPARENTESES comand  */
#line 265 "language01.y"
            { printf("ERRO: Condição inválida no comando IF na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
#line 1433 "parser.tab.c"
    break;

  case 47: /* else_opt: %empty  */
#line 267 "language01.y"
                               {
            LabelPair pair = pop_label(&label_stack);
            fprintf(codigo_3_enderecos, "%s:\n", pair.label1);
            free(pair.label1);
            free(pair.label2);
        }
#line 1444 "parser.tab.c"
    break;

  case 48: /* @3: %empty  */
#line 273 "language01.y"
               {
                LabelPair pair = pop_label(&label_stack);
                fprintf(codigo_3_enderecos, "goto %s\n", pair.label2);
                fprintf(codigo_3_enderecos, "%s:\n", pair.label1);
                (yyval.string) = pair.label2;
                free(pair.label1);
            }
#line 1456 "parser.tab.c"
    break;

  case 49: /* else_opt: ELSE @3 comand  */
#line 279 "language01.y"
                     {
                char* label_end = (yyvsp[-1].string);
                fprintf(codigo_3_enderecos, "%s:\n", label_end);
                free(label_end);
            }
#line 1466 "parser.tab.c"
    break;

  case 50: /* @4: %empty  */
#line 287 "language01.y"
                                                     {
                Rots rotas;

                rotas.rot_inicio.nome = new_label();
                rotas.rot_fim.nome    = new_label();

                (yyval.rotulos) = rotas; // passar início pro lado direito

                fprintf(codigo_3_enderecos, "%s:\n", rotas.rot_inicio.nome);
                fprintf(codigo_3_enderecos, "ifFalse %s goto %s\n", (yyvsp[-1].attr).nome, rotas.rot_fim.nome);
            }
#line 1482 "parser.tab.c"
    break;

  case 51: /* iterDecl: WHILE ABREPARENTESES expr FECHAPARENTESES @4 comand  */
#line 297 "language01.y"
                     {
                fprintf(codigo_3_enderecos, "goto %s\n", (yyvsp[-1].rotulos).rot_inicio.nome); // volta pro início
                fprintf(codigo_3_enderecos, "%s:\n", (yyvsp[-1].rotulos).rot_fim.nome);     // fim do while
            }
#line 1491 "parser.tab.c"
    break;

  case 52: /* iterDecl: WHILE ABREPARENTESES error FECHAPARENTESES comand  */
#line 303 "language01.y"
            { printf("ERRO: Condição inválida no comando WHILE na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
#line 1497 "parser.tab.c"
    break;

  case 55: /* returnDecl: RETURN error PONTO_VIRGULA  */
#line 310 "language01.y"
            { printf("ERRO: Valor de retorno inválido na linha %d, coluna %d\n", line_number, column_number); yyerrok; }
#line 1503 "parser.tab.c"
    break;

  case 56: /* expr: var ATRIBUICAO expr  */
#line 315 "language01.y"
                             { 
                // Verifica compatibilidade de tipos na atribuição
                if (!types_compatible((yyvsp[-2].attr).tipo, (yyvsp[0].attr).tipo)) {
                    printf("ERRO SEMÂNTICO: Incompatibilidade de tipos na atribuição. ");
                    printf("Tentativa de atribuir %s a %s na linha %d\n", 
                           symbol_type_to_string((yyvsp[0].attr).tipo), 
                           symbol_type_to_string((yyvsp[-2].attr).tipo), 
                           line_number);
                }
                
                // Para arrays, o nome já vem no formato "array[endereco]"
                if (strstr((yyvsp[-2].attr).nome, "[") != NULL) {
                    // É uma atribuição a array
                    fprintf(codigo_3_enderecos, "%s = %s\n", (yyvsp[-2].attr).nome, (yyvsp[0].attr).nome);
                } else {
                    // Atribuição normal a variável
                    fprintf(codigo_3_enderecos, "%s = %s\n", (yyvsp[-2].attr).nome, (yyvsp[0].attr).nome);
                }
                (yyval.attr) = (yyvsp[-2].attr);
            }
#line 1528 "parser.tab.c"
    break;

  case 57: /* expr: exprSimples  */
#line 335 "language01.y"
                          {(yyval.attr) = (yyvsp[0].attr);}
#line 1534 "parser.tab.c"
    break;

  case 58: /* exprSimples: exprSoma RELOP exprSoma  */
#line 339 "language01.y"
                                      {
                // Verifica se os operandos são compatíveis para comparação
                if (!is_numeric_type((yyvsp[-2].attr).tipo) || !is_numeric_type((yyvsp[0].attr).tipo)) {
                    printf("ERRO SEMÂNTICO: Operação relacional '%s' requer operandos numéricos na linha %d\n", 
                           (yyvsp[-1].string), line_number);
                }
                
                Atributo resultado;
                resultado.nome = new_temp();
                resultado.tipo = TYPE_INT; // Resultado de comparação é sempre int
                fprintf(codigo_3_enderecos, "%s = %s %s %s\n", resultado.nome, (yyvsp[-2].attr).nome, (yyvsp[-1].string),  (yyvsp[0].attr).nome);
                (yyval.attr) = resultado;
            }
#line 1552 "parser.tab.c"
    break;

  case 59: /* exprSimples: exprSoma  */
#line 352 "language01.y"
                       {(yyval.attr) = (yyvsp[0].attr);}
#line 1558 "parser.tab.c"
    break;

  case 60: /* exprSoma: exprSoma MAIS termo  */
#line 355 "language01.y"
                                 {
                // Verifica se os operandos são numéricos
                SymbolType result_type = get_operation_result_type((yyvsp[-2].attr).tipo, (yyvsp[0].attr).tipo, (yyvsp[-1].string));
                if (result_type == TYPE_ERROR) {
                    printf("ERRO SEMÂNTICO: Operação '%s' entre tipos incompatíveis (%s e %s) na linha %d\n", 
                           (yyvsp[-1].string), symbol_type_to_string((yyvsp[-2].attr).tipo), symbol_type_to_string((yyvsp[0].attr).tipo), line_number);
                    result_type = TYPE_INT; // Fallback
                }
                
                Atributo resultado;
                resultado.nome = new_temp();
                resultado.tipo = result_type;
                fprintf(codigo_3_enderecos, "%s = %s %s %s\n", resultado.nome, (yyvsp[-2].attr).nome, (yyvsp[-1].string),  (yyvsp[0].attr).nome);
                (yyval.attr) = resultado;
            }
#line 1578 "parser.tab.c"
    break;

  case 61: /* exprSoma: exprSoma MENOS termo  */
#line 370 "language01.y"
                                   {
                // Verifica se os operandos são numéricos
                SymbolType result_type = get_operation_result_type((yyvsp[-2].attr).tipo, (yyvsp[0].attr).tipo, (yyvsp[-1].string));
                if (result_type == TYPE_ERROR) {
                    printf("ERRO SEMÂNTICO: Operação '%s' entre tipos incompatíveis (%s e %s) na linha %d\n", 
                           (yyvsp[-1].string), symbol_type_to_string((yyvsp[-2].attr).tipo), symbol_type_to_string((yyvsp[0].attr).tipo), line_number);
                    result_type = TYPE_INT; // Fallback
                }
                
                Atributo resultado;
                resultado.nome = new_temp();
                resultado.tipo = result_type;
                fprintf(codigo_3_enderecos, "%s = %s %s %s\n", resultado.nome, (yyvsp[-2].attr).nome, (yyvsp[-1].string),  (yyvsp[0].attr).nome);
                (yyval.attr) = resultado;
            }
#line 1598 "parser.tab.c"
    break;

  case 62: /* exprSoma: termo  */
#line 385 "language01.y"
                    {
                (yyval.attr) = (yyvsp[0].attr);
            }
#line 1606 "parser.tab.c"
    break;

  case 63: /* termo: termo MULT fator  */
#line 390 "language01.y"
                         {
                // Verifica se os operandos são numéricos
                SymbolType result_type = get_operation_result_type((yyvsp[-2].attr).tipo, (yyvsp[0].attr).tipo, (yyvsp[-1].string));
                if (result_type == TYPE_ERROR) {
                    printf("ERRO SEMÂNTICO: Operação '%s' entre tipos incompatíveis (%s e %s) na linha %d\n", 
                           (yyvsp[-1].string), symbol_type_to_string((yyvsp[-2].attr).tipo), symbol_type_to_string((yyvsp[0].attr).tipo), line_number);
                    result_type = TYPE_INT; // Fallback
                }
                
                Atributo resultado;
                resultado.nome = new_temp();
                resultado.tipo = result_type;
                fprintf(codigo_3_enderecos, "%s = %s %s %s\n", resultado.nome, (yyvsp[-2].attr).nome, (yyvsp[-1].string), (yyvsp[0].attr).nome);
                (yyval.attr) = resultado;
            }
#line 1626 "parser.tab.c"
    break;

  case 64: /* termo: fator  */
#line 405 "language01.y"
                    {
                (yyval.attr) = (yyvsp[0].attr);
            }
#line 1634 "parser.tab.c"
    break;

  case 65: /* fator: ABREPARENTESES expr FECHAPARENTESES  */
#line 412 "language01.y"
                                                {
                (yyval.attr) = (yyvsp[-1].attr);
            }
#line 1642 "parser.tab.c"
    break;

  case 66: /* fator: var  */
#line 416 "language01.y"
                  {
                Atributo resultado;
                
                // Se é um array, precisamos gerar código para acessar o valor
                if (strstr((yyvsp[0].attr).nome, "[") != NULL) {
                    resultado.nome = new_temp();
                    fprintf(codigo_3_enderecos, "%s = %s\n", resultado.nome, (yyvsp[0].attr).nome);
                } else {
                    // Variável normal
                    resultado = (yyvsp[0].attr);
                }
                resultado.tipo = (yyvsp[0].attr).tipo;
                (yyval.attr) = resultado;
            }
#line 1661 "parser.tab.c"
    break;

  case 67: /* fator: ativacao  */
#line 430 "language01.y"
                       {
                (yyval.attr) = (yyvsp[0].attr);
            }
#line 1669 "parser.tab.c"
    break;

  case 68: /* fator: NUMFLOAT  */
#line 433 "language01.y"
                        {
                Atributo resultado;
                char* temp = (char*)malloc(20);
                sprintf(temp, "%f", (yyvsp[0].real));
                resultado.nome = temp;
                resultado.tipo = TYPE_FLOAT;
                (yyval.attr) = resultado;
            }
#line 1682 "parser.tab.c"
    break;

  case 69: /* fator: NUMINT  */
#line 441 "language01.y"
                      {
                Atributo resultado;
                char* temp = (char*)malloc(20);
                sprintf(temp, "%d", (yyvsp[0].integer));
                resultado.nome = temp;
                resultado.tipo = TYPE_INT;
                (yyval.attr) = resultado;
            }
#line 1695 "parser.tab.c"
    break;

  case 70: /* fator: MENOS fator  */
#line 449 "language01.y"
                                       {
                // Verifica se o operando é numérico
                if (!is_numeric_type((yyvsp[0].attr).tipo)) {
                    printf("ERRO SEMÂNTICO: Operador unário '-' requer operando numérico na linha %d\n", line_number);
                }
                
                Atributo resultado;
                resultado.nome = new_temp();
                resultado.tipo = (yyvsp[0].attr).tipo; // Mantém o tipo do operando
                fprintf(codigo_3_enderecos, "%s = -%s\n", resultado.nome, (yyvsp[0].attr).nome);
                (yyval.attr) = resultado;
            }
#line 1712 "parser.tab.c"
    break;

  case 71: /* ativacao: ID ABREPARENTESES args FECHAPARENTESES  */
#line 464 "language01.y"
            {
                Symbol *sym = procurarSimbolo(current_table, (yyvsp[-3].string));
                if (sym == NULL) {
                    yyerror("Função não declarada"); yyerrok;
                } else if (sym->type != TYPE_FUNCTION) {
                    printf("ERRO SEMÂNTICO: '%s' não é uma função na linha %d\n", (yyvsp[-3].string), line_number);
                }
                
                Atributo resultado;
                resultado.nome = new_temp();
                // O tipo do resultado é o tipo de retorno da função
                (yyval.attr) = resultado;
                fprintf(codigo_3_enderecos, "%s = call %s %d\n", resultado.nome, strdup((yyvsp[-3].string)), (yyvsp[-1].param_counter));
                free((yyvsp[-3].string));
            }
#line 1732 "parser.tab.c"
    break;

  case 72: /* args: argLista  */
#line 481 "language01.y"
                { (yyval.param_counter) = (yyvsp[0].param_counter); }
#line 1738 "parser.tab.c"
    break;

  case 73: /* args: %empty  */
#line 482 "language01.y"
       { (yyval.param_counter) = 0; }
#line 1744 "parser.tab.c"
    break;

  case 74: /* argLista: expr  */
#line 485 "language01.y"
                  {
                fprintf(codigo_3_enderecos, "param %s\n", (yyvsp[0].attr).nome);
                (yyval.param_counter) = 1;
            }
#line 1753 "parser.tab.c"
    break;

  case 75: /* argLista: argLista VIRGULA expr  */
#line 489 "language01.y"
                                    {
                fprintf(codigo_3_enderecos, "param %s\n", (yyvsp[0].attr).nome);
                (yyval.param_counter) = (yyvsp[-2].param_counter) + 1;
            }
#line 1762 "parser.tab.c"
    break;

  case 76: /* var: ID  */
#line 497 "language01.y"
            {
                Symbol *sym = procurarSimbolo(current_table, (yyvsp[0].string));
                if (sym == NULL) {
                    printf("ERRO: Identificador '%s' não foi declarado ou está fora de escopo\n", (yyvsp[0].string));
                }
                Atributo resultado;
                resultado.nome = strdup((yyvsp[0].string));
                resultado.tipo = sym ? sym->type : TYPE_ERROR;
                (yyval.attr) = resultado;
                free((yyvsp[0].string));
            }
#line 1778 "parser.tab.c"
    break;

  case 77: /* var: ID ABRECOLCHETE expr FECHACOLCHETE abreExpFecha  */
#line 509 "language01.y"
            {
                Symbol *sym = procurarSimbolo(current_table, (yyvsp[-4].string));
                if (sym == NULL) {
                    printf("ERRO: Identificador '%s' não foi declarado ou está fora de escopo\n", (yyvsp[-4].string));
                } else if (!is_array_type(sym->type)) {
                    printf("ERRO: '%s' não é um array\n", (yyvsp[-4].string));
                } else {
                    // Verifica se o índice é inteiro
                    if ((yyvsp[-2].attr).tipo != TYPE_INT && (yyvsp[-2].attr).tipo != TYPE_CHAR) {
                        printf("ERRO SEMÂNTICO: Índice de array deve ser inteiro, encontrado %s na linha %d\n", 
                               symbol_type_to_string((yyvsp[-2].attr).tipo), line_number);
                    }
                }
                
                Atributo resultado;
                
                if ((yyvsp[0].attr).nome != NULL && strlen((yyvsp[0].attr).nome) > 0) {
                    // Array multidimensional
                    
                    char* endereco_final = new_temp();
                    char* indices_extras = strdup((yyvsp[0].attr).nome);
                    char* primeiro_extra = strtok(indices_extras, ",");
                    
                    if (primeiro_extra) {
                        // arr[i][j] - caso bidimensional
                        char* mult_temp = new_temp();
                        fprintf(codigo_3_enderecos, "%s = %s * 10\n", mult_temp, (yyvsp[-2].attr).nome); // Assume tamanho 10 por padrão
                        fprintf(codigo_3_enderecos, "%s = %s + %s\n", endereco_final, mult_temp, primeiro_extra);
                        
                        // Se há mais dimensões
                        char* proximo_indice;
                        while ((proximo_indice = strtok(NULL, ",")) != NULL) {
                            char* mult_temp2 = new_temp();
                            char* soma_temp = new_temp();
                            fprintf(codigo_3_enderecos, "%s = %s * 10\n", mult_temp2, endereco_final);
                            fprintf(codigo_3_enderecos, "%s = %s + %s\n", soma_temp, mult_temp2, proximo_indice);
                            endereco_final = soma_temp;
                        }
                    }
                    
                    // Para retornar, criamos um nome que indica array com endereço calculado
                    resultado.nome = (char*)malloc(strlen((yyvsp[-4].string)) + strlen(endereco_final) + 10);
                    sprintf(resultado.nome, "%s[%s]", (yyvsp[-4].string), endereco_final);
                    free(indices_extras);
                } else {
                    // Array unidimensional: arr[i]
                    resultado.nome = (char*)malloc(strlen((yyvsp[-4].string)) + strlen((yyvsp[-2].attr).nome) + 10);
                    sprintf(resultado.nome, "%s[%s]", (yyvsp[-4].string), (yyvsp[-2].attr).nome);
                }
                
                // Para acesso a array, o tipo é o tipo base do array
                resultado.tipo = sym ? get_base_type(sym->type) : TYPE_ERROR;
                (yyval.attr) = resultado;
                free((yyvsp[-4].string));
            }
#line 1838 "parser.tab.c"
    break;

  case 78: /* abreExpFecha: ABRECOLCHETE expr FECHACOLCHETE abreExpFecha  */
#line 566 "language01.y"
            {
                // Concatena os índices para arrays multidimensionais
                if ((yyvsp[0].attr).nome != NULL && strlen((yyvsp[0].attr).nome) > 0) {
                    // Há mais índices após este
                    char* temp = (char*)malloc(strlen((yyvsp[-2].attr).nome) + strlen((yyvsp[0].attr).nome) + 2);
                    sprintf(temp, "%s,%s", (yyvsp[-2].attr).nome, (yyvsp[0].attr).nome);
                    (yyval.attr).nome = temp;
                } else {
                    // Este é o último índice
                    (yyval.attr).nome = strdup((yyvsp[-2].attr).nome);
                }
            }
#line 1855 "parser.tab.c"
    break;

  case 79: /* abreExpFecha: %empty  */
#line 579 "language01.y"
            {
                (yyval.attr).nome = strdup(""); // String vazia para indicar fim
            }
#line 1863 "parser.tab.c"
    break;


#line 1867 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 583 "language01.y"


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

    // Abre o arquivo para código de 3 endereços
    codigo_3_enderecos = fopen("codigo_3_enderecos.txt", "w");
    if (!codigo_3_enderecos) {
        printf("Erro ao criar arquivo de código de 3 endereços.\n");
        fclose(arq_compilado);
        return -3;
    }

    // Inicializa a tabela de símbolos
    iniciarTabelaDeSimbolos();

    yyin = arq_compilado;
    if (yyparse() == 0) {
        printf("\n==========================================\n");
        printf("Análise sintática concluída com sucesso!\n");
        printf("==========================================\n");
        printf("Código de 3 endereços gerado em: codigo_3_enderecos.txt\n");
        
        // Imprime a tabela de símbolos final
        imprimirTodasTabela(current_table);
    }

    // Libera memória da tabela de símbolos
    limparTabela();
    
    // Fecha os arquivos
    fclose(arq_compilado);
    fclose(codigo_3_enderecos);
    
    return 0;
}
