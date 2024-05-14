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