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
    #include "./classTable/class.h"

    int yyerror();
    int yylex();

    FILE *output;

    struct GSymbol* GST = NULL;
    struct LSymbol* LST = NULL;
    struct Typetable* current_type;
    struct Classtable* current_class;

    bool isInsideClass = false;



#line 96 "compiler.tab.c"

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
    CLASS = 297,
    ENDCLASS = 298,
    EXTENDS = 299,
    NEW = 300,
    DELETE = 301,
    RETURN = 302,
    NUM = 303,
    ID = 304,
    STR_LITERAL = 305,
    SELF = 306,
    OR = 307,
    AND = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "compiler.y"

    struct ASTNode* node;
    struct param* parameter;
    struct LSymbol* localSymbolTable;
    struct Arglist* Args;
    struct Fieldlist* fieldlist;
    int type;

#line 208 "compiler.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
#define YYLAST   634

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  295

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      57,    58,     2,     2,    59,     2,    54,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    79,    80,    85,    85,    85,    86,    88,
      89,    91,    93,    94,    96,    97,    99,   101,   102,   104,
     106,   107,   112,   113,   116,   117,   120,   120,   123,   124,
     127,   131,   132,   134,   135,   136,   138,   139,   140,   142,
     143,   145,   146,   147,   148,   154,   155,   157,   165,   173,
     185,   195,   196,   197,   199,   200,   201,   202,   203,   204,
     209,   210,   211,   213,   214,   216,   218,   219,   220,   221,
     226,   228,   230,   231,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   245,   247,   249,   250,   251,
     253,   254,   258,   259,   261,   263,   265,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   288,   289,   290,   292,
     293,   294
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
  "NULL_VAL", "CLASS", "ENDCLASS", "EXTENDS", "NEW", "DELETE", "RETURN",
  "NUM", "ID", "STR_LITERAL", "SELF", "OR", "AND", "'.'", "'{'", "'}'",
  "'('", "')'", "','", "'['", "']'", "$accept", "program", "ClassDefBlock",
  "$@1", "$@2", "ClassDefList", "ClassDef", "Cname", "Fieldlists", "Fld",
  "MethodDecl", "MDecl", "MethodDefns", "TypeDefBlock", "TypeDefList",
  "TypeDef", "$@3", "FieldDeclList", "FieldDecl", "GDeclBlock",
  "GDeclList", "GDecl", "Type", "GidList", "Gid", "FDefBlock", "Fdef",
  "MainBlock", "ParamList", "Param", "LDeclBlock", "LDeclList", "LDecl",
  "IdList", "Coderegion", "RtnStmt", "Slist", "Stmt", "InputStmt",
  "OutputStmt", "AsgnStmt", "IfStmt", "WhileStmt", "RptUntlStmt",
  "DoWhileStmt", "expr", "IDENTIFIERS", "ArgList", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    46,   123,   125,    40,    41,    44,
      91,    93
};
# endif

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -32,    84,    51,  -166,    42,  -166,  -166,  -166,    18,
      87,  -166,  -166,    47,    -8,    97,    94,  -166,   170,    69,
      47,  -166,   129,  -166,  -166,  -166,  -166,    77,  -166,    -2,
      72,   -19,   160,   163,    94,  -166,  -166,   -20,  -166,   178,
     197,   182,  -166,   216,  -166,  -166,   204,   -45,    -6,  -166,
     196,   198,   205,   214,  -166,  -166,  -166,  -166,   259,  -166,
    -166,  -166,  -166,   177,   229,  -166,    -2,   223,   177,   177,
     177,  -166,   170,    26,    27,    28,   -37,  -166,   218,  -166,
     250,   -13,    41,    58,  -166,    88,  -166,   233,   239,  -166,
     240,  -166,   244,  -166,  -166,   177,  -166,   153,   279,   246,
     247,   254,   181,  -166,   251,    21,  -166,  -166,  -166,  -166,
    -166,    33,   156,  -166,   552,   243,   250,   250,   250,   261,
      74,  -166,   237,  -166,   177,   262,  -166,    -5,  -166,  -166,
     255,   256,   258,   260,   263,   282,   303,   275,   274,   276,
     -10,  -166,   462,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,   320,  -166,   279,   279,   279,  -166,  -166,    66,  -166,
    -166,    34,    99,    90,    90,    90,   552,  -166,  -166,   552,
      99,   285,   291,    90,    90,   328,  -166,   235,   283,   295,
     296,   325,   306,  -166,   297,   298,  -166,  -166,  -166,    90,
     148,   302,   155,   176,   378,   411,   300,   314,   316,    83,
     301,  -166,   319,   321,   323,   322,  -166,  -166,  -166,  -166,
    -166,   347,   217,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,   366,    90,   362,   356,
     367,   360,   380,  -166,   345,  -166,  -166,   339,   340,   350,
    -166,  -166,  -166,   186,   186,  -166,  -166,  -166,   590,   590,
     590,   590,   590,   590,   364,   611,  -166,   343,   105,   552,
     552,   344,   351,  -166,   342,   391,   396,   352,  -166,    90,
     454,   496,    90,    90,   398,  -166,  -166,   399,   343,   552,
     400,   401,   238,   245,  -166,  -166,   524,  -166,  -166,   402,
     403,   406,  -166,  -166,  -166
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      23,     0,     0,     8,    26,     0,    25,     1,     5,     0,
       0,    22,    24,     0,     0,     0,     0,     4,     0,    12,
       6,    10,     0,    32,    36,    37,    38,     0,    34,     0,
       0,     0,     0,     0,     0,    46,     3,     0,    29,     0,
       0,     0,     9,     0,    31,    33,     0,    41,     0,    40,
       0,     0,     0,     0,    45,     2,    27,    28,     0,    13,
       7,    15,    42,    53,     0,    35,     0,     0,    53,    53,
      53,    30,     0,     0,     0,     0,     0,    52,     0,    39,
      62,     0,     0,     0,    14,     0,    18,     0,     0,    54,
       0,    55,     0,    59,    44,     0,    43,     0,     0,     0,
       0,     0,     0,    17,     0,     0,    56,    57,    58,    51,
      61,     0,     0,    64,     0,     0,    62,    62,    62,     0,
       0,    21,     0,    16,    53,     0,    67,     0,    60,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,     0,    73,    74,    75,    76,    77,    78,    81,
      82,     0,    50,     0,     0,     0,    11,    20,     0,    69,
      65,     0,     0,     0,     0,     0,     0,    79,    80,     0,
       0,     0,     0,     0,     0,     0,    72,     0,     0,     0,
       0,     0,     0,    66,   116,     0,   115,   111,   112,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,     0,    47,    48,    49,    19,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,     0,     0,    84,     0,   118,    71,     0,     0,     0,
      87,    85,   110,    97,    98,    99,   100,   101,   105,   107,
     102,   104,   106,   103,   108,   109,    86,   120,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,    88,    89,     0,   119,     0,
       0,     0,     0,     0,    90,    91,     0,    93,    94,     0,
       0,     0,    96,    95,    92
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,  -166,  -166,  -166,   408,  -166,  -166,  -166,
    -166,   335,  -166,  -166,  -166,   418,  -166,  -166,   389,  -166,
    -166,   404,     0,  -166,   371,  -166,   -28,    -7,   -26,   337,
     100,  -166,   318,  -166,    78,  -166,  -165,  -137,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -154,  -114,  -166
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    13,    41,    20,    21,    22,    72,    84,
      85,    86,   120,     3,     5,     6,    10,    37,    38,    16,
      27,    28,    29,    48,    49,    34,    35,    17,    76,    77,
      98,   112,   113,   127,   115,   175,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   190,   191,   258
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     151,   194,   172,    46,   195,   176,    54,    65,   160,    36,
     192,   193,    63,    24,    25,    64,    30,     4,    39,   199,
     200,    94,    95,   205,    23,    24,    25,    55,   151,    26,
      51,    88,    90,    92,   123,   212,    56,    39,   125,   182,
       1,    26,    81,    82,    83,    99,    95,    47,   185,    14,
     173,    15,   151,    66,   161,   151,   196,   176,   176,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    87,   257,   121,    89,    91,    93,   124,    11,
     151,   151,   126,   183,     7,   104,   213,   214,   215,   216,
     217,     4,   157,     8,   270,   271,    19,   111,   158,   100,
      95,   218,   219,   220,   221,   222,   223,   119,    32,    44,
      24,    25,   111,    40,   286,   278,   101,    95,   282,   283,
     102,    24,    25,    33,   181,    95,    26,    31,    32,    50,
     156,   186,    30,   176,   176,   224,   225,    26,   187,   184,
     188,   141,    18,    33,   235,   151,   151,   189,   184,   176,
     141,   213,   214,   215,   216,   217,   151,   151,   213,   214,
     215,   216,   217,   268,   269,   151,   218,   219,   220,   221,
     222,   223,   151,   218,   219,   220,   221,   222,   223,   213,
     214,   215,   216,   217,    43,   110,    24,    25,   128,    24,
      25,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    26,    24,    25,    26,   226,   224,   225,    52,
      73,    74,    53,   228,   119,    32,   153,   154,   155,    26,
     213,   214,   215,   216,   217,    60,    75,    58,   224,   225,
      33,   178,   179,   180,   229,   218,   219,   220,   221,   222,
     223,   213,   214,   215,   216,   217,    59,    61,   213,   214,
     215,   216,   217,    62,    67,    68,   218,   219,   220,   221,
     222,   223,    69,   218,   219,   220,   221,   222,   223,   224,
     225,    70,    71,   202,   203,   242,   186,    78,    80,    96,
     204,    97,   105,   187,   184,   188,   141,   114,   106,   107,
     224,   225,   189,   108,   124,   167,   289,   224,   225,   152,
     122,   116,   117,   290,   213,   214,   215,   216,   217,   118,
      51,   159,   162,   163,   236,   164,   168,   165,   166,   218,
     219,   220,   221,   222,   223,   213,   214,   215,   216,   217,
     169,   170,   177,   171,   197,   240,   198,   201,   209,   206,
     218,   219,   220,   221,   222,   223,   213,   214,   215,   216,
     217,   207,   208,   224,   225,   210,   211,   173,   232,   227,
     241,   218,   219,   220,   221,   222,   223,   213,   214,   215,
     216,   217,   233,   234,   224,   225,   237,   259,   238,   256,
     239,   260,   218,   219,   220,   221,   222,   223,   130,   131,
     262,   261,   132,   263,   264,   224,   225,   265,   266,   267,
     274,   272,   133,   134,   275,   135,   136,   137,   273,   276,
     277,   284,   285,   287,   288,   292,   293,   225,   138,   294,
     103,   130,   131,    12,   139,   132,    57,   140,    42,   141,
     129,    45,   109,     0,   230,   133,   134,    79,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,     0,     0,     0,   139,     0,     0,
     140,     0,   141,     0,   130,   131,     0,   231,   132,     0,
     279,   280,   130,   131,     0,     0,   132,     0,   133,   134,
       0,   135,   136,   137,     0,     0,   133,   134,     0,   135,
     136,   137,     0,     0,   138,     0,     0,     0,     0,     0,
     139,     0,   138,   140,     0,   141,   130,   131,   139,   174,
     132,   140,     0,   141,     0,     0,     0,     0,     0,     0,
     133,   134,   281,   135,   136,   137,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   131,   138,     0,   132,     0,
       0,   291,   139,     0,     0,   140,     0,   141,   133,   134,
       0,   135,   136,   137,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,   138,     0,   132,     0,     0,     0,
     139,     0,     0,   140,     0,   141,   133,   134,     0,   135,
     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   213,   214,   215,   216,   217,   139,     0,
       0,   140,     0,   141,     0,     0,     0,     0,    -1,    -1,
      -1,    -1,    -1,    -1,   213,   214,   215,   216,   217,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   218,
     219,   220,   221,   222,   223
};

static const yytype_int16 yycheck[] =
{
     114,   166,    12,     5,   169,   142,    34,    13,    13,    16,
     164,   165,    57,    33,    34,    60,    35,    49,    18,   173,
     174,    58,    59,   177,    32,    33,    34,    34,   142,    49,
      49,     5,     5,     5,    13,   189,    56,    37,     5,     5,
      36,    49,    68,    69,    70,    58,    59,    49,   162,    31,
      60,    33,   166,    59,    59,   169,   170,   194,   195,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    72,   227,   102,    49,    49,    49,    57,    37,
     194,   195,    49,    49,     0,    85,     3,     4,     5,     6,
       7,    49,   120,    42,   259,   260,    49,    97,   124,    58,
      59,    18,    19,    20,    21,    22,    23,    33,    34,    32,
      33,    34,   112,    44,   279,   269,    58,    59,   272,   273,
      32,    33,    34,    49,    58,    59,    49,    33,    34,    57,
      56,    41,    35,   270,   271,    52,    53,    49,    48,    49,
      50,    51,    55,    49,    61,   259,   260,    57,    49,   286,
      51,     3,     4,     5,     6,     7,   270,   271,     3,     4,
       5,     6,     7,    58,    59,   279,    18,    19,    20,    21,
      22,    23,   286,    18,    19,    20,    21,    22,    23,     3,
       4,     5,     6,     7,    55,    32,    33,    34,    32,    33,
      34,     5,     6,     7,    18,    19,    20,    21,    22,    23,
      52,    53,    49,    33,    34,    49,    58,    52,    53,    49,
      33,    34,    49,    58,    33,    34,   116,   117,   118,    49,
       3,     4,     5,     6,     7,    43,    49,    49,    52,    53,
      49,   153,   154,   155,    58,    18,    19,    20,    21,    22,
      23,     3,     4,     5,     6,     7,    49,    31,     3,     4,
       5,     6,     7,    49,    58,    57,    18,    19,    20,    21,
      22,    23,    57,    18,    19,    20,    21,    22,    23,    52,
      53,    57,    13,    38,    39,    58,    41,    48,    55,    61,
      45,    31,    49,    48,    49,    50,    51,     8,    49,    49,
      52,    53,    57,    49,    57,    13,    58,    52,    53,    56,
      49,    55,    55,    58,     3,     4,     5,     6,     7,    55,
      49,    49,    57,    57,    13,    57,    13,    57,    55,    18,
      19,    20,    21,    22,    23,     3,     4,     5,     6,     7,
      55,    57,    12,    57,    49,    13,    45,     9,    13,    56,
      18,    19,    20,    21,    22,    23,     3,     4,     5,     6,
       7,    56,    56,    52,    53,    49,    58,    60,    58,    57,
      13,    18,    19,    20,    21,    22,    23,     3,     4,     5,
       6,     7,    58,    57,    52,    53,    57,    15,    57,    13,
      57,    25,    18,    19,    20,    21,    22,    23,    10,    11,
      30,    24,    14,    13,    49,    52,    53,    58,    58,    49,
      58,    57,    24,    25,    13,    27,    28,    29,    57,    13,
      58,    13,    13,    13,    13,    13,    13,    53,    40,    13,
      85,    10,    11,     5,    46,    14,    37,    49,    20,    51,
     112,    27,    95,    -1,    56,    24,    25,    66,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      49,    -1,    51,    -1,    10,    11,    -1,    56,    14,    -1,
      16,    17,    10,    11,    -1,    -1,    14,    -1,    24,    25,
      -1,    27,    28,    29,    -1,    -1,    24,    25,    -1,    27,
      28,    29,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    40,    49,    -1,    51,    10,    11,    46,    47,
      14,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    11,    40,    -1,    14,    -1,
      -1,    17,    46,    -1,    -1,    49,    -1,    51,    24,    25,
      -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    11,    40,    -1,    14,    -1,    -1,    -1,
      46,    -1,    -1,    49,    -1,    51,    24,    25,    -1,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,     3,     4,     5,     6,     7,    46,    -1,
      -1,    49,    -1,    51,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    63,    75,    49,    76,    77,     0,    42,    64,
      78,    37,    77,    65,    31,    33,    81,    89,    55,    49,
      67,    68,    69,    32,    33,    34,    49,    82,    83,    84,
      35,    33,    34,    49,    87,    88,    89,    79,    80,    84,
      44,    66,    68,    55,    32,    83,     5,    49,    85,    86,
      57,    49,    49,    49,    88,    89,    56,    80,    49,    49,
      43,    31,    49,    57,    60,    13,    59,    58,    57,    57,
      57,    13,    70,    33,    34,    49,    90,    91,    48,    86,
      55,    90,    90,    90,    71,    72,    73,    84,     5,    49,
       5,    49,     5,    49,    58,    59,    61,    31,    92,    58,
      58,    58,    32,    73,    84,    49,    49,    49,    49,    91,
      32,    84,    93,    94,     8,    96,    55,    55,    55,    33,
      74,    88,    49,    13,    57,     5,    49,    95,    32,    94,
      10,    11,    14,    24,    25,    27,    28,    29,    40,    46,
      49,    51,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   108,    56,    92,    92,    92,    56,    88,    90,    49,
      13,    59,    57,    57,    57,    57,    55,    13,    13,    55,
      57,    57,    12,    60,    47,    97,    99,    12,    96,    96,
      96,    58,     5,    49,    49,   108,    41,    48,    50,    57,
     107,   108,   107,   107,    98,    98,   108,    49,    45,   107,
     107,     9,    38,    39,    45,   107,    56,    56,    56,    13,
      49,    58,   107,     3,     4,     5,     6,     7,    18,    19,
      20,    21,    22,    23,    52,    53,    58,    57,    58,    58,
      56,    56,    58,    58,    57,    61,    13,    57,    57,    57,
      13,    13,    58,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,    13,   107,   109,    15,
      25,    24,    30,    13,    49,    58,    58,    49,    58,    59,
      98,    98,    57,    57,    58,    13,    13,    58,   107,    16,
      17,    26,   107,   107,    13,    13,    98,    13,    13,    58,
      58,    17,    13,    13,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    63,    65,    66,    64,    64,    67,
      67,    68,    69,    69,    70,    70,    71,    72,    72,    73,
      74,    74,    75,    75,    76,    76,    78,    77,    79,    79,
      80,    81,    81,    82,    82,    83,    84,    84,    84,    85,
      85,    86,    86,    86,    86,    87,    87,    88,    88,    88,
      89,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      92,    92,    92,    93,    93,    94,    95,    95,    95,    95,
      96,    97,    98,    98,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,   100,   101,   102,   102,   102,
     102,   102,   103,   103,   104,   105,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   108,   108,   108,   109,
     109,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     0,     0,     5,     0,     2,
       1,     8,     1,     3,     2,     0,     3,     2,     1,     6,
       2,     1,     3,     0,     2,     1,     0,     5,     2,     1,
       3,     3,     2,     2,     1,     3,     1,     1,     1,     3,
       1,     1,     2,     4,     4,     2,     1,     9,     9,     9,
       8,     3,     1,     0,     2,     2,     3,     3,     3,     2,
       3,     2,     0,     2,     1,     3,     3,     1,     4,     2,
       4,     3,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     5,     4,     5,     5,     4,     6,     6,
       7,     7,    10,     8,     8,     9,     9,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     4,     1,     1,     1,     4,     3,
       1,     0
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
#line 78 "compiler.y"
                                                                           {   exitProg(output);PrintClassTable();  }
#line 1652 "compiler.tab.c"
    break;

  case 3:
#line 79 "compiler.y"
                                                                           {   exitProg(output);PrintClassTable();  }
#line 1658 "compiler.tab.c"
    break;

  case 4:
#line 80 "compiler.y"
                                                                           {   exitProg(output);PrintClassTable();  }
#line 1664 "compiler.tab.c"
    break;

  case 5:
#line 85 "compiler.y"
                        { isInsideClass = true;  }
#line 1670 "compiler.tab.c"
    break;

  case 6:
#line 85 "compiler.y"
                                                                 {  isInsideClass = false;  }
#line 1676 "compiler.tab.c"
    break;

  case 12:
#line 93 "compiler.y"
                                                                                {   current_class = CInstall((yyvsp[0].node)->name, NULL);}
#line 1682 "compiler.tab.c"
    break;

  case 13:
#line 94 "compiler.y"
                                                                            {   current_class = CInstall((yyvsp[-2].node)->name, (yyvsp[0].node)->name);}
#line 1688 "compiler.tab.c"
    break;

  case 16:
#line 99 "compiler.y"
                                                                                {   ClassFInstall(current_class, current_type, (yyvsp[-1].node)->name);}
#line 1694 "compiler.tab.c"
    break;

  case 19:
#line 104 "compiler.y"
                                                                            {   ClassMInstall(current_class, current_type, (yyvsp[-4].node)->name,(yyvsp[-2].parameter)); }
#line 1700 "compiler.tab.c"
    break;

  case 26:
#line 120 "compiler.y"
                        { TInstall((yyvsp[0].node)->name, 0, NULL, TYPE_USERDEF); }
#line 1706 "compiler.tab.c"
    break;

  case 27:
#line 120 "compiler.y"
                                                                                               {   updateUserDefined((yyvsp[-4].node)->name, (yyvsp[-1].fieldlist)); }
#line 1712 "compiler.tab.c"
    break;

  case 28:
#line 123 "compiler.y"
                                                  {   (yyval.fieldlist) = appendField((yyvsp[-1].fieldlist), (yyvsp[0].fieldlist));   }
#line 1718 "compiler.tab.c"
    break;

  case 29:
#line 124 "compiler.y"
                                                  {   (yyval.fieldlist) = (yyvsp[0].fieldlist); }
#line 1724 "compiler.tab.c"
    break;

  case 30:
#line 127 "compiler.y"
                                              {   (yyval.fieldlist) = createField(current_type, (yyvsp[-1].node)); }
#line 1730 "compiler.tab.c"
    break;

  case 31:
#line 131 "compiler.y"
                                                {   }
#line 1736 "compiler.tab.c"
    break;

  case 32:
#line 132 "compiler.y"
                                                {   }
#line 1742 "compiler.tab.c"
    break;

  case 35:
#line 136 "compiler.y"
                                                {  }
#line 1748 "compiler.tab.c"
    break;

  case 36:
#line 138 "compiler.y"
                                                {   current_type = TLookup("int");      }
#line 1754 "compiler.tab.c"
    break;

  case 37:
#line 139 "compiler.y"
                                                {   current_type = TLookup("str");      }
#line 1760 "compiler.tab.c"
    break;

  case 38:
#line 140 "compiler.y"
                                                {   current_type = TLookup((yyvsp[0].node)->name);   }
#line 1766 "compiler.tab.c"
    break;

  case 41:
#line 145 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[0].node), current_type, 1, 0, 0,NULL, NODE_ID, false);    }
#line 1772 "compiler.tab.c"
    break;

  case 42:
#line 146 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[0].node), current_type, 1, 0, 0, NULL, NODE_ID, true);    }
#line 1778 "compiler.tab.c"
    break;

  case 43:
#line 147 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[-3].node), current_type, (yyvsp[-1].node)->value.intVal, 1, (yyvsp[-1].node)->value.intVal, NULL, NODE_ID, false);   }
#line 1784 "compiler.tab.c"
    break;

  case 44:
#line 148 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[-3].node), current_type, 0, 0, 0, (yyvsp[-1].parameter), NODE_FUNCT,false);  
                                                    clearLST();  
                                                }
#line 1792 "compiler.tab.c"
    break;

  case 45:
#line 154 "compiler.y"
                                                {      }
#line 1798 "compiler.tab.c"
    break;

  case 46:
#line 155 "compiler.y"
                                                {      }
#line 1804 "compiler.tab.c"
    break;

  case 47:
#line 157 "compiler.y"
                                                                            {   
                                                                                if(isInsideClass)
                                                                                    validateMethod(current_class, (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node)); 
                                                                                else
                                                                                    validateFunct(TLookup("int"), (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node)); 
                                                                                generateFunct(output, (yyvsp[-7].node), (yyvsp[-1].node));
                                                                                clearLST();  
                                                                            }
#line 1817 "compiler.tab.c"
    break;

  case 48:
#line 165 "compiler.y"
                                                                            {   
                                                                                if(isInsideClass)
                                                                                    validateMethod(current_class, (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node)); 
                                                                                else
                                                                                    validateFunct(TLookup("int"), (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node)); 
                                                                                generateFunct(output, (yyvsp[-7].node), (yyvsp[-1].node));
                                                                                clearLST();  
                                                                            }
#line 1830 "compiler.tab.c"
    break;

  case 49:
#line 173 "compiler.y"
                                                                            {   
                                                                                if(isInsideClass)
                                                                                    validateMethod(current_class, (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node)); 
                                                                                else
                                                                                    validateFunct(TLookup((yyvsp[-8].node)->name), (yyvsp[-7].node), (yyvsp[-5].parameter), (yyvsp[-1].node)); 
                                                                                generateFunct(output, (yyvsp[-7].node), (yyvsp[-1].node));
                                                                                clearLST();  
                                                                            }
#line 1843 "compiler.tab.c"
    break;

  case 50:
#line 185 "compiler.y"
                                                                            {   
                                                                                setHeader(output);  
                                                                                validateMain((yyvsp[-1].node));
                                                                                generateFunct(output, NULL, (yyvsp[-1].node));
                                                                                clearLST();
                                                                            }
#line 1854 "compiler.tab.c"
    break;

  case 51:
#line 195 "compiler.y"
                                        {   (yyval.parameter) = appendParam((yyvsp[-2].parameter), (yyvsp[0].parameter)); }
#line 1860 "compiler.tab.c"
    break;

  case 52:
#line 196 "compiler.y"
                                        {   (yyval.parameter) = (yyvsp[0].parameter); }
#line 1866 "compiler.tab.c"
    break;

  case 53:
#line 197 "compiler.y"
                                        {   (yyval.parameter) = NULL; }
#line 1872 "compiler.tab.c"
    break;

  case 54:
#line 199 "compiler.y"
                                        {   (yyval.parameter) = createParam("int", (yyvsp[0].node), false);   }
#line 1878 "compiler.tab.c"
    break;

  case 55:
#line 200 "compiler.y"
                                        {   (yyval.parameter) = createParam("str", (yyvsp[0].node), false);   }
#line 1884 "compiler.tab.c"
    break;

  case 56:
#line 201 "compiler.y"
                                        {   (yyval.parameter) = createParam("int", (yyvsp[0].node), true);   }
#line 1890 "compiler.tab.c"
    break;

  case 57:
#line 202 "compiler.y"
                                        {   (yyval.parameter) = createParam("str", (yyvsp[0].node), true);   }
#line 1896 "compiler.tab.c"
    break;

  case 58:
#line 203 "compiler.y"
                                        {   (yyval.parameter) = createParam((yyvsp[-2].node)->name, (yyvsp[0].node), true);  }
#line 1902 "compiler.tab.c"
    break;

  case 59:
#line 204 "compiler.y"
                                        {   (yyval.parameter) = createParam((yyvsp[-1].node)->name, (yyvsp[0].node), false); }
#line 1908 "compiler.tab.c"
    break;

  case 60:
#line 209 "compiler.y"
                                                    {  }
#line 1914 "compiler.tab.c"
    break;

  case 63:
#line 213 "compiler.y"
                                                    {  }
#line 1920 "compiler.tab.c"
    break;

  case 64:
#line 214 "compiler.y"
                                                    {  }
#line 1926 "compiler.tab.c"
    break;

  case 65:
#line 216 "compiler.y"
                                                    {  }
#line 1932 "compiler.tab.c"
    break;

  case 66:
#line 218 "compiler.y"
                                                    {   LST = createLST((yyvsp[0].node), current_type, false);   }
#line 1938 "compiler.tab.c"
    break;

  case 67:
#line 219 "compiler.y"
                                                    {   LST = createLST((yyvsp[0].node), current_type, false);   }
#line 1944 "compiler.tab.c"
    break;

  case 68:
#line 220 "compiler.y"
                                                    {   LST = createLST((yyvsp[0].node), current_type, true);   }
#line 1950 "compiler.tab.c"
    break;

  case 69:
#line 221 "compiler.y"
                                                    {   LST = createLST((yyvsp[0].node), current_type, true);    }
#line 1956 "compiler.tab.c"
    break;

  case 70:
#line 226 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_CONNECTOR, (yyvsp[-2].node), (yyvsp[-1].node));    }
#line 1962 "compiler.tab.c"
    break;

  case 71:
#line 228 "compiler.y"
                                                    {   (yyval.node) = createRtnNode((yyvsp[-1].node)); }
#line 1968 "compiler.tab.c"
    break;

  case 72:
#line 230 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_CONNECTOR, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1974 "compiler.tab.c"
    break;

  case 73:
#line 231 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1980 "compiler.tab.c"
    break;

  case 74:
#line 233 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1986 "compiler.tab.c"
    break;

  case 75:
#line 234 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1992 "compiler.tab.c"
    break;

  case 76:
#line 235 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1998 "compiler.tab.c"
    break;

  case 77:
#line 236 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2004 "compiler.tab.c"
    break;

  case 78:
#line 237 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2010 "compiler.tab.c"
    break;

  case 79:
#line 238 "compiler.y"
                                                    {   (yyval.node) = createControlFlowNode(NODE_BREAK); }
#line 2016 "compiler.tab.c"
    break;

  case 80:
#line 239 "compiler.y"
                                                    {   (yyval.node) = createControlFlowNode(NODE_CONTINUE); }
#line 2022 "compiler.tab.c"
    break;

  case 81:
#line 240 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2028 "compiler.tab.c"
    break;

  case 82:
#line 241 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2034 "compiler.tab.c"
    break;

  case 83:
#line 242 "compiler.y"
                                                    {   (yyval.node) = createDynamicNode(NODE_FREE, (yyvsp[-2].node));  }
#line 2040 "compiler.tab.c"
    break;

  case 84:
#line 243 "compiler.y"
                                                    {   (yyval.node) = createClassNode(NODE_DELETE, (yyvsp[-1].node), NULL);    }
#line 2046 "compiler.tab.c"
    break;

  case 85:
#line 245 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_READ, (yyvsp[-2].node), NULL);   }
#line 2052 "compiler.tab.c"
    break;

  case 86:
#line 247 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_WRITE, (yyvsp[-2].node), NULL);     }
#line 2058 "compiler.tab.c"
    break;

  case 87:
#line 249 "compiler.y"
                                                                {   (yyval.node) = createTreeNode(NODE_ASSIGN, (yyvsp[-3].node), (yyvsp[-1].node));    }
#line 2064 "compiler.tab.c"
    break;

  case 88:
#line 250 "compiler.y"
                                                                {   (yyval.node) = createDynamicNode(NODE_ALLOC, (yyvsp[-5].node));  }
#line 2070 "compiler.tab.c"
    break;

  case 89:
#line 251 "compiler.y"
                                                                {   (yyval.node) = createDynamicNode(NODE_INITIALIZE, NULL);  }
#line 2076 "compiler.tab.c"
    break;

  case 90:
#line 253 "compiler.y"
                                                                {   (yyval.node) = createClassNode(NODE_NEW, (yyvsp[-6].node), (yyvsp[-2].node)); }
#line 2082 "compiler.tab.c"
    break;

  case 91:
#line 254 "compiler.y"
                                                                {   (yyval.node) = createClassNode(NODE_NEW, (yyvsp[-6].node), (yyvsp[-2].node)); }
#line 2088 "compiler.tab.c"
    break;

  case 92:
#line 258 "compiler.y"
                                                                {  (yyval.node) = createIfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));  }
#line 2094 "compiler.tab.c"
    break;

  case 93:
#line 259 "compiler.y"
                                                                {  (yyval.node) = createIfNode((yyvsp[-5].node), (yyvsp[-2].node), NULL); }
#line 2100 "compiler.tab.c"
    break;

  case 94:
#line 261 "compiler.y"
                                                                {  (yyval.node) = createLoopNode(NODE_WHILE, (yyvsp[-5].node), (yyvsp[-2].node));   }
#line 2106 "compiler.tab.c"
    break;

  case 95:
#line 263 "compiler.y"
                                                                {  (yyval.node) = createLoopNode(NODE_RPTUTL, (yyvsp[-2].node), (yyvsp[-6].node));   }
#line 2112 "compiler.tab.c"
    break;

  case 96:
#line 265 "compiler.y"
                                                                {  (yyval.node) = createLoopNode(NODE_DOWHILE, (yyvsp[-2].node), (yyvsp[-6].node));   }
#line 2118 "compiler.tab.c"
    break;

  case 97:
#line 268 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2124 "compiler.tab.c"
    break;

  case 98:
#line 269 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2130 "compiler.tab.c"
    break;

  case 99:
#line 270 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2136 "compiler.tab.c"
    break;

  case 100:
#line 271 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2142 "compiler.tab.c"
    break;

  case 101:
#line 272 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2148 "compiler.tab.c"
    break;

  case 102:
#line 273 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_EQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2154 "compiler.tab.c"
    break;

  case 103:
#line 274 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_NE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2160 "compiler.tab.c"
    break;

  case 104:
#line 275 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_GT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2166 "compiler.tab.c"
    break;

  case 105:
#line 276 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_GE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2172 "compiler.tab.c"
    break;

  case 106:
#line 277 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_LT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2178 "compiler.tab.c"
    break;

  case 107:
#line 278 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_LE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2184 "compiler.tab.c"
    break;

  case 108:
#line 279 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2190 "compiler.tab.c"
    break;

  case 109:
#line 280 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2196 "compiler.tab.c"
    break;

  case 110:
#line 281 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[-1].node);    }
#line 2202 "compiler.tab.c"
    break;

  case 111:
#line 282 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2208 "compiler.tab.c"
    break;

  case 112:
#line 283 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);   }
#line 2214 "compiler.tab.c"
    break;

  case 113:
#line 284 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2220 "compiler.tab.c"
    break;

  case 114:
#line 285 "compiler.y"
                                                             {   (yyval.node) = createFunctNode((yyvsp[-3].node), (yyvsp[-1].node));   }
#line 2226 "compiler.tab.c"
    break;

  case 115:
#line 286 "compiler.y"
                                                    {   (yyval.node) = createDynamicNode(NODE_NULL, NULL);    }
#line 2232 "compiler.tab.c"
    break;

  case 116:
#line 288 "compiler.y"
                                                    {   setType((yyvsp[0].node)); (yyval.node) = (yyvsp[0].node); }
#line 2238 "compiler.tab.c"
    break;

  case 117:
#line 289 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2244 "compiler.tab.c"
    break;

  case 118:
#line 290 "compiler.y"
                                                    {   (yyval.node) = createArrayNode((yyvsp[-3].node), NULL, (yyvsp[-1].node)); }
#line 2250 "compiler.tab.c"
    break;

  case 119:
#line 292 "compiler.y"
                                                    {   (yyval.node) = appendArgNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2256 "compiler.tab.c"
    break;

  case 120:
#line 293 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2262 "compiler.tab.c"
    break;

  case 121:
#line 294 "compiler.y"
                                                    {   (yyval.node) = NULL;  }
#line 2268 "compiler.tab.c"
    break;


#line 2272 "compiler.tab.c"

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
#line 297 "compiler.y"


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
