#include "SymbolEntry.h"
#include "symbolTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SymbolTable *createSymbolTable(const char *name, SymbolTable *parent) {
    SymbolTable *table = malloc(sizeof(SymbolTable));

    table->name = strdup(name);
    table->parent = parent;
    table->scope = parent == NULL ? 0 : parent->scope + 1;
    table->entries = NULL;
    table->size = 0;
    table->children = NULL;
    table->childCount = 0;

    return table;
}

// void destroySymbolTable(SymbolTable *table) {
//     if (table != NULL) {
//         free(table->name);
//         for (size_t i = 0; i < table->size; i++) {
//             destroySymbolEntry(table->entries[i]);
//         }
//         free(table->entries);
//         for (size_t i = 0; i < table->childCount; i++) {
//             destroySymbolTable(table->children[i]);
//         }
//         free(table->children);
//         free(table);
//     }
// }

void addChildrenToSymbolTable(SymbolTable * table, SymbolTable *child ){
    if(table->childCount==0){
        table->children = malloc(sizeof(SymbolTable *));
        table->children[0] = child;
    }
    else{
        table->children= realloc(table->children, (table->childCount + 1) * sizeof(SymbolEntry *));
        table->children[table->childCount] = child; 
    }
    table->childCount++;
}

void addSymbolEntry(SymbolTable *table, SymbolEntry *entry) {
    if (table->size == 0) {
        table->entries = malloc(sizeof(SymbolEntry *));
        table->entries[0] = entry;
    } else {
        table->entries = realloc(table->entries, (table->size + 1) * sizeof(SymbolEntry *));
        table->entries[table->size] = entry;    
    }
    table->size++;
}

SymbolEntry *getSymbolEntryFomCurrentScope(SymbolTable *table, const char *name) {
    for (size_t i = 0; i < table->size; i++) {
        if (strcmp(table->entries[i]->name, name) == 0) {
            return table->entries[i];
        }
    }
    return NULL;
}

SymbolEntry *getSymbolEntryFromParentScope(SymbolTable *table, const char *name) {
    SymbolTable *parent = table;
    while (parent != NULL) {
        for (size_t i = 0; i < parent->size; i++) {
            if (strcmp(parent->entries[i]->name, name) == 0) {
                return parent->entries[i];
            }
        }
        parent = parent->parent;
    }
    return NULL;
}


//overall entry
void modifySymbolEntry(SymbolTable *table, const char *name, SymbolEntry *entry) {
    for (size_t i = 0; i < table->size; i++) {
        if (strcmp(table->entries[i]->name, name) == 0) {
            table->entries[i] = entry;
            break;
        }
    }
}

const char *symbolKindToString(SymbolKind kind) {
    switch (kind) {
        case VARIABLE_E:
            return "Variable";
        case FUNCTION_E:
            return "Function";
        case ENUM_E:
            return "Enum";
        default:
            return "Unknown";
    }
}

void writeSymbolTableToFile(SymbolTable *table, FILE *file) {
    fprintf(file, "Symbol Table: %s\t\t Scope: %d\n", table->name, table->scope);
    fprintf(file, "-------------------------------------\n");
    fprintf(file, "Name\t\t\t\t\t\tKind\t\t\t\t\t\tVarType\t\t\t\t\t\tInitialized\t\t\t\t\t\tConstant\t\t\t\t\t\tUsed\t\t\t\t\t\tValue\t\t\t\t\t\tagrCount\t\t\t\t\t\tArgumentTypes\t\t\t\t\t\tReturnType\t\t\t\t\t\tEnumCount\t\t\t\t\t\tEnumTypes\n");
    for (size_t i = 0; i < table->size; i++) {
        fprintf(file, "%s\t\t\t\t\t\t%s\t\t\t\t\t\t%s\t\t\t\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t\t%s\t\t\t\t\t\t%d\t\t\t\t\t\t",
                table->entries[i]->name, symbolKindToString(table->entries[i]->kind),
                table->entries[i]->type, table->entries[i]->isInitialized, table->entries[i]->isConstant, table->entries[i]->isUsed, table->entries[i]->value,
                table->entries[i]->argCount);


        // for argtypes:
        if (table->entries[i]->argCount > 0) {
            for (int j = 0; j < table->entries[i]->argCount; j++) {
                fprintf(file, "%s\t\t\t\t\t\t", table->entries[i]->argTypes[j]);
            }
        } else {
            fprintf(file, "-\t\t\t\t\t\t");
        }

        fprintf(file, "%s\t\t\t\t\t\t%d\t\t\t\t\t\t",
                table->entries[i]->returnType,
                table->entries[i]->enumCount);

        // for enumtypes:
        if (table->entries[i]->enumCount > 0) {
            for (int j = 0; j < table->entries[i]->enumCount; j++) {
                fprintf(file, "%s\t\t\t\t\t\t", table->entries[i]->enumTypes[j]);
            }
            fprintf(file, "\n");
        } else {
            fprintf(file, "-\t\t\t\t\t\t");
        }
        fprintf(file, "\n");
    }
    fprintf(file, "-------------------------------------\n\n");
}

void writeAllSymbolTablesToFile(SymbolTable *table, FILE *file) {
    writeSymbolTableToFile(table, file);
    for (size_t i = 0; i < table->childCount; i++) {
        writeAllSymbolTablesToFile(table->children[i], file);
    }
}
