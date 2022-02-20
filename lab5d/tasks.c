#include <stdbool.h>
#include <string.h>

#include "tasks.h"
#include "C:\Users\oosko\CLionProjects\course\libs\data_structures\matrix\matrix.h"
#include "C:\Users\oosko\CLionProjects\course\libs\algorithms\array\array.h"

static int max2(const int x, const int y) {
    return x > y ? x : y;
}

static int getMax(const int *const a, const int n) {
    int max = a[0];
    for (int i = 0; i < n; ++i)
        max = max2(max, a[i]);

    return max;
}

static int getMin(const int *const a, const int n) {
    int min = a[0];
    for (int i = 0; i < n; ++i)
        if (a[i] < min)
            min = a[i];

    return min;
}

static long long getSum(const int *const a, const int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

static int longLongCmp(const void *x, const void *y) {
    long long a = *((long long *) x);
    long long b = *((long long *) y);

    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    else
        return 0;
}

static bool isUnique(const long long *const a, const int n) {
    long long *aCopy = (long long *) malloc(n * sizeof(long long));

    memcpy(aCopy, a, n * sizeof(long long));
    qsort(aCopy, n, sizeof(long long), longLongCmp);

    for (int i = 1; i < n; ++i)
        if (aCopy[i - 1] == aCopy[i]) {
            free(aCopy);
            return false;
        }

    free(aCopy);
    return true;
}

void swapRowsIncludeMinAndMaxElement(matrix m) {
    position posMax = getMaxValuePos(m);
    position posMin = getMinValuePos(m);

    swapRows(m, posMax.rowIndex, posMin.rowIndex);
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (!isSymmetricMatrix(*m))
        return;

    matrix square = multiplyMatrices(*m, *m);

    freeMemMatrix(*m);

    *m = square;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    int rows = m.nRows;
    int cols = m.nCols;
    long long *sumOfRows = (long long *) malloc(rows * sizeof(long long));

    for (int i = 0; i < rows; i++)
        sumOfRows[i] = getSum(m.values[i], cols);

    if (isUnique(sumOfRows, rows))
        transposeSquareMatrix(m);

    free(sumOfRows);
}