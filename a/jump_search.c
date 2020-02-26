#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int linearsearch(int *arr, int left, int right, int value) {
    for (int i = left; i <= right; i++) {
        if (arr[i] == value) {
            return i;
        }
    }

    return -1;
}

int jumpsearch(int *arr, int arr_length, int value) {
    int jump, left, right;
    double sqrt_length;

    if (value > arr[arr_length - 1] || value < arr[0]) {
        return -1;
    }

    sqrt_length = sqrt((double) arr_length);
    jump = (int) sqrt_length;
    
    left = 0;
    right =  jump - 1;

    while (arr[right] < value) {
        left = left + jump; 
        right = right + jump;
    }

    if (right > arr_length - 1) {
        left = arr_length - 1 - jump;
        right = arr_length - 1;
    }

    return linearsearch(arr, left, right, value);
}

int main(int argc, char *argv[]) {
    int index; 
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};

    if (argc != 2) {
        printf("Please provide a number to search for.\n");
        exit(1);
    }

    index = jumpsearch(arr, 10, atoi(argv[1])); 

    printf("Index: %d\n", index);

    return 0;
}
