#ifndef STUDENT1_H
#define STUDENT1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 1. Функции валидации
int validate_base(int base);
int validate_number(const char* number, int base);

// 2. Функции преобразования
double string_to_decimal(const char* number, int base);
char* decimal_to_string(double number, int base, int precision);

// 3. Вспомогательные функции
int char_to_value(char c);
char value_to_char(int value);
void split_number_string(const char* number, char* integer_part, char* fractional_part);

// 4. Главная функция
char* student1_process(int src_base, int dest_base, const char* number);

#endif // STUDENT1_H