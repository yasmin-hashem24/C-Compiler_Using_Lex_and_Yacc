
#include "node.h"
#include "y.tab.h"
#include <stdio.h>
#include "node.h"

void yyerror(const char *s);
nodeType *createTypeNode(conEnum type)
{
    nodeType *p = malloc(sizeof(nodeType));
    if (p == NULL)
    {
        yyerror("Memory allocation failed");
        return NULL;
    }
    p->type = typeDef; // Change to typeDef for a type node
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
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.type = typeInt; // Set the constant type
    p->con.iValue = value;
    return p;
}

nodeType *createFloatConstantNode(float value)
{
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.type = typeFloat; // Set the constant type
    p->con.fValue = value;
    return p;
}

nodeType *createBoolConstantNode(bool value)
{
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.type = typeBool; // Set the constant type
    p->con.iValue = value;
    return p;
}

nodeType *createCharConstantNode(char value)
{
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.type = typeChar; // Set the constant type
    p->con.cValue = value;
    return p;
}

nodeType *createStringConstantNode(char *value)
{
    nodeType *p = createConstantNode();

    p->type = typeCon;
    p->con.type = typeString;      // Set the constant type
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
    printf("createOperatorNode where oper = %d\n", oper);
    printf("nops = %d\n", nops);
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

void execute(nodeType *p)
{
    FILE *outputFile = fopen("QuadrapletsFile", "w");
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
        switch (p->type)
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
            fprintf(outputFile, "char");
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
        break;
    case typeCon:
        switch (p->con.type)
        {
        case typeInt:
            fprintf(outputFile, "%d", p->con.iValue);
            break;
        case typeFloat:
            fprintf(outputFile, "%f", p->con.fValue);
            break;
        case typeString:
            fprintf(outputFile, "%s", p->con.sValue);
            break;
        case typeChar:
            fprintf(outputFile, "%c", p->con.cValue);
            break;
        case typeBool:
            fprintf(outputFile, "%s", p->con.iValue ? "true" : "false");
            break;
        default:
            fprintf(outputFile, "error: unknown constant type\n");
            break;
        }
        break;
    case typeId:
        fprintf(outputFile, "%s", p->id.id);
        break;
    case typeOpr:
        switch (p->opr.oper)
        {
        case WHILE:
            fprintf(outputFile, "while(");
            execute(p->opr.op[0]);
            fprintf(outputFile, ") ");
            execute(p->opr.op[1]);
            break;
        case IF:
            fprintf(outputFile, "if(");
            execute(p->opr.op[0]);
            fprintf(outputFile, ") ");
            execute(p->opr.op[1]);
            if (p->opr.nops > 2)
            {
                fprintf(outputFile, " else ");
                execute(p->opr.op[2]);
            }
            break;
        case PRINT:
            fprintf(outputFile, "print ");
            execute(p->opr.op[0]);
            break;
        case ENUM:
            fprintf(outputFile, "enum ");
            execute(p->opr.op[0]);
            break;
        case '=':
            execute(p->opr.op[0]);
            fprintf(outputFile, " = ");
            execute(p->opr.op[1]);
            break;
        case '+':
            execute(p->opr.op[0]);
            fprintf(outputFile, " + ");
            execute(p->opr.op[1]);
            break;
        case '-':
            execute(p->opr.op[0]);
            fprintf(outputFile, " - ");
            execute(p->opr.op[1]);
            break;
        case '*':
            execute(p->opr.op[0]);
            fprintf(outputFile, " * ");
            execute(p->opr.op[1]);
            break;
        case '/':
            execute(p->opr.op[0]);
            fprintf(outputFile, " / ");
            execute(p->opr.op[1]);
            break;
        case LT:
            execute(p->opr.op[0]);
            fprintf(outputFile, " < ");
            execute(p->opr.op[1]);
            break;
        case GT:
            execute(p->opr.op[0]);
            fprintf(outputFile, " > ");
            execute(p->opr.op[1]);
            break;
        case GTE:
            execute(p->opr.op[0]);
            fprintf(outputFile, " >= ");
            execute(p->opr.op[1]);
            break;
        case LTE:
            execute(p->opr.op[0]);
            fprintf(outputFile, " <= ");
            execute(p->opr.op[1]);
            break;
        case NEQ:
            execute(p->opr.op[0]);
            fprintf(outputFile, " != ");
            execute(p->opr.op[1]);
            break;
        case EQ:
            execute(p->opr.op[0]);
            fprintf(outputFile, " == ");
            execute(p->opr.op[1]);
            break;
        case VAR:
            fprintf(outputFile, "var ");
            execute(p->opr.op[0]);
            break;
        default:
            fprintf(outputFile, "error: unknown operator '%d'\n");
  
            break;
        }
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
        if (p->con.type == typeString)
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