#include "student3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>




 // Remove spaces from string
 void rm_space(char* expressions){
    int i = 0, j = 0;
    while (expressions[i] != '\0'){
        if (expressions[i] != ' '){
            expressions[j] = expressions[i];
            j++;
        }
        i++;
    }
    expressions[j] = '\0';
}

// Find operator position
int find_operation(char* expressions){
    int i = 0;
    while(expressions[i] != '\0'){
        if (expressions[i] == '+' || expressions[i] == '-' || expressions[i] == '*' || expressions[i] == '/')
            return i;
        i++;
    }
    return -1; 
}

// Split expression into left and right parts
void split_expressions(char* expressions, char* left, char* right, int op_pos){
    int i = 0, j = 0, l = 0;
    while (i < op_pos){
        left[j] = expressions[i];
        i++; j++;
    }
    left[j] = '\0';

    i++;

    while (expressions[i] != '\0'){
        right[l] = expressions[i];
        i++; l++;
    }
    right[l] = '\0';
}

// Extract number and base from token (format: number@base)
int extract_number_base(const char* token, char* number, int* base){
    int j = 0; int i = 0;
    while (token[j] != '\0' && token[j] != '@'){
        number[i] = token[j];
        j++; i++;
    }
    number[i] = '\0';

    if (token[j] != '@'){
    printf("Ошибка: отстуствует '@' в выражении '%s'\n", token);
    return 0;     
    }

    j++;
    char base_str[10];
    int k = 0;
    for (; token[j] != '\0'; j++, k++){
        base_str[k] = token[j];
    }
    base_str[k] = '\0';
    *base = atoi(base_str);

    if (*base < 2 || *base > 16){
        printf("Ошибка: допустимая сс от 2 до 16\n");
        return 0;
    }
    return 1;
}


// Parse mathematical expression
int parse_expression(const char* input, 
                    char* num1_str, int* base1, 
                    char* num2_str, int* base2, 
                    char* operation){

    char expression[128];

    if (strlen(input) >= 128) {
        printf("Ошибка: строка слишком длинная\n");
        return 0;
    }
    strcpy(expression, input); 

    rm_space(expression);     

    int op_pos = find_operation(expression);
    if (op_pos == -1) {
        printf("Ошибка: не найдена операция\n");
        return 0;
    }

    *operation = expression[op_pos]; 

    char left[64], right[64];
    split_expressions(expression, left, right, op_pos);

     if (extract_number_base(left, num1_str, base1) != 1) {
        printf("Ошибка в левом операнде: %s\n", left);
        return 0;
    }
    if (extract_number_base(right, num2_str, base2) != 1) {
        printf("Ошибка в правом операнде: %s\n", right);
        return 0;
    }
    return 1; 
}


// Convert string to double in specified base
double string_to_double(const char* str, int base){
    double result = 0;
    char c; int digit;
    int found_dot = 0;
    double fract_multi = 1.0;                                                       

    for (int i = 0; str[i] != '\0'; i++){
        c = str[i];

        if (c == '.'){
            if (found_dot == 1){
                printf("ошибка: две точки в одной из чисел\n");
                return 0;
            }
            found_dot += 1;
            continue;
        }

        if (c >= '0' && c <= '9')
            digit = c - '0';
        else if (c >= 'A' && c <= 'F')
            digit = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f')
            digit = c -'a' + 10;

        else {
            printf("Ошибка: недопустимый символ '%c'\n", c);
            return 0;
        }
        if (digit >= base){
            printf("Ошибка: цифра '%c' не соответствует системе счисления %d\n", c, base);
            return 0;
        }

        if(found_dot == 1){
            fract_multi /= base;           
            result += digit * fract_multi; 
        }
        else{
            result = result * base + digit;
        }
    }
    return result;
}


// Perform arithmetic calculation
double calculate(double a, double b, char operation, int* error){
    double rez = 0;
    switch(operation){
        case '+': rez = a + b; break;
        case '-': rez = a - b; break;
        case '*': rez = a * b; break;
        case '/': 
            if(b == 0){                                                                            
                printf("Ошибка: нелья делить на 0\n");
                *error = 1;
                return 0;
            }
            rez = a / b; break;
        default:
            printf("Ошибка: неизвестная операция\n");
            *error = 1;
            return 0;
    }
    return rez;
}


// Main function
char* student3_calculate(const char* expression) {
    static char result_str[64];  // статическая строка для возврата
    char num1_str[64], num2_str[64];
    int base1, base2;
    char operation;

    if (!parse_expression(expression, num1_str, &base1, num2_str, &base2, &operation)) {
        strcpy(result_str, "Ошибка при парсинге");
        return result_str;
    }

    double num1 = string_to_double(num1_str, base1);
    double num2 = string_to_double(num2_str, base2);

    int error = 0;
    double result = calculate(num1, num2, operation, &error);
    if (error) {
        strcpy(result_str, "Ошибка вычисления");
        return result_str;
    }

    sprintf(result_str, "%g", result); 

    return result_str;
}
