#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct {
    int *array;
    int i;
    int capacity;
} dynamic_array;

dynamic_array* create_array();
void push(int element, dynamic_array* array);
int pop(dynamic_array* array);
void insert(int position, int element, dynamic_array* array);
int search(int element, dynamic_array* array);
void delete(int element, dynamic_array* array);
void free_array(dynamic_array* array);  // helper for freeing memory

#endif
