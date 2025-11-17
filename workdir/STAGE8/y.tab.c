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

    void yyerror(const char* error);
    int yylex();

    FILE *output;

    struct GSymbol* GST = NULL;
    struct LSymbol* LST = NULL;
    struct Typetable* current_type;
    struct Classtable* current_class;

    bool classDef = false;
    bool isProtected = true;
    char* Ldatatype = NULL;

    extern int yylineno;      // Line number (from lexer)
    extern char *yytext;      // Current token text (from lexer)
    extern int yychar;        // Current token code (from parser)



#line 102 "y.tab.c"

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
    ID = 290,
    MAIN = 291,
    TYPE = 292,
    ENDTYPE = 293,
    ALLOC = 294,
    INITIALIZE = 295,
    FREE = 296,
    NULL_VAL = 297,
    CLASS = 298,
    ENDCLASS = 299,
    EXTENDS = 300,
    NEW = 301,
    DELETE = 302,
    SELF = 303,
    PROTECTED = 304,
    RETURN = 305,
    NUM = 306,
    STR_LITERAL = 307,
    OR = 308,
    AND = 309
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
#define ID 290
#define MAIN 291
#define TYPE 292
#define ENDTYPE 293
#define ALLOC 294
#define INITIALIZE 295
#define FREE 296
#define NULL_VAL 297
#define CLASS 298
#define ENDCLASS 299
#define EXTENDS 300
#define NEW 301
#define DELETE 302
#define SELF 303
#define PROTECTED 304
#define RETURN 305
#define NUM 306
#define STR_LITERAL 307
#define OR 308
#define AND 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "compiler.y"

    struct ASTNode* node;
    struct param* parameter;
    struct LSymbol* localSymbolTable;
    struct Arglist* Args;
    struct Fieldlist* fieldlist;
    char* string;
    int type;

#line 272 "y.tab.c"

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
#define YYLAST   638

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  262

#define YYUNDEFTOK  2
#define YYMAXUTOK   309


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
      55,    59,     2,     2,    60,     2,    56,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    88,    89,    94,    94,    95,    97,    98,
     100,   100,   102,   103,   105,   106,   108,   109,   111,   112,
     114,   116,   117,   122,   123,   126,   127,   130,   130,   133,
     134,   137,   141,   142,   144,   145,   146,   146,   148,   149,
     150,   152,   153,   155,   156,   157,   163,   164,   166,   178,
     188,   189,   190,   192,   197,   198,   199,   201,   202,   204,
     204,   206,   207,   212,   213,   215,   217,   218,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   232,
     234,   236,   237,   238,   239,   242,   243,   245,   247,   249,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   271,   272,
     273,   274,   275,   277,   278,   279
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
  "INT", "STR", "ID", "MAIN", "TYPE", "ENDTYPE", "ALLOC", "INITIALIZE",
  "FREE", "NULL_VAL", "CLASS", "ENDCLASS", "EXTENDS", "NEW", "DELETE",
  "SELF", "PROTECTED", "RETURN", "NUM", "STR_LITERAL", "OR", "AND", "'('",
  "'.'", "'{'", "'}'", "')'", "','", "'['", "']'", "$accept", "program",
  "ClassDefBlock", "$@1", "ClassDefList", "ClassDef", "$@2", "Cname",
  "Fieldlists", "Fld", "MethodDecl", "MDecl", "MethodDefns",
  "TypeDefBlock", "TypeDefList", "TypeDef", "$@3", "FieldDeclList",
  "FieldDecl", "GDeclBlock", "GDeclList", "GDecl", "$@4", "Type",
  "GidList", "Gid", "FDefBlock", "Fdef", "MainBlock", "ParamList", "Param",
  "LDeclBlock", "LDeclList", "LDecl", "$@5", "IdList", "Coderegion",
  "RtnStmt", "Slist", "Stmt", "InputStmt", "OutputStmt", "AsgnStmt",
  "IfStmt", "WhileStmt", "RptUntlStmt", "DoWhileStmt", "expr",
  "IDENTIFIERS", "ArgList", YY_NULLPTR
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
     305,   306,   307,   308,   309,    40,    46,   123,   125,    41,
      44,    91,    93
};
# endif

#define YYPACT_NINF (-138)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,    12,    80,    47,  -138,     5,  -138,  -138,  -138,   -19,
     -31,  -138,  -138,    57,   108,    65,   101,  -138,   111,   110,
     -11,  -138,    61,  -138,  -138,  -138,  -138,   139,  -138,  -138,
     106,    65,   127,   101,  -138,  -138,   -26,  -138,   133,   141,
    -138,  -138,   147,  -138,  -138,   142,   121,   126,  -138,  -138,
    -138,  -138,   169,  -138,  -138,    34,   -12,  -138,   132,   111,
    -138,    -4,   111,   144,  -138,   142,   165,   189,     3,  -138,
    -138,  -138,   184,  -138,   190,    13,   170,  -138,   188,   196,
    -138,   185,   111,  -138,  -138,   209,    -2,  -138,  -138,  -138,
    -138,   203,  -138,   466,   191,   165,  -138,   111,   192,  -138,
     111,   210,  -138,  -138,   193,   195,   197,   204,   186,   238,
     245,   206,   199,   211,   224,  -138,   115,   255,   466,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,     1,  -138,   196,
     -17,  -138,    54,  -138,   -10,    26,   115,   115,   115,   555,
    -138,  -138,   555,   115,    26,    26,  -138,  -138,  -138,   115,
     335,    66,  -138,   256,  -138,   583,   115,    26,   222,  -138,
    -138,   273,  -138,   252,    32,   180,   187,   208,   412,   440,
      63,    64,    73,   250,   115,   115,   115,   115,   115,  -138,
     115,   115,   115,   115,   115,   115,   115,   115,  -138,   233,
     240,   247,   356,   377,    71,  -138,  -138,  -138,  -138,   292,
     293,   295,   282,   284,   281,  -138,   299,   300,  -138,   146,
     146,  -138,  -138,  -138,    16,    16,    16,    16,    16,    16,
     398,   594,   257,   258,   279,  -138,  -138,   115,  -138,  -138,
     555,   555,   260,   263,  -138,  -138,   306,   307,   262,   377,
     494,   520,   115,   115,  -138,  -138,   309,   555,   310,   313,
     271,   278,  -138,   546,  -138,  -138,   314,   315,   316,  -138,
    -138,  -138
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      24,     0,     0,     7,    27,     0,    26,     1,     5,     0,
       0,    23,    25,     0,     0,     0,     0,     4,     0,    12,
       0,     9,     0,    33,    38,    39,    40,     0,    35,    36,
       0,    38,     0,     0,    47,     3,     0,    30,     0,     0,
       6,     8,     0,    32,    34,     0,     0,     0,    46,     2,
      28,    29,     0,    13,    15,    43,     0,    42,     0,    52,
      31,     0,    52,     0,    37,     0,    56,     0,     0,    51,
      17,    14,     0,    19,     0,     0,     0,    41,     0,     0,
      53,     0,     0,    10,    18,     0,     0,    45,    44,    55,
      59,     0,    58,     0,     0,    56,    50,     0,     0,    16,
      52,     0,    54,    57,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,   109,     0,     0,     0,    67,
      68,    69,    70,    71,    72,    75,    76,     0,    49,     0,
       0,    22,     0,    62,     0,     0,     0,     0,     0,     0,
      73,    74,     0,     0,     0,     0,   107,   104,   105,     0,
       0,   106,    64,     0,    66,     0,   115,     0,     0,    11,
      21,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,   114,     0,   112,    48,    20,    61,     0,
       0,     0,     0,     0,     0,   110,     0,     0,   103,    90,
      91,    92,    93,    94,    98,   100,    95,    97,    99,    96,
     101,   102,     0,     0,     0,    81,   111,     0,    79,    80,
       0,     0,     0,     0,    77,    78,     0,     0,     0,   113,
       0,     0,     0,     0,    82,    83,     0,     0,     0,     0,
       0,     0,    84,     0,    86,    87,     0,     0,     0,    89,
      88,    85
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,  -138,  -138,   323,  -138,  -138,  -138,  -138,
    -138,   261,  -138,  -138,  -138,   329,  -138,  -138,   308,  -138,
    -138,   318,  -138,    97,  -138,   270,  -138,   -18,    -6,   -56,
     254,   251,  -138,   259,  -138,  -138,   218,   231,  -137,  -114,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,   -78,   -93,  -138
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    13,    20,    21,    97,    22,    61,    71,
      72,    73,   130,     3,     5,     6,    10,    36,    37,    16,
      27,    28,    45,    32,    56,    57,    33,    34,    17,    68,
      69,    79,    91,    92,   101,   134,    94,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   150,   151,   194
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     127,    64,   168,   162,   154,   169,    75,    24,    25,    26,
      35,    99,    14,   155,    15,    48,    24,    25,    26,   174,
     175,   176,   177,   178,    19,   127,    18,    49,     1,    24,
      25,    26,    50,    40,    -1,    -1,    -1,    -1,    -1,    -1,
       4,   159,   164,    11,   132,    70,   127,     4,    65,   127,
     163,   171,   172,   100,   154,   154,   156,   157,   165,   166,
     167,   112,    81,    82,   195,   170,   174,   175,   176,   177,
     178,   173,    87,    82,   115,   127,   127,   192,   193,   131,
       7,   180,   181,   182,   183,   184,   185,   156,   157,    62,
       8,   199,    19,   240,   241,    63,   209,   210,   211,   212,
     213,    30,   214,   215,   216,   217,   218,   219,   220,   221,
     253,    29,   160,   161,    82,    38,   186,   187,    42,   156,
     157,   156,   157,   206,    29,   205,   154,   154,   156,   157,
     226,   227,   207,    38,    31,    25,    26,   127,   127,   154,
      23,    24,    25,    26,    24,    25,    26,   127,   127,   239,
     112,   176,   177,   178,   127,    39,    67,   146,    74,    67,
     127,    46,    47,   115,   250,   251,   147,   148,    52,    85,
     149,    43,    24,    25,    26,    90,    53,    55,    54,    67,
      58,    59,    60,   174,   175,   176,   177,   178,    90,    66,
     174,   175,   176,   177,   178,    76,    78,    67,   180,   181,
     182,   183,   184,   185,    93,   180,   181,   182,   183,   184,
     185,   174,   175,   176,   177,   178,    83,    24,    25,    26,
      89,    24,    25,    26,    80,    86,   180,   181,   182,   183,
     184,   185,    88,   186,   187,   102,    24,    25,    26,   200,
     186,   187,    95,   139,    98,   133,   201,   100,   135,   128,
     136,   140,   137,   174,   175,   176,   177,   178,   141,   138,
     143,   186,   187,   142,   152,   188,   144,   202,   180,   181,
     182,   183,   184,   185,   174,   175,   176,   177,   178,   145,
     196,   174,   175,   176,   177,   178,   197,   198,   222,   180,
     181,   182,   183,   184,   185,   223,   180,   181,   182,   183,
     184,   185,   224,   186,   187,   228,   229,   231,   232,   208,
     230,   233,   234,   235,   238,   242,   236,   237,   243,   244,
     245,   246,   252,   254,   186,   187,   255,   259,   260,   261,
     256,   186,   187,    84,    12,    77,    96,   257,   174,   175,
     176,   177,   178,    41,    51,    44,   129,   158,   179,   153,
     103,     0,     0,   180,   181,   182,   183,   184,   185,   174,
     175,   176,   177,   178,     0,     0,     0,     0,     0,   225,
       0,     0,     0,     0,   180,   181,   182,   183,   184,   185,
     174,   175,   176,   177,   178,     0,     0,     0,   186,   187,
       0,     0,     0,     0,     0,   180,   181,   182,   183,   184,
     185,   174,   175,   176,   177,   178,     0,     0,     0,   186,
     187,     0,     0,     0,     0,     0,   180,   181,   182,   183,
     184,   185,   104,   105,     0,     0,   106,     0,     0,     0,
     186,   187,     0,     0,     0,     0,   107,   108,     0,   109,
     110,   111,     0,     0,     0,     0,     0,   112,     0,     0,
     104,   105,   187,   113,   106,     0,     0,     0,     0,   114,
     115,     0,     0,     0,   107,   108,     0,   109,   110,   111,
     203,     0,     0,     0,     0,   112,   104,   105,     0,     0,
     106,   113,     0,     0,     0,     0,     0,   114,   115,     0,
     107,   108,     0,   109,   110,   111,     0,     0,   204,     0,
       0,   112,     0,     0,   104,   105,     0,   113,   106,     0,
     247,   248,     0,   114,   115,     0,   116,     0,   107,   108,
       0,   109,   110,   111,     0,     0,     0,     0,     0,   112,
     104,   105,     0,     0,   106,   113,     0,     0,     0,     0,
       0,   114,   115,     0,   107,   108,   249,   109,   110,   111,
       0,     0,     0,     0,     0,   112,   104,   105,     0,     0,
     106,   113,     0,   258,     0,   104,   105,   114,   115,   106,
     107,   108,     0,   109,   110,   111,     0,     0,     0,   107,
     108,   112,   109,   110,   111,     0,     0,   113,     0,     0,
     112,     0,     0,   114,   115,     0,   113,   174,   175,   176,
     177,   178,   114,   115,     0,     0,     0,     0,     0,     0,
       0,     0,   180,   181,   182,   183,   184,   185,   112,     0,
       0,     0,   189,   190,     0,   146,     0,     0,     0,   191,
       0,   115,     0,     0,   147,   148,     0,     0,   149
};

static const yytype_int16 yycheck[] =
{
      93,    13,   139,    13,   118,   142,    62,    33,    34,    35,
      16,    13,    31,    12,    33,    33,    33,    34,    35,     3,
       4,     5,     6,     7,    35,   118,    57,    33,    37,    33,
      34,    35,    58,    44,    18,    19,    20,    21,    22,    23,
      35,    58,   135,    38,   100,    49,   139,    35,    60,   142,
      60,   144,   145,    55,   168,   169,    55,    56,   136,   137,
     138,    35,    59,    60,   157,   143,     3,     4,     5,     6,
       7,   149,    59,    60,    48,   168,   169,   155,   156,    97,
       0,    18,    19,    20,    21,    22,    23,    55,    56,    55,
      43,    59,    35,   230,   231,    61,   174,   175,   176,   177,
     178,    36,   180,   181,   182,   183,   184,   185,   186,   187,
     247,    14,   130,    59,    60,    18,    53,    54,    57,    55,
      56,    55,    56,    59,    27,    62,   240,   241,    55,    56,
      59,    60,    59,    36,    33,    34,    35,   230,   231,   253,
      32,    33,    34,    35,    33,    34,    35,   240,   241,   227,
      35,     5,     6,     7,   247,    45,    59,    42,    61,    62,
     253,    55,    35,    48,   242,   243,    51,    52,    35,    72,
      55,    32,    33,    34,    35,    78,    35,    35,    31,    82,
      59,    55,    13,     3,     4,     5,     6,     7,    91,    57,
       3,     4,     5,     6,     7,    51,    31,   100,    18,    19,
      20,    21,    22,    23,     8,    18,    19,    20,    21,    22,
      23,     3,     4,     5,     6,     7,    32,    33,    34,    35,
      32,    33,    34,    35,    35,    35,    18,    19,    20,    21,
      22,    23,    62,    53,    54,    32,    33,    34,    35,    59,
      53,    54,    57,    57,    35,    35,    59,    55,    55,    58,
      55,    13,    55,     3,     4,     5,     6,     7,    13,    55,
      61,    53,    54,    57,     9,     9,    55,    59,    18,    19,
      20,    21,    22,    23,     3,     4,     5,     6,     7,    55,
      58,     3,     4,     5,     6,     7,    13,    35,    55,    18,
      19,    20,    21,    22,    23,    55,    18,    19,    20,    21,
      22,    23,    55,    53,    54,    13,    13,    25,    24,    59,
      15,    30,    13,    13,    35,    55,    59,    59,    55,    13,
      13,    59,    13,    13,    53,    54,    13,    13,    13,    13,
      59,    53,    54,    72,     5,    65,    82,    59,     3,     4,
       5,     6,     7,    20,    36,    27,    95,   129,    13,   118,
      91,    -1,    -1,    18,    19,    20,    21,    22,    23,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,     3,     4,     5,     6,     7,    -1,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    10,    11,    -1,    -1,    14,    -1,    -1,    -1,
      53,    54,    -1,    -1,    -1,    -1,    24,    25,    -1,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      10,    11,    54,    41,    14,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    -1,    24,    25,    -1,    27,    28,    29,
      58,    -1,    -1,    -1,    -1,    35,    10,    11,    -1,    -1,
      14,    41,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      24,    25,    -1,    27,    28,    29,    -1,    -1,    58,    -1,
      -1,    35,    -1,    -1,    10,    11,    -1,    41,    14,    -1,
      16,    17,    -1,    47,    48,    -1,    50,    -1,    24,    25,
      -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    35,
      10,    11,    -1,    -1,    14,    41,    -1,    -1,    -1,    -1,
      -1,    47,    48,    -1,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    35,    10,    11,    -1,    -1,
      14,    41,    -1,    17,    -1,    10,    11,    47,    48,    14,
      24,    25,    -1,    27,    28,    29,    -1,    -1,    -1,    24,
      25,    35,    27,    28,    29,    -1,    -1,    41,    -1,    -1,
      35,    -1,    -1,    47,    48,    -1,    41,     3,     4,     5,
       6,     7,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    35,    -1,
      -1,    -1,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
      -1,    48,    -1,    -1,    51,    52,    -1,    -1,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    37,    64,    76,    35,    77,    78,     0,    43,    65,
      79,    38,    78,    66,    31,    33,    82,    91,    57,    35,
      67,    68,    70,    32,    33,    34,    35,    83,    84,    86,
      36,    33,    86,    89,    90,    91,    80,    81,    86,    45,
      44,    68,    57,    32,    84,    85,    55,    35,    90,    91,
      58,    81,    35,    35,    31,    35,    87,    88,    59,    55,
      13,    71,    55,    61,    13,    60,    57,    86,    92,    93,
      49,    72,    73,    74,    86,    92,    51,    88,    31,    94,
      35,    59,    60,    32,    74,    86,    35,    59,    62,    32,
      86,    95,    96,     8,    99,    57,    93,    69,    35,    13,
      55,    97,    32,    96,    10,    11,    14,    24,    25,    27,
      28,    29,    35,    41,    47,    48,    50,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   111,    58,    94,
      75,    90,    92,    35,    98,    55,    55,    55,    55,    57,
      13,    13,    57,    61,    55,    55,    42,    51,    52,    55,
     110,   111,     9,   100,   102,    12,    55,    56,    99,    58,
      90,    59,    13,    60,   111,   110,   110,   110,   101,   101,
     110,   111,   111,   110,     3,     4,     5,     6,     7,    13,
      18,    19,    20,    21,    22,    23,    53,    54,     9,    39,
      40,    46,   110,   110,   112,   111,    58,    13,    35,    59,
      59,    59,    59,    58,    58,    62,    59,    59,    59,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,    55,    55,    55,    13,    59,    60,    13,    13,
      15,    25,    24,    30,    13,    13,    59,    59,    35,   110,
     101,   101,    55,    55,    13,    13,    59,    16,    17,    26,
     110,   110,    13,   101,    13,    13,    59,    59,    17,    13,
      13,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    64,    64,    66,    65,    65,    67,    67,
      69,    68,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    75,    75,    76,    76,    77,    77,    79,    78,    80,
      80,    81,    82,    82,    83,    83,    85,    84,    86,    86,
      86,    87,    87,    88,    88,    88,    89,    89,    90,    91,
      92,    92,    92,    93,    94,    94,    94,    95,    95,    97,
      96,    98,    98,    99,    99,   100,   101,   101,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   103,
     104,   105,   105,   105,   105,   106,   106,   107,   108,   109,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   111,   111,
     111,   111,   111,   112,   112,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     0,     4,     0,     2,     1,
       0,     9,     1,     3,     2,     0,     3,     1,     2,     1,
       6,     2,     1,     3,     0,     2,     1,     0,     5,     2,
       1,     3,     3,     2,     2,     1,     0,     4,     1,     1,
       1,     3,     1,     1,     4,     4,     2,     1,     9,     8,
       3,     1,     0,     2,     3,     2,     0,     2,     1,     0,
       4,     3,     1,     4,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     5,     5,     5,
       5,     4,     6,     6,     7,    10,     8,     8,     9,     9,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       4,     4,     3,     3,     1,     0
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
#line 87 "compiler.y"
                                                                            {   exitProg(output);   }
#line 1705 "y.tab.c"
    break;

  case 3:
#line 88 "compiler.y"
                                                                            {   exitProg(output);   }
#line 1711 "y.tab.c"
    break;

  case 4:
#line 89 "compiler.y"
                                                                            {   exitProg(output);   }
#line 1717 "y.tab.c"
    break;

  case 5:
#line 94 "compiler.y"
                        { classDef = true;  }
#line 1723 "y.tab.c"
    break;

  case 6:
#line 94 "compiler.y"
                                                                            {  classDef = false; current_class == NULL; PrintClassTable();}
#line 1729 "y.tab.c"
    break;

  case 7:
#line 95 "compiler.y"
                                                                            {    }
#line 1735 "y.tab.c"
    break;

  case 10:
#line 100 "compiler.y"
                                                              {   updateClassEntry(); }
#line 1741 "y.tab.c"
    break;

  case 11:
#line 100 "compiler.y"
                                                                                                        { current_class = NULL; }
#line 1747 "y.tab.c"
    break;

  case 12:
#line 102 "compiler.y"
                                                                                {   current_class = CInstall((yyvsp[0].string), NULL);}
#line 1753 "y.tab.c"
    break;

  case 13:
#line 103 "compiler.y"
                                                                            {   current_class = CInstall((yyvsp[-2].string), (yyvsp[0].string));}
#line 1759 "y.tab.c"
    break;

  case 16:
#line 108 "compiler.y"
                                                                                {   ClassFInstall(current_class, (yyvsp[-2].string), (yyvsp[-1].string), isProtected);}
#line 1765 "y.tab.c"
    break;

  case 17:
#line 109 "compiler.y"
                                                                            {    }
#line 1771 "y.tab.c"
    break;

  case 20:
#line 114 "compiler.y"
                                                                            {   ClassMInstall(current_class, (yyvsp[-5].string), (yyvsp[-4].string), (yyvsp[-2].parameter));clearLST(); }
#line 1777 "y.tab.c"
    break;

  case 27:
#line 130 "compiler.y"
                        { TInstall((yyvsp[0].string), 0, NULL, TYPE_USERDEF); }
#line 1783 "y.tab.c"
    break;

  case 28:
#line 130 "compiler.y"
                                                                                         {   updateUserDefined((yyvsp[-4].string), (yyvsp[-1].fieldlist)); }
#line 1789 "y.tab.c"
    break;

  case 29:
#line 133 "compiler.y"
                                                {   (yyval.fieldlist) = appendField((yyvsp[-1].fieldlist), (yyvsp[0].fieldlist));   }
#line 1795 "y.tab.c"
    break;

  case 30:
#line 134 "compiler.y"
                                                {   (yyval.fieldlist) = (yyvsp[0].fieldlist); }
#line 1801 "y.tab.c"
    break;

  case 31:
#line 137 "compiler.y"
                                                {   (yyval.fieldlist) = createField((yyvsp[-2].string), (yyvsp[-1].string)); }
#line 1807 "y.tab.c"
    break;

  case 32:
#line 141 "compiler.y"
                                                {   }
#line 1813 "y.tab.c"
    break;

  case 33:
#line 142 "compiler.y"
                                                {   }
#line 1819 "y.tab.c"
    break;

  case 36:
#line 146 "compiler.y"
                     { current_type = TLookup((yyvsp[0].string)); current_class = CLookup((yyvsp[0].string)); }
#line 1825 "y.tab.c"
    break;

  case 37:
#line 146 "compiler.y"
                                                                                                 {     }
#line 1831 "y.tab.c"
    break;

  case 38:
#line 148 "compiler.y"
                                                {  (yyval.string) = (yyvsp[0].string); }
#line 1837 "y.tab.c"
    break;

  case 39:
#line 149 "compiler.y"
                                                {  (yyval.string) = (yyvsp[0].string); }
#line 1843 "y.tab.c"
    break;

  case 40:
#line 150 "compiler.y"
                                                {  (yyval.string) = (yyvsp[0].string); }
#line 1849 "y.tab.c"
    break;

  case 43:
#line 155 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[0].string), 1, 0, 0,NULL, NODE_ID);    }
#line 1855 "y.tab.c"
    break;

  case 44:
#line 156 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[-3].string), (yyvsp[-1].node)->value.intVal, 1, (yyvsp[-1].node)->value.intVal, NULL, NODE_ID);   }
#line 1861 "y.tab.c"
    break;

  case 45:
#line 157 "compiler.y"
                                                {   GST = insertToGlobal((yyvsp[-3].string), 0, 0, 0, (yyvsp[-1].parameter), NODE_FUNCT);  
                                                    clearLST();  
                                                }
#line 1869 "y.tab.c"
    break;

  case 46:
#line 163 "compiler.y"
                                                {      }
#line 1875 "y.tab.c"
    break;

  case 47:
#line 164 "compiler.y"
                                                {      }
#line 1881 "y.tab.c"
    break;

  case 48:
#line 166 "compiler.y"
                                                                            {   
                                                                                if(classDef)
                                                                                    validateMethod(TLookup((yyvsp[-8].string)), (yyvsp[-7].string), (yyvsp[-5].parameter), (yyvsp[-1].node)); 
                                                                                else
                                                                                    validateFunct(TLookup((yyvsp[-8].string)), (yyvsp[-7].string), (yyvsp[-5].parameter), (yyvsp[-1].node)); 
                                                                                generateFunct(output, (yyvsp[-7].string), (yyvsp[-1].node), (yyvsp[-5].parameter));
                                                                                clearLST();  
                                                                            }
#line 1894 "y.tab.c"
    break;

  case 49:
#line 178 "compiler.y"
                                                                            {   
                                                                                validateMain((yyvsp[-1].node));
                                                                                generateFunct(output, NULL, (yyvsp[-1].node), NULL);
                                                                                printLST("MAIN");
                                                                                clearLST();
                                                                            }
#line 1905 "y.tab.c"
    break;

  case 50:
#line 188 "compiler.y"
                                        {   (yyval.parameter) = appendParam((yyvsp[-2].parameter), (yyvsp[0].parameter)); }
#line 1911 "y.tab.c"
    break;

  case 51:
#line 189 "compiler.y"
                                        {   (yyval.parameter) = (yyvsp[0].parameter); }
#line 1917 "y.tab.c"
    break;

  case 52:
#line 190 "compiler.y"
                                        {   (yyval.parameter) = NULL; }
#line 1923 "y.tab.c"
    break;

  case 53:
#line 192 "compiler.y"
                                        {   (yyval.parameter) = createParam((yyvsp[-1].string), (yyvsp[0].string));   }
#line 1929 "y.tab.c"
    break;

  case 54:
#line 197 "compiler.y"
                                                    {  }
#line 1935 "y.tab.c"
    break;

  case 57:
#line 201 "compiler.y"
                                                    {  }
#line 1941 "y.tab.c"
    break;

  case 58:
#line 202 "compiler.y"
                                                    {  }
#line 1947 "y.tab.c"
    break;

  case 59:
#line 204 "compiler.y"
                     {  Ldatatype = (yyvsp[0].string);  }
#line 1953 "y.tab.c"
    break;

  case 61:
#line 206 "compiler.y"
                                                    {   LST = createLST((yyvsp[0].string), Ldatatype);   }
#line 1959 "y.tab.c"
    break;

  case 62:
#line 207 "compiler.y"
                                                    {   LST = createLST((yyvsp[0].string), Ldatatype);   }
#line 1965 "y.tab.c"
    break;

  case 63:
#line 212 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_CONNECTOR, (yyvsp[-2].node), (yyvsp[-1].node));    }
#line 1971 "y.tab.c"
    break;

  case 64:
#line 213 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_CONNECTOR, NULL, (yyvsp[-1].node));    }
#line 1977 "y.tab.c"
    break;

  case 65:
#line 215 "compiler.y"
                                                    {   (yyval.node) = createRtnNode((yyvsp[-1].node)); }
#line 1983 "y.tab.c"
    break;

  case 66:
#line 217 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_CONNECTOR, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1989 "y.tab.c"
    break;

  case 67:
#line 218 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 1995 "y.tab.c"
    break;

  case 68:
#line 220 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2001 "y.tab.c"
    break;

  case 69:
#line 221 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2007 "y.tab.c"
    break;

  case 70:
#line 222 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2013 "y.tab.c"
    break;

  case 71:
#line 223 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2019 "y.tab.c"
    break;

  case 72:
#line 224 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2025 "y.tab.c"
    break;

  case 73:
#line 225 "compiler.y"
                                                    {   (yyval.node) = createControlFlowNode(NODE_BREAK); }
#line 2031 "y.tab.c"
    break;

  case 74:
#line 226 "compiler.y"
                                                    {   (yyval.node) = createControlFlowNode(NODE_CONTINUE); }
#line 2037 "y.tab.c"
    break;

  case 75:
#line 227 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2043 "y.tab.c"
    break;

  case 76:
#line 228 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2049 "y.tab.c"
    break;

  case 77:
#line 229 "compiler.y"
                                                    {   (yyval.node) = createDynamicNode(NODE_FREE, (yyvsp[-2].node));  }
#line 2055 "y.tab.c"
    break;

  case 78:
#line 230 "compiler.y"
                                                    {   (yyval.node) = createClassNode(NODE_DELETE, createLeafNode(NODE_ID, NULL, (yyvsp[-2].node)->name, 0, NULL), NULL);    }
#line 2061 "y.tab.c"
    break;

  case 79:
#line 232 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_READ, (yyvsp[-2].node), NULL);   }
#line 2067 "y.tab.c"
    break;

  case 80:
#line 234 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_WRITE, (yyvsp[-2].node), NULL);     }
#line 2073 "y.tab.c"
    break;

  case 81:
#line 236 "compiler.y"
                                                                {   (yyval.node) = createTreeNode(NODE_ASSIGN, (yyvsp[-3].node), (yyvsp[-1].node));    }
#line 2079 "y.tab.c"
    break;

  case 82:
#line 237 "compiler.y"
                                                                {   setType((yyval.node));(yyval.node) = createDynamicNode(NODE_ALLOC, (yyvsp[-5].node));  }
#line 2085 "y.tab.c"
    break;

  case 83:
#line 238 "compiler.y"
                                                                {   (yyval.node) = createDynamicNode(NODE_INITIALIZE, NULL);  }
#line 2091 "y.tab.c"
    break;

  case 84:
#line 239 "compiler.y"
                                                                {   (yyval.node) = createClassNode(NODE_NEW, (yyvsp[-6].node), (yyvsp[-2].string)); }
#line 2097 "y.tab.c"
    break;

  case 85:
#line 242 "compiler.y"
                                                                 {  (yyval.node) = createIfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));  }
#line 2103 "y.tab.c"
    break;

  case 86:
#line 243 "compiler.y"
                                                                 {  (yyval.node) = createIfNode((yyvsp[-5].node), (yyvsp[-2].node), NULL); }
#line 2109 "y.tab.c"
    break;

  case 87:
#line 245 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_WHILE, (yyvsp[-5].node), (yyvsp[-2].node));   }
#line 2115 "y.tab.c"
    break;

  case 88:
#line 247 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_RPTUTL, (yyvsp[-2].node), (yyvsp[-6].node));   }
#line 2121 "y.tab.c"
    break;

  case 89:
#line 249 "compiler.y"
                                                                 {  (yyval.node) = createLoopNode(NODE_DOWHILE, (yyvsp[-2].node), (yyvsp[-6].node));   }
#line 2127 "y.tab.c"
    break;

  case 90:
#line 252 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2133 "y.tab.c"
    break;

  case 91:
#line 253 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2139 "y.tab.c"
    break;

  case 92:
#line 254 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2145 "y.tab.c"
    break;

  case 93:
#line 255 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2151 "y.tab.c"
    break;

  case 94:
#line 256 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2157 "y.tab.c"
    break;

  case 95:
#line 257 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_EQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2163 "y.tab.c"
    break;

  case 96:
#line 258 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_NE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2169 "y.tab.c"
    break;

  case 97:
#line 259 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_GT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2175 "y.tab.c"
    break;

  case 98:
#line 260 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_GE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2181 "y.tab.c"
    break;

  case 99:
#line 261 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_LT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2187 "y.tab.c"
    break;

  case 100:
#line 262 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_LE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2193 "y.tab.c"
    break;

  case 101:
#line 263 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2199 "y.tab.c"
    break;

  case 102:
#line 264 "compiler.y"
                                                    {   (yyval.node) = createTreeNode(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2205 "y.tab.c"
    break;

  case 103:
#line 265 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[-1].node);    }
#line 2211 "y.tab.c"
    break;

  case 104:
#line 266 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);    }
#line 2217 "y.tab.c"
    break;

  case 105:
#line 267 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node);   }
#line 2223 "y.tab.c"
    break;

  case 106:
#line 268 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); validateAndSetType((yyval.node));    }
#line 2229 "y.tab.c"
    break;

  case 107:
#line 269 "compiler.y"
                                                    {   (yyval.node) = createDynamicNode(NODE_NULL, NULL);    }
#line 2235 "y.tab.c"
    break;

  case 108:
#line 271 "compiler.y"
                                                    {   (yyval.node) = createLeafNode(NODE_ID, NULL, (yyvsp[0].string), 0, NULL); }
#line 2241 "y.tab.c"
    break;

  case 109:
#line 272 "compiler.y"
                                                    {   (yyval.node) = createLeafNode(NODE_SELF, NULL, NULL, 0, NULL);  }
#line 2247 "y.tab.c"
    break;

  case 110:
#line 273 "compiler.y"
                                                    {   (yyval.node) = createArrayNode(createLeafNode(NODE_ID, NULL, (yyvsp[-3].string), 0, NULL), NULL, (yyvsp[-1].node)); }
#line 2253 "y.tab.c"
    break;

  case 111:
#line 274 "compiler.y"
                                                    {   (yyval.node) = createFunctNode((yyvsp[-3].node), (yyvsp[-1].node));   }
#line 2259 "y.tab.c"
    break;

  case 112:
#line 275 "compiler.y"
                                                    {   (yyval.node) = createFieldAccessNode((yyvsp[-2].node), (yyvsp[0].node));    }
#line 2265 "y.tab.c"
    break;

  case 113:
#line 277 "compiler.y"
                                                    {   (yyval.node) = appendArgNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2271 "y.tab.c"
    break;

  case 114:
#line 278 "compiler.y"
                                                    {   (yyval.node) = (yyvsp[0].node); }
#line 2277 "y.tab.c"
    break;

  case 115:
#line 279 "compiler.y"
                                                    {   (yyval.node) = NULL;  }
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
#line 282 "compiler.y"


extern FILE* yyin;

void yyerror(const char* error) {
    fprintf(stderr, "\nSyntax error at line %d: %s\n", yylineno, error);

    if (yytext && *yytext) {
        fprintf(stderr, "    Offending token: '%s'\n", yytext);
    }

    // If yychar is defined, print its numeric ID too (optional)
    if (yychar != YYEMPTY) {
        fprintf(stderr, "    Token code: %d\n", yychar);
    }

    exit(1);
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
    setHeader(output);
    yyparse();
    /* printGST(); */
    
    fclose(output);
    return 0;
}
