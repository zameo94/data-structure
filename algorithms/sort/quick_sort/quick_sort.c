#include "quick_sort.h"

static void swap_values(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp; 
}

static int partition(int *array, int low, int high) {
    int pivot = array[low];
    int i = low;
    int j = high;

    while(i < j) {
        while(array[i] <= pivot && i <= (high - 1)) i++;
        while(array[j] > pivot && j >= (low + 1)) j--;

        if(i < j) swap_values(&array[i], &array[j]);
    }

    swap_values(&array[low], &array[j]);

    return j;
}

static void private_quick_sort(int *array, int low, int high) {
    if(low < high) {
        int pivot = partition(array, low, high);

        private_quick_sort(array, low, pivot - 1);
        private_quick_sort(array, pivot + 1, high);
    }
}

/*
 * Implementing quick sort algorithm, O(n log n)
*/
int quick_sort(int *array, size_t len) {
    if(array == NULL) return ERROR_ARRAY_NOT_ALLOCATED;
    if(len < 2) return SUCCESS;
    len = (int)len;

    private_quick_sort(array, 0, len - 1);

    return SUCCESS;
}
