/* part 1 defintions */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <y.tab.h>

%}

/* part 2 production rules */
%%
                     /* If-then-else statement, while loops, repeat-until loops, for loops, switch statement */
"if"                { return IF; }
"else"              { return ELSE; }
"while"             { return WHILE; }
"for"               { return FOR; }
"switch"            { return SWITCH; }
"repeat"            { return REPEAT; }
"until"             { return UNTIL; }
"case"              {return CASE;}
"default"           {return DEFAULT;}
"break"             {return BREAK;}
"return"            {return RETURN;}
"exit"              {return EXIT;}
"continue"          {return CONTINUE;}
"print"             {return PRINT;}

                       /* Variables and Constants declaration */
"var"               { return VAR; }
"const"             { return CONST; }
"func"              { return FUNC; }
"main"              { return MAIN; }
"include"           { return INCLUDE; }
"define"            { return DEFINE; }

                      /* Mathematical and logical expressions */
[0-9]+              { yylval.Integer = atoi(yytext); return INTEGER; }
[a-zA-Z0-9]+        { yylval.Char = strdup(yytext); return CHAR; }
[0-9]*\.[0-9]+      { yylval.Float  = atoi(yytext); return FLOAT; }
\"[_!\.@%&#$?^~'a-zA-Z0-9 ]*\"  { yylval.String = strdup(yytext); return STRING; }
[_a-zA-Z][_a-zA-Z0-9]*       {yylval.ID=strdup(yytext);return ID;}               /* identifiers and variable names */

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
[ \t\n\r]             ; 


            /* Error handling */
.                   { yyerror("Unexpected character"); }
                     /* Datatypes */
"int"               { return INT_TYPE; }
"float"             { return FLOAT_TYPE; }
"bool"              { return BOOL_TYPE; }
"char"              { return CHAR_TYPE; }
"string"            { return STRING_TYPE; }
"void"              { return VOID_TYPE; }

                        /* boolean constants */
"true"              {return BOOL_TRUE;}         
"false"             {return BOOL_FALSE;}


%%

/* part 3 user subroutines */
int yywrap(){
    return 1;
}