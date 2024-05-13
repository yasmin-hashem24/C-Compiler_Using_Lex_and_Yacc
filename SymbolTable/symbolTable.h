#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "SymbolEntry.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
void destroySymbolTable(SymbolTable *table);
void addSymbolEntry(SymbolTable *table, SymbolEntry *entry);
SymbolEntry *getSymbolEntryWithName(SymbolTable *table, const char *name);
void modifySymbolEntry(SymbolTable *table, const char *name, SymbolEntry *entry);
void printSymbolTable(SymbolTable *table);

#endif /* SYMBOLTABLE_H */