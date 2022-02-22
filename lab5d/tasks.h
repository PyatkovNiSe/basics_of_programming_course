#ifndef LAB_5B_TASKS_H
#define LAB_5B_TASKS_H

#include "C:\Users\oosko\CLionProjects\course\libs\data_structures\matrix\matrix.h"

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

#endif
