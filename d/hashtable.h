#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

struct Table {
    size_t size;
    //TODO: change this to a pointer to list???
    //struct Node* linked_lists[];
    struct Node* *linked_lists;
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

size_t get_hash_index(char *key) {
    size_t key_sum;

    key_sum = 0;
    for(size_t i = 0; i < length(key); i++) {
        key_sum = key_sum + key[i];
    }

    printf("%lu\n", key_sum);

    return key_sum%10;
}

struct Node* compare_keys(struct Node* head, char *key) {
    size_t same;
    struct Node* temp;

    temp = head;

    same = 1;
    while(temp != NULL) {
        for(size_t x = 0; x < length(temp->key); x++) {
            if(temp->key[x] != key[x]) {
                same = 0;
                break;
            }
        }

        if(same == 1) {
            break;
        }

        temp = temp->next;
    }

    if(same == 1) {
        return temp;
    }

    return NULL;
}

void add_value_to_table(struct Table** table, char *key, int value) {
    size_t hash_index;
    struct Node* temp;

    hash_index = get_hash_index(key);

    if((*table)->linked_lists[hash_index] == NULL) {
        printf("%lu\n", hash_index);
        (*table)->linked_lists[hash_index] = node_new(key, value);
    } else {
        temp = compare_keys((*table)->linked_lists[hash_index], key);

        if(temp != NULL) {
            temp->value = value;
        } else {
            add_node_to_head(&((*table)->linked_lists[hash_index]), key, value);
        }
    }
}


//int* get_value(struct Table** table, char key[]) {
//    size_t value_index;
//    struct Node* temp;
//
//    value_index = get_hash_index(key);
//
//
//    temp = (*table)->linked_lists[value_index];
//}
