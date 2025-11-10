#ifndef STUDENT3_H
#define STUDENT3_H

void rm_space(char* expressions);
int find_operation(char* expressions);
void split_expressions(char* expressions, char* left, char* right, int op_pos);
int extract_number_base(const char* token, char* number, int* base);
int parse_expression(const char* input, 
                     char* num1_str, int* base1, 
                     char* num2_str, int* base2, 
                     char* operation);
double string_to_double(const char* str, int base);
double calculate(double a, double b, char operation, int* error);
char* student3_calculate(const char* expression);

#endif
