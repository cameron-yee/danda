#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

struct Table {
    size_t size;
    //TODO: change this to a pointer to list???
    //struct Node* linked_lists[];
    //struct Node* linked_lists;
    struct Node *linked_lists[10];
};

struct Table* table_new(size_t size);
size_t get_hash_index(char *key);
struct Node* compare_keys(struct Node* head, char *key);
void add_value_to_table(struct Table** table, char *key, int value);

#endif
