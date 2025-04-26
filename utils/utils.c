#include "utils.h"
#include "c_ansi_textstyling.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void die(const char *str, ...) {
    static char buffer[1024];
    va_list args;

    va_start(args, str);
    sprintf(buffer, FG_HI_RED("[ERROR]: %s"), str);

    va_end(args);
    exit(EXIT_FAILURE);
}
