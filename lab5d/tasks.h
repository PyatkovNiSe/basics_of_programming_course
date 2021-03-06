#ifndef LAB_5B_TASKS_H
#define LAB_5B_TASKS_H

#include "../libs/data_structures/matrix/matrix.h"

void swapRowsIncludeMinAndMaxElement(matrix m);

void sortRowsByMaxElement(matrix m);

void sortColsByMinElement(matrix m);

void getSquareOfMatrixIfSymmetric(matrix *m);

void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

int getMinInArea(matrix m);

void sortByDistances(matrix m);

int countEqClassesByRowsSum(matrix m);

int getNSpecialElement(matrix m);

void swapPenultimateRow(matrix m);

int countNonDescendingRowsMatrices(const matrix *ms, int nMatrix);

void printMatrixWithMaxZeroRows(const matrix *ms, int nMatrix);

void printMatrixWithMinNorm(const matrix *ms, int nMatrices);

#endif
