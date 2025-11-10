#include "student1.h"


// Auxiliary functions:
// Converts a character to a numeric value (0-15)
int char_to_value(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    else
        return -1;
}

// Converts a numeric value (0-15) to a character
char value_to_char(int value){
    if (value >= 0 && value <= 9)
        return '0' + value;
    if (value > 9 && value < 16)
        return 'A' + (value - 10);
    return '?';
}

// Divides a string of numbers into whole and fractional parts
void split_number_string(const char* number, char* integer_part, char* fractional_part){
    const char* ppoint = strchr(number, '.');
    if (ppoint != NULL){
        int lenc = ppoint - number;
        strncpy(integer_part, number, lenc);
        integer_part[lenc] = '\0';
        strcpy(fractional_part, ppoint + 1);
    }
    else {
        strcpy(integer_part, number);
        fractional_part[0] = '\0';
    }
}


// Validation function:
// Checks that base is from 2 to 16
int validate_base(int base) {
    if (base >= 2 && base <= 16)
        return 1;
    else
        return 0;
}

// Checks valid characters for a given number system
int validate_number(const char* number, int base) {
    int len = strlen(number);
    if (len == 0 || len > 12)
        return 0;
    
// Checks that the point occurs no more than once
    int point = 0;
    for (int i = 0; i < len; i++) {
        char c = toupper(number[i]);
        if (c == '.') { 
            point ++;
            if (point > 1)
                return 0;
        }
        else {
            int valid = char_to_value(c);
            if (valid < 0 || valid >= base)
                return 0;
        }
    }
    return 1;
}


// Сonversion functions
// Divides a string into whole and fractional parts
double string_to_decimal(const char* number, int base) {
    char integer_part[16], fractional_part[16];
    split_number_string(number, integer_part, fractional_part);

    // Integer_part
    double integer = 0;
    for (int i = 0; i < strlen(integer_part); i++) {
        char c = toupper(integer_part[i]);
        int part = char_to_value(c);
        integer = integer * base + part;
    }
// Fractional_part
    double fract = 0;
    double mult = 1.0 / base;
    for (int i = 0; i < strlen(fractional_part); i++) {
        fract += mult * char_to_value(toupper(fractional_part[i]));
        mult /= base;
    }

    // Unification
    return integer + fract; 
}

// Divides a number into an integer and a fractional part
char* decimal_to_string(double number, int base, int precision) {
    if (precision > 12) precision = 12;
    long long integer_part = (long long)number;
    double fractional_part = number - integer_part;

// Integer_part
    char inter[64] = "";
    if (integer_part == 0)
        strcpy(inter, "0");
    else {
        char temp[64] = "";
        int index = 0;
        while (integer_part > 0) {
            temp[index++] = value_to_char(integer_part % base);
            integer_part /= base;
        }
        for (int i = 0; i < index; i++)
            inter[i] = temp[index - 1 - i];
        inter[index] = '\0';
    }

// Fractional_part
    char fracal[64] = "";
    if (fractional_part > 0) {
        strcpy(fracal, ".");
        int fracalindex = 1;

        for (int i = 0; i < precision && fractional_part; i++) {
            fractional_part = fractional_part * base;
            int part = (int)fractional_part;
            fracal[fracalindex++] = value_to_char(part);
            fractional_part = fractional_part - part;
        }
        fracal[fracalindex] = '\0';
    }
    
    // Unification
    int total_len = strlen(inter) + strlen(fracal) + 1;
    char* result = (char*)malloc(total_len);
    if (!result)
        return NULL;
    strcpy(result, inter);
    strcat(result, fracal);
    return result;
}

// Main function:
// Checking the validity of the input data
char* student1_process(int src_base, int dest_base, const char* number){
    if (validate_base(src_base) == 0 || validate_base(dest_base) == 0) {
        printf("Ошибка: недопустимое основание системы счисления\n");
        return NULL;
    }
    if (validate_number(number, src_base) == 0) {
        printf("Ошибка: недопустимое число для данной системы счисления\n");
        return NULL;
    }
    
    // Conversion to decimal number system
    double decimal_value = string_to_decimal(number, src_base);
    
    // Conversion to the target number system
    char* result = decimal_to_string(decimal_value, dest_base, 12);

    // Return of the result
    return result;
}
