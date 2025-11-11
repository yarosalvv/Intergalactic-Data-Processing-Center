#include "project.h"
#include "student2.h"

// Bubble Sort Algorithm
void bubble_sort_double(double* sort_arr, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1 ; j++)
            // Swap if current element is bigger than next
            if (*(sort_arr + j) > *(sort_arr + j + 1)) {
                // Swap elements using temporary variable
                double temp = *(sort_arr + j);
                *(sort_arr + j) = *(sort_arr + j + 1);
                *(sort_arr + j + 1) = temp; 
            }    
}

// Calculate average value
double calculate_mean(const double* numbers, int count) {
    double sum = 0.0;

    for (int i = 0; i < count; i++)
        sum += *(numbers + i);

    return sum / count;
}

// Find middle value in sorted array
double calculate_median(double* numbers, int count) {
    double median;
    int center = (int)(count / 2);

    // For even count - average of two middle values
    if (count % 2 == 0)
        median = (*(numbers + center) + *(numbers + center - 1)) / 2;
    // For odd count - take middle value
    else
        median = *(numbers + center);
    
    return median;
}

// Find minimum and maximum values
void find_min_max(const double* numbers, int count, double* min, double* max) {
    // Array is sorted, so min is first, max is last
    *min = *(numbers + 0);
    *max = *(numbers + count - 1);
}

// Convert strings to numbers with given base
int convert_numbers(const char** number_strings, const int* bases, int count, double* results) {
    int success_count = 0;

    for (int i = 0; i < count; i++) {
        double temp_result;

        // Try to convert each number
        int success = validate_and_convert_number(*(number_strings + i), *(bases + i), &temp_result);

        if (success) {
            // Store successful conversion
            *(results + success_count) = temp_result;
            success_count++;
        }    
        else {
            // Return error if any conversion fails
            return -1;
        }
    }
    return success_count;
}

// Validate and convert number string
int validate_and_convert_number(const char* number_str, int base, double* result) {
    int i = 0;

    double integer_part = 0;
    int pow_i_part = 0;

    double fractional_part = 0;
    int pow_f_part = 0;

    int point = 0;
    int valid = 0;

    char symbol;

    // Count digits before point
    while (*(number_str + i) != '\0' && *(number_str + i) != '.') {
        pow_i_part++;
        i++;
    }

    i = 0;
    // Process each character in string
    while ((symbol = *(number_str + i)) != '\0') {
        int digit;

        // Handle decimal point
        if (symbol == '.') {
            point++;
            // Invalid if multiple points or point at start
            if (point > 1 || i == 0){
                valid = 1;
                break;
            }
            i++;
            continue;
        }
        // Handle letters (for bases > 10)
        else if (isalpha(symbol)) {
            if (symbol >= 'A' && symbol <= 'F')
                digit = 10 + (symbol - 'A');
            else if (symbol >= 'a' && symbol <= 'f')
                digit = 10 + (symbol - 'a');
            else {
                valid = 1;
                break;
            }
        }
        // Handle digits
        else if (isdigit(symbol))
            digit = symbol - '0';
        else {
            valid = 1;
            break;
        }
        
        // Check if digit is valid for given base
        if (digit >= base) {
            valid = 1;
            break;
        }

        // Convert digit to value
        if (point == 0) {
            pow_i_part--;
            integer_part += digit * pow(base, pow_i_part);
        } 
        else {
            pow_f_part--;
            fractional_part += digit * pow(base, pow_f_part);
        }

        i++;
    }
    
    // Return result if valid
    if (valid == 1)
        return 0;
    else {
        *result = integer_part + fractional_part;
        return 1;
    }
}

// Print sorted array
void print_sorted_results(const double* numbers, int count) {
    printf("massiv: ");
    for (int i = 0; i < count; i++)
        printf("%lf ", *(numbers + i));
    printf("\n");
}

// Print statistical results
void print_statistics(double min, double max, double mean, double median) {
    printf("Min: %lf, Max: %lf, Mean: %lf, Median: %lf", min, max, mean, median);
}

// Main analysis function
void student2_analyze(const char** number_strings, const int* bases, int count) {
    // Check input parameters
    if (number_strings == NULL || bases == NULL || count <= 0) {
        printf("Error: Invalid input parameters\n");
        return;
    }

    double min, max; 
    double* results = (double*)malloc(count * sizeof(double));

    //Checking to allocate memory
    if (results == NULL) {
        printf("Error: Memory allocation failed");
        return;
    }

    // Convert numbers
    int num = convert_numbers(number_strings, bases, count, results);

    if (num == -1) {
        printf("Error: Incorrect input data");

        free(results);
        return;
    }

    // Sort and analyze
    bubble_sort_double(results, num);
    find_min_max(results, num, &min, &max);
    double median = calculate_median(results, num);
    double mean = calculate_mean(results, num);

    // Print results
    print_sorted_results(results, num);
    print_statistics(min, max, mean, median);

    // Free allocated memory
    free(results);
}