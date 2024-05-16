#ifndef SymbolEntry_H
#define SymbolEntry_H


// name (Identifier name)
// Kind (is it function/variable/enum ?)
// isUsed (to check if the variable, function or enum is used or not)
// isInitialized (1/0 for variables, function and enum(in function call for example we need to make sure that the function has been defined), same for enum)
// value (value of the variable, not applicable for function and enum)

// Extra parameters for variables
// isVariable
// type ( variable type, not applicable for function and enum)
// isConstant (1/0 for variables, -1(not applicable for function and enum)

// Extra parameters for functions
// isFunction
// argCount (number of arguments for function, -1(not applicable for variable and enum)
// argTypes (types of arguments for function, -1(not applicable for variable and enum)
// returnType (return type of function, not applicable for variable and enum)

// Extra parameters for enums
// isEnum 
// enumCount (number of enums, -1(not applicable for variable and function)
// enumTypes (types of enums, -1(not applicable for variable and function)

// lineNo (line number where the variable, function or enum is declared)


typedef enum {
    VARIABLE_E,
    FUNCTION_E,
    ENUM_E
} SymbolKind;

typedef struct {
    char *name;
    SymbolKind kind;
    int isUsed;
    int isInitialized;

    int isVariable;
    char *type;             // type of var
    int isConstant;
    char *value;

    int isFunction;
    int argCount;
    char **argTypes; 
    char *returnType; 

    int isEnum;
    int enumCount;
    char **enumTypesString;
    int *enumTypesInt;
         
    int lineNo;  
} SymbolEntry;


SymbolEntry *create_variable_SymbolEntry(const char *name, const char *type, int isInitialized, int isConstant, int isUsed, char* value, int lineNo);
SymbolEntry *create_function_SymbolEntry(const char *name, int isUsed, int isInitialized, int lineNo, int argCount, char **argTypes, char *returnType);
SymbolEntry *create_enum_SymbolEntry(const char *name, int isUsed, int isInitialized, int lineNo, int enumCount, char **enumTypesString, int *enumTypesInt);   //changed this
char *getName(SymbolEntry *entry);
SymbolKind getKind(SymbolEntry *entry);
char *getType(SymbolEntry *entry);
int getIsInitialized(SymbolEntry *entry);
int getIsConstant(SymbolEntry *entry);
int getIsUsed(SymbolEntry *entry);
int getIsVariable(SymbolEntry *entry);
char *getValue(SymbolEntry *entry);
int getIsEnum(SymbolEntry *entry);
int getEnumCount(SymbolEntry *entry);
char **getEnumTypesString(SymbolEntry *entry);
int *getEnumTypesInt(SymbolEntry *entry);
int getIsFunction(SymbolEntry *entry);
int getArgCount(SymbolEntry *entry);
char **getArgTypes(SymbolEntry *entry);
int getLineNo(SymbolEntry *entry);
void setName(SymbolEntry *entry, const char *name);
void setKind(SymbolEntry *entry, SymbolKind kind);
void setType(SymbolEntry *entry, const char *type);
void setIsInitialized(SymbolEntry *entry, int isInitialized);
void setIsConstant(SymbolEntry *entry, int isConstant);
void setIsUsed(SymbolEntry *entry, int isUsed);
void setIsVariable(SymbolEntry *entry, int isVariable);
void setValue(SymbolEntry *entry, const char *value);
void setIsEnum(SymbolEntry *entry, int isEnum);
void setEnumCount(SymbolEntry *entry, int enumCount);
void setEnumTypes(SymbolEntry *entry, char **enumTypesString, int *enumTypesInt);
void setIsFunction(SymbolEntry *entry, int isFunction);
void setArgCount(SymbolEntry *entry, int argCount);
void setArgTypes(SymbolEntry *entry, char **argTypes);
void setLineNo(SymbolEntry *entry, int lineNo);
void destroy_SymbolEntry(SymbolEntry *entry);

#endif /* SymbolEntry_H */
