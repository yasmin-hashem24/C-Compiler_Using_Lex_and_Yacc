
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

void execute(nodeType *p, int first)
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
            sprintf(Result, "L%s%d :\n", Result, LoopsNames);
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, Result);

            printf("Result: %s\n", Result);
            fprintf(outputFile, Result);
            memset(Result, 0, sizeof(Result));
            fprintf(outputFile, "\tjz\tL%d\n", LoopsNames);

            LoopsNames++;

            fprintf(outputFile, "\tjmp\tL%d\n", LoopsNames);
            fprintf(outputFile, "L%d:\n", LoopsNames);

            LoopsNames += 1;
            break;

        case IF:
            fprintf(outputFile, "if(");
            execute(p->opr.op[0], 0);
            fprintf(outputFile, ") ");
            execute(p->opr.op[1], 0);
            if (p->opr.nops > 2)
            {
                fprintf(outputFile, " else ");
                execute(p->opr.op[2], 0);
            }
            break;
        case PRINT:
            fprintf(outputFile, "print ");
            execute(p->opr.op[0], 0);
            fprintf(outputFile, "\n");
            break;
        case ENUM:
            switch (p->opr.nops)
            {
            case 1:
                strcat(Result, "EnumDef ");
                execute(p->opr.op[0], 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result)); // Clear Result after printing
                break;
            case 2:
                strcat(Result, "EnumDef ");
                execute(p->opr.op[0], 0);
                execute(p->opr.op[1], 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                break;
            case 3:
                strcat(Result, "EnumDef ");
                execute(p->opr.op[0], 0);
                execute(p->opr.op[1], 0);
                execute(p->opr.op[2], 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                break;
            default:
                break;
            }
            break;
        case VAR:
            fprintf(outputFile, "INIT  ");
            execute(p->opr.op[1], 0);
            fprintf(outputFile, Result);
            memset(Result, 0, sizeof(Result));
            break;
        case CONST:
            fprintf(outputFile, "CONST ");
            execute(p->opr.op[1], 0);
            execute(p->opr.op[2], 0);
            fprintf(outputFile, Result);
            memset(Result, 0, sizeof(Result));
            break;
        case FUNC:
            switch (p->opr.nops)
            {
            case 5:

                execute(p->opr.op[1], 0);
                strcat(Result, ":");
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));

                execute(p->opr.op[3], 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));

                break;
            case 4:
                execute(p->opr.op[1], 0);
                strcat(Result, ":");
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                execute(p->opr.op[2], 0);
                execute(p->opr.op[3], 0);
                fprintf(outputFile, Result);

                break;

            default:
                break;
            }
            fprintf(outputFile, "END OF FUNCTION");
            break;
        case SWITCH:
            fprintf(outputFile, "switch ");
            execute(p->opr.op[0], 0);
            break;
        case DEFAULT:
            fprintf(outputFile, "default ");
            execute(p->opr.op[0], 0);
            break;
        case CASE:
            fprintf(outputFile, "case ");
            execute(p->opr.op[0], 0);
            break;
        case CALL:
            strcat(Result, "CALL ");
            execute(p->opr.op[0], 0);
            fprintf(outputFile, Result);
            memset(Result, 0, sizeof(Result));
        case '=':
            switch (p->opr.nops)
            {
            case 2:
                strcat(Result, "ASSIGN ");
                execute(p->opr.op[0], 0);
                execute(p->opr.op[1], 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                break;
            case 3:
                strcat(Result, "ASSIGN ");
                execute(p->opr.op[0], 0);
                execute(p->opr.op[1], 0);
                execute(p->opr.op[2], 0);
                fprintf(outputFile, Result);
                memset(Result, 0, sizeof(Result));
                break;
            default:
                break;
            }

            break;
        case '+':
            strcat(Result, "ADD ");
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, Result);
            memset(Result, 0, sizeof(Result));
            break;
        case '-':
            strcat(Result, "SUB ");
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, Result);
            memset(Result, 0, sizeof(Result));
            break;
        case '*':
            strcat(Result, "MUL ");
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, Result);
            memset(Result, 0, sizeof(Result));
            break;
        case '/':
            strcat(Result, "DIV ");
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, Result);
            memset(Result, 0, sizeof(Result));
            break;
        case ';':
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            break;
        case ',':
            switch (p->opr.nops)
            {
            case 2:
                execute(p->opr.op[0], 0);
                execute(p->opr.op[1], 0);
                break;
            case 3:
                execute(p->opr.op[0], 0);
                execute(p->opr.op[1], 0);
                execute(p->opr.op[2], 0);
                break;
            default:
                break;
            }
        case '!':
            strcat(Result, "NOT ");
            execute(p->opr.op[0], 0);
            fprintf(outputFile, Result);
            memset(Result, 0, sizeof(Result));
            break;

        case LT:
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, "LessTn\n");
            break;

        case GT:
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, "GrTn \n");
            break;

        case LTE:
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, "LessTnE \n");
            break;

        case GTE:
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, "GrTnE \n");
            break;

        case NEQ:
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, "IsNEQ \n");
            break;

        case EQ:
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, "IsEQ %s\n");

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