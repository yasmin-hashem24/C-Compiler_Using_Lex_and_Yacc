#include "SymbolEntry.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SymbolEntry *create_variable_SymbolEntry(const char *name, const char *type, int isInitialized, int isConstant, int isUsed, char* value, int lineNo) {
    SymbolEntry *entry = malloc(sizeof(SymbolEntry));

    entry->name = strdup(name);
    entry->kind = VARIABLE_E;
    entry->type = strdup(type);
    entry->isInitialized = isInitialized;
    entry->isConstant = isConstant;
    entry->isUsed = isUsed;
    entry->value = (value == NULL) ? NULL : strdup(value);

    entry->isFunction = 0; // Not a function
    entry->argCount = -1;  // Not applicable
    entry->returnType = NULL; // Not applicable
    entry->argTypes = NULL; // Not applicable
    entry->isEnum = 0;     // Not an enum
    entry->enumCount = -1; // Not applicable
    entry->enumTypesString = NULL; // Not applicable
    entry->enumTypesInt= NULL; //Not applicable
    entry->lineNo = lineNo;

    return entry;
}

SymbolEntry *create_function_SymbolEntry(const char *name, int isUsed, int isInitialized, int lineNo, int argCount, char **argTypes, char *returnType) {
    printf("argCountaaaaaaaaaaaaaaaaa: %d\n", argCount);
    
    SymbolEntry *entry = malloc(sizeof(SymbolEntry));
    printf("argCountaaaaaaaaaaaaaaaaa: %d\n", argCount);

    entry->name = strdup(name);
    entry->kind = FUNCTION_E;
    entry->type = strdup(returnType);
    entry->isUsed = isUsed;
    entry->isInitialized = isInitialized;
    entry->isConstant = -1;   // Not applicable
    entry->value = NULL;      // Not applicable
    entry->isFunction = 1;    // Is a function
    printf("argCountaaaaaaaaaaaaaaaaa: %d\n", argCount);
    entry->argCount = argCount;
    entry->argTypes = malloc(argCount * sizeof(char *));
    for (int i = 0; i < argCount; i++) {
        entry->argTypes[i] = strdup(argTypes[i]);
    }
    entry->returnType = strdup(returnType);
    entry->isEnum = 0;         // Not an enum
    entry->enumCount = -1;     // Not applicable
    entry->enumTypesString = NULL;   // Not applicable
    entry->enumTypesInt=NULL; //Not applicable
    entry->lineNo = lineNo;

    return entry;
}

// SymbolEntry *create_enum_SymbolEntry(const char *name, int isUsed, int isInitialized, int lineNo, int enumCount, char **enumTypes) {
//     SymbolEntry *entry = malloc(sizeof(SymbolEntry));

//     entry->name = strdup(name);
//     entry->kind = ENUM_E;
//     entry->isUsed = isUsed;
//     entry->isInitialized = isInitialized; 
//     entry->isConstant = -1;    // Not applicable
//     entry->value = NULL;       // Not applicable
//     entry->isFunction = 0;     // Not a function
//     entry->argCount = -1;      // Not applicable
//     entry->argTypes = NULL;    // Not applicable
//     entry->returnType = NULL; // Not applicable
//     entry->isEnum = 1;         // Is an enum
//     entry->enumCount = enumCount;
//     entry->enumTypes = malloc(enumCount * sizeof(char *));
//     for (int i = 0; i < enumCount; i++) {
//         entry->enumTypes[i] = strdup(enumTypes[i]);
//     }
//     entry->lineNo = lineNo;

//     return entry;
// }

SymbolEntry *create_enum_SymbolEntry(const char *name, int isUsed, int isInitialized, int lineNo, int enumCount, char **enumTypesString,int *enumTypesInt) {
    SymbolEntry *entry = malloc(sizeof(SymbolEntry));

    entry->name = strdup(name);
    entry->kind = ENUM_E;
    entry->isUsed = isUsed;
    entry->isInitialized = isInitialized; 
    entry->isConstant = -1;    // Not applicable
    entry->value = NULL;       // Not applicable
    entry->isFunction = 0;     // Not a function
    entry->argCount = -1;      // Not applicable
    entry->argTypes = NULL;    // Not applicable
    entry->returnType = NULL; // Not applicable
    entry->isEnum = 1;         // Is an enum
    entry->enumCount = enumCount;
    entry->enumTypesString = malloc(enumCount * sizeof(char *));
    entry->enumTypesInt = malloc(enumCount * sizeof(int));
    for (int i = 0; i < enumCount; i++) {
        entry->enumTypesString[i] = strdup(enumTypesString[i]);
        entry->enumTypesInt[i]=enumTypesInt[i];
    }
    entry->lineNo = lineNo;

    return entry;
}

char *getName(SymbolEntry *entry) {
    return entry->name;
}

SymbolKind getKind(SymbolEntry *entry) {
    return entry->kind;
}

char *getType(SymbolEntry *entry) {
    return entry->type;
}

int getIsInitialized(SymbolEntry *entry) {
    return entry->isInitialized;
}

int getIsConstant(SymbolEntry *entry) {
    return entry->isConstant;
}

int getIsUsed(SymbolEntry *entry) {
    return entry->isUsed;
}

int getIsVariable(SymbolEntry *entry) {
    return entry->isVariable;
}

char * getValue(SymbolEntry *entry) {
    return entry->value;
}

int getIsEnum(SymbolEntry *entry) {
    return entry->isEnum;
}

int getEnumCount(SymbolEntry *entry) {
    return entry->enumCount;
}

char **getEnumTypesString(SymbolEntry *entry) {
    return entry->enumTypesString;
}

int *getEnumTypesInts(SymbolEntry *entry) {
    return entry->enumTypesInt;
}

int getIsFunction(SymbolEntry *entry) {
    return entry->isFunction;
}

int getArgCount(SymbolEntry *entry) {
    return entry->argCount;
}

char **getArgTypes(SymbolEntry *entry) {
    return entry->argTypes;
}

int getLineNo(SymbolEntry *entry) {
    return entry->lineNo;
}

void setName(SymbolEntry *entry, const char *name) {
    free(entry->name);
    entry->name = strdup(name);
}

void setKind(SymbolEntry *entry, SymbolKind kind) {
    entry->kind = kind;
}

void setType(SymbolEntry *entry, const char *type) {
    free(entry->type);
    entry->type = strdup(type);
}

void setIsInitialized(SymbolEntry *entry, int isInitialized) {
    entry->isInitialized = isInitialized;
}

void setIsConstant(SymbolEntry *entry, int isConstant) {
    entry->isConstant = isConstant;
}

void setIsUsed(SymbolEntry *entry, int isUsed) {
    entry->isUsed = isUsed;
}

void setIsVariable(SymbolEntry *entry, int isVariable) {
    entry->isVariable = isVariable;
}

void setValue(SymbolEntry *entry, const char *value) {
    free(entry->value);
    entry->value = strdup(value);
}

void setIsEnum(SymbolEntry *entry, int isEnum) {
    entry->isEnum = isEnum;
}

void setEnumCount(SymbolEntry *entry, int enumCount) {
    entry->enumCount = enumCount;
}

void setEnumTypes(SymbolEntry *entry, char **enumTypesString, int* enumTypesInt) {
    for (int i = 0; i < entry->enumCount; i++) {
        free(entry->enumTypesString[i]);
    }
    free(entry->enumTypesString);
    free(entry->enumTypesInt);
    entry->enumTypesString = malloc(entry->enumCount * sizeof(char *));
    entry->enumTypesInt = malloc(entry->enumCount * sizeof(int));
    for (int i = 0; i < entry->enumCount; i++) {
        entry->enumTypesString[i] = strdup(enumTypesString[i]);
        entry->enumTypesInt[i] = enumTypesInt[i];
    }
}

void setIsFunction(SymbolEntry *entry, int isFunction) {
    entry->isFunction = isFunction;
}

void setArgCount(SymbolEntry *entry, int argCount) {
    entry->argCount = argCount;
}

void setArgTypes(SymbolEntry *entry, char **argTypes) {
    for (int i = 0; i < entry->argCount; i++) {
        free(entry->argTypes[i]);
    }
    free(entry->argTypes);
    entry->argTypes = malloc(entry->argCount * sizeof(char *));
    for (int i = 0; i < entry->argCount; i++) {
        entry->argTypes[i] = strdup(argTypes[i]);
    }
}

void setLineNo(SymbolEntry *entry, int lineNo) {
    entry->lineNo = lineNo;
}

void destroy_SymbolEntry(SymbolEntry *entry) {
    if (entry != NULL) {
        free(entry->name);
        free(entry->type);
        for (int i = 0; i < entry->argCount; i++) {
            free(entry->argTypes[i]);
        }
        free(entry->argTypes);

        if (entry->isEnum) {
            for (int i = 0; i < entry->enumCount; i++) {
                free(entry->enumTypesString[i]);
            }
            free(entry->enumTypesString);
            free(entry->enumTypesInt);
        }

        free(entry);
    }
}
