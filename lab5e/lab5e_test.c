#include "lab5e_test.h"
#include "../string/tasks/string_.h"
#include "../lab5e/tasks.h"
#include <stdio.h>

#define ASSERT_STRING(expected, got) assert_string(expected, got, \
                                __FILE__, __FUNCTION__, __LINE__)

static void assert_string(const char* expected, const char* got,
                          const char* fileName, const char* funcName,
                          const int line) {
    if (strcmp(expected, got) != 0) {
        fprintf(stderr, "File: %s\n", fileName);
        fprintf(stderr, "%s - failed on line: %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got:      \"%s\"\n", got);
    } else
        fprintf(stderr, "%s - OK!\n", funcName);
}

static void test_removeNonLetters_commonCase() {
    char str[] = "qwe rty 112 ";

    removeNonLetters(str);

    char res[] = "qwerty112";

    ASSERT_STRING(res, str);
}

void lab5e_test() {
    test_removeNonLetters_commonCase();
}