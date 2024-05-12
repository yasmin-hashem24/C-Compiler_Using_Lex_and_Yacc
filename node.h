#pragma once
#include <stdbool.h>
#include <string.h>
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
// Function to determine the type of a node

nodeType *createTypeNode(conEnum type);
nodeType *createConstantNode();
nodeType *createIntConstantNode(int value);
nodeType *createFloatConstantNode(float value);
nodeType *createBoolConstantNode(bool value);
nodeType *createCharConstantNode(char value);
nodeType *createStringConstantNode(char *value);
nodeType *createIdentifierNode(char *id);
nodeType *createOperatorNode(int oper, int nops, ...);
conEnum getTypeOfEnum(const nodeType *node);

void freeNode(nodeType *p);

extern int sym[26]; // Declaration for external array
