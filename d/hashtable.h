#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

struct Table {
    size_t size;
    struct Node* linked_lists[];
};

struct Table* table_new(size_t size) {
    struct Table* new_table;

    new_table = (struct Table*)malloc(sizeof(struct Table));

    if(new_table == NULL) {
        printf("Error in malloc.");
        exit(1);
    }

    new_table->size = size;

    for(size_t i = 0; i < size; i++) {
        new_table->linked_lists[i] = NULL;
    }

    return new_table;
}

size_t get_hash_index(char key[]) {
    size_t key_sum;

    key_sum = 0;
    for(size_t i = 0; i < length(key); i++) {
        key_sum = key_sum + key[i];
    }

    printf("%lu\n", key_sum);

    return key_sum%10;
}

void add_value_to_table(struct Table** table, char key[], int value) {
    size_t hash_index;

    hash_index = get_hash_index(key);

    //TODO: check if value exists in list and add it or update depending
    for(size_t i = 0; i < (*table)->size; i++) {
        if(hash_index == i) {
            if((*table)->linked_lists[i] == NULL) {
                (*table)->linked_lists[i] = node_new(key, value);
            } else {
                add_node_to_head(&((*table)->linked_lists[i]), key, value);
            }
        }
    }
}

