
#include "node.h"
#include "y.tab.h"
#include <stdio.h>
#include "node.h"

void yyerror(const char *s);
char Result[1000000];
int LoopsNames = 0;
int switchLabel = 0;
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
    case typeDef:
        break;
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
                LoopsNames++;
                sprintf(Result, "%s jz\tL%d\n", Result, LoopsNames);

                LoopsNames--;
                sprintf(Result, "%sjmp\tL%d\n", Result, LoopsNames);
                LoopsNames++;
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
                LoopsNames++;
                fprintf(outputFile, "jz\tL%d\n", LoopsNames);

                LoopsNames--;

                fprintf(outputFile, "jmp\tL%d\n", LoopsNames);
                LoopsNames += 1;
                fprintf(outputFile, "\nL%d:\n", LoopsNames);

                LoopsNames += 1;
            }
            insideScope = 0;
            break;

        case IF:

            fprintf(outputFile, "\nIFScope:\n");
            execute(p->opr.op[0], 0, 1);

            execute(p->opr.op[1], 0, 1);

            fprintf(outputFile, Result);
            memset(Result, 0, sizeof(Result));
            fprintf(outputFile, "ENDIF\n");
            insideScope = 0;
            break;

        case ELSE:
            fprintf(outputFile, "\nIFScope:\n");
            execute(p->opr.op[0], 0, 1);

            execute(p->opr.op[1], 0, 1);
            fprintf(outputFile, Result);
            memset(Result, 0, sizeof(Result));
            fprintf(outputFile, "ELSEScope\n");
            execute(p->opr.op[2], 0, 1);
            fprintf(outputFile, Result);
            memset(Result, 0, sizeof(Result));
            fprintf(outputFile, "ENDIF\n");
            insideScope = 0;
            break;
        case PRINT:
            if (insideScope == 1)
            {
                strcat(Result, "PRINT ");
                execute(p->opr.op[0], 0, 1);
                strcat(Result, "\n ");
            }
            else
            {
                fprintf(outputFile, "PRINT ");
                execute(p->opr.op[0], 0, 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
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
                strcat(Result, "INIT ");
                execute(p->opr.op[1], 0, 1);
            }
            else
            {
                fprintf(outputFile, "INIT ");
                execute(p->opr.op[1], 0, 0);
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
                printf("FUNCTION DELECRATION SEEN\n");
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
            fprintf(outputFile, "\nFUNC_END");
            insideScope = 0;
            break;
        case SWITCH:
            switchLabel++;
            strcat(Result, "SWITCHScope:\n");
            strcat(Result, "Check\t");
            execute(p->opr.op[0], 0, 1);
            strcat(Result, "\n");
            execute(p->opr.op[1], 0, 1);
            fprintf(outputFile, Result);
            execute(p->opr.op[2], 0, 1);
            fprintf(outputFile, Result);
            break;

        case DEFAULT:

            strcat(Result, "DEFAULT: \n");
            execute(p->opr.op[0], 0, 1);
            strcat(Result, "\njmp SWITCH\n");

            break;
        case CASE:

            switch (p->opr.nops)
            {
            case 2:
                strcat(Result, "CASE ");
                execute(p->opr.op[0], 0, 1);
                strcat(Result, ": \n");
                execute(p->opr.op[1], 0, 1);
                strcat(Result, "\njmp Case\n");
                fprintf(outputFile, Result);

                memset(Result, 0, sizeof(Result));

                break;
            case 3:

                execute(p->opr.op[0], 0, 1);
                strcat(Result, "CASE ");
                execute(p->opr.op[1], 0, 1);
                strcat(Result, ": \n");
                execute(p->opr.op[2], 0, 1);
                strcat(Result, "\njmp Case\n");
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));

                break;
            }

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
        case FOR:
            if (insideScope == 1)
            {

                sprintf(Result, "\nL%d :\n", LoopsNames);

                execute(p->opr.op[0], 0, 1);
                strcat(Result, "\n");
                execute(p->opr.op[1], 0, 1);
                strcat(Result, "\n");

                execute(p->opr.op[2], 0, 1);

                execute(p->opr.op[3], 0, 1);
                strcat(Result, "\n");
                LoopsNames++;
                sprintf(Result, "%s jmp\tL%d\n", Result, LoopsNames);

                fprintf(outputFile, "L%d:\n", LoopsNames);

                LoopsNames++;
                sprintf(Result, "%s\n", Result);
            }
            else
            {
                sprintf(Result, "\nL%d :\n", LoopsNames);
                execute(p->opr.op[0], 0, 1);

                execute(p->opr.op[1], 0, 1);

                execute(p->opr.op[2], 0, 1);

                execute(p->opr.op[3], 0, 1);

                fprintf(outputFile, "jmp\tL%d\n", LoopsNames);

                fprintf(outputFile, "L%d:\n", LoopsNames);

                LoopsNames++;
            }
            insideScope = 0;
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
        case AND:
            if (insideScope == 1)
            {
                strcat(Result, "\nAND ");
                execute(p->opr.op[0], 0, 1);
                execute(p->opr.op[1], 0, 1);
            }
            else
            {
                fprintf(outputFile, "\nAND ");
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
        case OR:
            if (insideScope == 1)
            {
                strcat(Result, "\nOR ");
                execute(p->opr.op[0], 0, 1);
                execute(p->opr.op[1], 0, 1);
            }
            else
            {
                fprintf(outputFile, "\nOR ");
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
