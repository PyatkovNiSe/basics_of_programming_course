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

