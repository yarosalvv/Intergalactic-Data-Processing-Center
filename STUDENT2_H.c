// student2.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "student2.h"

// 1. Функции работы с массивами
void bubble_sort_double(double* sort_arr, int size){

    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1 ; j++)
            if (*(sort_arr + j) > *(sort_arr + j + 1)) {

                double temp = *(sort_arr + j);
                *(sort_arr + j) = *(sort_arr + j + 1);
                *(sort_arr + j + 1) = temp; 
            }    
        
}


// 2. Статистические функции
double calculate_mean(const double* numbers, int count) {
    double sum = 0.0;

    for (int i = 0; i < count; i++)
        sum += *(numbers + i);

    double mean = (double)(sum / count);

    return mean;
}


double calculate_median_min_max(double* numbers, int count, double* min, double* max) {
    double median;
    int center = (int)(count / 2);

    if (count % 2 == 0)
        median = (*(numbers + center) + *(numbers + center - 1)) / 2;
    else
        median = *(numbers + center);


    * min = *(numbers + 0);
    * max = *(numbers + count - 1);


    return median;
}



// 3. Функции преобразования и валидации

int convert_numbers(const char** number_strings, const int* bases, int count, double* results) {
    int success_count = 0;

    for (int i = 0; i < count; i++) {
        double temp_result;
        int num = validate_and_convert_number(*(number_strings + i), *(bases + i), &temp_result);
        if (num) {
            *(results + success_count) = temp_result;

            success_count++;
        else
            return -1;
        }
    }
    return success_count;
}

int validate_and_convert_number(const char* number_str, int base, double* result) {
    int i = 0;

    double integer_part = 0;
    int pow_i_part = 0;

    double fractional_part = 0;
    int pow_f_part = 0;

    int point = 0;
    int valid = 0;

    char symbol;

    // find the numder of digits before the point
    while (*(number_str + i)  != '\0' && *(number_str + i)  != '.') {
        pow_i_part++;
        i++;
    }

    i = 0;
    // check validate and conversion algorithm
    while ((symbol = *(number_str + i))  != '\0') {
        int digit;

        if (symbol == '.') {
            point++;

            if (point > 1){
                valid = 1;
                break;
            }

            i++;
            continue;
        }
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
        else if (isdigit(symbol))
            digit = symbol - '0';

        else {
            valid = 1;
            break;
        }

        if (digit >= base) {
            valid = 1;
            break;
        }

        //conversion algorithm
        if (point == 0) {
            pow_i_part--;
            integer_part += digit * pow(base, pow_i_part);
        } else {
            pow_f_part--;
            fractional_part += digit * pow(base, pow_f_part);
        }


        i++;
    }
    // validation check
    if (valid == 1)
        return 0;
    else {
        * result = integer_part + fractional_part;
        return 1;
    }
}

// 4. Функции вывода
void print_sorted_results(const double* numbers, int count) {
    printf("massiv: ");

    for (int i = 0; i < count; i++)
        printf("%lf ", *(numbers + i));

    puts("");
}

void print_statistics(double min, double max, double mean, double median) {
    printf("Min: %lf,", min);
    printf(" Max: %lf,",max);
    printf(" Mean: %lf,",mean);
    printf(" Median: %lf",median);
}

// 5. Главная функция
void student2_analyze(const char** number_strings, const int* bases, int count){
    double min, max; 
    double* results = (double*)malloc(count * sizeof(double));

    int num = convert_numbers(number_strings, bases, count, results);
    if (num == -1){
        printf("Error: Incorrect input data");
        return;
    }

    bubble_sort_double(results, num);

    double median = calculate_median_min_max(results, num, &min, &max);
    double mean = calculate_mean(results, num);

    print_sorted_results(results, num);
    print_statistics(min, max, mean, median);

    free(results);
}

