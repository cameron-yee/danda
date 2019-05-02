#include <stdlib.h>
#include <stdio.h>

int find_value_index_in_sorted_list(int *sorted_list, size_t list_length, int wanted_value);

int find_value_index_in_sorted_list(int *sorted_list, size_t list_length, int wanted_value) {
    int left, right;
    int middle;

    left = 0;
    right = list_length - 1;

    while(left <= right) {
        middle = left + ((right - left) / 2);
        if(wanted_value == sorted_list[middle]) {
            return middle;
        } else if(wanted_value < sorted_list[middle]) {
            right = middle - 1;
        } else if(wanted_value >= sorted_list[middle]) {
            left = middle + 1;
        }

    }

    return -1;
}

