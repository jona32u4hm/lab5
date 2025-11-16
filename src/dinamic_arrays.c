#include <stdio.h>
#include <stdlib.h>

int* create_array() {
    int* arr = malloc(sizeof(int));
    if (arr == NULL) {
       return NULL;
    };
    *arr = 0;
    return arr;
    
}

int* add_element(int* arr, int val) {
    if (arr == NULL) {
	printf("Array is NULL\n");
	return NULL;
	}
    int* backup = arr;
    arr = realloc(arr, sizeof(int)*(*arr + 2));
    if (arr == NULL){
	printf("Memory error\n");
    	return backup;
    }
    (*arr)++;
    *(arr + *arr) = val;
    return arr; 
}

int* elimate_element(int* arr, int index) {
    if (arr == NULL) {
	printf("Array is NULL\n");
	return NULL;
    }
    if (index >= *arr || index < 0)  {
	printf("Index out of range\n");
	return arr;
    }
    for (int i=index + 1;i < *arr; i++) { 
        *(arr + i) = *(arr + i+1);
    };
    (*arr)--;
    arr = realloc(arr, sizeof(int)*(*arr + 1));
    if (arr == NULL) {
	printf("Memory error\n")
	return NULL
    }
    return arr;
}

int get_element(int* arr, int index) {
    if (arr == NULL) {
        printf("Array is NULL\n");
        return 0;
    }
    if (index < 0 || index >= *arr) {
        printf("Index out of range\n");
        return 0;
    }
    return *(arr + index + 1);
}

int print_arr(int* arr) {
    printf("[");
    for (int i=1;i <= *arr; i++) {
	if (i == *arr) {
	    printf("%d", *(arr + i));
	    continue;
	}
	printf("%d,", *(arr + i));
    }
    printf("]");
    return 0;
}

