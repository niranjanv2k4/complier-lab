/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "compiler.y"

    
    #include "main.h"

    #include "./Conditionals/jump.h"
    #include "./ExecGen/exec.h"
    #include "./TreeGen/tree.h"
    #include "./symbolTable/symbol.h"
    #include "./typeTable/type.h"

    int yyerror();
    int yylex();

    FILE *output;

    struct GSymbol* GST = NULL;
    struct param* paramlist = NULL;
    struct LSymbol* LST = NULL;
    struct Typetable* current_type;


#line 92 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    ADD = 258,
    SUB = 259,
    STAR = 260,
    DIV = 261,
    MOD = 262,
    T_BEGIN = 263,
    T_END = 264,
    READ = 265,
    WRITE = 266,
    ASSGN = 267,
    EOL = 268,
    IF = 269,
    THEN = 270,
    ELSE = 271,
    ENDIF = 272,
    GE = 273,
    LE = 274,
    EQ = 275,
    GT = 276,
    LT = 277,
    NE = 278,
    WHILE = 279,
    DO = 280,
    END_WHILE = 281,
    BREAK = 282,
    CONTINUE = 283,
    REPEAT = 284,
    UNTILL = 285,
    DECL = 286,
    ENDDECL = 287,
    INT = 288,
    STR = 289,
    TUPLE = 290,
    MAIN = 291,
    RETURN = 292,
    NUM = 293,
    ID = 294,
    STR_LITERAL = 295,
    OR = 296,
    AND = 297
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define STAR 260
#define DIV 261
#define MOD 262
#define T_BEGIN 263
#define T_END 264
#define READ 265
#define WRITE 266
#define ASSGN 267
#define EOL 268
#define IF 269
#define THEN 270
#define ELSE 271
#define ENDIF 272
#define GE 273
#define LE 274
#define EQ 275
#define GT 276
#define LT 277
#define NE 278
#define WHILE 279
#define DO 280
#define END_WHILE 281
#define BREAK 282
#define CONTINUE 283
#define REPEAT 284
#define UNTILL 285
#define DECL 286
#define ENDDECL 287
#define INT 288
#define STR 289
#define TUPLE 290
#define MAIN 291
#define RETURN 292
#define NUM 293
#define ID 294
#define STR_LITERAL 295
#define OR 296
#define AND 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "compiler.y"

    struct ASTNode* node;
    struct param* parameter;
    struct LSymbol* localSymbolTable;
    struct Arglist* Args;
    int type;

#line 236 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   618

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

#define YYUNDEFTOK  2
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,     2,
      45,    46,     2,     2,    47,     2,    43,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    71,    72,    73,    76,    77,    79,    80,
      81,    83,    84,    85,    87,    88,    90,    91,    92,    93,
      97,    98,   100,   106,   116,   127,   128,   129,   132,   133,
     134,   135,   140,   141,   142,   144,   145,   147,   149,   150,
     151,   152,   157,   159,   163,   164,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   176,   178,   180,   183,   184,
     186,   188,   190,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     213,   215,   216,   217,   220,   221,   222,   223,   224,   225
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "STAR", "DIV", "MOD",
  "T_BEGIN", "T_END", "READ", "WRITE", "ASSGN", "EOL", "IF", "THEN",
  "ELSE", "ENDIF", "GE", "LE", "EQ", "GT", "LT", "NE", "WHILE", "DO",
  "END_WHILE", "BREAK", "CONTINUE", "REPEAT", "UNTILL", "DECL", "ENDDECL",
  "INT", "STR", "TUPLE", "MAIN", "RETURN", "NUM", "ID", "STR_LITERAL",
  "OR", "AND", "'.'", "'&'", "'('", "')'", "','", "'['", "']'", "'{'",
  "'}'", "$accept", "program", "GDeclBlock", "GDeclList", "GDecl", "Type",
  "GidList", "Gid", "FDefBlock", "Fdef", "MainBlock", "ParamList", "Param",
  "LDeclBlock", "LDeclList", "LDecl", "IdList", "Coderegion", "RtnStmt",
  "Slist", "Stmt", "InputStmt", "OutputStmt", "AsgnStmt", "IfStmt",
  "WhileStmt", "RptUntlStmt", "DoWhileStmt", "expr", "ArgList",
  "IDENTIFIERS", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    46,    38,    40,    41,    44,    91,    93,
     123,   125
};
# endif

#define YYPACT_NINF (-96)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      84,    68,   -10,   -35,    11,    71,    71,   -96,   -96,   -96,
     -96,   -96,    10,    78,   -96,    -3,    17,    28,    35,   -96,
      71,   -96,   -96,   -96,    69,   -96,   -96,    82,    30,    -8,
     -96,    79,   100,   100,   -96,   100,   -96,   100,    92,   -96,
      -3,    94,     1,     2,    91,   -96,   106,   112,   124,   107,
     -96,   110,   115,   -96,   137,   -96,   132,   100,   134,   -96,
     -96,   -96,   116,   175,   -96,   -96,   110,   -96,   110,   -96,
       4,   133,   -96,   477,   135,   175,   175,   146,   -96,    -1,
     -96,   -96,   148,   143,   145,   147,   162,   141,   180,   195,
     159,   -40,   171,    32,   389,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   211,   -96,   173,   174,   -96,   -96,     5,
     -96,    20,    32,    32,    32,   477,   -96,   -96,   477,   187,
      32,   -96,   -96,   -21,   -96,    32,   193,   -96,    32,   218,
     -96,    32,   -96,   -96,   189,   -96,   183,   199,   243,   249,
     118,   150,   -96,    12,    32,   293,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,   188,
     505,   -96,   530,   -96,   217,   219,   221,   208,   213,   212,
     -96,   555,   126,   188,    50,    50,   -96,   -96,   -96,   586,
     586,   586,   586,   586,   586,   561,   595,   204,   -96,   -96,
     -96,   -96,   477,   477,   206,   214,   -96,    32,   -96,   363,
     425,    32,    32,   555,   477,   225,   231,   299,   343,   451,
     -96,   -96,   244,   245,   247,   -96,   -96,   -96
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    21,     5,     7,
      11,    12,     0,     0,     9,     0,     0,     0,     0,     1,
       0,     4,    20,     3,     0,     6,     8,     0,    16,     0,
      15,     0,    27,    27,     2,    27,    19,    27,     0,    10,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
      14,    33,     0,    28,     0,    29,     0,     0,     0,    13,
      18,    17,     0,     0,    30,    31,    33,    25,    33,    34,
       0,     0,    36,     0,     0,     0,     0,     0,    39,     0,
      32,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,    45,    46,    47,    48,    49,
      50,    53,    54,     0,    24,     0,     0,    41,    37,     0,
      86,     0,     0,     0,     0,     0,    51,    52,     0,     0,
       0,    87,    77,    84,    78,     0,     0,    80,     0,     0,
      44,     0,    22,    23,     0,    38,     0,     0,     0,     0,
       0,     0,    89,     0,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,    40,     0,     0,     0,     0,     0,     0,
      85,    82,     0,    76,    63,    64,    65,    66,    67,    71,
      73,    68,    70,    72,    69,    74,    75,     0,    43,    57,
      55,    56,     0,     0,     0,     0,    79,     0,    88,     0,
       0,     0,     0,    81,     0,     0,     0,     0,     0,     0,
      59,    60,     0,     0,     0,    62,    61,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -96,   -96,   -96,   -96,   260,    37,   -96,   234,   270,    54,
       8,    46,   220,    56,   -96,   205,   -96,   105,   -96,   -95,
     -93,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -62,   -96,
     -73
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    13,    14,    15,    29,    30,     6,     7,
       8,    44,    45,    63,    71,    72,    79,    74,   129,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   126,   172,
     127
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     103,   130,    27,   119,    18,    39,    52,    54,   120,    77,
     134,    19,   108,    21,    23,   146,   147,   148,   149,   150,
     140,   103,   119,   141,   144,    82,    16,   120,    34,    17,
     151,   152,   153,   154,   155,   156,    28,    82,   136,    40,
      53,    55,   103,    78,   135,   103,   109,   130,   130,    24,
     137,   138,   139,   157,   158,   148,   149,   150,   143,    91,
      22,   170,    31,   145,    92,    93,   160,   103,   103,   162,
     122,   123,   124,    32,    22,    37,    92,   125,    38,    46,
      33,    47,   171,    48,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   199,   200,    70,
       9,    10,    11,    12,     2,     3,   130,   130,    70,   209,
      25,    10,    11,    12,    35,     1,   130,     2,     3,   103,
     103,    36,    75,    82,    76,    41,   103,   103,    83,    84,
      49,   103,    85,    42,    43,   203,   103,    56,    57,   207,
     208,    62,    86,    87,    51,    88,    89,    90,    69,    10,
      11,    12,    58,    57,    64,    82,    61,    91,    59,    57,
      83,    84,    92,    93,    85,    80,    10,    11,    12,   168,
      60,    57,   196,   197,    86,    87,    65,    88,    89,    90,
     105,   106,    66,    73,    68,   107,   104,   110,   111,    91,
     112,   115,   113,   116,    92,    93,   146,   147,   148,   149,
     150,   169,   146,   147,   148,   149,   150,   114,   117,   118,
     121,   151,   152,   153,   154,   155,   156,   151,   152,   153,
     154,   155,   156,   131,   132,   133,   142,   161,   163,   164,
     190,   187,   191,   193,   157,   158,   192,   194,   210,   159,
     157,   158,   195,   198,   211,   165,   146,   147,   148,   149,
     150,   201,   146,   147,   148,   149,   150,   215,   216,   202,
     217,   151,   152,   153,   154,   155,   156,   151,   152,   153,
     154,   155,   156,    26,    50,    20,    81,    67,     0,     0,
       0,     0,     0,     0,   157,   158,     0,     0,     0,   166,
     157,   158,     0,     0,     0,   167,   146,   147,   148,   149,
     150,     0,   146,   147,   148,   149,   150,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   156,   151,   152,   153,
     154,   155,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   158,     0,     0,     0,   173,
     157,   158,     0,     0,     0,   212,   146,   147,   148,   149,
     150,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   156,     0,    82,     0,
       0,     0,     0,    83,    84,     0,     0,    85,     0,   204,
     205,     0,     0,     0,   157,   158,     0,    86,    87,   213,
      88,    89,    90,     0,    82,     0,     0,     0,     0,    83,
      84,     0,    91,    85,     0,     0,     0,    92,    93,     0,
       0,     0,     0,    86,    87,     0,    88,    89,    90,     0,
       0,     0,     0,     0,     0,     0,   128,     0,    91,     0,
      82,     0,     0,    92,    93,    83,    84,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,   206,    88,    89,    90,     0,    82,     0,     0,     0,
       0,    83,    84,     0,    91,    85,     0,     0,   214,    92,
      93,     0,     0,     0,     0,    86,    87,     0,    88,    89,
      90,     0,    82,     0,     0,     0,     0,    83,    84,     0,
      91,    85,     0,     0,     0,    92,    93,     0,     0,     0,
       0,    86,    87,     0,    88,    89,    90,     0,   146,   147,
     148,   149,   150,     0,     0,     0,    91,     0,   188,     0,
       0,    92,    93,   151,   152,   153,   154,   155,   156,     0,
       0,     0,     0,   146,   147,   148,   149,   150,     0,     0,
       0,     0,     0,   189,     0,     0,   157,   158,   151,   152,
     153,   154,   155,   156,     0,     0,     0,     0,   146,   147,
     148,   149,   150,     0,   146,   147,   148,   149,   150,     0,
       0,   157,   158,   151,   152,   153,   154,   155,   156,   151,
     152,   153,   154,   155,   156,     0,     0,     0,     0,   146,
     147,   148,   149,   150,     0,     0,   157,   158,   146,   147,
     148,   149,   150,   158,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     0,     0,   151,   152,   153,   154,   155,   156
};

static const yytype_int16 yycheck[] =
{
      73,    94,     5,    43,    39,    13,     5,     5,    48,     5,
       5,     0,    13,     5,     6,     3,     4,     5,     6,     7,
     115,    94,    43,   118,    45,     5,    36,    48,    20,    39,
      18,    19,    20,    21,    22,    23,    39,     5,   111,    47,
      39,    39,   115,    39,    39,   118,    47,   140,   141,    39,
     112,   113,   114,    41,    42,     5,     6,     7,   120,    39,
       6,    49,    45,   125,    44,    45,   128,   140,   141,   131,
      38,    39,    40,    45,    20,    45,    44,    45,    48,    33,
      45,    35,   144,    37,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   192,   193,    62,
      32,    33,    34,    35,    33,    34,   199,   200,    71,   204,
      32,    33,    34,    35,    45,    31,   209,    33,    34,   192,
     193,    39,    66,     5,    68,    46,   199,   200,    10,    11,
      38,   204,    14,    33,    34,   197,   209,    46,    47,   201,
     202,    31,    24,    25,    50,    27,    28,    29,    32,    33,
      34,    35,    46,    47,    39,     5,    49,    39,    46,    47,
      10,    11,    44,    45,    14,    32,    33,    34,    35,    51,
      46,    47,    46,    47,    24,    25,    39,    27,    28,    29,
      75,    76,    50,     8,    50,    39,    51,    39,    45,    39,
      45,    50,    45,    13,    44,    45,     3,     4,     5,     6,
       7,    51,     3,     4,     5,     6,     7,    45,    13,    50,
      39,    18,    19,    20,    21,    22,    23,    18,    19,    20,
      21,    22,    23,    12,    51,    51,    39,     9,    39,    46,
      13,    43,    13,    25,    41,    42,    15,    24,    13,    46,
      41,    42,    30,    39,    13,    46,     3,     4,     5,     6,
       7,    45,     3,     4,     5,     6,     7,    13,    13,    45,
      13,    18,    19,    20,    21,    22,    23,    18,    19,    20,
      21,    22,    23,    13,    40,     5,    71,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    46,
      41,    42,    -1,    -1,    -1,    46,     3,     4,     5,     6,
       7,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    46,
      41,    42,    -1,    -1,    -1,    46,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    -1,     5,    -1,
      -1,    -1,    -1,    10,    11,    -1,    -1,    14,    -1,    16,
      17,    -1,    -1,    -1,    41,    42,    -1,    24,    25,    46,
      27,    28,    29,    -1,     5,    -1,    -1,    -1,    -1,    10,
      11,    -1,    39,    14,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    24,    25,    -1,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,
       5,    -1,    -1,    44,    45,    10,    11,    -1,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    -1,     5,    -1,    -1,    -1,
      -1,    10,    11,    -1,    39,    14,    -1,    -1,    17,    44,
      45,    -1,    -1,    -1,    -1,    24,    25,    -1,    27,    28,
      29,    -1,     5,    -1,    -1,    -1,    -1,    10,    11,    -1,
      39,    14,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    24,    25,    -1,    27,    28,    29,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    39,    -1,    13,    -1,
      -1,    44,    45,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    41,    42,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    41,    42,    18,    19,    20,    21,    22,    23,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    41,    42,     3,     4,
       5,     6,     7,    42,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    33,    34,    53,    54,    60,    61,    62,    32,
      33,    34,    35,    55,    56,    57,    36,    39,    39,     0,
      60,    62,    61,    62,    39,    32,    56,     5,    39,    58,
      59,    45,    45,    45,    62,    45,    39,    45,    48,    13,
      47,    46,    33,    34,    63,    64,    63,    63,    63,    38,
      59,    50,     5,    39,     5,    39,    46,    47,    46,    46,
      46,    49,    31,    65,    39,    39,    50,    64,    50,    32,
      57,    66,    67,     8,    69,    65,    65,     5,    39,    68,
      32,    67,     5,    10,    11,    14,    24,    25,    27,    28,
      29,    39,    44,    45,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    82,    51,    69,    69,    39,    13,    47,
      39,    45,    45,    45,    45,    50,    13,    13,    50,    43,
      48,    39,    38,    39,    40,    45,    80,    82,    37,    70,
      72,    12,    51,    51,     5,    39,    82,    80,    80,    80,
      71,    71,    39,    80,    45,    80,     3,     4,     5,     6,
       7,    18,    19,    20,    21,    22,    23,    41,    42,    46,
      80,     9,    80,    39,    46,    46,    46,    46,    51,    51,
      49,    80,    81,    46,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    43,    13,    13,
      13,    13,    15,    25,    24,    30,    46,    47,    39,    71,
      71,    45,    45,    80,    16,    17,    26,    80,    80,    71,
      13,    13,    46,    46,    17,    13,    13,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    54,    54,    55,    55,
      56,    57,    57,    57,    58,    58,    59,    59,    59,    59,
      60,    60,    61,    61,    62,    63,    63,    63,    64,    64,
      64,    64,    65,    65,    65,    66,    66,    67,    68,    68,
      68,    68,    69,    70,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    74,    75,    76,    76,
      77,    78,    79,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    82,    82,    82,    82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     3,     2,     2,     1,
       3,     1,     1,     5,     3,     1,     1,     4,     4,     2,
       2,     1,     9,     9,     8,     3,     1,     0,     2,     2,
       3,     3,     3,     0,     2,     2,     1,     3,     3,     1,
       4,     2,     4,     3,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     5,     5,     4,    10,     8,
       8,     9,     9,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     4,
       1,     3,     1,     0,     1,     4,     2,     2,     5,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 70 "compiler.y"
                                                {   exitProg(output);printGST();  }
#line 1632 "y.tab.c"
    break;

  case 3:
#line 71 "compiler.y"
                                                {   exitProg(output);printGST();  }
#line 1638 "y.tab.c"
    break;

  case 4:
#line 72 "compiler.y"
                                                {   exitProg(output);printGST();  }
#line 1644 "y.tab.c"
    break;

  case 5:
#line 73 "compiler.y"
                                                {   exitProg(output);printGST();  }
#line 1650 "y.tab.c"
    break;

  case 6:
#line 76 "compiler.y"
                                                {   }
#line 1656 "y.tab.c"
    break;

  case 7:
#line 77 "compiler.y"
                                                {   }
#line 1662 "y.tab.c"
    break;

  case 10:
#line 81 "compiler.y"
                                                {   }
#line 1668 "y.tab.c"
    break;

  case 11:
#line 83 "compiler.y"
                                                {   current_type = TLookup("int");    }
#line 1674 "y.tab.c"
    break;

  case 12:
#line 84 "compiler.y"
                                                {   current_type = TLookup("str");    }
#line 1680 "y.tab.c"
    break;

  case 13:
#line 85 "compiler.y"
                                                {   current_type = TInstallTuple((yyvsp[-3].node), (yyvsp[-1].parameter));   }
#line 1686 "y.tab.c"
    break;

  case 16:
#line 90 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[0].node), current_type, 1, 0, 0,NULL, NODE_ID, false);    }
#line 1692 "y.tab.c"
    break;

  case 17:
#line 91 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[-3].node), current_type, (yyvsp[-1].node)->value.intVal, 1, (yyvsp[-1].node)->value.intVal, NULL, NODE_ID, false); }
#line 1698 "y.tab.c"
    break;

  case 18:
#line 92 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[-3].node), current_type, 0, 0, 0, (yyvsp[-1].parameter), NODE_FUNCT,false);    }
#line 1704 "y.tab.c"
    break;

  case 19:
#line 93 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[0].node), current_type, 1, 0, 0, NULL, NODE_ID, true);    }
#line 1710 "y.tab.c"
    break;

  case 20:
#line 97 "compiler.y"
                                                {      }
#line 1716 "y.tab.c"
    break;

  case 21:
#line 98 "compiler.y"
                                                {      }
#line 1722 "y.tab.c"
    break;

  case 22:
#line 100 "compiler.y"
                                                                            {   
                                                                                setHeader(output);  
                                                                                validateFunct(TLookup("int"), (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node)); 
                                                                                printLST((yyvsp[-7].node)->name);
                                                                                generateFunct(output, (yyvsp[-7].node), (yyvsp[-1].node));
                                                                            }
#line 1733 "y.tab.c"
    break;

  case 23:
#line 106 "compiler.y"
                                                                            {   
                                                                                setHeader(output);  
                                                                                validateFunct(TLookup("str"), (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node));    
                                                                                printLST((yyvsp[-7].node)->name);
                                                                                generateFunct(output, (yyvsp[-7].node), (yyvsp[-1].node));
                                                                            }
#line 1744 "y.tab.c"
    break;

  case 24:
#line 116 "compiler.y"
                                                                {   
                                                                    setHeader(output);  
                                                                    validateMain((yyvsp[-1].node));
                                                                    printLST("MAIN");
                                                                    generateFunct(output, NULL, (yyvsp[-1].node));
                                                                    LST = NULL;
                                                                   }
#line 1756 "y.tab.c"
    break;

  case 25:
#line 127 "compiler.y"
                                        {   (yyval.parameter) = appendParam((yyvsp[-2].parameter), (yyvsp[0].parameter)); }
#line 1762 "y.tab.c"
    break;

  case 26:
#line 128 "compiler.y"
                                        {   (yyval.parameter) = (yyvsp[0].parameter); }
#line 1768 "y.tab.c"
    break;

  case 27:
#line 129 "compiler.y"
                                        {   (yyval.parameter) = NULL; }
#line 1774 "y.tab.c"
    break;

  case 28:
#line 132 "compiler.y"
                                        {   (yyval.parameter) = createParam(TLookup("int"), (yyvsp[0].node));   }
#line 1780 "y.tab.c"
    break;

  case 29:
#line 133 "compiler.y"
                                        {   (yyval.parameter) = createParam(TLookup("str"), (yyvsp[0].node));   }
#line 1786 "y.tab.c"
    break;

  case 30:
#line 134 "compiler.y"
                                        {   (yyval.parameter) = createParam(TLookup("int ptr"), (yyvsp[0].node));   }
#line 1792 "y.tab.c"
    break;

  case 31:
#line 135 "compiler.y"
                                        {   (yyval.parameter) = createParam(TLookup("str ptr"), (yyvsp[0].node));   }
#line 1798 "y.tab.c"
    break;

  case 32:
#line 140 "compiler.y"
                                                                {  }
#line 1804 "y.tab.c"
    break;

  case 35:
#line 144 "compiler.y"
                                                                {  }
#line 1810 "y.tab.c"
    break;

  case 36:
#line 145 "compiler.y"
                                                                {  }
#line 1816 "y.tab.c"
    break;

  case 37:
#line 147 "compiler.y"
                                                                {  }
#line 1822 "y.tab.c"
    break;

  case 38:
#line 149 "compiler.y"
                                                                {   LST = createLST((yyvsp[0].node), current_type, false);   }
#line 1828 "y.tab.c"
    break;

  case 39:
#line 150 "compiler.y"
                                                                {   LST = createLST((yyvsp[0].node), current_type, true);   }
#line 1834 "y.tab.c"
    break;

  case 40:
#line 151 "compiler.y"
                                                                {   LST = createLST((yyvsp[0].node), current_type, false);   }
#line 1840 "y.tab.c"
    break;

  case 41:
#line 152 "compiler.y"
                                                                {   LST = createLST((yyvsp[0].node), current_type, true);    }
#line 1846 "y.tab.c"
    break;

  case 42:
#line 157 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_CONNECTOR, (yyvsp[-2].node), (yyvsp[-1].node));    }
#line 1852 "y.tab.c"
    break;

  case 43:
#line 159 "compiler.y"
                                                    {   
                                                        (yyval.node) = createRtnNode((yyvsp[-1].node));
                                                    }
#line 1860 "y.tab.c"
    break;

  case 44:
#line 163 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_CONNECTOR, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1866 "y.tab.c"
    break;

  case 45:
#line 164 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1872 "y.tab.c"
    break;

  case 46:
#line 166 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1878 "y.tab.c"
    break;

  case 47:
#line 167 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1884 "y.tab.c"
    break;

  case 48:
#line 168 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1890 "y.tab.c"
    break;

  case 49:
#line 169 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1896 "y.tab.c"
    break;

  case 50:
#line 170 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1902 "y.tab.c"
    break;

  case 51:
#line 171 "compiler.y"
                                                    {   (yyval.node) = createControlFlowNode(NODE_BREAK); }
#line 1908 "y.tab.c"
    break;

  case 52:
#line 172 "compiler.y"
                                                    {   (yyval.node) = createControlFlowNode(NODE_CONTINUE); }
#line 1914 "y.tab.c"
    break;

  case 53:
#line 173 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1920 "y.tab.c"
    break;

  case 54:
#line 174 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1926 "y.tab.c"
    break;

  case 55:
#line 176 "compiler.y"
                                                        {   (yyval.node) = createTreeNode(NODE_READ, (yyvsp[-2].node), NULL);   }
#line 1932 "y.tab.c"
    break;

  case 56:
#line 178 "compiler.y"
                                                        {   (yyval.node) = createTreeNode(NODE_WRITE, (yyvsp[-2].node), NULL);     }
#line 1938 "y.tab.c"
    break;

  case 57:
#line 180 "compiler.y"
                                                        {   (yyval.node) = createTreeNode(NODE_ASSIGN, (yyvsp[-3].node), (yyvsp[-1].node));    }
#line 1944 "y.tab.c"
    break;

  case 58:
#line 183 "compiler.y"
                                                                 {  (yyval.node) = createIfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));  }
#line 1950 "y.tab.c"
    break;

  case 59:
#line 184 "compiler.y"
                                                                 {  (yyval.node) = createIfNode((yyvsp[-5].node), (yyvsp[-2].node), NULL); }
#line 1956 "y.tab.c"
    break;

  case 60:
#line 186 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_WHILE, (yyvsp[-5].node), (yyvsp[-2].node));   }
#line 1962 "y.tab.c"
    break;

  case 61:
#line 188 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_RPTUTL, (yyvsp[-2].node), (yyvsp[-6].node));   }
#line 1968 "y.tab.c"
    break;

  case 62:
#line 190 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_DOWHILE, (yyvsp[-2].node), (yyvsp[-6].node));   }
#line 1974 "y.tab.c"
    break;

  case 63:
#line 193 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1980 "y.tab.c"
    break;

  case 64:
#line 194 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1986 "y.tab.c"
    break;

  case 65:
#line 195 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1992 "y.tab.c"
    break;

  case 66:
#line 196 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1998 "y.tab.c"
    break;

  case 67:
#line 197 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2004 "y.tab.c"
    break;

  case 68:
#line 198 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_EQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2010 "y.tab.c"
    break;

  case 69:
#line 199 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_NE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2016 "y.tab.c"
    break;

  case 70:
#line 200 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_GT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2022 "y.tab.c"
    break;

  case 71:
#line 201 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_GE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2028 "y.tab.c"
    break;

  case 72:
#line 202 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_LT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2034 "y.tab.c"
    break;

  case 73:
#line 203 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_LE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2040 "y.tab.c"
    break;

  case 74:
#line 204 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2046 "y.tab.c"
    break;

  case 75:
#line 205 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2052 "y.tab.c"
    break;

  case 76:
#line 206 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[-1].node);    }
#line 2058 "y.tab.c"
    break;

  case 77:
#line 207 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2064 "y.tab.c"
    break;

  case 78:
#line 208 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2070 "y.tab.c"
    break;

  case 79:
#line 209 "compiler.y"
                                                    {   
                                                        setType((yyvsp[-3].node));
                                                        (yyval.node) = createFunctNode((yyvsp[-3].node), (yyvsp[-1].node)); 
                                                    }
#line 2079 "y.tab.c"
    break;

  case 80:
#line 213 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2085 "y.tab.c"
    break;

  case 81:
#line 215 "compiler.y"
                                                    {   (yyval.node) = appendArgNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2091 "y.tab.c"
    break;

  case 82:
#line 216 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2097 "y.tab.c"
    break;

  case 83:
#line 217 "compiler.y"
                                                    {   (yyval.node) = NULL;  }
#line 2103 "y.tab.c"
    break;

  case 84:
#line 220 "compiler.y"
                                    { setType((yyvsp[0].node)); (yyval.node) = (yyvsp[0].node); }
#line 2109 "y.tab.c"
    break;

  case 85:
#line 221 "compiler.y"
                                    { (yyval.node) = createArrayNode((yyvsp[-3].node), NULL, (yyvsp[-1].node)); }
#line 2115 "y.tab.c"
    break;

  case 86:
#line 222 "compiler.y"
                                    { (yyval.node) = createDerefNode((yyvsp[0].node)); }
#line 2121 "y.tab.c"
    break;

  case 87:
#line 223 "compiler.y"
                                    { (yyval.node) = createAddrNode((yyvsp[0].node)); }
#line 2127 "y.tab.c"
    break;

  case 88:
#line 224 "compiler.y"
                                       { (yyval.node) = createTupleNode((yyvsp[-3].node), (yyvsp[0].node)); }
#line 2133 "y.tab.c"
    break;

  case 89:
#line 225 "compiler.y"
                           { (yyval.node) = createTupleNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2139 "y.tab.c"
    break;


#line 2143 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 228 "compiler.y"


extern FILE* yyin;

int yyerror(const char* s){
    printf("Error: %s\n", s);
    return 1;
}

int main(int argc, char **argv){

    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("Error opening file\n");
            return 1;
        }
    }
    TypeTableCreate();
    output = fopen("output.xsm", "w");
    yyparse();

    fclose(output);
    return 0;
}
