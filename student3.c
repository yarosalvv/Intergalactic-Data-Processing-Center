#include "student3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void rm_spaces(char* expression){
    int i = 0, j = 0;
    while(expression[i] != '\0'){
        if(expression[i] != ' '){
            expression[j] = expression[i];
            j++;
        }
        i++;
    }
    expression[j] = '\0';
}


int find_operator_position(const char* expression){
   int i = 0;
    while (expression[i] != '\0'){
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'){          
            return i;
        }
        i++;
    }
    return -1;
}


int split_expression(const char* expression, int op_pos, char* left, char* right) {
    int i = 0;
    while (i < op_pos){
        left[i] = expression[i];
        i++;
    }
    left[i] = '\0';

    int j = 0;
    i = op_pos + 1;
    while (expression[i] != '\0') {
        right[j] = expression[i];
        j++;
        i++;
    }
    right[j] = '\0';
    return 1;
}


int parse_number_base(const char* str, char* number, int* base){
    int i = 0;
    
    if (str[0] == '\0') return 0;

    while (str[i] != '@' && str[i] != '\0'){
        number[i] = str[i];
        i++;
    }
    number[i] = '\0';
    if(str[i] != '@') return 0;
    i++;

    if (str[i] == '\0') return 0;   

    char base_str[10];
    int j = 0;
    while (str[i] != '\0'){
        base_str[j] = str[i];
        i++;
        j++;
    }
    base_str[j] = '\0';
    *base = atoi(base_str);
    return 1;
}


int string_to_int(const char* str, int base){
    int res = 0;
    for (int i = 0;str[i] != '\0';i++){
        int dig = -1;
        switch(str[i]){
            case '0': dig = 0; break;
            case '1': dig = 1; break;
            case '2': dig = 2; break;
            case '3': dig = 3; break;
            case '4': dig = 4; break;
            case '5': dig = 5; break;
            case '6': dig = 6; break;
            case '7': dig = 7; break;
            case '8': dig = 8; break;
            case '9': dig = 9; break;
            case 'A': case 'a': dig = 10; break;
            case 'B': case 'b': dig = 11; break;
            case 'C': case 'c': dig = 12; break;
            case 'D': case 'd': dig = 13; break;
            case 'E': case 'e': dig = 14; break;
            case 'F': case 'f': dig = 15; break;
            default: dig = -1;
        }
        if (dig == -1){
            return -1;
        }
        if (dig >= base){
            return -1;
        }
        res = res * base + dig;
    }
    return res;
}
        

char* student3_calculate(const char* expression){
    char expression_copy[50];
    strncpy(expression_copy, expression, 49);
    expression_copy[49] = '\0';

    rm_spaces(expression_copy);
    int op_pos = find_operator_position(expression_copy);

    if (op_pos == -1) {
        char* error = malloc(100);
        strcpy(error, "Ошибка: оператор не найден");
        return error;
    }

    char operator = expression_copy[op_pos];
    char left[50], right[50];
    split_expression(expression_copy, op_pos, left, right);

    char number1[20], number2[20] = {};
    int base1, base2;

    if (!parse_number_base(left, number1, &base1)){
        char* error = malloc(100);
        strcpy(error, "Ошибка: неверный формат первого числа");
        return error;
    }
    
    if (!parse_number_base(right, number2, &base2)){
        char* error = malloc(100);
        strcpy(error, "Ошибка: неверный формат второго числа");
        return error;
    }

    int num1 = string_to_int(number1, base1);
    int num2 = string_to_int(number2, base2);  

    int result;
    switch(operator){
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': if (num2 == 0){
                char * error = malloc(100);
                strcpy(error, "Ошибка: нельзя делить на 0!\n");    
                return error;
            }   
            result = num1 / num2; break;
        default:
            char* error = malloc(100);
            strcpy(error, "Ошибка: неизвестная операция\0");
            return error;
        }
    char* result_str = malloc(100);
    snprintf(result_str, 20, "%d", result);
    return result_str;
}


int main() {
    printf("Введите выражение в формате число@сс операция число@cc \n");
    char input[50] = {};
    scanf("%49[^\n]", input);
    
    char* result = student3_calculate(input);
    printf("Результат: %s@1016\n", result);
    free(result);
    
    return 0;
}