/* part 1 defintions */
%{
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
    SymbolTable *table = createSymbolTable("global", NULL);
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
            if_condition_statement switch_statement case_list case_default while_loop do_while_loop
            for_loop function_declaration function_call arg_list arg_list_call declaration_assignment declaration 
            assignment enum_declaration enum_list expression type value binary_expression unary_expression function_call_expression declaration_assignment_loop
            start_scope end_scope
%%

program                 : statement_list                    {printf("start of program\n");}    
                        ;


statement_list          : statement                          {}
                        | statement_list statement           {}
                    
                        ;   

// Statements rules
statement               : declaration_assignment            {}
                        | enum_declaration                  {}
                        | function_call                     {}
                        | print_statement                   {}
                        | if_condition_statement            {}
                        | switch_statement                  {}
                        | while_loop                        {}
                        | do_while_loop                     {}
                        | for_loop                          {}
                        |function_declaration               {}
                        |expression                         {}
                        ;

// Print statement rules
print_statement         : PRINT '(' expression ')' ';'    {}

// Statements rules: Conditional statements
if_condition_statement  : IF '(' expression ')' LBRACE start_scope statement_list RBRACE end_scope                                                              {printf("hi if 1\n");}
                        | IF '(' expression ')' LBRACE start_scope statement_list RBRACE end_scope ELSE LBRACE start_scope statement_list RBRACE end_scope      {printf("hi if 2\n");}
                        ;
switch_statement        : SWITCH '(' expression ')' LBRACE case_list case_default RBRACE                                                  {}
                        ;

case_list            : case_list CASE expression ':' statement_list BREAK ';'  {}
                     | CASE expression ':' statement_list BREAK ';'            {}
                     ;

case_default            : DEFAULT ':' statement_list BREAK ';'                  {}
                        ;


// Statements rules: Loop statements
while_loop              : WHILE '(' expression ')' LBRACE start_scope statement_list RBRACE end_scope           {}

do_while_loop           : DO LBRACE start_scope statement_list RBRACE end_scope WHILE '(' expression ')' ';'    {}
                        ;

for_loop                : FOR '(' declaration_assignment_loop ';' expression';' declaration_assignment_loop ')' LBRACE start_scope statement_list RBRACE end_scope  {}
                        ;

// Functions rules
function_declaration   : type IDENTIFIER '(' arg_list ')' LBRACE start_scope statement_list RETURN statement_list';' RBRACE end_scope  {}
                        | VOID_TYPE IDENTIFIER '(' arg_list ')' LBRACE start_scope statement_list RBRACE end_scope                     {}
                        |type IDENTIFIER '(' arg_list ')' LBRACE start_scope  RETURN statement_list RBRACE end_scope                   {}
                        ;

function_call           : IDENTIFIER '(' arg_list_call ')' ';'  {}
                        ;

function_call_expression: IDENTIFIER '(' arg_list_call ')'      {}
                        ;

arg_list                : type IDENTIFIER ',' arg_list          {}
                        | type IDENTIFIER                       {}

arg_list_call           : arg_list_call ',' expression          {}
                        | expression                            {}
                        |
                        ;
                

// Assignments and declarations rules

declaration_assignment  : declaration';'    {}
                        | assignment';'     {}
                        ;

declaration_assignment_loop     : declaration       {}
                                | assignment        {}
                                ;

declaration             : type IDENTIFIER                           {  }
                        | type IDENTIFIER '=' expression            { }
                        | CONST type IDENTIFIER '=' expression      {  }
                        | ENUM IDENTIFIER IDENTIFIER '=' IDENTIFIER { }
                        | VAR IDENTIFIER                            { }
                        ;

assignment              : IDENTIFIER '=' expression              {printf("hi assign\n");}
                        ; 
// Enum rules
// enum Foo { a, b, c = 10, d, e = 1, f, g = f + c };
enum_declaration        : ENUM IDENTIFIER LBRACE enum_list RBRACE ';'   {}
                        ;


enum_list               : enum_list ',' IDENTIFIER                      { }
                        | enum_list ',' IDENTIFIER '=' expression       { }
                        | IDENTIFIER                                    { }
                        | IDENTIFIER '=' expression                     { }
                        ;

// Expressions rules

expression              : binary_expression  { }
                        | unary_expression   { }

binary_expression      : expression '+' expression   { }
                        | expression '-' expression  { }
                        | expression '*' expression  { }
                        | expression '/' expression  { }
                        | expression '%' expression  { }
                        | expression EQ expression   { }
                        | expression NEQ expression  { }
                        | expression LT expression   {}
                        | expression GT expression   {}
                        | expression LTE expression  { }
                        | expression GTE expression  { }
                        | expression AND expression  { }
                        | expression OR expression   {}
                        | '(' expression ')'         {  }
                        | value                      {  }
                        | IDENTIFIER                 {}
                        | function_call_expression   { }

unary_expression       : '-' expression %prec UMINUS  { }
                        | '!' expression %prec NOT    { }
                        ;


type                    : INT_TYPE      {  }
                        | FLOAT_TYPE    {  }
                        | BOOL_TYPE     {  }
                        | CHAR_TYPE     {  }
                        | STRING_TYPE   {  }
                        ;

value                   : INTEGER
                        | FLOAT    
                        | BOOL
                        | CHAR
                        | STRING
                        | BOOL_TRUE
                        | BOOL_FALSE
                        ;

start_scope             :   {printf("start of scope\n");}
                        ;

end_scope               :   {printf("end of scope\n");}

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
