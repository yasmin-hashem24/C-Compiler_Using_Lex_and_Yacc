#ifndef ERRORGENERATOR_H
#define ERRORGENERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "../node.h"

void throwError(const char *message, int lineNo, FILE *file);
// Define the function pointer type
typedef bool (*CheckTypeFunc)(const char *type, const char *value);
CheckTypeFunc getCheckFunction(conEnum type);
bool checkTypeInt(const char *type, const char *value);
bool checkTypeFloat(const char *type, const char *value);
bool checkTypeChar(const char *type, const char *value);
bool checkTypeString(const char *type, const char *value);
bool checkTypeBool(const char *type, const char *value);



#endif /* ERRORGENERATOR_H */