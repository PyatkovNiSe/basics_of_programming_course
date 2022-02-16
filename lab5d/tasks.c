#include "tasks.h"
#include "C:\Users\oosko\CLionProjects\course\libs\data_structures\matrix\matrix.h"
#include "C:\Users\oosko\CLionProjects\course\libs\algorithms\array\array.h"

static int max2(const int x, const int y) {
    return x > y ? x : y;
}

static int getMax(const int *const a, const int size) {
    int max = a[0];
    for (int i = 0; i < size; ++i)
        max = max2(max, a[i]);

    return max;
}

static int getMin(const int *const a, const int size) {
    int min = a[0];
    for (int i = 0; i < size; ++i)
        if (a[i] < min)
            min = a[i];

    return min;
}

void swapRowsIncludeMinAndMaxElement(matrix m) {
    position posMax = getMaxValuePos(m);
    position posMin = getMinValuePos(m);

    swapRows(m, posMax.rowIndex, posMin.rowIndex);
}

void sortRowsByNonDecreasingLargestRowElements(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void sortColsByNonDecreasingLeastColElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (!isSymmetricMatrix(*m))
        return;

    matrix square = multiplyMatrices(*m, *m);

    freeMemMatrix(*m);

    *m = square;
}