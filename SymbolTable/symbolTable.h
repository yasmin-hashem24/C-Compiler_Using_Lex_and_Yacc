#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "SymbolEntry.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable : 4996)


// Forward declaration of SymbolTable
typedef struct SymbolTable SymbolTable;

struct SymbolTable {
    char *name; // name of the symbol table eg. global, function name
    int scope;
    //struct 
    SymbolTable *parent;
    //struct 
    SymbolEntry **entries;
    size_t size;
    //struct 
    SymbolTable **children;
    size_t childCount;
};


SymbolTable *createSymbolTable(const char *name, SymbolTable *parent);
// void destroySymbolTable(SymbolTable *table);
void addSymbolEntry(SymbolTable *table, SymbolEntry *entry);
// SymbolEntry *getSymbolEntryWithName(SymbolTable *table, const char *name);
SymbolEntry *getSymbolEntryFomCurrentScope(SymbolTable *table, const char *name) ;
SymbolEntry *getSymbolEntryFromParentScope(SymbolTable *table, const char *name);
const char *symbolKindToString(SymbolKind kind);
void addChildrenToSymbolTable(SymbolTable * table, SymbolTable *child );
void modifySymbolEntry(SymbolTable *table, const char *name, SymbolEntry *entry);
void writeSymbolTableToFile(SymbolTable *table, FILE *file);
void writeAllSymbolTablesToFile(SymbolTable *table, FILE *file);
void diplayWarningTable(SymbolTable *table, FILE *file);
void displayWarningAllTables(SymbolTable *table, FILE *file);

#endif /* SYMBOLTABLE_H */