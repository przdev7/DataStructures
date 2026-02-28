#include "dynamic_array.h"

size_t get_size(DATA_TYPE type){
    switch (type)
    {
    case INT_TYPE: {
        return sizeof(int);
        break;
    }
    case CHAR_TYPE: {
        return sizeof(char);
        break;
    }
    case FLOAT_TYPE: {
        return sizeof(float);
        break;
    }
    case DOUBLE_TYPE: {
        return sizeof(double);
        break;
    }
    case BOOL_TYPE: {
        return sizeof(bool);
        break;
        }   
    }
}

d_array create_darray(DATA_TYPE type) {
    //defult value for array capacity, power of 2.
    size_t capacity = 8;
    size_t size = 0;
    void* ptr = malloc(capacity * get_size(type));

    d_array d = {
        .capacity = capacity,
        .data = ptr,
        .size = size,
        .type = type,
    };

    if(d.data == NULL) {
        printf("allocation falied (create) \n");
    }

    return d;
}

void clear_darray(d_array* array) {
    free(array->data);
    array->data = NULL;
}

void push_back(d_array* array, void* value) {
    if(array->size >= array->capacity) { 
        array->capacity *= 2; 
        array->data = realloc(array->data, array->capacity * get_size(array->type));

        if(array->data == NULL) {
            printf("allocation failed");
            exit(-1);
        }
    }
        size_t element_size = get_size(array->type);
        memcpy((char*)array->data + array->size * element_size, value, element_size);

    array->size++;
}

void pop_back(d_array* array) {
    if(array->size * 2 < array->capacity) {
        array->capacity /= 2;
        array->data = realloc(array->data, array->capacity * sizeof(int));

        if(array->data == NULL) {
        printf("allocation failed (pop)");
        exit(-1);
        }
    }
    array->size--;
}

