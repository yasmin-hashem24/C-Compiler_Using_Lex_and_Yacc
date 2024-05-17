#include "error.h"

void throwError(const char *message, int lineNo, FILE* file) {
    fprintf(file, "At line %d, Error: %s\n", lineNo, message);
}

CheckTypeFunc getCheckFunction(conEnum type, char **typeEnum) {
  //Note: I changed them to be = conEnumToString function
    switch (type) {
        case typeInt:
            *typeEnum = "Integer";
            return &checkTypeInt;
        case typeFloat:
            *typeEnum = "Float";
            return &checkTypeFloat;
        case typeString:
            *typeEnum = "String";
            return &checkTypeString;
        case typeChar:
            *typeEnum = "Char";
            return &checkTypeChar;
        case typeBool:
            *typeEnum = "Boolean";
            return &checkTypeBool;
        default:
            fprintf(stderr, "Invalid type\n");
            exit(EXIT_FAILURE);
    }
}

bool checkTypeInt(conEnum  typeEnum) {
    return typeEnum == typeInt;
}

bool checkTypeFloat(conEnum    typeEnum) {
    return typeEnum == typeFloat;
}

bool checkTypeChar(conEnum typeEnum) {
    return typeEnum == typeChar;
}

bool checkTypeString(conEnum   typeEnum) {
    return typeEnum == typeString;
}

bool checkTypeBool(conEnum typeEnum) {
    return typeEnum == typeBool;
}

bool checkTypeMismatchConNode(nodeType* node, char* symbolValue, char* typeUnion, CheckTypeFunc checkFunc) {
                                                                          
    if(checkFunc(node->con.typeConst)){
        if(strcmp(typeUnion, "Integer") == 0){
            int integerValue = node->con.iValue;
            sprintf(symbolValue, "%d", integerValue);
        }
        else if(strcmp(typeUnion, "Float") == 0){
            float floatValue = node->con.fValue;
            sprintf(symbolValue, "%f", floatValue);
        }
        else if(strcmp(typeUnion, "Boolean") == 0){
            sprintf(symbolValue, "%s", node->con.iValue ? "true" : "false");
        }
        else if(strcmp(typeUnion, "Char") == 0){
            char charValue = node->con.cValue;
            sprintf(symbolValue, "%c", charValue);
        }
        else if(strcmp(typeUnion, "String") == 0){
            char* stringValue = node->con.sValue;
            sprintf(symbolValue, "%s", stringValue);
        }
        return true;
    }
    return false;
}

SymbolEntry* checkIdNodeDeclaration(SymbolTable *currTable, const char *id) {
    SymbolEntry *idEntry = getSymbolEntryFomCurrentScope(currTable,id);
    if(idEntry==NULL){
        printf("Error: Identifier %s not deaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaclared\n",id);
       idEntry = getSymbolEntryFromParentScope(currTable,id);
    }
    return idEntry;
}