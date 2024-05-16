/* part 1 defintions */
%{
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
    void getArgList(nodeType *node, int *argCount, char*** argList);
    bool doesStringExist(char *str, char **array, int size);

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
%token IF ELSE WHILE DO FOR SWITCH CASE DEFAULT BREAK RETURN EXIT CONTINUE PRINT ENUM CALL

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

program                 : start_scope statement_list     {execute($2,1,0);freeNode($2);} 
                      
                        ;


statement_list          : statement                          {$$=$1;}
                        | statement_list statement           {$$=createOperatorNode(';', 2, $1, $2);}
                    
                        ;   

// Statements rules
statement               : declaration_assignment            {$$=$1;}
                        | enum_declaration                  {$$=$1;}
                        | function_call                     {$$=$1;}
                        | print_statement                   {$$=$1;}
                        | if_condition_statement            {$$=$1;}
                        | switch_statement                  {$$=$1;}
                        | while_loop                        {$$=$1;}
                        | do_while_loop                     {$$=$1;}
                        | for_loop                          {$$=$1;}
                        | function_declaration               {$$=$1;}
                        | expression                         {$$=$1;}
                        ;

// Print statement rules
print_statement         : PRINT '(' expression ')' ';'    {$$= createOperatorNode(PRINT, 1, $3);}

// Statements rules: Conditional statements
if_condition_statement  : IF '(' expression ')' LBRACE start_scope statement_list RBRACE end_scope                                                              {$$ = createOperatorNode(IF,2,$3,$7);}
                        | IF '(' expression ')' LBRACE start_scope statement_list RBRACE end_scope ELSE LBRACE start_scope statement_list RBRACE end_scope      {$$ = createOperatorNode(IF, 2, $3, $7, $13);}
                        ;
switch_statement        : SWITCH '(' expression ')' LBRACE case_list case_default RBRACE    {$$ = createOperatorNode(SWITCH, 2, $3, $6);}
                        ;

case_list            : case_list CASE expression ':' statement_list BREAK ';'  {$$ = createOperatorNode(CASE,3,$1,$3,$5);}
                     | CASE expression ':' statement_list BREAK ';'            {$$ = createOperatorNode(CASE, 2, $2, $4);}
                     ;

case_default            : DEFAULT ':' statement_list BREAK ';'                  {$$ = createOperatorNode(DEFAULT, 1, $3);}
                        ;


// Statements rules: Loop statements
while_loop              : WHILE '(' expression ')' LBRACE start_scope statement_list RBRACE end_scope           {
                                                                                                                              
                                                                                                                                $$ = createOperatorNode(WHILE, 2, $3, $7);
                                                                                                                                }
                                                                                                                                                    ;

do_while_loop           : DO LBRACE start_scope statement_list RBRACE end_scope WHILE '(' expression ')' ';'    { $$ = createOperatorNode(DO, 2, $4, $9);}
                        ;

for_loop                : FOR start_scope '(' declaration_assignment_loop ';' expression';' declaration_assignment_loop ')' LBRACE  statement_list RBRACE end_scope  {$$ = createOperatorNode(FOR, 3, $4, $6, $8);}
                        ;

// Functions rules
function_declaration    : type IDENTIFIER start_scope '(' arg_list ')' LBRACE  statement_list RETURN expression ';' RBRACE end_scope     
                                                                                                                                        { 
 
                                                                                                                                            SymbolEntry *entry = getSymbolEntryFromParentScope(currTable, $2);
                                                                    
                                                                                                                                            if(entry == NULL){
                                                                                                                                                bool noError = handleReturnTypeCheck($1, $10);
                                                                                                                                                

                                                                                                                                                if (noError) {
                                                                                                                                                    // Itirate over the arguments types to add them
                                                                                                                                                    int argCount = 0;
                                                                                                                                                    char** argList = NULL;
                                                                                                                                                    getArgList($5, &argCount, &argList);
                                                                                                                                                    SymbolEntry *newEntry = create_function_SymbolEntry($2, 0, 1, currentLineNumber, argCount, argList, conEnumToString($1->typ.type));
                                                                                                                                                    addSymbolEntry(currTable, newEntry);
                                                                                                                                                    $$=createOperatorNode(FUNC, 5, createTypeNode($1->typ.type), createIdentifierNode($2), $5, $8, $10);
                                                                                                                                                }
                                                                                                                                                else{
                                                                                                                                                    throwError("Type mismatch. Return type does not match function declaration", currentLineNumber, semanticErrorsFile);
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                            else{
                                                                                                                                                throwError("Function name already declared", currentLineNumber, semanticErrorsFile);
                                                                                                                                            }
                                                                                                                                        }
                        | VOID_TYPE IDENTIFIER start_scope '(' arg_list ')' LBRACE  statement_list RBRACE end_scope                      
                                                                                                                                        { 

                                                                                                                                            SymbolEntry *entry = getSymbolEntryFromParentScope(currTable, $2);
                                                                    
                                                                                                                                            if(entry == NULL){
                                                                                                                                                // Itirate over the arguments types to add them
                                                                                                                                                int argCount = 0;
                                                                                                                                                char** argList = NULL;
                                                                                                                                                getArgList($5, &argCount, &argList);
                                                                                                                                                SymbolEntry *newEntry = create_function_SymbolEntry($2, 0, 1, currentLineNumber, argCount, argList, "Void");
                                                                                                                                                addSymbolEntry(currTable, newEntry);
                                                                                                                                                $$=createOperatorNode(FUNC, 4, createTypeNode(typeVoid), createIdentifierNode($2), $5, $8);
                                                                                                                                            }
                                                                                                                                            else{
                                                                                                                                                throwError("Function name already declared", currentLineNumber, semanticErrorsFile);
                                                                                                                                            }
                                                                                                                                        }
                        | type IDENTIFIER start_scope '(' arg_list ')' LBRACE   RETURN expression ';' RBRACE end_scope                   
                                                                                                                                        { 

                                                                                                                                            SymbolEntry *entry = getSymbolEntryFromParentScope(currTable, $2);
                                                                    
                                                                                                                                            if(entry == NULL){
                                                                                                                                                bool noError = handleReturnTypeCheck($1, $9);
                                                                                                                                                

                                                                                                                                                if (noError) {
                                                                                                                                                    // Itirate over the arguments types to add them
                                                                                                                                                    int argCount = 0;
                                                                                                                                                    char** argList = NULL;
                                                                                                                                                    getArgList($5, &argCount, &argList);
                                                                                                                                                    SymbolEntry *newEntry = create_function_SymbolEntry($2, 0, 1, currentLineNumber, argCount, argList, conEnumToString($1->typ.type));
                                                                                                                                                    addSymbolEntry(currTable, newEntry);
                                                                                                                                                    $$=createOperatorNode(FUNC, 3, createTypeNode($1->typ.type), createIdentifierNode($2), $5, $9);
                                                                                                                                                }
                                                                                                                                                else{
                                                                                                                                                    throwError("Type mismatch. Return type does not match function declaration", currentLineNumber, semanticErrorsFile);
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                            else{
                                                                                                                                                throwError("Function name already declared", currentLineNumber, semanticErrorsFile);
                                                                                                                                            }
                                                                                                                                        }
                        ;


function_call           : IDENTIFIER '(' arg_list_call ')' ';'   { 
                                                                    // $$=createOperatorNode(CALL, 1, createIdentifierNode($1), $3);
                                                                    // // Check that the function name exists in the symbol table
                                                                    // SymbolEntry *entry = checkIdNodeDeclaration(currTable, $1);
                                                                    // if (entry != NULL) {
                                                                    //     if (entry->isFunc) {
                                                                    //         // Create 2 checks:
                                                                    //         // Check that the number of arguments is correct
                                                                    //         // Check that the types of the arguments are correct
                                                                    //     } else {
                                                                    //         throwError("Identifier is not a function", currentLineNumber, semanticErrorsFile);
                                                                    //     }
                                                                    // } else {
                                                                    //     throwError("Function name not declared", currentLineNumber, semanticErrorsFile);
                                                                    // }
                                                                }
                        ;

function_call_expression: IDENTIFIER '(' arg_list_call ')'       { $$=createOperatorNode(CALL, 1, createIdentifierNode($1), $3);}
                        ;

arg_list                : type IDENTIFIER ',' arg_list          { 
                                                                    //add the variable in arg list to the symbol table
                                                                    SymbolEntry *newEntry = create_variable_SymbolEntry($2, conEnumToString($1->typ.type), 1, 0, 0, NULL, currentLineNumber);
                                                                    addSymbolEntry(currTable, newEntry);
                                                                    $$=createOperatorNode(',', 2, createTypeNode($1->typ.type), createIdentifierNode($2));
                                                                    // Concatenate the current node with the rest of the list
                                                                    $$ = createOperatorNode(',', 2, $$, $4);
                                                                }
                        | type IDENTIFIER                           
                                                                { 
                                                                    $$=createOperatorNode(',', 2, createTypeNode($1->typ.type), createIdentifierNode($2));
                                                                    
                                                                    //add the variable in arg list to the symbol table
                                                                    SymbolEntry *newEntry = create_variable_SymbolEntry($2, conEnumToString($1->typ.type), 1, 0, 0, NULL, currentLineNumber);
                                                                    addSymbolEntry(currTable, newEntry);
                                                                }
                        |                                       { $$=NULL;}
                        ;

arg_list_call           : arg_list_call ',' expression           { $$=createOperatorNode(',', 2, $1, $3);}
                        | expression                             { $$=$1;}
                        |                                        { $$=NULL;}
                        ;
                
                

// Assignments and declarations rules

declaration_assignment  : declaration ';' { $$ = $1;}
                        | assignment ';' { $$ = $1;}
                        ;

declaration_assignment_loop     : declaration   { $$ = $1;}
                                | assignment    { $$ = $1;}
                                ;


declaration             : type IDENTIFIER                           
                                                                    { 
                                                                        SymbolEntry *entry = getSymbolEntryFomCurrentScope(currTable, $2);

                                                                        if(entry == NULL){
                                                                            SymbolEntry *newEntry = create_variable_SymbolEntry($2, conEnumToString($1->typ.type), 0, 0, 0, NULL, currentLineNumber);
                                                                            addSymbolEntry(currTable, newEntry);
                                                                            $$ = createOperatorNode(VAR, 2, createTypeNode($1->typ.type), createIdentifierNode($2));  
                                                                        }
                                                                        else{
                                                                            throwError("Variable already declared in this scope", currentLineNumber, semanticErrorsFile);
                                                                        }

                                                                    }
                        | type IDENTIFIER '=' expression            
                                                                    {  
                                                                        
                                                                        SymbolEntry *entry = getSymbolEntryFomCurrentScope(currTable, $2);
                                                                        if(entry == NULL){
                                                                            
                                                                            char* typeUnion;
                                                                            CheckTypeFunc checkFunc = getCheckFunction($1->typ.type, &typeUnion);
                                                                            bool noError = true;
                                                                            //expression can be => con, ID or op
                                                                            if($4->type == typeCon){
                                                                                noError = handleConNodeExpressionInDeclaration($1, $2, $4, true, 0);
                                                                                
                                                                            }
                                                                            else if($4->type == typeId){
                                                                                //i.e. int x = expr
                                                                                noError = handleIdNodeExpressionInDeclaration($1, $2, $4, true, 0);
                                                                                
                                                                            }
                                                                            else if($4->type==typeOpr){
                                                                                noError = handleOperandsExpressionInDeclaration($1, $2, $4, true, 0);
                                                                            }

                                                                            if(noError){
                                                                                $$ = createOperatorNode('=', 3, createTypeNode($1->typ.type), createIdentifierNode($2), $4); 
                                                                            }

                                                                        }
                                                                        else{
                                                                            throwError("Variable already declared in this scope", 1, semanticErrorsFile);
                                                                        }
                                                                    }
                                                                    
            | CONST type IDENTIFIER '=' expression                  
                                                                    {  
                                                                        SymbolEntry *entry = getSymbolEntryFomCurrentScope(currTable, $3);
                                                                        if(entry == NULL){
                                                                            
                                                                            char* typeUnion;
                                                                            CheckTypeFunc checkFunc = getCheckFunction($2->typ.type, &typeUnion);
                                                                            bool noError = true;
                                                                            //expression can be => con, ID or op
                                                                            if($5->type == typeCon){
                                                                                noError = handleConNodeExpressionInDeclaration($2, $3, $5, true, 1);
                                                                                
                                                                            }
                                                                            else if($5->type == typeId){
                                                                                //i.e. int x = expr
                                                                                noError = handleIdNodeExpressionInDeclaration($2, $3, $5, true, 1);
                                                                                
                                                                            }
                                                                            else if($5->type==typeOpr){
                                                                                noError = handleOperandsExpressionInDeclaration($2, $3, $5, true, 1);
                                                                            }

                                                                            if(noError){
                                                                                $$ = createOperatorNode(CONST, 3, createTypeNode($2->typ.type), createIdentifierNode($3), $5);
                                                                            }

                                                                        }
                                                                        else{
                                                                            throwError("Variable already declared in this scope", 1, semanticErrorsFile);
                                                                        }
                                                                    }
            | ENUM IDENTIFIER IDENTIFIER '=' IDENTIFIER             
                                                             
                                                                    {
                                                                        // a variable type of enum
                                                                        //errors to check: 1st id exists in enums
                                                                        // get the enum types
                                                                        //2nd id check that its not existing before under vars
                                                                        //3rd id check that its in the enum types
                                                                        //if no errors make new var with type enum

                                                                        bool noError=true;
                                                                        
                                                                        SymbolEntry *varEntry=getSymbolEntryFomCurrentScope(currTable, $3);
                                                                        if(varEntry==NULL){
                                                                            SymbolEntry *enumEntry=getSymbolEntryFromParentScope(currTable, $2);
                                                                            if(enumEntry!=NULL){
                                                                               int enumTypesCount= getEnumCount(enumEntry);
                                                                               char **enumTypes= getEnumTypesString(enumEntry);
                                                                               bool enumTypeExists=false;
                                                                               int strIndex=-1;
                                                                               for(int i=0; i<enumTypesCount; i++){
                                                                                    if (strcmp(enumTypes[i], $5) == 0) {
                                                                                        enumTypeExists=true;
                                                                                        strIndex=i;
                                                                                        break;
                                                                                    }
                                                                               }
                                                                               if(enumTypeExists){
                                                                                    char strValueIndex[20]; 
                                                                                    sprintf(strValueIndex, "%d", strIndex);
                                                                                    SymbolEntry *newEntry = create_variable_SymbolEntry($3, $2, 1, 0, 0, strValueIndex, currentLineNumber);
                                                                                    addSymbolEntry(currTable, newEntry);
                                                                               }
                                                                               else{
                                                                                    noError=false;
                                                                                    throwError("There is no such enumerator existing in the Enum", currentLineNumber, semanticErrorsFile);
                                                                               }


                                                                            }
                                                                            else{
                                                                                noError=false;
                                                                                throwError("No such enum exists. Enum has not been declared before", currentLineNumber, semanticErrorsFile);
                                                                            }
                                                                        }
                                                                        else{
                                                                            noError=false;
                                                                            throwError("Variable has been declared before in same scope", currentLineNumber, semanticErrorsFile);
                                                                        }

                                                                        if(noError)
                                                                        {
                                                                            $$ = createOperatorNode(ENUM, 3, createIdentifierNode($2),createIdentifierNode($3) ,createIdentifierNode($5));
                                                                        }

                                                                        
                                                                    }

            ;

assignment              : IDENTIFIER '=' expression              
                                                                    {     $$=createOperatorNode('=', 2, createIdentifierNode($1), $3);
                                                                        SymbolEntry *entry = getSymbolEntryFomCurrentScope(currTable, $1);
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
                                                                                if($3->type == typeCon){
                                                                                    char symbolValue[20];

                                                                                    if (checkTypeMismatchConNode($3, symbolValue, typeUnion, checkFunc)) {
                                                                                        setValue(entry, symbolValue);
                                                                                        setIsInitialized(entry, 1);
                                                                                        setIsUsed(entry, 1);
                                                                                    } else {
                                                                                        throwError("Type mismatch", currentLineNumber, semanticErrorsFile);
                                                                                    }
                                                                                    
                                                                                }
                                                                                else if($3->type == typeId){

                                                                                    SymbolEntry *idEntry = checkIdNodeDeclaration(currTable, $3->id.id);
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
                                                                                else if($3->type==typeOpr){
                                                                                    noError = handleOperandsExpressionInDeclaration($1, $1, $3, false, 0);
                                                                                }

                                                                                if(noError){
                                                                                    $$=createOperatorNode('=', 2, createIdentifierNode($1), $3);
                                                                                }
                                                                            }
                                                                        }
                                                                        else{
                                                                            throwError("Use of undeclared variable", 1, semanticErrorsFile);
                                                                        }
                                                                    }
                        ; 
// Enum rules
// enum Foo { a, b, c = 10, d, e = 1, f, g = f + c };
enum_declaration        : ENUM IDENTIFIER LBRACE enum_list RBRACE ';'   {
                                                                            //elana fhmah en enum_list hena is operator node either having 1 arg or 2 arg
                                                                            //1 yb2a id bs
                                                                            //2 yb2a id=expression

                                                                            //what about all the list b2a in enum list idk??---------
                                                                            //i will just for now take the case eno we have b2a enumerator wa7da goa el enum_list


                                                                            //enum errors check:
                                                                            //1.check that its not declared before:
                                                                            printf("hereeeeeeeeeeeeeee");
                                                                            printf("enum_declaration\n");
                                                                            SymbolEntry *entry = getSymbolEntryFomCurrentScope(currTable, $2);
                                                                            bool noError=false;
                                                                    
                                                                            if(entry == NULL){
                                                                                printf("entry not null!!!!!");
                                                                                //enum_list can be id,id,id
                                                                                //or id= expression, id, id
                                                                                // or id= expression , id=expression, id=expression
                                                                                //each enum_list is considered an operator
                                                                                
                                                                                //Errors:
                                                                                //check that enum list doesnt have duplicate identifiers
                                                                                //check if some are initialized that their type is int
                                                                                // check that multiple id's dont have same value if initialized
                                                                                //check that enums have id's onlyyy


                                                                                
                                                                                //get nops
                                                                                int enumListCount= 1;     //idk where to get that yet so its 1 for now

                                                                                //save types (strings and ints)
                                                                                char **typesStrings=malloc(enumListCount * sizeof(char *));
                                                                                int *typesInt=malloc(enumListCount * sizeof(int));
                                                                                int counter=0;
                                                                                
                                                                               
                                                                                

                                                                                for(int i=0; i<enumListCount; i++){
                                                                                    //check the nops
                                                                                    int nops=$4->opr.nops;   //for only 1 =>enum_list[i]
                                                                                    printf("lets see nops:%d", nops);

                                                                                    //if 1 then its iD
                                                                                    //if 2 then its an (id=expression)

                                                                                    if(nops==1){
                                                                                        if($4->opr.op[i]->type == typeId){
                                                                                            
                                                                                            //check that ID is not defined in same scope elsehwere (if we have int x we cannot use x inside enum)
                                                                                            SymbolEntry *entry = getSymbolEntryFomCurrentScope(currTable, $4->opr.op[0]->id.id);
                                                                                            if(entry ==NULL){
                                                                                                //check that ID is not existing before in the Enum itself
                                                                                                if(!doesStringExist($4->opr.op[0]->id.id, typesStrings, enumListCount)){
                                                                                                    //add it
                                                                                                    typesStrings[i] = strdup($4->opr.op[0]->id.id);
                                                                                                    typesInt[i]= counter;
                                                                                                    counter++;
                                                                                                }else{
                                                                                                   //error
                                                                                                    noError=false;
                                                                                                    throwError("redeclaration of enumerator inside ENUM", currentLineNumber, semanticErrorsFile);
                                                                                                    break;
                                                                                                }
                                                                                            }
                                                                                            else{
                                                                                                //Error of redecleration
                                                                                                noError=false;
                                                                                                throwError("redeclaration of identifer in the same scope", currentLineNumber, semanticErrorsFile);
                                                                                                break;
                                                                                            }
                                                                                        }
                                                                                        else{
                                                                                            //unexpected error
                                                                                            throwError("Expected an Identifier", currentLineNumber, semanticErrorsFile);
                                                                                            noError=false;
                                                                                            break;
                                                                                        }
                                                                                    }
                                                                                    else if(nops==2){ 
                                                                                        // id= expression [conenum, id, oper] 

                                                                                        //Errors on ID :  same as above
                                                                                        //Errors for expression:    

                                                                                        //EXPRESSION PART:
                                                                                        //---------------
                                                                                        if($4->opr.op[1]->type == typeCon){

                                                                                           //must be an integer only else Error message: enumerator value is Not an integer constant
                                                                                           //must be iValue
                                                                                         //not sure of condition
                                                                                        
                                                                                           if(conEnumToString($4->opr.op[1]->typ.type)=='Integer'){
                                                                                                typesInt[i]=$4->opr.op[1]->con.iValue;
                                                                                                //increment the counter to after it
                                                                                                counter= ($4->opr.op[1]->con.iValue) +1;
                                                                                           }
                                                                                        }
                                                                                        else if($4->opr.op[1]->type == typeId){
                                                                                            //first check if we have id declared and initialized before else error
                                                                                            //check that the type is int else error
                                                                                            //
                                                                                            //increment the counter to after it if no errors

                                                                                            SymbolEntry *entry = getSymbolEntryFromParentScope(currTable, $4->opr.op[1]->id.id);
                                                                                            if(entry!=NULL){
                                                                                                if(getType(entry)=="Integer"){
                                                                                                   char *charValue= getValue(entry);
                                                                                                   int intValue = atoi(charValue);
                                                                                                   typesInt[i]= intValue;
                                                                                                   counter= intValue +1;
                                                                                                }
                                                                                                else{
                                                                                                    throwError("Variable is not an integer constant", currentLineNumber, semanticErrorsFile);
                                                                                                    noError=false;
                                                                                                    break;
                                                                                                }

                                                                                            }
                                                                                            else{
                                                                                                throwError("Variable not declared before", currentLineNumber, semanticErrorsFile);
                                                                                                noError=false;
                                                                                                break;
                                                                                            }
                                                                                          

                                                                                        }
                                                                                        else if($4->opr.op[1]->type == typeOpr){
                                                                                            //missing
                                                                                            //also need execute 3shan nt2kd en value Int w 
                                                                                            //increment counter= value+1
                                                                                        }


                                                                                    }
                                                                                }
                                                                                
                                                                                if(noError){
                                                                                    
                                                                                    SymbolEntry *newEntryEnum =create_enum_SymbolEntry($2, 0, 0, currentLineNumber, enumListCount, typesStrings,typesInt);
                                                                                    addSymbolEntry(currTable, newEntryEnum);
                                                                                    //msh mot2kda de mknha eh:
                                                                                    $$=createOperatorNode(ENUM, 2, createIdentifierNode($2), $4);
                                                                                }
                                                                            }
                                                                            else{
                                                                                throwError("redeclaration of ENUM", currentLineNumber, semanticErrorsFile);
                                                                                
                                                                            }

                                                                            

                                                                        }
                        ;


enum_list               : enum_list ',' IDENTIFIER                      { $$ = createOperatorNode(ENUM, 1, createIdentifierNode($3)); }
                        | enum_list ',' IDENTIFIER '=' expression       { $$ = createOperatorNode(ENUM, 2, createIdentifierNode($3), $5); }
                        | IDENTIFIER                                    { $$ = createOperatorNode(ENUM, 1, createIdentifierNode($1)); }
                        | IDENTIFIER '=' expression                     { $$ = createOperatorNode(ENUM, 2, createIdentifierNode($1), $3); }
                        ;

// Expressions rules

expression              : binary_expression  { $$=$1;}
                        | unary_expression   { $$=$1;}

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

start_scope             :   {
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
                        ;

end_scope               :   {
                                printf("end of scope\n");
                                currentScope--;
                                prevTable = currTable;
                                currTable = currTable->parent;
                            }
                        ;

%%

void yyerror(const char *s) {
    fprintf(syntaxErrorsFile, "Syntax error at line %d: %s\n", currentLineNumber, s);
}

bool doesStringExist(char *str, char **array, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(str, array[i]) == 0) {
            return true; 
        }
    }
    return false; 
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

void getArgList(nodeType *node, int *argCount, char*** argList) {
    if (node->type == typeOpr) {
        for (int i = 0; i < node->opr.nops; i++) {
            getArgList(node->opr.op[i], argCount, argList);
        }
    } else if (node->type == typeDef) {
        // Allocate memory for the new argument in argList
        (*argList) = realloc((*argList), ((*argCount) + 1) * sizeof(char*));
        // Allocate memory for the argument string
        (*argList)[*argCount] = malloc((strlen(conEnumToString(node->typ.type)) + 1) * sizeof(char));
        // Copy the argument string into the allocated memory
        strcpy((*argList)[*argCount], conEnumToString(node->typ.type));
        printf("string: %s\n", (*argList)[*argCount]);
        (*argCount)++;
    }
}

void checkArgListTpes(nodeType *node, int *argCount, char*** argList) {
    if (node->type == typeOpr) {
        for (int i = 0; i < node->opr.nops; i++) {
            getArgList(node->opr.op[i], argCount, argList);
        }
    } else if (node->type == typeDef) {
        // Allocate memory for the new argument in argList
        (*argList) = realloc((*argList), ((*argCount) + 1) * sizeof(char*));
        // Allocate memory for the argument string
        (*argList)[*argCount] = malloc((strlen(conEnumToString(node->typ.type)) + 1) * sizeof(char));
        // Copy the argument string into the allocated memory
        strcpy((*argList)[*argCount], conEnumToString(node->typ.type));
        printf("string: %s\n", (*argList)[*argCount]);
        (*argCount)++;
    }
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
