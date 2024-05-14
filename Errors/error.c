#include "error.h"

void throwError(const char *message, int lineNo, FILE* file) {
    fprintf(file, "At line %d, Error: %s\n", lineNo, message);
}

CheckTypeFunc getCheckFunction(conEnum type) {
    switch (type) {
        case typeInt:
            return &checkTypeInt;
        case typeFloat:
            return &checkTypeFloat;
        case typeString:
            return &checkTypeString;
        case typeChar:
            return &checkTypeChar;
        case typeBool:
            return &checkTypeBool;
        default:
            fprintf(stderr, "Invalid type\n");
            exit(EXIT_FAILURE);
    }
}

bool checkTypeInt(const char *value) {
    return 0;
}

bool checkTypeFloat(const char *value) {
    return 0;
}

bool checkTypeChar(const char *value) {
    return 0;
}

bool checkTypeString(const char *value) {
    return 0;
}

bool checkTypeBool(const char *value) {
    return 0;
}