#include "bubble_sort.h"

static void swap_values(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp; 
}

/*
 * Implementing bubble sort algorithm, O(n^2)
*/
int bubble_sort(int *array, size_t len) {
    if(array == NULL) return ERROR_ARRAY_NOT_ALLOCATED;
    if(len < 2) return SUCCESS;

    for(size_t i = 0; i < len; i++) {
        bool swapped = false;

        for(size_t j = 0; j < len - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                swap_values(&array[j], &array[j + 1]);
                swapped = true;
            }
        }

        // If no swap happened, the array is already sorted
        if(!swapped) break;
    }

    return SUCCESS;
}
