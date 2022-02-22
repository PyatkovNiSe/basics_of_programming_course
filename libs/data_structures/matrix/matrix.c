#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "matrix.h"
#include "../../algorithms/algorithm.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);

    free(m.values);
    m.values = NULL;
    m.nRows = 0;
    m.nCols = 0;
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    int rows = m.nRows;
    int cols = m.nCols;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *const arrayOfMatrices, const int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        inputMatrix(arrayOfMatrices[i]);
}

void outputMatrix(const matrix m) {
    int rows = m.nRows;
    int cols = m.nCols;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            printf("%d\t", m.values[i][j]);
        printf("\n");
    }
}

void outputMatrices(const matrix *const arrayOfMatrices,
                    const int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        outputMatrix(arrayOfMatrices[i]);
        printf("\n");
    }
}

void swapRows(matrix m, const int i, const int j) {
    assert(i < m.nRows && j < m.nRows);

    swap(&m.values[i], &m.values[j], sizeof(int *));
}

void swapColumns(matrix m, const int i, const int j) {
    assert(i < m.nCols && j < m.nCols);

    int rows = m.nRows;
    for (int k = 0; k < rows; ++k)
        swap(&m.values[k][i], &m.values[k][j], sizeof(int));
}

void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*const criteria)(const int *const, const int)) {
    int rows = m.nRows;
    int cols = m.nCols;
    int *valuesOfCriteria = (int *) malloc(sizeof(int) * rows);

    for (int i = 0; i < rows; ++i)
        valuesOfCriteria[i] = criteria(m.values[i], cols);

    for (int i = 1; i < cols; ++i) {
        int j = i;
        while (j != 0 && valuesOfCriteria[j - 1] > valuesOfCriteria[j]) {
            swapRows(m, j - 1, j);
            swap(valuesOfCriteria + j - 1, valuesOfCriteria + j, sizeof(int));
            j--;
        }
    }

    free(valuesOfCriteria);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                           float (*criteria)(const int *, int)) {
    int rows = m.nRows;
    int cols = m.nCols;
    float *valuesOfCriteria = (float *) malloc(sizeof(float) * rows);

    for (int i = 0; i < rows; ++i)
        valuesOfCriteria[i] = criteria(m.values[i], cols);

    for (int i = 1; i < rows; ++i) {
        int j = i;
        while (j != 0 && valuesOfCriteria[j - 1] > valuesOfCriteria[j]) {
            swapRows(m, j - 1, j);
            swap(valuesOfCriteria + j - 1, valuesOfCriteria + j, sizeof(int));
            j--;
        }
    }

    free(valuesOfCriteria);
}

void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*const criteria)(const int *const, const int)) {
    int cols = m.nCols;
    int rows = m.nRows;
    int *valuesOfCriteria = (int *) malloc(cols * sizeof(int));
    int *currentCol = (int *) malloc(rows * sizeof(int));

    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j)
            currentCol[j] = m.values[j][i];
        valuesOfCriteria[i] = criteria(currentCol, rows);
    }

    free(currentCol);

    for (int i = 1; i < cols; ++i) {
        int j = i;
        while (j != 0 && valuesOfCriteria[j - 1] > valuesOfCriteria[j]) {
            swapColumns(m, j - 1, j);
            swap(valuesOfCriteria + j - 1, valuesOfCriteria + j, sizeof(int));
            j--;
        }
    }

    free(valuesOfCriteria);
}

bool isSquareMatrix(const matrix m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    for (int i = 0; i < m1.nRows; ++i)
        if (memcmp(m1.values[i], m2.values[i], sizeof(int) * m1.nCols) != 0)
            return false;
    return true;
}

bool isEMatrix(const matrix m) {
    if (!isSquareMatrix(m))
        return false;

    int rows = m.nRows;
    int cols = m.nCols;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (i == j && m.values[i][j] != 1 || i != j && m.values[i][j] != 0)
                return false;
    return true;
}

bool isSymmetricMatrix(const matrix m) {
    if (!isSquareMatrix(m))
        return false;

    int rows = m.nRows;
    int cols = m.nCols;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (m.values[i][j] != m.values[j][i])
                return false;
    return true;
}

void transposeSquareMatrix(matrix m) {
    if (!isSquareMatrix(m)) {
        fprintf(stderr, "non-square matrix is given");
        exit(1);
    }

    int rows = m.nRows;
    int cols = m.nCols;
    for (int i = 0; i < rows; ++i)
        for (int j = i; j < cols; ++j)
            if (i != j)
                swap(&m.values[i][j], &m.values[j][i], sizeof(int));
}

position getMinValuePos(const matrix m) {
    int min = m.values[0][0];
    position pos = (position) {0, 0};

    int rows = m.nRows;
    int cols = m.nCols;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            int currentElement = m.values[i][j];
            if (currentElement < min) {
                min = currentElement;
                pos = (position) {i, j};
            }
        }

    return pos;
}

position getMaxValuePos(const matrix m) {
    int max = m.values[0][0];
    position pos = (position) {0, 0};

    int rows = m.nRows;
    int cols = m.nCols;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            int currentElement = m.values[i][j];
            if (currentElement > max) {
                max = currentElement;
                pos = (position) {i, j};
            }
        }

    return pos;
}

matrix createMatrixFromArray(const int *const values,
                             const int nRows, const int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; ++i)
        for (int j = 0; j < nCols; ++j)
            m.values[i][j] = values[k++];

    return m;
}

matrix *createArrayOfMatricesFromArray(const int *const values,
                                       const int nMatrices,
                                       const int nRows, const int nCols) {
    matrix *arrayOfMatrices = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int i = 0; i < nMatrices; ++i)
        for (int j = 0; j < nRows; ++j)
            for (int k = 0; k < nCols; ++k)
                arrayOfMatrices[i].values[j][k] = values[l++];

    return arrayOfMatrices;
}

matrix multiplyMatrices(const matrix m1, const matrix m2) {
    alloca(m1.nCols != m2.nRows);

    matrix result = getMemMatrix(m1.nRows, m2.nCols);

    int rows1 = m1.nRows;
    int rows2 = m2.nRows;
    int cols2 = m2.nCols;
    for (int i = 0; i < rows1; ++i)
        for (int j = 0; j < cols2; ++j) {
            result.values[i][j] = 0;
            for (int k = 0; k < rows2; ++k)
                result.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    return result;
}