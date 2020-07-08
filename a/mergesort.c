#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void merge(int *arr, size_t left_start, size_t middle, size_t right_end) {
    size_t i, j, k;
    size_t left_size, right_size;

    left_size = middle - left_start + 1;
    right_size = right_end - middle; 
    
    int left_temp[left_size];
    int right_temp[right_size];

    for (i = 0; i <= left_size; i++) {
        left_temp[i] = arr[left_start + i];
    }
    
    for (j = 0; j <= right_size; j++) {
        right_temp[j] = arr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left_start;

    while (i < left_size && j < right_size) {
        if (left_temp[i] <= right_temp[j]) {
            arr[k] = left_temp[i];
            i++;
        } else {
            arr[k] = right_temp[j];
            j++;
        }

        k++;
    } 

    while (i < left_size) {
        arr[k] = left_temp[i];
        i++;
        k++;
    }
    
    while (j < right_size) {
        arr[k] = right_temp[j];
        j++;
        k++;
    }
}

void sort(int *arr, size_t left_start, size_t right_end) {
    size_t middle;

    if (left_start >= right_end) {
        return;
    }

    middle = (left_start + right_end) / 2;
    
    sort(arr, left_start, middle);
    sort(arr, middle + 1, right_end);
    
    merge(arr, left_start, middle, right_end);
}

void msort(int *arr, int arr_size) {
    sort(arr, 0, arr_size - 1);
}

int * getTestArray(int number) {
    int *r;
    int i;

    r = malloc(number * sizeof(int)); 
    if (r == NULL) {
        exit(1);
    }

    /* set the seed */
    srand((unsigned)time( NULL ));

    for (i = 0; i < number; i++) {
        r[i] = rand() % 10;
    }

    return r;
}
                                           
int main(int argc, char *argv[]) {
    int *arr;
    int number; 
    clock_t start, end;
    double cpu_time_used;

    if (argc < 2) {
        printf("Provide a number dangit.\n");
        return 1;
    }

    number = atoi(argv[1]);
    arr = getTestArray(number); 
    
    printf("%d\n", number);

    start = clock(); 
    msort(arr, number);
    end = clock(); 
    free(arr);
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%fs\n", cpu_time_used);
         
    return 0;
}
