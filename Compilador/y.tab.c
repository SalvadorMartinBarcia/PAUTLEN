/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "alfa.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "alfa.h"
	#include "tablaHash.h"

	void yyerror(char const *cad);/**/
	extern int linea, columna, flagError;/**/
	extern FILE *yyin;/**/
	extern FILE *out;/**/
	extern int yylex();/**/
	
	TIPO tipo_actual;/**/
	CLASE clase_actual;/**/
	int tamVector;/**/


	INFO_SIMBOLO simbolo;/**/
	INFO_SIMBOLO *buscar;/**/

	int num_no = 0;
	int num_comparaciones = 0;
	int num_If = 0;/**/
	int num_bucles = 0;
	int pos_variable_local_actual = 0;
	int num_variables_locales_actual = 0;
	int num_parametros_actual = 0;
	int pos_parametro_actual = 0;

	int es_funcion = 0;/**/
	int es_llamada = 0;
	int params = 0;
	int hay_return = 0;

#line 102 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_MAIN = 258,
    TOK_INT = 259,
    TOK_BOOLEAN = 260,
    TOK_ARRAY = 261,
    TOK_FUNCTION = 262,
    TOK_IF = 263,
    TOK_ELSE = 264,
    TOK_WHILE = 265,
    TOK_SCANF = 266,
    TOK_PRINTF = 267,
    TOK_RETURN = 268,
    TOK_PUNTOYCOMA = 269,
    TOK_COMA = 270,
    TOK_PARENTESISIZQUIERDO = 271,
    TOK_PARENTESISDERECHO = 272,
    TOK_CORCHETEIZQUIERDO = 273,
    TOK_CORCHETEDERECHO = 274,
    TOK_LLAVEIZQUIERDA = 275,
    TOK_LLAVEDERECHA = 276,
    TOK_ASIGNACION = 277,
    TOK_MAS = 278,
    TOK_MENOS = 279,
    TOK_DIVISION = 280,
    TOK_ASTERISCO = 281,
    TOK_AND = 282,
    TOK_OR = 283,
    TOK_NOT = 284,
    TOK_IGUAL = 285,
    TOK_DISTINTO = 286,
    TOK_MENORIGUAL = 287,
    TOK_MAYORIGUAL = 288,
    TOK_MENOR = 289,
    TOK_MAYOR = 290,
    TOK_IDENTIFICADOR = 291,
    TOK_CONSTANTE_ENTERA = 292,
    TOK_TRUE = 293,
    TOK_FALSE = 294,
    TOK_ERROR = 295
  };
#endif
/* Tokens.  */
#define TOK_MAIN 258
#define TOK_INT 259
#define TOK_BOOLEAN 260
#define TOK_ARRAY 261
#define TOK_FUNCTION 262
#define TOK_IF 263
#define TOK_ELSE 264
#define TOK_WHILE 265
#define TOK_SCANF 266
#define TOK_PRINTF 267
#define TOK_RETURN 268
#define TOK_PUNTOYCOMA 269
#define TOK_COMA 270
#define TOK_PARENTESISIZQUIERDO 271
#define TOK_PARENTESISDERECHO 272
#define TOK_CORCHETEIZQUIERDO 273
#define TOK_CORCHETEDERECHO 274
#define TOK_LLAVEIZQUIERDA 275
#define TOK_LLAVEDERECHA 276
#define TOK_ASIGNACION 277
#define TOK_MAS 278
#define TOK_MENOS 279
#define TOK_DIVISION 280
#define TOK_ASTERISCO 281
#define TOK_AND 282
#define TOK_OR 283
#define TOK_NOT 284
#define TOK_IGUAL 285
#define TOK_DISTINTO 286
#define TOK_MENORIGUAL 287
#define TOK_MAYORIGUAL 288
#define TOK_MENOR 289
#define TOK_MAYOR 290
#define TOK_IDENTIFICADOR 291
#define TOK_CONSTANTE_ENTERA 292
#define TOK_TRUE 293
#define TOK_FALSE 294
#define TOK_ERROR 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 38 "alfa.y" /* yacc.c:355  */

	tipo_atributos atributos;

#line 226 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   112,   114,   119,   124,   127,   133,   138,
     141,   147,   159,   161,   166,   168,   175,   199,   216,   245,
     247,   252,   254,   258,   265,   284,   286,   291,   292,   297,
     299,   304,   306,   308,   310,   315,   317,   322,   353,   363,
     391,   394,   399,   410,   416,   422,   428,   439,   450,   456,
     467,   476,   485,   494,   503,   512,   521,   530,   539,   566,
     571,   575,   579,   582,   603,   614,   619,   625,   628,   632,
     639,   646,   653,   660,   667,   674,   684,   689,   697,   702,
     710,   717,   752,   757
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN",
  "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_PUNTOYCOMA", "TOK_COMA",
  "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
  "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS", "TOK_MENOS",
  "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL",
  "TOK_MENOR", "TOK_MAYOR", "TOK_IDENTIFICADOR", "TOK_CONSTANTE_ENTERA",
  "TOK_TRUE", "TOK_FALSE", "TOK_ERROR", "$accept", "programa",
  "declaraciones", "declaracion", "clase", "clase_escalar", "tipo",
  "clase_vector", "identificadores", "funciones", "funcion",
  "fn_declaration", "fn_name", "parametros_funcion",
  "resto_parametros_funcion", "parametro_funcion", "idpf",
  "declaraciones_funcion", "sentencias", "sentencia", "sentencia_simple",
  "bloque", "asignacion", "elemento_vector", "condicional", "if_exp",
  "if_exp_sentencias", "bucle", "while", "while_exp", "lectura",
  "escritura", "retorno_funcion", "exp", "call_func", "lista_expresiones",
  "resto_lista_expresiones", "expf", "comparacion", "constante",
  "constante_logica", "constante_entera", "identificador", "tabla", "main", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -31

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-31)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,     0,    21,     5,   -31,   -31,   -31,    10,   -31,     5,
     -12,   -31,   -31,   -31,    11,    23,   -31,   -31,    30,    32,
      14,    10,   -31,    23,    26,    36,   -31,   -12,    34,    18,
      26,   -31,    43,    44,    25,    19,    19,   -10,    42,    26,
      50,   -31,   -31,    51,   -31,    26,    53,   -31,    19,    26,
     -31,   -31,   -31,    10,   -31,   -31,   -31,    55,    19,   -31,
     -31,    19,    19,    19,     9,   -31,   -31,   -31,   -31,   112,
      19,   -31,   -31,   -31,   112,    19,    19,   -31,   -31,   -31,
      19,   -31,    63,    54,    62,    39,    67,    71,   -31,    76,
      89,    69,    15,   -31,   -31,    19,    19,    19,    19,    19,
      19,   112,    77,    80,   106,   112,   112,    78,    85,   -31,
     -31,   -31,    87,    10,   -31,    90,   -31,    19,    19,    19,
      19,    19,    19,   -31,    15,    15,   -31,   -31,   -31,    15,
     -31,    19,   -31,   -31,    26,   -31,     5,    71,   -31,   112,
     112,   112,   112,   112,   112,    80,    75,   -31,   -31,   -31,
     -31,   -31
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     9,    10,     0,    82,     3,
       0,     6,     8,     7,     0,    15,     4,    81,     0,    12,
       0,     0,    83,    15,     0,     0,     5,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,    27,
       0,    30,    31,     0,    35,     0,     0,    36,     0,     0,
      32,    33,    34,    20,    13,    11,    18,     0,     0,    45,
      47,     0,     0,     0,    58,    80,    78,    79,    62,    48,
      66,    59,    76,    77,    49,     0,     0,    16,    28,    29,
       0,    43,    40,     0,     0,     0,     0,    22,     2,     0,
       0,     0,    54,    57,    64,     0,     0,     0,     0,     0,
       0,    69,     0,    68,     0,    37,    38,     0,     0,    44,
      24,    23,     0,     0,    19,     0,    60,     0,     0,     0,
       0,     0,     0,    61,    50,    51,    52,    53,    55,    56,
      63,     0,    65,    39,     0,    46,    26,    22,    42,    70,
      71,    72,    73,    74,    75,    68,     0,    25,    17,    21,
      67,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,    -9,   -31,   -31,   -31,    -4,   -31,    70,    95,
     -31,   -31,   -31,   -31,   -11,    28,   -31,   -31,   -26,   -31,
     -31,   -31,   -31,   -23,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -30,   -31,   -31,   -17,    12,   -31,   -31,
     -31,   -31,   -31,   -31,   -31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    11,    12,    13,    18,    22,
      23,    24,    25,    86,   114,    87,   111,   148,    38,    39,
      40,    41,    42,    68,    44,    45,    46,    47,    48,    49,
      50,    51,    52,   101,    70,   102,   132,   103,    91,    71,
      72,    73,    19,    15,    30
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    43,     1,    14,    57,    69,    74,    43,    75,     5,
       6,     7,    76,    78,     5,     6,    43,    29,    83,    81,
       3,     4,    43,    84,    17,    94,    43,    75,    89,    20,
      21,    90,    92,    93,    32,    61,    33,    34,    35,    36,
      97,    98,    99,    62,    26,   104,   105,    27,    63,    85,
     106,    28,    53,    55,    56,    64,    65,    66,    67,    58,
      59,    60,    37,    77,    79,   124,   125,   126,   127,   128,
     129,   108,   107,    80,    82,   110,    88,    95,    96,    97,
      98,    99,   100,   109,   112,   113,   123,   139,   140,   141,
     142,   143,   144,   115,   130,   131,   151,    54,   134,    95,
      96,    97,    98,    99,   100,   135,   116,   136,   146,    85,
     138,    43,    95,    96,    97,    98,    99,   100,    31,   117,
     118,   119,   120,   121,   122,   133,   149,   147,   150,    95,
      96,    97,    98,    99,   100,    95,    96,    97,    98,    99,
     100,   137,     0,   145
};

static const yytype_int16 yycheck[] =
{
       9,    24,     3,     7,    30,    35,    36,    30,    18,     4,
       5,     6,    22,    39,     4,     5,    39,    21,    48,    45,
      20,     0,    45,    49,    36,    16,    49,    18,    58,    18,
       7,    61,    62,    63,     8,    16,    10,    11,    12,    13,
      25,    26,    27,    24,    14,    75,    76,    15,    29,    53,
      80,    37,    16,    19,    36,    36,    37,    38,    39,    16,
      16,    36,    36,    21,    14,    95,    96,    97,    98,    99,
     100,    17,     9,    22,    21,    36,    21,    23,    24,    25,
      26,    27,    28,    21,    17,    14,    17,   117,   118,   119,
     120,   121,   122,    17,    17,    15,    21,    27,    20,    23,
      24,    25,    26,    27,    28,    20,    17,    20,   134,   113,
      20,   134,    23,    24,    25,    26,    27,    28,    23,    30,
      31,    32,    33,    34,    35,    19,   137,   136,   145,    23,
      24,    25,    26,    27,    28,    23,    24,    25,    26,    27,
      28,   113,    -1,   131
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    42,    20,     0,     4,     5,     6,    43,    44,
      45,    46,    47,    48,    47,    84,    43,    36,    49,    83,
      18,     7,    50,    51,    52,    53,    14,    15,    37,    47,
      85,    50,     8,    10,    11,    12,    13,    36,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    16,    49,    19,    36,    59,    16,    16,
      36,    16,    24,    29,    36,    37,    38,    39,    64,    74,
      75,    80,    81,    82,    74,    18,    22,    21,    59,    14,
      22,    59,    21,    74,    59,    47,    54,    56,    21,    74,
      74,    79,    74,    74,    16,    23,    24,    25,    26,    27,
      28,    74,    76,    78,    74,    74,    74,     9,    17,    21,
      36,    57,    17,    14,    55,    17,    17,    30,    31,    32,
      33,    34,    35,    17,    74,    74,    74,    74,    74,    74,
      17,    15,    77,    19,    20,    20,    20,    56,    20,    74,
      74,    74,    74,    74,    74,    78,    59,    43,    58,    55,
      77,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    45,    45,    46,    47,
      47,    48,    49,    49,    50,    50,    51,    52,    53,    54,
      54,    55,    55,    56,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    61,    62,    62,    63,    63,    64,
      65,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    76,    76,    77,    77,    78,
      79,    79,    79,    79,    79,    79,    80,    80,    81,    81,
      82,    83,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     2,     3,     1,     1,     1,     1,
       1,     5,     1,     3,     2,     0,     3,     6,     3,     2,
       0,     3,     0,     2,     1,     1,     0,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     4,
       2,     6,     5,     2,     3,     2,     4,     2,     2,     2,
       3,     3,     3,     3,     2,     3,     3,     2,     1,     1,
       3,     3,     1,     3,     2,     2,     0,     3,     0,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 107 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
	}
#line 1441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 112 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R2:\t<declaraciones> ::= <declaracion>\n");
	}
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 114 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");
	}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 119 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
	}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 124 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R5:\t<clase> ::= <clase_escalar>\n");
		clase_actual = ESCALAR;
	}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 127 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R7:\t<clase> ::= <clase_vector>\n");
		clase_actual = VECTOR;
	}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 133 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R9:\t<clase_escalar> ::= <tipo>\n");
	}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 138 "alfa.y" /* yacc.c:1646  */
    {
		tipo_actual = ENTERO;
		fprintf(out, ";R10:\t<tipo> ::= int\n");
	}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 141 "alfa.y" /* yacc.c:1646  */
    {
		tipo_actual = BOOLEANO;
		fprintf(out, ";R11:\t<tipo> ::= boolean\n");
	}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 147 "alfa.y" /* yacc.c:1646  */
    {
		//EN $4.valor TENEMOS EL TAMAÑO DEL VECTOR 
		tamVector = (yyvsp[-1].atributos).valor_numerico;	/*DE DONDE SACAS QUE ES $4.VALOR*/
  		//COMPROBACIONES SEMANTICAS (TAMANO > 0 y TAMANO < MAX) Y PROPAGACION EN $$.valor
		if (tamVector <= 0 || tamVector > MAX_TAMANIO_VECTOR){
			fprintf(stdout, "Error en el tamaño del vector\n");
			return -1;
		}
		fprintf(out,";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
	}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 159 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R18:\t<identificadores> ::= <identificador>\n");
	}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 161 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
	}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 166 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R20:\t<funciones> ::= <funcion> <funciones>\n");
	}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 168 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R21:\t<funciones> ::=\n");
	}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 175 "alfa.y" /* yacc.c:1646  */
    {
		/*ERROR SI LA FUNCION NO TIENE SENTENCIA DE RETORNO*/
		if(!hay_return) {
			fprintf(stdout, "***Error semantico en lin %d: Funcion %s sin sentencia de retorno.\n", linea, (yyvsp[-2].atributos).nombre);
			return -1;
		}
		CerrarFuncion();
  		retornarFuncion(out, (yyvsp[-2].atributos).es_direccion);
		buscar = UsoLocal((yyvsp[-2].atributos).nombre);
	
		//ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.nombre
		// Buscamos si ese simbolo existe en la tabla de simbolos local con categoria funcion
		if(buscar == NULL){
			fprintf(stdout, "Error en la función %s,función ya declarada.\n", (yyvsp[-2].atributos).nombre);
			return -1;
		}

		//CIERRE DE AMBITO, ETC
		buscar->adicional1 = num_parametros_actual;
  		es_funcion = 0;
		fprintf(out,";R22 :\t<funcion> ::= function <tipo> <identificador> (<parametros_funcion>) { <declaraciones_funcion> <sentencias> }\n");
	}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 199 "alfa.y" /* yacc.c:1646  */
    {
  	//ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.nombre
	buscar = UsoLocal((yyvsp[-5].atributos).nombre);
	if(buscar == NULL){
		fprintf(stdout, "Error en la declaracion %s, ya declarada d\n", (yyvsp[-5].atributos).nombre);
		return -1;
	}
 	buscar->adicional1 = num_parametros_actual;
 	strcpy((yyval.atributos).nombre, (yyvsp[-5].atributos).nombre);
 	(yyval.atributos).tipo = (yyvsp[-5].atributos).tipo;
 	//GENERACION DE CODIGO
 	declararFuncion(out, (yyvsp[-5].atributos).nombre, num_variables_locales_actual);	
}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 216 "alfa.y" /* yacc.c:1646  */
    {
		//COMPROBACIONES SEMANTICAS
		hay_return = 0;
		es_funcion = 1;
		buscar = UsoLocal((yyvsp[0].atributos).nombre);
		if(buscar != NULL) {
			fprintf(stdout, "****Error semantico en lin %d : Declaracion duplicada.\n", linea);
			return -1;
		}

		simbolo.lexema = (yyvsp[0].atributos).nombre;
		simbolo.categoria = FUNCION;
		simbolo.clase = ESCALAR;
		simbolo.tipo = tipo_actual;
		(yyval.atributos).tipo = tipo_actual;
		strcpy((yyval.atributos).nombre, (yyvsp[0].atributos).nombre);

		//ABRIR AMBITO EN LA TABLA DE SIMBOLOS CON IDENTIFICADOR $3.nombre
		DeclararFuncion((yyvsp[0].atributos).nombre, &simbolo); /*POR QUE*/ 

		//RESETEAR VARIABLES QUE NECESITAMOS PARA PROCESAR LA FUNCION:
		//posicion_variable_local, num_variables_locales, posicion_parametro, num_parametros
		pos_variable_local_actual = 0;
		num_variables_locales_actual=0;
		num_parametros_actual = 0;
		pos_parametro_actual = 0;
	}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 245 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
	}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 247 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R24:\t<parametros_funcion> :=\n");
}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 252 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");
	}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 254 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R26:\t<resto_parametros_funcion> ::=\n");
	}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 258 "alfa.y" /* yacc.c:1646  */
    {
	//INCREMENTAR CONTADORES, POR EJEMPLO
	num_parametros_actual++;
	pos_parametro_actual++;
	fprintf(out, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 265 "alfa.y" /* yacc.c:1646  */
    {
    //COMPROBACIONES SEMANTICAS PARA $1.nombre
    //EN ESTE CASO SE MUESTRA ERROR SI EL NOMBRE DEL PARAMETRO YA SE HA UTILIZADO
	buscar = UsoLocal((yyvsp[0].atributos).nombre);
	if(buscar != NULL){
		fprintf(stdout, "Error, parametro ya utilizado en la linea %d\n", linea);
		return -1;
	}
    simbolo.lexema = (yyvsp[0].atributos).nombre;
    simbolo.categoria = PARAMETRO;
    simbolo.tipo = tipo_actual;
    simbolo.clase = ESCALAR;
    simbolo.adicional1 = num_parametros_actual;

    //DECLARAR SIMBOLO EN LA TABLA
	Declarar((yyvsp[0].atributos).nombre, &simbolo);
}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 284 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
	}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 286 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out, ";R29:\t<declaraciones_funcion> ::=\n");
	}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 291 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R30:\t<sentencias> ::= <sentencia>\n");
	}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 292 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");
}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 297 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");
	}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 299 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out, ";R33:\t<sentencia> ::= <bloque>\n");
	}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 304 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out, ";R34:\t<sentencia_simple> ::= <asignacion>\n");
	}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 306 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out, ";R35:\t<sentencia_simple> ::= <lectura>\n");
	}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 308 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out, ";R36:\t<sentencia_simple> ::= <escritura>\n");
	}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 310 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");
	}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 315 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out, ";R40:\t<bloque> ::= <condicional>\n");}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 317 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out, ";R41:\t<bloque> ::= <bucle>\n");
	}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 322 "alfa.y" /* yacc.c:1646  */
    {
		buscar = UsoLocal((yyvsp[-2].atributos).nombre);
		if(buscar==NULL) {
			fprintf(stdout, "***Error semantico en lin %d: Acceso a variable no declarada (%s).\n", linea, (yyvsp[-2].atributos).nombre);
			return -1;
		}
		if(buscar->categoria == FUNCION) {
			fprintf(stdout, "***Error semantico en lin %d: Asignacion incompatible.\n", linea);
			return -1;
		}
		if(buscar->clase == VECTOR) {
			fprintf(stdout, "***Error semantico en lin %d: Asignacion incompatible.\n", linea);
			return -1;
		}
		if(buscar->tipo != (yyvsp[0].atributos).tipo) {
			fprintf(stdout, "***Error semantico en lin %d: Asignacion incompatible.\n", linea);
			return -1;
		}
		if (UsoGlobal((yyvsp[-2].atributos).nombre) == NULL) {
		/* Estamos en una funcion y la variable es local */
			if(buscar->categoria == PARAMETRO) {
			// REVISAR
				escribirParametro(out, buscar->adicional1, num_parametros_actual);
			} else {
				escribirParametro(out, buscar->adicional1, 0);
			}
		}
		else{
			asignar(out, (yyvsp[-2].atributos).nombre, 0);
			fprintf(out, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
		}
	}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 353 "alfa.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2].atributos).tipo != (yyvsp[0].atributos).tipo){
			fprintf(stdout, "***Error semantico en lin %d: Asignacion incompatible.\n", linea);
			return -1;
		}
 		asignarDestinoEnPila(out, (yyvsp[0].atributos).es_direccion);
		fprintf(out, ";R44 :\t<asignacion> ::= <elemento_vector> = <exp>\n");
	}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 363 "alfa.y" /* yacc.c:1646  */
    {
		//COMPROBACIONES SEMANTICAS PARA EL SIMBOLO CON IDENTIFICADOR $1.nombre
 		//NECESITAMOS EN $$: tipo, es_variable = 1, valor de $3 (ES EL INDICE DEL VECTOR)
  		buscar = UsoLocal((yyvsp[-3].atributos).nombre);
		if(buscar == NULL) {
			fprintf(stdout, "***Error semantico en lin %d: Acceso a variable no declarada (%s).\n", linea, (yyvsp[-3].atributos).nombre);
			return -1;
		}  
		if(buscar->categoria == FUNCION) { /***REVISAR*/
			fprintf(stdout,"***Error semantico en lin %d: Identificador no valido\n", linea);
			return -1;  
		}  
		if(buscar->clase == ESCALAR) {
			fprintf(stdout, "***Error semantico en lin %d: Intento de indexacion de una variable que no es de tipo vector.\n", linea);
			return -1;
		}
		(yyval.atributos).tipo = buscar->tipo;  
		(yyval.atributos).es_direccion = 1;
		if((yyvsp[-1].atributos).tipo != ENTERO) {
			fprintf(stdout, "***Error semantico en lin %d: El indice en una operacion de indexacion tiene que ser de tipo entero.\n", linea);
			return -1;
		}
		escribir_elemento_vector(out, (yyvsp[-3].atributos).nombre, buscar->adicional1, (yyvsp[-1].atributos).es_direccion);

		fprintf(out, ";R48 :\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
	}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 391 "alfa.y" /* yacc.c:1646  */
    {
		ifthenelse_fin(out, (yyvsp[-1].atributos).etiqueta);
		fprintf(out, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
	}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 394 "alfa.y" /* yacc.c:1646  */
    {
		ifthenelse_fin(out, (yyvsp[-5].atributos).etiqueta);
		fprintf(out, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 399 "alfa.y" /* yacc.c:1646  */
    {
 	 //COMPROBACIONES SEMANTICAS
	if((yyvsp[-2].atributos).tipo != BOOLEANO){
		fprintf(stdout, "Error semántico, tipos no compatibles\n");
		return -1;
	}
 	//GESTION ETIQUETA
	(yyval.atributos).etiqueta =  num_If++;
 	ifthenelse_inicio(out, (yyvsp[-2].atributos).es_direccion, (yyval.atributos).etiqueta);
}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 410 "alfa.y" /* yacc.c:1646  */
    {
  (yyval.atributos).etiqueta = (yyvsp[-1].atributos).etiqueta;
  ifthenelse_fin_then(out, (yyval.atributos).etiqueta);
}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 416 "alfa.y" /* yacc.c:1646  */
    {
		while_fin(out, (yyvsp[-2].atributos).etiqueta);
		fprintf(out,";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
	}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 422 "alfa.y" /* yacc.c:1646  */
    {
		(yyval.atributos).etiqueta = num_bucles++;
		while_inicio(out, (yyval.atributos).etiqueta);
	}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 428 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].atributos).tipo != BOOLEANO) {
			fprintf(stdout, "****Error semantico en lin %d: Bucle con condicion de tipo int.\n", linea);
			return -1;
  	}

  (yyval.atributos).etiqueta = (yyvsp[-3].atributos).etiqueta;
  while_exp_pila(out, (yyvsp[-2].atributos).es_direccion, (yyval.atributos).etiqueta);
}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 439 "alfa.y" /* yacc.c:1646  */
    {
		buscar = UsoLocal((yyvsp[0].atributos).nombre);
		if(buscar == NULL) {
			fprintf(stdout, "****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", linea, (yyvsp[0].atributos).nombre);
			return -1;
		}
		leer(out, (yyvsp[0].atributos).nombre, buscar->tipo); 
		fprintf(out, ";R54:\t<lectura> ::= scanf <identificador>\n");
	}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 450 "alfa.y" /* yacc.c:1646  */
    {
		escribir(out, ((yyvsp[0].atributos).es_direccion), ((yyvsp[0].atributos).tipo));
		fprintf(out,";R56:\t<escritura> ::= printf <exp>\n");
	}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 456 "alfa.y" /* yacc.c:1646  */
    {
		if(!es_funcion){
			fprintf(stdout, "Error en la linea, escribiendo retorno fuera de una función d\n");
			return -1;
		}
		hay_return = 1;
		retornarFuncion(out, (yyvsp[0].atributos).es_direccion);/*NO SE QUE PONER EN LA SEGUNDA, COMO SE SI ES VAR O NO*/
		fprintf(out,";R61:\t<retorno_funcion> ::= return <exp>\n");
	}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 467 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].atributos).tipo!=ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
			return -1;
		}
		sumar(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
		(yyval.atributos).es_direccion = 0;
		(yyval.atributos).tipo = ENTERO;
		fprintf(out,";R72:\t<exp> ::= <exp> + <exp>\n");
	}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 476 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].atributos).tipo!=ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d : Operacion aritmetica con operandos boolean.\n", linea);
			return -1;
		}
		(yyval.atributos).tipo = ENTERO;
		restar(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
		(yyval.atributos).es_direccion = 0;
		fprintf(out,";R73:\t<exp> ::= <exp> - <exp>\n");
	}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 485 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].atributos).tipo!=ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d : Operacion aritmetica con operandos boolean.\n", linea);
			return -1;
		}
		(yyval.atributos).tipo = ENTERO;
		dividir(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
		(yyval.atributos).es_direccion = 0;
		fprintf(out,";R74:\t<exp> ::= <exp> / <exp>\n");
	}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 494 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].atributos).tipo!=ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d : Operacion aritmetica con operandos boolean.\n", linea);
			return -1;
		}
		(yyval.atributos).tipo = ENTERO;
		multiplicar(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
		(yyval.atributos).es_direccion = 0;
		fprintf(out,";R75:\t<exp> ::= <exp> * <exp>\n");
	}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 503 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[0].atributos).tipo!=ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d : Operacion aritmetica con operandos boolean.\n", linea);
			return -1; 
		}
		(yyval.atributos).tipo = ENTERO;
		cambiar_signo(out, (yyvsp[0].atributos).es_direccion);
		(yyval.atributos).es_direccion = 0;
		fprintf(out,";R76:\t<exp> ::= - <exp>\n");
	}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 512 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].atributos).tipo!=BOOLEANO || (yyvsp[0].atributos).tipo != BOOLEANO) {
			fprintf(stdout, "****Error semantico en lin %d : Operacion logica con operandos int.\n", linea);
			return -1;
		}
		(yyval.atributos).tipo = BOOLEANO;
		y(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
		(yyval.atributos).es_direccion = 0;
		fprintf(out,";R77:\t<exp> ::= <exp> && <exp>\n");
	}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 521 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].atributos).tipo!=BOOLEANO || (yyvsp[0].atributos).tipo != BOOLEANO) {
			fprintf(stdout, "****Error semantico en lin %d : Operacion logica con operandos int.\n", linea);
			return -1;
		}
		(yyval.atributos).tipo = BOOLEANO;
		o(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
		(yyval.atributos).es_direccion = 0;
		fprintf(out,";R78:\t<exp> ::= <exp> || <exp>\n");
	}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 530 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[0].atributos).tipo!=BOOLEANO) {
			fprintf(stdout, "****Error semantico en lin %d : Operacion logica con operandos int.\n", linea);
			return -1;
		}
		(yyval.atributos).tipo = BOOLEANO;
		no(out, (yyvsp[0].atributos).es_direccion, num_no++);
		(yyval.atributos).es_direccion = 0;
		fprintf(out,";R79:\t<exp> ::= ! <exp>\n");
	}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 539 "alfa.y" /* yacc.c:1646  */
    {
		strcpy((yyval.atributos).nombre, (yyvsp[0].atributos).nombre);
    	buscar = UsoLocal((yyvsp[0].atributos).nombre);
		if(buscar == NULL) {
			fprintf(stdout, "***Error semantico en lin %d : Acceso a variable no declarada (%s).\n", linea, (yyvsp[0].atributos).nombre);
			return -1;
		}
		if (UsoGlobal((yyvsp[0].atributos).nombre) == NULL) {
		/* Estamos en una funcion y la variable es local */
			if(buscar->categoria == PARAMETRO) {
				escribirVariableLocal(out, (num_parametros_actual-buscar->adicional1)+1);
			} else {
				escribirVariableLocal(out, -(buscar->adicional1+1));
			}

		} else {
			if(buscar->categoria==FUNCION) {
				/* NUNCA SUCEDE */
				fprintf(stdout,"Identificador no valido\n");
				return -1;
			}
			escribir_operando(out, (yyvsp[0].atributos).nombre, 1);

		}
		(yyval.atributos).es_direccion = 1;
		(yyval.atributos).tipo = buscar->tipo;
		fprintf(out, ";R80:\t<exp> ::= <identificador>\n");
	}
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 566 "alfa.y" /* yacc.c:1646  */
    {
		(yyval.atributos).tipo =(yyvsp[0].atributos).tipo;
		(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
		escribir_operando(out, (yyvsp[0].atributos).nombre, 0);
		fprintf(out,";R81:\t<exp> ::= <constante>\n");
	}
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 571 "alfa.y" /* yacc.c:1646  */
    {
		(yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
    	(yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
		fprintf(out,";R82:\t<exp> ::= ( <exp> )\n");
	}
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 575 "alfa.y" /* yacc.c:1646  */
    {
		(yyval.atributos).tipo =BOOLEANO;
		(yyval.atributos).es_direccion = 0;
		fprintf(out,";R83:\t<exp> ::= ( <comparacion> )\n");
	}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 579 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out,";R85:\t<exp> ::= <elemento_vector>\n");

	}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 582 "alfa.y" /* yacc.c:1646  */
    {
		buscar = UsoLocal((yyvsp[-2].atributos).nombre);
		if(buscar == NULL) {
			fprintf(stdout, "***Error semantico en lin %d : Funcion no declarada (%s).\n", linea, (yyvsp[-2].atributos).nombre);
			return -1;
		}
		if(buscar->categoria != FUNCION){
			fprintf(stdout, "***Error semantico en lin %d : El identificador no es una funcion (%s).\n", linea, (yyvsp[-2].atributos).nombre);
			return -1;
		}
		if(buscar->adicional1 != params) {
			fprintf(stdout, "***Error semantico en lin %d : Numero incorrecto de parametros en llamada a funcion.\n", linea);
			return -1;
		}
		es_llamada = 0;
		(yyval.atributos).tipo = buscar->tipo;
		llamarFuncion(out, (yyvsp[-2].atributos).nombre, buscar->adicional1);
		fprintf(out,";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");
	}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 603 "alfa.y" /* yacc.c:1646  */
    {
	if(es_llamada) {
		fprintf(stdout, "****Error semantico en lin %d: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", linea);
		return -1;
	}
	es_llamada = 1;
	params = 0;
	strcpy((yyval.atributos).nombre, (yyvsp[-1].atributos).nombre);
	}
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 614 "alfa.y" /* yacc.c:1646  */
    {
		es_llamada = 0;
		params++;
		
		fprintf(out, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
	}
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 619 "alfa.y" /* yacc.c:1646  */
    {
		es_llamada = 0;
		fprintf(out, ";R90:\t<lista_expresiones> ::=\n");
	}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 625 "alfa.y" /* yacc.c:1646  */
    {
  		params++;
  		fprintf(out, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 628 "alfa.y" /* yacc.c:1646  */
    {
	fprintf(out, ";R92:\t<resto_lista_expresiones> ::=\n");
}
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 632 "alfa.y" /* yacc.c:1646  */
    {
  if((yyvsp[0].atributos).es_direccion) {
    operandoEnPilaAArgumento(out, (yyvsp[0].atributos).es_direccion);
  }
}
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 639 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
			return -1;
		}
		igual(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, num_comparaciones++);
		fprintf(out,";R93:\t<comparacion> ::= <exp> == <exp>\n");
	}
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 646 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
			return -1;
		}
		distinto(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, num_comparaciones++);
		fprintf(out,";R94:\t<comparacion> ::= <exp> != <exp>\n");
	}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 653 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
			return -1;
		}
		menor_igual(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, num_comparaciones++);
		fprintf(out,";R95:\t<comparacion> ::= <exp> <= <exp>\n");
	}
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 660 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
			return -1;
		}
		mayor_igual(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, num_comparaciones++);
		fprintf(out,";R96:\t<comparacion> ::= <exp> >= <exp>\n");
	}
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 667 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
			return -1;
		}
		menor(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, num_comparaciones++);
		fprintf(out,";R97:\t<comparacion> ::= <exp> < <exp>\n");
	}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 674 "alfa.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
			return -1;
		}
		mayor(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, num_comparaciones++);
		fprintf(out,";R98:\t<comparacion> ::= <exp> > <exp>\n");
	}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 684 "alfa.y" /* yacc.c:1646  */
    {
		(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
		(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
		strcpy((yyval.atributos).nombre, (yyvsp[0].atributos).nombre);
		fprintf(out,";R99:\t<constante> ::= <constante_logica>\n");
	}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 689 "alfa.y" /* yacc.c:1646  */
    {
		(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
		(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
		strcpy((yyval.atributos).nombre, (yyvsp[0].atributos).nombre);
		fprintf(out,";R100:\t<constante> ::= <constante_entera>\n");
	}
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 697 "alfa.y" /* yacc.c:1646  */
    {
		(yyval.atributos).tipo = BOOLEANO;
		(yyval.atributos).es_direccion = 0;
		strcpy((yyval.atributos).nombre,"1");
		fprintf(out,";R102:\t<constante_logica> ::= true\n");
	}
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 702 "alfa.y" /* yacc.c:1646  */
    {
		(yyval.atributos).tipo = BOOLEANO;
		(yyval.atributos).es_direccion = 0;
		strcpy((yyval.atributos).nombre,"1");
		fprintf(out,";R103:\t<constante_logica> ::= false\n");
}
#line 2383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 710 "alfa.y" /* yacc.c:1646  */
    {
		(yyval.atributos).tipo = ENTERO;
		(yyval.atributos).es_direccion = 0;
		fprintf(out,";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
	}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 717 "alfa.y" /* yacc.c:1646  */
    {
		buscar = UsoLocal((yyvsp[0].atributos).nombre);
		if(buscar != NULL && EsLocal((yyvsp[0].atributos).nombre)) {
			fprintf(stdout, "***Error semantico en lin %d: Declaracion duplicada.\n", linea);
			return -1;
		}
		simbolo.lexema = (yyvsp[0].atributos).nombre;
		simbolo.categoria = VARIABLE;
		simbolo.clase = clase_actual;
		simbolo.tipo = tipo_actual;
    	if(clase_actual == VECTOR) {
    	  simbolo.adicional1 = tamVector;

    	}
		else {
			simbolo.adicional1 = 1;
		}
    	if(es_funcion) {
      		if(clase_actual == VECTOR) {
        		fprintf(stdout, "***Error semantico en lin %d : Variable local de tipo no escalar.\n", linea);
        		return -1;
      		}
			simbolo.adicional1 = num_variables_locales_actual;
			num_variables_locales_actual++;
			pos_variable_local_actual++;
    	}
		else {
      		declarar_variable(out, (yyvsp[0].atributos).nombre, tipo_actual,  simbolo.adicional1);
        }
    	Declarar((yyvsp[0].atributos).nombre, &simbolo);

		fprintf(out,";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
	}
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 752 "alfa.y" /* yacc.c:1646  */
    { 
	escribir_segmento_codigo(out); 
	}
#line 2439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 757 "alfa.y" /* yacc.c:1646  */
    { 
	escribir_inicio_main(out);
	}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2451 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 761 "alfa.y" /* yacc.c:1906  */

void yyerror (char const *cad)
{
	if(flagError == 0)
		fprintf(stdout,"*** Error sintáctico en [lin %d, col %d]\n",linea,columna);
	flagError = 0;
}
