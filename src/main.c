#include "dynamic_array.h"

int main() {
    d_array array = create_darray(CHAR_TYPE);

    for(int i = 65 ; i <= 90 ;i++){
        char c = (char)i;
        push_back(&array, &c);
        printf("%d capacity, %c char\n", array.capacity, c);
    }
    
    while(array.size >= 0){
        pop_back(&array);
     //   printf("%d capacity, %c char\n", array.capacity, ((char*)array.data)[i]);
    }

    clear_darray(&array);
    return 0;
}