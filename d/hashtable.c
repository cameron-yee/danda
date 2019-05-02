#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"

int main() {
    char person[] = "Cameron";
    size_t index = get_hash_index(person);
    struct Table* table;

    printf("%lu\n", index);

    table = table_new(10);

    printf("%lu\n", table->size);

    add_value_to_table(&table, person, 20);

    printf("%d\n", table->linked_lists[9]->value);

    add_value_to_table(&table, person, 19);

    printf("%d\n", table->linked_lists[9]->value);

    return 0;
}
