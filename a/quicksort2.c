#include <stdlib.h>
#include <stdio.h>

void swap(int *arr, int left, int right) {
    int temp;

    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

int partition(int *arr, int left, int right, int pivot) {
    while (left <= right) {
        while (arr[left] < pivot) {
            left++;
        }

        while (arr[right] > pivot) {
            right--;
        }

        if (left <= right) {
            swap(arr, left, right);    
            left++;
            right--;
        }
    }
    
    return left;
}

void sort(int *arr, int left, int right) {
    int pivot, index;

    if (left >= right) {
        return;
    }

    pivot = arr[(left + right) / 2];

    index = partition(arr, left, right, pivot);

    sort(arr, left, index - 1);
    sort(arr, index, right);
}

void quicksort(int *arr, size_t arr_length) {
    sort(arr, 0, arr_length - 1);
}


int main() {
    size_t i;

    int unsorted[10] = {1, 7, 2, 4, 6, 3, 9, 8, 5, 0};

    quicksort(unsorted, 10);

    for (i = 0; i < 10; i++) {
        printf("%d, ", unsorted[i]); 
    }

    printf("\n");
    
    return 0;
}
