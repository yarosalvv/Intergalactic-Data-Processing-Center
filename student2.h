#ifndef STUDENT2_H
#define STUDENT2_H

// 1. Cортировка
void bubble_sort_double(double* arr, int size);
// 2. Статистические функции
double calculate_mean(const double* numbers, int count);
double calculate_median_min_max(double* numbers, int count, double* min, double* max);
//3. Функции преобразования и валидации
int convert_numbers(const char** number_strings, const int* bases, int count, double* results);
int validate_and_convert_number(const char* number_str, int base, double* result);
// 4. Функции вывода
void print_sorted_results(const double* numbers, int count);
void print_statistics(double min, double max, double mean, double median);
// 5. Главная функция
void student2_analyze(const char** number_strings, const int* bases, int count);

#endif // STUDENT2_H





