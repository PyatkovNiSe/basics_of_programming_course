#include "tasks.h"
#include "../string/tasks/string_.h"
#include <ctype.h>

static bool alwaysTrue(int ch) {
    return true;
}

static void reverseWord(WordDescriptor word) {
    char *endBuffer = copyIfReverse(word.end - 1,
                                    word.begin - 1,
                                    _stringBuffer,
                                    alwaysTrue);
    copy(_stringBuffer, endBuffer, word.begin);
}

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

void removeExtraSpaces(char *s) {
    if (!(*s))
        return;

    char *writePos = s;
    s++;
    while (*s) {
        if (isspace(*writePos) && isspace(*s))
            *writePos = ' ';
        else
            *(++writePos) = *s;
        s++;
    }
    *(++writePos) = '\0';
}

void reverseWordsInString(char *s) {
    char *beginSearch = findNonSpace(s);
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        reverseWord(word);
        beginSearch = word.end;
    }
}