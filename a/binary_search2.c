#include <stdlib.h>
#include <stdio.h>

int search(int *arr, int value, int left, int right) {
    size_t pivot;

    while (left <= right) {
        pivot = (left + right) / 2;

        if (arr[pivot] == value) {
            return pivot;
        }

        if (arr[pivot] < value) {
            return search(arr, value, pivot + 1, right);
        } else {
            return search(arr, value, left, pivot - 1);
        }
    }

    return -1;
}

int binarysearch(int *arr, int arr_length, int value) {
    return search(arr, value, 0, arr_length - 1); 
}

int main(int argc, char *argv[]) {
    int index;
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};

    if (argc != 2) {
        printf("Please provide a number to search for.\n");
        exit(1);
    }

    index = binarysearch(arr, 10, atoi(argv[1]));

    printf("Index: %d\n", index);

    return 0;
}
