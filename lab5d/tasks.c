#include <stdio.h>
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

static int countNUnique(const long long *const a, const int size) {
    if (size == 0)
        return 0;

    long long *aCopy = malloc(size * sizeof(long long));
    memcpy(aCopy, a, size * sizeof(long long));
    qsort(aCopy, size, sizeof(long long), cmp_long_long);

    int counter = 1;
    for (int i = 1; i < size; ++i)
        if (aCopy[i - 1] != aCopy[i])
            counter++;

    return counter;
}

void swapRowsIncludeMinAndMaxElement(matrix m) {
    position posMax = getMaxValuePos(m);
    position posMin = getMinValuePos(m);

    swapRows(m, posMax.rowIndex, posMin.rowIndex);
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

static int getMin(const int *const a, const int n) {
    int min = a[0];
    for (int i = 0; i < n; ++i)
        if (a[i] < min)
            min = a[i];

    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void getSquareOfMatrixIfSymmetric(matrix *const m) {
    if (!isSymmetricMatrix(*m))
        return;

    matrix square = multiplyMatrices(*m, *m);

    freeMemMatrix(*m);

    *m = square;
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

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    int rows = m.nRows;
    int cols = m.nCols;
    long long *sumOfRows = malloc(rows * sizeof(long long));

    for (int i = 0; i < rows; i++)
        sumOfRows[i] = arraySum_(m.values[i], cols);

    if (isUnique(sumOfRows, rows))
        transposeSquareMatrix(m);

    free(sumOfRows);
}

bool isMutuallyInverseMatrices(const matrix m1, const matrix m2) {
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

static int min2(const int x, const int y) {
    return x < y ? x : y;
}

int getMinInArea(const matrix m) {
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

static float getDistance(const int *const a, const int size) {
    long long distanceSquared = 0;
    for (int i = 0; i < size; ++i)
        distanceSquared += a[i] * a[i];

    return sqrt(distanceSquared);
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int countEqClassesByRowsSum(const matrix m) {
    int rows = m.nRows;
    int cols = m.nCols;
    long long *arrayOfSums = malloc(sizeof(long long) * rows);

    for (int i = 0; i < rows; ++i)
        arrayOfSums[i] = arraySum_(m.values[i], cols);

    int unique = countNUnique(arrayOfSums, rows);

    free(arrayOfSums);

    return unique;
}

int getNSpecialElement(const matrix m) {
    int counter = 0;

    for (int i = 0; i < m.nCols; ++i) {
        long long currentSum = 0;
        for (int j = 0; j < m.nRows; ++j)
            currentSum += m.values[j][i];
        for (int j = 0; j < m.nRows; ++j)
            if (currentSum < 2 * m.values[j][i])
                counter++;
    }

    return counter;
}

static position getLeftMin(matrix m) {
    position minPos = (position) {0, 0};

    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            int min = m.values[minPos.rowIndex][minPos.colIndex];
            if (j < minPos.colIndex && m.values[i][j] == min ||
                m.values[i][j] < min)
                minPos = (position) {i, j};
        }
    }

    return minPos;
}

void swapPenultimateRow(matrix m) {
    int minColIndex = getLeftMin(m).colIndex;
    int penultimateRow = m.nRows - 2;
    int rows = m.nRows;

    int *minCol = (int *) malloc(sizeof(int) * rows);

    for (int i = 0; i < rows; ++i)
        minCol[i] = m.values[i][minColIndex];

    memcpy(m.values[penultimateRow], minCol, sizeof(int) * m.nCols);
    free(minCol);
}

static bool isNonDescendingSorted(const int *const a, const int n) {
    for (int i = 1; i < n; ++i)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

static bool hasAllNonDescendingRows(const matrix m) {
    int rows = m.nRows;

    for (int i = 0; i < rows; ++i)
        if (!isNonDescendingSorted(m.values[i], rows))
            return false;
    return true;
}

int countNonDescendingRowsMatrices(const matrix *const ms,
                                   const int nMatrix) {
    int counter = 0;

    for (int i = 0; i < nMatrix; ++i)
        counter += hasAllNonDescendingRows(ms[i]);

    return counter;
}

static int countValues(const int *a, int n, int value) {
    int counter = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == value)
            counter++;
    }

    return counter;
}

static int countZeroRows(matrix m) {
    int rows = m.nRows;
    int cols = m.nCols;
    int counter = 0;

    for (int i = 0; i < rows; ++i)
        counter += countValues(m.values[i], cols, 0) == cols;

    return counter;
}

void printMatrixWithMaxZeroRows(const matrix *const ms,
                                const int nMatrix) {
    int *matricesZeroRows = (int *) malloc(sizeof(int) * nMatrix);

    for (int i = 0; i < nMatrix; ++i)
        matricesZeroRows[i] = countZeroRows(ms[i]);

    int zeroRowsMax = getMax(matricesZeroRows, nMatrix);

    for (int i = 0; i < nMatrix; ++i)
        if (zeroRowsMax == matricesZeroRows[i]) {
            outputMatrix(ms[i]);
            printf("\n");
        }

    free(matricesZeroRows);
}

static int matrixGetV(matrix m, position p) {
    return m.values[p.rowIndex][p.colIndex];
}

void printMatrixWithMinNorm(const matrix *const ms, const int nMatrices) {
    int* normsOfMatrix = (int *) malloc(sizeof(int) * nMatrices);

    for (int i = 0; i < nMatrices; i++) {
        position maxPos = getMaxValuePos(ms[i]);
        position minPos = getMinValuePos(ms[i]);


        int max = max2(abs(matrixGetV(ms[i], maxPos)),
                       abs(matrixGetV(ms[i], minPos)));
        normsOfMatrix[i] = max;
    }

    int min_norm = linearSearchMin_(normsOfMatrix, nMatrices);

    for (int i = 0; i < nMatrices; i++) {
        if (normsOfMatrix[i] == min_norm) {
            outputMatrix(ms[i]);
            printf("\n");
        }
    }

    free(normsOfMatrix);
}