#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <stdio.h>
#include <stdbool.h>

/* ERROR STATUS CONSTANTS */

// Setup Errors code
#define ERROR_ARRAY_NOT_ALLOCATED -11

// Input Error
#define ERROR_INVALID_LENGTH -30

// Success code
#define SUCCESS 0

/* MAIN FUNCTION */

int bubble_sort(int *array, size_t len);

#endif
