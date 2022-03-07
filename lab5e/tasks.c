#include "tasks.h"
#include "../string/tasks/string_.h"
#include <ctype.h>

void removeNonLetters(char *s) {
    char *endSrc = getEndOfString(s);
    char *dest = copyIf(s, endSrc, s, (bool (*)(int)) isgraph);
    *dest = '\0';
}