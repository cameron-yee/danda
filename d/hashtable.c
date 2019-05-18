#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"

int main() {
    char person[] = "Cameron"; //709, 9
    char person_2[] = "Jordan"; //606, 6
    size_t index = get_hash_index(person);
    struct Table* table;

    printf("1. %lu\n", index);

    table = table_new(10);

    printf("2. %lu\n", table->size);

    add_value_to_table(&table, person, 1);

    printf("3. %d\n", table->linked_lists[9]->value);

    add_value_to_table(&table, person, 2);

    printf("4. %d\n", table->linked_lists[9]->value);

    add_value_to_table(&table, person_2, 3);

    printf("5. %d\n", table->linked_lists[6]->value);

    return 0;
}
