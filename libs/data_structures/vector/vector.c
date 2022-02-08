#include <stdio.h>
#include "vector.h"

vector createVector(const size_t n) {
    vector v = {NULL, 0, n};

    if (n == 0)
        return v;

    v.data = (int *) malloc(n * sizeof(int));
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return v;
}

void reserve(vector *v, const size_t newCapacity) {
    v->data = realloc(v->data, sizeof(int) * newCapacity);

    v->capacity = newCapacity;
    if (newCapacity < v->size)
        v->size = newCapacity;

    if (newCapacity == 0)
        return;

    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    reserve(v, 0);
}

bool isEmpty(const vector *v) {
    return v->size == 0;
}

bool isFull(const vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(const vector *v, const size_t i) {
    return v->data[i];
}

void pushBack(vector *v, const int x) {
    if (isFull(v))
        reserve(v, isEmpty(v) ? 1 : v->capacity * 2);
    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }

    v->size--;
}

int *atVector(const vector *v, const size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%llu] doesn't exist\n", index);
        exit(1);;
    }

    return v->data + index;
}

int *back(const vector *v) {
    return atVector(v, v->size - 1);
}

int *front(const vector *v) {
    return atVector(v, 0);
}