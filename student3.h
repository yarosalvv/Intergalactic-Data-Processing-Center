#ifndef STUDENT3_H
#define STUDENT3_H

// Объявления ВСЕХ функций, которые используются в tests.c
char* student3_calculate(const char* expression);
void rm_spaces(char* expression);
int find_operator_position(const char* expression);
int split_expression(const char* expression, int op_pos, char* left, char* right);
int parse_number_base(const char* str, char* number, int* base);
int string_to_int(const char* str, int base);

#endif
