#include <stdlib.h>
#include <stdio.h>

int *sort(int *list, int length);
void printList(int *list, int length);

int *sort(int *list, int length) {
    size_t is_sorted;

    is_sorted = 0;
    while(is_sorted == 0) {
        size_t hit = 1;
        //printf("%lu", sizeof(list)/sizeof(list[0]));
        //for(size_t i = 0; i < sizeof(list)/sizeof(list[0]) - 1; i++) {
        for(size_t i = 0; i < length - 1; i++) {
            if(list[i] > list[i + 1]) {
                int n = list[i];
                list[i] = list[i+1];
                list[i+1] = n;
                hit = 0;
            }
        }

        is_sorted = hit;
    }

    return list;
}

void printList(int *list, int length) {
    //for(size_t i = 0; i < (sizeof(list)/sizeof(list[0])); i++) {
    for(size_t i = 0; i < length; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");
}

int main() {
    //int list[10];
    int *sorted;

    int list[10] = {2, 1, 4, 5, 3, 7, 6, 8, 0, 9};

    printList(list, 10);

    sorted = sort(list, 10);

    printList(sorted, 10);
    return 0;
}
