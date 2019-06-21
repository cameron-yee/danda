#include <stdlib.h>
#include <stdio.h>

#ifndef QUICKSORT_H
#define QUICKSORT_H

void quicksort(int* list, size_t list_length);
void swap(int* list, size_t left, size_t right);
void sort(int* list, size_t list_length, size_t left, size_t right);

#endif
