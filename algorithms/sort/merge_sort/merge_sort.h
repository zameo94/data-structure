#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* ERROR STATUS CONSTANTS */

// Setup Errors code
#define ERROR_ARRAY_NOT_ALLOCATED -11

// Input Error
#define ERROR_INVALID_LENGTH -30

// Success code
#define SUCCESS 0

/* MAIN FUNCTION */

int merge_sort(int *array, size_t len);

#endif
