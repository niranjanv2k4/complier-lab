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
    struct LSymbol* LST = NULL;
    struct Typetable* current_type;


#line 91 "y.tab.c"

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
    TYPE = 291,
    ENDTYPE = 292,
    ALLOC = 293,
    INITIALIZE = 294,
    FREE = 295,
    NULL_VAL = 296,
    RETURN = 297,
    NUM = 298,
    ID = 299,
    STR_LITERAL = 300,
    OR = 301,
    AND = 302
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
#define TYPE 291
#define ENDTYPE 292
#define ALLOC 293
#define INITIALIZE 294
#define FREE 295
#define NULL_VAL 296
#define RETURN 297
#define NUM 298
#define ID 299
#define STR_LITERAL 300
#define OR 301
#define AND 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "compiler.y"

    struct ASTNode* node;
    struct param* parameter;
    struct LSymbol* localSymbolTable;
    struct Arglist* Args;
    struct Fieldlist* fieldlist;
    int type;

#line 246 "y.tab.c"

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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   616

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  264

#define YYUNDEFTOK  2
#define YYMAXUTOK   302


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
      55,    56,     2,     2,    52,     2,    48,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    73,    73,    74,    75,    80,    81,    84,    85,    88,
      88,    91,    92,    95,    97,    98,    99,   104,   105,   107,
     108,   109,   111,   112,   113,   115,   116,   118,   119,   120,
     121,   127,   128,   130,   137,   144,   155,   166,   167,   168,
     170,   171,   172,   173,   174,   175,   180,   181,   182,   184,
     185,   187,   189,   190,   191,   192,   197,   199,   201,   202,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     215,   217,   219,   220,   221,   224,   225,   227,   229,   231,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   254,
     255,   256,   259,   260,   261,   262,   263,   264,   265,   266,
     267
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
  "INT", "STR", "MAIN", "TYPE", "ENDTYPE", "ALLOC", "INITIALIZE", "FREE",
  "NULL_VAL", "RETURN", "NUM", "ID", "STR_LITERAL", "OR", "AND", "'.'",
  "'&'", "'{'", "'}'", "','", "'['", "']'", "'('", "')'", "$accept",
  "program", "TypeDefBlock", "TypeDefList", "TypeDef", "$@1",
  "FieldDeclList", "FieldDecl", "TypeName", "GDeclBlock", "GDeclList",
  "GDecl", "Type", "GidList", "Gid", "FDefBlock", "Fdef", "MainBlock",
  "ParamList", "Param", "LDeclBlock", "LDeclList", "LDecl", "IdList",
  "Coderegion", "RtnStmt", "Slist", "Stmt", "InputStmt", "OutputStmt",
  "AsgnStmt", "IfStmt", "WhileStmt", "RptUntlStmt", "DoWhileStmt", "expr",
  "ArgList", "IDENTIFIERS", "UserDef", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,    46,    38,
     123,   125,    44,    91,    93,    40,    41
};
# endif

#define YYPACT_NINF (-139)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -33,    -3,    11,    89,  -139,   216,  -139,  -139,   108,     5,
     -27,  -139,    21,  -139,  -139,  -139,  -139,  -139,  -139,   169,
    -139,    -1,    12,    22,    26,    53,   -27,  -139,  -139,   110,
    -139,  -139,    75,   142,    -4,  -139,    72,    68,    90,   100,
    -139,  -139,  -139,  -139,  -139,   102,  -139,   106,  -139,   121,
     129,  -139,    -1,   132,   129,   129,   129,  -139,  -139,   192,
     152,    19,    20,    46,    17,  -139,  -139,   183,    35,    36,
      95,  -139,  -139,   214,  -139,   223,  -139,   224,  -139,   129,
    -139,   175,   207,   186,   220,   237,  -139,  -139,  -139,  -139,
    -139,    67,   217,  -139,   489,   218,   183,   183,   183,   229,
    -139,    69,  -139,  -139,   230,   233,   234,   235,   248,   254,
     292,   293,   257,   253,    -9,   265,   155,   349,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,   298,   263,  -139,   207,
     207,   207,  -139,  -139,    81,  -139,     3,   155,   155,   155,
     489,  -139,  -139,   489,     3,   268,   155,  -139,  -139,  -139,
     204,  -139,   155,     9,  -139,   155,   304,  -139,    40,   270,
     264,   266,   267,   272,  -139,   274,   165,   171,   219,   357,
     389,   276,  -139,   111,   155,   225,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   275,
     536,  -139,   269,   281,   557,  -139,  -139,  -139,  -139,  -139,
     308,   324,   323,   314,   316,   313,   334,   300,   504,   164,
     275,   174,   174,  -139,  -139,  -139,   587,   587,   587,   587,
     587,   587,    15,   593,   305,  -139,   294,   295,  -139,  -139,
    -139,   489,   489,   297,   301,  -139,   309,   155,  -139,  -139,
     342,   345,   317,   421,   155,   155,  -139,   504,  -139,  -139,
     489,   351,   352,   273,   279,   457,  -139,  -139,   356,   362,
     366,  -139,  -139,  -139
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     0,     0,     9,     0,     8,     1,     0,     0,
       0,     4,     0,     5,     7,    18,    22,    23,    24,     0,
      20,     0,     0,     0,     0,     0,     0,    32,     3,     0,
      17,    19,     0,    27,     0,    26,     0,     0,     0,     0,
      31,     2,    14,    15,    16,     0,    12,     0,    28,     0,
      39,    21,     0,     0,    39,    39,    39,    10,    11,     0,
       0,     0,     0,     0,     0,    38,    25,    47,     0,     0,
       0,    13,    29,     0,    40,     0,    41,     0,    45,     0,
      30,     0,     0,     0,     0,     0,    42,    43,    44,    37,
      48,     0,     0,    50,     0,     0,    47,    47,    47,     0,
      53,     0,    46,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,     0,     0,     0,    59,    60,
      61,    62,    63,    64,    67,    68,     0,   107,    36,     0,
       0,     0,    55,    51,     0,   104,     0,     0,     0,     0,
       0,    65,    66,     0,     0,     0,     0,   105,    98,    94,
     102,    95,     0,     0,    97,     0,     0,    58,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,   109,     0,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,     0,   108,    33,    34,    35,    54,
       0,     0,     0,     0,     0,     0,     0,   103,   100,     0,
      93,    80,    81,    82,    83,    84,    88,    90,    85,    87,
      89,    86,    91,    92,     0,    57,     0,     0,    72,    70,
      71,     0,     0,     0,     0,    69,     0,     0,    96,   106,
       0,     0,     0,     0,     0,     0,   110,    99,    73,    74,
       0,     0,     0,     0,     0,     0,    76,    77,     0,     0,
       0,    79,    78,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,  -139,   365,  -139,  -139,   335,  -139,  -139,
    -139,   364,    32,  -139,   336,  -139,   361,     0,   179,   311,
     158,  -139,   303,  -139,   133,  -139,  -138,  -116,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,   -78,  -139,   -94,  -139
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    12,    45,    46,    47,    10,
      19,    20,    21,    34,    35,    26,    27,    11,    64,    65,
      82,    92,    93,   101,    95,   156,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   153,   209,   154,   127
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     126,   157,   169,     1,    32,   170,    23,    24,   104,    51,
      28,     7,   176,   177,   178,   179,   180,    25,   176,   177,
     178,   179,   180,   126,    73,    75,    41,   181,   182,   183,
     184,   185,   186,   181,   182,   183,   184,   185,   186,   145,
      22,     4,   165,    33,   146,   104,   126,   114,    52,   126,
     171,    77,   115,   157,   157,   187,   188,    22,   116,   166,
     167,   168,   188,    74,    76,   189,    37,    36,   173,    79,
      38,    29,    99,    80,   175,   126,   126,   190,   192,   193,
     194,   148,   133,   149,   150,   151,   163,    79,    79,   115,
      78,    83,    84,   242,   243,   152,   208,    39,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   100,   255,    91,   176,   177,   178,   179,   180,    48,
       8,   134,     9,    54,    91,   164,   157,   157,    53,   181,
     182,   183,   184,   185,   186,    42,    43,   126,   126,   157,
      15,    16,    17,    42,    43,    55,    44,    79,   126,   126,
      59,    85,    18,    57,    44,    56,   126,   187,   188,   247,
     104,   126,    61,    62,    60,   207,   253,   254,   176,   177,
     178,   179,   180,    63,   176,   177,   178,   179,   180,   178,
     179,   180,    67,   181,   182,   183,   184,   185,   186,   181,
     182,   183,   184,   185,   186,    49,   148,    50,   149,   150,
     151,    30,    16,    17,   115,    71,    72,    90,    16,    17,
     152,   187,   188,    18,    81,    94,   237,   187,   188,    18,
     238,   201,   176,   177,   178,   179,   180,   202,   176,   177,
     178,   179,   180,    68,    69,    70,    96,   181,   182,   183,
     184,   185,   186,   181,   182,   183,   184,   185,   186,   102,
      16,    17,   145,    13,   129,   130,   131,   146,    86,   174,
       4,    18,   160,   161,   162,   187,   188,    87,    88,   128,
      97,   187,   188,   132,   135,   203,   176,   177,   178,   179,
     180,   210,   176,   177,   178,   179,   180,    98,   136,   137,
     138,   181,   182,   183,   184,   185,   186,   181,   182,   183,
     184,   185,   186,   139,   140,   141,   142,   143,   144,   147,
     158,   159,   172,   191,   195,   196,   199,   197,   198,   187,
     188,   229,   104,   224,   226,   187,   188,   105,   106,   258,
     200,   107,   206,   250,   251,   259,   227,   230,   231,   232,
     233,   108,   109,   234,   110,   111,   112,   235,   236,   239,
     240,   241,   244,   246,   104,   248,   245,   113,   249,   105,
     106,   114,   104,   107,   256,   257,   115,   105,   106,   261,
      14,   107,   116,   108,   109,   262,   110,   111,   112,   263,
      58,   108,   109,    31,   110,   111,   112,    40,    66,   113,
      89,   155,     0,   114,   104,   103,     0,   113,   115,   105,
     106,   114,     0,   107,   116,     0,   115,     0,   204,     0,
       0,     0,   116,   108,   109,     0,   110,   111,   112,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   113,
       0,   105,   106,   114,     0,   107,     0,     0,   115,     0,
     205,     0,     0,     0,   116,   108,   109,   252,   110,   111,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,   104,     0,     0,   114,     0,   105,   106,     0,
     115,   107,     0,     0,   260,     0,   116,     0,     0,     0,
       0,   108,   109,     0,   110,   111,   112,     0,     0,     0,
       0,     0,     0,     0,   104,     0,     0,   113,     0,   105,
     106,   114,     0,   107,     0,     0,   115,   176,   177,   178,
     179,   180,   116,   108,   109,     0,   110,   111,   112,     0,
       0,     0,   181,   182,   183,   184,   185,   186,     0,   113,
       0,     0,     0,   114,     0,     0,     0,     0,   115,   176,
     177,   178,   179,   180,   116,     0,     0,     0,     0,   225,
     187,   188,     0,     0,   181,   182,   183,   184,   185,   186,
     176,   177,   178,   179,   180,     0,     0,     0,     0,     0,
     228,     0,     0,     0,     0,   181,   182,   183,   184,   185,
     186,     0,   187,   188,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,     0,   176,   177,   178,   179,
     180,     0,     0,   187,   188,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,   184,   185,   186
};

static const yytype_int16 yycheck[] =
{
      94,   117,   140,    36,     5,   143,    33,    34,     5,    13,
      10,     0,     3,     4,     5,     6,     7,    44,     3,     4,
       5,     6,     7,   117,     5,     5,    26,    18,    19,    20,
      21,    22,    23,    18,    19,    20,    21,    22,    23,    48,
      35,    44,   136,    44,    53,     5,   140,    44,    52,   143,
     144,     5,    49,   169,   170,    46,    47,    35,    55,   137,
     138,   139,    47,    44,    44,    56,    44,    55,   146,    52,
      44,    50,     5,    56,   152,   169,   170,   155,    38,    39,
     158,    41,    13,    43,    44,    45,     5,    52,    52,    49,
      44,    56,    56,   231,   232,    55,   174,    44,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    44,   250,    81,     3,     4,     5,     6,     7,    44,
      31,    52,    33,    55,    92,    44,   242,   243,    56,    18,
      19,    20,    21,    22,    23,    33,    34,   231,   232,   255,
      32,    33,    34,    33,    34,    55,    44,    52,   242,   243,
      44,    56,    44,    51,    44,    55,   250,    46,    47,   237,
       5,   255,    33,    34,    43,    54,   244,   245,     3,     4,
       5,     6,     7,    44,     3,     4,     5,     6,     7,     5,
       6,     7,    50,    18,    19,    20,    21,    22,    23,    18,
      19,    20,    21,    22,    23,    53,    41,    55,    43,    44,
      45,    32,    33,    34,    49,    13,    54,    32,    33,    34,
      55,    46,    47,    44,    31,     8,    52,    46,    47,    44,
      56,    56,     3,     4,     5,     6,     7,    56,     3,     4,
       5,     6,     7,    54,    55,    56,    50,    18,    19,    20,
      21,    22,    23,    18,    19,    20,    21,    22,    23,    32,
      33,    34,    48,    37,    96,    97,    98,    53,    44,    55,
      44,    44,   129,   130,   131,    46,    47,    44,    44,    51,
      50,    46,    47,    44,    44,    56,     3,     4,     5,     6,
       7,    56,     3,     4,     5,     6,     7,    50,    55,    55,
      55,    18,    19,    20,    21,    22,    23,    18,    19,    20,
      21,    22,    23,    55,    50,    13,    13,    50,    55,    44,
      12,    48,    44,     9,    44,    51,    44,    51,    51,    46,
      47,    13,     5,    48,    55,    46,    47,    10,    11,    56,
      56,    14,    56,    16,    17,    56,    55,    13,    15,    25,
      24,    24,    25,    30,    27,    28,    29,    13,    48,    44,
      56,    56,    55,    44,     5,    13,    55,    40,    13,    10,
      11,    44,     5,    14,    13,    13,    49,    10,    11,    13,
       5,    14,    55,    24,    25,    13,    27,    28,    29,    13,
      45,    24,    25,    19,    27,    28,    29,    26,    52,    40,
      79,    42,    -1,    44,     5,    92,    -1,    40,    49,    10,
      11,    44,    -1,    14,    55,    -1,    49,    -1,    51,    -1,
      -1,    -1,    55,    24,    25,    -1,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    40,
      -1,    10,    11,    44,    -1,    14,    -1,    -1,    49,    -1,
      51,    -1,    -1,    -1,    55,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,     5,    -1,    -1,    44,    -1,    10,    11,    -1,
      49,    14,    -1,    -1,    17,    -1,    55,    -1,    -1,    -1,
      -1,    24,    25,    -1,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     5,    -1,    -1,    40,    -1,    10,
      11,    44,    -1,    14,    -1,    -1,    49,     3,     4,     5,
       6,     7,    55,    24,    25,    -1,    27,    28,    29,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    -1,    40,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    49,     3,
       4,     5,     6,     7,    55,    -1,    -1,    -1,    -1,    13,
      46,    47,    -1,    -1,    18,    19,    20,    21,    22,    23,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    46,    47,    18,    19,    20,    21,    22,
      23,    18,    19,    20,    21,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    58,    59,    44,    60,    61,     0,    31,    33,
      66,    74,    62,    37,    61,    32,    33,    34,    44,    67,
      68,    69,    35,    33,    34,    44,    72,    73,    74,    50,
      32,    68,     5,    44,    70,    71,    55,    44,    44,    44,
      73,    74,    33,    34,    44,    63,    64,    65,    44,    53,
      55,    13,    52,    56,    55,    55,    55,    51,    64,    44,
      43,    33,    34,    44,    75,    76,    71,    50,    75,    75,
      75,    13,    54,     5,    44,     5,    44,     5,    44,    52,
      56,    31,    77,    56,    56,    56,    44,    44,    44,    76,
      32,    69,    78,    79,     8,    81,    50,    50,    50,     5,
      44,    80,    32,    79,     5,    10,    11,    14,    24,    25,
      27,    28,    29,    40,    44,    49,    55,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    94,    95,    51,    77,
      77,    77,    44,    13,    52,    44,    55,    55,    55,    55,
      50,    13,    13,    50,    55,    48,    53,    44,    41,    43,
      44,    45,    55,    92,    94,    42,    82,    84,    12,    48,
      81,    81,    81,     5,    44,    94,    92,    92,    92,    83,
      83,    94,    44,    92,    55,    92,     3,     4,     5,     6,
       7,    18,    19,    20,    21,    22,    23,    46,    47,    56,
      92,     9,    38,    39,    92,    44,    51,    51,    51,    44,
      56,    56,    56,    56,    51,    51,    56,    54,    92,    93,
      56,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    48,    13,    55,    55,    13,    13,
      13,    15,    25,    24,    30,    13,    48,    52,    56,    44,
      56,    56,    83,    83,    55,    55,    44,    92,    13,    13,
      16,    17,    26,    92,    92,    83,    13,    13,    56,    56,
      17,    13,    13,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    58,    59,    59,    60,    60,    62,
      61,    63,    63,    64,    65,    65,    65,    66,    66,    67,
      67,    68,    69,    69,    69,    70,    70,    71,    71,    71,
      71,    72,    72,    73,    73,    73,    74,    75,    75,    75,
      76,    76,    76,    76,    76,    76,    77,    77,    77,    78,
      78,    79,    80,    80,    80,    80,    81,    82,    83,    83,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      85,    86,    87,    87,    87,    88,    88,    89,    90,    91,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    93,    94,    94,    94,    94,    94,    94,    95,    95,
      95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     0,     2,     1,     0,
       5,     2,     1,     3,     1,     1,     1,     3,     2,     2,
       1,     3,     1,     1,     1,     3,     1,     1,     2,     4,
       4,     2,     1,     9,     9,     9,     8,     3,     1,     0,
       2,     2,     3,     3,     3,     2,     3,     0,     2,     2,
       1,     3,     3,     1,     4,     2,     4,     3,     2,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     5,
       5,     5,     4,     6,     6,    10,     8,     8,     9,     9,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     4,     1,     1,     3,
       1,     0,     1,     4,     2,     2,     5,     1,     3,     3,
       6
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
#line 73 "compiler.y"
                                                             {   exitProg(output);  }
#line 1669 "y.tab.c"
    break;

  case 3:
#line 74 "compiler.y"
                                                             {   exitProg(output);  }
#line 1675 "y.tab.c"
    break;

  case 4:
#line 75 "compiler.y"
                                                             {   exitProg(output);  }
#line 1681 "y.tab.c"
    break;

  case 9:
#line 88 "compiler.y"
                        { TInstall((yyvsp[0].node)->name, 0, NULL, TYPE_USERDEF); }
#line 1687 "y.tab.c"
    break;

  case 10:
#line 88 "compiler.y"
                                                                                               {   updateUserDefined((yyvsp[-4].node)->name, (yyvsp[-1].fieldlist)); }
#line 1693 "y.tab.c"
    break;

  case 11:
#line 91 "compiler.y"
                                                  {   (yyval.fieldlist) = appendField((yyvsp[-1].fieldlist), (yyvsp[0].fieldlist));   }
#line 1699 "y.tab.c"
    break;

  case 12:
#line 92 "compiler.y"
                                                  {   (yyval.fieldlist) = (yyvsp[0].fieldlist); }
#line 1705 "y.tab.c"
    break;

  case 13:
#line 95 "compiler.y"
                                                  {   (yyval.fieldlist) = createField(current_type, (yyvsp[-1].node)); }
#line 1711 "y.tab.c"
    break;

  case 14:
#line 97 "compiler.y"
                                                  {   current_type = TLookup("int"); }
#line 1717 "y.tab.c"
    break;

  case 15:
#line 98 "compiler.y"
                                                  {   current_type = TLookup("str"); }
#line 1723 "y.tab.c"
    break;

  case 16:
#line 99 "compiler.y"
                                                  {   current_type = TLookup((yyvsp[0].node)->name);  }
#line 1729 "y.tab.c"
    break;

  case 17:
#line 104 "compiler.y"
                                                {   }
#line 1735 "y.tab.c"
    break;

  case 18:
#line 105 "compiler.y"
                                                {   }
#line 1741 "y.tab.c"
    break;

  case 21:
#line 109 "compiler.y"
                                                {  }
#line 1747 "y.tab.c"
    break;

  case 22:
#line 111 "compiler.y"
                                                {   current_type = TLookup("int");      }
#line 1753 "y.tab.c"
    break;

  case 23:
#line 112 "compiler.y"
                                                {   current_type = TLookup("str");      }
#line 1759 "y.tab.c"
    break;

  case 24:
#line 113 "compiler.y"
                                                {   current_type = TLookup((yyvsp[0].node)->name);   }
#line 1765 "y.tab.c"
    break;

  case 27:
#line 118 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[0].node), current_type, 1, 0, 0,NULL, NODE_ID, false);    }
#line 1771 "y.tab.c"
    break;

  case 28:
#line 119 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[0].node), current_type, 1, 0, 0, NULL, NODE_ID, true);    }
#line 1777 "y.tab.c"
    break;

  case 29:
#line 120 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[-3].node), current_type, (yyvsp[-1].node)->value.intVal, 1, (yyvsp[-1].node)->value.intVal, NULL, NODE_ID, false);   }
#line 1783 "y.tab.c"
    break;

  case 30:
#line 121 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[-3].node), current_type, 0, 0, 0, (yyvsp[-1].parameter), NODE_FUNCT,false);  
                                                    clearLST();  
                                                }
#line 1791 "y.tab.c"
    break;

  case 31:
#line 127 "compiler.y"
                                                {      }
#line 1797 "y.tab.c"
    break;

  case 32:
#line 128 "compiler.y"
                                                {      }
#line 1803 "y.tab.c"
    break;

  case 33:
#line 130 "compiler.y"
                                                                            {   
                                                                                setHeader(output);  
                                                                                validateFunct(TLookup("int"), (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node)); 
                                                                                // printLST($2->name);
                                                                                generateFunct(output, (yyvsp[-7].node), (yyvsp[-1].node));
                                                                                clearLST();  
                                                                            }
#line 1815 "y.tab.c"
    break;

  case 34:
#line 137 "compiler.y"
                                                                            {   
                                                                                setHeader(output);  
                                                                                validateFunct(TLookup("str"), (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node));    
                                                                                // printLST($2->name);
                                                                                generateFunct(output, (yyvsp[-7].node), (yyvsp[-1].node));
                                                                                clearLST();  
                                                                            }
#line 1827 "y.tab.c"
    break;

  case 35:
#line 144 "compiler.y"
                                                                            {   
                                                                                setHeader(output);  
                                                                                validateFunct(TLookup((yyvsp[-8].node)->name), (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node));    
                                                                                // printLST($2->name);
                                                                                generateFunct(output, (yyvsp[-7].node), (yyvsp[-1].node));
                                                                                clearLST();  
                                                                            }
#line 1839 "y.tab.c"
    break;

  case 36:
#line 155 "compiler.y"
                                                                            {   
                                                                                setHeader(output);  
                                                                                validateMain((yyvsp[-1].node));
                                                                                // printLST("MAIN");
                                                                                generateFunct(output, NULL, (yyvsp[-1].node));
                                                                                clearLST();
                                                                            }
#line 1851 "y.tab.c"
    break;

  case 37:
#line 166 "compiler.y"
                                        {   (yyval.parameter) = appendParam((yyvsp[-2].parameter), (yyvsp[0].parameter)); }
#line 1857 "y.tab.c"
    break;

  case 38:
#line 167 "compiler.y"
                                        {   (yyval.parameter) = (yyvsp[0].parameter); }
#line 1863 "y.tab.c"
    break;

  case 39:
#line 168 "compiler.y"
                                        {   (yyval.parameter) = NULL; }
#line 1869 "y.tab.c"
    break;

  case 40:
#line 170 "compiler.y"
                                        {   (yyval.parameter) = createParam("int", (yyvsp[0].node), false);   }
#line 1875 "y.tab.c"
    break;

  case 41:
#line 171 "compiler.y"
                                        {   (yyval.parameter) = createParam("str", (yyvsp[0].node), false);   }
#line 1881 "y.tab.c"
    break;

  case 42:
#line 172 "compiler.y"
                                        {   (yyval.parameter) = createParam("int", (yyvsp[0].node), true);   }
#line 1887 "y.tab.c"
    break;

  case 43:
#line 173 "compiler.y"
                                        {   (yyval.parameter) = createParam("str", (yyvsp[0].node), true);   }
#line 1893 "y.tab.c"
    break;

  case 44:
#line 174 "compiler.y"
                                        {   (yyval.parameter) = createParam((yyvsp[-2].node)->name, (yyvsp[0].node), true);  }
#line 1899 "y.tab.c"
    break;

  case 45:
#line 175 "compiler.y"
                                        {   (yyval.parameter) = createParam((yyvsp[-1].node)->name, (yyvsp[0].node), false); }
#line 1905 "y.tab.c"
    break;

  case 46:
#line 180 "compiler.y"
                                                    {  }
#line 1911 "y.tab.c"
    break;

  case 49:
#line 184 "compiler.y"
                                                    {  }
#line 1917 "y.tab.c"
    break;

  case 50:
#line 185 "compiler.y"
                                                    {  }
#line 1923 "y.tab.c"
    break;

  case 51:
#line 187 "compiler.y"
                                                    {  }
#line 1929 "y.tab.c"
    break;

  case 52:
#line 189 "compiler.y"
                                                    {   LST = createLST((yyvsp[0].node), current_type, false);   }
#line 1935 "y.tab.c"
    break;

  case 53:
#line 190 "compiler.y"
                                                    {   LST = createLST((yyvsp[0].node), current_type, false);   }
#line 1941 "y.tab.c"
    break;

  case 54:
#line 191 "compiler.y"
                                                    {   LST = createLST((yyvsp[0].node), current_type, true);   }
#line 1947 "y.tab.c"
    break;

  case 55:
#line 192 "compiler.y"
                                                    {   LST = createLST((yyvsp[0].node), current_type, true);    }
#line 1953 "y.tab.c"
    break;

  case 56:
#line 197 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_CONNECTOR, (yyvsp[-2].node), (yyvsp[-1].node));    }
#line 1959 "y.tab.c"
    break;

  case 57:
#line 199 "compiler.y"
                                                    {   (yyval.node) = createRtnNode((yyvsp[-1].node)); }
#line 1965 "y.tab.c"
    break;

  case 58:
#line 201 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_CONNECTOR, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1971 "y.tab.c"
    break;

  case 59:
#line 202 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1977 "y.tab.c"
    break;

  case 60:
#line 204 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1983 "y.tab.c"
    break;

  case 61:
#line 205 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1989 "y.tab.c"
    break;

  case 62:
#line 206 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1995 "y.tab.c"
    break;

  case 63:
#line 207 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2001 "y.tab.c"
    break;

  case 64:
#line 208 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2007 "y.tab.c"
    break;

  case 65:
#line 209 "compiler.y"
                                                    {   (yyval.node) = createControlFlowNode(NODE_BREAK); }
#line 2013 "y.tab.c"
    break;

  case 66:
#line 210 "compiler.y"
                                                    {   (yyval.node) = createControlFlowNode(NODE_CONTINUE); }
#line 2019 "y.tab.c"
    break;

  case 67:
#line 211 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2025 "y.tab.c"
    break;

  case 68:
#line 212 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2031 "y.tab.c"
    break;

  case 69:
#line 213 "compiler.y"
                                                    {   (yyval.node) = createDynamicNode(NODE_FREE, (yyvsp[-2].node));  }
#line 2037 "y.tab.c"
    break;

  case 70:
#line 215 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_READ, (yyvsp[-2].node), NULL);   }
#line 2043 "y.tab.c"
    break;

  case 71:
#line 217 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_WRITE, (yyvsp[-2].node), NULL);     }
#line 2049 "y.tab.c"
    break;

  case 72:
#line 219 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_ASSIGN, (yyvsp[-3].node), (yyvsp[-1].node));    }
#line 2055 "y.tab.c"
    break;

  case 73:
#line 220 "compiler.y"
                                                    {   (yyval.node) = createDynamicNode(NODE_ALLOC, (yyvsp[-5].node));  }
#line 2061 "y.tab.c"
    break;

  case 74:
#line 221 "compiler.y"
                                                         {   (yyval.node) = createDynamicNode(NODE_INITIALIZE, NULL);  }
#line 2067 "y.tab.c"
    break;

  case 75:
#line 224 "compiler.y"
                                                                 {  (yyval.node) = createIfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));  }
#line 2073 "y.tab.c"
    break;

  case 76:
#line 225 "compiler.y"
                                                                 {  (yyval.node) = createIfNode((yyvsp[-5].node), (yyvsp[-2].node), NULL); }
#line 2079 "y.tab.c"
    break;

  case 77:
#line 227 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_WHILE, (yyvsp[-5].node), (yyvsp[-2].node));   }
#line 2085 "y.tab.c"
    break;

  case 78:
#line 229 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_RPTUTL, (yyvsp[-2].node), (yyvsp[-6].node));   }
#line 2091 "y.tab.c"
    break;

  case 79:
#line 231 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_DOWHILE, (yyvsp[-2].node), (yyvsp[-6].node));   }
#line 2097 "y.tab.c"
    break;

  case 80:
#line 234 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2103 "y.tab.c"
    break;

  case 81:
#line 235 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2109 "y.tab.c"
    break;

  case 82:
#line 236 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2115 "y.tab.c"
    break;

  case 83:
#line 237 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2121 "y.tab.c"
    break;

  case 84:
#line 238 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2127 "y.tab.c"
    break;

  case 85:
#line 239 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_EQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2133 "y.tab.c"
    break;

  case 86:
#line 240 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_NE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2139 "y.tab.c"
    break;

  case 87:
#line 241 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_GT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2145 "y.tab.c"
    break;

  case 88:
#line 242 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_GE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2151 "y.tab.c"
    break;

  case 89:
#line 243 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_LT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2157 "y.tab.c"
    break;

  case 90:
#line 244 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_LE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2163 "y.tab.c"
    break;

  case 91:
#line 245 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2169 "y.tab.c"
    break;

  case 92:
#line 246 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2175 "y.tab.c"
    break;

  case 93:
#line 247 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[-1].node);    }
#line 2181 "y.tab.c"
    break;

  case 94:
#line 248 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2187 "y.tab.c"
    break;

  case 95:
#line 249 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);   }
#line 2193 "y.tab.c"
    break;

  case 96:
#line 250 "compiler.y"
                                                    {   (yyval.node) = createFunctNode((yyvsp[-3].node), (yyvsp[-1].node));   }
#line 2199 "y.tab.c"
    break;

  case 97:
#line 251 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2205 "y.tab.c"
    break;

  case 98:
#line 252 "compiler.y"
                                                    {   (yyval.node) = createDynamicNode(NODE_NULL, NULL);    }
#line 2211 "y.tab.c"
    break;

  case 99:
#line 254 "compiler.y"
                                                    {   (yyval.node) = appendArgNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2217 "y.tab.c"
    break;

  case 100:
#line 255 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2223 "y.tab.c"
    break;

  case 101:
#line 256 "compiler.y"
                                                    {   (yyval.node) = NULL;  }
#line 2229 "y.tab.c"
    break;

  case 102:
#line 259 "compiler.y"
                                                    {   setType((yyvsp[0].node)); (yyval.node) = (yyvsp[0].node); }
#line 2235 "y.tab.c"
    break;

  case 103:
#line 260 "compiler.y"
                                                    {   (yyval.node) = createArrayNode((yyvsp[-3].node), NULL, (yyvsp[-1].node)); }
#line 2241 "y.tab.c"
    break;

  case 104:
#line 261 "compiler.y"
                                                    {   (yyval.node) = createDerefNode((yyvsp[0].node)); }
#line 2247 "y.tab.c"
    break;

  case 105:
#line 262 "compiler.y"
                                                    {   (yyval.node) = createAddrNode((yyvsp[0].node)); }
#line 2253 "y.tab.c"
    break;

  case 106:
#line 263 "compiler.y"
                                                    {   (yyval.node) = createFieldAccessNode((yyvsp[-3].node), (yyvsp[0].node)); }
#line 2259 "y.tab.c"
    break;

  case 107:
#line 264 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2265 "y.tab.c"
    break;

  case 108:
#line 265 "compiler.y"
                                                    {   (yyval.node) = createFieldAccessNode((yyvsp[-2].node), (yyvsp[0].node));  }
#line 2271 "y.tab.c"
    break;

  case 109:
#line 266 "compiler.y"
                                                    {   (yyval.node) = createFieldAccessNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2277 "y.tab.c"
    break;

  case 110:
#line 267 "compiler.y"
                                                    {   (yyval.node) = createFieldAccessNode(createArrayNode((yyvsp[-5].node), NULL, (yyvsp[-3].node)), (yyvsp[0].node)); }
#line 2283 "y.tab.c"
    break;


#line 2287 "y.tab.c"

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
    printGST();
    fclose(output);
    return 0;
}
