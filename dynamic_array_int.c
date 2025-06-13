/*
Author: Santhosh T K
Date : 12 Sep 2023
*/


#include<stdio.h>
#include <stdlib.h>
#include "dynamic_array_int.h"

typedef struct{
	int *array;
	int i;
	int capacity;
} dynamic_array;

void _resize_expand(dynamic_array* array){

	int old_capacity = array->capacity;

	// Creating a new array with double the size of old one.
	int *new_array = malloc(sizeof(int) * old_capacity * 2);

	// Copy the old contents into the new array O(old_capacity)
	for(int i = 0; i <= array->i; i++){
		new_array[i] = array->array[i];
	}

	free(array->array);
	array->array = new_array;
	array->capacity = old_capacity * 2;
}


void _resize_shrink(dynamic_array* array){

	int old_capacity = array->capacity;

	// Creating a new array with half the size of old one.
	int *new_array = malloc(sizeof(int) * (int)(old_capacity / 2));

	// Copy the old contents into the new array O(old_capacity)
	for(int i = 0; i <= array->i; i++){
		new_array[i] = array->array[i];
	}

	free(array->array);
	array->array = new_array;
	array->capacity = (int)old_capacity / 2;

}

dynamic_array* create_array(){

	// Creates a struct type of dynamic_array
	// Allocate initial size of 10 to the array of integers
	// Return: pointer to the struct

	dynamic_array* array = malloc(sizeof(dynamic_array));
	array->array = malloc(sizeof(int) * 10);
	array->capacity = 10;
	array->i = -1;

	return array;
}

void push(int element, dynamic_array* array){

	if(array->i + 1 >= array->capacity){
		_resize_expand(array);
	}

	array->i++;
	array->array[array->i] = element;
}


int pop(dynamic_array* array){

	int temp = array->array[array->i];
	array->i--;

	if (array->i + 1 < array->capacity / 2 && array->capacity > 10) {
        _resize_shrink(array);
    }

    return temp;
}


void insert(int position, int element, dynamic_array* array){

	// If the array cell is empty we can directly place the element.
	if(position > array->i){
		array->array[position] = element;
		array->i = position;
	}
	else{

		if(array->i + 1 >= array->capacity){
			_resize_expand(array);
		}

		int temp = element;
		for(int i = position; i <= array->i; i++){
			int t = array->array[i];
			array->array[i] = temp;
			temp = t;
		}
	}

	array->i++;

}


int search(int element, dynamic_array* array){
	for(int i = 0; i <= array->i; i++){
		if(array->array[i] == element){
			return i;
		}
	}
	return -1;
}


void delete(int element, dynamic_array* array){

	// Find out the position of the element.
	int position = search(element, array);

	if(position != -1){

		if(position == array->capacity - 1){
			array->i--;
			return;
		}
		else{
			for(int i = position; i <= array->i - 1; i++){
				array->array[i] = array->array[i + 1];
			}
			array->i--;
		}

		if (array->i + 1 < array->capacity / 2 && array->capacity > 10) {
        	_resize_shrink(array);
    	}
    	return;

	}
}


int main() {
    printf("=== Dynamic Array Testing ===\n\n");

    dynamic_array* arr = create_array();

    printf("Initial capacity: %d\n", arr->capacity);
    printf("Initial size: %d\n", arr->i + 1);

    // Test push beyond initial capacity
    printf("\nPushing 20 elements...\n");
    for (int i = 0; i < 20; i++) {
        push(i * 5, arr);
    }

    printf("After pushing:\n");
    for (int j = 0; j <= arr->i; j++) {
        printf("%d ", arr->array[j]);
    }
    printf("\nCurrent capacity: %d\n", arr->capacity);

    // Test insert in between
    printf("\nInserting 999 at index 10\n");
    insert(10, 999, arr);

    printf("Inserting 111 at beginning (index 0)\n");
    insert(0, 111, arr);

    printf("Inserting 777 at index 30 (beyond current size)\n");
    insert(30, 777, arr);

    printf("\nAfter insertions:\n");
    for (int j = 0; j <= arr->i; j++) {
        printf("%d ", arr->array[j]);
    }
    printf("\nCurrent capacity: %d\n", arr->capacity);

    // Test search
    printf("\nSearching for 999: Index %d\n", search(999, arr));
    printf("Searching for 777: Index %d\n", search(777, arr));
    printf("Searching for 42 (not in array): Index %d\n", search(42, arr));

    // Test deletion
    printf("\nDeleting 999...\n");
    delete(999, arr);

    printf("Deleting 777...\n");
    delete(777, arr);

    printf("Deleting 42 (non-existent)...\n");
    delete(42, arr);  // Should handle gracefully

    printf("\nAfter deletions:\n");
    for (int j = 0; j <= arr->i; j++) {
        printf("%d ", arr->array[j]);
    }
    printf("\nCurrent capacity: %d\n", arr->capacity);

    // Test pop
    printf("\nPopping 5 elements...\n");
    for (int i = 0; i < 5; i++) {
        int val = pop(arr);
        printf("Popped: %d\n", val);
    }

    printf("\nAfter popping:\n");
    for (int j = 0; j <= arr->i; j++) {
        printf("%d ", arr->array[j]);
    }
    printf("\nCurrent capacity: %d\n", arr->capacity);

    // Test shrinking
    printf("\nPopping more to test shrinking...\n");
    while (arr->i >= 0) {
        pop(arr);
    }

    printf("After popping all elements:\n");
    printf("Current size: %d\n", arr->i + 1);
    printf("Current capacity: %d\n", arr->capacity);

    // Clean up
    free(arr->array);
    free(arr);

    printf("\nTest completed. Memory cleaned up.\n");

    return 0;
}

