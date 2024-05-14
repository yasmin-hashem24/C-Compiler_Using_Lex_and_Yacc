#include "error.h"

void throwError(const char *message, int lineNo, FILE* file) {
    fprintf(file, "At line %d, Error: %s\n", lineNo, message);
}

CheckTypeFunc getCheckFunction(conEnum type, char **typeEnum) {
    switch (type) {
        case typeInt:
            *typeEnum = "int";
            return &checkTypeInt;
        case typeFloat:
            *typeEnum = "float";
            return &checkTypeFloat;
        case typeString:
            *typeEnum = "string";
            return &checkTypeString;
        case typeChar:
            *typeEnum = "char";
            return &checkTypeChar;
        case typeBool:
            *typeEnum = "bool";
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