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
    size_t i;

    for(i = 0; i < list_length - 1; i++) {
        int temp;
        if(list[i] > list[i+1]) {
            temp = list[i];
            list[i] = list[i+1];
            list[i+1] = temp;
            i = -1;
        }
    }

    return list;
}


int main() {
    int numbers[9] = {2,1,4,5,3,6,7,9,8};
    size_t numbers_length;

    numbers_length = sizeof(numbers)/sizeof(numbers[0]);

    printf("%lu\n", numbers_length);

    printList(numbers, numbers_length);

    int *sorted = get_sorted_list(numbers, numbers_length);

    printList(sorted, numbers_length);

    return 0;
}
