/* part 1 defintions */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h> 
    #include <string.h>
    #include "node.h"
    #include "y.tab.h"
    int currentLineNumber = 1;
%}

%option nounistd
%%
                    /* part 2 production rules */
                     /* If-then-else statement, while loops, repeat-until loops, for loops, switch statement */
"if"                { printf("IF\n"); return IF; }
"else"              { printf("ELSE\n"); return ELSE; }
"while"             { printf("WHILE\n"); return WHILE; }
"for"               { printf("FOR\n"); return FOR; }
"switch"            { printf("SWITCH\n"); return SWITCH; }
"do"                { printf("DO\n"); return DO; }
"case"              { printf("CASE\n"); return CASE; }
"default"           { printf("DEFAULT\n"); return DEFAULT; }
"break"             { printf("BREAK\n"); return BREAK; }
"return"            { printf("RETURN\n"); return RETURN; }
"exit"              { printf("EXIT\n"); return EXIT; }
"continue"          { printf("CONTINUE\n"); return CONTINUE; }
"print"             { printf("PRINT\n"); return PRINT; }
"enum"              { printf("ENUM\n"); return ENUM; }

                     /* Datatypes */
"int"               { printf("INT_TYPE\n"); return INT_TYPE; }
"float"             { printf("FLOAT_TYPE\n"); return FLOAT_TYPE; }
"bool"              { printf("BOOL_TYPE\n"); return BOOL_TYPE; }
"char"              { printf("CHAR_TYPE\n"); return CHAR_TYPE; }
"string"            { printf("STRING_TYPE\n"); return STRING_TYPE; }
"void"              { printf("VOID_TYPE\n"); return VOID_TYPE; }
                       /* Variables and Constants declaration */
"var"               { printf("VAR\n"); return VAR; }
"const"             { printf("CONST\n"); return CONST; }
"func"              { printf("FUNC\n"); return FUNC; }
"main"              { printf("MAIN\n"); return MAIN; }
"include"           { printf("INCLUDE\n"); return INCLUDE; }
"define"            { printf("DEFINE\n"); return DEFINE; }

"=="                { printf("EQ\n"); return EQ; }
"!="                { printf("NEQ\n"); return NEQ; }
"<"                 { printf("LT\n"); return LT; }
">"                 { printf("GT\n"); return GT; }
"<="                { printf("LTE\n"); return LTE; }
">="                { printf("GTE\n"); return GTE; }
"&&"                { printf("AND\n"); return AND; }
"||"                { printf("OR\n"); return OR; }

[\(\)\+\\\-\*\/\%\[\]\=\!\,\:\;] { printf("%s\n", yytext); return yytext[0]; }

                    /* Block structure (nested scopes where variables may be declared at the beginning of blocks) */
"{"                 { printf("LBRACE\n"); return LBRACE; }
"}"                 { printf("RBRACE\n"); return RBRACE; }


                        /* boolean constants */
"true"              { yylval.bVal = 1; printf("BOOL_TRUE\n"); return BOOL_TRUE; }  // Assign value 1 for BOOL_TRUE
"false"             { yylval.bVal = 0; printf("BOOL_FALSE\n"); return BOOL_FALSE; } // Assign value 0 for BOOL_FALSE

           /* skip whitespace */
[ \t\r]+                             ; 
\n                      { ++currentLineNumber; }
\/\/[^\n]*                            ;                 /* single line comment */
\/\*([^*]|\*[^\/]|[\n])*[\n]*\*\/   { 
                                        ++currentLineNumber;
                                        yytext[yyleng - 1] = '\0';
                                    }






                      /* Mathematical and logical expressions */
[0-9]+              { yylval.iVal = atoi(yytext); printf("INTEGER: %s\n", yytext); return INTEGER; }
\'[a-zA-Z0-9]\'    { yylval.cVal = strdup(yytext); printf("CHAR: %s\n", yytext); return CHAR; }
[0-9]*\.[0-9]+      { yylval.fVal =  atof(yytext); printf("FLOAT: %s\n", yytext); return FLOAT; }
\"[_!\.@%&#$?^~'a-zA-Z0-9 ]*\"  { yylval.sVal = strdup(yytext); printf("STRING: %s\n", yytext); return STRING; }
[_a-zA-Z][_a-zA-Z0-9]*       { yylval.sVal = strdup(yytext); printf("IDENTIFIER: %s\n", yytext); return IDENTIFIER; }               /* identifiers and variable names */

            /* Error handling */
.                   { printf("Unexpected character\n"); yyerror("Unexpected character"); }

%%


/* part 3 user subroutines */
int yywrap(){
    return 1;
}