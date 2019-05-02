#include <stdlib.h>
#include <stdio.h>
#include "insert_sort.h"
#include "binary_search.h"

int main() {
    int numbers[9] = {2,1,4,5,3,6,7,9,8};
    size_t numbers_length;
    int index_of_four;

    numbers_length = sizeof(numbers)/sizeof(numbers[0]);

    printf("%lu\n", numbers_length);

    printList(numbers, numbers_length);

    int *sorted = get_sorted_list(numbers, numbers_length);

    printList(sorted, numbers_length);

    index_of_four = find_value_index_in_sorted_list(sorted, numbers_length, 4);

    printf("%d\n", index_of_four);

    return 0;
}
