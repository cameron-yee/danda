#include <stdlib.h>
#include <stdio.h>

int *get_sorted_list(int *list, size_t list_length);
void printList(int *list, size_t list_length);

void printList(int *list, size_t list_length) {
    size_t i;

    for(i = 0; i < list_length; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");
}

int *get_sorted_list(int *list, size_t list_length) {
    //int sorted_list[list_length] = (int *)malloc(sizeof(int * list_length));
    int *sorted_list;
    
    sorted_list = (int *)malloc(sizeof(int) * list_length);

    if(sorted_list == NULL) {
        printf("malloc failed for sorted_list");
        exit(1);
    }

    size_t i;
    size_t x;
    size_t y;

    for(y = 0; y < list_length; y++) {
        sorted_list[y] = -1;
    }

    for(i = 0; i < list_length; i++) {
        for(x = 0; x < list_length; x++) {
            if(sorted_list[x] == -1) {
                sorted_list[x] = list[i];
                break;
            } else if(sorted_list[x+1] != -1) {
                continue;
            } else if (sorted_list[x] > list[i]) {
                sorted_list[x+1] = sorted_list[x];
                sorted_list[x] = list[i];
                break;
            } else if (sorted_list[x] <= list[i]) {
                sorted_list[x+1] = list[i];
                break;
            }
        }
    }

    return sorted_list;
}


int main() {
    int numbers[10] = {2,1,4,5,3,6,7,9,8};
    size_t numbers_length;
    size_t sorted_length;

    numbers_length = sizeof(numbers)/sizeof(numbers[0]);

    printList(numbers, numbers_length);

    int *sorted = get_sorted_list(numbers, numbers_length);

    sorted_length = sizeof(sorted)/sizeof(sorted[0]);

    printList(sorted, sorted_length);

    return 0;
}
