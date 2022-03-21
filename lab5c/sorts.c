#include "sorts.h"
#include "../libs/algorithms/algorithm.h"
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

#define SWAP(a, b) swap(a, b, sizeof(int))

long long nCompsMergeSort;

static int cmp_int(const void *a, const void *b) {
    int x = *((int *) a);
    int y = *((int *) b);
    if (x < y)
        return -1;
    if (x > y)
        return 1;

    return 0;
}

void merge(const int *a, const size_t sizeA,
           const int *b, const size_t sizeB,
           int *c) {
    size_t indexA = 0;
    size_t indexB = 0;
    while (indexA < sizeA || indexB < sizeB)
        if (indexB == sizeB || indexA < sizeA && a[indexA] < b[indexB]) {
            c[indexA + indexB] = a[indexA];
            indexA++;
        } else {
            c[indexA + indexB] = b[indexB];
            indexB++;
        }
}

void _mergeSort(int *a, int left, int right, int *buf) {
    int size = right - left;
    if (size <= 1)
        return;

    int middle = left + (right - left) / 2;
    _mergeSort(a, left, middle, buf);
    _mergeSort(a, middle, right, buf);

    merge(a + left, middle - left,
          a + middle, right - middle,
          buf);
    memcpy(a + left, buf, size * sizeof(int));
}

void mergeSort(int *a, const size_t n) {
    int *buffer = (int *) malloc(sizeof(int) * n);
    _mergeSort(a, 0, n, buffer);
    free(buffer);
}

void getMergeComps(const int *a, const size_t sizeA,
                   const int *b, const size_t sizeB,
                   int *c) {
    size_t indexA = 0;
    size_t indexB = 0;
    while (++nCompsMergeSort && (indexA < sizeA || indexB < sizeB))
        if (++nCompsMergeSort && (indexB == sizeB || indexA < sizeA && a[indexA] < b[indexB])) {
            c[indexA + indexB] = a[indexA];
            indexA++;
        } else {
            c[indexA + indexB] = b[indexB];
            indexB++;
        }
}

void _getMergeSortComps(int *a, int left, int right,
                        int *buf) {
    int size = right - left;
    if (++nCompsMergeSort && size <= 1)
        return;

    int middle = left + (right - left) / 2;
    _getMergeSortComps(a, left, middle, buf);
    _getMergeSortComps(a, middle, right, buf);

    getMergeComps(a + left, middle - left,
                  a + middle, right - middle,
                  buf);
    memcpy(a + left, buf, size * sizeof(int));
}

long long getMergeSortComps(int *a, size_t n) {
    nCompsMergeSort = 0;

    int *buffer = (int *) malloc(sizeof(int) * n);
    _getMergeSortComps(a, 0, n, buffer);
    free(buffer);

    return nCompsMergeSort;
}

void selectionSort(int *a, const size_t n) {
    if (n <= 1)
        return;
    for (size_t i = 0; i < n; ++i) {
        size_t currentIndex = i;
        for (size_t j = i + 1; j < n; j++) {
            if (a[j] < a[currentIndex])
                currentIndex = j;
        }
        SWAP(&a[i], &a[currentIndex]);
    }
}

void insertionSort(int *a, const size_t n) {
    for (int i = 1; i < n; ++i) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

long long getSelectionSortComps(int *a, size_t n) {
    long long nComps = 0;

    if (++nComps && n <= 1)
        return nComps;
    for (size_t i = 0; ++nComps && i < n; ++i) {
        size_t currentIndex = i;
        for (size_t j = i + 1; ++nComps && j < n; j++) {
            if (++nComps && a[j] < a[currentIndex])
                currentIndex = j;
        }
        SWAP(&a[i], &a[currentIndex]);
    }

    return nComps;
}

long long getInsertionSortComps(int *a, size_t n) {
    long long nComps = 0;

    for (int i = 1; ++nComps && i < n; ++i) {
        int t = a[i];
        int j = i;
        while (++nComps && j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }

    return nComps;
}

void combSort(int *a, const size_t n) {
    double factor = 1.24733;
    size_t step = n;
    bool swapped = true;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= factor;
        swapped = false;
        for (size_t i = 0, j = i + step; j < n; ++i, ++j) {
            if (a[i] > a[j]) {
                SWAP(&a[i], &a[j]);
                swapped = true;
            }
        }
    }
}

long long getCombSortComps(int *a, size_t n) {
    long long nComps = 0;

    double factor = 1.24733;
    size_t step = n;
    bool swapped = true;
    while (++nComps && (step > 1 || swapped)) {
        if (++nComps && step > 1)
            step /= factor;
        swapped = false;
        for (size_t i = 0, j = i + step; ++nComps && j < n; ++i, ++j) {
            if (++nComps && a[i] > a[j]) {
                SWAP(&a[i], &a[j]);
                swapped = true;
            }
        }
    }

    return nComps;
}

void shellSort(int *a, size_t n) {
    for (int d = n / 2; d > 0; d /= 2)
        for (int i = d; i < n; ++i)
            for (int j = i - d; j >= 0 && a[j] > a[j + d]; j -= d)
                SWAP(&a[j], &a[j + d]);
}

long long getShellSortComps(int *a, size_t n) {
    long long nComps = 0;

    for (int d = n / 2; ++nComps && d > 0; d /= 2)
        for (int i = d; ++nComps && i < n; ++i)
            for (int j = i - d; ++nComps && j >= 0 && a[j] > a[j + d]; j -= d)
                SWAP(&a[j], &a[j + d]);

    return nComps;
}

static long long getPrefixSums(int *a, size_t n) {
    long long nComps = 0;

    int prev = a[0];
    *a = 0;
    for (int i = 1; ++nComps && i < n; i++) {
        int t = a[i];
        a[i] = prev + a[i - 1];
        prev = t;
    }

    return nComps;
}

void LSD_sort(int *a, size_t n) {
    int *buffer = (int *) calloc(n, sizeof(int));

    const int STEP = 8;
    const int MASK = 0b11111111;

    for (int byte = 0; byte < sizeof(int); byte++) {
        int values[UCHAR_MAX + 1] = {0};

        for (size_t i = 0; i < n; i++) {
            int currentByte;
            if (byte + 1 == sizeof(int))
                currentByte = ((a[i] >> (byte * STEP)) + CHAR_MAX + 1) & MASK;
            else
                currentByte = (a[i] >> (byte * STEP)) & MASK;

            values[currentByte]++;
        }

        getPrefixSums(values, UCHAR_MAX + 1);

        for (size_t i = 0; i < n; i++) {
            int currentByte;
            if (byte + 1 == sizeof(int))
                currentByte = ((a[i] >> (byte * STEP)) + CHAR_MAX + 1) & MASK;
            else
                currentByte = (a[i] >> (byte * STEP)) & MASK;

            buffer[values[currentByte]++] = a[i];
        }

        memcpy(a, buffer, sizeof(int) * n);
    }

    free(buffer);
}

long long getLSD_sortComps(int *a, size_t n) {
    long long nComps = 0;

    int *buffer = (int *) calloc(n, sizeof(int));

    const int STEP = 8;
    const int MASK = 0b11111111;

    for (int byte = 0; ++nComps && byte < sizeof(int); byte++) {
        int values[UCHAR_MAX + 1] = {0};

        for (size_t i = 0; ++nComps && i < n; i++) {
            int currentByte;
            if (++nComps && byte + 1 == sizeof(int))
                currentByte = ((a[i] >> (byte * STEP)) + CHAR_MAX + 1) & MASK;
            else
                currentByte = (a[i] >> (byte * STEP)) & MASK;

            values[currentByte]++;
        }

        nComps += getPrefixSums(values, UCHAR_MAX + 1);

        for (size_t i = 0; ++nComps && i < n; i++) {
            int currentByte;
            if (++nComps && byte + 1 == sizeof(int))
                currentByte = ((a[i] >> (byte * STEP)) + CHAR_MAX + 1) & MASK;
            else
                currentByte = (a[i] >> (byte * STEP)) & MASK;

            buffer[values[currentByte]++] = a[i];
        }

        memcpy(a, buffer, sizeof(int) * n);
    }

    free(buffer);

    return nComps;
}

void stdlibQsort(int *a, size_t n) {
    qsort(a, n, sizeof(int), cmp_int);
}