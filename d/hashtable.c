#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "hashtable.h"

struct Table* table_new(size_t size) {
    struct Table* new_table;

    new_table = (struct Table*)malloc(sizeof(struct Table));

    if(new_table == NULL) {
        printf("Error in malloc.");
        exit(1);
    }

    new_table->size = size;

    //for(size_t i = 0; i < size; i++) {
    //    new_table->linked_lists[i] = NULL;
    //}

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

    if(&((*table)->linked_lists[hash_index]) == NULL) {
        printf("%lu\n", hash_index);
        struct Node* point = &(*table)->linked_lists[hash_index];
        point = node_new(key, value);
    } else {
        temp = compare_keys(&((*table)->linked_lists[hash_index]), key);

        if(temp != NULL) {
            temp->value = value;
        } else {
            struct Node* spot = &(*table)->linked_lists[hash_index];
            struct Node** spot_2 = &spot;
            add_node_to_head(spot_2, key, value);
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

int main() {
    size_t index;

    struct Table* table;
    //struct Node* table_head;
    //struct Node lists[10];

    char person[] = "Cameron"; //709, 9
    char person_2[] = "Jordan"; //606, 6

    index = get_hash_index(person);

    //table_head = &lists[0];

    //size_of_table = sizeof(table_head)/sizeof(struct Node);
    printf("1. %lu\n", index);

    table = table_new(10);
    printf("2. %lu\n", table->size);

    add_value_to_table(&table, person, 1);
    printf("3. %d\n", table->linked_lists[9].value);

    add_value_to_table(&table, person, 2);
    printf("4. %d\n", table->linked_lists[9].value);

    add_value_to_table(&table, person_2, 3);
    printf("5. %d\n", table->linked_lists[6].value);

    return 0;
}
