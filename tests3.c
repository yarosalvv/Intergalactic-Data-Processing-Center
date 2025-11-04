#include <assert.h>
#include <string.h>
#include "student3.h"
#include <stdio.h>
#include <stdlib.h>

void test_rm_spaces() {
    char expr1[] = "A @ 16 + 15 @ 8";
    rm_spaces(expr1);
    assert(strcmp(expr1, "A@16+15@8") == 0);

    char expr2[] = "  10  @  2  *  11  @  10  ";
    rm_spaces(expr2);
    assert(strcmp(expr2, "10@2*11@10") == 0);
}

void test_find_operator_position() {
    assert(find_operator_position("A@16+15@8") == 4);
    assert(find_operator_position("10@2*11@10") == 4);
    assert(find_operator_position("1A@16-1F@16") == 5); 
    assert(find_operator_position("10@2/2@2") == 4);
    assert(find_operator_position("invalid_expression") == -1);
}

void test_split_expression() {
    char left[50], right[50];

    split_expression("A@16+15@8", 4, left, right);
    assert(strcmp(left, "A@16") == 0);
    assert(strcmp(right, "15@8") == 0);

    split_expression("10@2*11@10", 4, left, right);
    assert(strcmp(left, "10@2") == 0);
    assert(strcmp(right, "11@10") == 0);
}

void test_parse_number_base() {
    char number[20];
    int base;

    assert(parse_number_base("A@16", number, &base) == 1);
    assert(strcmp(number, "A") == 0);
    assert(base == 16);

    assert(parse_number_base("15@8", number, &base) == 1);
    assert(strcmp(number, "15") == 0);
    assert(base == 8);

    assert(parse_number_base("invalid", number, &base) == 0);
}

void test_string_to_int() {
    assert(string_to_int("A", 16) == 10);
    assert(string_to_int("F", 16) == 15);
    assert(string_to_int("1010", 2) == 10);
    assert(string_to_int("1F", 16) == 31);
    assert(string_to_int("invalid", 16) == -1);
}

void test_student3_calculate() {
    char* result;

    result = student3_calculate("A@16 + 15@8");
    assert(strcmp(result, "23") == 0);  s
    free(result);

    result = student3_calculate("10@2 * 11@10");
    assert(strcmp(result, "22") == 0);  
    free(result);

    result = student3_calculate("1A@16 - 1F@16");
    assert(strcmp(result, "-5") == 0);  
    free(result);

    result = student3_calculate("10@2 / 2@2");
    assert(strcmp(result, "1") == 0);  
    free(result);

    result = student3_calculate("10@2 / 0@10");
    assert(strstr(result, "Ошибка: нельзя делить на 0") != NULL);  
    free(result);

    result = student3_calculate("invalid_expression");
    assert(strstr(result, "Ошибка: оператор не найден") != NULL);
    free(result);

    result = student3_calculate("F@16 + 1@16");
    assert(strcmp(result, "16") == 0);  
    free(result);

    result = student3_calculate("  A@16   +   5@10  ");
    assert(strcmp(result, "15") == 0);  
    free(result);
}

int main() {
    test_rm_spaces();
    test_find_operator_position();
    test_split_expression();
    test_parse_number_base();
    test_string_to_int();
    test_student3_calculate();
    
    printf("✅ Все тесты прошли успешно!\n");
    return 0;
}