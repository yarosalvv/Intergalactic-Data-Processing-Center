#include "project.h"
#include "student1.h"
#include "student2.h"
#include "student3.h"

void print_menu() {
    printf("\n=== Intergalactic Data Processing Center ===\n");
    printf("1. Convert numbers between numeral systems (student1)\n");
    printf("2. Analyze arrays of numbers (student2)\n");
    printf("3. Calculate expressions with different bases (student3)\n");
    printf("4. Run all tests\n");
    printf("5. Exit\n");
    printf("Choose option: ");
}

void student1_demo() {
    printf("\n--- Number System Conversion ---\n");
    
    char number[64];
    int src_base, dest_base;
    
    printf("Enter source base (2-16): ");
    scanf("%d", &src_base);
    printf("Enter destination base (2-16): ");
    scanf("%d", &dest_base);
    printf("Enter number: ");
    scanf("%s", number);
    
    char* result = student1_process(src_base, dest_base, number);
    if (result) {
        printf("Result: %s\n", result);
        free(result);
    } else {
        printf("Conversion failed!\n");
    }
}

void student2_demo() {
    printf("\n--- Array Analysis ---\n");
    
    int count;
    printf("Enter number of elements: ");
    scanf("%d", &count);
    
    if (count <= 0) {
        printf("Invalid count!\n");
        return;
    }
    
    const char** numbers = malloc(count * sizeof(char*));
    int* bases = malloc(count * sizeof(int));
    
    printf("Enter numbers and their bases:\n");
    for (int i = 0; i < count; i++) {
        numbers[i] = malloc(64 * sizeof(char));
        printf("Number %d: ", i + 1);
        scanf("%s", (char*)numbers[i]);
        printf("Base for %s: ", numbers[i]);
        scanf("%d", &bases[i]);
    }
    
    printf("\nAnalysis results:\n");
    student2_analyze(numbers, bases, count);
    
    // Cleanup
    for (int i = 0; i < count; i++) {
        free((char*)numbers[i]);
    }
    free(numbers);
    free(bases);
}

void student3_demo() {
    printf("\n--- Expression Calculator ---\n");
    
    char expression[128];
    printf("Enter expression (format: number@base+number@base): ");
    getchar(); // Clear buffer
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0; // Remove newline
    
    char* result = student3_calculate(expression);
    printf("Result: %s\n", result);
}

void run_all_tests() {
    printf("\n=== Running All Tests ===\n");
    
    // Test student1
    printf("\n--- Testing Student1 (Number Conversion) ---\n");
    char* test1 = student1_process(10, 16, "255");
    printf("255 (10) -> %s (16) - %s\n", test1, strcmp(test1, "FF") == 0 ? "PASS" : "FAIL");
    free(test1);
    
    char* test2 = student1_process(2, 10, "1101");
    printf("1101 (2) -> %s (10) - %s\n", test2, strcmp(test2, "13") == 0 ? "PASS" : "FAIL");
    free(test2);
    
    // Test student2
    printf("\n--- Testing Student2 (Array Analysis) ---\n");
    const char* test_nums[] = {"10", "5", "15", "20"};
    const int test_bases[] = {10, 10, 10, 10};
    printf("Testing with [10,5,15,20] (base 10)...\n");
    student2_analyze(test_nums, test_bases, 4);
    
    // Test student3
    printf("\n--- Testing Student3 (Expression Calculator) ---\n");
    char* test3 = student3_calculate("10@10+5@10");
    printf("10@10+5@10 = %s - %s\n", test3, strcmp(test3, "15") == 0 ? "PASS" : "FAIL");
    
    char* test4 = student3_calculate("A@16+5@10");
    printf("A@16+5@10 = %s\n", test4);
    
    printf("\nAll tests completed!\n");
}

int main() {
    printf("Welcome to Intergalactic Data Processing Center! \n");
    
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                student1_demo();
                break;
            case 2:
                student2_demo();
                break;
            case 3:
                student3_demo();
                break;
            case 4:
                run_all_tests();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);
    
    return 0;
}