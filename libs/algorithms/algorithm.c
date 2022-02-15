#include "algorithm.h"

static void swap_(unsigned char *a, unsigned char *b) {
    unsigned const char t = *a;
    *a = *b;
    *b = t;
}

void swap(void *const a, void *const b, const int size) {
    for (int i = 0; i < size; i++)
        swap_(a + i, b + i);
}