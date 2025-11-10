#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student3.h"

// Test helper functions
void test_rm_space() {
    char expr[] = " 10 @ 2 + 1 0 @ 2 ";
    rm_space(expr);
    printf("[rm_space] -> '%s'\n", expr);
}

void test_find_operation() {
    char expr[] = "10@2+11@2";
    int pos = find_operation(expr);
    printf("[find_operation] -> position: %d, operator: '%c'\n", pos, expr[pos]);
}

void test_split_expressions() {
    char expr[] = "10@2+11@2";
    char left[64], right[64];
    int pos = find_operation(expr);
    split_expressions(expr, left, right, pos);
    printf("[split_expressions] -> left: '%s', right: '%s'\n", left, right);
}

void test_extract_number_base() {
    char token[] = "101.1@2";
    char number[64];
    int base;
    if (extract_number_base(token, number, &base))
        printf("[extract_number_base] -> number: '%s', base: %d\n", number, base);
    else
        printf("[extract_number_base] -> Error\n");
}

void test_parse_expression() {
    char expr[] = "101@2+10@2";
    char num1[64], num2[64], op;
    int base1, base2;
    if (parse_expression(expr, num1, &base1, num2, &base2, &op))
        printf("[parse_expression] -> num1='%s'(base %d), op='%c', num2='%s'(base %d)\n",
               num1, base1, op, num2, base2);
    else
        printf("[parse_expression] -> Parsing error for '%s'\n", expr);
}

// Test main function
void test_student3_calculate_from_file() {
    FILE* in = fopen("student3_input.txt", "r");
    if (!in) {
        printf("Error: cannot open input.txt\n");
        return;
    }

    char expression[128];
    printf("\n=== Testing student3_calculate() ===\n");
    while (fgets(expression, sizeof(expression), in)) {
        if (expression[0] == '#' || strlen(expression) < 3) continue; // skip comments and empty lines

        expression[strcspn(expression, "\n")] = 0; // remove newline

        char* result = student3_calculate(expression);
        if (result)
            printf("Expression: %-20s => Result: %s\n", expression, result);
        else
            printf("Expression: %-20s => Error (NULL)\n", expression);
    }

    fclose(in);
}

int main() {
    printf("=== Testing helper functions ===\n");
    test_rm_space();
    test_find_operation();
    test_split_expressions();
    test_extract_number_base();
    test_parse_expression();

    printf("\n=== Testing entire program ===\n");
    test_student3_calculate_from_file();

    return 0;
}