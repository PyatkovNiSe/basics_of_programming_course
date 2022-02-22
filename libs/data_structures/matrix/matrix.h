#ifndef LAB5D_MATRIX_H
#define LAB5D_MATRIX_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct matrix {
    int **values;
    int nRows;
    int nCols;
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

//размещает в динамической памяти матрицу размером nRows на nCols
matrix getMemMatrix(int nRows, int nCols);

//размещает в динамической памяти массив из
//nMatrices матриц размером nRows на nCols
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

//освобождает память, выделенную под хранение матрицы m
void freeMemMatrix(matrix m);

//освобождает память, выделенную под
//хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices);

//ввод матрицы m
void inputMatrix(matrix m);

//ввод массива из nMatrices матриц, хранящейся по адресу ms
void inputMatrices(matrix *arrayOfMatrices, int nMatrices);

//вывод матрицы m
void outputMatrix(matrix m);

//вывод массива из nMatrices матриц, хранящейся по адресу ms
void outputMatrices(const matrix *arrayOfMatrices, int nMatrices);

//обмен строк с порядковыми номерами i1 и i2 в матрице m
void swapRows(matrix m, int i, int j);

//обмен колонок с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix m, int i, int j);

//сортитрует строки матрицы m по неубыванию значения
//функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(const int *, int));

//сортитрует строки матрицы m по неубыванию значения
//функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                           float (*criteria)(const int *, int));

//сортирует столбцы матрицы m по неубыванию значения
//функции criteria применяемой для столбцов
void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(const int *, int));

//возвращает значение ’истина’, если
//матрица m является квадратной
bool isSquareMatrix(matrix m);

//возвращает значение ’истина’, если матрицы m1 и m2 равны
bool areTwoMatricesEqual(matrix m1, matrix m2);

//возвращает значение ’истина’, если
//матрица m является единичной
bool isEMatrix(matrix m);

//возвращает значение ’истина’, если
//матрица m является симметричной
bool isSymmetricMatrix(matrix m);

//транспонирует квадратную матрицу m
void transposeSquareMatrix(matrix m);

//возвращает позицию минимального элемента матрицы m
position getMinValuePos(matrix m);

//возвращает позицию максимального элемента матрицы m
position getMaxValuePos(matrix m);

//возвращает матрицу, размера nRows на nCols,
//построенного из элементов массива a
matrix createMatrixFromArray(const int *values,
                             int nRows, int nCols);

//возвращает указатель на нулевую матрицу массива из
//nMatrices матриц построенных из элементов массива a
matrix *createArrayOfMatricesFromArray(const int *values,
                                       int nMatrices,
                                       int nRows, int nCols);

matrix multiplyMatrices(matrix m1, matrix m2);

#endif //LAB5D_MATRIX_H
