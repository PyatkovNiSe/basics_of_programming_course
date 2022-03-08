#ifndef LAB_5B_TASKS_H
#define LAB_5B_TASKS_H


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

#endif
