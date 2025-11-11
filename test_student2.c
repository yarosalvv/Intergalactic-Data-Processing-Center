#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "student2.h"

// An auxiliary function for comparing with floating-point error
int double_equals(double a, double b, double epsilon) {
    return fabs(a - b) < epsilon;
}

void test_bubble_sort() {
    printf("=== Testing sorting ===\n");
    
    // Array of 1 element
    double arr1[] = {5.0};
    bubble_sort_double(arr1, 1);
    printf("Array of 1 element: %.1f - ", arr1[0]);
    if (double_equals(arr1[0], 5.0, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    // Array of 5 elements
    double arr3[] = {5.0, 2.0, 4.0, 1.0, 3.0};

    bubble_sort_double(arr3, 5);

    int sorted3 = 1;

    for (int i = 0; i < 4; i++) 
        if (arr3[i] > arr3[i+1]) 
              sorted3 = 0;
    
    printf("Array of 5 elements: %.1f,%.1f,%.1f,%.1f,%.1f - ",
           arr3[0], arr3[1], arr3[2], arr3[3], arr3[4]);
    if (sorted3)
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    // Sorted array
    double arr4[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    bubble_sort_double(arr4, 5);
    int sorted4 = 1;
    for (int i = 0; i < 4; i++) 
        if (arr4[i] > arr4[i+1]) 
              sorted4 = 0;
    
    printf("Sorted array - ");
    if (sorted4)
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    printf("\n");
}

void test_statistical_functions() {
    printf("=== Testing statistical functions ===\n");
    
    // Basic set
    double test1[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double min, max;
    
    find_min_max(test1, 5, &min, &max);
    double mean1 = calculate_mean(test1, 5);
    double median1 = calculate_median(test1, 5);
    
    printf("Set [1,2,3,4,5]:\n");
    printf("  Mean: %.1f (expected 3.0) - ", mean1);
    if (double_equals(mean1, 3.0, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    printf("  Median: %.1f (expected 3.0) - ", median1);
    if (double_equals(median1, 3.0, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    printf("  Min: %.1f (expected 1.0) - ", min);
    if (double_equals(min, 1.0, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    printf("  Max: %.1f (expected 5.0) - ", max);
    if (double_equals(max, 5.0, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    // Even number of elements
    double test2[] = {1.0, 2.0, 3.0, 4.0};
    bubble_sort_double(test2, 4); // Sort for median
    find_min_max(test2, 4, &min, &max);
    double mean2 = calculate_mean(test2, 4);
    double median2 = calculate_median(test2, 4);
    
    printf("Set [1,2,3,4]:\n");
    printf("  Mean: %.1f (expected 2.5) - ", mean2);
    if (double_equals(mean2, 2.5, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    printf("  Median: %.1f (expected 2.5) - ", median2);
    if (double_equals(median2, 2.5, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    printf("  Min: %.1f (expected 1.0) - ", min);
    if (double_equals(min, 1.0, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    printf("  Max: %.1f (expected 4.0) - ", max);
    if (double_equals(max, 4.0, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    // Negative numbers
    double test3[] = {-2.0, -1.0, 0.0, 1.0, 2.0};
    bubble_sort_double(test3, 5);
    find_min_max(test3, 5, &min, &max);
    double mean3 = calculate_mean(test3, 5);
    double median3 = calculate_median(test3, 5);
    
    printf("Set [-2,-1,0,1,2]:\n");
    printf("  Mean: %.1f (expected 0.0) - ", mean3);
    if (double_equals(mean3, 0.0, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    printf("  Median: %.1f (expected 0.0) - ", median3);
    if (double_equals(median3, 0.0, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    printf("  Min: %.1f (expected -2.0) - ", min);
    if (double_equals(min, -2.0, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    printf("  Max: %.1f (expected 2.0) - ", max);
    if (double_equals(max, 2.0, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    printf("\n");
}

void test_validation_and_conversion() {
    printf("=== Testing validation and conversion ===\n");
    
    double result;
    
    // Valid decimal numbers
    printf("Valid decimal numbers:\n");
    int test1 = validate_and_convert_number("123", 10, &result);
    printf("  '123' base 10: %.1f - ", result);
    if (test1 && double_equals(result, 123.0, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    int test2 = validate_and_convert_number("45.67", 10, &result);
    printf("  '45.67' base 10: %.2f - ", result);
    if (test2 && double_equals(result, 45.67, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    // Valid hexadecimal numbers
    printf("Valid hexadecimal numbers:\n");
    int test3 = validate_and_convert_number("FF", 16, &result);
    printf("  'FF' base 16: %.1f - ", result);
    if (test3 && double_equals(result, 255.0, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    int test4 = validate_and_convert_number("A.8", 16, &result);
    printf("  'A.8' base 16: %.2f - ", result);
    if (test4 && double_equals(result, 10.5, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    // Valid binary numbers
    printf("Valid binary numbers:\n");
    int test5 = validate_and_convert_number("1010", 2, &result);
    printf("  '1010' base 2: %.1f - ", result);
    if (test5 && double_equals(result, 10.0, 0.001))
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    // Invalid numbers
    printf("Invalid numbers:\n");
    int test6 = validate_and_convert_number("12G", 10, &result);
    printf("  '12G' base 10: ");
    if (!test6)
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    int test7 = validate_and_convert_number("5", 2, &result);
    printf("  '5' base 2: ");
    if (!test7)
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    int test8 = validate_and_convert_number("12.34.56", 10, &result);
    printf("  '12.34.56' base 10: ");
    if (!test8)
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    printf("\n");
}

void test_invalid_records() {
    printf("=== Testing invalid records processing ===\n");
    
    const char* valid_strings[] = {"10", "20", "30"};
    const int valid_bases[] = {10, 10, 10};
    
    const char* invalid_strings[] = {"10", "2G", "30"}; // Second string is invalid
    const int invalid_bases[] = {10, 10, 10};
    
    double results[3];
    
    // All valid records
    int count1 = convert_numbers(valid_strings, valid_bases, 3, results);
    printf("All valid records: count=%d - ", count1);
    if (count1 == 3)
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    // One invalid record
    int count2 = convert_numbers(invalid_strings, invalid_bases, 3, results);
    printf("One invalid record: count=%d - ", count2);
    if (count2 == -1)
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    printf("\n");
}

void test_integration() {
    printf("=== Integration testing ===\n");
    
    // Full workflow
    const char* numbers[] = {"15", "5", "10", "20"};
    const int bases[] = {10, 10, 10, 10};
    
    printf("Full test with numbers [15,5,10,20]:\n");
    student2_analyze(numbers, bases, 4);
    printf(" - Expected sorted array: 5.0 10.0 15.0 20.0\n");
    printf(" - Expected Min:5.0, Max:20.0, Mean:12.5, Median:12.5\n\n");
    
    // Mixed numeral systems
    const char* mixed_numbers[] = {"1010", "A", "12"};
    const int mixed_bases[] = {2, 16, 10};
    
    printf("Test with mixed numeral systems [1010(bin),A(hex),12(dec)]:\n");
    student2_analyze(mixed_numbers, mixed_bases, 3);
    printf(" - All numbers should be 10.0, 10.0, 12.0\n\n");
}

int main() {
    printf("Starting student2.c testing\n\n");
    
    test_bubble_sort();
    test_statistical_functions();
    test_validation_and_conversion();
    test_invalid_records();
    test_integration();
    
    printf("Testing completed\n");
    return 0;
}