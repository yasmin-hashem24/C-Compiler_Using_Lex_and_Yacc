/* part 1 defintions */
/* yylex() is called inside the yyparse(), this is why we add it in this section */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h> 
    #include <string.h>
    #include <stdarg.h>
    #include "node.h"

    void yyerror(char *s);
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

/* To remove the shift/reduce conflict(in If-Else Ambiguity), we need to add the following precedence and associativity rules */
%nonassoc IFX 
%nonassoc ELSE 
/* The following rules are for the precedence of the operators */
%left EQ NEQ LT GT LTE GTE AND OR
%left '+' '-' 
%left '*' '/' 
%left '%'
%nonassoc UMINUS 

%type <nPtr>    program statement_list statement conditional_statement loop_statement print_statement 
                if_condition_statement switch_statement case_list case_default while_loop do_while_loop 
                for_loop function function_call arg_list arg_list_call declaration_assignment declaration 
                assignment enum_declaration enum_list expression type value

/* end of part 1 definitions */
/* part 2 production rules */
%%

program                 : function
                        | statement_list
                        ;

statement_list          : statement_list statement
                        | statement
                        |
                        ;   

// Statements rules
statement               : declaration_assignment
                        | enum_declaration
                        | function_call
                        | conditional_statement
                        | loop_statement
                        | print_statement
                        | function
                        ;

conditional_statement   : if_condition_statement
                        | switch_statement
                        ;

loop_statement          : while_loop
                        | do_while_loop
                        | for_loop
                        ;

// Print statement rules
print_statement         : PRINT '(' expression ')' ';'

// Statements rules: Conditional statements
if_condition_statement  : IF '(' expression ')' LBRACE statement_list RBRACE
                        | IF '(' expression ')' LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE
                        ;
switch_statement        : SWITCH '(' expression ')' LBRACE case_list case_default RBRACE
                        ;

case_list               : case_list CASE value ':' statement_list BREAK ';'
                        | CASE value ':' statement_list BREAK ';'
                        ;

case_default            : DEFAULT ':' statement_list BREAK ';'
                        ;


// Statements rules: Loop statements
while_loop              : WHILE '(' expression ')' LBRACE statement_list RBRACE
                        ;

do_while_loop           : DO LBRACE statement_list RBRACE WHILE '(' expression ')' ';'
                        ;

for_loop                : FOR '(' declaration_assignment expression ';' expression ')' LBRACE statement_list RBRACE
                        ;

// Functions rules
function                : type IDENTIFIER '('arg_list')' LBRACE statement_list RETURN expression';' RBRACE 
                        | VOID_TYPE IDENTIFIER '(' arg_list ')' LBRACE statement_list RBRACE

function_call           : IDENTIFIER '(' arg_list_call ')' ';'

arg_list                : type IDENTIFIER','arg_list
                        | type IDENTIFIER
                        |
                        ;

arg_list_call           : arg_list_call ',' expression
                        | expression
                        |
                        ;
                

// Assignments and declarations rules

declaration_assignment  : declaration';'
                        | assignment';'
                        ;

declaration             : type IDENTIFIER
                        | type IDENTIFIER '=' expression
                        | CONST type IDENTIFIER '=' expression
                        | ENUM IDENTIFIER IDENTIFIER '=' IDENTIFIER
                        | VAR IDENTIFIER
                        ;

assignment              : IDENTIFIER '=' expression
                        ;

// Enum rules
// enum Foo { a, b, c = 10, d, e = 1, f, g = f + c };
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
                        ;

type                    : INT_TYPE
                        | FLOAT_TYPE 
                        | BOOL_TYPE 
                        | CHAR_TYPE 
                        | STRING_TYPE

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

/* part 3 user subroutines */
void yyerror(char *s) {
     fprintf(errorsFile, "Syntax error at line %d: %s\n", currentLineNumber, s);
}

int main() {
      FILE *fp = fopen("testinput.txt", "r");

    if (!fp) {
        perror("Error opening input file");
        return 1;
    }

    errorsFile = fopen("output.txt", "w");
    if (!errorsFile) {
        perror("Error opening output file");
        fclose(fp);
        return 1;
    }

    yyin = fp;

    yyparse();

    fclose(fp);
    fclose(errorsFile);

    return 0;
}