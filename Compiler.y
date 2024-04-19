/* part 1 defintions */
%{
    #include <stdio.h>
    #include <stdlib.h>

    void yyerror(char *s);
    int yylex();
%}

/* part 2 production rules */
%%



%%

/* part 3 user subroutines */
void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}

int main() {
    yyparse();
    return 0;
}