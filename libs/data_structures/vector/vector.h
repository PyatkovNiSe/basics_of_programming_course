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
void reserve(vector *v, size_t newCapacity);

//удаляет элементы из контейнера,
//но не освобождает выделенную память
void clear(vector *v);

//освобождает память, выделенную под
//неиспользуемые элементы
void shrinkToFit(vector *v);

//освобождает память, выделенную вектору
void deleteVector(vector *v);

//проверяет на то, является ли вектор пустым
bool isEmpty(const vector *v);

//проверяет на то, является ли вектор полным
bool isFull(const vector *v);

//возвращает i-ый элемент вектора v
int getVectorValue(const vector *v, size_t i);

//добавляет элемент x в конец вектора v
void pushBack(vector *v, int x);

//удаляет последний элемент из вектора
void popBack(vector *v);

//возвращает указатель на index-ый элемент вектора
int *atVector(const vector *v, size_t index);

//возвращает указатель на последний элемент вектора
int *back(const vector *v);

//возвращает указатель на последний элемент вектора
int *front(const vector *v);

#endif //LAB_5B_VECTOR_H