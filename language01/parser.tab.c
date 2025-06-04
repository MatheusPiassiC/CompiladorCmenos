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
    extern FILE *yyin;

    extern int yylex();
    extern int yyparse(void);
    void yyerror(const char *s);

    extern int line_number;
    extern int column_number;

#line 84 "parser.tab.c"

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
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_ABRECOLCHETE = 5,               /* ABRECOLCHETE  */
  YYSYMBOL_FECHACOLCHETE = 6,              /* FECHACOLCHETE  */
  YYSYMBOL_ATRIBUICAO = 7,                 /* ATRIBUICAO  */
  YYSYMBOL_RELOP = 8,                      /* RELOP  */
  YYSYMBOL_SOMA = 9,                       /* SOMA  */
  YYSYMBOL_MULT = 10,                      /* MULT  */
  YYSYMBOL_ABREPARENTESES = 11,            /* ABREPARENTESES  */
  YYSYMBOL_FECHAPARENTESES = 12,           /* FECHAPARENTESES  */
  YYSYMBOL_NUMFLOAT = 13,                  /* NUMFLOAT  */
  YYSYMBOL_NUMINT = 14,                    /* NUMINT  */
  YYSYMBOL_ABRECHAVE = 15,                 /* ABRECHAVE  */
  YYSYMBOL_FECHACHAVE = 16,                /* FECHACHAVE  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_INT = 20,                       /* INT  */
  YYSYMBOL_FLOAT = 21,                     /* FLOAT  */
  YYSYMBOL_CHAR = 22,                      /* CHAR  */
  YYSYMBOL_VOID = 23,                      /* VOID  */
  YYSYMBOL_STRUCT = 24,                    /* STRUCT  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_PONTO_VIRGULA = 26,             /* PONTO_VIRGULA  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_VIRGULA = 28,                   /* VIRGULA  */
  YYSYMBOL_FOR = 29,                       /* FOR  */
  YYSYMBOL_BOOLEAN = 30,                   /* BOOLEAN  */
  YYSYMBOL_UMINUS = 31,                    /* UMINUS  */
  YYSYMBOL_32_n_ = 32,                     /* '\n'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_programa = 35,                  /* programa  */
  YYSYMBOL_declaracaoLista = 36,           /* declaracaoLista  */
  YYSYMBOL_declaracao = 37,                /* declaracao  */
  YYSYMBOL_varDeclaracao = 38,             /* varDeclaracao  */
  YYSYMBOL_abreNumFecha = 39,              /* abreNumFecha  */
  YYSYMBOL_tipoEspc = 40,                  /* tipoEspc  */
  YYSYMBOL_atriDeclara = 41,               /* atriDeclara  */
  YYSYMBOL_funDeclaracao = 42,             /* funDeclaracao  */
  YYSYMBOL_params = 43,                    /* params  */
  YYSYMBOL_paramLista = 44,                /* paramLista  */
  YYSYMBOL_param = 45,                     /* param  */
  YYSYMBOL_compostDecl = 46,               /* compostDecl  */
  YYSYMBOL_localDecla = 47,                /* localDecla  */
  YYSYMBOL_comandLista = 48,               /* comandLista  */
  YYSYMBOL_comand = 49,                    /* comand  */
  YYSYMBOL_exprDecl = 50,                  /* exprDecl  */
  YYSYMBOL_selecDecl = 51,                 /* selecDecl  */
  YYSYMBOL_iterDecl = 52,                  /* iterDecl  */
  YYSYMBOL_returnDecl = 53,                /* returnDecl  */
  YYSYMBOL_expr = 54,                      /* expr  */
  YYSYMBOL_exprSimples = 55,               /* exprSimples  */
  YYSYMBOL_exprSoma = 56,                  /* exprSoma  */
  YYSYMBOL_termo = 57,                     /* termo  */
  YYSYMBOL_fator = 58,                     /* fator  */
  YYSYMBOL_ativacao = 59,                  /* ativacao  */
  YYSYMBOL_args = 60,                      /* args  */
  YYSYMBOL_argLista = 61,                  /* argLista  */
  YYSYMBOL_var = 62,                       /* var  */
  YYSYMBOL_abreExpFecha = 63               /* abreExpFecha  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      32,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    33,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    50,    50,    55,    57,    62,    64,    69,    71,    72,
      76,    79,    82,    84,    86,    88,    93,    95,   101,   103,
     107,   109,   114,   116,   121,   123,   128,   134,   137,   141,
     144,   148,   150,   152,   154,   156,   161,   163,   168,   170,
     175,   180,   182,   188,   190,   195,   197,   201,   203,   207,
     209,   214,   216,   218,   220,   222,   224,   228,   232,   235,
     238,   240,   245,   247,   250,   253
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "STRING",
  "ABRECOLCHETE", "FECHACOLCHETE", "ATRIBUICAO", "RELOP", "SOMA", "MULT",
  "ABREPARENTESES", "FECHAPARENTESES", "NUMFLOAT", "NUMINT", "ABRECHAVE",
  "FECHACHAVE", "IF", "ELSE", "WHILE", "INT", "FLOAT", "CHAR", "VOID",
  "STRUCT", "RETURN", "PONTO_VIRGULA", "NOT", "VIRGULA", "FOR", "BOOLEAN",
  "UMINUS", "'\\n'", "'-'", "$accept", "programa", "declaracaoLista",
  "declaracao", "varDeclaracao", "abreNumFecha", "tipoEspc", "atriDeclara",
  "funDeclaracao", "params", "paramLista", "param", "compostDecl",
  "localDecla", "comandLista", "comand", "exprDecl", "selecDecl",
  "iterDecl", "returnDecl", "expr", "exprSimples", "exprSoma", "termo",
  "fator", "ativacao", "args", "argLista", "var", "abreExpFecha", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      67,   -18,   -57,   -57,   -57,   -57,     4,    18,    77,   -57,
     -57,    16,   -57,   -57,     5,   -57,   -57,    23,    82,    13,
      73,   -57,    82,    33,    28,    40,    35,    45,    46,    32,
     -57,   -57,    -2,   -57,    61,    66,    69,    87,    60,    55,
      76,   -57,   -57,   -57,   105,   -57,   -57,    82,    61,   -57,
      26,   -57,     6,    -1,   -57,   -57,   -57,   101,   102,    59,
     -57,    -1,   -57,   -57,   -57,   -57,   -57,   -57,    88,   -57,
       7,   106,   -57,   -57,   108,    -1,    -1,   107,    -1,    -1,
     -57,    91,   -57,   -57,   -57,    -1,    -1,    -1,    -1,   112,
     -57,   109,    92,   -57,   110,   111,   -57,   115,   106,   -57,
     -57,   -57,   -57,    -1,    50,    50,   120,   -57,   113,   -57,
      -1,    50,   121,   -57,   -57
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    12,    13,    14,    15,     0,     0,     0,     3,
       6,     0,     5,    19,     0,     1,     4,     0,     0,     0,
       0,     7,    16,     0,     0,     0,    15,     0,     0,    20,
      22,    17,     0,     9,    11,    24,     0,     0,     0,     0,
       0,    28,    18,    23,     0,     8,    25,    30,    11,    27,
       0,    10,    62,     0,    54,    55,    26,     0,     0,     0,
      37,     0,    32,    29,    31,    33,    34,    35,     0,    44,
      46,    48,    50,    53,    52,     0,    59,     0,     0,     0,
      41,     0,    56,    52,    36,     0,     0,     0,     0,     0,
      60,     0,    58,    51,     0,     0,    42,    45,    47,    49,
      43,    65,    57,     0,     0,     0,    63,    61,    38,    40,
       0,     0,     0,    39,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -57,   118,   -14,    80,     1,   114,   -57,   -57,
     -57,    93,    96,   -57,   -57,   -25,   -57,   -57,   -57,   -57,
     -53,   -57,    44,    47,   -56,   -57,   -57,   -57,   -31,   -57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    39,    23,    24,    12,    28,
      29,    30,    62,    47,    50,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    91,    92,    74,   106
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      77,    11,    52,    19,    22,    82,    81,    14,    22,    11,
      53,    75,    54,    55,    13,    85,    86,    76,    15,    17,
      18,    27,    89,    90,    21,    94,    95,    25,    19,    52,
      83,    99,    61,    49,    20,   100,    32,    53,    27,    54,
      55,    41,    56,    57,    33,    58,    34,   -21,    35,    21,
     107,    59,    60,    52,    83,    83,    83,   112,    36,    61,
      37,    53,    52,    54,    55,    41,    38,    57,     1,    58,
      53,    40,    54,    55,    44,    59,    60,    -2,     1,   108,
     109,    45,    46,    61,    41,    80,   113,     2,     3,     4,
       5,     6,    61,     2,     3,     4,    26,     2,     3,     4,
       5,     6,     2,     3,     4,     5,     6,     2,     3,     4,
       5,    48,    78,    79,    84,    88,    87,    96,   101,    93,
     103,   102,   104,   105,    86,   110,    16,   114,    51,    97,
      43,   111,    42,    98,     0,     0,    31
};

static const yytype_int8 yycheck[] =
{
      53,     0,     3,     5,    18,    61,    59,     3,    22,     8,
      11,     5,    13,    14,    32,     8,     9,    11,     0,     3,
      15,    20,    75,    76,    26,    78,    79,    14,     5,     3,
      61,    87,    33,    47,    11,    88,     3,    11,    37,    13,
      14,    15,    16,    17,    16,    19,     6,    12,     3,    26,
     103,    25,    26,     3,    85,    86,    87,   110,    12,    33,
      28,    11,     3,    13,    14,    15,     5,    17,     1,    19,
      11,     5,    13,    14,    14,    25,    26,     0,     1,   104,
     105,    26,     6,    33,    15,    26,   111,    20,    21,    22,
      23,    24,    33,    20,    21,    22,    23,    20,    21,    22,
      23,    24,    20,    21,    22,    23,    24,    20,    21,    22,
      23,     6,    11,    11,    26,     7,    10,    26,     6,    12,
      28,    12,    12,    12,     9,     5,     8,     6,    48,    85,
      37,    18,    36,    86,    -1,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    20,    21,    22,    23,    24,    35,    36,    37,
      38,    40,    42,    32,     3,     0,    37,     3,    15,     5,
      11,    26,    38,    40,    41,    14,    23,    40,    43,    44,
      45,    41,     3,    16,     6,     3,    12,    28,     5,    39,
       5,    15,    46,    45,    14,    26,     6,    47,     6,    38,
      48,    39,     3,    11,    13,    14,    16,    17,    19,    25,
      26,    33,    46,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    62,     5,    11,    54,    11,    11,
      26,    54,    58,    62,    26,     8,     9,    10,     7,    54,
      54,    60,    61,    12,    54,    54,    26,    56,    57,    58,
      54,     6,    12,    28,    12,    12,    63,    54,    49,    49,
       5,    18,    54,    49,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    38,    38,
      39,    39,    40,    40,    40,    40,    41,    41,    42,    42,
      43,    43,    44,    44,    45,    45,    46,    47,    47,    48,
      48,    49,    49,    49,    49,    49,    50,    50,    51,    51,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    59,    60,    60,
      61,    61,    62,    62,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     7,     5,
       4,     0,     1,     1,     1,     1,     1,     2,     6,     2,
       1,     1,     1,     3,     2,     4,     4,     2,     0,     2,
       0,     1,     1,     1,     1,     1,     2,     1,     5,     7,
       5,     2,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     2,     4,     1,     0,
       1,     3,     1,     5,     4,     0
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
  case 2: /* programa: declaracaoLista  */
#line 51 "language01.y"
            { printf("Redução: programa -> declaracaoLista\n"); }
#line 1213 "parser.tab.c"
    break;

  case 3: /* declaracaoLista: declaracao  */
#line 56 "language01.y"
            { printf("Redução: declaracaoLista -> declaracao\n"); }
#line 1219 "parser.tab.c"
    break;

  case 4: /* declaracaoLista: declaracaoLista declaracao  */
#line 58 "language01.y"
            { printf("Redução: declaracaoLista -> declaracaoLista declaracao\n"); }
#line 1225 "parser.tab.c"
    break;

  case 5: /* declaracao: funDeclaracao  */
#line 63 "language01.y"
            { printf("Redução: declaracao -> funDeclaracao\n"); }
#line 1231 "parser.tab.c"
    break;

  case 6: /* declaracao: varDeclaracao  */
#line 65 "language01.y"
            { printf("Redução: declaracao -> varDeclaracao\n"); }
#line 1237 "parser.tab.c"
    break;

  case 7: /* varDeclaracao: tipoEspc ID PONTO_VIRGULA  */
#line 70 "language01.y"
            { printf("Redução: varDeclaracao -> tipoEspc ID PONTO_VIRGULA\n"); }
#line 1243 "parser.tab.c"
    break;

  case 9: /* varDeclaracao: STRUCT ID ABRECHAVE atriDeclara FECHACHAVE  */
#line 73 "language01.y"
            { printf("Redução: varDeclaracao -> tipoEspc ID ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha PONTO_VIRGULA\n"); }
#line 1249 "parser.tab.c"
    break;

  case 10: /* abreNumFecha: ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha  */
#line 77 "language01.y"
            { printf("Redução: abreNumFecha -> ABRECOLCHETE NUMINT FECHACOLCHETE abreNumFecha\n"); }
#line 1255 "parser.tab.c"
    break;

  case 11: /* abreNumFecha: %empty  */
#line 79 "language01.y"
            { printf("Redução: abreNumFecha -> ε\n"); }
#line 1261 "parser.tab.c"
    break;

  case 12: /* tipoEspc: INT  */
#line 83 "language01.y"
            { printf("Redução: tipoEspc -> INT\n"); }
#line 1267 "parser.tab.c"
    break;

  case 13: /* tipoEspc: FLOAT  */
#line 85 "language01.y"
            { printf("Redução: tipoEspc -> FLOAT\n"); }
#line 1273 "parser.tab.c"
    break;

  case 14: /* tipoEspc: CHAR  */
#line 87 "language01.y"
            { printf("Redução: tipoEspc -> CHAR\n"); }
#line 1279 "parser.tab.c"
    break;

  case 15: /* tipoEspc: VOID  */
#line 89 "language01.y"
            { printf("Redução: tipoEspc -> VOID\n"); }
#line 1285 "parser.tab.c"
    break;

  case 16: /* atriDeclara: varDeclaracao  */
#line 94 "language01.y"
            { printf("Redução: atriDeclara -> varDeclaracao\n"); }
#line 1291 "parser.tab.c"
    break;

  case 17: /* atriDeclara: varDeclaracao atriDeclara  */
#line 96 "language01.y"
            { printf("Redução: atriDeclara -> varDeclaracao atriDeclara\n"); }
#line 1297 "parser.tab.c"
    break;

  case 18: /* funDeclaracao: tipoEspc ID ABREPARENTESES params FECHAPARENTESES compostDecl  */
#line 102 "language01.y"
            { printf("Redução: funDeclaracao -> tipoEspc ID ABREPARENTESES params FECHAPARENTESES compostDecl\n"); }
#line 1303 "parser.tab.c"
    break;

  case 19: /* funDeclaracao: error '\n'  */
#line 103 "language01.y"
                         { printf("Redução: ERRO NA REDUCAO PARA FUNDECLARACAO\n"); yyerrok;}
#line 1309 "parser.tab.c"
    break;

  case 20: /* params: paramLista  */
#line 108 "language01.y"
            { printf("Redução: params -> paramLista\n"); }
#line 1315 "parser.tab.c"
    break;

  case 21: /* params: VOID  */
#line 110 "language01.y"
            { printf("Redução: params -> VOID\n"); }
#line 1321 "parser.tab.c"
    break;

  case 22: /* paramLista: param  */
#line 115 "language01.y"
            { printf("Redução: paramLista -> param\n"); }
#line 1327 "parser.tab.c"
    break;

  case 23: /* paramLista: paramLista VIRGULA param  */
#line 117 "language01.y"
            { printf("Redução: paramLista -> paramLista VIRGULA param\n"); }
#line 1333 "parser.tab.c"
    break;

  case 24: /* param: tipoEspc ID  */
#line 122 "language01.y"
            { printf("Redução: param -> tipoEspc ID\n"); }
#line 1339 "parser.tab.c"
    break;

  case 25: /* param: tipoEspc ID ABRECOLCHETE FECHACOLCHETE  */
#line 124 "language01.y"
            { printf("Redução: param -> tipoEspc ID ABRECOLCHETE FECHACOLCHETE\n"); }
#line 1345 "parser.tab.c"
    break;

  case 26: /* compostDecl: ABRECHAVE localDecla comandLista FECHACHAVE  */
#line 129 "language01.y"
            { printf("Redução: compostDecl -> ABRECHAVE localDecla comandLista FECHACHAVE\n"); }
#line 1351 "parser.tab.c"
    break;

  case 27: /* localDecla: localDecla varDeclaracao  */
#line 135 "language01.y"
            { printf("Redução: localDecla -> localDecla varDeclaracao\n"); }
#line 1357 "parser.tab.c"
    break;

  case 28: /* localDecla: %empty  */
#line 137 "language01.y"
            { printf("Redução: localDecla -> ε\n"); }
#line 1363 "parser.tab.c"
    break;

  case 29: /* comandLista: comandLista comand  */
#line 142 "language01.y"
            { printf("Redução: comandLista -> comandLista comand\n"); }
#line 1369 "parser.tab.c"
    break;

  case 30: /* comandLista: %empty  */
#line 144 "language01.y"
            { printf("Redução: comandLista -> ε\n"); }
#line 1375 "parser.tab.c"
    break;

  case 31: /* comand: exprDecl  */
#line 149 "language01.y"
            { printf("Redução: comand -> exprDecl\n"); }
#line 1381 "parser.tab.c"
    break;

  case 32: /* comand: compostDecl  */
#line 151 "language01.y"
            { printf("Redução: comand -> compostDecl\n"); }
#line 1387 "parser.tab.c"
    break;

  case 33: /* comand: selecDecl  */
#line 153 "language01.y"
            { printf("Redução: comand -> selecDecl\n"); }
#line 1393 "parser.tab.c"
    break;

  case 34: /* comand: iterDecl  */
#line 155 "language01.y"
            { printf("Redução: comand -> iterDecl\n"); }
#line 1399 "parser.tab.c"
    break;

  case 35: /* comand: returnDecl  */
#line 157 "language01.y"
            { printf("Redução: comand -> returnDecl\n"); }
#line 1405 "parser.tab.c"
    break;

  case 36: /* exprDecl: expr PONTO_VIRGULA  */
#line 162 "language01.y"
            { printf("Redução: exprDecl -> expr PONTO_VIRGULA\n"); }
#line 1411 "parser.tab.c"
    break;

  case 37: /* exprDecl: PONTO_VIRGULA  */
#line 164 "language01.y"
            { printf("Redução: exprDecl -> PONTO_VIRGULA\n"); }
#line 1417 "parser.tab.c"
    break;

  case 38: /* selecDecl: IF ABREPARENTESES expr FECHAPARENTESES comand  */
#line 169 "language01.y"
            { printf("Redução: selecDecl -> IF ABREPARENTESES expr FECHAPARENTESES comand\n"); }
#line 1423 "parser.tab.c"
    break;

  case 39: /* selecDecl: IF ABREPARENTESES expr FECHAPARENTESES comand ELSE comand  */
#line 171 "language01.y"
            { printf("Redução: selecDecl -> IF ABREPARENTESES expr FECHAPARENTESES comand ELSE comand\n"); }
#line 1429 "parser.tab.c"
    break;

  case 40: /* iterDecl: WHILE ABREPARENTESES expr FECHAPARENTESES comand  */
#line 176 "language01.y"
            { printf("Redução: iterDecl -> WHILE ABREPARENTESES expr FECHAPARENTESES comand\n"); }
#line 1435 "parser.tab.c"
    break;

  case 41: /* returnDecl: RETURN PONTO_VIRGULA  */
#line 181 "language01.y"
            { printf("Redução: returnDecl -> RETURN PONTO_VIRGULA\n"); }
#line 1441 "parser.tab.c"
    break;

  case 42: /* returnDecl: RETURN expr PONTO_VIRGULA  */
#line 183 "language01.y"
            { printf("Redução: returnDecl -> RETURN expr PONTO_VIRGULA\n"); }
#line 1447 "parser.tab.c"
    break;

  case 43: /* expr: var ATRIBUICAO expr  */
#line 189 "language01.y"
            { printf("Redução: expr -> var ATRIBUICAO expr\n"); }
#line 1453 "parser.tab.c"
    break;

  case 44: /* expr: exprSimples  */
#line 191 "language01.y"
            { printf("Redução: expr -> exprSimples\n"); }
#line 1459 "parser.tab.c"
    break;

  case 45: /* exprSimples: exprSoma RELOP exprSoma  */
#line 196 "language01.y"
            { printf("Redução: exprSimples -> exprSoma RELOP exprSoma\n"); }
#line 1465 "parser.tab.c"
    break;

  case 46: /* exprSimples: exprSoma  */
#line 198 "language01.y"
            { printf("Redução: exprSimples -> exprSoma\n"); }
#line 1471 "parser.tab.c"
    break;

  case 47: /* exprSoma: exprSoma SOMA termo  */
#line 202 "language01.y"
            { printf("Redução: exprSoma -> exprSoma SOMA termo\n"); yyval = yyvsp[-2] + yyvsp[0];}
#line 1477 "parser.tab.c"
    break;

  case 48: /* exprSoma: termo  */
#line 204 "language01.y"
            { printf("Redução: exprSoma -> termo\n"); }
#line 1483 "parser.tab.c"
    break;

  case 49: /* termo: termo MULT fator  */
#line 208 "language01.y"
            { printf("Redução: termo -> termo MULT fator\n"); }
#line 1489 "parser.tab.c"
    break;

  case 50: /* termo: fator  */
#line 210 "language01.y"
            { printf("Redução: termo -> fator\n"); }
#line 1495 "parser.tab.c"
    break;

  case 51: /* fator: ABREPARENTESES expr FECHAPARENTESES  */
#line 215 "language01.y"
            { printf("Redução: fator -> ABREPARENTESES expr FECHAPARENTESES\n"); yyval = yyvsp[-1];}
#line 1501 "parser.tab.c"
    break;

  case 52: /* fator: var  */
#line 217 "language01.y"
            { printf("Redução: fator -> var\n"); }
#line 1507 "parser.tab.c"
    break;

  case 53: /* fator: ativacao  */
#line 219 "language01.y"
            { printf("Redução: fator -> ativacao\n"); }
#line 1513 "parser.tab.c"
    break;

  case 54: /* fator: NUMFLOAT  */
#line 221 "language01.y"
            { printf("Redução: fator -> NUMFLOAT\n"); }
#line 1519 "parser.tab.c"
    break;

  case 55: /* fator: NUMINT  */
#line 223 "language01.y"
            { printf("Redução: fator -> NUMINT\n"); }
#line 1525 "parser.tab.c"
    break;

  case 56: /* fator: '-' fator  */
#line 225 "language01.y"
            { printf("Redução: fator -> - fator\n"); }
#line 1531 "parser.tab.c"
    break;

  case 57: /* ativacao: ID ABREPARENTESES args FECHAPARENTESES  */
#line 229 "language01.y"
            { printf("Redução: ativacao -> ID ABREPARENTESES args FECHAPARENTESES\n"); }
#line 1537 "parser.tab.c"
    break;

  case 58: /* args: argLista  */
#line 233 "language01.y"
            { printf("Redução: args -> argLista\n"); }
#line 1543 "parser.tab.c"
    break;

  case 59: /* args: %empty  */
#line 235 "language01.y"
            { printf("Redução: args -> ε\n"); }
#line 1549 "parser.tab.c"
    break;

  case 60: /* argLista: expr  */
#line 239 "language01.y"
            { printf("Redução: argLista -> expr\n"); }
#line 1555 "parser.tab.c"
    break;

  case 61: /* argLista: argLista VIRGULA expr  */
#line 241 "language01.y"
            { printf("Redução: argLista -> argLista VIRGULA expr\n"); }
#line 1561 "parser.tab.c"
    break;

  case 62: /* var: ID  */
#line 246 "language01.y"
            { printf("Redução: var -> ID\n"); }
#line 1567 "parser.tab.c"
    break;

  case 63: /* var: ID ABRECOLCHETE expr FECHACOLCHETE abreExpFecha  */
#line 248 "language01.y"
            { printf("Redução: var -> ID ABRECOLCHETE expr FECHACOLCHETE abreExpFecha\n"); yyval = yyvsp[-4];}
#line 1573 "parser.tab.c"
    break;

  case 64: /* abreExpFecha: abreExpFecha ABRECOLCHETE expr FECHACOLCHETE  */
#line 251 "language01.y"
            { printf("Redução: abreExpFecha -> abreExpFecha ABRECOLCHETE expr FECHACOLCHETE\n"); }
#line 1579 "parser.tab.c"
    break;

  case 65: /* abreExpFecha: %empty  */
#line 253 "language01.y"
            { printf("Redução: abreExpFecha -> ε\n"); }
#line 1585 "parser.tab.c"
    break;


#line 1589 "parser.tab.c"

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

#line 255 "language01.y"


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

    yyin = arq_compilado;
    if (yyparse() == 0) {
        printf("\n==========================================\n");
        printf("Análise sintática concluída com sucesso!\n");
        printf("==========================================\n");
    }

    fclose(arq_compilado);
    return 0;
}
