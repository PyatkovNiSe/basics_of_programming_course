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

static void test_makeMixedStringFromTwo_commonCase() {
    char str1[] = "qwerty first top";
    char str2[] = "is on";
    char str[MAX_STRING_SIZE];

    makeMixedStringFromTwo(str1, str2, str);

    char assumedStr[] = "qwerty is first on top";

    ASSERT_STRING(assumedStr, str);
}

static void test_makeMixedStringFromTwo_emptyStrings() {
    char str1[] = "";
    char str2[] = "";
    char str[MAX_STRING_SIZE] = "qwewqweg";

    makeMixedStringFromTwo(str1, str2, str);

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);
}

static void test_reverseWordOrder_commonCase() {
    char str[MAX_STRING_SIZE] = "abcde alfabet' edcba";

    reverseWordOrder(str);

    char assumedStr[] = "edcba alfabet' abcde";

    ASSERT_STRING(assumedStr, str);
}

static void test_reverseWordOrder_emptyString() {
    char str[MAX_STRING_SIZE] = "";

    reverseWordOrder(str);

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);
}

static void testAll_getWordBeforeFirstWordWithA() {
    WordDescriptor word;
    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &word)
            == EMPTY_STRING
    );

    char s2[] = " ABC ";
    assert(getWordBeforeFirstWordWithA(s2, &word)
            == FIRST_WORD_WITH_A
    );

    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &word)
            == WORD_FOUND
    );

    char got[MAX_WORD_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    ASSERT_STRING ("BC", got);

    char s4[] = "B Q WE YR OW IUWR ";
    assert(getWordBeforeFirstWordWithA(s4, &word)
            == NOT_FOUND_A_WORD_WITH_A);
}

static void test_lastWordInFirstStringInSecondString_commonCase() {
    char str1[] = "when you when you";
    char str2[] = "you writing tests";

    WordDescriptor word;
    lastWordInFirstStringInSecondString(str1, str2, &word);

    char result[MAX_STRING_SIZE];
    wordDescriptorToString(word, result);

    char assumedStr[] = "you";

    ASSERT_STRING(assumedStr, result);
}

static void test_lastWordInFirstStringInSecondString_emptyString() {
    char str1[] = "";
    char str2[] = "when you writing tests";

    WordDescriptor word;
    bool status = lastWordInFirstStringInSecondString(str1, str2, &word);

    assert(status == false);
}

static void test_hasEqualWords_commonCase() {
    char str[] = "testi delat pisat testi nado";

    assert(hasEqualWords(str) == true);
}

static void test_hasEqualWords_emptyString() {
    char str[] = "";

    assert(hasEqualWords(str) == true);
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
    test_makeMixedStringFromTwo_commonCase();
    test_makeMixedStringFromTwo_emptyStrings();
    test_reverseWordOrder_commonCase();
    test_reverseWordOrder_emptyString();
    testAll_getWordBeforeFirstWordWithA();
    test_lastWordInFirstStringInSecondString_commonCase();
    test_lastWordInFirstStringInSecondString_emptyString();
    test_hasEqualWords_commonCase();
    test_hasEqualWords_emptyString();
}