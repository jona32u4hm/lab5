#include <stdio.h>
#include <stdlib.h>
#include "dynamic_arrays.h"

int main() {
    int* array = create_array();
    print_array(array);
    array = add_element(array, 1);
    array = add_element(array, 2);
    print_array(array);
    array = eliminate_element(array, 1);
    print_array(array);
    int val = get_element(array, 0);
    printf("%d", val);
}
