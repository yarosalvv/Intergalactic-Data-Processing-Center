#include "student1.h"

#include "project.h"


void test_conversions_systems(void) {
    printf("1. TESTING TRANSFORMATIONS BETWEEN DIFFERENT SYSTEMS:\n");
    char* result;

    result = student1_process(2, 8, "11001.01");
    printf("result: %s\n", result);
    assert(strcmp(result, "31.2") == 0);  // 11010.1 = 31.2
    free(result);

    result = student1_process(8, 2, "31.2");
    printf("result: %s\n", result);
    assert(strcmp(result, "11001.01") == 0);
    free(result);

    result = student1_process(10, 16, "228.5");
    printf("result: %s\n", result);
    assert(strcmp(result, "E4.8") == 0);  // 228.5 = E4.8
    free(result);
    
    result = student1_process(16, 10, "E4.8");
    printf("result: %s\n", result);
    assert(strcmp(result, "228.5") == 0);
    free(result);
}

void test_working_fractions(void) {
    printf("2. TESTING WORK WITH FRACTIONAL NUMBERS:\n");
    char* result;

    result = student1_process(10, 4, "0.25");
    printf("result: %s\n", result);
    assert(strcmp(result, "0.1") == 0);  // 1/4
    free(result);

    result = student1_process(10, 16, "0.0625");
    printf("result: %s\n", result);
    assert(strcmp(result, "0.1") == 0);  // 1/16
    free(result);
}

void test_correct_rounding(void) {
    printf("3. TESTING ROUNDING UP TO 12 DIGITS:\n");
    char* result;

    result = student1_process(10, 2, "0.1");
    assert(result != NULL);
    printf("result: %s\n", result);

    char* fractional_part = strchr(result, '.');
    if (fractional_part != NULL) {
        int fractional_len = strlen(fractional_part + 1);
        assert(fractional_len <= 12);
    }
    free(result);

    result = student1_process(10, 2, "0.5");
    assert(result != NULL);
    printf("result: %s\n", result);
    char* back_result = student1_process(2, 10, result);
    assert(back_result != NULL);
    
    printf("Direct: 0.5 -> %s -> The reverse: %s\n", result, back_result);
    free(result);
    free(back_result);
}

void test_error(void) {
    printf("4. TESTING INPUT ERROR HANDLING:\n");
    char* result;

    result = student1_process(0, 10, "23.45");  // Another base
    assert(result == NULL);

    result = student1_process(17, 10, "233.45");  // Another base
    assert(result == NULL);

    result = student1_process(2, 10, "242");  // Numbers 2,4
    assert(result == NULL);

    result = student1_process(8, 10, "189");  // Numbers 8,9
    assert(result == NULL);

    result = student1_process(16, 10, "11Q.A");  // Letter Q
    assert(result == NULL);
}

int main(void) {
    printf("Starting student1.c testing\n\n");

    test_conversions_systems();
    test_working_fractions();
    test_correct_rounding();
    test_error();

    printf("Testing completed\n");
    return 0;

}
