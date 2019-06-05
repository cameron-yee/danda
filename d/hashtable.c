#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "hashtable.h"

struct Node *compare_keys(struct Node *head, char *key);
size_t get_hash_index(char *key);
size_t string_compare(char *one, char *two);

struct Table *table_new(size_t size) {
    struct Table *new_table;

    new_table = (struct Table*)malloc(sizeof(struct Table));

    if (new_table == NULL) {
        printf("Error in malloc.");
        exit(1);
    }

    new_table->size = size;

    //new_table->linked_lists = { NULL };
    for (size_t i = 0; i < size; i++) {
        new_table->linked_lists[i] = NULL;
    }

    return new_table;
}

size_t get_hash_index(char *key) {
    size_t key_sum;

    key_sum = 0;
    for (size_t i = 0; i < ll_length(key); i++) {
        key_sum = key_sum + key[i];
    }

    return key_sum%10;
}

size_t string_compare(char *one, char *two) {

    for (size_t i = 0; i < ll_length(one); i++) {
        if (one[i] != two[i]) {
            return 0;
        }
    }

    return 1;
}

struct Node *compare_keys(struct Node *head, char *key) {
    size_t same;
    struct Node *temp;

    temp = head;

    //TODO: this is probably stupid. for loop nested in while loop.
    same = 0;
    while (temp != NULL) {
        same = string_compare(temp->key, key);

        if(same == 1) {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

void table_add_value(struct Table **table, char *key, int value) {
    size_t hash_index;
    struct Node *temp;
    struct Node *hash_index_head;

    hash_index = get_hash_index(key);

    hash_index_head = (*table)->linked_lists[hash_index];
    if (hash_index_head == NULL) {
        (*table)->linked_lists[hash_index] = node_new(key, value);
    } else {
        temp = compare_keys((*table)->linked_lists[hash_index], key);

        if (temp != NULL) {
            temp->value = value;
        } else {
            struct Node *spot = (*table)->linked_lists[hash_index];
            ll_add_node_to_head(&spot, key, value);
        }
    }
}


int table_get_value_by_key(struct Table **table, char *key) {
    size_t hash_index;
    struct Node *hash_index_head;
    struct Node *key_node;

    hash_index = get_hash_index(key);

    hash_index_head = (*table)->linked_lists[hash_index];

    key_node = compare_keys(hash_index_head, key);

    if (key_node != NULL) {
       return key_node->value;
    } else {
        return -1;
    }
}

//TODO: this isn't ready
int table_delete_key(struct Table **table, char *key) {
    int value;
    size_t hash_index;
    struct Node *hash_index_head;
    struct Node *key_node;

    hash_index = get_hash_index(key);

    hash_index_head = (*table)->linked_lists[hash_index];

    key_node = compare_keys(hash_index_head, key);

    //TODO: How do I set the previous node->next to NULL?
    if (key_node != NULL) {
       value = key_node->value;
       key_node = NULL;
       free(key_node);

       return value;
    } else {
        return -1;
    }
}

//
// gcc -Wall linked_list.c hashtable.c -o hashtable
//
int main() {
    size_t index;

    struct Table *table;

    char person[] = "Cameron"; //709, 9
    char person_2[] = "Jordan"; //606, 6

    int person_value;

    index = get_hash_index(person);

    printf("1. %lu\n", index);

    table = table_new(10);

    printf("2. %lu\n", table->size);

    table_add_value(&table, person, 1);
    printf("3. %d\n", table->linked_lists[9]->value);

    table_add_value(&table, person, 2);
    printf("4. %d\n", table->linked_lists[9]->value);

    table_add_value(&table, person_2, 3);
    printf("5. %d\n", table->linked_lists[6]->value);

    person_value = table_get_value_by_key(&table, person);
    printf("6. %d\n", person_value);

    return 0;
}
