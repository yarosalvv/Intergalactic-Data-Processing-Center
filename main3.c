#include "student3.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    printf("Введите выражение в формате число@сс операция число@cc \n");
    char input[50] = {};
    scanf("%49[^\n]", input);
    
    char* result = student3_calculate(input);
    printf("Результат: %s\n", result);
    free(result);
    
    return 0;
}
