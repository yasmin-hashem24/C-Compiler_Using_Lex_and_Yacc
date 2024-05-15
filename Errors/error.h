#ifndef ERRORGENERATOR_H
#define ERRORGENERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "../node.h"
#include "../SymbolTable/symbolTable.h"

void throwError(const char *message, int lineNo, FILE *file);
// Define the function pointer type
typedef bool (*CheckTypeFunc)(conEnum type);
CheckTypeFunc getCheckFunction(conEnum type, char **typeEnum);
bool checkTypeInt(conEnum type);
bool checkTypeFloat(conEnum type);
bool checkTypeChar(conEnum type);
bool checkTypeString(conEnum type);
bool checkTypeBool(conEnum type);

bool checkTypeMismatchConNode(nodeType* node, char* symbolValue, char* typeUnion, CheckTypeFunc checkFunc);

SymbolEntry* checkIdNodeDeclaration(SymbolTable *currTable, const char *id);

#endif /* ERRORGENERATOR_H */