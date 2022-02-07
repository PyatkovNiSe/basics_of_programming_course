#include <stdio.h>
#include "vector.h"

vector createVector(size_t n) {
    vector v = {NULL, 0, n};

    if (n == 0)
        return v;

    v.data = (int*) malloc(n * sizeof(int));
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return v;
}

void reserve(vector *v, size_t new_capacity) {
    v->data = realloc (v->data, sizeof(int) * new_capacity);

    v->capacity = new_capacity;
    if (new_capacity < v->size)
        v->size = new_capacity;

    if (new_capacity == 0)
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