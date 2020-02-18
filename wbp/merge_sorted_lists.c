#include <stdlib.h>
#include <stdio.h>

int find_new_position(int *list, int value) {

}

int *insert_at_position(int *list, size_t list_length;  size_t position, int value) {
    int temp;

    for (size_t i = position; i < list_length; i++) {
        temp = list[i+1];
        list[i+1] = list[i];

    }
}

int *merge_sorted_lists(int *sorted_lists, size_t x, size_t y) {
    int max;
    int merged_lists[x * y] = { NULL };

    max = -1;

    //Can I do this in one loop? Should I?
    //for (size_t i = 0, size_t j = 0; i < x; i++) {
    //    if (max == -1) {
    //        merged_lists[i] = *(*(sorted_lists + 0) + 0);
    //        max = *(*(sorted_lists + 0) + 0);
    //    } else {
    //        if (*(*(sorted_lists + 0) + 0) > merged_lists[i]
    //    }
    //}
    int c = 0;
    for (size_t i = 0, size_t j = 0; i < x; i++) {
        for (size_t j = 0, j < y; i++) {
            if (max == -1) {
                merged_lists[c] = sorted_lists[i][j];
                max = sorted_lists[i][j];
                continue;
            } else if (sorted_lists[i][j] >= max) {
                merged_lists[c] = sorted_lists[i][j];
            } else {
                for (size_t k = 0; k < (x * y); k++) {
                    if (merged_lists[k] == NULL) {
                        merged_lists[k] = sorted_lists[i][j];
                        max = sorted_lists[i][j];
                        continue;
                    } else if (merged_lists[c] <= sorted_lists[i][j]) {
                        //merged_lists[c+1] = sorted_lists[i][j];   
                        insert_at_position(*merged_lists, c + 1, sorted_lists[i][j]);
                    }
                }
            }
        }
    }
}

int main() {
    int sorted_lists[3][3] = {
        {10, 15, 30},
        {12, 15, 20},
        {17, 20, 32}
    };

    //TODO: Read about pointer arithmetic
    //https://codeforwin.org/2017/12/access-two-dimensional-array-using-pointers-c-programming.html
    merge_sorted_lists(int *sorted_lists, 3, 3);

    print

    return 0;
}
