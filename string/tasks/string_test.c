#include "string_test.h"
#include "string_.h"
#include <assert.h>

static bool isDigit(int x) {
    return x >= '0' && x <= '9';
}

static bool isNotDigit(int x) {
    return !isDigit(x);
}

void test_strlen_commonCase() {
    char str[] = "1234";

    int assumedResult = 4;
    int result = strlen(str);

    assert(assumedResult == result);
}

void test_find_commonCase() {
    char str[] = "qwerty211";

    char *assumedResult = str + 4;
    char *result = find(str, str + 9, 't');

    assert(assumedResult == result);
}

void test_find_elementNotFound() {
    char str[] = "sqwerty45";

    char *assumedResult = str + 9;
    char *result = find(str, str + 9, 'b');

    assert(assumedResult == result);
}

void test_findNonSpace_commonCase() {
    char str[] = "  qwertty65";

    char *assumedResult = str + 2;
    char *result = findNonSpace(str);

    assert(assumedResult == result);
}

void test_findNonSpace_elementNotFound() {
    char str[] = "   ";

    char *assumedResult = str + 3;
    char *result = findNonSpace(str);

    assert(assumedResult == result);
}

void test_findSpace_elementNotFound() {
    char str[] = "qwertys324";

    char *assumedResult = str + 10;
    char *result = findSpace(str);

    assert(assumedResult == result);
}

void test_findSpace_commonCase() {
    char str[] = "qwe rty 33";

    char *assumedResult = str + 3;
    char *result = findSpace(str);

    assert(assumedResult == result);
}

void test_findSpaceReverse_commonCase() {
    char str[] = "qwe rt y";

    char *assumedResult = str + 6;
    char *result = findSpaceReverse(str + 7, str);

    assert(assumedResult == result);
}

void test_findSpaceReverse_elementNotFound() {
    char str[] = "qwe555rty";

    char *assumedResult = str;
    char *result = findSpaceReverse(str + 7, str);

    assert(assumedResult == result);
}

void test_findNonSpaceReverse_commonCase() {
    char str[] = "  \t  t";

    char *assumedResult = str + 5;
    char *result = findNonSpaceReverse(str + 5, str);

    assert(assumedResult == result);
}

void test_findNonSpaceReverse_elementNotFound() {
    char str[] = "   ";

    char *assumedResult = str;
    char *result = findNonSpaceReverse(str + 2, str);

    assert(assumedResult == result);
}

void test_strcmp_elementsEqual() {
    char str[] = "qwerty 12";
    char res[] = "qwerty 12";

    assert(strcmp(str, res) == 0);
}

void test_strcmp_firstLess() {
    char str[] = "qwery 4";
    char res[] = "qwerty 4";

    assert(strcmp(str, res) > 0);
}

void test_strcmp_firstGreater() {
    char str[] = "qwert 4";
    char res[] = "qwerty 4";

    assert(strcmp(str, res) < 0);
}

void test_copy_commonCase() {
    char str[] = "qwe1234t";

    char *resBegin = malloc(sizeof(char) * 8);

    char *resEnd = copy(str, str + 8, resBegin);
    *resEnd = '\0';

    assert(strcmp(str, resBegin) == 0);

    free(resBegin);
}

void test_copyIf_onlyDigits() {
    char str[] = "d34f 8xwj0q x";
    char endStr[] = "3480";
    char *resBegin = malloc(sizeof(char) * 14);

    char *resEnd = copyIf(str, str + 13, resBegin, isDigit);
    *resEnd = '\0';

    assert(strcmp(endStr, resBegin) == 0);

    free(resBegin);
}

void test_copyIf_allExceptDigits() {
    char str[] = "d34f 8xwj0q x";
    char endStr[] = "df xwjq x";
    char *resBegin = malloc(sizeof(char) * 14);

    char *resEnd = copyIf(str, str + 13, resBegin, isNotDigit);
    *resEnd = '\0';

    assert(strcmp(endStr, resBegin) == 0);

    free(resBegin);
}

void test_copyIfReverse_onlyDigits() {
    char str[] = "je4 6 4c3flr";
    char endStr[] = "3464";
    char *resBegin = malloc(sizeof(char) * 13);

    char *resEnd = copyIfReverse(str + 12, str - 1, resBegin, isDigit);
    *resEnd = '\0';

    assert(strcmp(endStr, resBegin) == 0);

    free(resBegin);
}

void test_copyIfReverse_allExceptDigits() {
    char str[] = "je4 6 4c3flr";
    char endStr[] = "rlfc  e";
    char *resBegin = malloc(sizeof(char) * 12);

    char *resEnd = copyIfReverse(str + 11, str, resBegin, isNotDigit);
    *resEnd = '\0';

    assert(strcmp(endStr, resBegin) == 0);

    free(resBegin);
}

void string_test() {
    test_strlen_commonCase();
    test_find_commonCase();
    test_find_elementNotFound();
    test_findNonSpace_commonCase();
    test_findNonSpace_elementNotFound();
    test_findSpace_elementNotFound();
    test_findSpace_commonCase();
    test_findSpaceReverse_commonCase();
    test_findSpaceReverse_elementNotFound();
    test_findNonSpaceReverse_commonCase();
    test_findNonSpaceReverse_elementNotFound();
    test_strcmp_elementsEqual();
    test_strcmp_firstLess();
    test_strcmp_firstGreater();
    test_copy_commonCase();
    test_copyIf_onlyDigits();
    test_copyIf_allExceptDigits();
    test_copyIfReverse_onlyDigits();
    test_copyIfReverse_allExceptDigits();
}