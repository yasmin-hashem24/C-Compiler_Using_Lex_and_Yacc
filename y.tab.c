/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "Compiler.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include <stdarg.h>
    #include "node.h"
    #include "symbolTable/symbolTable.h"
    #include "symbolTable/symbolEntry.h"
    #include "Errors/error.h"

    void yyerror(const char *s);
    bool handleOperandsExpressionInDeclaration(const nodeType *node1, const nodeType *node2, const nodeType *node4, bool mainCall, int isConst);
    bool handleConNodeExpressionInDeclaration(const nodeType *node1, const nodeType *node2, const nodeType *node4, bool mainCall, int isConst);
    bool handleIdNodeExpressionInDeclaration(const nodeType *node1, const nodeType *node2, const nodeType *node4, bool mainCall, int isConst);
    bool handleReturnTypeCheck(const nodeType *node1, const nodeType *node10);
    bool handleOperNodeReturnTypeCheck(const nodeType *node1, const nodeType *node10);

    int yylex();
    extern FILE *yyin;
    FILE *syntaxErrorsFile;
    FILE *semanticErrorsFile;
    FILE *warningFile;
    FILE *symbolTableFile;
    extern int currentLineNumber;


    int currentScope = -1;
    SymbolTable *globalTable;
    SymbolTable *currTable;
    SymbolTable *prevTable;

    const char *conEnumToString(conEnum enumValue);


#line 107 "y.tab.c"

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
    FUNC = 283,                    /* FUNC  */
    MAIN = 284,                    /* MAIN  */
    INCLUDE = 285,                 /* INCLUDE  */
    DEFINE = 286,                  /* DEFINE  */
    VAR = 287,                     /* VAR  */
    IF = 288,                      /* IF  */
    ELSE = 289,                    /* ELSE  */
    WHILE = 290,                   /* WHILE  */
    DO = 291,                      /* DO  */
    FOR = 292,                     /* FOR  */
    SWITCH = 293,                  /* SWITCH  */
    CASE = 294,                    /* CASE  */
    DEFAULT = 295,                 /* DEFAULT  */
    BREAK = 296,                   /* BREAK  */
    RETURN = 297,                  /* RETURN  */
    EXIT = 298,                    /* EXIT  */
    CONTINUE = 299,                /* CONTINUE  */
    PRINT = 300,                   /* PRINT  */
    ENUM = 301,                    /* ENUM  */
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
#define FUNC 283
#define MAIN 284
#define INCLUDE 285
#define DEFINE 286
#define VAR 287
#define IF 288
#define ELSE 289
#define WHILE 290
#define DO 291
#define FOR 292
#define SWITCH 293
#define CASE 294
#define DEFAULT 295
#define BREAK 296
#define RETURN 297
#define EXIT 298
#define CONTINUE 299
#define PRINT 300
#define ENUM 301
#define IFX 302
#define UMINUS 303
#define NOT 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "Compiler.y"

    int iVal;
    float fVal;
    bool bVal;
    char cVal;
    char *sVal;
    nodeType *nPtr;

#line 267 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_BOOL = 5,                       /* BOOL  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_IDENTIFIER = 8,                 /* IDENTIFIER  */
  YYSYMBOL_BOOL_FALSE = 9,                 /* BOOL_FALSE  */
  YYSYMBOL_BOOL_TRUE = 10,                 /* BOOL_TRUE  */
  YYSYMBOL_INT_TYPE = 11,                  /* INT_TYPE  */
  YYSYMBOL_FLOAT_TYPE = 12,                /* FLOAT_TYPE  */
  YYSYMBOL_BOOL_TYPE = 13,                 /* BOOL_TYPE  */
  YYSYMBOL_CHAR_TYPE = 14,                 /* CHAR_TYPE  */
  YYSYMBOL_STRING_TYPE = 15,               /* STRING_TYPE  */
  YYSYMBOL_VOID_TYPE = 16,                 /* VOID_TYPE  */
  YYSYMBOL_LBRACE = 17,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 18,                    /* RBRACE  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_NEQ = 20,                       /* NEQ  */
  YYSYMBOL_LT = 21,                        /* LT  */
  YYSYMBOL_GT = 22,                        /* GT  */
  YYSYMBOL_LTE = 23,                       /* LTE  */
  YYSYMBOL_GTE = 24,                       /* GTE  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_CONST = 27,                     /* CONST  */
  YYSYMBOL_FUNC = 28,                      /* FUNC  */
  YYSYMBOL_MAIN = 29,                      /* MAIN  */
  YYSYMBOL_INCLUDE = 30,                   /* INCLUDE  */
  YYSYMBOL_DEFINE = 31,                    /* DEFINE  */
  YYSYMBOL_VAR = 32,                       /* VAR  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_ELSE = 34,                      /* ELSE  */
  YYSYMBOL_WHILE = 35,                     /* WHILE  */
  YYSYMBOL_DO = 36,                        /* DO  */
  YYSYMBOL_FOR = 37,                       /* FOR  */
  YYSYMBOL_SWITCH = 38,                    /* SWITCH  */
  YYSYMBOL_CASE = 39,                      /* CASE  */
  YYSYMBOL_DEFAULT = 40,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 41,                     /* BREAK  */
  YYSYMBOL_RETURN = 42,                    /* RETURN  */
  YYSYMBOL_EXIT = 43,                      /* EXIT  */
  YYSYMBOL_CONTINUE = 44,                  /* CONTINUE  */
  YYSYMBOL_PRINT = 45,                     /* PRINT  */
  YYSYMBOL_ENUM = 46,                      /* ENUM  */
  YYSYMBOL_IFX = 47,                       /* IFX  */
  YYSYMBOL_48_ = 48,                       /* '+'  */
  YYSYMBOL_49_ = 49,                       /* '-'  */
  YYSYMBOL_50_ = 50,                       /* '*'  */
  YYSYMBOL_51_ = 51,                       /* '/'  */
  YYSYMBOL_52_ = 52,                       /* '%'  */
  YYSYMBOL_UMINUS = 53,                    /* UMINUS  */
  YYSYMBOL_NOT = 54,                       /* NOT  */
  YYSYMBOL_55_ = 55,                       /* '('  */
  YYSYMBOL_56_ = 56,                       /* ')'  */
  YYSYMBOL_57_ = 57,                       /* ';'  */
  YYSYMBOL_58_ = 58,                       /* ':'  */
  YYSYMBOL_59_ = 59,                       /* ','  */
  YYSYMBOL_60_ = 60,                       /* '='  */
  YYSYMBOL_61_ = 61,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_statement_list = 64,            /* statement_list  */
  YYSYMBOL_statement = 65,                 /* statement  */
  YYSYMBOL_print_statement = 66,           /* print_statement  */
  YYSYMBOL_if_condition_statement = 67,    /* if_condition_statement  */
  YYSYMBOL_switch_statement = 68,          /* switch_statement  */
  YYSYMBOL_case_list = 69,                 /* case_list  */
  YYSYMBOL_case_default = 70,              /* case_default  */
  YYSYMBOL_while_loop = 71,                /* while_loop  */
  YYSYMBOL_do_while_loop = 72,             /* do_while_loop  */
  YYSYMBOL_for_loop = 73,                  /* for_loop  */
  YYSYMBOL_function_declaration = 74,      /* function_declaration  */
  YYSYMBOL_function_call = 75,             /* function_call  */
  YYSYMBOL_function_call_expression = 76,  /* function_call_expression  */
  YYSYMBOL_arg_list = 77,                  /* arg_list  */
  YYSYMBOL_arg_list_call = 78,             /* arg_list_call  */
  YYSYMBOL_declaration_assignment = 79,    /* declaration_assignment  */
  YYSYMBOL_declaration_assignment_loop = 80, /* declaration_assignment_loop  */
  YYSYMBOL_declaration = 81,               /* declaration  */
  YYSYMBOL_assignment = 82,                /* assignment  */
  YYSYMBOL_enum_declaration = 83,          /* enum_declaration  */
  YYSYMBOL_enum_list = 84,                 /* enum_list  */
  YYSYMBOL_expression = 85,                /* expression  */
  YYSYMBOL_binary_expression = 86,         /* binary_expression  */
  YYSYMBOL_unary_expression = 87,          /* unary_expression  */
  YYSYMBOL_type = 88,                      /* type  */
  YYSYMBOL_value = 89,                     /* value  */
  YYSYMBOL_start_scope = 90,               /* start_scope  */
  YYSYMBOL_end_scope = 91                  /* end_scope  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  225

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,     2,     2,    52,     2,     2,
      55,    56,    50,    48,    59,    49,     2,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    57,
       2,    60,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    53,    54
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    82,    82,    87,    88,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   107,   110,   111,   113,
     116,   117,   120,   125,   128,   131,   135,   158,   173,   199,
     202,   205,   206,   207,   210,   211,   212,   219,   220,   223,
     224,   228,   242,   274,   305,   309,   374,   378,   379,   380,
     381,   386,   387,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     407,   408,   412,   413,   414,   415,   416,   419,   420,   421,
     422,   423,   424,   425,   428,   446
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "FLOAT",
  "BOOL", "CHAR", "STRING", "IDENTIFIER", "BOOL_FALSE", "BOOL_TRUE",
  "INT_TYPE", "FLOAT_TYPE", "BOOL_TYPE", "CHAR_TYPE", "STRING_TYPE",
  "VOID_TYPE", "LBRACE", "RBRACE", "EQ", "NEQ", "LT", "GT", "LTE", "GTE",
  "AND", "OR", "CONST", "FUNC", "MAIN", "INCLUDE", "DEFINE", "VAR", "IF",
  "ELSE", "WHILE", "DO", "FOR", "SWITCH", "CASE", "DEFAULT", "BREAK",
  "RETURN", "EXIT", "CONTINUE", "PRINT", "ENUM", "IFX", "'+'", "'-'",
  "'*'", "'/'", "'%'", "UMINUS", "NOT", "'('", "')'", "';'", "':'", "','",
  "'='", "'!'", "$accept", "program", "statement_list", "statement",
  "print_statement", "if_condition_statement", "switch_statement",
  "case_list", "case_default", "while_loop", "do_while_loop", "for_loop",
  "function_declaration", "function_call", "function_call_expression",
  "arg_list", "arg_list_call", "declaration_assignment",
  "declaration_assignment_loop", "declaration", "assignment",
  "enum_declaration", "enum_list", "expression", "binary_expression",
  "unary_expression", "type", "value", "start_scope", "end_scope", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-148)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -148,     6,   838,  -148,  -148,  -148,  -148,  -148,  -148,   -46,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,    12,   156,   -32,
     -15,    53,    16,    18,    20,    69,    55,    55,    55,   838,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,    23,    24,  -148,  1063,  -148,  -148,    74,  -148,    55,
      55,    29,    77,    55,    55,  -148,   116,    55,    55,    -4,
      31,  -148,   951,  -148,  -148,  -148,  -148,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
     -39,   -49,  1063,  1063,   156,    27,   960,   998,   838,    33,
      81,    34,  -148,  -148,    90,  1007,  1016,    41,    94,    55,
    -148,    13,    13,     1,     1,     1,     1,    85,  -148,  1071,
    1071,   364,   364,   482,   156,    55,    46,    55,    56,   106,
      55,    98,   100,   189,   112,    55,    61,   109,    66,   124,
      75,    -3,   -37,    78,  1063,  -148,  1063,   119,    82,  1063,
    -148,  -148,  -148,   892,   101,  -148,  -148,    55,    87,   134,
    -148,   128,  -148,   156,   838,   838,   115,   116,    55,    28,
    1063,  -148,    91,  -148,   838,  -148,   248,   307,   102,    97,
     162,    55,   107,   137,    55,   366,   425,  -148,  -148,    55,
     142,   838,   881,   838,  -148,  1063,    55,   484,  -148,   126,
    -148,  1054,  -148,   543,   838,   602,   902,    55,  -148,   158,
     120,   838,   121,   661,   122,   155,   941,  -148,  -148,   720,
    -148,   132,  -148,  -148,   172,   838,  -148,  -148,  -148,  -148,
     779,  -148,  -148,  -148,  -148
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      84,     0,     0,     1,    77,    78,    79,    80,    81,    68,
      83,    82,    72,    73,    74,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     8,     9,    10,    11,    12,    13,    14,     7,    69,
       5,     0,     0,     6,    15,    51,    52,     0,    67,    36,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
      68,    70,     0,    71,     4,    37,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,    35,    45,    33,     0,     0,     0,     0,     0,
       0,     0,    39,    40,     0,     0,     0,     0,     0,    36,
      66,    58,    59,    60,    61,    62,    63,    64,    65,    53,
      54,    55,    56,    57,    33,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      49,     0,     0,     0,    42,    29,    34,     0,    32,    43,
      84,    84,    85,     0,     0,    16,    44,     0,     0,     0,
      30,     0,    84,    33,     0,     0,     0,     0,     0,     0,
      50,    46,    47,    84,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    85,     0,
       0,     0,     0,     0,    19,    48,     0,     0,    85,    17,
      23,     0,    84,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    24,     0,
      21,     0,    22,    85,     0,     0,    85,    20,    28,    85,
       0,    25,    26,    85,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,   -76,   -29,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,   -96,   110,  -148,    19,   -51,
     -48,  -148,  -148,   -25,  -148,  -148,    -1,  -148,   -44,  -147
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    29,    30,    31,    32,    33,   159,   173,    34,
      35,    36,    37,    38,    39,   118,    81,    40,    91,    41,
      42,    43,   131,    44,    45,    46,    47,    48,     2,   156
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      64,    61,    62,    63,    97,    92,     3,   116,    93,    49,
     117,    88,   123,    98,    50,   148,   114,    52,   133,   150,
      51,   115,   117,    53,    82,    83,    73,    74,    86,    87,
     189,   190,    95,    96,    69,    70,    71,    72,    73,    74,
      54,   198,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    94,   149,   165,     4,     5,
       6,     7,     8,    60,    10,    11,   218,   171,   172,   221,
      55,    56,   222,    57,    82,    58,   224,    59,   166,   167,
      65,    66,    80,   119,    84,    85,    99,   120,   176,   124,
     134,   125,   136,    50,    64,   139,   154,   155,   126,   187,
     143,   129,   130,   135,    26,   193,    92,   195,   164,    93,
      27,    74,   137,   119,   138,   140,    28,   141,   203,   175,
      97,   115,   160,   145,    89,   209,   144,    12,    13,    14,
      15,    16,   146,   170,   151,   147,   152,    64,    64,   220,
     158,   153,   162,    18,   161,   163,   182,    64,   201,   185,
     168,   174,   119,   180,   191,   184,    94,   179,    64,   192,
     199,   196,    90,   215,    64,   183,    64,    12,    13,    14,
      15,    16,   206,   213,    64,   207,   169,   208,   210,   212,
      64,    67,    68,    69,    70,    71,    72,    73,    74,   217,
     219,    64,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     0,   142,     0,   132,
      75,    76,    77,    78,    79,     0,    18,     0,     0,     0,
     181,     0,    19,     0,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,    24,    25,     0,     0,    26,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
      28,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     0,   177,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,    19,     0,    20,    21,    22,    23,     0,     0,     0,
       0,     0,     0,    24,    25,     0,     0,    26,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,    28,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     0,   178,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
      19,     0,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,    24,    25,     0,     0,    26,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,    28,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    18,     0,     0,     0,     0,     0,    19,
       0,    20,    21,    22,    23,     0,     0,     0,   186,     0,
       0,    24,    25,     0,     0,    26,    79,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,    28,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,   188,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    19,     0,
      20,    21,    22,    23,     0,     0,     0,     0,     0,     0,
      24,    25,     0,     0,    26,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,    28,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    18,     0,     0,     0,     0,     0,    19,     0,    20,
      21,    22,    23,     0,     0,     0,   197,     0,     0,    24,
      25,     0,     0,    26,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,     0,    28,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,    19,     0,    20,    21,
      22,    23,     0,     0,   202,     0,     0,     0,    24,    25,
       0,     0,    26,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,    28,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,    19,     0,    20,    21,    22,
      23,     0,     0,   204,     0,     0,     0,    24,    25,     0,
       0,    26,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,    28,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,    19,     0,    20,    21,    22,    23,
       0,     0,   211,     0,     0,     0,    24,    25,     0,     0,
      26,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,    28,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     0,   216,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,    19,     0,    20,    21,    22,    23,     0,
       0,     0,     0,     0,     0,    24,    25,     0,     0,    26,
       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,    28,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     0,   223,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,    19,     0,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,    24,    25,     0,     0,    26,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
      28,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,    19,     0,    20,    21,    22,    23,     0,     0,     0,
       0,     0,     0,    24,    25,     0,     0,    26,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,    28,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
       0,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,     0,     0,     0,   194,
      75,    76,    77,    78,    79,     0,     0,     0,     0,   157,
      75,    76,    77,    78,    79,     0,     0,     0,     0,   205,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
      67,    68,    69,    70,    71,    72,    73,    74,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,    77,    78,    79,     0,     0,     0,     0,   214,    75,
      76,    77,    78,    79,     0,     0,     0,   100,    75,    76,
      77,    78,    79,     0,     0,     0,   121,    67,    68,    69,
      70,    71,    72,    73,    74,     0,    67,    68,    69,    70,
      71,    72,    73,    74,     0,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,     0,     0,     0,   122,    75,    76,    77,    78,    79,
       0,     0,     0,   127,    75,    76,    77,    78,    79,     0,
       0,     0,   128,    67,    68,    69,    70,    71,    72,    73,
      74,     0,    67,    68,    69,    70,    71,    72,    73,    74,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
       0,     0,    75,    76,    77,    78,    79,     0,     0,     0,
     200,    75,    76,    77,    78,    79,     0,     0,     0,     0,
       0,    77,    78,    79
};

static const yytype_int16 yycheck[] =
{
      29,    26,    27,    28,     8,    56,     0,    56,    56,    55,
      59,    55,    88,    17,    60,    18,    55,    18,   114,    56,
       8,    60,    59,    55,    49,    50,    25,    26,    53,    54,
     177,   178,    57,    58,    21,    22,    23,    24,    25,    26,
      55,   188,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    56,    59,   153,     3,     4,
       5,     6,     7,     8,     9,    10,   213,    39,    40,   216,
      17,    55,   219,    55,    99,    55,   223,     8,   154,   155,
      57,    57,     8,    84,    55,     8,    55,    60,   164,     8,
     115,    57,   117,    60,   123,   120,   140,   141,     8,   175,
     125,    60,     8,    57,    49,   181,   157,   183,   152,   157,
      55,    26,    56,   114,     8,    17,    61,    17,   194,   163,
       8,    60,   147,    57,     8,   201,    17,    11,    12,    13,
      14,    15,     8,   158,    56,    60,    17,   166,   167,   215,
      39,    59,     8,    27,    57,    17,   171,   176,   192,   174,
      35,    60,   153,    56,   179,    18,   157,    55,   187,    17,
      34,   186,    46,   207,   193,    58,   195,    11,    12,    13,
      14,    15,   197,    18,   203,    17,   157,    57,    57,    57,
     209,    19,    20,    21,    22,    23,    24,    25,    26,    57,
      18,   220,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    -1,    99,
      48,    49,    50,    51,    52,    -1,    27,    -1,    -1,    -1,
      58,    -1,    33,    -1,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      61,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    35,    36,    37,    38,    -1,    -1,    -1,    42,    -1,
      -1,    45,    46,    -1,    -1,    49,    52,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    61,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    61,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,
      36,    37,    38,    -1,    -1,    -1,    42,    -1,    -1,    45,
      46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    61,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,    36,
      37,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    61,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    35,    36,    37,
      38,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    61,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    35,    36,    37,    38,
      -1,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    61,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    61,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      61,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    56,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    56,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    56,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    56,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    56,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      56,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    63,    90,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    27,    33,
      35,    36,    37,    38,    45,    46,    49,    55,    61,    64,
      65,    66,    67,    68,    71,    72,    73,    74,    75,    76,
      79,    81,    82,    83,    85,    86,    87,    88,    89,    55,
      60,     8,    88,    55,    55,    17,    55,    55,    55,     8,
       8,    85,    85,    85,    65,    57,    57,    19,    20,    21,
      22,    23,    24,    25,    26,    48,    49,    50,    51,    52,
       8,    78,    85,    85,    55,     8,    85,    85,    90,     8,
      46,    80,    81,    82,    88,    85,    85,     8,    17,    55,
      56,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    55,    60,    56,    59,    77,    88,
      60,    56,    56,    64,     8,    57,     8,    56,    56,    60,
       8,    84,    78,    77,    85,    57,    85,    56,     8,    85,
      17,    17,    18,    85,    17,    57,     8,    60,    18,    59,
      56,    56,    17,    59,    90,    90,    91,    57,    39,    69,
      85,    57,     8,    17,    90,    77,    64,    64,    35,    80,
      85,    39,    40,    70,    60,    90,    64,    18,    18,    55,
      56,    58,    85,    58,    18,    85,    42,    64,    18,    91,
      91,    85,    17,    64,    58,    64,    85,    42,    91,    34,
      56,    90,    41,    64,    41,    57,    85,    17,    57,    64,
      57,    41,    57,    18,    57,    90,    18,    57,    91,    18,
      64,    91,    91,    18,    91
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    67,    67,    68,
      69,    69,    70,    71,    72,    73,    74,    74,    74,    75,
      76,    77,    77,    77,    78,    78,    78,    79,    79,    80,
      80,    81,    81,    81,    81,    82,    83,    84,    84,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    88,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    90,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     9,    15,     8,
       7,     6,     5,     9,    11,    13,    13,    10,    12,     5,
       4,     4,     2,     0,     3,     1,     0,     2,     2,     1,
       1,     2,     4,     5,     5,     3,     6,     3,     5,     1,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: start_scope statement_list  */
#line 82 "Compiler.y"
                                                         {execute((yyvsp[0].nPtr),1);freeNode((yyvsp[0].nPtr));}
#line 1660 "y.tab.c"
    break;

  case 3: /* statement_list: statement  */
#line 87 "Compiler.y"
                                                             {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1666 "y.tab.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 88 "Compiler.y"
                                                             {(yyval.nPtr)=createOperatorNode(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 1672 "y.tab.c"
    break;

  case 5: /* statement: declaration_assignment  */
#line 93 "Compiler.y"
                                                            {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1678 "y.tab.c"
    break;

  case 6: /* statement: enum_declaration  */
#line 94 "Compiler.y"
                                                            {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1684 "y.tab.c"
    break;

  case 7: /* statement: function_call  */
#line 95 "Compiler.y"
                                                            {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1690 "y.tab.c"
    break;

  case 8: /* statement: print_statement  */
#line 96 "Compiler.y"
                                                            {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1696 "y.tab.c"
    break;

  case 9: /* statement: if_condition_statement  */
#line 97 "Compiler.y"
                                                            {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1702 "y.tab.c"
    break;

  case 10: /* statement: switch_statement  */
#line 98 "Compiler.y"
                                                            {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1708 "y.tab.c"
    break;

  case 11: /* statement: while_loop  */
#line 99 "Compiler.y"
                                                            {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1714 "y.tab.c"
    break;

  case 12: /* statement: do_while_loop  */
#line 100 "Compiler.y"
                                                            {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1720 "y.tab.c"
    break;

  case 13: /* statement: for_loop  */
#line 101 "Compiler.y"
                                                            {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1726 "y.tab.c"
    break;

  case 14: /* statement: function_declaration  */
#line 102 "Compiler.y"
                                                             {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1732 "y.tab.c"
    break;

  case 15: /* statement: expression  */
#line 103 "Compiler.y"
                                                             {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1738 "y.tab.c"
    break;

  case 16: /* print_statement: PRINT '(' expression ')' ';'  */
#line 107 "Compiler.y"
                                                          {(yyval.nPtr)= createOperatorNode(PRINT, 1, (yyvsp[-2].nPtr));}
#line 1744 "y.tab.c"
    break;

  case 17: /* if_condition_statement: IF '(' expression ')' LBRACE start_scope statement_list RBRACE end_scope  */
#line 110 "Compiler.y"
                                                                                                                                                                {(yyval.nPtr) = createOperatorNode(IF,2,(yyvsp[-6].nPtr),(yyvsp[-2].nPtr));}
#line 1750 "y.tab.c"
    break;

  case 18: /* if_condition_statement: IF '(' expression ')' LBRACE start_scope statement_list RBRACE end_scope ELSE LBRACE start_scope statement_list RBRACE end_scope  */
#line 111 "Compiler.y"
                                                                                                                                                                {(yyval.nPtr) = createOperatorNode(IF, 2, (yyvsp[-12].nPtr), (yyvsp[-8].nPtr), (yyvsp[-2].nPtr));}
#line 1756 "y.tab.c"
    break;

  case 19: /* switch_statement: SWITCH '(' expression ')' LBRACE case_list case_default RBRACE  */
#line 113 "Compiler.y"
                                                                                            {(yyval.nPtr) = createOperatorNode(SWITCH, 2, (yyvsp[-5].nPtr), (yyvsp[-2].nPtr));}
#line 1762 "y.tab.c"
    break;

  case 20: /* case_list: case_list CASE expression ':' statement_list BREAK ';'  */
#line 116 "Compiler.y"
                                                                               {(yyval.nPtr) = createOperatorNode(CASE,3,(yyvsp[-6].nPtr),(yyvsp[-4].nPtr),(yyvsp[-2].nPtr));}
#line 1768 "y.tab.c"
    break;

  case 21: /* case_list: CASE expression ':' statement_list BREAK ';'  */
#line 117 "Compiler.y"
                                                                               {(yyval.nPtr) = createOperatorNode(CASE, 2, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr));}
#line 1774 "y.tab.c"
    break;

  case 22: /* case_default: DEFAULT ':' statement_list BREAK ';'  */
#line 120 "Compiler.y"
                                                                                {(yyval.nPtr) = createOperatorNode(DEFAULT, 1, (yyvsp[-2].nPtr));}
#line 1780 "y.tab.c"
    break;

  case 23: /* while_loop: WHILE '(' expression ')' LBRACE start_scope statement_list RBRACE end_scope  */
#line 125 "Compiler.y"
                                                                                                                {(yyval.nPtr) = createOperatorNode(WHILE, 2, (yyvsp[-6].nPtr), (yyvsp[-2].nPtr));}
#line 1786 "y.tab.c"
    break;

  case 24: /* do_while_loop: DO LBRACE start_scope statement_list RBRACE end_scope WHILE '(' expression ')' ';'  */
#line 128 "Compiler.y"
                                                                                                                { (yyval.nPtr) = createOperatorNode(DO, 2, (yyvsp[-7].nPtr), (yyvsp[-2].nPtr));}
#line 1792 "y.tab.c"
    break;

  case 25: /* for_loop: FOR '(' declaration_assignment_loop ';' expression ';' declaration_assignment_loop ')' LBRACE start_scope statement_list RBRACE end_scope  */
#line 131 "Compiler.y"
                                                                                                                                                                    {(yyval.nPtr) = createOperatorNode(FOR, 3, (yyvsp[-10].nPtr), (yyvsp[-8].nPtr), (yyvsp[-6].nPtr));}
#line 1798 "y.tab.c"
    break;

  case 26: /* function_declaration: type IDENTIFIER '(' arg_list ')' LBRACE start_scope statement_list RETURN expression ';' RBRACE end_scope  */
#line 136 "Compiler.y"
                                                                                                                                        { 

                                                                                                                                            SymbolEntry *entry = getSymbolEntryFromParentScope(currTable, (yyvsp[-11].sVal));
                                                                    
                                                                                                                                            if(entry == NULL){
                                                                                                                                                bool noError = handleReturnTypeCheck((yyvsp[-12].nPtr), (yyvsp[-3].nPtr));
                                                                                                                                                

                                                                                                                                                if (noError) {
                                                                                                                                                    // Itirate over the arguments types to add them
                                                                                                                                                    SymbolEntry *newEntry = create_function_SymbolEntry((yyvsp[-11].sVal), 0, 1, currentLineNumber, 0, NULL, conEnumToString((yyvsp[-12].nPtr)->typ.type));
                                                                                                                                                    addSymbolEntry(currTable, newEntry);
                                                                                                                                                    (yyval.nPtr)=createOperatorNode(FUNC, 3, createTypeNode(getTypeOfEnum((yyvsp[-12].nPtr))), createIdentifierNode((yyvsp[-11].sVal)), (yyvsp[-9].nPtr), (yyvsp[-5].nPtr), (yyvsp[-3].nPtr));
                                                                                                                                                }
                                                                                                                                                else{
                                                                                                                                                    throwError("Type mismatch. Return type does not match function declaration", currentLineNumber, semanticErrorsFile);
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                            else{
                                                                                                                                                throwError("Function name already declared", currentLineNumber, semanticErrorsFile);
                                                                                                                                            }
                                                                                                                                        }
#line 1825 "y.tab.c"
    break;

  case 27: /* function_declaration: VOID_TYPE IDENTIFIER '(' arg_list ')' LBRACE start_scope statement_list RBRACE end_scope  */
#line 159 "Compiler.y"
                                                                                                                                        { 

                                                                                                                                            SymbolEntry *entry = getSymbolEntryFromParentScope(currTable, (yyvsp[-8].sVal));
                                                                    
                                                                                                                                            if(entry == NULL){
                                                                                                                                                // Itirate over the arguments types to add them
                                                                                                                                                SymbolEntry *newEntry = create_function_SymbolEntry((yyvsp[-8].sVal), 0, 1, currentLineNumber, 0, NULL, "Void");
                                                                                                                                                addSymbolEntry(currTable, newEntry);
                                                                                                                                                (yyval.nPtr)=createOperatorNode(FUNC, 4, createTypeNode(typeVoid), createIdentifierNode((yyvsp[-8].sVal)), (yyvsp[-6].nPtr), (yyvsp[-2].nPtr));
                                                                                                                                            }
                                                                                                                                            else{
                                                                                                                                                throwError("Function name already declared", currentLineNumber, semanticErrorsFile);
                                                                                                                                            }
                                                                                                                                        }
#line 1844 "y.tab.c"
    break;

  case 28: /* function_declaration: type IDENTIFIER '(' arg_list ')' LBRACE start_scope RETURN expression ';' RBRACE end_scope  */
#line 174 "Compiler.y"
                                                                                                                                        { 

                                                                                                                                            SymbolEntry *entry = getSymbolEntryFromParentScope(currTable, (yyvsp[-10].sVal));
                                                                    
                                                                                                                                            if(entry == NULL){
                                                                                                                                                bool noError = handleReturnTypeCheck((yyvsp[-11].nPtr), (yyvsp[-3].nPtr));
                                                                                                                                                

                                                                                                                                                if (noError) {
                                                                                                                                                    // Itirate over the arguments types to add them
                                                                                                                                                    SymbolEntry *newEntry = create_function_SymbolEntry((yyvsp[-10].sVal), 0, 1, currentLineNumber, 0, NULL, conEnumToString((yyvsp[-11].nPtr)->typ.type));
                                                                                                                                                    addSymbolEntry(currTable, newEntry);
                                                                                                                                                    (yyval.nPtr)=createOperatorNode(FUNC, 3, createTypeNode(getTypeOfEnum((yyvsp[-11].nPtr))), createIdentifierNode((yyvsp[-10].sVal)), (yyvsp[-8].nPtr), (yyvsp[-3].nPtr));
                                                                                                                                                }
                                                                                                                                                else{
                                                                                                                                                    throwError("Type mismatch. Return type does not match function declaration", currentLineNumber, semanticErrorsFile);
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                            else{
                                                                                                                                                throwError("Function name already declared", currentLineNumber, semanticErrorsFile);
                                                                                                                                            }
                                                                                                                                        }
#line 1871 "y.tab.c"
    break;

  case 29: /* function_call: IDENTIFIER '(' arg_list_call ')' ';'  */
#line 199 "Compiler.y"
                                                                { (yyval.nPtr)=createOperatorNode(FUNC, 1, createIdentifierNode((yyvsp[-4].sVal)), (yyvsp[-2].nPtr));}
#line 1877 "y.tab.c"
    break;

  case 30: /* function_call_expression: IDENTIFIER '(' arg_list_call ')'  */
#line 202 "Compiler.y"
                                                                 { (yyval.nPtr)=createOperatorNode(FUNC, 1, createIdentifierNode((yyvsp[-3].sVal)), (yyvsp[-1].nPtr));}
#line 1883 "y.tab.c"
    break;

  case 31: /* arg_list: type IDENTIFIER ',' arg_list  */
#line 205 "Compiler.y"
                                                                 { (yyval.nPtr)=createOperatorNode(',', 2, createTypeNode(getTypeOfEnum((yyvsp[-3].nPtr))), createIdentifierNode((yyvsp[-2].sVal)));}
#line 1889 "y.tab.c"
    break;

  case 32: /* arg_list: type IDENTIFIER  */
#line 206 "Compiler.y"
                                                                 { (yyval.nPtr)=createOperatorNode(',', 2, createTypeNode(getTypeOfEnum((yyvsp[-1].nPtr))), createIdentifierNode((yyvsp[0].sVal)));}
#line 1895 "y.tab.c"
    break;

  case 33: /* arg_list: %empty  */
#line 207 "Compiler.y"
                                                                 { (yyval.nPtr)=NULL;}
#line 1901 "y.tab.c"
    break;

  case 34: /* arg_list_call: arg_list_call ',' expression  */
#line 210 "Compiler.y"
                                                                 { (yyval.nPtr)=createOperatorNode(',', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1907 "y.tab.c"
    break;

  case 35: /* arg_list_call: expression  */
#line 211 "Compiler.y"
                                                                 { (yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1913 "y.tab.c"
    break;

  case 36: /* arg_list_call: %empty  */
#line 212 "Compiler.y"
                                                                 { (yyval.nPtr)=NULL;}
#line 1919 "y.tab.c"
    break;

  case 37: /* declaration_assignment: declaration ';'  */
#line 219 "Compiler.y"
                                          { (yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1925 "y.tab.c"
    break;

  case 38: /* declaration_assignment: assignment ';'  */
#line 220 "Compiler.y"
                                         { (yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1931 "y.tab.c"
    break;

  case 39: /* declaration_assignment_loop: declaration  */
#line 223 "Compiler.y"
                                                { (yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1937 "y.tab.c"
    break;

  case 40: /* declaration_assignment_loop: assignment  */
#line 224 "Compiler.y"
                                                { (yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1943 "y.tab.c"
    break;

  case 41: /* declaration: type IDENTIFIER  */
#line 229 "Compiler.y"
                                                                    { 
                                                                        SymbolEntry *entry = getSymbolEntryFomCurrentScope(currTable, (yyvsp[0].sVal));

                                                                        if(entry == NULL){
                                                                            SymbolEntry *newEntry = create_variable_SymbolEntry((yyvsp[0].sVal), conEnumToString((yyvsp[-1].nPtr)->typ.type), 0, 0, 0, NULL, currentLineNumber);
                                                                            addSymbolEntry(currTable, newEntry);
                                                                            (yyval.nPtr) = createOperatorNode(VAR, 2, createTypeNode(getTypeOfEnum((yyvsp[-1].nPtr))), createIdentifierNode((yyvsp[0].sVal)));  
                                                                        }
                                                                        else{
                                                                            throwError("Variable already declared in this scope", currentLineNumber, semanticErrorsFile);
                                                                        }

                                                                    }
#line 1961 "y.tab.c"
    break;

  case 42: /* declaration: type IDENTIFIER '=' expression  */
#line 243 "Compiler.y"
                                                                    {  
                                                                        SymbolEntry *entry = getSymbolEntryFomCurrentScope(currTable, (yyvsp[-2].sVal));
                                                                        if(entry == NULL){
                                                                            
                                                                            char* typeUnion;
                                                                            CheckTypeFunc checkFunc = getCheckFunction((yyvsp[-3].nPtr)->typ.type, &typeUnion);
                                                                            bool noError = true;
                                                                            //expression can be => con, ID or op
                                                                            if((yyvsp[0].nPtr)->type == typeCon){
                                                                                noError = handleConNodeExpressionInDeclaration((yyvsp[-3].nPtr), (yyvsp[-2].sVal), (yyvsp[0].nPtr), true, 0);
                                                                                
                                                                            }
                                                                            else if((yyvsp[0].nPtr)->type == typeId){
                                                                                //i.e. int x = expr
                                                                                noError = handleIdNodeExpressionInDeclaration((yyvsp[-3].nPtr), (yyvsp[-2].sVal), (yyvsp[0].nPtr), true, 0);
                                                                                
                                                                            }
                                                                            else if((yyvsp[0].nPtr)->type==typeOpr){
                                                                                noError = handleOperandsExpressionInDeclaration((yyvsp[-3].nPtr), (yyvsp[-2].sVal), (yyvsp[0].nPtr), true, 0);
                                                                            }

                                                                            if(noError){
                                                                                (yyval.nPtr) = createOperatorNode('=', 3, createTypeNode(getTypeOfEnum((yyvsp[-3].nPtr))), createIdentifierNode((yyvsp[-2].sVal)), (yyvsp[0].nPtr)); 
                                                                            }

                                                                        }
                                                                        else{
                                                                            throwError("Variable already declared in this scope", 1, semanticErrorsFile);
                                                                        }
                                                                    }
#line 1996 "y.tab.c"
    break;

  case 43: /* declaration: CONST type IDENTIFIER '=' expression  */
#line 275 "Compiler.y"
                                                                    {  
                                                                        SymbolEntry *entry = getSymbolEntryFomCurrentScope(currTable, (yyvsp[-2].sVal));
                                                                        if(entry == NULL){
                                                                            
                                                                            char* typeUnion;
                                                                            CheckTypeFunc checkFunc = getCheckFunction((yyvsp[-3].nPtr)->typ.type, &typeUnion);
                                                                            bool noError = true;
                                                                            //expression can be => con, ID or op
                                                                            if((yyvsp[0].nPtr)->type == typeCon){
                                                                                noError = handleConNodeExpressionInDeclaration((yyvsp[-3].nPtr), (yyvsp[-2].sVal), (yyvsp[0].nPtr), true, 1);
                                                                                
                                                                            }
                                                                            else if((yyvsp[0].nPtr)->type == typeId){
                                                                                //i.e. int x = expr
                                                                                noError = handleIdNodeExpressionInDeclaration((yyvsp[-3].nPtr), (yyvsp[-2].sVal), (yyvsp[0].nPtr), true, 1);
                                                                                
                                                                            }
                                                                            else if((yyvsp[0].nPtr)->type==typeOpr){
                                                                                noError = handleOperandsExpressionInDeclaration((yyvsp[-3].nPtr), (yyvsp[-2].sVal), (yyvsp[0].nPtr), true, 1);
                                                                            }

                                                                            if(noError){
                                                                                (yyval.nPtr) = createOperatorNode(CONST, 3, createTypeNode(getTypeOfEnum((yyvsp[-3].nPtr))), createIdentifierNode((yyvsp[-2].sVal)), (yyvsp[0].nPtr));
                                                                            }

                                                                        }
                                                                        else{
                                                                            throwError("Variable already declared in this scope", 1, semanticErrorsFile);
                                                                        }
                                                                    }
#line 2031 "y.tab.c"
    break;

  case 44: /* declaration: ENUM IDENTIFIER IDENTIFIER '=' IDENTIFIER  */
#line 305 "Compiler.y"
                                                                    {  (yyval.nPtr) = createOperatorNode(ENUM, 3, createIdentifierNode((yyvsp[-3].sVal)),createIdentifierNode((yyvsp[-2].sVal)) ,createIdentifierNode((yyvsp[0].sVal)));}
#line 2037 "y.tab.c"
    break;

  case 45: /* assignment: IDENTIFIER '=' expression  */
#line 310 "Compiler.y"
                                                                    { 
                                                                        SymbolEntry *entry = getSymbolEntryFomCurrentScope(currTable, (yyvsp[-2].sVal));
                                                                        if(entry != NULL){
                                                                            //check that it's not constant
                                                                            if(getIsConstant(entry)){
                                                                                throwError("Cannot assign to constant variable", currentLineNumber, semanticErrorsFile);
                                                                            }
                                                                            else{
                                                                                char* typeUnion;
                                                                                CheckTypeFunc checkFunc = getCheckFunction(stringToConEnum(entry->type), &typeUnion);
                                                                                bool noError = true;
                                                                                //expression can be => con, ID or op
                                                                                if((yyvsp[0].nPtr)->type == typeCon){
                                                                                    char symbolValue[20];

                                                                                    if (checkTypeMismatchConNode((yyvsp[0].nPtr), symbolValue, typeUnion, checkFunc)) {
                                                                                        setValue(entry, symbolValue);
                                                                                        setIsInitialized(entry, 1);
                                                                                        setIsUsed(entry, 1);
                                                                                    } else {
                                                                                        throwError("Type mismatch", currentLineNumber, semanticErrorsFile);
                                                                                    }
                                                                                    
                                                                                }
                                                                                else if((yyvsp[0].nPtr)->type == typeId){

                                                                                    SymbolEntry *idEntry = checkIdNodeDeclaration(currTable, (yyvsp[0].nPtr)->id.id);
                                                                                    if (idEntry != NULL) {
                                                                                        bool isInitialized = getIsInitialized(idEntry);
                                                                                        if (isInitialized) {
                                                                                            setIsUsed(idEntry, 1);
                                                                                            char *idEntryValue = getValue(idEntry);
                                                                                            char *idEntryType = getType(idEntry);
                                                                                            if (strcmp(typeUnion, idEntryType) == 0) {
                                                                                                setValue(entry, idEntryValue);
                                                                                                setIsInitialized(entry, 1);
                                                                                                setIsUsed(entry, 1);
                                                                                            } else {
                                                                                                throwError("Type mismatch", currentLineNumber, semanticErrorsFile);
                                                                                            }
                                                                                        } else {
                                                                                            throwError("Variable has not been initialized before", currentLineNumber, semanticErrorsFile);
                                                                                        }
                                                                                    } else {
                                                                                        throwError("There is no such variable existing, Variable in expression is not declared", currentLineNumber, semanticErrorsFile);
                                                                                    }
                                                                                    
                                                                                }
                                                                                else if((yyvsp[0].nPtr)->type==typeOpr){
                                                                                    noError = handleOperandsExpressionInDeclaration((yyvsp[-2].sVal), (yyvsp[-2].sVal), (yyvsp[0].nPtr), false, 0);
                                                                                }

                                                                                if(noError){
                                                                                    (yyval.nPtr)=createOperatorNode('=', 2, createIdentifierNode((yyvsp[-2].sVal)), (yyvsp[0].nPtr));
                                                                                }
                                                                            }
                                                                        }
                                                                        else{
                                                                            throwError("Use of undeclared variable", 1, semanticErrorsFile);
                                                                        }
                                                                    }
#line 2103 "y.tab.c"
    break;

  case 46: /* enum_declaration: ENUM IDENTIFIER LBRACE enum_list RBRACE ';'  */
#line 374 "Compiler.y"
                                                                        {(yyval.nPtr)=createOperatorNode(ENUM, 2, createIdentifierNode((yyvsp[-4].sVal)), (yyvsp[-2].nPtr));}
#line 2109 "y.tab.c"
    break;

  case 47: /* enum_list: enum_list ',' IDENTIFIER  */
#line 378 "Compiler.y"
                                                                        { (yyval.nPtr) = createOperatorNode(ENUM, 1, createIdentifierNode((yyvsp[0].sVal))); }
#line 2115 "y.tab.c"
    break;

  case 48: /* enum_list: enum_list ',' IDENTIFIER '=' expression  */
#line 379 "Compiler.y"
                                                                        { (yyval.nPtr) = createOperatorNode(ENUM, 2, createIdentifierNode((yyvsp[-2].sVal)), (yyvsp[0].nPtr)); }
#line 2121 "y.tab.c"
    break;

  case 49: /* enum_list: IDENTIFIER  */
#line 380 "Compiler.y"
                                                                        { (yyval.nPtr) = createOperatorNode(ENUM, 1, createIdentifierNode((yyvsp[0].sVal))); }
#line 2127 "y.tab.c"
    break;

  case 50: /* enum_list: IDENTIFIER '=' expression  */
#line 381 "Compiler.y"
                                                                        { (yyval.nPtr) = createOperatorNode(ENUM, 2, createIdentifierNode((yyvsp[-2].sVal)), (yyvsp[0].nPtr)); }
#line 2133 "y.tab.c"
    break;

  case 51: /* expression: binary_expression  */
#line 386 "Compiler.y"
                                             { (yyval.nPtr)=(yyvsp[0].nPtr);}
#line 2139 "y.tab.c"
    break;

  case 52: /* expression: unary_expression  */
#line 387 "Compiler.y"
                                             { (yyval.nPtr)=(yyvsp[0].nPtr);}
#line 2145 "y.tab.c"
    break;

  case 53: /* binary_expression: expression '+' expression  */
#line 389 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2151 "y.tab.c"
    break;

  case 54: /* binary_expression: expression '-' expression  */
#line 390 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2157 "y.tab.c"
    break;

  case 55: /* binary_expression: expression '*' expression  */
#line 391 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2163 "y.tab.c"
    break;

  case 56: /* binary_expression: expression '/' expression  */
#line 392 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2169 "y.tab.c"
    break;

  case 57: /* binary_expression: expression '%' expression  */
#line 393 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2175 "y.tab.c"
    break;

  case 58: /* binary_expression: expression EQ expression  */
#line 394 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2181 "y.tab.c"
    break;

  case 59: /* binary_expression: expression NEQ expression  */
#line 395 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(NEQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2187 "y.tab.c"
    break;

  case 60: /* binary_expression: expression LT expression  */
#line 396 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(LT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2193 "y.tab.c"
    break;

  case 61: /* binary_expression: expression GT expression  */
#line 397 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(GT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2199 "y.tab.c"
    break;

  case 62: /* binary_expression: expression LTE expression  */
#line 398 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(LTE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2205 "y.tab.c"
    break;

  case 63: /* binary_expression: expression GTE expression  */
#line 399 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(GTE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2211 "y.tab.c"
    break;

  case 64: /* binary_expression: expression AND expression  */
#line 400 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2217 "y.tab.c"
    break;

  case 65: /* binary_expression: expression OR expression  */
#line 401 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2223 "y.tab.c"
    break;

  case 66: /* binary_expression: '(' expression ')'  */
#line 402 "Compiler.y"
                                                     { (yyval.nPtr)=(yyvsp[-1].nPtr); }
#line 2229 "y.tab.c"
    break;

  case 67: /* binary_expression: value  */
#line 403 "Compiler.y"
                                                     { (yyval.nPtr)=(yyvsp[0].nPtr); }
#line 2235 "y.tab.c"
    break;

  case 68: /* binary_expression: IDENTIFIER  */
#line 404 "Compiler.y"
                                                     { (yyval.nPtr)=createIdentifierNode((yyvsp[0].sVal)); }
#line 2241 "y.tab.c"
    break;

  case 69: /* binary_expression: function_call_expression  */
#line 405 "Compiler.y"
                                                     { (yyval.nPtr)=(yyvsp[0].nPtr);}
#line 2247 "y.tab.c"
    break;

  case 70: /* unary_expression: '-' expression  */
#line 407 "Compiler.y"
                                                      { (yyval.nPtr) = createOperatorNode('-', 1, (yyvsp[0].nPtr)); }
#line 2253 "y.tab.c"
    break;

  case 71: /* unary_expression: '!' expression  */
#line 408 "Compiler.y"
                                                      { (yyval.nPtr) = createOperatorNode('!', 1, (yyvsp[0].nPtr)); }
#line 2259 "y.tab.c"
    break;

  case 72: /* type: INT_TYPE  */
#line 412 "Compiler.y"
                                     { (yyval.nPtr) = createTypeNode(typeInt); }
#line 2265 "y.tab.c"
    break;

  case 73: /* type: FLOAT_TYPE  */
#line 413 "Compiler.y"
                                     { (yyval.nPtr) = createTypeNode(typeFloat); }
#line 2271 "y.tab.c"
    break;

  case 74: /* type: BOOL_TYPE  */
#line 414 "Compiler.y"
                                     { (yyval.nPtr) = createTypeNode(typeBool); }
#line 2277 "y.tab.c"
    break;

  case 75: /* type: CHAR_TYPE  */
#line 415 "Compiler.y"
                                     { (yyval.nPtr) = createTypeNode(typeChar); }
#line 2283 "y.tab.c"
    break;

  case 76: /* type: STRING_TYPE  */
#line 416 "Compiler.y"
                                      { (yyval.nPtr) = createTypeNode(typeString); }
#line 2289 "y.tab.c"
    break;

  case 77: /* value: INTEGER  */
#line 419 "Compiler.y"
                                  { (yyval.nPtr) = createIntConstantNode((yyvsp[0].iVal)); }
#line 2295 "y.tab.c"
    break;

  case 78: /* value: FLOAT  */
#line 420 "Compiler.y"
                                  { (yyval.nPtr) = createFloatConstantNode((yyvsp[0].fVal)); }
#line 2301 "y.tab.c"
    break;

  case 79: /* value: BOOL  */
#line 421 "Compiler.y"
                                  { (yyval.nPtr) = createBoolConstantNode((yyvsp[0].bVal)); }
#line 2307 "y.tab.c"
    break;

  case 80: /* value: CHAR  */
#line 422 "Compiler.y"
                                  { (yyval.nPtr) = createCharConstantNode((yyvsp[0].cVal)); }
#line 2313 "y.tab.c"
    break;

  case 81: /* value: STRING  */
#line 423 "Compiler.y"
                                  { (yyval.nPtr) = createStringConstantNode((yyvsp[0].sVal)); }
#line 2319 "y.tab.c"
    break;

  case 82: /* value: BOOL_TRUE  */
#line 424 "Compiler.y"
                                     { (yyval.nPtr) = createBoolConstantNode((yyvsp[0].bVal)); }
#line 2325 "y.tab.c"
    break;

  case 83: /* value: BOOL_FALSE  */
#line 425 "Compiler.y"
                                     { (yyval.nPtr) = createBoolConstantNode((yyvsp[0].bVal)); }
#line 2331 "y.tab.c"
    break;

  case 84: /* start_scope: %empty  */
#line 428 "Compiler.y"
                            {
                                printf("start of scope\n");
                                //we want to increment scope and add new ST (child to current scope)
                                currentScope++;
                                if(currentScope==0){
                                    globalTable = createSymbolTable("global", NULL);
                                    currTable = globalTable;
                                }
                                else{
                                    prevTable = currTable;
                                    SymbolTable *childTable = createSymbolTable("local", currTable);
                                    addChildrenToSymbolTable(currTable,childTable );
                                    currTable = childTable;
                                }
                                
                            }
#line 2352 "y.tab.c"
    break;

  case 85: /* end_scope: %empty  */
#line 446 "Compiler.y"
                            {
                                printf("end of scope\n");
                                currentScope--;
                                prevTable = currTable;
                                currTable = currTable->parent;
                            }
#line 2363 "y.tab.c"
    break;


#line 2367 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 454 "Compiler.y"


void yyerror(const char *s) {
    fprintf(syntaxErrorsFile, "Syntax error at line %d: %s\n", currentLineNumber, s);
}

bool handleOperandsExpressionInDeclaration(const nodeType *node1, const nodeType *node2, const nodeType *node4, bool mainCall, int isConst) {

    bool correctOperands = true;
    for(int i = 0; i < node4->opr.nops; i++) {
        if(node4->opr.op[i]->type == typeCon) {
            if(!handleConNodeExpressionInDeclaration(node1, node2, node4->opr.op[i],false, -1)) {
                correctOperands = false;
                break;
            }
        } else if(node4->opr.op[i]->type == typeId) {
            if(!handleIdNodeExpressionInDeclaration(node1, node2, node4->opr.op[i], false, -1)) {
                correctOperands = false;
                break;
            }
        } else if(node4->opr.op[i]->type == typeOpr) {
            if(!handleOperandsExpressionInDeclaration(node1, node2, node4->opr.op[i], false, -1)) {
                correctOperands = false;
                break;
            }
        }
    }

    if(!correctOperands) {
        return false;
    }
    // create the symbol entry and add it to the symbol table
    if(mainCall) {
        SymbolEntry *newEntry = create_variable_SymbolEntry(node2, conEnumToString(node1->typ.type), 1, isConst, 1, NULL, currentLineNumber);
        addSymbolEntry(currTable, newEntry);
    }
    return true;
        
}

bool handleConNodeExpressionInDeclaration(const nodeType *node1, const nodeType *node2, const nodeType *node4, bool mainCall, int isConst){

    char* typeUnion;
    CheckTypeFunc checkFunc = getCheckFunction(node1->typ.type, &typeUnion);
    char symbolValue[20];

    if (checkTypeMismatchConNode(node4, symbolValue, typeUnion, checkFunc)) {
        if(!mainCall) {
            return true;
        }
        SymbolEntry *newEntry = create_variable_SymbolEntry(node2, conEnumToString(node1->typ.type), 1, isConst, 1, symbolValue, currentLineNumber);
        addSymbolEntry(currTable, newEntry);
        return true;
    } else {
        throwError("Type mismatch", currentLineNumber, semanticErrorsFile);
        return false;
    }

}

bool handleIdNodeExpressionInDeclaration(const nodeType *node1, const nodeType *node2, const nodeType *node4, bool mainCall, int isConst){

    char* typeUnion;
    CheckTypeFunc checkFunc = getCheckFunction(node1->typ.type, &typeUnion);

    SymbolEntry *idEntry = checkIdNodeDeclaration(currTable, node4->id.id);
    if (idEntry != NULL) {
        bool isInitialized = getIsInitialized(idEntry);
        if (isInitialized) {
            setIsUsed(idEntry, 1);
            char *idEntryValue = getValue(idEntry);
            char *idEntryType = getType(idEntry);
            if (strcmp(typeUnion, idEntryType) == 0) {
                if(!mainCall) {
                    return true;
                }
                SymbolEntry *newEntry = create_variable_SymbolEntry(node2, conEnumToString(node1->typ.type), 1, isConst, 1, idEntryValue, currentLineNumber);
                addSymbolEntry(currTable, newEntry);
                return true;
            } else {
                throwError("Type mismatch", currentLineNumber, semanticErrorsFile);
            }
        } else {
            throwError("Variable has not been initialized before", currentLineNumber, semanticErrorsFile);
        }
    } else {
        throwError("There is no such variable/function existing, Variable in expression is not variable/function", currentLineNumber, semanticErrorsFile);
    }
    return false;
}

// Function to handle the type check for return statements in functions
bool handleReturnTypeCheck(const nodeType *node1, const nodeType *node10) {

    if (node10->type == typeCon) {
        if (!(node1->typ.type == node10->con.typeConst)) {
            return false;
        }
    } else if (node10->type == typeId) {
        SymbolEntry *idEntry = checkIdNodeDeclaration(prevTable, node10->id.id);
        if (idEntry != NULL) {
            bool isInitialized = getIsInitialized(idEntry);
            if (isInitialized) {
                setIsUsed(idEntry, 1);
                char *idEntryType = getType(idEntry);
                if (strcmp(conEnumToString(node1->typ.type), idEntryType) != 0) {
                    return false;
                }
            } else {
                throwError("Variable has not been initialized before, can't return it", currentLineNumber, semanticErrorsFile);
                return false;
            }
        } else {
            throwError("There is no such variable existing, Variable in return is not declared", currentLineNumber, semanticErrorsFile);
            return false;
        }
    } else if (node10->type == typeOpr) {
        return handleOperNodeReturnTypeCheck(node1, node10);
    }

    return true;
}

// Function to handle type checks for operator nodes in return statements
bool handleOperNodeReturnTypeCheck(const nodeType *node1, const nodeType *node10) {
    for (int i = 0; i < node10->opr.nops; i++) {
        if (node10->opr.op[i]->type == typeCon) {
            // Handle constant node
            if (!(node1->typ.type == node10->opr.op[i]->con.typeConst)) {
                return false;  // Return false if type mismatch
            }
        } else if (node10->opr.op[i]->type == typeId) {
            // Handle identifier node
            SymbolEntry *idEntry = checkIdNodeDeclaration(prevTable, node10->opr.op[i]->id.id);
            if (idEntry != NULL) {
                bool isInitialized = getIsInitialized(idEntry);
                if (isInitialized) {
                    setIsUsed(idEntry, 1);
                    char *idEntryType = getType(idEntry);
                    if (strcmp(conEnumToString(node1->typ.type), idEntryType) != 0) {
                        return false;  // Return false if type mismatch
                    }
                } else {
                    throwError("Variable has not been initialized before, can't return it", currentLineNumber, semanticErrorsFile);
                    return false;
                }
            } else {
                throwError("There is no such variable existing, Variable in return is not declared", currentLineNumber, semanticErrorsFile);
                return false;
            }
        } else if (node10->opr.op[i]->type == typeOpr) {
            if (!handleOperNodeReturnTypeCheck(node1, node10->opr.op[i])) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening input file");
        return 1;
    }

    yyin = fp;


    syntaxErrorsFile = fopen("syntax_errors.txt", "w");
    if (!syntaxErrorsFile) {
        perror("Error opening syntax errors file");
        fclose(fp);
        return 1;
    }

    semanticErrorsFile = fopen("semantic_errors.txt", "w");
    if (!syntaxErrorsFile) {
        perror("Error opening syntax errors file");
        fclose(fp);
        fclose(syntaxErrorsFile);
        return 1;
    }

    warningFile = fopen("warnings.txt", "w");
    if (!warningFile) {
        perror("Error opening warnings file");
        fclose(fp);
        fclose(syntaxErrorsFile);
        fclose(semanticErrorsFile);
        return 1;
    }

    symbolTableFile = fopen("symbol_table.txt", "w");
    if (!symbolTableFile) {
        perror("Error opening symbol table file");
        fclose(fp);
        fclose(syntaxErrorsFile);
        fclose(semanticErrorsFile);
        fclose(warningFile);
        return 1;
    }

    if(!yyparse()) {
        printf("Parsing successful\n");
        writeAllSymbolTablesToFile(globalTable, symbolTableFile);


        fclose(fp);
        fclose(syntaxErrorsFile);
        fclose(semanticErrorsFile);
        fclose(warningFile);
        fclose(symbolTableFile);
    }
    else {
        printf("Parsing failed\n");
        fclose(fp);
        fclose(syntaxErrorsFile);
        fclose(semanticErrorsFile);
        fclose(warningFile);
        fclose(symbolTableFile);
    }
    return 0;
}
