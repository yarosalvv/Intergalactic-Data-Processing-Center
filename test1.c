#include "student1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

void test_conversions_systems(void);
void test_working_fractions(void);
void test_correct_rounding(void);
void test_error(void);

void test_conversions_systems(void) {
    printf("1. ТЕСТИРОВАНИЕ ПРЕОБРАЗОВАНИЙ МЕЖДУ РАЗНЫМИ СИСТЕМАМИ:\n");
    char* result;

    result = student1_process(2, 8, "11001.01");
    printf("Результат: %s\n", result);
    assert(strcmp(result, "31.2") == 0);  // 11010.1 = 31.2
    free(result);

    result = student1_process(8, 2, "31.2");
    printf("Результат: %s\n", result);
    assert(strcmp(result, "11010.1") == 0);
    free(result);

    result = student1_process(10, 16, "228.5");
    printf("Результат: %s\n", result);
    assert(strcmp(result, "E4.8") == 0);  // 228.5 = E4.8
    free(result);
    
    result = student1_process(16, 10, "E4.8");
    printf("Результат: %s\n", result);
    assert(strcmp(result, "228.5") == 0);
    free(result);
}

void test_working_fractions(void) {
    printf("2. ТЕСТИРОВАНИЕ РАБОТЫ С ДРОБНЫМИ ЧИСЛАМИ:\n");
    char* result;

    result = student1_process(10, 4, "0.25");
    printf("Результат: %s\n", result);
    assert(strcmp(result, "0.1") == 0);  // 1/4
    free(result);

    result = student1_process(10, 16, "0.0625");
    printf("Результат: %s\n", result);
    assert(strcmp(result, "0.1") == 0);  // 1/16
    free(result);
}

void test_correct_rounding(void) {
    printf("3. ТЕСТИРОВАНИЕ ОКРУГЛЕНИЯ ДО 12 ЗНАКОВ:\n");
    char* result;

    result = student1_process(10, 2, "0.1");
    assert(result != NULL);
    printf("Результат: %s\n", result);

    char* fractional_part = strchr(result, '.');
    if (fractional_part != NULL) {
        int fractional_len = strlen(fractional_part + 1);
        assert(fractional_len <= 12);
    }
    free(result);

    result = student1_process(10, 2, "125.1515151599");
    printf("Результат: %s\n", result);
    char* back_result = student1_process(2, 10, result);
    assert(back_result != NULL);
    

    printf("Прямое: 125.1515151599 -> %s -> Обратное: %s\n", result, back_result);
    free(result);
    free(back_result);
}

void test_error(void) {
    printf("4. ТЕСТИРОВАНИЕ ОБРАБОТКИ ОШИБОК ВВОДА:\n");
    char* result;

    result = student1_process(0, 10, "23.45");
    assert(result == NULL);

    result = student1_process(17, 10, "233.45");
    assert(result == NULL);

    result = student1_process(2, 10, "242");    // Цифра 2,4
    assert(result == NULL);

    result = student1_process(8, 10, "189");    // Цифры 8,9
    assert(result == NULL);

    result = student1_process(16, 10, "11Q.A"); // Буква Q
    assert(result == NULL);
}

int main() {
    test_conversions_systems();
    test_working_fractions();
    test_correct_rounding();
    test_error();

    return 0;
}