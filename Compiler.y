/* part 1 defintions */
%{
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
%left EQ NEQ
%left LT GT LTE GTE 
%left AND
%left OR

%nonassoc UMINUS  
%nonassoc NOT     

%type <nPtr> program statement_list statement print_statement
            if_statement switch_statement case_list case_default while_loop do_while_loop
            for_loop function_declaration function_call arg_list arg_list_call declaration_assignment declaration function_or_statement
            assignment enum_declaration enum_list expression type value binary_expression unary_expression function_call_expression declaration_assignment_loop

%%

program                 : function_or_statement              {printf("start of program");}    
                        ;

function_or_statement   : function_declaration               {$$=$1;}
                        | statement_list                     {$$=$1;}
                        ;

statement_list          : statement_list statement           {$$=$1;}
                        |                                    {$$=NULL;}
                        ;

// Statements rules
statement               : declaration_assignment             { $$ = $1; }
                        | enum_declaration                  { $$ = $1; }
                        | function_call                     { $$ = $1; }
                        | print_statement                   { $$ = $1; }
                        | if_statement                      { $$ = $1; }
                        | switch_statement                  { $$ = $1; }
                        | while_loop                        { $$ = $1; }
                        | do_while_loop                    { $$ = $1; }
                        | for_loop                         { $$ = $1; }
                        ;


// Print statement rules
print_statement         : PRINT '(' expression ')' ';'            {$$= CreateOperatorNode(PRINT, 1, $3);}
                        ;

// Statements rules: Conditional statements
if_statement          : IF '(' expression ')' LBRACE statement_list RBRACE %prec IFX {$$ = createOperatorNode(IF,2,$3,$6);}
                      | IF '(' expression ')' LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE %prec IFX {$$ = createOperatorNode(IF, 2, $3, $6, $10);}
                      ;



switch_statement        : SWITCH '(' expression ')' LBRACE case_list case_default RBRACE  {$$ = createOperatorNode(SWITCH, 2, $3, $6);}
                        ;

case_list            : case_list CASE expression ':' statement_list BREAK ';'  {$$ = createOperatorNode(CASE,3,$1,$3,$5);}
                     | CASE expression ':' statement_list BREAK ';'            {$$ = createOperatorNode(CASE, 2, $2, $4);}
                     ;

               


case_default            : DEFAULT ':' statement_list BREAK ';'                {$$ = createOperatorNode(DEFAULT, 1, $3);}
                        ;

// Statements rules: Loop statements
while_loop              : WHILE '(' expression ')' LBRACE statement_list RBRACE {$$ = createOperatorNode(WHILE, 2, $3, $6);}
                        ;

do_while_loop           : DO LBRACE statement_list RBRACE WHILE '(' expression ')' ';' { $$ = createOperatorNode(DO_WHILE, 2, $3, $7);}

                        ;

for_loop             : FOR '(' declaration_assignment_loop ';' expression ';' declaration_assignment_loop ')' LBRACE statement_list RBRACE {$$ = createOperatorNode(FOR, 3, $3, $5, $7);}
                     ;

// Functions rules
function_declaration: type IDENTIFIER '(' arg_list ')' LBRACE statement_list RETURN expression ';' RBRACE  { $$=createOperatorNode(FUNC, 3, createTypeNode($1->typ.type), createIdentifierNode($2), $4, $7, $9);}
                     | VOID_TYPE IDENTIFIER '(' arg_list ')' LBRACE statement_list RBRACE   { $$=createOperatorNode(FUNC, 4, createTypeNode(typeVoid), createIdentifierNode($2), $4, $7);}
                     ;

function_call           : IDENTIFIER '(' arg_list_call ')' ';'  { $$=createOperatorNode(FUNC, 1, createIdentifierNode($1), $3);}
                        ;

function_call_expression: IDENTIFIER '(' arg_list_call ')'       { $$=createOperatorNode(FUNC, 1, createIdentifierNode($1), $3);}
                        ;

arg_list                : type IDENTIFIER ',' arg_list           { $$=createOperatorNode(',', 2, createTypeNode($1->typ.type), createIdentifierNode($2));}
                        | type IDENTIFIER                        { $$=createOperatorNode(',', 2, createTypeNode($1->typ.type), createIdentifierNode($2));}
                        ;

arg_list_call           : arg_list_call ',' expression           { $$=createOperatorNode(',', 2, $1, $3);}
                        | expression                             { $$=$1;}
                        
                        ;

// Assignments and declarations rules
declaration_assignment  : declaration ';'                         {$$=$1;}
                        | assignment ';'                           {$$=$1;}
                        ;

declaration_assignment_loop     : declaration                    { $$=$1;}
                                | assignment                     { $$=$1;}
                                ;
declaration             : type IDENTIFIER ';'                                   { $$ = createOperatorNode(VAR_DECL, 2, createTypeNode($1->typ.type), createIdentifierNode($2)); }
                        | CONST type IDENTIFIER '=' expression ';'             { $$ = createOperatorNode(CONST_DECL, 2, createTypeNode($2->typ.type), createIdentifierNode($3), $5); }
                        | ENUM IDENTIFIER LBRACE enum_list RBRACE ';'           { $$ = createOperatorNode(ENUM_DECL, 2, createIdentifierNode($2), $4); }
                        | VAR IDENTIFIER ';'                                   { $$ = createOperatorNode(VAR_DECL, 2, createTypeNode(typeVar), createIdentifierNode($2)); }
                        ;


assignment              : IDENTIFIER '=' expression  { $$=createOperatorNode('=', 2, createIdentifierNode($1), $3);}
                        ;

// Enum rules
enum_declaration        : ENUM IDENTIFIER LBRACE enum_list RBRACE ';'  {$$=createOperatorNode(ENUM, 2, createIdentifierNode($2), $4);}
                        ;

enum_list               : enum_list ',' IDENTIFIER                      { $$ = createOperatorNode(ENUM, 1, createIdentifierNode($3)); }
                        | enum_list ',' IDENTIFIER '=' expression      { $$ = createOperatorNode(ENUM, 2, createIdentifierNode($3), $5); }
                        | IDENTIFIER                                    { $$ = createOperatorNode(ENUM, 1, createIdentifierNode($1)); }
                        | IDENTIFIER '=' expression                    { $$ = createOperatorNode(ENUM, 2, createIdentifierNode($1), $3); }
                        ;


expression              : binary_expression  { $$=$1;}
                        | unary_expression   { $$=$1;}
                        ;

binary_expression      : expression '+' expression   { $$=createOperatorNode('+', 2, $1, $3); }
                        | expression '-' expression  { $$=createOperatorNode('-', 2, $1, $3); }
                        | expression '*' expression  { $$=createOperatorNode('*', 2, $1, $3); }
                        | expression '/' expression  { $$=createOperatorNode('/', 2, $1, $3); }
                        | expression '%' expression  { $$=createOperatorNode('%', 2, $1, $3); }
                        | expression EQ expression   { $$=createOperatorNode(EQ, 2, $1, $3); }
                        | expression NEQ expression  { $$=createOperatorNode(NEQ, 2, $1, $3); }
                        | expression LT expression   { $$=createOperatorNode(LT, 2, $1, $3); }
                        | expression GT expression   { $$=createOperatorNode(GT, 2, $1, $3); }
                        | expression LTE expression  { $$=createOperatorNode(LTE, 2, $1, $3); }
                        | expression GTE expression  { $$=createOperatorNode(GTE, 2, $1, $3); }
                        | expression AND expression  { $$=createOperatorNode(AND, 2, $1, $3); }
                        | expression OR expression   { $$=createOperatorNode(OR, 2, $1, $3); }
                        | '(' expression ')'         { $$=$2; }
                        | value                      { $$=$1; }
                        | IDENTIFIER                 { $$=createIdentifierNode($1); }
                        | function_call_expression   { $$=$1;}
                        ;

unary_expression       : '-' expression %prec UMINUS  { $$ = createOperatorNode('-', 1, $2); }
                        | '!' expression %prec NOT    { $$ = createOperatorNode('!', 1, $2); }
                        ;


type                    : INT_TYPE   { $$ = createTypeNode(typeInt); }
                        | FLOAT_TYPE { $$ = createTypeNode(typeFloat); }
                        | BOOL_TYPE  { $$ = createTypeNode(typeBool); }
                        | CHAR_TYPE  { $$ = createTypeNode(typeChar); }
                        | STRING_TYPE { $$ = createTypeNode(typeString); }
                        ;

value                   : INTEGER { $$ = createIntConstantNode($1); }
                        | FLOAT   { $$ = createFloatConstantNode($1); }
                        | BOOL    { $$ = createBoolConstantNode($1); }
                        | CHAR    { $$ = createCharConstantNode($1); }
                        | STRING  { $$ = createStringConstantNode($1); }
                        | BOOL_TRUE  { $$ = createBoolConstantNode($1); }
                        | BOOL_FALSE { $$ = createBoolConstantNode($1); }
                        ;

%%


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
