#include <stdio.h>
#include "merge_sort/merge_sort.h"
#include "bubble_sort/bubble_sort.h"

// Setup Errors code
#define ERROR_ARRAY_NOT_ALLOCATED -11

// Input Error
#define ERROR_INVALID_LENGTH -30

// Success code
#define SUCCESS 0

typedef int (*sort_func_t)(int *, size_t);

void test_algorithm(int *array, size_t len, char *alg_type, sort_func_t sort_function) {
    printf("%s: Array before sorting:\n", alg_type);

    for(size_t i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int result = sort_function(array, len);

    if(result == ERROR_ARRAY_NOT_ALLOCATED) {
        printf("Error: Invalid array.\n");
    } else if(result == ERROR_INVALID_LENGTH) {
        printf("Error: Invalid array length.\n");
    } else if(result == SUCCESS) {
        printf("Array sorted:\n");

        for(size_t i = 0; i < len; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
}

int main(void) {
    int buble_sort_array[] = { 65, 6, 3, 9, 32, 10 };
    int merge_sort_array[] = { 65, 6, 3, 9, 32, 10 };
    size_t len = sizeof(buble_sort_array) / sizeof(buble_sort_array[0]);

    test_algorithm(buble_sort_array, len, "Bubble Sort", bubble_sort);
    test_algorithm(merge_sort_array, len, "Merge Sort", merge_sort);

    return 0;
}
