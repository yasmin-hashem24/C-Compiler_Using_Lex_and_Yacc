#ifndef ERRORGENERATOR_H
#define ERRORGENERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void throwError(const char *message, int lineNo, FILE *file);

#endif /* ERRORGENERATOR_H */