#include <stdlib.h>
#include <stdio.h>

void shift_merged_list(int *merged_list, int list_length, size_t position, int holder) {
    int temp;

    for (size_t i = position; i < list_length; i++) {
        for (size_t x = 0; x < list_length; x++) {
            printf("%d ", merged_list[x]);
        }

        printf("\n");

        temp = merged_list[position];

        if (temp == 0) {
            merged_list[position] = holder;
            break;
        }

        printf("temp: %d\n", temp);
        merged_list[position] = holder;
        holder = temp;
    }
}

int *insert_into_list(int *merged_list, int list_length, size_t position, int value) {
    int holder;
    
    //printf("value: %d\n", value);

    if (merged_list[position] == 0) {
        merged_list[position] = value;
        return merged_list;
    }

    holder = merged_list[position];
    //printf("holder: %d\n", holder);
    merged_list[position] = value;

    shift_merged_list(merged_list, list_length, position + 1, holder);

    return merged_list;
}

size_t find_insert_position(int *merged_list, size_t list_length, int value) {
    //printf("%d, ", value);
    for (size_t i = 0; i < list_length; i++) {
        if (value <= merged_list[i] || merged_list[i] == 0) {
            //printf("\n");
            return i;
        }
    }

    printf("List is already full\n");
    exit(1);
}

void merge_sorted_lists(size_t x, size_t y, int unmerged_list[][y], int *merged_list) {
    //static int merged_list[x*y];
    //static int merged_list[9];
    size_t insert_position;

    // Can't initialize list with variables for length
    //for (size_t l = 0; l < x*y; l++) {
    //    merged_list[l] = -1;
    //}

    for (size_t i = 0; i < x; i++) {
        for (size_t j = 0; j < y; j++) {
            insert_position = find_insert_position(merged_list, x*y, unmerged_list[i][j]);
            insert_into_list(merged_list, x*y, insert_position, unmerged_list[i][j]);
        }
    }

    printf("\n");
}

void print_merged_list(int *merged_list, size_t list_length) {
    for (size_t i = 0; i < list_length; i++) {
        printf("%d, ", merged_list[i]);
    }

    printf("\n");
}

int main() {
    int sorted_lists[][3] = {
        {10, 15, 30},
        {12, 15, 20},
        {17, 20, 32}
    };

    int merged_list[9] = { 0 };

    //TODO: Read about pointer arithmetic
    //https://codeforwin.org/2017/12/access-two-dimensional-array-using-pointers-c-programming.html
    merge_sorted_lists(3, 3, sorted_lists, merged_list);

    print_merged_list(merged_list, 9);

    return 0;
}
