#include "dynamic_array.h"

int main() {
    d_array array = create_darray(CHAR_TYPE);

    for(int i = 65 ; i <= 90 ;i++){
        char c = (char)i;
        push_back(&array, &c);
        printf("%d capacity, %c char\n", array.capacity, c);
    }

    printf("size: %d, capacity: %d\n", array.size, array.capacity);
    fit_size(&array);
    printf("size: %d, capacity: %d\n", array.size, array.capacity);

    clear_darray(&array);
    return 0;
}