/* part 1 defintions */
/* yylex() is called inside the yyparse(), this is why we add it in this section */
%{
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
%}

%union {
    int iVal;
    float fVal;
    bool bVal;
    char cVal;
    char *sVal;
    nodeType *nPtr;
};

%token <iVal> INTEGER
%token <fVal> FLOAT
%token <bVal> BOOL
%token <cVal> CHAR
%token <sVal> STRING
%token <sVal> IDENTIFIER
%token <bVal> BOOL_FALSE BOOL_TRUE
%token INT_TYPE FLOAT_TYPE BOOL_TYPE CHAR_TYPE STRING_TYPE VOID_TYPE
%token LBRACE RBRACE
%token EQ NEQ LT GT LTE GTE AND OR
%token CONST FUNC MAIN INCLUDE DEFINE VAR
%token IF ELSE WHILE DO FOR SWITCH CASE DEFAULT BREAK RETURN EXIT CONTINUE PRINT ENUM

%nonassoc IFX
%nonassoc ELSE

/* Precedence and associativity rules for operators */
%left '+' '-'
%left '*' '/'
%left '%'
%left EQ NEQ LT GT LTE GTE AND OR
%nonassoc UMINUS

%type <nPtr> program statement_list statement print_statement
            if_condition_statement switch_statement case_list case_default while_loop do_while_loop
            for_loop function_declaration function_call arg_list arg_list_call declaration_assignment declaration
            assignment enum_declaration enum_list expression type value

%%

program                 : function_or_statement
                        ;

function_or_statement   : function_declaration
                        | statement_list
                        ;

statement_list          : statement_list statement
                        | 
                        ;

// Statements rules
statement               : declaration_assignment
                        | enum_declaration
                        | function_call
                        | print_statement
                        | if_condition_statement
                        | switch_statement
                        | while_loop
                        | do_while_loop
                        | for_loop
                        ;

// Print statement rules
print_statement         : PRINT '(' expression ')' ';'
                        ;

// Statements rules: Conditional statements
if_condition_statement  : IF '(' expression ')' LBRACE statement_list RBRACE %prec IFX
                        | IF '(' expression ')' LBRACE statement_list RBRACE %prec IFX ELSE LBRACE statement_list RBRACE
                        ;

switch_statement        : SWITCH '(' expression ')' LBRACE case_list case_default RBRACE
                        ;

case_list               : case_list CASE value ':' statement_list BREAK ';'
                        | CASE value ':' statement_list BREAK ';'
                        | 
                        ;

case_default            : DEFAULT ':' statement_list BREAK ';'
                        ;

// Statements rules: Loop statements
while_loop              : WHILE '(' expression ')' LBRACE statement_list RBRACE
                        ;

do_while_loop           : DO LBRACE statement_list RBRACE WHILE '(' expression ')' ';'
                        ;

for_loop                : FOR '(' declaration_assignment_loop ';' expression';' declaration_assignment_loop ')' LBRACE statement_list RBRACE
                        ;

// Functions rules
function_declaration   : type IDENTIFIER '(' arg_list ')' LBRACE statement_list RETURN expression';' RBRACE
                        | VOID_TYPE IDENTIFIER '(' arg_list ')' LBRACE statement_list RBRACE
                        ;

function_call           : IDENTIFIER '(' arg_list_call ')' ';'
                        ;

function_call_expression: IDENTIFIER '(' arg_list_call ')'
                        ;

arg_list                : type IDENTIFIER ',' arg_list
                        | type IDENTIFIER
                        |
                        ;

arg_list_call           : arg_list_call ',' expression
                        | expression
                        |
                        ;

// Assignments and declarations rules

declaration_assignment  : declaration ';'
                        | assignment ';'
                        ;

declaration_assignment_loop     : declaration
                                | assignment
                                ;

declaration             : type IDENTIFIER ';' 
                        | CONST type IDENTIFIER '=' expression ';'
                        | ENUM IDENTIFIER LBRACE enum_list RBRACE ';'
                        | VAR IDENTIFIER
                        ;

assignment              : IDENTIFIER '=' expression
                        ;

// Enum rules
enum_declaration        : ENUM IDENTIFIER LBRACE enum_list RBRACE ';'
                        ;

enum_list               : enum_list ',' IDENTIFIER
                        | IDENTIFIER
                        | enum_list ',' IDENTIFIER '=' expression
                        | IDENTIFIER '=' expression
                        ;

// Expressions rules
expression              : expression '+' expression
                        | expression '-' expression
                        | expression '*' expression
                        | expression '/' expression
                        | expression '%' expression
                        | expression EQ expression
                        | expression NEQ expression
                        | expression LT expression
                        | expression GT expression
                        | expression LTE expression
                        | expression GTE expression
                        | expression AND expression
                        | expression OR expression
                        | '(' expression ')'
                        | '-' expression %prec UMINUS
                        | '!' expression
                        | value
                        | IDENTIFIER
                        | function_call_expression
                        ;

type                    : INT_TYPE
                        | FLOAT_TYPE
                        | BOOL_TYPE
                        | CHAR_TYPE
                        | STRING_TYPE
                        ;

value                   : INTEGER
                        | FLOAT
                        | BOOL
                        | CHAR
                        | STRING
                        | BOOL_TRUE
                        | BOOL_FALSE
                        ;

%%
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
