
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
    p->type = typeDef; // Change to typeDef for a type node
    p->typ.type = type;
    return p;
}

nodeType *createConstantNode()
{
    nodeType *p;

    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("Memory allocation failed");

    /* Set the node type */
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
    p->con.typeConst = typeFloat; // Set the constant type
    p->con.fValue = value;
    return p;
}

nodeType *createBoolConstantNode(bool value)
{
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.typeConst = typeBool; // Set the constant type
    p->con.iValue = value;
    return p;
}

nodeType *createCharConstantNode(char value)
{
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.typeConst = typeChar; // Set the constant type
    p->con.cValue = value;
    return p;
}

nodeType *createStringConstantNode(char *value)
{
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.typeConst = typeString; // Set the constant type
    p->con.sValue = strdup(value); // Duplicate the string
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

conEnum getTypeOfEnum(const nodeType *node)
{
    // Assuming that the identifier is stored in the node and it's a string
    const char *identifier = NULL;

    // Determine the identifier based on the node's content
    switch (node->type)
    {
    case typeId:
        identifier = node->id.id;
        break;
    default:

        break;
    }

    // Return the type based on the identifier
    if (identifier != NULL)
    {
        if (strcmp(identifier, "int") == 0)
        {
            return typeInt;
        }
        else if (strcmp(identifier, "float") == 0)
        {
            return typeFloat;
        }
        else if (strcmp(identifier, "string") == 0)
        {
            return typeString;
        }
        else if (strcmp(identifier, "char") == 0)
        {
            return typeChar;
        }
        else if (strcmp(identifier, "bool") == 0)
        {
            return typeBool;
        }
    }

    // Handle unknown types
    return typeND;
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
    case typeDef:
        switch (p->typ.type)
        {

        case typeInt:
            fprintf(outputFile, "int");
            break;
        case typeFloat:
            fprintf(outputFile, "float");
            break;
        case typeString:
            fprintf(outputFile, "string");
            break;
        case typeChar:
            fprintf(outputFile, "TYPEDEFchar");
            break;
        case typeBool:
            fprintf(outputFile, "bool");
            break;
        case typeConst:
            fprintf(outputFile, "const");
            break;
        case typeND:
            fprintf(outputFile, "unknown");
            break;
        case typeVoid:
            fprintf(outputFile, "void");
            break;
        case typeVar:
            fprintf(outputFile, "var");
            break;
        default:
            fprintf(outputFile, "error: unknown type\n");
            break;
        }
        fprintf(outputFile, "\n");
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
            fprintf(outputFile, "L%d ", LoopsNames);
            fprintf(outputFile, ":/n");                  // Quadruple description: Jmp L
            LoopsNames++;                                // Increment loop counter
            execute(p->opr.op[0], 0);                    // Execute the condition part of the while loop
            fprintf(outputFile, Result);                 // Print the result of the condition check (e.g., JE, JNE)
            memset(Result, 0, sizeof(Result));           // Clear Result for further use
            execute(p->opr.op[1], 0);                    // Execute the body of the while loop
            fprintf(outputFile, Result);                 // Print the result of the loop body
            memset(Result, 0, sizeof(Result));           // Clear Result for further use
            fprintf(outputFile, "JNZ L%d ", LoopsNames); // Quadruple description: JNZ LABEL
            fprintf(outputFile, "L%d ", LoopsNames);     // Quadruple description: END LABEL
            LoopsNames++;                                // Increment loop counter
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
            fprintf(outputFile, "LessTn %s\n", Result);
            break;

        case GT:
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, "GrTn %s\n", Result);
            break;

        case LTE:
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, "LessTnE %s\n", Result);
            break;

        case GTE:
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, "GrTnE %s\n", Result);
            break;

        case NEQ:
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, "IsNEQ %s\n", Result);
            break;

        case EQ:
            execute(p->opr.op[0], 0);
            execute(p->opr.op[1], 0);
            fprintf(outputFile, "IsEQ %s\n", Result);

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
