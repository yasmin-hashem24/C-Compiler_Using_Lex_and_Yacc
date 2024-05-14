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
    INT_TYPE = 258,                /* INT_TYPE  */
    FLOAT_TYPE = 259,              /* FLOAT_TYPE  */
    BOOL_TYPE = 260,               /* BOOL_TYPE  */
    CHAR_TYPE = 261,               /* CHAR_TYPE  */
    STRING_TYPE = 262,             /* STRING_TYPE  */
    VOID_TYPE = 263,               /* VOID_TYPE  */
    LBRACE = 264,                  /* LBRACE  */
    RBRACE = 265,                  /* RBRACE  */
    EQ = 266,                      /* EQ  */
    NEQ = 267,                     /* NEQ  */
    LT = 268,                      /* LT  */
    GT = 269,                      /* GT  */
    LTE = 270,                     /* LTE  */
    GTE = 271,                     /* GTE  */
    AND = 272,                     /* AND  */
    OR = 273,                      /* OR  */
    CONST = 274,                   /* CONST  */
    FUNC = 275,                    /* FUNC  */
    MAIN = 276,                    /* MAIN  */
    INCLUDE = 277,                 /* INCLUDE  */
    DEFINE = 278,                  /* DEFINE  */
    VAR = 279,                     /* VAR  */
    IF = 280,                      /* IF  */
    ELSE = 281,                    /* ELSE  */
    WHILE = 282,                   /* WHILE  */
    DO = 283,                      /* DO  */
    FOR = 284,                     /* FOR  */
    SWITCH = 285,                  /* SWITCH  */
    CASE = 286,                    /* CASE  */
    DEFAULT = 287,                 /* DEFAULT  */
    BREAK = 288,                   /* BREAK  */
    RETURN = 289,                  /* RETURN  */
    EXIT = 290,                    /* EXIT  */
    CONTINUE = 291,                /* CONTINUE  */
    PRINT = 292,                   /* PRINT  */
    ENUM = 293,                    /* ENUM  */
    INTEGER = 294,                 /* INTEGER  */
    FLOAT = 295,                   /* FLOAT  */
    BOOL = 296,                    /* BOOL  */
    CHAR = 297,                    /* CHAR  */
    STRING = 298,                  /* STRING  */
    IDENTIFIER = 299,              /* IDENTIFIER  */
    BOOL_FALSE = 300,              /* BOOL_FALSE  */
    BOOL_TRUE = 301,               /* BOOL_TRUE  */
    IFX = 302,                     /* IFX  */
    UMINUS = 303,                  /* UMINUS  */
    NOT = 304                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT_TYPE 258
#define FLOAT_TYPE 259
#define BOOL_TYPE 260
#define CHAR_TYPE 261
#define STRING_TYPE 262
#define VOID_TYPE 263
#define LBRACE 264
#define RBRACE 265
#define EQ 266
#define NEQ 267
#define LT 268
#define GT 269
#define LTE 270
#define GTE 271
#define AND 272
#define OR 273
#define CONST 274
#define FUNC 275
#define MAIN 276
#define INCLUDE 277
#define DEFINE 278
#define VAR 279
#define IF 280
#define ELSE 281
#define WHILE 282
#define DO 283
#define FOR 284
#define SWITCH 285
#define CASE 286
#define DEFAULT 287
#define BREAK 288
#define RETURN 289
#define EXIT 290
#define CONTINUE 291
#define PRINT 292
#define ENUM 293
#define INTEGER 294
#define FLOAT 295
#define BOOL 296
#define CHAR 297
#define STRING 298
#define IDENTIFIER 299
#define BOOL_FALSE 300
#define BOOL_TRUE 301
#define IFX 302
#define UMINUS 303
#define NOT 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "Compiler.y"

    int iVal;
    float fVal;
    bool bVal;
    char cVal;
    char *sVal;
    nodeType *nPtr;

#line 174 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
