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

    struct Typetable* ptrType(){
        return current_type == TLookup("int")?TLookup("int ptr"):TLookup("str ptr");
    }


#line 98 "y.tab.c"

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
    MAIN = 290,
    RETURN = 291,
    NUM = 292,
    ID = 293,
    STR_LITERAL = 294,
    OR = 295,
    AND = 296
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
#define MAIN 290
#define RETURN 291
#define NUM 292
#define ID 293
#define STR_LITERAL 294
#define OR 295
#define AND 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "compiler.y"

    struct ASTNode* node;
    struct param* parameter;
    struct LSymbol* localSymbolTable;
    struct Arglist* Args;
    int type;

#line 240 "y.tab.c"

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   520

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


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
       2,     2,     2,     2,     2,     2,     2,     2,    49,     2,
      45,    46,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    80,    84,    88,    94,    95,    97,    98,
      99,   101,   102,   104,   105,   107,   108,   109,   110,   116,
     117,   119,   125,   132,   133,   134,   137,   141,   145,   149,
     157,   168,   169,   170,   172,   173,   175,   177,   178,   179,
     182,   189,   191,   195,   196,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   208,   210,   212,   215,   216,   218,
     220,   222,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   245,
     248,   252,   256,   260,   265,   266,   267
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
  "INT", "STR", "MAIN", "RETURN", "NUM", "ID", "STR_LITERAL", "OR", "AND",
  "','", "'['", "']'", "'('", "')'", "'{'", "'}'", "'&'", "$accept",
  "program", "GDeclBlock", "GDeclList", "GDecl", "GidList", "Type", "Gid",
  "FDefBlock", "Fdef", "ParamList", "Param", "MainBlock", "LDeclBlock",
  "LDeclList", "LDecl", "IdList", "Coderegion", "RtnStmt", "Slist", "Stmt",
  "InputStmt", "OutputStmt", "AsgnStmt", "IfStmt", "WhileStmt",
  "RptUntlStmt", "DoWhileStmt", "expr", "IDENTIFIERS", "ArgList", YY_NULLPTR
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
     295,   296,    44,    91,    93,    40,    41,   123,   125,    38
};
# endif

#define YYPACT_NINF (-108)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      84,    55,    69,   -30,    29,   109,   109,  -108,  -108,  -108,
    -108,  -108,   137,  -108,     1,   -11,    28,    34,  -108,   109,
    -108,  -108,  -108,  -108,  -108,    61,    85,   -10,  -108,     3,
     116,   116,  -108,  -108,    74,   116,  -108,     1,    19,     2,
       4,   -18,  -108,   -15,    77,    21,  -108,   115,    97,  -108,
     102,  -108,   116,   106,   110,  -108,  -108,   146,   156,  -108,
    -108,  -108,   115,   115,  -108,     5,   152,  -108,   197,   112,
     156,   156,   143,  -108,    -9,  -108,  -108,   155,   153,   159,
     160,   164,   168,   206,   207,   176,   167,   191,    98,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,   216,  -108,   182,
     183,  -108,  -108,     9,  -108,    33,    31,    31,    31,   197,
    -108,  -108,   197,    31,  -108,    31,   223,  -108,    31,  -108,
    -108,   195,  -108,   188,  -108,    88,  -108,    31,   236,  -108,
     244,   288,   127,   134,   390,   419,  -108,   443,  -108,   224,
      31,   295,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,   231,   221,   220,   228,   230,
    -108,  -108,  -108,  -108,   467,    44,  -108,   190,   190,  -108,
    -108,  -108,   396,   396,   396,   396,   396,   396,   473,   497,
    -108,   197,   197,   208,   225,    31,  -108,    67,   163,    31,
      31,   467,   197,   248,   255,   339,   346,   189,  -108,  -108,
     256,   258,   259,  -108,  -108,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    20,     5,     7,
      13,    14,     0,     9,     0,     0,     0,     0,     1,     0,
       4,    19,     3,     6,     8,     0,    15,     0,    12,     0,
      25,    25,     2,    18,     0,    25,    10,     0,     0,     0,
       0,     0,    24,     0,     0,     0,    11,    32,     0,    26,
       0,    27,     0,     0,     0,    16,    17,     0,     0,    28,
      29,    23,    32,    32,    33,     0,     0,    35,     0,     0,
       0,     0,     0,    38,     0,    31,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,    44,
      45,    46,    47,    48,    49,    52,    53,     0,    30,     0,
       0,    40,    36,     0,    82,     0,     0,     0,     0,     0,
      50,    51,     0,     0,    83,     0,     0,    43,     0,    21,
      22,     0,    37,     0,    76,    80,    77,     0,     0,    79,
       0,     0,     0,     0,     0,     0,    41,     0,    39,     0,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,    42,    56,    54,    85,     0,    75,    62,    63,    64,
      65,    66,    70,    72,    67,    69,    71,    68,    73,    74,
      55,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,    58,    59,
       0,     0,     0,    61,    60,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,  -108,  -108,   261,  -108,   -44,   237,   270,    11,
      71,   226,     6,   104,  -108,   213,  -108,   -52,  -108,  -107,
     -87,  -108,  -108,  -108,  -108,  -108,  -108,  -108,   -92,   -68,
    -108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    12,    13,    27,    14,    28,     6,     7,
      41,    42,     8,    58,    66,    67,    74,    69,   116,    88,
      89,    90,    91,    92,    93,    94,    95,    96,   128,   129,
     165
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      97,   117,   132,    36,   102,   133,    25,    48,    17,    50,
      72,    20,    22,    65,   121,   130,   131,    21,    99,   100,
      97,   134,    65,   135,    52,    32,   137,    52,    53,    18,
      21,    54,    37,   103,    29,   141,    77,   123,    77,    26,
      49,    97,    51,    73,    97,   117,   117,   122,   164,    38,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,    52,    97,    97,    47,    56,   124,   125,
     126,    86,    77,    30,   187,   188,   127,    78,    79,    31,
      87,    80,    87,   192,   193,   197,   185,     9,    10,    11,
     186,    81,    82,   191,    83,    84,    85,   195,   196,    33,
     117,   117,    43,    77,    15,    86,    45,    16,    78,    79,
     117,    44,    80,    97,    97,     1,    87,     2,     3,    97,
      97,    55,    81,    82,    97,    83,    84,    85,    34,    97,
      35,   113,    77,   140,   115,    59,    86,    78,    79,    77,
      60,    80,     2,     3,    78,    79,    57,    87,    80,    39,
      40,    81,    82,    62,    83,    84,    85,    63,    81,    82,
      98,    83,    84,    85,    68,    86,    70,    71,    77,    23,
      10,    11,    86,    78,    79,   158,    87,    80,    64,    10,
      11,   101,   159,    87,    75,    10,    11,    81,    82,   194,
      83,    84,    85,   104,    77,   144,   145,   146,   105,    78,
      79,    86,    77,    80,   106,   107,   202,    78,    79,   108,
     113,    80,    87,    81,    82,   109,    83,    84,    85,   110,
     111,    81,    82,   112,    83,    84,    85,    86,   118,   114,
     119,   120,   136,   138,   139,    86,   181,   163,    87,   142,
     143,   144,   145,   146,   180,   182,    87,   142,   143,   144,
     145,   146,   183,   189,   147,   148,   149,   150,   151,   152,
     184,   198,   147,   148,   149,   150,   151,   152,   199,   203,
     190,   204,   205,    24,    46,    19,   153,   154,    61,    76,
       0,     0,   155,     0,   153,   154,     0,     0,     0,     0,
     156,   142,   143,   144,   145,   146,     0,     0,   142,   143,
     144,   145,   146,     0,     0,     0,   147,   148,   149,   150,
     151,   152,     0,   147,   148,   149,   150,   151,   152,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
       0,     0,     0,     0,   157,   153,   154,     0,     0,     0,
       0,   166,   142,   143,   144,   145,   146,     0,     0,   142,
     143,   144,   145,   146,     0,     0,     0,   147,   148,   149,
     150,   151,   152,     0,   147,   148,   149,   150,   151,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     154,     0,     0,     0,     0,   200,   153,   154,     0,     0,
       0,     0,   201,   142,   143,   144,   145,   146,     0,   142,
     143,   144,   145,   146,     0,     0,     0,     0,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     0,   142,   143,   144,   145,   146,     0,     0,     0,
     153,   154,   161,     0,   160,     0,     0,   147,   148,   149,
     150,   151,   152,     0,     0,     0,   142,   143,   144,   145,
     146,     0,     0,     0,     0,     0,   162,     0,     0,   153,
     154,   147,   148,   149,   150,   151,   152,     0,     0,     0,
     142,   143,   144,   145,   146,     0,   142,   143,   144,   145,
     146,     0,     0,   153,   154,   147,   148,   149,   150,   151,
     152,   147,   148,   149,   150,   151,   152,     0,     0,     0,
     142,   143,   144,   145,   146,     0,     0,   153,   154,     0,
       0,     0,     0,     0,   154,   147,   148,   149,   150,   151,
     152
};

static const yytype_int16 yycheck[] =
{
      68,    88,   109,    13,    13,   112,     5,     5,    38,     5,
       5,     5,     6,    57,     5,   107,   108,     6,    70,    71,
      88,   113,    66,   115,    42,    19,   118,    42,    46,     0,
      19,    46,    42,    42,    45,   127,     5,   105,     5,    38,
      38,   109,    38,    38,   112,   132,   133,    38,   140,    46,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    42,   132,   133,    47,    46,    37,    38,
      39,    38,     5,    45,   181,   182,    45,    10,    11,    45,
      49,    14,    49,    16,    17,   192,    42,    32,    33,    34,
      46,    24,    25,   185,    27,    28,    29,   189,   190,    38,
     187,   188,    31,     5,    35,    38,    35,    38,    10,    11,
     197,    37,    14,   181,   182,    31,    49,    33,    34,   187,
     188,    44,    24,    25,   192,    27,    28,    29,    43,   197,
      45,    43,     5,    45,    36,    38,    38,    10,    11,     5,
      38,    14,    33,    34,    10,    11,    31,    49,    14,    33,
      34,    24,    25,    47,    27,    28,    29,    47,    24,    25,
      48,    27,    28,    29,     8,    38,    62,    63,     5,    32,
      33,    34,    38,    10,    11,    48,    49,    14,    32,    33,
      34,    38,    48,    49,    32,    33,    34,    24,    25,    26,
      27,    28,    29,    38,     5,     5,     6,     7,    45,    10,
      11,    38,     5,    14,    45,    45,    17,    10,    11,    45,
      43,    14,    49,    24,    25,    47,    27,    28,    29,    13,
      13,    24,    25,    47,    27,    28,    29,    38,    12,    38,
      48,    48,     9,    38,    46,    38,    15,    13,    49,     3,
       4,     5,     6,     7,    13,    25,    49,     3,     4,     5,
       6,     7,    24,    45,    18,    19,    20,    21,    22,    23,
      30,    13,    18,    19,    20,    21,    22,    23,    13,    13,
      45,    13,    13,    12,    37,     5,    40,    41,    52,    66,
      -1,    -1,    46,    -1,    40,    41,    -1,    -1,    -1,    -1,
      46,     3,     4,     5,     6,     7,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    -1,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    46,    40,    41,    -1,    -1,    -1,
      -1,    46,     3,     4,     5,     6,     7,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    23,    -1,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    46,    40,    41,    -1,    -1,
      -1,    -1,    46,     3,     4,     5,     6,     7,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    18,    19,    20,    21,    22,    23,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      40,    41,    13,    -1,    44,    -1,    -1,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    40,
      41,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    40,    41,    18,    19,    20,    21,    22,
      23,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    41,    18,    19,    20,    21,    22,
      23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    33,    34,    51,    52,    58,    59,    62,    32,
      33,    34,    53,    54,    56,    35,    38,    38,     0,    58,
      62,    59,    62,    32,    54,     5,    38,    55,    57,    45,
      45,    45,    62,    38,    43,    45,    13,    42,    46,    33,
      34,    60,    61,    60,    37,    60,    57,    47,     5,    38,
       5,    38,    42,    46,    46,    44,    46,    31,    63,    38,
      38,    61,    47,    47,    32,    56,    64,    65,     8,    67,
      63,    63,     5,    38,    66,    32,    65,     5,    10,    11,
      14,    24,    25,    27,    28,    29,    38,    49,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    79,    48,    67,
      67,    38,    13,    42,    38,    45,    45,    45,    45,    47,
      13,    13,    47,    43,    38,    36,    68,    70,    12,    48,
      48,     5,    38,    79,    37,    38,    39,    45,    78,    79,
      78,    78,    69,    69,    78,    78,     9,    78,    38,    46,
      45,    78,     3,     4,     5,     6,     7,    18,    19,    20,
      21,    22,    23,    40,    41,    46,    46,    46,    48,    48,
      44,    13,    13,    13,    78,    80,    46,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      13,    15,    25,    24,    30,    42,    46,    69,    69,    45,
      45,    78,    16,    17,    26,    78,    78,    69,    13,    13,
      46,    46,    17,    13,    13,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    51,    51,    52,    52,    53,    53,
      54,    55,    55,    56,    56,    57,    57,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    61,    61,    61,    61,
      62,    63,    63,    63,    64,    64,    65,    66,    66,    66,
      66,    67,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    71,    72,    73,    74,    74,    75,
      76,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     3,     2,     2,     1,
       3,     3,     1,     1,     1,     1,     4,     4,     2,     2,
       1,     9,     9,     3,     1,     0,     2,     2,     3,     3,
       8,     3,     0,     2,     2,     1,     3,     3,     1,     4,
       2,     4,     3,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     5,     5,     4,    10,     8,     8,
       9,     9,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     4,     1,
       1,     4,     2,     2,     3,     1,     0
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
#line 76 "compiler.y"
                                                {   
                                                    exitProg(output);
                                                    printGST();  
                                                }
#line 1616 "y.tab.c"
    break;

  case 3:
#line 80 "compiler.y"
                                                {   
                                                    exitProg(output);
                                                    printGST();  
                                                }
#line 1625 "y.tab.c"
    break;

  case 4:
#line 84 "compiler.y"
                                                {   
                                                    exitProg(output);
                                                    printGST();  
                                                }
#line 1634 "y.tab.c"
    break;

  case 5:
#line 88 "compiler.y"
                                                {
                                                    exitProg(output);
                                                    printGST();  
                                                }
#line 1643 "y.tab.c"
    break;

  case 6:
#line 94 "compiler.y"
                                                {   }
#line 1649 "y.tab.c"
    break;

  case 7:
#line 95 "compiler.y"
                                                {   }
#line 1655 "y.tab.c"
    break;

  case 10:
#line 99 "compiler.y"
                                                {   }
#line 1661 "y.tab.c"
    break;

  case 13:
#line 104 "compiler.y"
                                                {   current_type = TLookup("int");    }
#line 1667 "y.tab.c"
    break;

  case 14:
#line 105 "compiler.y"
                                                {   current_type = TLookup("str");    }
#line 1673 "y.tab.c"
    break;

  case 15:
#line 107 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[0].node), current_type, 1, 1,NULL, NODE_ID);    }
#line 1679 "y.tab.c"
    break;

  case 16:
#line 108 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[-3].node), current_type, 1, (yyvsp[-1].node)->value.intVal, NULL, NODE_ID); }
#line 1685 "y.tab.c"
    break;

  case 17:
#line 109 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[-3].node), current_type, 1, 1, (yyvsp[-1].parameter), NODE_FUNCT);LST = NULL;    }
#line 1691 "y.tab.c"
    break;

  case 18:
#line 110 "compiler.y"
                                                {   
                                                    GST = insertToGlobal((yyvsp[0].node), ptrType(), 1, 1, NULL, NODE_ID);    
                                                }
#line 1699 "y.tab.c"
    break;

  case 19:
#line 116 "compiler.y"
                                                {      }
#line 1705 "y.tab.c"
    break;

  case 20:
#line 117 "compiler.y"
                                                {      }
#line 1711 "y.tab.c"
    break;

  case 21:
#line 119 "compiler.y"
                                                                            {   
                                                                                setHeader(output);  
                                                                                validateFunct(TLookup("int"), (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node)); 
                                                                                printLST((yyvsp[-7].node)->name);
                                                                                generateFunct(output, (yyvsp[-7].node), (yyvsp[-1].node));
                                                                            }
#line 1722 "y.tab.c"
    break;

  case 22:
#line 125 "compiler.y"
                                                                            {   
                                                                                setHeader(output);  
                                                                                validateFunct(TLookup("str"), (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node));    
                                                                                printLST((yyvsp[-7].node)->name);
                                                                                generateFunct(output, (yyvsp[-7].node), (yyvsp[-1].node));
                                                                            }
#line 1733 "y.tab.c"
    break;

  case 23:
#line 132 "compiler.y"
                                        {   (yyval.parameter) = appendParam((yyvsp[-2].parameter), (yyvsp[0].parameter)); }
#line 1739 "y.tab.c"
    break;

  case 24:
#line 133 "compiler.y"
                                        {   (yyval.parameter) = (yyvsp[0].parameter); }
#line 1745 "y.tab.c"
    break;

  case 25:
#line 134 "compiler.y"
                                        {   (yyval.parameter) = NULL; }
#line 1751 "y.tab.c"
    break;

  case 26:
#line 137 "compiler.y"
                                       {   
                                            (yyval.parameter) = createParam(TLookup("int"), (yyvsp[0].node));  
                                            LST = addParamtoLST((yyval.parameter));
                                        }
#line 1760 "y.tab.c"
    break;

  case 27:
#line 141 "compiler.y"
                                        {
                                            (yyval.parameter) = createParam(TLookup("str"), (yyvsp[0].node));  
                                            LST = addParamtoLST((yyval.parameter));
                                        }
#line 1769 "y.tab.c"
    break;

  case 28:
#line 145 "compiler.y"
                                            {   
                                            (yyval.parameter) = createParam(TLookup("int ptr"), (yyvsp[0].node));  
                                            LST = addParamtoLST((yyval.parameter));
                                        }
#line 1778 "y.tab.c"
    break;

  case 29:
#line 149 "compiler.y"
                                             {
                                            (yyval.parameter) = createParam(TLookup("str ptr"), (yyvsp[0].node));  
                                            LST = addParamtoLST((yyval.parameter));
                                        }
#line 1787 "y.tab.c"
    break;

  case 30:
#line 157 "compiler.y"
                                                                {   
                                                                    setHeader(output);  
                                                                    validateMain((yyvsp[-1].node));
                                                                    printLST("MAIN");
                                                                    generateFunct(output, NULL, (yyvsp[-1].node));
                                                                    LST = NULL;
                                                                   }
#line 1799 "y.tab.c"
    break;

  case 31:
#line 168 "compiler.y"
                                                                {  }
#line 1805 "y.tab.c"
    break;

  case 34:
#line 172 "compiler.y"
                                                                {  }
#line 1811 "y.tab.c"
    break;

  case 35:
#line 173 "compiler.y"
                                                                {  }
#line 1817 "y.tab.c"
    break;

  case 36:
#line 175 "compiler.y"
                                                                {  }
#line 1823 "y.tab.c"
    break;

  case 37:
#line 177 "compiler.y"
                                                                {   LST = createLST((yyvsp[0].node), current_type);   }
#line 1829 "y.tab.c"
    break;

  case 38:
#line 178 "compiler.y"
                                                                {   LST = createLST((yyvsp[0].node), current_type);   }
#line 1835 "y.tab.c"
    break;

  case 39:
#line 179 "compiler.y"
                                                                {   
                                                                    LST = createLST((yyvsp[0].node), ptrType());   
                                                                }
#line 1843 "y.tab.c"
    break;

  case 40:
#line 182 "compiler.y"
                                                                {   
                                                                    LST = createLST((yyvsp[0].node), ptrType());   
                                                                }
#line 1851 "y.tab.c"
    break;

  case 41:
#line 189 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_CONNECTOR, (yyvsp[-2].node), (yyvsp[-1].node));    }
#line 1857 "y.tab.c"
    break;

  case 42:
#line 191 "compiler.y"
                                                    {   
                                                        (yyval.node) = createRtnNode((yyvsp[-1].node));
                                                    }
#line 1865 "y.tab.c"
    break;

  case 43:
#line 195 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_CONNECTOR, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1871 "y.tab.c"
    break;

  case 44:
#line 196 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1877 "y.tab.c"
    break;

  case 45:
#line 198 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1883 "y.tab.c"
    break;

  case 46:
#line 199 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1889 "y.tab.c"
    break;

  case 47:
#line 200 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1895 "y.tab.c"
    break;

  case 48:
#line 201 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1901 "y.tab.c"
    break;

  case 49:
#line 202 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1907 "y.tab.c"
    break;

  case 50:
#line 203 "compiler.y"
                                                    {   (yyval.node) = createControlFlowNode(NODE_BREAK); }
#line 1913 "y.tab.c"
    break;

  case 51:
#line 204 "compiler.y"
                                                    {   (yyval.node) = createControlFlowNode(NODE_CONTINUE); }
#line 1919 "y.tab.c"
    break;

  case 52:
#line 205 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1925 "y.tab.c"
    break;

  case 53:
#line 206 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1931 "y.tab.c"
    break;

  case 54:
#line 208 "compiler.y"
                                                        {   (yyval.node) = createTreeNode(NODE_READ, (yyvsp[-2].node), NULL);   }
#line 1937 "y.tab.c"
    break;

  case 55:
#line 210 "compiler.y"
                                                        {   (yyval.node) = createTreeNode(NODE_WRITE, (yyvsp[-2].node), NULL);     }
#line 1943 "y.tab.c"
    break;

  case 56:
#line 212 "compiler.y"
                                                        {   (yyval.node) = createTreeNode(NODE_ASSIGN, (yyvsp[-3].node), (yyvsp[-1].node));    }
#line 1949 "y.tab.c"
    break;

  case 57:
#line 215 "compiler.y"
                                                                 {  (yyval.node) = createIfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));  }
#line 1955 "y.tab.c"
    break;

  case 58:
#line 216 "compiler.y"
                                                                 {  (yyval.node) = createIfNode((yyvsp[-5].node), (yyvsp[-2].node), NULL); }
#line 1961 "y.tab.c"
    break;

  case 59:
#line 218 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_WHILE, (yyvsp[-5].node), (yyvsp[-2].node));   }
#line 1967 "y.tab.c"
    break;

  case 60:
#line 220 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_RPTUTL, (yyvsp[-2].node), (yyvsp[-6].node));   }
#line 1973 "y.tab.c"
    break;

  case 61:
#line 222 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_DOWHILE, (yyvsp[-2].node), (yyvsp[-6].node));   }
#line 1979 "y.tab.c"
    break;

  case 62:
#line 225 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1985 "y.tab.c"
    break;

  case 63:
#line 226 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1991 "y.tab.c"
    break;

  case 64:
#line 227 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1997 "y.tab.c"
    break;

  case 65:
#line 228 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2003 "y.tab.c"
    break;

  case 66:
#line 229 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2009 "y.tab.c"
    break;

  case 67:
#line 230 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_EQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2015 "y.tab.c"
    break;

  case 68:
#line 231 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_NE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2021 "y.tab.c"
    break;

  case 69:
#line 232 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_GT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2027 "y.tab.c"
    break;

  case 70:
#line 233 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_GE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2033 "y.tab.c"
    break;

  case 71:
#line 234 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_LT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2039 "y.tab.c"
    break;

  case 72:
#line 235 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_LE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2045 "y.tab.c"
    break;

  case 73:
#line 236 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2051 "y.tab.c"
    break;

  case 74:
#line 237 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2057 "y.tab.c"
    break;

  case 75:
#line 238 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[-1].node);    }
#line 2063 "y.tab.c"
    break;

  case 76:
#line 239 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2069 "y.tab.c"
    break;

  case 77:
#line 240 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2075 "y.tab.c"
    break;

  case 78:
#line 241 "compiler.y"
                                                    {   
                                                        setType((yyvsp[-3].node));
                                                        (yyval.node) = createFunctNode((yyvsp[-3].node), (yyvsp[-1].node)); 
                                                    }
#line 2084 "y.tab.c"
    break;

  case 79:
#line 245 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2090 "y.tab.c"
    break;

  case 80:
#line 248 "compiler.y"
                                                    {   
                                                        setType((yyvsp[0].node));
                                                        (yyval.node) = (yyvsp[0].node);    
                                                    }
#line 2099 "y.tab.c"
    break;

  case 81:
#line 252 "compiler.y"
                                                    {   
                                                        setType((yyvsp[-3].node));
                                                        (yyval.node) = createArrayNode((yyvsp[-3].node), NULL, (yyvsp[-1].node)); 
                                                    }
#line 2108 "y.tab.c"
    break;

  case 82:
#line 256 "compiler.y"
                                                    {
                                                        setType((yyvsp[0].node));
                                                        (yyval.node) = createDerefNode((yyvsp[0].node));
                                                    }
#line 2117 "y.tab.c"
    break;

  case 83:
#line 260 "compiler.y"
                                                    {
                                                        setType((yyvsp[0].node));
                                                        (yyval.node) = createAddrNode((yyvsp[0].node));
                                                    }
#line 2126 "y.tab.c"
    break;

  case 84:
#line 265 "compiler.y"
                                                    {   (yyval.node) = appendArgNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2132 "y.tab.c"
    break;

  case 85:
#line 266 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2138 "y.tab.c"
    break;

  case 86:
#line 267 "compiler.y"
                                                    {   (yyval.node) = NULL;  }
#line 2144 "y.tab.c"
    break;


#line 2148 "y.tab.c"

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
#line 270 "compiler.y"


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
