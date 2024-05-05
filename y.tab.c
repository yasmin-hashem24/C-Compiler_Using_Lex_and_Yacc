/* A Bison parser, made by GNU Bison 3.7.5.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

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

    void yyerror(const char *s);
    nodeType *createTypeNode(conEnum type);
    nodeType *createConstantNode();
    nodeType *createIntConstantNode(int value);
    nodeType *createFloatConstantNode(float value);
    nodeType *createBoolConstantNode(bool value);
    nodeType *createCharConstantNode(char value);
    nodeType *createStringConstantNode(char* value);
    nodeType *createIdentifierNode(char* id);
    nodeType *createOperatorNode(int oper, int nops, ...);
    void freeNode(nodeType *p);
    int yylex();
    extern FILE *yyin;
    extern FILE *errorsFile;
    extern int currentLineNumber;

#line 96 "y.tab.c"

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
#line 27 "Compiler.y"

    int iVal;
    float fVal;
    bool bVal;
    char cVal;
    char *sVal;
    nodeType *nPtr;

#line 256 "y.tab.c"

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
  YYSYMBOL_function_or_statement = 64,     /* function_or_statement  */
  YYSYMBOL_statement_list = 65,            /* statement_list  */
  YYSYMBOL_statement = 66,                 /* statement  */
  YYSYMBOL_print_statement = 67,           /* print_statement  */
  YYSYMBOL_if_statement = 68,              /* if_statement  */
  YYSYMBOL_switch_statement = 69,          /* switch_statement  */
  YYSYMBOL_case_list = 70,                 /* case_list  */
  YYSYMBOL_case_default = 71,              /* case_default  */
  YYSYMBOL_while_loop = 72,                /* while_loop  */
  YYSYMBOL_do_while_loop = 73,             /* do_while_loop  */
  YYSYMBOL_for_loop = 74,                  /* for_loop  */
  YYSYMBOL_function_declaration = 75,      /* function_declaration  */
  YYSYMBOL_function_call = 76,             /* function_call  */
  YYSYMBOL_function_call_expression = 77,  /* function_call_expression  */
  YYSYMBOL_arg_list = 78,                  /* arg_list  */
  YYSYMBOL_arg_list_call = 79,             /* arg_list_call  */
  YYSYMBOL_declaration_assignment = 80,    /* declaration_assignment  */
  YYSYMBOL_declaration_assignment_loop = 81, /* declaration_assignment_loop  */
  YYSYMBOL_declaration = 82,               /* declaration  */
  YYSYMBOL_assignment = 83,                /* assignment  */
  YYSYMBOL_enum_declaration = 84,          /* enum_declaration  */
  YYSYMBOL_enum_list = 85,                 /* enum_list  */
  YYSYMBOL_expression = 86,                /* expression  */
  YYSYMBOL_binary_expression = 87,         /* binary_expression  */
  YYSYMBOL_unary_expression = 88,          /* unary_expression  */
  YYSYMBOL_type = 89,                      /* type  */
  YYSYMBOL_value = 90                      /* value  */
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   771

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

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
static const yytype_uint8 yyrline[] =
{
       0,    71,    71,    74,    75,    78,    79,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    96,   100,   101,   106,
     109,   110,   116,   120,   123,   127,   131,   132,   135,   138,
     141,   142,   145,   146,   151,   152,   155,   156,   158,   159,
     160,   161,   165,   169,   172,   173,   174,   175,   179,   180,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   202,   203,   207,
     208,   209,   210,   211,   214,   215,   216,   217,   218,   219,
     220
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
  "'='", "'!'", "$accept", "program", "function_or_statement",
  "statement_list", "statement", "print_statement", "if_statement",
  "switch_statement", "case_list", "case_default", "while_loop",
  "do_while_loop", "for_loop", "function_declaration", "function_call",
  "function_call_expression", "arg_list", "arg_list_call",
  "declaration_assignment", "declaration_assignment_loop", "declaration",
  "assignment", "enum_declaration", "enum_list", "expression",
  "binary_expression", "unary_expression", "type", "value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    43,    45,
      42,    47,    37,   303,   304,    40,    41,    59,    58,    44,
      61,    33
};
#endif

#define YYPACT_NINF (-50)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      96,   -50,   -50,   -50,   -50,   -50,    19,    28,   -50,   499,
     -50,    33,    -2,   -50,   -44,    74,    46,     1,     4,    40,
       5,    22,    24,    73,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,    25,    34,   -50,    84,    38,    74,    29,
      29,    86,    57,    29,    29,   -50,   594,    29,    29,    78,
     -50,   -50,    58,    74,    60,   111,   -50,   -50,   -50,   -50,
     -50,    65,   -50,   -50,    29,    29,    29,   -50,   -49,   711,
     -50,   -50,   -50,   711,    61,   -50,   593,   608,   139,    62,
     117,    75,   -50,   -50,   646,   655,   125,   -50,    80,   118,
      82,    29,   -50,   664,   -50,    77,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,    29,    29,    29,    29,
      29,   128,   132,   120,   147,    29,   148,    99,   107,   -17,
     151,   -50,    74,   -41,   -50,   -50,   711,   137,   137,    18,
      18,    18,    18,   143,   -50,   719,   719,   558,   558,   280,
     498,   -50,   -50,   115,   125,   537,   134,   -50,    29,   121,
     171,   -50,   175,   -50,   -50,   -50,   211,   247,    29,   -12,
     594,    29,     6,   711,   123,   122,   283,   -50,   157,   -50,
     702,   124,   136,     0,    29,   138,   176,    29,    29,   178,
     140,   -50,   181,   -50,    79,   -50,   -50,   711,   547,   -50,
     -50,   -50,   319,   -50,   355,   182,   391,   427,   142,   463,
     144,   -50,   -50,   -50,   -50,   146,   -50,   -50
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,    69,    70,    71,    72,    73,     0,     0,     2,     4,
       3,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,    10,    11,    12,    13,    14,
      15,     9,     7,     0,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     0,     0,     0,
      34,    35,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    65,    80,    79,     0,     0,     0,    66,     0,    33,
      48,    49,    64,    42,     0,    41,     0,     0,     0,     0,
       0,     0,    36,    37,     0,     0,     0,    38,     0,     0,
      31,     0,    67,     0,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     6,     0,     0,    63,    28,    32,    55,    56,    57,
      58,    59,    60,    61,    62,    50,    51,    52,    53,    54,
       0,     6,     6,     0,     0,     0,     0,    16,     0,     0,
       0,     6,     0,    30,    29,    39,     0,     0,     0,     0,
       0,     0,     0,    47,    43,    44,     0,    27,    17,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    40,     0,     6,     0,     6,    19,    45,     0,     6,
      24,     6,     0,     6,     0,     0,     0,     0,     0,     0,
       0,    26,    18,    25,    21,     0,    22,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,   -50,   -45,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -39,   113,   -50,    45,
     -43,   -42,   -50,    70,   -35,   -50,   -50,     2,   -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    24,    25,    26,    27,   162,   176,
      28,    29,    30,    10,    31,    67,    54,    68,    32,    81,
      33,    34,    35,   119,    69,    70,    71,    36,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,   149,    11,    82,    83,    73,   171,    95,    76,    77,
      96,    39,    84,    85,    88,   154,    40,    41,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    12,    13,    92,
      93,    94,    56,    57,    58,    59,    60,    61,    62,    63,
      55,    37,   150,   103,   104,   174,   175,   150,   105,   106,
     107,   108,   109,    38,    42,    55,    43,    45,   183,    44,
      46,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   152,    47,    64,    48,
     145,    49,    50,   153,    65,     1,     2,     3,     4,     5,
      66,    51,    52,    53,    74,    86,   156,   157,    97,    98,
      99,   100,   101,   102,   103,   104,   166,     1,     2,     3,
       4,     5,     6,   163,    75,    87,    89,    82,    83,    90,
      91,   110,    40,   170,    55,   114,   173,   105,   106,   107,
     108,   109,   115,   118,   125,   121,   120,   193,   192,   184,
     194,   122,   187,   188,   196,   141,   197,    14,   199,   142,
       1,     2,     3,     4,     5,   143,   147,   113,    99,   100,
     101,   102,   103,   104,   144,   146,    15,   148,   151,   104,
     158,    16,    17,   161,    18,    19,    20,    21,   164,   165,
     -40,   181,   177,    14,    22,    23,     1,     2,     3,     4,
       5,   179,   182,   167,   186,   189,   185,   190,   191,   204,
     201,   206,    15,   207,   123,   172,     0,    16,    17,     0,
      18,    19,    20,    21,   159,     0,     0,     0,     0,    14,
      22,    23,     1,     2,     3,     4,     5,     0,     0,   168,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,    16,    17,     0,    18,    19,    20,    21,
       0,     0,     0,     0,     0,    14,    22,    23,     1,     2,
       3,     4,     5,     0,     0,   169,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,    16,
      17,     0,    18,    19,    20,    21,     0,     0,     0,     0,
       0,    14,    22,    23,     1,     2,     3,     4,     5,    97,
      98,    99,   100,   101,   102,   103,   104,     0,     0,     0,
      15,     0,     0,     0,     0,    16,    17,     0,    18,    19,
      20,    21,     0,     0,     0,   178,     0,    14,    22,    23,
       1,     2,     3,     4,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,    16,    17,     0,    18,    19,    20,    21,     0,     0,
     198,     0,     0,    14,    22,    23,     1,     2,     3,     4,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     0,     0,     0,    16,    17,     0,
      18,    19,    20,    21,     0,     0,   200,     0,     0,    14,
      22,    23,     1,     2,     3,     4,     5,     0,     0,   202,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,    16,    17,     0,    18,    19,    20,    21,
       0,     0,     0,     0,     0,    14,    22,    23,     1,     2,
       3,     4,     5,     0,     0,   203,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,    16,
      17,     0,    18,    19,    20,    21,     0,     0,     0,     0,
       0,    14,    22,    23,     1,     2,     3,     4,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,    16,    17,     0,    18,    19,
      20,    21,     0,     0,   205,     0,     0,    14,    22,    23,
       1,     2,     3,     4,     5,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,     0,    15,     0,     0,     0,
       0,    16,    17,     0,    18,    19,    20,    21,     0,     0,
       0,     0,     0,     0,    22,    23,   105,   106,   107,   108,
     109,     0,     0,     0,     0,   155,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,   160,   105,   106,   107,   108,   109,
       0,     0,    79,     0,   195,     1,     2,     3,     4,     5,
     109,     0,    97,    98,    99,   100,   101,   102,   103,   104,
       0,    15,     0,     0,     0,     0,    16,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
      80,   105,   106,   107,   108,   109,     0,     0,     0,   111,
       0,     0,     0,     0,     0,     0,   105,   106,   107,   108,
     109,     0,     0,     0,   112,    97,    98,    99,   100,   101,
     102,   103,   104,     0,    97,    98,    99,   100,   101,   102,
     103,   104,     0,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,   106,   107,   108,   109,     0,
       0,     0,   116,   105,   106,   107,   108,   109,     0,     0,
       0,   117,   105,   106,   107,   108,   109,     0,     0,     0,
     124,    97,    98,    99,   100,   101,   102,   103,   104,     0,
      97,    98,    99,   100,   101,   102,   103,   104,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,     0,     0,
     105,   106,   107,   108,   109,     0,     0,     0,   180,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,   107,
     108,   109
};

static const yytype_int16 yycheck[] =
{
      45,    18,     0,    46,    46,    40,    18,    56,    43,    44,
      59,    55,    47,    48,    53,    56,    60,    15,    59,    19,
      20,    21,    22,    23,    24,    25,    26,     8,     0,    64,
      65,    66,     3,     4,     5,     6,     7,     8,     9,    10,
      38,     8,    59,    25,    26,    39,    40,    59,    48,    49,
      50,    51,    52,    55,     8,    53,    55,    17,    58,    55,
      55,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   121,    55,    49,    55,
     115,     8,    57,   122,    55,    11,    12,    13,    14,    15,
      61,    57,     8,    55,     8,    17,   141,   142,    19,    20,
      21,    22,    23,    24,    25,    26,   151,    11,    12,    13,
      14,    15,    16,   148,    57,    57,    56,   160,   160,     8,
      55,    60,    60,   158,   122,     8,   161,    48,    49,    50,
      51,    52,    57,     8,    57,    17,    56,    58,   183,   174,
     185,    59,   177,   178,   189,    17,   191,     8,   193,    17,
      11,    12,    13,    14,    15,    35,    57,    18,    21,    22,
      23,    24,    25,    26,    17,    17,    27,    60,    17,    26,
      55,    32,    33,    39,    35,    36,    37,    38,    57,     8,
      57,    57,    60,     8,    45,    46,    11,    12,    13,    14,
      15,    34,    56,    18,    18,    17,    58,    57,    17,    57,
      18,    57,    27,    57,    91,   160,    -1,    32,    33,    -1,
      35,    36,    37,    38,   144,    -1,    -1,    -1,    -1,     8,
      45,    46,    11,    12,    13,    14,    15,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,     8,    45,    46,    11,    12,
      13,    14,    15,    -1,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
      33,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,     8,    45,    46,    11,    12,    13,    14,    15,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    32,    33,    -1,    35,    36,
      37,    38,    -1,    -1,    -1,    42,    -1,     8,    45,    46,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    32,    33,    -1,    35,    36,    37,    38,    -1,    -1,
      41,    -1,    -1,     8,    45,    46,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,    -1,
      35,    36,    37,    38,    -1,    -1,    41,    -1,    -1,     8,
      45,    46,    11,    12,    13,    14,    15,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,     8,    45,    46,    11,    12,
      13,    14,    15,    -1,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
      33,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,     8,    45,    46,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    32,    33,    -1,    35,    36,
      37,    38,    -1,    -1,    41,    -1,    -1,     8,    45,    46,
      11,    12,    13,    14,    15,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    27,    -1,    -1,    -1,
      -1,    32,    33,    -1,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    57,    48,    49,    50,    51,    52,
      -1,    -1,     8,    -1,    57,    11,    12,    13,    14,    15,
      52,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    27,    -1,    -1,    -1,    -1,    32,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      46,    48,    49,    50,    51,    52,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    56,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    56,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    56,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      56,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    56,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    12,    13,    14,    15,    16,    63,    64,    65,
      75,    89,     8,     0,     8,    27,    32,    33,    35,    36,
      37,    38,    45,    46,    66,    67,    68,    69,    72,    73,
      74,    76,    80,    82,    83,    84,    89,     8,    55,    55,
      60,    89,     8,    55,    55,    17,    55,    55,    55,     8,
      57,    57,     8,    55,    78,    89,     3,     4,     5,     6,
       7,     8,     9,    10,    49,    55,    61,    77,    79,    86,
      87,    88,    90,    86,     8,    57,    86,    86,    65,     8,
      46,    81,    82,    83,    86,    86,    17,    57,    78,    56,
       8,    55,    86,    86,    86,    56,    59,    19,    20,    21,
      22,    23,    24,    25,    26,    48,    49,    50,    51,    52,
      60,    56,    56,    18,     8,    57,    56,    56,     8,    85,
      56,    17,    59,    79,    56,    57,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    17,    17,    35,    17,    86,    17,    57,    60,    18,
      59,    17,    65,    78,    56,    57,    65,    65,    55,    85,
      57,    39,    70,    86,    57,     8,    65,    18,    18,    18,
      86,    18,    81,    86,    39,    40,    71,    60,    42,    34,
      56,    57,    56,    58,    86,    58,    18,    86,    86,    17,
      57,    17,    65,    58,    65,    57,    65,    65,    41,    65,
      41,    18,    18,    18,    57,    41,    57,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    68,    68,    69,
      70,    70,    71,    72,    73,    74,    75,    75,    76,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    83,    84,    85,    85,    85,    85,    86,    86,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    88,    89,
      89,    89,    89,    89,    90,    90,    90,    90,    90,    90,
      90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     7,    11,     8,
       7,     6,     5,     7,     9,    11,    11,     8,     5,     4,
       4,     2,     3,     1,     2,     2,     1,     1,     3,     6,
       6,     3,     3,     6,     3,     5,     1,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
  case 2: /* program: function_or_statement  */
#line 71 "Compiler.y"
                                                             {printf("start of program");}
#line 1583 "y.tab.c"
    break;

  case 3: /* function_or_statement: function_declaration  */
#line 74 "Compiler.y"
                                                             {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1589 "y.tab.c"
    break;

  case 4: /* function_or_statement: statement_list  */
#line 75 "Compiler.y"
                                                             {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1595 "y.tab.c"
    break;

  case 5: /* statement_list: statement_list statement  */
#line 78 "Compiler.y"
                                                             {(yyval.nPtr)=(yyvsp[-1].nPtr);}
#line 1601 "y.tab.c"
    break;

  case 6: /* statement_list: %empty  */
#line 79 "Compiler.y"
                                                             {(yyval.nPtr)=NULL;}
#line 1607 "y.tab.c"
    break;

  case 7: /* statement: declaration_assignment  */
#line 83 "Compiler.y"
                                                             { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1613 "y.tab.c"
    break;

  case 8: /* statement: enum_declaration  */
#line 84 "Compiler.y"
                                                            { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1619 "y.tab.c"
    break;

  case 9: /* statement: function_call  */
#line 85 "Compiler.y"
                                                            { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1625 "y.tab.c"
    break;

  case 10: /* statement: print_statement  */
#line 86 "Compiler.y"
                                                            { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1631 "y.tab.c"
    break;

  case 11: /* statement: if_statement  */
#line 87 "Compiler.y"
                                                            { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1637 "y.tab.c"
    break;

  case 12: /* statement: switch_statement  */
#line 88 "Compiler.y"
                                                            { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1643 "y.tab.c"
    break;

  case 13: /* statement: while_loop  */
#line 89 "Compiler.y"
                                                            { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1649 "y.tab.c"
    break;

  case 14: /* statement: do_while_loop  */
#line 90 "Compiler.y"
                                                           { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1655 "y.tab.c"
    break;

  case 15: /* statement: for_loop  */
#line 91 "Compiler.y"
                                                           { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1661 "y.tab.c"
    break;

  case 16: /* print_statement: PRINT '(' expression ')' ';'  */
#line 96 "Compiler.y"
                                                                  {(yyval.nPtr)= CreateOperatorNode(PRINT, 1, (yyvsp[-2].nPtr));}
#line 1667 "y.tab.c"
    break;

  case 17: /* if_statement: IF '(' expression ')' LBRACE statement_list RBRACE  */
#line 100 "Compiler.y"
                                                                                     {(yyval.nPtr) = createOperatorNode(IF,2,(yyvsp[-4].nPtr),(yyvsp[-1].nPtr));}
#line 1673 "y.tab.c"
    break;

  case 18: /* if_statement: IF '(' expression ')' LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE  */
#line 101 "Compiler.y"
                                                                                                                       {(yyval.nPtr) = createOperatorNode(IF, 2, (yyvsp[-8].nPtr), (yyvsp[-5].nPtr), (yyvsp[-1].nPtr));}
#line 1679 "y.tab.c"
    break;

  case 19: /* switch_statement: SWITCH '(' expression ')' LBRACE case_list case_default RBRACE  */
#line 106 "Compiler.y"
                                                                                          {(yyval.nPtr) = createOperatorNode(SWITCH, 2, (yyvsp[-5].nPtr), (yyvsp[-2].nPtr));}
#line 1685 "y.tab.c"
    break;

  case 20: /* case_list: case_list CASE expression ':' statement_list BREAK ';'  */
#line 109 "Compiler.y"
                                                                               {(yyval.nPtr) = createOperatorNode(CASE,3,(yyvsp[-6].nPtr),(yyvsp[-4].nPtr),(yyvsp[-2].nPtr));}
#line 1691 "y.tab.c"
    break;

  case 21: /* case_list: CASE expression ':' statement_list BREAK ';'  */
#line 110 "Compiler.y"
                                                                               {(yyval.nPtr) = createOperatorNode(CASE, 2, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr));}
#line 1697 "y.tab.c"
    break;

  case 22: /* case_default: DEFAULT ':' statement_list BREAK ';'  */
#line 116 "Compiler.y"
                                                                              {(yyval.nPtr) = createOperatorNode(DEFAULT, 1, (yyvsp[-2].nPtr));}
#line 1703 "y.tab.c"
    break;

  case 23: /* while_loop: WHILE '(' expression ')' LBRACE statement_list RBRACE  */
#line 120 "Compiler.y"
                                                                                {(yyval.nPtr) = createOperatorNode(WHILE, 2, (yyvsp[-4].nPtr), (yyvsp[-1].nPtr));}
#line 1709 "y.tab.c"
    break;

  case 24: /* do_while_loop: DO LBRACE statement_list RBRACE WHILE '(' expression ')' ';'  */
#line 123 "Compiler.y"
                                                                                       { (yyval.nPtr) = createOperatorNode(DO_WHILE, 2, (yyvsp[-6].nPtr), (yyvsp[-2].nPtr));}
#line 1715 "y.tab.c"
    break;

  case 25: /* for_loop: FOR '(' declaration_assignment_loop ';' expression ';' declaration_assignment_loop ')' LBRACE statement_list RBRACE  */
#line 127 "Compiler.y"
                                                                                                                                           {(yyval.nPtr) = createOperatorNode(FOR, 3, (yyvsp[-8].nPtr), (yyvsp[-6].nPtr), (yyvsp[-4].nPtr));}
#line 1721 "y.tab.c"
    break;

  case 26: /* function_declaration: type IDENTIFIER '(' arg_list ')' LBRACE statement_list RETURN expression ';' RBRACE  */
#line 131 "Compiler.y"
                                                                                                           { (yyval.nPtr)=createOperatorNode(FUNC, 3, createTypeNode((yyvsp[-10].nPtr)->typ.type), createIdentifierNode((yyvsp[-9].sVal)), (yyvsp[-7].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr));}
#line 1727 "y.tab.c"
    break;

  case 27: /* function_declaration: VOID_TYPE IDENTIFIER '(' arg_list ')' LBRACE statement_list RBRACE  */
#line 132 "Compiler.y"
                                                                                            { (yyval.nPtr)=createOperatorNode(FUNC, 4, createTypeNode(typeVoid), createIdentifierNode((yyvsp[-6].sVal)), (yyvsp[-4].nPtr), (yyvsp[-1].nPtr));}
#line 1733 "y.tab.c"
    break;

  case 28: /* function_call: IDENTIFIER '(' arg_list_call ')' ';'  */
#line 135 "Compiler.y"
                                                                { (yyval.nPtr)=createOperatorNode(FUNC, 1, createIdentifierNode((yyvsp[-4].sVal)), (yyvsp[-2].nPtr));}
#line 1739 "y.tab.c"
    break;

  case 29: /* function_call_expression: IDENTIFIER '(' arg_list_call ')'  */
#line 138 "Compiler.y"
                                                                 { (yyval.nPtr)=createOperatorNode(FUNC, 1, createIdentifierNode((yyvsp[-3].sVal)), (yyvsp[-1].nPtr));}
#line 1745 "y.tab.c"
    break;

  case 30: /* arg_list: type IDENTIFIER ',' arg_list  */
#line 141 "Compiler.y"
                                                                 { (yyval.nPtr)=createOperatorNode(',', 2, createTypeNode((yyvsp[-3].nPtr)->typ.type), createIdentifierNode((yyvsp[-2].sVal)));}
#line 1751 "y.tab.c"
    break;

  case 31: /* arg_list: type IDENTIFIER  */
#line 142 "Compiler.y"
                                                                 { (yyval.nPtr)=createOperatorNode(',', 2, createTypeNode((yyvsp[-1].nPtr)->typ.type), createIdentifierNode((yyvsp[0].sVal)));}
#line 1757 "y.tab.c"
    break;

  case 32: /* arg_list_call: arg_list_call ',' expression  */
#line 145 "Compiler.y"
                                                                 { (yyval.nPtr)=createOperatorNode(',', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1763 "y.tab.c"
    break;

  case 33: /* arg_list_call: expression  */
#line 146 "Compiler.y"
                                                                 { (yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1769 "y.tab.c"
    break;

  case 34: /* declaration_assignment: declaration ';'  */
#line 151 "Compiler.y"
                                                                  {(yyval.nPtr)=(yyvsp[-1].nPtr);}
#line 1775 "y.tab.c"
    break;

  case 35: /* declaration_assignment: assignment ';'  */
#line 152 "Compiler.y"
                                                                   {(yyval.nPtr)=(yyvsp[-1].nPtr);}
#line 1781 "y.tab.c"
    break;

  case 36: /* declaration_assignment_loop: declaration  */
#line 155 "Compiler.y"
                                                                 { (yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1787 "y.tab.c"
    break;

  case 37: /* declaration_assignment_loop: assignment  */
#line 156 "Compiler.y"
                                                                 { (yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1793 "y.tab.c"
    break;

  case 38: /* declaration: type IDENTIFIER ';'  */
#line 158 "Compiler.y"
                                                                                { (yyval.nPtr) = createOperatorNode(VAR_DECL, 2, createTypeNode((yyvsp[-2].nPtr)->typ.type), createIdentifierNode((yyvsp[-1].sVal))); }
#line 1799 "y.tab.c"
    break;

  case 39: /* declaration: CONST type IDENTIFIER '=' expression ';'  */
#line 159 "Compiler.y"
                                                                               { (yyval.nPtr) = createOperatorNode(CONST_DECL, 2, createTypeNode((yyvsp[-4].nPtr)->typ.type), createIdentifierNode((yyvsp[-3].sVal)), (yyvsp[-1].nPtr)); }
#line 1805 "y.tab.c"
    break;

  case 40: /* declaration: ENUM IDENTIFIER LBRACE enum_list RBRACE ';'  */
#line 160 "Compiler.y"
                                                                                { (yyval.nPtr) = createOperatorNode(ENUM_DECL, 2, createIdentifierNode((yyvsp[-4].sVal)), (yyvsp[-2].nPtr)); }
#line 1811 "y.tab.c"
    break;

  case 41: /* declaration: VAR IDENTIFIER ';'  */
#line 161 "Compiler.y"
                                                                               { (yyval.nPtr) = createOperatorNode(VAR_DECL, 2, createTypeNode(typeVar), createIdentifierNode((yyvsp[-1].sVal))); }
#line 1817 "y.tab.c"
    break;

  case 42: /* assignment: IDENTIFIER '=' expression  */
#line 165 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode('=', 2, createIdentifierNode((yyvsp[-2].sVal)), (yyvsp[0].nPtr));}
#line 1823 "y.tab.c"
    break;

  case 43: /* enum_declaration: ENUM IDENTIFIER LBRACE enum_list RBRACE ';'  */
#line 169 "Compiler.y"
                                                                       {(yyval.nPtr)=createOperatorNode(ENUM, 2, createIdentifierNode((yyvsp[-4].sVal)), (yyvsp[-2].nPtr));}
#line 1829 "y.tab.c"
    break;

  case 44: /* enum_list: enum_list ',' IDENTIFIER  */
#line 172 "Compiler.y"
                                                                        { (yyval.nPtr) = createOperatorNode(ENUM, 1, createIdentifierNode((yyvsp[0].sVal))); }
#line 1835 "y.tab.c"
    break;

  case 45: /* enum_list: enum_list ',' IDENTIFIER '=' expression  */
#line 173 "Compiler.y"
                                                                       { (yyval.nPtr) = createOperatorNode(ENUM, 2, createIdentifierNode((yyvsp[-2].sVal)), (yyvsp[0].nPtr)); }
#line 1841 "y.tab.c"
    break;

  case 46: /* enum_list: IDENTIFIER  */
#line 174 "Compiler.y"
                                                                        { (yyval.nPtr) = createOperatorNode(ENUM, 1, createIdentifierNode((yyvsp[0].sVal))); }
#line 1847 "y.tab.c"
    break;

  case 47: /* enum_list: IDENTIFIER '=' expression  */
#line 175 "Compiler.y"
                                                                       { (yyval.nPtr) = createOperatorNode(ENUM, 2, createIdentifierNode((yyvsp[-2].sVal)), (yyvsp[0].nPtr)); }
#line 1853 "y.tab.c"
    break;

  case 48: /* expression: binary_expression  */
#line 179 "Compiler.y"
                                             { (yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1859 "y.tab.c"
    break;

  case 49: /* expression: unary_expression  */
#line 180 "Compiler.y"
                                             { (yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1865 "y.tab.c"
    break;

  case 50: /* binary_expression: expression '+' expression  */
#line 183 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1871 "y.tab.c"
    break;

  case 51: /* binary_expression: expression '-' expression  */
#line 184 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1877 "y.tab.c"
    break;

  case 52: /* binary_expression: expression '*' expression  */
#line 185 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1883 "y.tab.c"
    break;

  case 53: /* binary_expression: expression '/' expression  */
#line 186 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1889 "y.tab.c"
    break;

  case 54: /* binary_expression: expression '%' expression  */
#line 187 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1895 "y.tab.c"
    break;

  case 55: /* binary_expression: expression EQ expression  */
#line 188 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1901 "y.tab.c"
    break;

  case 56: /* binary_expression: expression NEQ expression  */
#line 189 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(NEQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1907 "y.tab.c"
    break;

  case 57: /* binary_expression: expression LT expression  */
#line 190 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(LT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1913 "y.tab.c"
    break;

  case 58: /* binary_expression: expression GT expression  */
#line 191 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(GT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1919 "y.tab.c"
    break;

  case 59: /* binary_expression: expression LTE expression  */
#line 192 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(LTE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1925 "y.tab.c"
    break;

  case 60: /* binary_expression: expression GTE expression  */
#line 193 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(GTE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1931 "y.tab.c"
    break;

  case 61: /* binary_expression: expression AND expression  */
#line 194 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1937 "y.tab.c"
    break;

  case 62: /* binary_expression: expression OR expression  */
#line 195 "Compiler.y"
                                                     { (yyval.nPtr)=createOperatorNode(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1943 "y.tab.c"
    break;

  case 63: /* binary_expression: '(' expression ')'  */
#line 196 "Compiler.y"
                                                     { (yyval.nPtr)=(yyvsp[-1].nPtr); }
#line 1949 "y.tab.c"
    break;

  case 64: /* binary_expression: value  */
#line 197 "Compiler.y"
                                                     { (yyval.nPtr)=(yyvsp[0].nPtr); }
#line 1955 "y.tab.c"
    break;

  case 65: /* binary_expression: IDENTIFIER  */
#line 198 "Compiler.y"
                                                     { (yyval.nPtr)=createIdentifierNode((yyvsp[0].sVal)); }
#line 1961 "y.tab.c"
    break;

  case 66: /* binary_expression: function_call_expression  */
#line 199 "Compiler.y"
                                                     { (yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1967 "y.tab.c"
    break;

  case 67: /* unary_expression: '-' expression  */
#line 202 "Compiler.y"
                                                      { (yyval.nPtr) = createOperatorNode('-', 1, (yyvsp[0].nPtr)); }
#line 1973 "y.tab.c"
    break;

  case 68: /* unary_expression: '!' expression  */
#line 203 "Compiler.y"
                                                      { (yyval.nPtr) = createOperatorNode('!', 1, (yyvsp[0].nPtr)); }
#line 1979 "y.tab.c"
    break;

  case 69: /* type: INT_TYPE  */
#line 207 "Compiler.y"
                                     { (yyval.nPtr) = createTypeNode(typeInt); }
#line 1985 "y.tab.c"
    break;

  case 70: /* type: FLOAT_TYPE  */
#line 208 "Compiler.y"
                                     { (yyval.nPtr) = createTypeNode(typeFloat); }
#line 1991 "y.tab.c"
    break;

  case 71: /* type: BOOL_TYPE  */
#line 209 "Compiler.y"
                                     { (yyval.nPtr) = createTypeNode(typeBool); }
#line 1997 "y.tab.c"
    break;

  case 72: /* type: CHAR_TYPE  */
#line 210 "Compiler.y"
                                     { (yyval.nPtr) = createTypeNode(typeChar); }
#line 2003 "y.tab.c"
    break;

  case 73: /* type: STRING_TYPE  */
#line 211 "Compiler.y"
                                      { (yyval.nPtr) = createTypeNode(typeString); }
#line 2009 "y.tab.c"
    break;

  case 74: /* value: INTEGER  */
#line 214 "Compiler.y"
                                  { (yyval.nPtr) = createIntConstantNode((yyvsp[0].iVal)); }
#line 2015 "y.tab.c"
    break;

  case 75: /* value: FLOAT  */
#line 215 "Compiler.y"
                                  { (yyval.nPtr) = createFloatConstantNode((yyvsp[0].fVal)); }
#line 2021 "y.tab.c"
    break;

  case 76: /* value: BOOL  */
#line 216 "Compiler.y"
                                  { (yyval.nPtr) = createBoolConstantNode((yyvsp[0].bVal)); }
#line 2027 "y.tab.c"
    break;

  case 77: /* value: CHAR  */
#line 217 "Compiler.y"
                                  { (yyval.nPtr) = createCharConstantNode((yyvsp[0].cVal)); }
#line 2033 "y.tab.c"
    break;

  case 78: /* value: STRING  */
#line 218 "Compiler.y"
                                  { (yyval.nPtr) = createStringConstantNode((yyvsp[0].sVal)); }
#line 2039 "y.tab.c"
    break;

  case 79: /* value: BOOL_TRUE  */
#line 219 "Compiler.y"
                                     { (yyval.nPtr) = createBoolConstantNode((yyvsp[0].bVal)); }
#line 2045 "y.tab.c"
    break;

  case 80: /* value: BOOL_FALSE  */
#line 220 "Compiler.y"
                                     { (yyval.nPtr) = createBoolConstantNode((yyvsp[0].bVal)); }
#line 2051 "y.tab.c"
    break;


#line 2055 "y.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 223 "Compiler.y"



extern FILE *yyin;
FILE *errorsFile;

void yyerror(const char *s) {
    fprintf(errorsFile, "Syntax error at line %d: %s\n", currentLineNumber, s);
}
nodeType *createTypeNode(conEnum type) {
    nodeType *p;

    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("Memory allocation failed");

    /* Copy information */
    p->type = typeDef;
    p->typ.type = type;

    return p;
}

nodeType *createConstantNode() {
    nodeType *p;

    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("Memory allocation failed");

    /* Set the node type */
    p->type = typeCon;

    return p;
}

nodeType *createIntConstantNode(int value) {
    nodeType *p = createConstantNode();

    p->con.type = typeInt;
    p->con.iValue = value;
    
    return p;
}

nodeType *createFloatConstantNode(float value) {
    nodeType *p = createConstantNode();

    p->con.type = typeFloat;
    p->con.fValue = value;

    return p;
}

nodeType *createBoolConstantNode(bool value) {
    nodeType *p = createConstantNode();

    p->con.type = typeBool;
    p->con.iValue = value;

    return p;
}

nodeType *createCharConstantNode(char value) {
    nodeType *p = createConstantNode();

    p->con.type = typeChar;
    p->con.cValue = value;

    return p;
}

nodeType *createStringConstantNode(char* value) {
    nodeType *p = createConstantNode();

    p->con.type = typeString;
    p->con.sValue = value;

    return p;
}

nodeType *createIdentifierNode(char* id) {
    nodeType *p;

    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("Memory allocation failed");

    p->type = typeId;
    p->id.id = id;

    return p;
}

// Create a node representing an operator
nodeType *createOperatorNode(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("Memory allocation failed");

    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}


void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free(p);
}
int main(int argc, char **argv) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(fp);
        return 1;
    }

    errorsFile = outputFile;

    yyin = fp;

    yyparse();

    fclose(fp);
    fclose(outputFile);

    return 0;
}
