#include <stdlib.h>
#include <stdio.h>
#include "insert_sort.h"
#include "binary_search.h"

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

int main() {
    int numbers[9] = {2,1,4,5,3,6,7,9,8};
    size_t numbers_length;
    int index_of_four;

    numbers_length = sizeof(numbers)/sizeof(numbers[0]);

    printf("%lu\n", numbers_length);

    print_list(numbers, numbers_length);

    int *sorted = get_sorted_list(numbers, numbers_length);

    print_list(sorted, numbers_length);

    index_of_four = find_value_index_in_sorted_list(sorted, numbers_length, 4);

    printf("%d\n", index_of_four);

    return 0;
}
