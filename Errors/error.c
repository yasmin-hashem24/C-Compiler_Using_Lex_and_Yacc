#include "error.h"

void throwError(const char *message, int lineNo, FILE* file) {
    fprintf(file, "At line %d, Error: %s\n", lineNo, message);
}