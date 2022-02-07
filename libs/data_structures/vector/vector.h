#ifndef LAB_5B_VECTOR_H
#define LAB_5B_VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

//возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

//изменяет количество памяти, выделенное
//под хранение элементов вектора
void reserve(vector *v, size_t new_capacity);

//удаляет элементы из контейнера,
//но не освобождает выделенную память
void clear(vector *v);

//освобождает память, выделенную под
//неиспользуемые элементы
void shrinkToFit(vector *v);

//освобождает память, выделенную вектору
void deleteVector(vector *v);

#endif //LAB_5B_VECTOR_H