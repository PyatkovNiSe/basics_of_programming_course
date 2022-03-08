#ifndef LAB_5B_TASKS_H
#define LAB_5B_TASKS_H

#include <stdbool.h>

// Удалить из строки все пробельные символы
void removeNonLetters(char *s);

// Преобразовать строку, оставляя только один символ в каждой
// последовательности подряд идущих одинаковых символов
void removeAdjacentEqualLetters(char *s);

// Сократить количество пробелов между
// словами данного предложения до одного
void removeExtraSpaces(char *s);

// Преобразовать строку, обратив каждое слово этой строки
void reverseWordsInString(char *s);

// Преобразовать строку, заменяя каждую цифру
// соответствующим ей числом пробелов
void replaceNumbersWithSpaces(char *s);

// Заменить все вхождения слова 𝑤1 на слово 𝑤2
void replaceWord(char *source, char *w1, char *w2);

// Определить, упорядочены ли лексикографически слова данного предложения
bool isLexicographicOrdered(char *s);

// Вывести слова данной строки в обратном порядке по одному в строке экрана
void printWordsInReverseOrder(char *s);

// Определить количество слов-палиндромов
int countPalindromeWordsSeparatedWithComma(char *s);

// Получить строку, в которой чередуются слова первой и второй строки. Если в
// одной из строк число слов больше, чем в другой, то оставшиеся слова этой
// строки должны быть дописаны в строку-результат
void makeMixedStringFromTwo(char *s1, char *s2, char *sWrite);

// Преобразовать строку, изменив порядок следования слов в строке на обратный
void reverseWordOrder(char *s);

#endif
