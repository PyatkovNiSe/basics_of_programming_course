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

// Преобразовать строку, заменяя каждую цифру
// соответствующим ей числом пробелов
void replaceNumbersWithSpaces(char *s);

// Заменить все вхождения слова 𝑤1 на слово 𝑤2
void replaceWord(char *source, char *w1, char *w2);

#endif
