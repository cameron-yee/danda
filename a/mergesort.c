#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void merge(int *arr, size_t left, size_t middle, size_t right) {
    size_t i, j, k;
    size_t left_size, right_size;

    left_size = middle - left + 1;
    right_size = right - middle; 
    
    // int L[left_size];
    // int R[right_size];
    int *L = malloc(left_size * sizeof(int));
    if (L == NULL) {
        exit(1);
    }
    int *R = malloc(right_size * sizeof(int));
    if (R == NULL) {
        exit(1);
    }

    for (i = 0; i < left_size; i++) {
        L[i] = arr[left + i];
    }
    
    for (j = 0; j < right_size; j++) {
        R[j] = arr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < left_size && j < right_size) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }

        k++;
    } 

    while (i < left_size) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < right_size) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void sort(int *arr, size_t left, size_t right) {
    size_t middle;

    if (left >= right) {
        return;
    }

    middle = left + (right - left) / 2;
    
    sort(arr, left, middle);
    sort(arr, middle + 1, right);
     
    merge(arr, left, middle, right);
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
