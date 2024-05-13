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

    void yyerror(const char *s);
  
    int yylex();
    extern FILE *yyin;
    extern FILE *errorsFile;
    extern int currentLineNumber;

    int currentScope = 0;
    SymbolTable *table;

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
#line 22 "Compiler.y"

    int iVal;
    float fVal;
    bool bVal;
    char cVal;
    char *sVal;
    nodeType *nPtr;

#line 251 "y.tab.c"

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
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1236

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
static const yytype_uint8 yyrline[] =
{
       0,    66,    66,    70,    71,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    90,    93,    94,    96,
      99,   100,   103,   108,   110,   113,   117,   118,   119,   122,
     125,   128,   129,   131,   132,   133,   139,   140,   143,   144,
     147,   148,   149,   150,   151,   154,   158,   162,   163,   164,
     165,   170,   171,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     191,   192,   196,   197,   198,   199,   200,   203,   204,   205,
     206,   207,   208,   209,   212,   215
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

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     957,  -131,  -131,  -131,  -131,  -131,   -41,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,     9,    62,    14,   -24,   -20,    21,
     -16,   -15,   -14,    36,    81,    81,    81,    60,   957,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
     -12,     4,  -131,  1176,  -131,  -131,    54,  -131,    81,    81,
      25,    73,  -131,    81,    81,  -131,  1059,    81,    81,     1,
      38,  -131,  1058,  -131,  -131,  -131,  -131,  -131,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,   -40,   -46,  1176,  1176,    62,    34,  1073,  1111,   957,
      39,    90,    44,  -131,  -131,    96,  1120,  1129,    46,    99,
      81,  -131,    94,    94,     0,     0,     0,     0,    86,  -131,
    1184,  1184,   365,   365,    45,    62,    81,    56,    81,    65,
     115,    81,   107,   109,   190,   120,    81,    71,   118,    75,
     129,    87,   -17,   -35,    92,  1176,  -131,  1176,   133,    93,
    1176,  -131,  -131,  -131,   164,   114,  -131,  -131,    81,    89,
     147,  -131,   139,  -131,    62,   957,   957,   122,  1059,    81,
     -10,  1176,  -131,    98,  -131,   957,  -131,   249,   308,   108,
     106,  1000,    81,   112,   146,    81,   367,   426,  -131,  -131,
      81,   148,   957,  1011,   957,  -131,  1176,   957,   485,  -131,
     137,  -131,  1167,  -131,   544,   957,   603,   662,   957,  -131,
     150,   116,   957,   123,   721,   124,  -131,   780,  -131,  -131,
     839,  -131,   134,  -131,  -131,   157,   957,  -131,  -131,  -131,
     898,  -131,  -131,  -131,  -131
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    77,    78,    79,    80,    81,    68,    83,    82,    72,
      73,    74,    75,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       8,     9,    10,    11,    12,    13,    14,     7,    69,     5,
       0,     0,     6,    15,    51,    52,     0,    67,    35,     0,
       0,     0,    44,     0,     0,    84,     0,     0,     0,     0,
      68,    70,     0,    71,     1,     4,    36,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    40,     0,    34,    45,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,     0,     0,     0,     0,     0,
      35,    66,    58,    59,    60,    61,    62,    63,    64,    65,
      53,    54,    55,    56,    57,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,    49,     0,     0,     0,    41,    29,    33,     0,    32,
      42,    84,    84,    85,     0,     0,    16,    43,     0,     0,
       0,    30,     0,    84,     0,     0,     0,     0,     0,     0,
       0,    50,    46,    47,    84,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    85,
       0,     0,     0,     0,     0,    19,    48,     0,     0,    85,
      17,    23,     0,    84,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,     0,     0,    85,     0,    84,    24,
       0,    21,     0,    22,    28,     0,     0,    85,    20,    85,
       0,    25,    26,    85,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,   -73,   -28,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -108,    77,  -131,    49,   -50,
     -48,  -131,  -131,   -21,  -131,  -131,   -13,  -131,  -130,   -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    27,    28,    29,    30,    31,    32,   160,   174,    33,
      34,    35,    36,    37,    38,   119,    82,    39,    92,    40,
      41,    42,   132,    43,    44,    45,    46,    47,    89,   157
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      65,   149,    51,    61,    62,    63,    93,   134,    94,    98,
     117,   155,   156,   118,    48,   115,   124,    50,    99,    49,
     116,   151,    52,   165,   118,    74,    75,    83,    84,   172,
     173,    53,    87,    88,   176,    54,    96,    97,    55,    56,
      57,    58,   150,    95,    59,    66,   166,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      64,    67,    81,   202,    68,    69,    70,    71,    72,    73,
      74,    75,   120,     9,    10,    11,    12,    13,   216,    83,
      85,    86,   167,   168,     1,     2,     3,     4,     5,    60,
       7,     8,   177,   100,   121,   135,    65,   137,   125,    49,
     140,   126,   120,   188,   127,   144,   130,   131,    93,   194,
      94,   196,    75,   136,   197,    70,    71,    72,    73,    74,
      75,   138,   204,   139,   141,   207,   142,   161,    98,   210,
      24,   116,   146,   190,   191,   145,    25,   147,   171,    65,
      65,   120,    26,   220,   199,    95,   162,   148,   152,    65,
     153,   183,   154,   159,   186,   163,   164,   169,   175,   192,
      65,   214,   181,   180,   185,   193,    65,   208,    65,    65,
     184,   200,   221,   209,   222,   219,    65,   133,   224,    65,
     211,   213,    65,    68,    69,    70,    71,    72,    73,    74,
      75,   218,    65,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,   170,   143,     0,
       0,     0,    76,    77,    78,    79,    80,    15,     0,     0,
       0,   158,    16,    17,     0,    18,    19,    20,    21,     0,
       0,     0,     0,     0,     0,    22,    23,     0,     0,    24,
       0,     0,     0,     0,     0,    25,     0,     0,     0,     0,
       0,    26,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,    16,    17,     0,    18,    19,    20,    21,     0,     0,
       0,     0,     0,     0,    22,    23,     0,     0,    24,     0,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
      26,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,   179,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
      16,    17,     0,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,    22,    23,     0,     0,    24,     0,     0,
       0,     0,     0,    25,     0,     0,     0,     0,     0,    26,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    15,     0,     0,     0,     0,    16,
      17,     0,    18,    19,    20,    21,     0,     0,     0,   187,
       0,     0,    22,    23,     0,     0,    24,    80,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,    26,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,   189,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,    16,    17,
       0,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,    22,    23,     0,     0,    24,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     0,    26,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     0,     0,     0,    16,    17,     0,
      18,    19,    20,    21,     0,     0,     0,   198,     0,     0,
      22,    23,     0,     0,    24,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     0,     0,    26,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,    16,    17,     0,    18,
      19,    20,    21,     0,     0,   203,     0,     0,     0,    22,
      23,     0,     0,    24,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,    26,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,    16,    17,     0,    18,    19,
      20,    21,     0,     0,   205,     0,     0,     0,    22,    23,
       0,     0,    24,     0,     0,     0,     0,     0,    25,     0,
       0,     0,     0,     0,    26,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
     206,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,    16,    17,     0,    18,    19,    20,
      21,     0,     0,     0,     0,     0,     0,    22,    23,     0,
       0,    24,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,    26,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,    16,    17,     0,    18,    19,    20,    21,
       0,     0,   212,     0,     0,     0,    22,    23,     0,     0,
      24,     0,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,    26,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,    16,    17,     0,    18,    19,    20,    21,     0,
       0,     0,     0,     0,     0,    22,    23,     0,     0,    24,
       0,     0,     0,     0,     0,    25,     0,   215,     0,     0,
       0,    26,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,   217,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,    16,    17,     0,    18,    19,    20,    21,     0,     0,
       0,     0,     0,     0,    22,    23,     0,     0,    24,     0,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
      26,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,   223,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
      16,    17,     0,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,    22,    23,     0,     0,    24,     0,     0,
       0,     0,     0,    25,     0,     0,     0,     0,     0,    26,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,    16,
      17,     0,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,    22,    23,     0,     0,    24,     0,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,    26,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,     0,     0,     0,     0,     0,   182,    76,
      77,    78,    79,    80,     0,     0,     0,    90,     0,   195,
       9,    10,    11,    12,    13,     0,     0,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    15,     0,     0,     0,
       0,    16,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,     0,     0,     0,    91,    76,    77,    78,    79,
      80,     0,     0,     0,   101,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,     0,     0,     0,   122,
      68,    69,    70,    71,    72,    73,    74,    75,     0,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,     0,    76,
      77,    78,    79,    80,     0,     0,     0,   123,    76,    77,
      78,    79,    80,     0,     0,     0,   128,    76,    77,    78,
      79,    80,     0,     0,     0,   129,    68,    69,    70,    71,
      72,    73,    74,    75,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,     0,     0,    76,    77,    78,    79,    80,
       0,     0,     0,   201,    76,    77,    78,    79,    80,     0,
       0,     0,     0,     0,    78,    79,    80
};

static const yytype_int16 yycheck[] =
{
      28,    18,    15,    24,    25,    26,    56,   115,    56,     8,
      56,   141,   142,    59,    55,    55,    89,     8,    17,    60,
      60,    56,     8,   153,    59,    25,    26,    48,    49,    39,
      40,    55,    53,    54,   164,    55,    57,    58,    17,    55,
      55,    55,    59,    56,     8,    57,   154,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
       0,    57,     8,   193,    19,    20,    21,    22,    23,    24,
      25,    26,    85,    11,    12,    13,    14,    15,   208,   100,
      55,     8,   155,   156,     3,     4,     5,     6,     7,     8,
       9,    10,   165,    55,    60,   116,   124,   118,     8,    60,
     121,    57,   115,   176,     8,   126,    60,     8,   158,   182,
     158,   184,    26,    57,   187,    21,    22,    23,    24,    25,
      26,    56,   195,     8,    17,   198,    17,   148,     8,   202,
      49,    60,    57,   178,   179,    17,    55,     8,   159,   167,
     168,   154,    61,   216,   189,   158,    57,    60,    56,   177,
      17,   172,    59,    39,   175,     8,    17,    35,    60,   180,
     188,   206,    56,    55,    18,    17,   194,    17,   196,   197,
      58,    34,   217,    57,   219,    18,   204,   100,   223,   207,
      57,    57,   210,    19,    20,    21,    22,    23,    24,    25,
      26,    57,   220,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   158,    18,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    27,    -1,    -1,
      -1,    57,    32,    33,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    61,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    32,    33,    -1,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      61,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      32,    33,    -1,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
      33,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    42,
      -1,    -1,    45,    46,    -1,    -1,    49,    52,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,
      -1,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    61,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,    -1,
      35,    36,    37,    38,    -1,    -1,    -1,    42,    -1,    -1,
      45,    46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    61,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    32,    33,    -1,    35,
      36,    37,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,
      46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    61,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    32,    33,    -1,    35,    36,
      37,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    61,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    61,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,    38,
      -1,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    61,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    32,    33,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    57,    -1,    -1,
      -1,    61,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    32,    33,    -1,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      61,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      32,    33,    -1,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
      33,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    48,
      49,    50,    51,    52,    -1,    -1,    -1,     8,    -1,    58,
      11,    12,    13,    14,    15,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    27,    -1,    -1,    -1,
      -1,    32,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    46,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    -1,    -1,    -1,    56,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    56,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    56,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    56,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    56,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    27,    32,    33,    35,    36,
      37,    38,    45,    46,    49,    55,    61,    63,    64,    65,
      66,    67,    68,    71,    72,    73,    74,    75,    76,    79,
      81,    82,    83,    85,    86,    87,    88,    89,    55,    60,
       8,    88,     8,    55,    55,    17,    55,    55,    55,     8,
       8,    85,    85,    85,     0,    65,    57,    57,    19,    20,
      21,    22,    23,    24,    25,    26,    48,    49,    50,    51,
      52,     8,    78,    85,    85,    55,     8,    85,    85,    90,
       8,    46,    80,    81,    82,    88,    85,    85,     8,    17,
      55,    56,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    55,    60,    56,    59,    77,
      88,    60,    56,    56,    64,     8,    57,     8,    56,    56,
      60,     8,    84,    78,    77,    85,    57,    85,    56,     8,
      85,    17,    17,    18,    85,    17,    57,     8,    60,    18,
      59,    56,    56,    17,    59,    90,    90,    91,    57,    39,
      69,    85,    57,     8,    17,    90,    77,    64,    64,    35,
      80,    85,    39,    40,    70,    60,    90,    64,    18,    18,
      55,    56,    58,    85,    58,    18,    85,    42,    64,    18,
      91,    91,    85,    17,    64,    58,    64,    64,    42,    91,
      34,    56,    90,    41,    64,    41,    18,    64,    17,    57,
      64,    57,    41,    57,    91,    57,    90,    18,    57,    18,
      64,    91,    91,    18,    91
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    67,    67,    68,
      69,    69,    70,    71,    72,    73,    74,    74,    74,    75,
      76,    77,    77,    78,    78,    78,    79,    79,    80,    80,
      81,    81,    81,    81,    81,    82,    83,    84,    84,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    88,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    90,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     9,    15,     8,
       7,     6,     5,     9,    11,    13,    13,    10,    11,     5,
       4,     4,     2,     3,     1,     0,     2,     2,     1,     1,
       2,     4,     5,     5,     2,     3,     6,     3,     5,     1,
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
  case 2: /* program: statement_list  */
#line 66 "Compiler.y"
                                                            {printf("start of program\n");}
#line 1666 "y.tab.c"
    break;

  case 3: /* statement_list: statement  */
#line 70 "Compiler.y"
                                                             {}
#line 1672 "y.tab.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 71 "Compiler.y"
                                                             {}
#line 1678 "y.tab.c"
    break;

  case 5: /* statement: declaration_assignment  */
#line 76 "Compiler.y"
                                                            {}
#line 1684 "y.tab.c"
    break;

  case 6: /* statement: enum_declaration  */
#line 77 "Compiler.y"
                                                            {}
#line 1690 "y.tab.c"
    break;

  case 7: /* statement: function_call  */
#line 78 "Compiler.y"
                                                            {}
#line 1696 "y.tab.c"
    break;

  case 8: /* statement: print_statement  */
#line 79 "Compiler.y"
                                                            {}
#line 1702 "y.tab.c"
    break;

  case 9: /* statement: if_condition_statement  */
#line 80 "Compiler.y"
                                                            {}
#line 1708 "y.tab.c"
    break;

  case 10: /* statement: switch_statement  */
#line 81 "Compiler.y"
                                                            {}
#line 1714 "y.tab.c"
    break;

  case 11: /* statement: while_loop  */
#line 82 "Compiler.y"
                                                            {}
#line 1720 "y.tab.c"
    break;

  case 12: /* statement: do_while_loop  */
#line 83 "Compiler.y"
                                                            {}
#line 1726 "y.tab.c"
    break;

  case 13: /* statement: for_loop  */
#line 84 "Compiler.y"
                                                            {}
#line 1732 "y.tab.c"
    break;

  case 14: /* statement: function_declaration  */
#line 85 "Compiler.y"
                                                            {}
#line 1738 "y.tab.c"
    break;

  case 15: /* statement: expression  */
#line 86 "Compiler.y"
                                                            {}
#line 1744 "y.tab.c"
    break;

  case 16: /* print_statement: PRINT '(' expression ')' ';'  */
#line 90 "Compiler.y"
                                                          {}
#line 1750 "y.tab.c"
    break;

  case 17: /* if_condition_statement: IF '(' expression ')' LBRACE start_scope statement_list RBRACE end_scope  */
#line 93 "Compiler.y"
                                                                                                                                                                {printf("hi if 1\n");}
#line 1756 "y.tab.c"
    break;

  case 18: /* if_condition_statement: IF '(' expression ')' LBRACE start_scope statement_list RBRACE end_scope ELSE LBRACE start_scope statement_list RBRACE end_scope  */
#line 94 "Compiler.y"
                                                                                                                                                                {printf("hi if 2\n");}
#line 1762 "y.tab.c"
    break;

  case 19: /* switch_statement: SWITCH '(' expression ')' LBRACE case_list case_default RBRACE  */
#line 96 "Compiler.y"
                                                                                                                                          {}
#line 1768 "y.tab.c"
    break;

  case 20: /* case_list: case_list CASE expression ':' statement_list BREAK ';'  */
#line 99 "Compiler.y"
                                                                               {}
#line 1774 "y.tab.c"
    break;

  case 21: /* case_list: CASE expression ':' statement_list BREAK ';'  */
#line 100 "Compiler.y"
                                                                               {}
#line 1780 "y.tab.c"
    break;

  case 22: /* case_default: DEFAULT ':' statement_list BREAK ';'  */
#line 103 "Compiler.y"
                                                                                {}
#line 1786 "y.tab.c"
    break;

  case 23: /* while_loop: WHILE '(' expression ')' LBRACE start_scope statement_list RBRACE end_scope  */
#line 108 "Compiler.y"
                                                                                                                {}
#line 1792 "y.tab.c"
    break;

  case 24: /* do_while_loop: DO LBRACE start_scope statement_list RBRACE end_scope WHILE '(' expression ')' ';'  */
#line 110 "Compiler.y"
                                                                                                                {}
#line 1798 "y.tab.c"
    break;

  case 25: /* for_loop: FOR '(' declaration_assignment_loop ';' expression ';' declaration_assignment_loop ')' LBRACE start_scope statement_list RBRACE end_scope  */
#line 113 "Compiler.y"
                                                                                                                                                                    {}
#line 1804 "y.tab.c"
    break;

  case 26: /* function_declaration: type IDENTIFIER '(' arg_list ')' LBRACE start_scope statement_list RETURN statement_list ';' RBRACE end_scope  */
#line 117 "Compiler.y"
                                                                                                                                       {}
#line 1810 "y.tab.c"
    break;

  case 27: /* function_declaration: VOID_TYPE IDENTIFIER '(' arg_list ')' LBRACE start_scope statement_list RBRACE end_scope  */
#line 118 "Compiler.y"
                                                                                                                                       {}
#line 1816 "y.tab.c"
    break;

  case 28: /* function_declaration: type IDENTIFIER '(' arg_list ')' LBRACE start_scope RETURN statement_list RBRACE end_scope  */
#line 119 "Compiler.y"
                                                                                                                                       {}
#line 1822 "y.tab.c"
    break;

  case 29: /* function_call: IDENTIFIER '(' arg_list_call ')' ';'  */
#line 122 "Compiler.y"
                                                                {}
#line 1828 "y.tab.c"
    break;

  case 30: /* function_call_expression: IDENTIFIER '(' arg_list_call ')'  */
#line 125 "Compiler.y"
                                                                {}
#line 1834 "y.tab.c"
    break;

  case 31: /* arg_list: type IDENTIFIER ',' arg_list  */
#line 128 "Compiler.y"
                                                                {}
#line 1840 "y.tab.c"
    break;

  case 32: /* arg_list: type IDENTIFIER  */
#line 129 "Compiler.y"
                                                                {}
#line 1846 "y.tab.c"
    break;

  case 33: /* arg_list_call: arg_list_call ',' expression  */
#line 131 "Compiler.y"
                                                                {}
#line 1852 "y.tab.c"
    break;

  case 34: /* arg_list_call: expression  */
#line 132 "Compiler.y"
                                                                {}
#line 1858 "y.tab.c"
    break;

  case 36: /* declaration_assignment: declaration ';'  */
#line 139 "Compiler.y"
                                            {}
#line 1864 "y.tab.c"
    break;

  case 37: /* declaration_assignment: assignment ';'  */
#line 140 "Compiler.y"
                                            {}
#line 1870 "y.tab.c"
    break;

  case 38: /* declaration_assignment_loop: declaration  */
#line 143 "Compiler.y"
                                                    {}
#line 1876 "y.tab.c"
    break;

  case 39: /* declaration_assignment_loop: assignment  */
#line 144 "Compiler.y"
                                                    {}
#line 1882 "y.tab.c"
    break;

  case 40: /* declaration: type IDENTIFIER  */
#line 147 "Compiler.y"
                                                                    {  }
#line 1888 "y.tab.c"
    break;

  case 41: /* declaration: type IDENTIFIER '=' expression  */
#line 148 "Compiler.y"
                                                                    { }
#line 1894 "y.tab.c"
    break;

  case 42: /* declaration: CONST type IDENTIFIER '=' expression  */
#line 149 "Compiler.y"
                                                                    {  }
#line 1900 "y.tab.c"
    break;

  case 43: /* declaration: ENUM IDENTIFIER IDENTIFIER '=' IDENTIFIER  */
#line 150 "Compiler.y"
                                                                    { }
#line 1906 "y.tab.c"
    break;

  case 44: /* declaration: VAR IDENTIFIER  */
#line 151 "Compiler.y"
                                                                    { }
#line 1912 "y.tab.c"
    break;

  case 45: /* assignment: IDENTIFIER '=' expression  */
#line 154 "Compiler.y"
                                                                 {printf("hi assign\n");}
#line 1918 "y.tab.c"
    break;

  case 46: /* enum_declaration: ENUM IDENTIFIER LBRACE enum_list RBRACE ';'  */
#line 158 "Compiler.y"
                                                                        {}
#line 1924 "y.tab.c"
    break;

  case 47: /* enum_list: enum_list ',' IDENTIFIER  */
#line 162 "Compiler.y"
                                                                        { }
#line 1930 "y.tab.c"
    break;

  case 48: /* enum_list: enum_list ',' IDENTIFIER '=' expression  */
#line 163 "Compiler.y"
                                                                        { }
#line 1936 "y.tab.c"
    break;

  case 49: /* enum_list: IDENTIFIER  */
#line 164 "Compiler.y"
                                                                        { }
#line 1942 "y.tab.c"
    break;

  case 50: /* enum_list: IDENTIFIER '=' expression  */
#line 165 "Compiler.y"
                                                                        { }
#line 1948 "y.tab.c"
    break;

  case 51: /* expression: binary_expression  */
#line 170 "Compiler.y"
                                             { }
#line 1954 "y.tab.c"
    break;

  case 52: /* expression: unary_expression  */
#line 171 "Compiler.y"
                                             { }
#line 1960 "y.tab.c"
    break;

  case 53: /* binary_expression: expression '+' expression  */
#line 173 "Compiler.y"
                                                     { }
#line 1966 "y.tab.c"
    break;

  case 54: /* binary_expression: expression '-' expression  */
#line 174 "Compiler.y"
                                                     { }
#line 1972 "y.tab.c"
    break;

  case 55: /* binary_expression: expression '*' expression  */
#line 175 "Compiler.y"
                                                     { }
#line 1978 "y.tab.c"
    break;

  case 56: /* binary_expression: expression '/' expression  */
#line 176 "Compiler.y"
                                                     { }
#line 1984 "y.tab.c"
    break;

  case 57: /* binary_expression: expression '%' expression  */
#line 177 "Compiler.y"
                                                     { }
#line 1990 "y.tab.c"
    break;

  case 58: /* binary_expression: expression EQ expression  */
#line 178 "Compiler.y"
                                                     {printf("hi eq\n");}
#line 1996 "y.tab.c"
    break;

  case 59: /* binary_expression: expression NEQ expression  */
#line 179 "Compiler.y"
                                                     { }
#line 2002 "y.tab.c"
    break;

  case 60: /* binary_expression: expression LT expression  */
#line 180 "Compiler.y"
                                                     {}
#line 2008 "y.tab.c"
    break;

  case 61: /* binary_expression: expression GT expression  */
#line 181 "Compiler.y"
                                                     {}
#line 2014 "y.tab.c"
    break;

  case 62: /* binary_expression: expression LTE expression  */
#line 182 "Compiler.y"
                                                     { }
#line 2020 "y.tab.c"
    break;

  case 63: /* binary_expression: expression GTE expression  */
#line 183 "Compiler.y"
                                                     { }
#line 2026 "y.tab.c"
    break;

  case 64: /* binary_expression: expression AND expression  */
#line 184 "Compiler.y"
                                                     { }
#line 2032 "y.tab.c"
    break;

  case 65: /* binary_expression: expression OR expression  */
#line 185 "Compiler.y"
                                                     {}
#line 2038 "y.tab.c"
    break;

  case 66: /* binary_expression: '(' expression ')'  */
#line 186 "Compiler.y"
                                                     {  }
#line 2044 "y.tab.c"
    break;

  case 67: /* binary_expression: value  */
#line 187 "Compiler.y"
                                                     {  }
#line 2050 "y.tab.c"
    break;

  case 68: /* binary_expression: IDENTIFIER  */
#line 188 "Compiler.y"
                                                     {}
#line 2056 "y.tab.c"
    break;

  case 69: /* binary_expression: function_call_expression  */
#line 189 "Compiler.y"
                                                     { }
#line 2062 "y.tab.c"
    break;

  case 70: /* unary_expression: '-' expression  */
#line 191 "Compiler.y"
                                                      { }
#line 2068 "y.tab.c"
    break;

  case 71: /* unary_expression: '!' expression  */
#line 192 "Compiler.y"
                                                      { }
#line 2074 "y.tab.c"
    break;

  case 72: /* type: INT_TYPE  */
#line 196 "Compiler.y"
                                        {  }
#line 2080 "y.tab.c"
    break;

  case 73: /* type: FLOAT_TYPE  */
#line 197 "Compiler.y"
                                        {  }
#line 2086 "y.tab.c"
    break;

  case 74: /* type: BOOL_TYPE  */
#line 198 "Compiler.y"
                                        {  }
#line 2092 "y.tab.c"
    break;

  case 75: /* type: CHAR_TYPE  */
#line 199 "Compiler.y"
                                        {  }
#line 2098 "y.tab.c"
    break;

  case 76: /* type: STRING_TYPE  */
#line 200 "Compiler.y"
                                        {  }
#line 2104 "y.tab.c"
    break;

  case 84: /* start_scope: %empty  */
#line 212 "Compiler.y"
                            {printf("start of scope\n");}
#line 2110 "y.tab.c"
    break;

  case 85: /* end_scope: %empty  */
#line 215 "Compiler.y"
                            {printf("end of scope\n");}
#line 2116 "y.tab.c"
    break;


#line 2120 "y.tab.c"

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

#line 217 "Compiler.y"



extern FILE *yyin;
FILE *errorsFile;

void yyerror(const char *s) {
    fprintf(errorsFile, "Syntax error at line %d: %s\n", currentLineNumber, s);
}

nodeType *createTypeNode(conEnum type) {
    nodeType *p;

    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("Memory allocation failed");

    /* Set the node type */
    p->type = typeDef; // Change to typeDef for a type node

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

    p->type = typeCon;
    p->con.type = typeInt; // Set the constant type
    p->con.iValue = value;

    return p;
}

nodeType *createFloatConstantNode(float value) {
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.type = typeFloat; // Set the constant type
    p->con.fValue = value;

    return p;
}

nodeType *createBoolConstantNode(bool value) {
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.type = typeBool; // Set the constant type
    p->con.iValue = value;

    return p;
}

nodeType *createCharConstantNode(char value) {
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.type = typeChar; // Set the constant type
    p->con.cValue = value;

    return p;
}

nodeType *createStringConstantNode(char* value) {
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.type = typeString; // Set the constant type
    p->con.sValue = strdup(value); // Duplicate the string

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

conEnum getTypeOfEnum(const nodeType *node) {
    // Assuming that the identifier is stored in the node and it's a string
    const char *identifier = NULL;

    // Determine the identifier based on the node's content
    switch (node->type) {
        case typeId:
            identifier = node->id.id; // Assuming id is the member containing the identifier
            break;
        default:
            // Handle other node types if necessary
            break;
    }

    // Return the type based on the identifier
    if (identifier != NULL) {
        if (strcmp(identifier, "int") == 0) {
            return typeInt;
        } else if (strcmp(identifier, "float") == 0) {
            return typeFloat;
        } else if (strcmp(identifier, "string") == 0) {
            return typeString;
        } else if (strcmp(identifier, "char") == 0) {
            return typeChar;
        } else if (strcmp(identifier, "bool") == 0) {
            return typeBool;
        }
    }

    // Handle unknown types
    return typeND;
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
