#ifndef COURSE_SORTS_H
#define COURSE_SORTS_H

#include <stdio.h>

void mergeSort(int *a, size_t n);

long long getMergeSortComps(int *a, size_t n);

void selectionSort(int *a, size_t n);

long long getSelectionSortComps(int *a, size_t n);

void insertionSort(int *a, size_t n);

long long getInsertionSortComps(int *a, size_t n);

void combSort(int *a, size_t n);

long long getCombSortComps(int *a, size_t n);

void shellSort(int *a, size_t n);

long long getShellSortComps(int *a, size_t n);

#endif
