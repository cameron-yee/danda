#include <stdlib.h>
#include <stdio.h>
#include "quicksort.h"

int main() {
    int list[];
    size_t list_length;

    list = {2,1,9,7,5,4,6,8,3,0};
    list_length = sizeof(list)/sizeof(int)

    quicksort(list, list_length);
    return 0;
}

