/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    FLOAT = 259,                   /* FLOAT  */
    BOOL = 260,                    /* BOOL  */
    CHAR = 261,                    /* CHAR  */
    STRING = 262,                  /* STRING  */
    IDENTIFIER = 263,              /* IDENTIFIER  */
    BOOL_FALSE = 264,              /* BOOL_FALSE  */
    BOOL_TRUE = 265,               /* BOOL_TRUE  */
    INT_TYPE = 266,                /* INT_TYPE  */
    FLOAT_TYPE = 267,              /* FLOAT_TYPE  */
    BOOL_TYPE = 268,               /* BOOL_TYPE  */
    CHAR_TYPE = 269,               /* CHAR_TYPE  */
    STRING_TYPE = 270,             /* STRING_TYPE  */
    VOID_TYPE = 271,               /* VOID_TYPE  */
    LBRACE = 272,                  /* LBRACE  */
    RBRACE = 273,                  /* RBRACE  */
    EQ = 274,                      /* EQ  */
    NEQ = 275,                     /* NEQ  */
    LT = 276,                      /* LT  */
    GT = 277,                      /* GT  */
    LTE = 278,                     /* LTE  */
    GTE = 279,                     /* GTE  */
    AND = 280,                     /* AND  */
    OR = 281,                      /* OR  */
    CONST = 282,                   /* CONST  */
    VAR = 283,                     /* VAR  */
    IF = 284,                      /* IF  */
    ELSE = 285,                    /* ELSE  */
    WHILE = 286,                   /* WHILE  */
    DO = 287,                      /* DO  */
    FOR = 288,                     /* FOR  */
    SWITCH = 289,                  /* SWITCH  */
    CASE = 290,                    /* CASE  */
    DEFAULT = 291,                 /* DEFAULT  */
    BREAK = 292,                   /* BREAK  */
    RETURN = 293,                  /* RETURN  */
    PRINT = 294,                   /* PRINT  */
    ENUM = 295,                    /* ENUM  */
    IFX = 296,                     /* IFX  */
    UMINUS = 297                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INTEGER 258
#define FLOAT 259
#define BOOL 260
#define CHAR 261
#define STRING 262
#define IDENTIFIER 263
#define BOOL_FALSE 264
#define BOOL_TRUE 265
#define INT_TYPE 266
#define FLOAT_TYPE 267
#define BOOL_TYPE 268
#define CHAR_TYPE 269
#define STRING_TYPE 270
#define VOID_TYPE 271
#define LBRACE 272
#define RBRACE 273
#define EQ 274
#define NEQ 275
#define LT 276
#define GT 277
#define LTE 278
#define GTE 279
#define AND 280
#define OR 281
#define CONST 282
#define VAR 283
#define IF 284
#define ELSE 285
#define WHILE 286
#define DO 287
#define FOR 288
#define SWITCH 289
#define CASE 290
#define DEFAULT 291
#define BREAK 292
#define RETURN 293
#define PRINT 294
#define ENUM 295
#define IFX 296
#define UMINUS 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "Compiler.y"

    int iVal;
    float fVal;
    bool bVal;
    char cVal;
    char *sVal;
    nodeType *nPtr;

#line 160 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
