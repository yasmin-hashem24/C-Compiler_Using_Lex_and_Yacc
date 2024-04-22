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
/* part 2 production rules */
%%

                     /* If-then-else statement, while loops, repeat-until loops, for loops, switch statement */
"if"                { return IF; }
"else"              { return ELSE; }
"while"             { return WHILE; }
"for"               { return FOR; }
"switch"            { return SWITCH; }
"do"                { return DO; }
"case"              {return CASE;}
"default"           {return DEFAULT;}
"break"             {return BREAK;}
"return"            {return RETURN;}
"exit"              {return EXIT;}
"continue"          {return CONTINUE;}
"print"             {return PRINT;}
"enum"              {return ENUM;}
                       /* Variables and Constants declaration */
"var"               { return VAR; }
"const"             { return CONST; }
"func"              { return FUNC; }
"main"              { return MAIN; }
"include"           { return INCLUDE; }
"define"            { return DEFINE; }

"=="                { return EQ; }
"!="                { return NEQ; }
"<"                 { return LT; }
">"                 { return GT; }
"<="                { return LTE; }
">="                { return GTE; }
"&&"                { return AND; }
"||"                { return OR; }

[\(\)\+\\\-\*\/\%\[\]\=\!\,\:\;] { return yytext[0]; }

                    /* Block structure (nested scopes where variables may be declared at the beginning of blocks) */
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
           /* skip whitespace */
[\t\r]                             ; 
\n                      { ++currentLineNumber; }
\/\/[^\n]*                            ;                 /* single line comment */
\/\*([^*]|\*[^\/])*\*\/               ;                 /* multiline comment */


                     /* Datatypes */
"int"               { return INT_TYPE; }
"float"             { return FLOAT_TYPE; }
"bool"              { return BOOL_TYPE; }
"char"              { return CHAR_TYPE; }
"string"            { return STRING_TYPE; }
"void"              { return VOID_TYPE; }

                        /* boolean constants */
"true"              { yylval.bVal = 1; return BOOL_TRUE; }  // Assign value 1 for BOOL_TRUE
"false"             { yylval.bVal = 0; return BOOL_FALSE; } // Assign value 0 for BOOL_FALSE

                      /* Mathematical and logical expressions */
[0-9]+              { yylval.iVal = atoi(yytext); return INTEGER; }
\'[a-zA-Z0-9]\'       { yylval.cVal = strdup(yytext); return CHAR; }
[0-9]*\.[0-9]+        { yylval.fVal =  atof(yytext); return FLOAT; }
\"[_!\.@%&#$?^~'a-zA-Z0-9 ]*\"  { yylval.sVal = strdup(yytext); return STRING; }
[_a-zA-Z][_a-zA-Z0-9]*       {yylval.sVal = strdup(yytext);return IDENTIFIER;}               /* identifiers and variable names */

            /* Error handling */
.                   { yyerror("Unexpected character"); }

%%

/* part 3 user subroutines */
int yywrap(){
    return 1;
}