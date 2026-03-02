#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DYNAMIC_ARRAYS

#define DYNAMIC_ARRAYS

typedef enum {
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    CHAR_TYPE,
    BOOL_TYPE
} DATA_TYPE;

/**
 * @brief Dynamic array structure
 * @author przdev7
 * @struct d_array
 *
 * @param data pointer to array (use malloc or calloc to define)
 * @param capacity max elements which array can store
 * @param size current number of elements
 *
 * @example
 * int n = 8;
 * int *arr = malloc(n * sizeof(int));
 * int size = 0;
 * d_array array = {&arr, &n, &size};
 */
typedef struct {
    DATA_TYPE type;
    void* data;
    size_t capacity;
    size_t size;
} d_array;

/**
 * @brief Push as last element to array
 * @author przdev7
 * @struct d_array
 * 
 * @param array pointer of your d_array (you can create by using create_darray function)
 * @param value 
 */
void push_back(d_array* array, void* value);

/**
 * @brief Pops last element of array
 * @author przdev7
 * @struct d_array
 * 
 * @param array pointer of your d_array (you can create by using create_darray function)
 */
void pop_back(d_array* array);

/**
 * @brief Creates a dynamic array
 * @author przdev7
 * 
 * @param type Data type which array will contain
 */
d_array create_darray(DATA_TYPE type);
/**
 * @brief Frees allocated data in memory
 * @author przdev7
 * 
 * Prevents from memory leak, always use when your array is no longer needed
 */
void clear_darray(d_array* array);


/**
 * @brief Checks if array is empty.
 * @param array pointer of your d_array (you can create by using create_darray function)
 */
bool is_empty(d_array* array);



#endif
