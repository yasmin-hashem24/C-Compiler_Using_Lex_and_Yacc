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
    fprintf(file, "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(file, "%-25s%-25s%-25s%-25s%-25s%-25s%-25s%-25s%-40s%-25s%-25s%-50s\n",
            "Name", "Kind", "VarType", "Initialized", "Constant", "Used", "Value", "agrCount", "ArgumentTypes", "ReturnType", "EnumCount", "EnumTypes");

    for (size_t i = 0; i < table->size; i++) {
        fprintf(file, "%-25s%-25s%-25s%-25d%-25d%-25d%-25s%-25d",
                table->entries[i]->name, symbolKindToString(table->entries[i]->kind),
                table->entries[i]->type, table->entries[i]->isInitialized, table->entries[i]->isConstant,
                table->entries[i]->isUsed, table->entries[i]->value, table->entries[i]->argCount);

        // for argtypes:
        if (table->entries[i]->argCount > 0) {
            // Initialize a buffer to store the concatenated string
            char concatenatedString[41]; // 40 characters + 1 for null terminator
            int currentIndex = 0;

            // Concatenate each element of the argTypes array
            for (int j = 0; j < table->entries[i]->argCount; j++) {
                int charsCopied = snprintf(concatenatedString + currentIndex, sizeof(concatenatedString) - currentIndex, "%s, ", table->entries[i]->argTypes[j]);
                if (charsCopied > 0) {
                    currentIndex += charsCopied;
                }
            }

            // Pad the remaining characters with spaces if needed
            while (currentIndex < 40) {
                concatenatedString[currentIndex++] = ' ';
            }

            // Add null terminator to the concatenated string
            concatenatedString[currentIndex] = '\0';

            fprintf(file, "%s", concatenatedString);
        } else {
            fprintf(file, "%-40s", "-");
        }

        fprintf(file, "%-25s%-25d", table->entries[i]->returnType, table->entries[i]->enumCount);

        // for enumtypes:
        if (table->entries[i]->enumCount > 0) {
            // Initialize a buffer to store the concatenated string
            char concatenatedEnumString[71]; // 70 characters + 1 for null terminator
            int currentIndex = 0;
        
            // Concatenate each element of the enumTypes array
            for (int j = 0; j < table->entries[i]->enumCount; j++) {
                int charsCopied = snprintf(concatenatedEnumString + currentIndex, sizeof(concatenatedEnumString) - currentIndex, "%s, ", table->entries[i]->enumTypes[j]);
                if (charsCopied > 0) {
                    currentIndex += charsCopied;
                }
            }
        
            // Pad the remaining characters with spaces if needed
            while (currentIndex < 70) {
                concatenatedEnumString[currentIndex++] = ' ';
            }
        
            // Add null terminator to the concatenated string
            concatenatedEnumString[currentIndex] = '\0';
        
            fprintf(file, "%s\n", concatenatedEnumString);
        } else {
            fprintf(file, "%-70s\n", "-");
        }
        fprintf(file, "\n");
    }
    fprintf(file, "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}

void writeAllSymbolTablesToFile(SymbolTable *table, FILE *file) {
    writeSymbolTableToFile(table, file);
    for (size_t i = 0; i < table->childCount; i++) {
        writeAllSymbolTablesToFile(table->children[i], file);
    }
}

