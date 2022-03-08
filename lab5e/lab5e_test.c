#include "lab5e_test.h"
#include "../string/tasks/string_.h"
#include "../lab5e/tasks.h"
#include <stdio.h>
#include <assert.h>

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

static void test_removeAdjacentEqualLetters_commonCase() {
    char str[] = "qqqqwwwweeeerty234riot";
    removeAdjacentEqualLetters(str);

    char assumedStr[] = "qwerty234riot";

    ASSERT_STRING(assumedStr, str);
}

static void test_removeExtraSpaces_commonCase() {
    char str[] = "q\t\t  werty k\tbbb  dg";

    removeExtraSpaces(str);

    char assumedStr[] = "q werty k\tbbb dg";

    ASSERT_STRING(assumedStr, str);
}

static void test_reverseWord_commonCase() {
    char str[] = "qwerty 238";

    reverseWordsInString(str);

    char assumedStr[] = "ytrewq 832";

    ASSERT_STRING(assumedStr, str);
}

static void test_reverseWord_emptyString() {
    char str[] = "";

    reverseWordsInString(str);

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);
}

static void test_replaceNumbersWithSpaces_commonCase() {
    char str[MAX_STRING_SIZE] = "s0m3sp4c3";

    replaceNumbersWithSpaces(str);

    char assumedStr[] = "sm   sp    c   ";

    ASSERT_STRING(assumedStr, str);
}

static void test_replaceNumbersWithSpaces_emptyString() {
    char str[MAX_STRING_SIZE] = "";

    replaceNumbersWithSpaces(str);

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);
}

static void test_replaceWord_commonCase() {
    char str[MAX_STRING_SIZE] = "jili bili biba and boba";

    replaceWord(str, "biba", "boba");

    char assumedStr[] = "jili bili boba and boba";

    ASSERT_STRING(assumedStr, str);
}

static void test_replaceWord_emptyString() {
    char str[MAX_STRING_SIZE] = "";

    replaceWord(str, "biba", "boba");

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);
}

static void test_isLexicographicOrdered_isOrdered() {
    char str[MAX_STRING_SIZE] = "a b c d e";

    assert(isLexicographicOrdered(str) == true);
}

static void test_isLexicographicOrdered_isNotOrdered() {
    char str[MAX_STRING_SIZE] = "s a f a s f";

    assert(isLexicographicOrdered(str) == false);
}

static void test_countPalindromeWordsSeparatedWithComma_commonCase() {
    char str[] = "botob,deked,abcdedcba,code";

    int assumedResult = 3;

    assert(countPalindromeWordsSeparatedWithComma(str) == assumedResult);
}

static void test_countPalindromeWordsSeparatedWithComma_emptyString() {
    char str[] = "";

    int assumedResult = 0;

    assert(countPalindromeWordsSeparatedWithComma(str) == assumedResult);
}

void lab5e_test() {
    test_removeNonLetters_commonCase();
    test_removeAdjacentEqualLetters_commonCase();
    test_removeExtraSpaces_commonCase();
    test_reverseWord_commonCase();
    test_reverseWord_emptyString();
    test_replaceNumbersWithSpaces_commonCase();
    test_replaceNumbersWithSpaces_emptyString();
    test_replaceWord_commonCase();
    test_replaceWord_emptyString();
    test_isLexicographicOrdered_isOrdered();
    test_isLexicographicOrdered_isNotOrdered();
    test_countPalindromeWordsSeparatedWithComma_commonCase();
    test_countPalindromeWordsSeparatedWithComma_emptyString();
}