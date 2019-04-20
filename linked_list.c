#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

int main() {
    struct Node* head;
    char data[] = "Hello";
    char more_data[] = "World";

    head = node_new(data);

    add_node_to_head(&head, more_data);

    print_list(head);

    return 0;
}
