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

    bool isTuple = false;

    struct Typetable* arrType(){
        return current_type == TLookup("int")?TLookup("int arr"):TLookup("str arr");
    }


#line 97 "y.tab.c"

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
#line 28 "compiler.y"

    struct ASTNode* node;
    struct param* parameter;
    struct LSymbol* localSymbolTable;
    struct Arglist* Args;
    struct Fieldlist* fieldlist;
    int type;

#line 242 "y.tab.c"

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   618

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

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
       0,    77,    77,    78,    79,    82,    83,    85,    86,    87,
      89,    90,    91,    93,    94,    96,    97,    98,   105,   117,
     118,   120,   127,   138,   149,   150,   151,   153,   154,   155,
     156,   157,   158,   163,   164,   165,   167,   168,   173,   174,
     175,   177,   178,   180,   182,   183,   184,   185,   190,   192,
     194,   195,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   207,   209,   211,   214,   215,   217,   219,   221,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   243,   244,   245,
     248,   249,   250,   251,   252,   253
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
  "FieldList", "Field", "LDeclBlock", "LDeclList", "LDecl", "IdList",
  "Coderegion", "RtnStmt", "Slist", "Stmt", "InputStmt", "OutputStmt",
  "AsgnStmt", "IfStmt", "WhileStmt", "RptUntlStmt", "DoWhileStmt", "expr",
  "ArgList", "IDENTIFIERS", YY_NULLPTR
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

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,    68,   -28,    24,    98,  -105,  -105,  -105,  -105,    -5,
      72,  -105,    -3,    27,  -105,    -4,    37,    98,  -105,  -105,
      36,  -105,  -105,    44,    71,   -10,  -105,    51,    70,    75,
    -105,  -105,   122,  -105,    40,    89,  -105,    -3,    67,    40,
      40,    95,   101,   119,  -105,     0,     1,     2,   132,  -105,
      99,  -105,   120,   137,   139,  -105,  -105,  -105,   122,   118,
    -105,   128,  -105,   136,  -105,  -105,    40,  -105,    79,   172,
     149,   150,  -105,  -105,  -105,  -105,  -105,  -105,     4,    91,
    -105,   490,   152,   120,   120,   162,  -105,    10,  -105,  -105,
     165,   160,   161,   175,   176,   173,   209,   223,   187,    13,
     199,    15,   402,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,   227,  -105,   172,   172,  -105,  -105,    39,  -105,    26,
      15,    15,    15,   490,  -105,  -105,   490,   201,    15,  -105,
    -105,    32,  -105,    15,   206,  -105,    15,   232,  -105,    15,
     191,   192,   205,  -105,   200,   212,   256,   262,   125,   163,
    -105,   140,    15,   306,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15,   202,   518,  -105,
     543,  -105,  -105,  -105,   236,   237,   240,   226,   233,   234,
    -105,   568,   147,   202,    11,    11,  -105,  -105,  -105,   574,
     574,   574,   574,   574,   574,     7,   595,   217,  -105,  -105,
    -105,  -105,   490,   490,   225,   228,  -105,    15,  -105,   376,
     438,    15,    15,   568,   490,   258,   259,   312,   356,   464,
    -105,  -105,   273,   274,   275,  -105,  -105,  -105
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     6,    10,    11,     0,
       0,     8,     0,     0,     1,     0,     0,     0,    20,     3,
       0,     5,     7,     0,    15,     0,    14,     0,     0,     0,
      19,     2,    35,    16,    26,     0,     9,     0,     0,    26,
      26,     0,     0,     0,    34,     0,     0,     0,     0,    25,
       0,    13,    39,     0,     0,    36,    37,    12,     0,     0,
      27,     0,    28,     0,    32,    18,     0,    17,     0,     0,
       0,     0,    33,    29,    30,    31,    24,    40,     0,     0,
      42,     0,     0,    39,    39,     0,    45,     0,    38,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    51,    52,    53,    54,    55,    56,    59,
      60,     0,    23,     0,     0,    47,    43,     0,    92,     0,
       0,     0,     0,     0,    57,    58,     0,     0,     0,    93,
      83,    90,    84,     0,     0,    86,     0,     0,    50,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
      95,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,    21,    22,    46,     0,     0,     0,     0,     0,     0,
      91,    88,     0,    82,    69,    70,    71,    72,    73,    77,
      79,    74,    76,    78,    75,    80,    81,     0,    49,    63,
      61,    62,     0,     0,     0,     0,    85,     0,    94,     0,
       0,     0,     0,    87,     0,     0,     0,     0,     0,     0,
      65,    66,     0,     0,     0,    68,    67,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,  -105,  -105,   279,   -64,  -105,   253,  -105,   276,
      29,   156,   229,  -105,   238,    88,  -105,   213,  -105,    84,
    -105,  -104,  -101,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
     -70,  -105,   -81
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    10,    11,    12,    25,    26,    17,    18,
       5,    48,    49,    43,    44,    69,    79,    80,    87,    82,
     137,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     134,   182,   135
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     111,   138,    23,    36,    78,    59,    61,    63,    13,    85,
     154,   155,   156,   157,   158,    78,   156,   157,   158,   148,
      90,   111,   149,   116,    14,   159,   160,   161,   162,   163,
     164,    90,    13,    19,    20,    28,    24,    37,   144,    60,
      62,    64,   111,    86,   142,   111,    31,   138,   138,   166,
     145,   146,   147,   130,   131,   132,   127,   117,   151,   100,
     133,   128,     1,   153,     2,    99,   168,   111,   111,   170,
     100,   101,    27,    45,    46,   127,    29,   152,   143,    47,
     128,    32,   181,    33,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    38,   209,   210,
       6,     7,     8,     9,    21,     7,     8,     9,   138,   138,
     219,    77,     7,     8,     9,    39,    34,    52,   138,    35,
      40,   111,   111,    88,     7,     8,     9,    50,   111,   111,
      90,    15,    16,   111,    55,    91,    92,   213,   111,    93,
      56,   217,   218,   154,   155,   156,   157,   158,    67,    94,
      95,    68,    96,    97,    98,    41,    42,    73,   159,   160,
     161,   162,   163,   164,    99,    57,    58,    74,    90,   100,
     101,   113,   114,    91,    92,    75,   178,    93,    65,    66,
      81,   165,   166,    70,    66,    71,    66,    94,    95,   180,
      96,    97,    98,   206,   207,    53,    54,   140,   141,    83,
      84,   115,    99,   112,   118,   119,   120,   100,   101,   154,
     155,   156,   157,   158,   179,   154,   155,   156,   157,   158,
     121,   122,   124,   123,   159,   160,   161,   162,   163,   164,
     159,   160,   161,   162,   163,   164,   125,   126,   129,   139,
     150,   169,   171,   172,   173,   197,   174,   165,   166,   200,
     201,   203,   167,   165,   166,   202,   208,   204,   175,   154,
     155,   156,   157,   158,   205,   154,   155,   156,   157,   158,
     211,   220,   221,   212,   159,   160,   161,   162,   163,   164,
     159,   160,   161,   162,   163,   164,   225,   226,   227,    22,
      51,     0,    89,    30,     0,    76,    72,   165,   166,     0,
       0,     0,   176,   165,   166,     0,     0,     0,   177,   154,
     155,   156,   157,   158,     0,   154,   155,   156,   157,   158,
       0,     0,     0,     0,   159,   160,   161,   162,   163,   164,
     159,   160,   161,   162,   163,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   166,     0,
       0,     0,   183,   165,   166,     0,     0,     0,   222,   154,
     155,   156,   157,   158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   159,   160,   161,   162,   163,   164,
       0,    90,     0,     0,     0,     0,    91,    92,     0,     0,
      93,     0,   214,   215,     0,     0,     0,   165,   166,     0,
      94,    95,   223,    96,    97,    98,     0,    90,     0,     0,
       0,     0,    91,    92,     0,    99,    93,     0,     0,     0,
     100,   101,     0,     0,     0,     0,    94,    95,     0,    96,
      97,    98,     0,     0,     0,     0,     0,     0,     0,   136,
       0,    99,     0,    90,     0,     0,   100,   101,    91,    92,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,   216,    96,    97,    98,     0,    90,
       0,     0,     0,     0,    91,    92,     0,    99,    93,     0,
       0,   224,   100,   101,     0,     0,     0,     0,    94,    95,
       0,    96,    97,    98,     0,    90,     0,     0,     0,     0,
      91,    92,     0,    99,    93,     0,     0,     0,   100,   101,
       0,     0,     0,     0,    94,    95,     0,    96,    97,    98,
       0,   154,   155,   156,   157,   158,     0,     0,     0,    99,
       0,   198,     0,     0,   100,   101,   159,   160,   161,   162,
     163,   164,     0,     0,     0,     0,   154,   155,   156,   157,
     158,     0,     0,     0,     0,     0,   199,     0,     0,   165,
     166,   159,   160,   161,   162,   163,   164,     0,     0,     0,
       0,   154,   155,   156,   157,   158,     0,   154,   155,   156,
     157,   158,     0,     0,   165,   166,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,     0,     0,     0,     0,     0,     0,   165,
     166,     0,     0,   159,   160,   161,   162,   163,   164
};

static const yytype_int16 yycheck[] =
{
      81,   102,     5,    13,    68,     5,     5,     5,    36,     5,
       3,     4,     5,     6,     7,    79,     5,     6,     7,   123,
       5,   102,   126,    13,     0,    18,    19,    20,    21,    22,
      23,     5,    36,     4,    39,    39,    39,    47,   119,    39,
      39,    39,   123,    39,     5,   126,    17,   148,   149,    42,
     120,   121,   122,    38,    39,    40,    43,    47,   128,    44,
      45,    48,    31,   133,    33,    39,   136,   148,   149,   139,
      44,    45,    45,    33,    34,    43,    39,    45,    39,    39,
      48,    45,   152,    39,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    46,   202,   203,
      32,    33,    34,    35,    32,    33,    34,    35,   209,   210,
     214,    32,    33,    34,    35,    45,    45,    50,   219,    48,
      45,   202,   203,    32,    33,    34,    35,    38,   209,   210,
       5,    33,    34,   214,    39,    10,    11,   207,   219,    14,
      39,   211,   212,     3,     4,     5,     6,     7,    49,    24,
      25,    31,    27,    28,    29,    33,    34,    39,    18,    19,
      20,    21,    22,    23,    39,    46,    47,    39,     5,    44,
      45,    83,    84,    10,    11,    39,    51,    14,    46,    47,
       8,    41,    42,    46,    47,    46,    47,    24,    25,    49,
      27,    28,    29,    46,    47,    39,    40,   113,   114,    50,
      50,    39,    39,    51,    39,    45,    45,    44,    45,     3,
       4,     5,     6,     7,    51,     3,     4,     5,     6,     7,
      45,    45,    13,    50,    18,    19,    20,    21,    22,    23,
      18,    19,    20,    21,    22,    23,    13,    50,    39,    12,
      39,     9,    51,    51,    39,    43,    46,    41,    42,    13,
      13,    25,    46,    41,    42,    15,    39,    24,    46,     3,
       4,     5,     6,     7,    30,     3,     4,     5,     6,     7,
      45,    13,    13,    45,    18,    19,    20,    21,    22,    23,
      18,    19,    20,    21,    22,    23,    13,    13,    13,    10,
      37,    -1,    79,    17,    -1,    66,    58,    41,    42,    -1,
      -1,    -1,    46,    41,    42,    -1,    -1,    -1,    46,     3,
       4,     5,     6,     7,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    -1,
      -1,    -1,    46,    41,    42,    -1,    -1,    -1,    46,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      -1,     5,    -1,    -1,    -1,    -1,    10,    11,    -1,    -1,
      14,    -1,    16,    17,    -1,    -1,    -1,    41,    42,    -1,
      24,    25,    46,    27,    28,    29,    -1,     5,    -1,    -1,
      -1,    -1,    10,    11,    -1,    39,    14,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    24,    25,    -1,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    39,    -1,     5,    -1,    -1,    44,    45,    10,    11,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,    -1,     5,
      -1,    -1,    -1,    -1,    10,    11,    -1,    39,    14,    -1,
      -1,    17,    44,    45,    -1,    -1,    -1,    -1,    24,    25,
      -1,    27,    28,    29,    -1,     5,    -1,    -1,    -1,    -1,
      10,    11,    -1,    39,    14,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    -1,    24,    25,    -1,    27,    28,    29,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    39,
      -1,    13,    -1,    -1,    44,    45,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    41,
      42,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    41,    42,    18,    19,    20,    21,
      22,    23,    18,    19,    20,    21,    22,    23,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    -1,    -1,    18,    19,    20,    21,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    33,    53,    54,    62,    32,    33,    34,    35,
      55,    56,    57,    36,     0,    33,    34,    60,    61,    62,
      39,    32,    56,     5,    39,    58,    59,    45,    39,    39,
      61,    62,    45,    39,    45,    48,    13,    47,    46,    45,
      45,    33,    34,    65,    66,    33,    34,    39,    63,    64,
      38,    59,    50,    63,    63,    39,    39,    46,    47,     5,
      39,     5,    39,     5,    39,    46,    47,    49,    31,    67,
      46,    46,    66,    39,    39,    39,    64,    32,    57,    68,
      69,     8,    71,    50,    50,     5,    39,    70,    32,    69,
       5,    10,    11,    14,    24,    25,    27,    28,    29,    39,
      44,    45,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    84,    51,    67,    67,    39,    13,    47,    39,    45,
      45,    45,    45,    50,    13,    13,    50,    43,    48,    39,
      38,    39,    40,    45,    82,    84,    37,    72,    74,    12,
      71,    71,     5,    39,    84,    82,    82,    82,    73,    73,
      39,    82,    45,    82,     3,     4,     5,     6,     7,    18,
      19,    20,    21,    22,    23,    41,    42,    46,    82,     9,
      82,    51,    51,    39,    46,    46,    46,    46,    51,    51,
      49,    82,    83,    46,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    43,    13,    13,
      13,    13,    15,    25,    24,    30,    46,    47,    39,    73,
      73,    45,    45,    82,    16,    17,    26,    82,    82,    73,
      13,    13,    46,    46,    17,    13,    13,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    53,    54,    54,    55,    55,    56,
      57,    57,    57,    58,    58,    59,    59,    59,    59,    60,
      60,    61,    61,    62,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    65,    65,    65,    66,    66,    67,    67,
      67,    68,    68,    69,    70,    70,    70,    70,    71,    72,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    76,    77,    78,    78,    79,    80,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    83,
      84,    84,    84,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       1,     1,     5,     3,     1,     1,     2,     4,     4,     2,
       1,     9,     9,     8,     3,     1,     0,     2,     2,     3,
       3,     3,     2,     3,     1,     0,     2,     2,     3,     0,
       2,     2,     1,     3,     3,     1,     4,     2,     4,     3,
       2,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     5,     5,     4,    10,     8,     8,     9,     9,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     4,     1,     3,     1,     0,
       1,     4,     2,     2,     5,     3
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
#line 77 "compiler.y"
                                                {   exitProg(output);printGST();  }
#line 1644 "y.tab.c"
    break;

  case 3:
#line 78 "compiler.y"
                                                {   exitProg(output);printGST();  }
#line 1650 "y.tab.c"
    break;

  case 4:
#line 79 "compiler.y"
                                                {   exitProg(output);printGST();  }
#line 1656 "y.tab.c"
    break;

  case 5:
#line 82 "compiler.y"
                                                {    }
#line 1662 "y.tab.c"
    break;

  case 6:
#line 83 "compiler.y"
                                                {   }
#line 1668 "y.tab.c"
    break;

  case 9:
#line 87 "compiler.y"
                                                {  }
#line 1674 "y.tab.c"
    break;

  case 10:
#line 89 "compiler.y"
                                                {   current_type = TLookup("int");          isTuple = false;    }
#line 1680 "y.tab.c"
    break;

  case 11:
#line 90 "compiler.y"
                                                {   current_type = TLookup("str");          isTuple = false;    }
#line 1686 "y.tab.c"
    break;

  case 12:
#line 91 "compiler.y"
                                                {   current_type = TInstallTuple((yyvsp[-3].node), (yyvsp[-1].fieldlist));   isTuple = true;     }
#line 1692 "y.tab.c"
    break;

  case 15:
#line 96 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[0].node), current_type, 1, 0, 0,NULL, NODE_ID, false);    }
#line 1698 "y.tab.c"
    break;

  case 16:
#line 97 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[0].node), current_type, 1, 0, 0, NULL, NODE_ID, true);    }
#line 1704 "y.tab.c"
    break;

  case 17:
#line 98 "compiler.y"
                                                {   
                                                    if(isTuple){
                                                        printf("Error: Cannot declare array of tuples\n");
                                                        exit(1);
                                                    }
                                                    GST = insertToGlobal((yyvsp[-3].node), arrType(), (yyvsp[-1].node)->value.intVal, 1, (yyvsp[-1].node)->value.intVal, NULL, NODE_ID, false); 
                                                }
#line 1716 "y.tab.c"
    break;

  case 18:
#line 105 "compiler.y"
                                                {   
                                                    if(isTuple){
                                                        printf("Error: Cannot declare function of tuples\n");
                                                        exit(1);
                                                    }

                                                    GST = insertToGlobal((yyvsp[-3].node), current_type, 0, 0, 0, (yyvsp[-1].parameter), NODE_FUNCT,false);  
                                                    clearLST();  
                                                }
#line 1730 "y.tab.c"
    break;

  case 19:
#line 117 "compiler.y"
                                                {      }
#line 1736 "y.tab.c"
    break;

  case 20:
#line 118 "compiler.y"
                                                {      }
#line 1742 "y.tab.c"
    break;

  case 21:
#line 120 "compiler.y"
                                                                            {   
                                                                                setHeader(output);  
                                                                                validateFunct(TLookup("int"), (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node)); 
                                                                                //printLST($2->name);
                                                                                generateFunct(output, (yyvsp[-7].node), (yyvsp[-1].node));
                                                                                clearLST();  
                                                                            }
#line 1754 "y.tab.c"
    break;

  case 22:
#line 127 "compiler.y"
                                                                            {   
                                                                                setHeader(output);  
                                                                                //printLST($2->name);
                                                                                validateFunct(TLookup("str"), (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node));    
                                                                                generateFunct(output, (yyvsp[-7].node), (yyvsp[-1].node));
                                                                                clearLST();  
                                                                            }
#line 1766 "y.tab.c"
    break;

  case 23:
#line 138 "compiler.y"
                                                                            {   
                                                                                setHeader(output);  
                                                                                printLST("MAIN");
                                                                                validateMain((yyvsp[-1].node));
                                                                                generateFunct(output, NULL, (yyvsp[-1].node));
                                                                                clearLST();
                                                                            }
#line 1778 "y.tab.c"
    break;

  case 24:
#line 149 "compiler.y"
                                        {   (yyval.parameter) = appendParam((yyvsp[-2].parameter), (yyvsp[0].parameter)); }
#line 1784 "y.tab.c"
    break;

  case 25:
#line 150 "compiler.y"
                                        {   (yyval.parameter) = (yyvsp[0].parameter); }
#line 1790 "y.tab.c"
    break;

  case 26:
#line 151 "compiler.y"
                                        {   (yyval.parameter) = NULL; }
#line 1796 "y.tab.c"
    break;

  case 27:
#line 153 "compiler.y"
                                        {   (yyval.parameter) = createParam("int", (yyvsp[0].node), false);   }
#line 1802 "y.tab.c"
    break;

  case 28:
#line 154 "compiler.y"
                                        {   (yyval.parameter) = createParam("str", (yyvsp[0].node), false);   }
#line 1808 "y.tab.c"
    break;

  case 29:
#line 155 "compiler.y"
                                        {   (yyval.parameter) = createParam("int", (yyvsp[0].node), true);   }
#line 1814 "y.tab.c"
    break;

  case 30:
#line 156 "compiler.y"
                                        {   (yyval.parameter) = createParam("str", (yyvsp[0].node), true);   }
#line 1820 "y.tab.c"
    break;

  case 31:
#line 157 "compiler.y"
                                        {   (yyval.parameter) = createParam((yyvsp[-2].node)->name, (yyvsp[0].node), true);  }
#line 1826 "y.tab.c"
    break;

  case 32:
#line 158 "compiler.y"
                                        {   (yyval.parameter) = createParam((yyvsp[-1].node)->name, (yyvsp[0].node), false); }
#line 1832 "y.tab.c"
    break;

  case 33:
#line 163 "compiler.y"
                                        {   (yyval.fieldlist) = appendField((yyvsp[-2].fieldlist), (yyvsp[0].fieldlist)); }
#line 1838 "y.tab.c"
    break;

  case 34:
#line 164 "compiler.y"
                                        {   (yyval.fieldlist) = (yyvsp[0].fieldlist); }
#line 1844 "y.tab.c"
    break;

  case 35:
#line 165 "compiler.y"
                                        {   (yyval.fieldlist) = NULL; }
#line 1850 "y.tab.c"
    break;

  case 36:
#line 167 "compiler.y"
                                        {   (yyval.fieldlist) = createField(TLookup("int"), (yyvsp[0].node));   }
#line 1856 "y.tab.c"
    break;

  case 37:
#line 168 "compiler.y"
                                        {   (yyval.fieldlist) = createField(TLookup("str"), (yyvsp[0].node));   }
#line 1862 "y.tab.c"
    break;

  case 38:
#line 173 "compiler.y"
                                                    {  }
#line 1868 "y.tab.c"
    break;

  case 41:
#line 177 "compiler.y"
                                                    {  }
#line 1874 "y.tab.c"
    break;

  case 42:
#line 178 "compiler.y"
                                                    {  }
#line 1880 "y.tab.c"
    break;

  case 43:
#line 180 "compiler.y"
                                                    {  }
#line 1886 "y.tab.c"
    break;

  case 44:
#line 182 "compiler.y"
                                                    {   LST = createLST((yyvsp[0].node), current_type, false);   }
#line 1892 "y.tab.c"
    break;

  case 45:
#line 183 "compiler.y"
                                                    {   LST = createLST((yyvsp[0].node), current_type, false);   }
#line 1898 "y.tab.c"
    break;

  case 46:
#line 184 "compiler.y"
                                                    {   LST = createLST((yyvsp[0].node), current_type, true);   }
#line 1904 "y.tab.c"
    break;

  case 47:
#line 185 "compiler.y"
                                                    {   LST = createLST((yyvsp[0].node), current_type, true);    }
#line 1910 "y.tab.c"
    break;

  case 48:
#line 190 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_CONNECTOR, (yyvsp[-2].node), (yyvsp[-1].node));    }
#line 1916 "y.tab.c"
    break;

  case 49:
#line 192 "compiler.y"
                                                    {   (yyval.node) = createRtnNode((yyvsp[-1].node)); }
#line 1922 "y.tab.c"
    break;

  case 50:
#line 194 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_CONNECTOR, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1928 "y.tab.c"
    break;

  case 51:
#line 195 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1934 "y.tab.c"
    break;

  case 52:
#line 197 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1940 "y.tab.c"
    break;

  case 53:
#line 198 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1946 "y.tab.c"
    break;

  case 54:
#line 199 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1952 "y.tab.c"
    break;

  case 55:
#line 200 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1958 "y.tab.c"
    break;

  case 56:
#line 201 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1964 "y.tab.c"
    break;

  case 57:
#line 202 "compiler.y"
                                                    {   (yyval.node) = createControlFlowNode(NODE_BREAK); }
#line 1970 "y.tab.c"
    break;

  case 58:
#line 203 "compiler.y"
                                                    {   (yyval.node) = createControlFlowNode(NODE_CONTINUE); }
#line 1976 "y.tab.c"
    break;

  case 59:
#line 204 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1982 "y.tab.c"
    break;

  case 60:
#line 205 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1988 "y.tab.c"
    break;

  case 61:
#line 207 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_READ, (yyvsp[-2].node), NULL);   }
#line 1994 "y.tab.c"
    break;

  case 62:
#line 209 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_WRITE, (yyvsp[-2].node), NULL);     }
#line 2000 "y.tab.c"
    break;

  case 63:
#line 211 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_ASSIGN, (yyvsp[-3].node), (yyvsp[-1].node));    }
#line 2006 "y.tab.c"
    break;

  case 64:
#line 214 "compiler.y"
                                                                 {  (yyval.node) = createIfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));  }
#line 2012 "y.tab.c"
    break;

  case 65:
#line 215 "compiler.y"
                                                                 {  (yyval.node) = createIfNode((yyvsp[-5].node), (yyvsp[-2].node), NULL); }
#line 2018 "y.tab.c"
    break;

  case 66:
#line 217 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_WHILE, (yyvsp[-5].node), (yyvsp[-2].node));   }
#line 2024 "y.tab.c"
    break;

  case 67:
#line 219 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_RPTUTL, (yyvsp[-2].node), (yyvsp[-6].node));   }
#line 2030 "y.tab.c"
    break;

  case 68:
#line 221 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_DOWHILE, (yyvsp[-2].node), (yyvsp[-6].node));   }
#line 2036 "y.tab.c"
    break;

  case 69:
#line 224 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2042 "y.tab.c"
    break;

  case 70:
#line 225 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2048 "y.tab.c"
    break;

  case 71:
#line 226 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2054 "y.tab.c"
    break;

  case 72:
#line 227 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2060 "y.tab.c"
    break;

  case 73:
#line 228 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2066 "y.tab.c"
    break;

  case 74:
#line 229 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_EQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2072 "y.tab.c"
    break;

  case 75:
#line 230 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_NE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2078 "y.tab.c"
    break;

  case 76:
#line 231 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_GT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2084 "y.tab.c"
    break;

  case 77:
#line 232 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_GE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2090 "y.tab.c"
    break;

  case 78:
#line 233 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_LT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2096 "y.tab.c"
    break;

  case 79:
#line 234 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_LE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2102 "y.tab.c"
    break;

  case 80:
#line 235 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2108 "y.tab.c"
    break;

  case 81:
#line 236 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2114 "y.tab.c"
    break;

  case 82:
#line 237 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[-1].node);    }
#line 2120 "y.tab.c"
    break;

  case 83:
#line 238 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2126 "y.tab.c"
    break;

  case 84:
#line 239 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);   }
#line 2132 "y.tab.c"
    break;

  case 85:
#line 240 "compiler.y"
                                                    {   (yyval.node) = createFunctNode((yyvsp[-3].node), (yyvsp[-1].node));   }
#line 2138 "y.tab.c"
    break;

  case 86:
#line 241 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2144 "y.tab.c"
    break;

  case 87:
#line 243 "compiler.y"
                                                    {   (yyval.node) = appendArgNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2150 "y.tab.c"
    break;

  case 88:
#line 244 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2156 "y.tab.c"
    break;

  case 89:
#line 245 "compiler.y"
                                                    {   (yyval.node) = NULL;  }
#line 2162 "y.tab.c"
    break;

  case 90:
#line 248 "compiler.y"
                                                    { setType((yyvsp[0].node)); (yyval.node) = (yyvsp[0].node); }
#line 2168 "y.tab.c"
    break;

  case 91:
#line 249 "compiler.y"
                                                    { (yyval.node) = createArrayNode((yyvsp[-3].node), NULL, (yyvsp[-1].node)); }
#line 2174 "y.tab.c"
    break;

  case 92:
#line 250 "compiler.y"
                                                    { (yyval.node) = createDerefNode((yyvsp[0].node)); }
#line 2180 "y.tab.c"
    break;

  case 93:
#line 251 "compiler.y"
                                                    { (yyval.node) = createAddrNode((yyvsp[0].node)); }
#line 2186 "y.tab.c"
    break;

  case 94:
#line 252 "compiler.y"
                                                    { (yyval.node) = createTupleNode((yyvsp[-3].node), (yyvsp[0].node)); }
#line 2192 "y.tab.c"
    break;

  case 95:
#line 253 "compiler.y"
                                                    { (yyval.node) = createTupleNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2198 "y.tab.c"
    break;


#line 2202 "y.tab.c"

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
#line 256 "compiler.y"


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
