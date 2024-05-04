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
#line 1 "Compiler.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include "node.h"

void yyerror(const char *s);
int yylex();
extern FILE *yyin;
extern FILE *errorsFile;
extern int currentLineNumber;

#line 86 "y.tab.c"

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

#line 232 "y.tab.c"

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
  YYSYMBOL_VAR = 28,                       /* VAR  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_DO = 32,                        /* DO  */
  YYSYMBOL_FOR = 33,                       /* FOR  */
  YYSYMBOL_SWITCH = 34,                    /* SWITCH  */
  YYSYMBOL_CASE = 35,                      /* CASE  */
  YYSYMBOL_DEFAULT = 36,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 37,                     /* BREAK  */
  YYSYMBOL_RETURN = 38,                    /* RETURN  */
  YYSYMBOL_PRINT = 39,                     /* PRINT  */
  YYSYMBOL_ENUM = 40,                      /* ENUM  */
  YYSYMBOL_IFX = 41,                       /* IFX  */
  YYSYMBOL_42_ = 42,                       /* '+'  */
  YYSYMBOL_43_ = 43,                       /* '-'  */
  YYSYMBOL_44_ = 44,                       /* '*'  */
  YYSYMBOL_45_ = 45,                       /* '/'  */
  YYSYMBOL_46_ = 46,                       /* '%'  */
  YYSYMBOL_UMINUS = 47,                    /* UMINUS  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_50_ = 50,                       /* ';'  */
  YYSYMBOL_51_ = 51,                       /* ':'  */
  YYSYMBOL_52_ = 52,                       /* ','  */
  YYSYMBOL_53_ = 53,                       /* '='  */
  YYSYMBOL_54_ = 54,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_program = 56,                   /* program  */
  YYSYMBOL_function_or_statement = 57,     /* function_or_statement  */
  YYSYMBOL_statement_list = 58,            /* statement_list  */
  YYSYMBOL_statement = 59,                 /* statement  */
  YYSYMBOL_print_statement = 60,           /* print_statement  */
  YYSYMBOL_if_condition_statement = 61,    /* if_condition_statement  */
  YYSYMBOL_switch_statement = 62,          /* switch_statement  */
  YYSYMBOL_case_list = 63,                 /* case_list  */
  YYSYMBOL_case_default = 64,              /* case_default  */
  YYSYMBOL_while_loop = 65,                /* while_loop  */
  YYSYMBOL_do_while_loop = 66,             /* do_while_loop  */
  YYSYMBOL_for_loop = 67,                  /* for_loop  */
  YYSYMBOL_function_declaration = 68,      /* function_declaration  */
  YYSYMBOL_function_call = 69,             /* function_call  */
  YYSYMBOL_function_call_expression = 70,  /* function_call_expression  */
  YYSYMBOL_arg_list = 71,                  /* arg_list  */
  YYSYMBOL_arg_list_call = 72,             /* arg_list_call  */
  YYSYMBOL_declaration_assignment = 73,    /* declaration_assignment  */
  YYSYMBOL_declaration_assignment_loop = 74, /* declaration_assignment_loop  */
  YYSYMBOL_declaration = 75,               /* declaration  */
  YYSYMBOL_assignment = 76,                /* assignment  */
  YYSYMBOL_enum_declaration = 77,          /* enum_declaration  */
  YYSYMBOL_enum_list = 78,                 /* enum_list  */
  YYSYMBOL_expression = 79,                /* expression  */
  YYSYMBOL_type = 80,                      /* type  */
  YYSYMBOL_value = 81                      /* value  */
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
#define YYLAST   682

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  205

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
       2,     2,     2,    54,     2,     2,     2,    46,     2,     2,
      48,    49,    44,    42,    52,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    50,
       2,    53,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    58,    59,    62,    63,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    79,    83,    84,    87,
      90,    91,    92,    95,    99,   102,   105,   109,   110,   113,
     116,   119,   120,   121,   124,   125,   126,   131,   132,   135,
     136,   139,   140,   141,   142,   145,   149,   152,   153,   154,
     155,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     180,   181,   182,   183,   184,   187,   188,   189,   190,   191,
     192,   193
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
  "AND", "OR", "CONST", "VAR", "IF", "ELSE", "WHILE", "DO", "FOR",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "RETURN", "PRINT", "ENUM", "IFX",
  "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "'('", "')'", "';'", "':'",
  "','", "'='", "'!'", "$accept", "program", "function_or_statement",
  "statement_list", "statement", "print_statement",
  "if_condition_statement", "switch_statement", "case_list",
  "case_default", "while_loop", "do_while_loop", "for_loop",
  "function_declaration", "function_call", "function_call_expression",
  "arg_list", "arg_list_call", "declaration_assignment",
  "declaration_assignment_loop", "declaration", "assignment",
  "enum_declaration", "enum_list", "expression", "type", "value", YY_NULLPTR
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
     295,   296,    43,    45,    42,    47,    37,   297,    40,    41,
      59,    58,    44,    61,    33
};
#endif

#define YYPACT_NINF (-146)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-44)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,  -146,  -146,  -146,  -146,  -146,    11,     5,  -146,   439,
    -146,    19,     4,  -146,     3,    75,    45,     7,    27,    61,
      31,    33,    34,    84,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,    62,    65,  -146,   108,    35,    75,    37,
      37,   109,  -146,    37,    37,  -146,    10,    37,    37,    67,
    -146,  -146,    68,    75,    72,   123,  -146,  -146,  -146,  -146,
    -146,    85,  -146,  -146,    37,    37,    37,  -146,   -32,   628,
    -146,   628,    79,   511,   519,   136,    81,   128,    90,  -146,
    -146,   550,   558,   134,  -146,    97,   135,   103,    37,  -146,
     589,   628,   106,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,   140,   141,
     122,   142,    37,   143,   111,   113,    -4,   145,  -146,    75,
      25,  -146,  -146,   628,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,   636,   636,    76,    76,   104,   438,  -146,  -146,
     124,   134,   470,   138,  -146,    37,   121,   174,  -146,   166,
    -146,  -146,  -146,   196,   226,    37,    -3,    10,   101,   -26,
     628,   133,   132,   256,  -146,   156,  -146,   597,   137,   139,
     150,   101,   151,   171,    37,    37,   173,   146,  -146,   175,
    -146,   152,  -146,  -146,   628,   479,  -146,  -146,  -146,   289,
    -146,   319,   194,   349,   379,   163,   409,   165,  -146,  -146,
    -146,  -146,   167,  -146,  -146
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,    70,    71,    72,    73,    74,     0,     0,     2,     4,
       3,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,    10,    11,    12,    13,    14,
      15,     9,     7,     0,     0,     8,     0,     0,    33,    36,
       0,     0,    44,     0,     0,     6,     0,     0,     0,     0,
      37,    38,     0,    33,     0,     0,    75,    76,    77,    78,
      79,    68,    81,    80,     0,     0,     0,    69,     0,    35,
      67,    45,     0,     0,     0,     0,     0,     0,     0,    39,
      40,     0,     0,     0,    41,     0,     0,    32,    36,    65,
       0,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,     6,    33,
       0,    64,    29,    34,    56,    57,    58,    59,    60,    61,
      62,    63,    51,    52,    53,    54,    55,     0,     6,     6,
       0,     0,     0,    22,    16,     0,     0,     0,     6,     0,
      31,    30,    42,     0,     0,     0,     0,     0,     0,     0,
      50,    46,    47,     0,    28,    17,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,     0,
       6,     0,     6,    19,    49,     0,     6,    25,     6,     0,
       6,     0,     0,     0,     0,     0,     0,     0,    27,    18,
      26,    21,     0,    23,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,   -45,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,   -47,   130,  -146,    59,
     -44,   -43,  -146,    50,   -36,     1,  -145
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    24,    25,    26,    27,   159,   173,
      28,    29,    30,    10,    31,    67,    54,    68,    32,    78,
      33,    34,    35,   116,    69,    36,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    11,    79,    80,    71,    13,    85,    73,    74,   171,
     172,    81,    82,   170,   146,   168,    41,    92,    76,    12,
      93,     1,     2,     3,     4,     5,   181,    37,    89,    90,
      91,     1,     2,     3,     4,     5,     6,    15,    16,    55,
      56,    57,    58,    59,    60,    61,    62,    63,   147,   147,
      77,    39,    38,    42,    55,    43,    40,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   150,   149,   151,    44,   142,    93,    45,    46,
      64,    47,    48,    53,    83,    65,     1,     2,     3,     4,
       5,    66,    49,   153,   154,    94,    95,    96,    97,    98,
      99,   100,   101,   163,    56,    57,    58,    59,    60,   160,
      62,    63,    50,    79,    80,    51,    52,    72,    84,   167,
      55,    86,   106,    94,    95,    96,    97,    98,    99,   100,
     101,    87,   107,    88,    40,   189,   111,   191,   184,   185,
     112,   193,   115,   194,    14,   196,   117,     1,     2,     3,
       4,     5,   118,   140,   110,   119,   122,   138,   139,   141,
     143,   144,   148,    15,    16,    17,   145,    18,    19,    20,
      21,   161,   155,   158,    14,    22,    23,     1,     2,     3,
       4,     5,   162,   -43,   164,   174,   176,   178,   179,   183,
     186,   156,   188,    15,    16,    17,   187,    18,    19,    20,
      21,   180,   182,   190,    14,    22,    23,     1,     2,     3,
       4,     5,   198,   201,   165,   203,   169,   204,   120,     0,
       0,     0,     0,    15,    16,    17,     0,    18,    19,    20,
      21,     0,     0,     0,    14,    22,    23,     1,     2,     3,
       4,     5,     0,     0,   166,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,    17,     0,    18,    19,    20,
      21,     0,     0,     0,    14,    22,    23,     1,     2,     3,
       4,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,    17,     0,    18,    19,    20,
      21,     0,     0,     0,   175,    22,    23,    14,     0,     0,
       1,     2,     3,     4,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,    17,     0,
      18,    19,    20,    21,     0,     0,   195,    14,    22,    23,
       1,     2,     3,     4,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,    17,     0,
      18,    19,    20,    21,     0,     0,   197,    14,    22,    23,
       1,     2,     3,     4,     5,     0,     0,   199,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,    17,     0,
      18,    19,    20,    21,     0,     0,     0,    14,    22,    23,
       1,     2,     3,     4,     5,     0,     0,   200,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,    17,     0,
      18,    19,    20,    21,     0,     0,     0,    14,    22,    23,
       1,     2,     3,     4,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,    17,     0,
      18,    19,    20,    21,     0,     0,   202,    14,    22,    23,
       1,     2,     3,     4,     5,     0,     0,    94,    95,    96,
      97,    98,    99,   100,   101,     0,    15,    16,    17,     0,
      18,    19,    20,    21,     0,     0,     0,     0,    22,    23,
     102,   103,   104,   105,   106,     0,     0,     0,   152,    94,
      95,    96,    97,    98,    99,   100,   101,     0,    94,    95,
      96,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,     0,     0,     0,
     157,   102,   103,   104,   105,   106,     0,     0,     0,   192,
      94,    95,    96,    97,    98,    99,   100,   101,    94,    95,
      96,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,     0,     0,
     108,   102,   103,   104,   105,   106,     0,     0,   109,    94,
      95,    96,    97,    98,    99,   100,   101,    94,    95,    96,
      97,    98,    99,   100,   101,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,     0,     0,   113,
     102,   103,   104,   105,   106,     0,     0,   114,    94,    95,
      96,    97,    98,    99,   100,   101,    94,    95,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,     0,     0,   121,   102,
     103,   104,   105,   106,     0,     0,   177,    94,    95,    96,
      97,    98,    99,   100,   101,    94,    95,    96,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,     0,     0,     0,     0,     0,
     104,   105,   106
};

static const yytype_int16 yycheck[] =
{
      45,     0,    46,    46,    40,     0,    53,    43,    44,    35,
      36,    47,    48,   158,    18,    18,    15,    49,     8,     8,
      52,    11,    12,    13,    14,    15,   171,     8,    64,    65,
      66,    11,    12,    13,    14,    15,    16,    27,    28,    38,
       3,     4,     5,     6,     7,     8,     9,    10,    52,    52,
      40,    48,    48,     8,    53,    48,    53,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   119,   118,    49,    48,   112,    52,    17,    48,
      43,    48,    48,    48,    17,    48,    11,    12,    13,    14,
      15,    54,     8,   138,   139,    19,    20,    21,    22,    23,
      24,    25,    26,   148,     3,     4,     5,     6,     7,   145,
       9,    10,    50,   157,   157,    50,     8,     8,    50,   155,
     119,    49,    46,    19,    20,    21,    22,    23,    24,    25,
      26,     8,    53,    48,    53,   180,     8,   182,   174,   175,
      50,   186,     8,   188,     8,   190,    49,    11,    12,    13,
      14,    15,    17,    31,    18,    52,    50,    17,    17,    17,
      17,    50,    17,    27,    28,    29,    53,    31,    32,    33,
      34,    50,    48,    35,     8,    39,    40,    11,    12,    13,
      14,    15,     8,    50,    18,    53,    30,    50,    49,    18,
      17,   141,    17,    27,    28,    29,    50,    31,    32,    33,
      34,    51,    51,    51,     8,    39,    40,    11,    12,    13,
      14,    15,    18,    50,    18,    50,   157,    50,    88,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    -1,    -1,    -1,     8,    39,    40,    11,    12,    13,
      14,    15,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    -1,    -1,    -1,     8,    39,    40,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    -1,    -1,    -1,    38,    39,    40,     8,    -1,    -1,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    -1,    -1,    37,     8,    39,    40,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    -1,    -1,    37,     8,    39,    40,
      11,    12,    13,    14,    15,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    -1,    -1,    -1,     8,    39,    40,
      11,    12,    13,    14,    15,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    -1,    -1,    -1,     8,    39,    40,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    -1,    -1,    37,     8,    39,    40,
      11,    12,    13,    14,    15,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    50,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    42,    43,    44,    45,    46,    -1,    -1,    -1,    50,
      19,    20,    21,    22,    23,    24,    25,    26,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    -1,    -1,
      49,    42,    43,    44,    45,    46,    -1,    -1,    49,    19,
      20,    21,    22,    23,    24,    25,    26,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    -1,    -1,    49,
      42,    43,    44,    45,    46,    -1,    -1,    49,    19,    20,
      21,    22,    23,    24,    25,    26,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    -1,    -1,    49,    42,
      43,    44,    45,    46,    -1,    -1,    49,    19,    20,    21,
      22,    23,    24,    25,    26,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    12,    13,    14,    15,    16,    56,    57,    58,
      68,    80,     8,     0,     8,    27,    28,    29,    31,    32,
      33,    34,    39,    40,    59,    60,    61,    62,    65,    66,
      67,    69,    73,    75,    76,    77,    80,     8,    48,    48,
      53,    80,     8,    48,    48,    17,    48,    48,    48,     8,
      50,    50,     8,    48,    71,    80,     3,     4,     5,     6,
       7,     8,     9,    10,    43,    48,    54,    70,    72,    79,
      81,    79,     8,    79,    79,    58,     8,    40,    74,    75,
      76,    79,    79,    17,    50,    71,    49,     8,    48,    79,
      79,    79,    49,    52,    19,    20,    21,    22,    23,    24,
      25,    26,    42,    43,    44,    45,    46,    53,    49,    49,
      18,     8,    50,    49,    49,     8,    78,    49,    17,    52,
      72,    49,    50,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    17,    17,
      31,    17,    79,    17,    50,    53,    18,    52,    17,    58,
      71,    49,    50,    58,    58,    48,    78,    50,    35,    63,
      79,    50,     8,    58,    18,    18,    18,    79,    18,    74,
      81,    35,    36,    64,    53,    38,    30,    49,    50,    49,
      51,    81,    51,    18,    79,    79,    17,    50,    17,    58,
      51,    58,    50,    58,    58,    37,    58,    37,    18,    18,
      18,    50,    37,    50,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    61,    61,    62,
      63,    63,    63,    64,    65,    66,    67,    68,    68,    69,
      70,    71,    71,    71,    72,    72,    72,    73,    73,    74,
      74,    75,    75,    75,    75,    76,    77,    78,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      80,    80,    80,    80,    80,    81,    81,    81,    81,    81,
      81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     7,    11,     8,
       7,     6,     0,     5,     7,     9,    11,    11,     8,     5,
       4,     4,     2,     0,     3,     1,     0,     2,     2,     1,
       1,     3,     6,     6,     2,     3,     6,     3,     1,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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

#line 1527 "y.tab.c"

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

#line 196 "Compiler.y"

extern FILE *yyin;
FILE *errorsFile;

/* Part 3: User Subroutines */
void yyerror(const char *s) {
    fprintf(errorsFile, "Syntax error at line %d: %s\n", currentLineNumber, s);
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
