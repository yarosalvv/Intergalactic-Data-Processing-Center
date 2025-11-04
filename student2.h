#ifndef STUDENT2_H
#define STUDENT2_H

// Sorting
void bubble_sort_double(double* arr, int size);

// Statistical functions
double calculate_mean(const double* numbers, int count);
double calculate_median(double* numbers, int count);
void find_min_max(const double* numbers, int count, double* min, double* max);

// Conversion and validation functions
int convert_numbers(const char** number_strings, const int* bases, int count, double* results);
int validate_and_convert_number(const char* number_str, int base, double* result);

// Output functions
void print_sorted_results(const double* numbers, int count);
void print_statistics(double min, double max, double mean, double median);

// Main function
void student2_analyze(const char** number_strings, const int* bases, int count);

#endif // STUDENT2_H





