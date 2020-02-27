#include <stdlib.h>
#include <stdio.h>

void merge(int *arr, size_t arr_length, int *temp, size_t left_start, size_t right_end) {
    size_t left_end, right_start, size, left, right, index;

    left_end = (right_end + left_start) / 2;
    right_start = left_end + 1; 
    size = right_end - left_start + 1;

    left = left_start;
    right = right_start;
    index = left_start;

    while (left <= left_end && right <= right_end) {
        if (arr[left] <= arr[right]) {
            temp[index] = arr[left];
            left++;
        } else {
            temp[index] = arr[right];
            right++;
        }

        index++;
    }

    for (size_t i = left; i <= left_end; i++, index++) {
        temp[index] = arr[i];
    }
    
    for (size_t i = right; i <= right_end; i++, index++) {
        temp[index] = arr[i];
    }

    //TODO: pretty sure this is the culprit
    for (size_t i = left_start; i < size - 1; i++) {
        arr[i] = temp[i];
    }
}

void sort(int *arr, size_t arr_length, int *temp, size_t left_start, size_t right_end) {
    size_t middle;

    if (left_start >= right_end) {
        return;
    }

    middle = (left_start + right_end) / 2;
    sort(arr, arr_length, temp, left_start, middle);
    sort(arr, arr_length, temp, middle + 1, right_end);
    merge(arr, arr_length, temp, left_start, right_end);
}

void msort(int *arr, size_t arr_length) {
    int temp[arr_length];
    
    sort(arr, arr_length, temp, 0, arr_length - 1);
}

int main() {
    int arr[10] = {4,3,8,1,2,0,7,5,9,6};

    msort(arr, 10);

    for (size_t i = 0; i < 10; i++) {
        printf("%d, ", arr[i]);
    }

    printf("\n");
     
    return 0;
}
