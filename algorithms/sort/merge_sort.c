#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Setup Errors code
#define ERROR_ARRAY_NOT_ALLOCATED -11

// Input Error
#define ERROR_INVALID_LENGTH -30

// Success code
#define SUCCESS 0

static void private_merge(int *array, size_t left, size_t medium, size_t right) {
    assert(array != NULL);
    assert(left <= medium && medium <= right);

    size_t i, j, k;
    size_t n1 = medium - left + 1;
    size_t n2 = right - medium;

    int *L = malloc(sizeof(int) * n1);
    int *R = malloc(sizeof(int) * n2);

    for(i = 0; i < n1; i++) L[i] = array[left + i];
    for(j = 0; j < n2; j++) R[j] = array[medium + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

static void private_merge_sort(int *array, size_t left, size_t right) {
    if(left < right) {
        size_t medium = left + (right - left) / 2;

        private_merge_sort(array, left, medium);
        private_merge_sort(array, medium + 1, right);

        private_merge(array, left, medium, right);
    }
}

/*
 * Implementing merge sort algorithm, O(n log n)
*/
int merge_sort(int *array, size_t len) {
    if(array == NULL) return ERROR_ARRAY_NOT_ALLOCATED;
    if(len < 2) return SUCCESS;

    private_merge_sort(array, 0, len - 1);

    return SUCCESS;
}

int main(void) {
    int my_array[] = { 65, 6, 3, 9, 32, 10 };
    size_t len = sizeof(my_array) / sizeof(my_array[0]);

    printf("Array before sorting:\n");

    for(size_t i = 0; i < len; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");

    int result = merge_sort(my_array, len);

    if(result == ERROR_ARRAY_NOT_ALLOCATED) {
        printf("Error: Invalid array.\n");
    } else if(result == ERROR_INVALID_LENGTH) {
        printf("Error: Invalid array length.\n");
    } else if(result == SUCCESS) {
        printf("Array sorted:\n");

        for(size_t i = 0; i < len; i++) {
            printf("%d ", my_array[i]);
        }
        printf("\n");
    }

    return 0;
}