#include "dynamic_array.h"

int main() {
    d_array array = create_darray(CHAR_TYPE);

    for(int i = 65 ; i <= 90 ;i++){
        char c = (char)i;
        push_back(&array, &c);
    }
    for(int i = 0 ; i < array.size ;i++){
        pop_back(&array);
        printf("%d capacity, %c number\n", array.capacity, ((char*)array.data)[i]);
    }

    clear_darray(&array);
    return 0;
}