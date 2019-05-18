#include <stdlib.h>
#include <stdio.h>

void quicksort(int* list, size_t list_length) {
    size_t left, right, pivot;

    left = 0;
    right = list_length - 1;

}

void swap(int* list, size_t left, size_t right) {
    int temp;

    temp = list[left];
    list[left] = list[right];
    list[right] = temp;
}

void sort(int* list, size_t list_length, size_t left, size_t right) {
    size_t pivot;

    pivot = (left + right) / 2;

    if(left >= right) {
        return;
    }


    while(left <= right) {
        while(list[left] < pivot) {
            left++;
        }

        while(list[right] > pivot) {
            right--;
        }

        if(left <= right) {
            swap(list, left, right)
            left++;
        }
   }

}
