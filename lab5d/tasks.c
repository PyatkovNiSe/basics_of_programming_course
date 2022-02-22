#include <stdbool.h>
#include <string.h>
#include <math.h>

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

static int cmp_long_long(const void *pa, const void *pb) {
    long long a = *((long long *) pa);
    long long b = *((long long *) pb);

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
    qsort(aCopy, n, sizeof(long long), cmp_long_long);

    for (int i = 1; i < n; ++i)
        if (aCopy[i - 1] == aCopy[i]) {
            free(aCopy);
            return false;
        }

    free(aCopy);
    return true;
}

static int min2(const int x, const int y) {
    return x < y ? x : y;
}

static float getDistance(const int *const a, const int size) {
    long long distanceSquared = 0;
    for (int i = 0; i < size; ++i)
        distanceSquared += a[i] * a[i];

    return sqrt(distanceSquared);
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

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix result = multiplyMatrices(m1, m2);

    if (isEMatrix(result)) {
        freeMemMatrix(result);
        return true;
    }

    freeMemMatrix(result);
    return false;
}

long long findSumOfMaxesOfPseudoDiagonal(const matrix m) {
    long long sum = 0;

    int rows = m.nRows;
    int cols = m.nCols;
    for (int i = 1; i < rows; ++i) {
        int j = 0;
        int k = i;
        int max = m.values[k][j];
        while (k < rows && j < cols)
            max = max2(max, m.values[k++][j++]);
        sum += max;
    }
    for (int j = 1; j < cols; ++j) {
        int i = 0;
        int k = j;
        int max = m.values[i][k];
        while (i < rows && k < cols)
            max = max2(max, m.values[i++][k++]);
        sum += max;
    }

    return sum;
}

int getMinInArea(matrix m) {
    position pos = getMaxValuePos(m);
    int rowIndex = pos.rowIndex;
    int leftBoarder = pos.colIndex;
    int rightBoarder = leftBoarder;
    int min = m.values[rowIndex][leftBoarder];

    while (rowIndex >= 0) {
        for (int k = leftBoarder; k <= rightBoarder; ++k)
            min = min2(min, m.values[rowIndex][k]);
        if (leftBoarder > 0)
            leftBoarder--;
        if (rightBoarder + 1 < m.nCols)
            rightBoarder++;
        rowIndex--;
    }

    return min;
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}
