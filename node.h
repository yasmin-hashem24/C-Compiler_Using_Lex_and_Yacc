#pragma once
#include <stdbool.h>

// Enumeration for the type of nodes: constants, identifiers, operations, and data types
typedef enum
{
    typeCon,
    typeId,
    typeOpr,
    typeDef
} nodeEnum;

// Enumeration for constant types: int, float, string, char, bool, constant, non-defined, and void
typedef enum
{
    typeInt,
    typeFloat,
    typeString,
    typeChar,
    typeBool,
    typeConst,
    typeND,
    typeVoid,
    typeVar,
} conEnum;

/* Constants */
struct conNodeType
{
    conEnum type; // Type of the constant value

    // Constant values
    union
    {
        int iValue;
        float fValue;
        char *sValue;
        char cValue;
    };
};

/* Identifiers */
struct idNodeType
{
    char *id; // Pointer to the identifiers table
};

/* Operators */
struct oprNodeType
{
    int oper;                  // Operator
    int nops;                  // Number of operands
    struct nodeTypeTag *op[1]; // Operands, extended at runtime
};

/* Types */
struct typeNodeType
{
    conEnum type; // Type of the node
};

// Node structure with a union for different node types
typedef struct nodeTypeTag
{
    nodeEnum type; // Type of node

    union
    {
        struct conNodeType con;  // Constants
        struct idNodeType id;    // Identifiers
        struct oprNodeType opr;  // Operators
        struct typeNodeType typ; // Types
    };
} nodeType;

// Function to get the conEnum from the type
conEnum getTypeEnum(char *type)
{
    if (strcmp(type, "typeInt") == 0)
    {
        return typeInt;
    }
    else if (strcmp(type, "typeFloat") == 0)
    {
        return typeFloat;
    }
    else if (strcmp(type, "typeString") == 0)
    {
        return typeString;
    }
    else if (strcmp(type, "typeChar") == 0)
    {
        return typeChar;
    }
    else if (strcmp(type, "typeBool") == 0)
    {
        return typeBool;
    }
    else if (strcmp(type, "typeVar") == 0)
    {
        return typeVar;
    }
    else
    {
        return typeND; // If type not found, return non-defined
    }
}

extern int sym[26]; // Declaration for external array
