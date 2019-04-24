#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

struct Table {
    struct Node* linked_lists[10];
};

struct *Table table_new() {
    struct *Table new_table;

    new_table = (struct *Table)malloc(sizeof(struct Table));
    return new_table;
}

size_t get_size_of_table(struct *Table table) {
    struct Node* table_list[];
    size_t size;

    table_list = table->linked_lists[];

    size = sizeof(table_list)/sizeof(table_list[0]);

    return size;
}

size_t get_hash_index(char key[]) {
    int key_sum;

    key_sum = 0;
    for(size_t i = 0; i < length(key); i++) {
        key_sum = key_sum + key[i];
    }

    return key_sum%10;
}

void add_value_to_table(struct **Table table, char key[], int value) {
    struct Node* table_list[];
    size_t hash_index;

    table_list = (*table)->linked_lists[];
    hash_index = get_hash_index(key);

    //TODO: check if value exists in list and add it or update depending
    //for(size_t i = 0; i < get_size_of_table((*table)), i++) {
    //    if(hash_index == i) {
    //        if(table_list[i] == NULL) {
    //            node_new(key, value);
    //        } else {
    //            struct Node* list = table_list[i];
    //            add_node_to_head(&list
    //        }
    //    }
    //}
}

