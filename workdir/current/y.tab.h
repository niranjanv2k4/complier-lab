/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 147 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
