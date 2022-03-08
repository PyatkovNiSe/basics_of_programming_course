#ifndef LAB_5B_STRING__H
#define LAB_5B_STRING__H

#include <stdlib.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

static char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

// возвращает количество символов в строке
size_t strlen(const char *begin);

// возвращает указатель на первый элемент с кодом ch,
// расположенным на ленте памяти междуадресами begin
// и end не включая end
char *find(char *begin, const char *end, int ch);

// возвращает указатель на первый символ, отличный
// от пробельных, расположенный на ленте памяти,
// начиная с begin и заканчивая ноль-символом.
char *findNonSpace(char *begin);

// возвращает указатель на первый пробельный символ,
// расположенный на ленте памяти начиная с адреса
// begin или на первый ноль-символ
char *findSpace(char *begin);

// возвращает указатель на первый справа символ,
// отличный от пробельных, расположенный на ленте
// памяти, начиная с rbegin и заканчивая rend
char *findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает указатель на первый пробельный символ справа,
// расположенный на ленте памяти, начиная с rbegin и
// заканчивая rend
char *findSpaceReverse(char *rbegin, const char *rend);

// возвращает отрицательное значение, если lhs располагается
// до rhs как в словаре, значение 0, если lhs и rhs равны,
// иначе – положительное значение
int strcmp(const char *lhs, const char *rhs);

// записывает по адресу beginDestination фрагмент памяти, начиная
// с адреса beginSource до endSource. Возвращает указатель
// на следующий свободный фрагмент памяти в destination
char *copy(char *beginSource, const char *endSource,
           char *beginDestination);

// записывает по адресу beginDestination элементы из фрагмента
// памяти начиная с beginSource заканчивая endSource, удовлетворяющие
// функции-предикату f. Возвращает указатель на следующий
// свободный для записи фрагмент в памяти
char *copyIf(const char *beginSource, const char *endSource,
             char *beginDestination, bool (*f)(int));

// записывает по адресу beginDestination элементы из фрагмента
// памяти начиная с rbeginSource заканчивая rendSource, удовлетворяющие
// функции-предикату f. Возвращает значение beginDestination по
// окончанию работы функции
char *copyIfReverse(const char *rbeginSource, const char *rendSource,
                    char *beginDestination, bool (*f)(int));

char *getEndOfString(char *str);

// возвращает значение 0, если слово не было считано, в противном
// случае будет возвращено значение 1 и в переменную word типа WordDescriptor
// будут записаны позиции начала слова, и первого символа после конца слова
bool getWord(char *beginSearch, WordDescriptor *word);

// возвращает значение 0, если слово не было считано, в противном
// случае будет возвращено значение 1 и в переменную word типа WordDescriptor
// будут записаны позиции конца слова, и первого символа после начала слова
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

#endif