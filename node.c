
#include "node.h"
#include "y.tab.h"
#include <stdio.h>
#include "node.h"

void yyerror(const char *s);
char Result[1000000];
int LoopsNames = 0;
nodeType *createTypeNode(conEnum type)
{
    nodeType *p = malloc(sizeof(nodeType));
    if (p == NULL)
    {
        yyerror("Memory allocation failed");
        return NULL;
    }
    p->type = typeDef;
    p->typ.type = type;
    return p;
}

nodeType *createConstantNode()
{
    nodeType *p;

    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("Memory allocation failed");

    p->type = typeCon;

    return p;
}

nodeType *createIntConstantNode(int value)
{
    nodeType *p;
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("Memory allocation failed");

    p->type = typeCon;
    p->con.typeConst = typeInt; // Set the constant type
    p->con.iValue = value;

    return p;
}

nodeType *createFloatConstantNode(float value)
{
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.typeConst = typeFloat;
    p->con.fValue = value;
    return p;
}

nodeType *createBoolConstantNode(bool value)
{
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.typeConst = typeBool;
    p->con.iValue = value;
    return p;
}

nodeType *createCharConstantNode(char value)
{
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.typeConst = typeChar;
    p->con.cValue = value;
    return p;
}

nodeType *createStringConstantNode(char *value)
{
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.typeConst = typeString;
    p->con.sValue = strdup(value);
    return p;
}

nodeType *createIdentifierNode(char *id)
{
    nodeType *p;

    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("Memory allocation failed");

    p->type = typeId;
    p->id.id = id;
    return p;
}

nodeType *createOperatorNode(int oper, int nops, ...)
{
    printf("createOper");
    va_list ap;
    nodeType *p;
    int i;

    if ((p = malloc(sizeof(nodeType) + (nops - 1) * sizeof(nodeType *))) == NULL)
        yyerror("Memory allocation failed");

    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType *);
    va_end(ap);
    return p;
}

void execute(nodeType *p, int first, int insideScope)
{

    FILE *outputFile;
    if (first == 1)
    {
        outputFile = fopen("QuadrapletsFile", "w");
    }
    else
    {
        outputFile = fopen("QuadrapletsFile", "a+");
    }

    if (!outputFile)
    {
        perror("Error opening output file");
        return;
    }

    if (p == NULL)
    {
        fprintf(outputFile, "error: null node\n");
        return;
    }
    switch (p->type)
    {
    case typeCon:

        switch (p->con.typeConst)
        {
        case typeInt:

            sprintf(Result, "%s%d ", Result, p->con.iValue);

            break;
        case typeFloat:
            sprintf(Result, "%s%f ", Result, p->con.fValue);
            break;
        case typeString:

            sprintf(Result, "%s%s ", Result, p->con.sValue);
            break;
        case typeChar:
            sprintf(Result, "%s%c ", Result, p->con.cValue);
            break;
        case typeBool:

            sprintf(Result, "%s%s ", Result, p->con.iValue ? "true" : "false");
            break;

        default:
            fprintf(outputFile, "error: unknown constant type\n");
            break;
        }
        fprintf(outputFile, "\n");
        break;
    case typeId:
        sprintf(Result, "%s%s ", Result, p->id.id);
        break;
    case typeOpr:

        switch (p->opr.oper)
        {
        case WHILE:
            if (insideScope == 1)
            {
                sprintf(Result, "\nL%d :\n", LoopsNames);
                execute(p->opr.op[0], 0, 1);
                strcat(Result, "\n");

                execute(p->opr.op[1], 0, 1);

                sprintf(Result, "%s jz\tL%d\n", Result, LoopsNames);

                LoopsNames++;
                sprintf(Result, "%sjmp\tL%d\n", Result, LoopsNames);

                fprintf(outputFile, "\nL%d:\n", LoopsNames);

                LoopsNames += 1;
            }
            else
            {
                sprintf(Result, "\nL%d :\n", LoopsNames);
                execute(p->opr.op[0], 0, 1);
                fprintf(outputFile, "\n");
                execute(p->opr.op[1], 0, 1);

                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                fprintf(outputFile, "jz\tL%d\n", LoopsNames);

                LoopsNames++;

                fprintf(outputFile, "jmp\tL%d\n", LoopsNames);
                fprintf(outputFile, "\nL%d:\n", LoopsNames);

                LoopsNames += 1;
            }
            insideScope = 0;
            break;

        case IF:
            fprintf(outputFile, "\nIFScope:\n");
            execute(p->opr.op[0], 0, 1);

            execute(p->opr.op[1], 0, 1);
            if (p->opr.nops > 2)
            {
                fprintf(outputFile, " else ");
                execute(p->opr.op[2], 0, 1);
            }
            fprintf(outputFile, Result);
            memset(Result, 0, sizeof(Result));
            fprintf(outputFile, "ENDIF\n");
            insideScope = 0;
            break;
        case PRINT:
            if (insideScope == 1)
            {
                strcat(Result, "print ");

                execute(p->opr.op[0], 0, 1);
                strcat(Result, "\n ");
            }
            else
            {
                fprintf(outputFile, "print ");
                execute(p->opr.op[0], 0, 0);
                fprintf(outputFile, "\n");
            }

            break;
        case ENUM:
            switch (p->opr.nops)
            {
            case 1:
                strcat(Result, "EnumDef ");
                execute(p->opr.op[0], 0, 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result)); // Clear Result after printing
                break;
            case 2:
                strcat(Result, "EnumDef ");
                execute(p->opr.op[0], 0, 0);
                execute(p->opr.op[1], 0, 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                break;
            case 3:
                strcat(Result, "EnumDef ");
                execute(p->opr.op[0], 0, 0);
                execute(p->opr.op[1], 0, 0);
                execute(p->opr.op[2], 0, 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                break;
            default:
                break;
            }
            break;
        case VAR:
            if (insideScope == 1)
            {
                strcat(Result, "VAR ");
                execute(p->opr.op[0], 0, 1);
            }
            else
            {
                fprintf(outputFile, "VAR ");
                execute(p->opr.op[0], 0, 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
            }

            break;
        case CONST:
            if (insideScope == 1)
            {
                strcat(Result, "CONST ");
                execute(p->opr.op[1], 0, 1);
                execute(p->opr.op[2], 0, 1);
            }
            else
            {
                fprintf(outputFile, "CONST ");
                execute(p->opr.op[1], 0, 0);
                execute(p->opr.op[2], 0, 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
            }

            break;
        case FUNC:
            switch (p->opr.nops)
            {
            case 5:
                /*
                    type IDENTIFIER start_scope '(' arg_list ')' LBRACE statement_list RETURN expression ';' RBRACE end_scope
                        $$ = createOperatorNode(FUNC, 5, createTypeNode($1->typ.type), createIdentifierNode($2), $5, $8, $10);
                    0->type 1->identifier 2->arg_list 3->statement_list 4->expression*/

                execute(p->opr.op[1], 0, 1);
                strcat(Result, ":\n");
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                execute(p->opr.op[3], 0, 1);

                strcat(Result, "RETURN ");
                execute(p->opr.op[4], 0, 1);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                break;

            case 4:
                execute(p->opr.op[1], 0, 1);
                strcat(Result, ":\n");
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                execute(p->opr.op[3], 0, 1);
                fprintf(outputFile, Result);

                break;

            default:
                break;
            }
            fprintf(outputFile, "\nEND OF FUNCTION");
            insideScope = 0;
            break;
        case SWITCH:
            fprintf(outputFile, "\nswitch ");
            execute(p->opr.op[0], 0, 0);
            break;
        case DEFAULT:
            fprintf(outputFile, "\ndefault ");
            execute(p->opr.op[0], 0, 0);
            break;
        case CASE:
            fprintf(outputFile, "\ncase ");
            execute(p->opr.op[0], 0, 0);
            break;
        case CALL:
            if (insideScope == 1)
            {
                strcat(Result, "\nCALL ");
                execute(p->opr.op[0], 0, 1);
            }
            else
            {
                fprintf(outputFile, "\nCALL ");
                execute(p->opr.op[0], 0, 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
            }
            break;
        case '=':
            switch (p->opr.nops)
            {
            case 2:
                if (insideScope == 1)
                {
                    strcat(Result, "\nASSIGN ");
                    execute(p->opr.op[1], 0, 1);
                    execute(p->opr.op[0], 0, 1);
                    strcat(Result, "\n");
                }
                else
                {
                    fprintf(outputFile, "\nASSIGN ");
                    execute(p->opr.op[1], 0, 0);
                    execute(p->opr.op[0], 0, 0);
                    fprintf(outputFile, Result);
                    fprintf(outputFile, "\n");
                    memset(Result, 0, sizeof(Result));
                }
                break;

            case 3:
                if (insideScope == 1)
                {
                    strcat(Result, "\nASSIGN ");
                    execute(p->opr.op[0], 0, 1);
                    execute(p->opr.op[2], 0, 1);
                    execute(p->opr.op[1], 0, 1);

                    strcat(Result, "\n");
                }
                else
                {
                    fprintf(outputFile, "\nASSIGN ");
                    execute(p->opr.op[0], 0, 0);
                    execute(p->opr.op[2], 0, 0);
                    execute(p->opr.op[1], 0, 0);

                    fprintf(outputFile, Result);
                    fprintf(outputFile, "\n");
                    memset(Result, 0, sizeof(Result));
                }
                break;

            default:
                break;
            }

            break;
        case '+':

            if (insideScope == 1)
            {

                strcat(Result, "\nADD ");
                execute(p->opr.op[0], 0, 1);
                execute(p->opr.op[1], 0, 1);
            }
            else
            {

                fprintf(outputFile, "\nADD ");
                char *Temp;
                Temp = strdup(Result);

                memset(Result, 0, sizeof(Result));

                execute(p->opr.op[0], 0, 0);
                execute(p->opr.op[1], 0, 0);
                strcat(Result, "TEMP ");
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                strcat(Result, "TEMP ");
                sprintf(Result, "%s%s ", Result, Temp);
                free(Temp);
            }
            break;

        case '-':
            if (insideScope == 1)
            {
                strcat(Result, "\nSUB ");
                execute(p->opr.op[0], 0, 1);
                execute(p->opr.op[1], 0, 1);
            }
            else
            {

                fprintf(outputFile, "\nSUB ");
                char *Temp;
                Temp = strdup(Result);

                memset(Result, 0, sizeof(Result));

                execute(p->opr.op[0], 0, 0);
                execute(p->opr.op[1], 0, 0);
                strcat(Result, "TEMP ");
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                strcat(Result, "TEMP ");
                sprintf(Result, "%s%s ", Result, Temp);
                free(Temp);
            }
            break;
        case '*':
            if (insideScope == 1)
            {
                strcat(Result, "\nMUL ");
                execute(p->opr.op[0], 0, 1);
                execute(p->opr.op[1], 0, 1);
            }
            else
            {

                fprintf(outputFile, "\nMUL ");
                char *Temp;
                Temp = strdup(Result);

                memset(Result, 0, sizeof(Result));

                execute(p->opr.op[0], 0, 0);
                execute(p->opr.op[1], 0, 0);
                strcat(Result, "TEMP ");
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                strcat(Result, "TEMP ");
                sprintf(Result, "%s%s ", Result, Temp);
                free(Temp);
            }
            break;
        case '/':
            if (insideScope == 1)
            {
                strcat(Result, "\nDIV ");
                execute(p->opr.op[0], 0, 1);
                execute(p->opr.op[1], 0, 1);
            }
            else
            {

                fprintf(outputFile, "\nDIV ");
                char *Temp;
                Temp = strdup(Result);

                memset(Result, 0, sizeof(Result));

                execute(p->opr.op[0], 0, 0);
                execute(p->opr.op[1], 0, 0);
                strcat(Result, "TEMP ");
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                strcat(Result, "TEMP ");
                sprintf(Result, "%s%s ", Result, Temp);
                free(Temp);
            }
            break;
        case ';':
            execute(p->opr.op[0], 0, 0);
            execute(p->opr.op[1], 0, 0);
            break;
        case ',':
            switch (p->opr.nops)
            {
            case 2:
                execute(p->opr.op[0], 0, 0);
                execute(p->opr.op[1], 0, 0);
                break;
            case 3:
                execute(p->opr.op[0], 0, 0);
                execute(p->opr.op[1], 0, 0);
                execute(p->opr.op[2], 0, 0);
                break;
            default:
                break;
            }
        case '!':
            if (insideScope == 1)
            {
                strcat(Result, "\nNOT ");
                execute(p->opr.op[0], 0, 1);
            }
            else
            {
                fprintf(outputFile, "\nNOT ");
                execute(p->opr.op[0], 0, 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
            }
            break;

        case LT:
            if (insideScope == 1)
            {
                strcat(Result, "\nLessTn ");
                execute(p->opr.op[0], 0, 1);
                execute(p->opr.op[1], 0, 1);
            }
            else
            {
                fprintf(outputFile, "\nLessTn ");
                execute(p->opr.op[0], 0, 0);
                execute(p->opr.op[1], 0, 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
            }
            break;

        case GT:
            if (insideScope == 1)
            {
                strcat(Result, "\nGrTn ");
                execute(p->opr.op[0], 0, 1);
                execute(p->opr.op[1], 0, 1);
            }
            else
            {
                fprintf(outputFile, "\nGrTn ");
                execute(p->opr.op[0], 0, 0);
                execute(p->opr.op[1], 0, 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
            }
            break;
        case LTE:
            if (insideScope == 1)
            {
                strcat(Result, "\nLessTnE ");
                execute(p->opr.op[0], 0, 1);
                execute(p->opr.op[1], 0, 1);
            }
            else
            {
                fprintf(outputFile, "\nLessTnE ");
                execute(p->opr.op[0], 0, 0);
                execute(p->opr.op[1], 0, 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
            }
            break;
        case GTE:
            if (insideScope == 1)
            {
                strcat(Result, "\nGrTnE ");
                execute(p->opr.op[0], 0, 1);
                execute(p->opr.op[1], 0, 1);
            }
            else
            {
                fprintf(outputFile, "\nGrTnE ");
                execute(p->opr.op[0], 0, 0);
                execute(p->opr.op[1], 0, 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
            }
            break;

        case NEQ:
            if (insideScope == 1)
            {
                strcat(Result, "\nIsNEQ ");
                execute(p->opr.op[0], 0, 1);
                execute(p->opr.op[1], 0, 1);
            }
            else
            {
                fprintf(outputFile, "\nIsNEQ ");
                execute(p->opr.op[0], 0, 0);
                execute(p->opr.op[1], 0, 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
            }
            break;

        case EQ:
            if (insideScope == 1)
            {
                strcat(Result, "\nIsEQ ");
                execute(p->opr.op[0], 0, 1);
                execute(p->opr.op[1], 0, 1);
            }
            else
            {
                fprintf(outputFile, "\nIsEQ ");
                execute(p->opr.op[0], 0, 0);
                execute(p->opr.op[1], 0, 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
            }
            break;
        default:
            fprintf(outputFile, "error: unknown operator '%d'\n");
            break;
        }
        fprintf(outputFile, "\n");
        break;
    }
    fclose(outputFile);
}

void freeNode(nodeType *p)
{
    if (!p)
        return;
    if (p->type == typeOpr)
    {
        for (int i = 0; i < p->opr.nops; i++)
        {
            freeNode(p->opr.op[i]);
        }
    }
    else if (p->type == typeCon)
    {
        if (p->con.typeConst == typeString)
        {
            free(p->con.sValue);
        }
    }
    else if (p->type == typeId)
    {
        free(p->id.id);
    }
    free(p);
}

const char *conEnumToString(conEnum enumValue)
{
    switch (enumValue)
    {
    case typeInt:
        return "Integer";
    case typeFloat:
        return "Float";
    case typeString:
        return "String";
    case typeChar:
        return "Char";
    case typeBool:
        return "Boolean";
    case typeConst:
        return "Constant";
    case typeND:
        return "Non-Defined";
    case typeVoid:
        return "Void";
    case typeVar:
        return "Variable";
    default:
        return "Unknown";
    }
}

conEnum stringToConEnum(const char *str)
{
    if (strcmp(str, "Integer") == 0)
    {
        return typeInt;
    }
    else if (strcmp(str, "Float") == 0)
    {
        return typeFloat;
    }
    else if (strcmp(str, "String") == 0)
    {
        return typeString;
    }
    else if (strcmp(str, "Char") == 0)
    {
        return typeChar;
    }
    else if (strcmp(str, "Boolean") == 0)
    {
        return typeBool;
    }
    else if (strcmp(str, "Constant") == 0)
    {
        return typeConst;
    }
    else if (strcmp(str, "Non-Defined") == 0)
    {
        return typeND;
    }
    else if (strcmp(str, "Void") == 0)
    {
        return typeVoid;
    }
    else
    {
        return typeVar;
    }
}

void printNode(nodeType *node)
{
    if (node == NULL)
    {
        printf("NULL\n");
        return;
    }

    switch (node->type)
    {
    case typeCon:
        switch (node->con.typeConst)
        {
        case typeInt:
            printf("Integer Constant: %d\n", node->con.iValue);
            break;
        case typeFloat:
            printf("Float Constant: %f\n", node->con.fValue);
            break;
        case typeString:
            printf("String Constant: %s\n", node->con.sValue);
            break;
        case typeChar:
            printf("Char Constant: %c\n", node->con.cValue);
            break;
        case typeBool:
            printf("Boolean Constant: %s\n", node->con.iValue ? "true" : "false");
            break;
        default:
            printf("Unknown Constant Type\n");
        }
        break;
    case typeId:
        printf("Identifier: %s\n", node->id.id);
        break;
    case typeOpr:
        printf("Operator: %d\n", node->opr.oper);
        for (int i = 0; i < node->opr.nops; i++)
        {
            printf("Operand %d:\n", i + 1);
            printNode(node->opr.op[i]);
        }
        break;
    case typeDef:
        printf("Type Definition\n");
        break;
    default:
        printf("Unknown Node Type\n");
    }
}