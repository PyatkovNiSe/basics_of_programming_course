#include <assert.h>

#include "tasks_test.h"
#include "C:\Users\oosko\CLionProjects\course\lab5d\tasks.c"

static void test_swapRowsWithMaxMinElements_commonCase() {
    matrix result = createMatrixFromArray((int[]) {3, 9, 3,
                                                   4, 2, 6,
                                                   7, 8, 1}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int[]) {7, 8, 1,
                                                          4, 2, 6,
                                                          3, 9, 3}, 3, 3);

    swapRowsIncludeMinAndMaxElement(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_sortRowsByMaxElement_commonCase() {
    matrix result = createMatrixFromArray((int[]) {3, 1, 3,
                                                   1, 9, 1,
                                                   6, 4, 2}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int[]) {3, 1, 3,
                                                          6, 4, 2,
                                                          1, 9, 1}, 3, 3);

    sortRowsByMaxElement(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_sortColsByMinElement_commonCase() {
    matrix result = createMatrixFromArray((int[]) {3, 5, 2, 4, 3, 3,
                                                   2, 5, 1, 8, 2, 7,
                                                   6, 1, 4, 4, 8, 3}, 3, 6);
    matrix assumedMatrix = createMatrixFromArray((int[]) {5, 2, 3, 3, 3, 4,
                                                          5, 1, 2, 2, 7, 8,
                                                          1, 4, 6, 8, 3, 4}, 3, 6);

    sortColsByMinElement(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_getSquareOfMatrixIfSymmetric_symmetric() {
    matrix result = createMatrixFromArray((int[]) {1, 4, 5,
                                                   4, 2, 6,
                                                   5, 6, 3}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int[]) {42, 42, 44,
                                                          42, 56, 50,
                                                          44, 50, 70}, 3, 3);

    getSquareOfMatrixIfSymmetric(&result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(assumedMatrix);
    freeMemMatrix(result);
}

static void test_getSquareOfMatrixIfSymmetric_nonSymmetric() {
    matrix result = createMatrixFromArray((int[]) {1, 4, 4,
                                                   4, 2, 6,
                                                   5, 6, 3}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int[]) {1, 4, 4,
                                                          4, 2, 6,
                                                          5, 6, 3}, 3, 3);

    getSquareOfMatrixIfSymmetric(&result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(assumedMatrix);
    freeMemMatrix(result);
}

static void test_transposeIfMatrixHasNotEqualSumOfRows_commonCase() {
    matrix result = createMatrixFromArray((int[]) {1, 4, 4,
                                                   4, 2, 6,
                                                   5, 6, 3}, 3, 3);
    matrix assumedMatrix = createMatrixFromArray((int[]) {1, 4, 5,
                                                          4, 2, 6,
                                                          4, 6, 3}, 3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(assumedMatrix);
    freeMemMatrix(result);
}

static void test_isMutuallyInverseMatrices_commonCase() {
    matrix m1 = createMatrixFromArray((int[]) {3, -5,
                                               1, -2}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {2, -5,
                                               1, -3}, 2, 2);

    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}


static void test_findSumOfMaxesOfPseudoDiagonal_commonCase() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                              1, 3, 6, 3,
                                              3, 2, 1, 2}, 3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);

    freeMemMatrix(m);
}

static void test_getMinInArea_commonCase1() {
    matrix m = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                              3, 11, 8, 9,
                                              4, 1, 12, 2}, 3, 4);

    assert(getMinInArea(m) == 5);

    freeMemMatrix(m);
}

static void test_getMinInArea_commonCase2() {
    matrix m = createMatrixFromArray((int[]) {6, 8, 9, 2,
                                              7, 12, 3, 4,
                                              10, 11, 5, 1}, 3, 4);

    assert(getMinInArea(m) == 6);

    freeMemMatrix(m);
}

void test_sortByDistances_commonCase() {
    matrix result = createMatrixFromArray((int[]) {3, 1, 2, 4,
                                                   0, 0, 0, 1,
                                                   4, 6, 1, 3}, 3, 4);
    matrix assumedMatrix = createMatrixFromArray((int[]) {0, 0, 0, 1,
                                                          3, 1, 2, 4,
                                                          4, 6, 1, 3}, 3, 4);

    sortByDistances(result);

    assert(areTwoMatricesEqual(assumedMatrix, result));

    freeMemMatrix(result);
    freeMemMatrix(assumedMatrix);
}

static void test_countEqClassesByRowsSum_commonCase() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              2, 7,
                                              5, 4,
                                              4, 3,
                                              1, 6,
                                              8, 0}, 6, 2);

    int result = countEqClassesByRowsSum(m);
    int assumedResult = 3;

    assert(result == assumedResult);

    freeMemMatrix(m);
}

void tasks_test() {
    test_swapRowsWithMaxMinElements_commonCase();
    test_sortRowsByMaxElement_commonCase();
    test_sortColsByMinElement_commonCase();
    test_getSquareOfMatrixIfSymmetric_symmetric();
    test_getSquareOfMatrixIfSymmetric_nonSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows_commonCase();
    test_isMutuallyInverseMatrices_commonCase();
    test_findSumOfMaxesOfPseudoDiagonal_commonCase();
    test_getMinInArea_commonCase1();
    test_getMinInArea_commonCase2();
    test_sortByDistances_commonCase();
    test_countEqClassesByRowsSum_commonCase();
}