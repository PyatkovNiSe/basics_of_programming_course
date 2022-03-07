#include "tasks.h"
#include "../string/tasks/string_.h"
#include <ctype.h>

void removeNonLetters(char *s) {
    char *endSrc = getEndOfString(s);
    char *dest = copyIf(s, endSrc, s, (bool (*)(int)) isgraph);
    *dest = '\0';
}

void removeAdjacentEqualLetters(char *s) {
    if (!(*s))
        return;

    char *previous = s;
    while (*s) {
        if (*previous != *s)
            *(++previous) = *s;
        s++;
    }
    *(++previous) = '\0';
}