#include <stdio.h>
#include <stdlib.h>
#include "dynamic_arrays.h"

// create_array returns a dinamic array with only one value which will contain the array elemts counter
// For the use of this functions, the array is empty
int* create_array() {
    int* arr = malloc(sizeof(int));
    if (arr == NULL) {
       return NULL;
    };
    *arr = 0;
    return arr;
}

//add_element receives as parameteres the pointer to the array and a value
//The function will return a version of the array with increased size and the value added at the end
int* add_element(int* arr, int val) {
    if (arr == NULL) {
	printf("Array is NULL\n");
	return NULL;
	}
    int* backup = arr;
    arr = realloc(arr, sizeof(int)*(*arr + 2));    //+2 Sums the size of the new element and the element counter
    if (arr == NULL){
	printf("Memory error\n");
    	return backup;
    }
    (*arr)++;
    *(arr + *arr) = val;
    return arr; 
}

//eliminate_element receives as parameters the pointer to the array and a zero based index to the element to be eliminated
//The function returns a version of the array without the eliminated element and all contiguous elements moved to the left
int* eliminate_element(int* arr, int index) {
    if (arr == NULL) {
	printf("Array is NULL\n");
	return NULL;
    }
    if (index >= *arr || index < 0)  {
	printf("Index out of range\n");
	return arr;
    }
    //Moving each element to the left
    for (int i=index + 1;i < *arr; i++) { 
        *(arr + i) = *(arr + i+1);
    };
    (*arr)--;
    arr = realloc(arr, sizeof(int)*(*arr + 1));
    if (arr == NULL) {
	printf("Memory error\n");
	return NULL;
    }
    return arr;
}


//get_element receives as parameters the pointer to the array and a zero based index to the element to return
//returns the integer contained in the array pointed with the index
int get_element(int* arr, int index) {
    if (arr == NULL) {
        printf("Array is NULL\n");
        return 0;
    }
    if (index < -1 || index >= *arr) {    //if the function receives index=-1 it will return the element counter
        printf("Index out of range\n");
        return 0;
    }
    return *(arr + index + 1);
}

//print_array prints the array elemnts except for the element counter
int print_array(int* arr) {
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

//normalize_array receives as a parameter a pointer to the array
//It will return a version of the array without the element counter to be used with other c functions
//This operation can be reversed by creating and array with the element counter as its first element 

int* normalize_array(int* arr) {
    int* backup = arr;
    if (arr == NULL) {
	printf("Array is NULL\n");
	return backup;
    }
    int limit = *arr;
    for (int i=0;i < limit; i++) { 
        *(arr + i) = *(arr + i+1);
    };
    arr = realloc(arr, sizeof(int)*(limit));
    if (arr == NULL) {
	printf("Memory error\n");
	return backup;
    }
    return arr;

}
