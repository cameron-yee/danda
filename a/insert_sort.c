#include <stdlib.h>
#include <stdio.h>
#include "insert_sort.h"

int main() {
    int numbers[9] = {2,1,4,5,3,6,7,9,8};
    size_t numbers_length;

    numbers_length = sizeof(numbers)/sizeof(numbers[0]);

    printf("%lu\n", numbers_length);

    printList(numbers, numbers_length);

    int *sorted = get_sorted_list(numbers, numbers_length);

    printList(sorted, numbers_length);

    return 0;
}
