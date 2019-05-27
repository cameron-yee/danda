#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

struct Table {
    size_t size;
    struct Node *linked_lists[10];
};

struct Table *table_new(size_t size);
void table_add_value(struct Table **table, char *key, int value);
int table_get_value_by_key(struct Table **table, char *key);

#endif
